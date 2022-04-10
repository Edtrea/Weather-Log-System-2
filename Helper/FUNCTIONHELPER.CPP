/**
 * @file MENUHELPER.CPP
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-05
 * 
 * 
 */
#include "FUNCTIONHELPER.H"


string FunctionHelper::DisplayMenu()
{
    string menu;
    menu += "1. The average wind speed and average ambient air temperature for a specified month and  year.\n";
    menu += "2. Average wind speed and average ambient air temperature for each month of a specified year.\n";
    menu += "3. Total solar radiation in kWh/m2 for each month of a specified year.\n";
    menu += "4. Write average wind speed (km/h), average ambient air temperature and total solar radiation in kWh/m2 for each month of a specified year to CSV.\n";
    menu += "5. Show the times for the highest solar radiation for a date (d/m/yyy/)\n";
    menu += "6. Exit the program.\n";

    return menu;
}

string FunctionHelper::FindAverageWindTempMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int monthInput, int yearInput)
{
    LogicHelper logicHelp;
    string result;
        //Get the average wind speed of the month
    float averageWind = logicHelp.AverageWindSpeedMonth(windLog, monthInput, yearInput);
        //Get the average air temperature of the month
    float averageTemp = logicHelp.AverageAirTemperatureMonth(windLog, monthInput, yearInput);

        //If average wind speed and average air temperature is not found
    if(averageWind == -1 && averageTemp == -1)
    {
        result += logicHelp.IntMonthToString(monthInput) + " " + to_string(yearInput) + ": " + "No Data" + "\n";
    }
    else
    {
        float convertedWind = logicHelp.ConvertWindMStoKMH(averageWind);

        result += logicHelp.IntMonthToString(monthInput) + " " + to_string(yearInput) + ": " + to_string(convertedWind) + " km/h, " + to_string(averageTemp) + " degrees C" + "\n";
    }
    return result;
}

string FunctionHelper::FindAverageWindTempMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput)
{
    string result;

        //Loop for each month of the year
    for(int month = 1; month <= 12; month++)
    {       
            //Get Average Wind speed and air temperature result
        result += FindAverageWindTempMonth(windLog, month, yearInput);
    }
    return result;
}

string FunctionHelper::FindSumSolarRadMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput)
{
    LogicHelper logicHelp;
    float totalRadiation;
    string result;

        //Loop for each month of the year
    for(int month = 1; month <= 12; month++)
    {
            //Get total solar radiation of the month
        totalRadiation = logicHelp.SumSolarRadiationMonth(windLog, month, yearInput);
            
            //If no data for solar radiation is found
        if(totalRadiation == -1)
        {
            result += logicHelp.IntMonthToString(month) + " " + to_string(yearInput) + ": No Data\n";
        }
        else
        {
            totalRadiation = logicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);

            result += logicHelp.IntMonthToString(month) + " " + to_string(yearInput) + ": " + to_string(totalRadiation) + " kWh/m" + u8"\u00B2" + "\n";
        }
    }

    return result;
}

void FunctionHelper::OutputFileAverageWindTempSolarMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput)
{
    LogicHelper logicHelp;
    const char outputFile[] = "WindTempSolar.csv";
    const string outputFileStr = "WindTempSolar.csv";
    string outputStr;
        //Delete the output file if it exist
    remove(outputFile);

        //appends the string and proceed to nextline
    outputStr += to_string(yearInput) + "\n";

    float averageWind, averageTemp, totalRadiation;
        //Loop for each month of the year
    for(int month = 1; month <= 12; month++)
    {
            //Get the average wind speed of the month
        averageWind = logicHelp.AverageWindSpeedMonth(windLog, month, yearInput);
            //Get the average air temperature of the month
        averageTemp = logicHelp.AverageAirTemperatureMonth(windLog, month, yearInput);
            //Get the total solar radiation of the month
        totalRadiation = logicHelp.SumSolarRadiationMonth(windLog, month, yearInput);

            //If no data for wind speed and air temperature and solar radiation is found
        if(averageWind == -1 && averageTemp == -1 && totalRadiation == -1)
        {
            continue;
        }
        else
        {
                //Print the month
            outputStr += logicHelp.IntMonthToString(month)+",";

                //If no data for wind speed is found
            if(averageWind == -1)
            {
                continue;
            }
            else
            {
                    //Convert and print the data
                averageWind = logicHelp.ConvertWindMStoKMH(averageWind);
                outputStr += to_string(averageWind);
            }
                //Add , separator
            outputStr += ",";
                //If average air temperature data is not found
            if(averageTemp == -1)
            {
                continue;
            }
            else
            {
                    //print the data
                outputStr += to_string(averageTemp);
            }
                //Add , separator
            outputStr += ",";
                //If data for solar radiation not found
            if(totalRadiation == -1)
            {
                continue;
            }
            else
            {
                    //Convert and print data
                totalRadiation = logicHelp.ConvertSolarRadiationWMtoKWH(totalRadiation);
                outputStr += to_string(totalRadiation);
            }
        }
        outputStr += "\n";
    }
    logicHelp.WriteAppendFile(outputFileStr, outputStr);
}

string FunctionHelper::FindHighestSolarTimeByDate(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int day, int month, int year)
{
    LogicHelper logicHelp;
    string result;
        //Check if data for that year exist
    if(windLog.count(year) > 0)
    {
            //Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {       
                //Check if data of that date exist
            if(windLog.at(year).at(month).count(day) > 0)
            {
                result += "Date: " + to_string(day) + "/" + to_string(month) + "/" + to_string(year) + "\n";

                    //Get the highest solar radiation on that date
                float MaxSolarRadiation = logicHelp.HighestSolarRadiationDay(windLog.at(year).at(month).at(day));

                result += "High solar radiation for the day: " + to_string(logicHelp.ConvertSolarRadiationWMtoKWH(MaxSolarRadiation)) + "W/m2\n\n";

                result += "Time: \n";
                    
                    //Get the list of time with the same solar radiation as MaxSolarRadiation
                result += logicHelp.TimeOfSolarRadiationDay(windLog.at(year).at(month).at(day), MaxSolarRadiation);
            }
            else
            {
                cout << "No log from this date" << endl;
            }
        }
        else
        {
            cout << "No log from this date" << endl;
        }
    }
    else
    {
        cout << "No log from this date" << endl;
    }

    return result;
}

