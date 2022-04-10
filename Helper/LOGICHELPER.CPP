/**
 * @file LOGICHELPER.CPP
 * @author Lim Wen Chao
 * @brief .cpp file for LogicHelper
 * @version 0.1
 * @date 2022-02-21
 *
 * @version 0.2
 * @date 2022-03-09
 * Change LoadDataFileCSV function to return bool.
 * True when invalid data
 * False when no invalid data
 * Added Checks for AverageWindSpeedMonth and AverageAirTemperatureMonth function to make sure value is positive before counting it
 * Added check for ConvertWindMStoKMH to be more than 0 to convert else it will return 0
 */

#include "LOGICHELPER.H"

void LogicHelper::LoadMultiDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog)
{
    string fileName;
    ifstream dataFile;

        //While there is still a line to read in inputfile
    while(getline(inputFile,fileName))
    {       
            //Check if line is not empty/blank
        if(fileName != "")
        {       
                //Open the file using the line
            dataFile.open("data/" + fileName);
            if(dataFile.is_open())
            {
                cout << "Loading file: " + fileName << endl;
                if(LoadDataFileCSV(dataFile,windLog) == false)
                {
                    cout << "Error loading data file: " + fileName << endl;
                }
                else
                {
                    cout << "Loaded data file: " + fileName << endl;
                }
                dataFile.close();
            }
            else
            {
                cout << "Error while opening file: " + fileName << endl;
            }
        }
    }
}

bool LogicHelper::LoadDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog)
{
    unsigned int recordCount = 0;
        // Initialises ValidationHelper
    ValidationHelper validateHelp;
        //String to store a line of data
    string line;
        // input string stream for reading and spliting of elements
    istringstream row, dateTime, date, time;
        //String to store a column of data
    string column;
    string dateField, timeField;
    string day, month, year;
    string hour, minute;
    Date tempDate;
    Time tempTime;
    Weather tempLog;
    
    bool re = true;

        // Get and ignore csv header
    getline(inputFile, line);
        // Loops for each row of record in file
    while (getline(inputFile, line))
    {
            //Checks that line obtained is not empty
        if (line != "")
        {
                // Split a row into its component columns
            row.str(line);
            getline(row, column, ',');   //0 WAST
                //Split WAST into Date and Time
            dateTime.str(column);
            getline(dateTime, dateField, ' ');    //date part of WAST
            getline(dateTime, timeField, ' ');    //time part of WAST
            dateTime.clear();
                //Split Date into day, month and year
            date.str(dateField);
            getline(date, day, '/');    //day part of date
            getline(date, month, '/');  //month part of date
            getline(date, year, '/');   //year part of date
            date.clear();
                //Remove leading zeros when storing date
            day = RemoveLeadingZeros(day);
            month = RemoveLeadingZeros(month);
            year = RemoveLeadingZeros(year);
                //Validate date and load to tempDate object
            if(validateHelp.IsInteger(day) == false || validateHelp.IsInteger(month) == false || validateHelp.IsInteger(year) == false)
            {
                cout << "Error: Invalid date(WAST) detected at row " << recordCount + 1 << endl;
                cout << column << endl;
                cout << "Date is not integer" << endl;
                re = false;
            }
            else
            {
                if (validateHelp.IsValidDate(stoi(day), stoi(month), stoi(year)))
                {
                        //Store date object into weather object
                    tempDate.SetDay(stoi(day));
                    tempDate.SetMonth(stoi(month));
                    tempDate.SetYear(stoi(year));
                    tempLog.SetDate(tempDate);
                }
                else
                {
                    cout << "Error: Invalid date(WAST) detected at row " << recordCount + 1 << endl;
                    cout << "Error Data: " << day << "/" << month << "/" << year << endl;
                    cout << "Accepted date format: dd/mm/yyyy" << endl;
                    re = false;
                }
            }

                //Split Time into hour and minute
            time.str(timeField);
            getline(time, hour, ':');   //hour part of date
            getline(time, minute, ':'); //minute part of date
            time.clear();
                //Remove leading zeros when storing date
            hour = RemoveLeadingZeros(hour);
            minute = RemoveLeadingZeros(minute);
                //Valide Time and load to templog object
            if(validateHelp.IsInteger(hour) == false || validateHelp.IsInteger(minute) == false)
            {
                cout << "Error: Invalid time(WAST) detected at row: " << recordCount + 1 << endl;
                cout << column << endl;
                cout << "Time not integer" << endl;
                re = false;
            }
            else
            {
                if (validateHelp.IsValid24HourTime(stoi(hour), stoi(minute)))
                {
                    tempTime.SetHour(stoi(hour));
                    tempTime.SetMinute(stoi(minute));
                    tempLog.SetTime(tempTime);
                }
                else
                {
                    cout << "Error: Invalid time(WAST) detected at row: " << recordCount + 1 << endl;
                    cout << "Accepted time format(24h only): hh:mm" << endl;
                    re = false;
                }
            }

            getline(row, column, ',');   //1
            getline(row, column, ',');   //2
            getline(row, column, ',');   //3
            getline(row, column, ',');   //4
            getline(row, column, ',');   //5
            getline(row, column, ',');   //6
            getline(row, column, ',');   //7
            getline(row, column, ',');   //8
            getline(row, column, ',');   //9
            getline(row, column, ',');   //10 S
            //Validate WindSpeed(S) and store in templog
            if (validateHelp.IsNumber(column) == false)
            {
                cout << "Error: Invalid Wind Speed(S) detected at row: " << recordCount + 1 << endl;
                cout << column << endl;
                cout << "Only integer/float are accepted" << endl;
                re = false;
            }
            else
            {
                tempLog.SetWindSpeed(stof(column));
            }
            getline(row, column, ',');   //11 SR
                //Validate SR and store in tempLog
            if (validateHelp.IsNumber(column) == false)
            {
                cout << "Error: Invalid Solar Radiation(SR) detected at row: " << recordCount + 1 << endl;
                cout << column << endl;
                cout << "Only integer/float are accepted" << endl;
                re = false;
            }
            else
            {
                tempLog.SetSolarRadiation(stof(column));
            }
            getline(row, column, ',');   //12
            getline(row, column, ',');   //13
            getline(row, column, ',');   //14
            getline(row, column, ',');   //15
            getline(row, column, ',');   //16
            getline(row, column, ',');   //17 T
            //Validate T and store in tempLog
            if (validateHelp.IsNumber(column) == false)
            {
                cout << "Error: Invalid Ambient Air Temperature(T) detected at row: " << recordCount + 1 << endl;
                cout << column << endl;
                cout << "Only integer/float are accepted" << endl;
                re = false;
            }
            else
            {
                tempLog.SetAirTemp(stof(column));
            }

            try
            {
                InsertWeatherToMap(windLog, tempLog);
            }
            catch(const exception& e)
            {
                cerr << e.what() << '\n';
                cout << "Failed to load" << endl;
                re = false;
                abort();
            }

            row.clear();

            recordCount++;
        }
    }

    return re;
}

void LogicHelper::InsertWeatherToMap(map<int, map<int, map<int, Bst<Weather>>>>& windLog, Weather& tempLog)
{
    
        //Get year, month, day from weather log to be stored
    int logYear = tempLog.GetDate().GetYear();
    int logMonth = tempLog.GetDate().GetMonth();
    int logDay = tempLog.GetDate().GetDay();

        //Check if data of that year already exist
    int yearCount = windLog.count(logYear);
    if(yearCount > 0)
    {
            //Check if data of that year and month already exist
        int monthCount = windLog[logYear].count(logMonth);
        if(monthCount > 0)
        {
                //Check if data of that year, month and day already exist
            int dayCount = windLog[logYear][logMonth].count(logDay);
            if(dayCount > 0)
            {
                windLog[logYear][logMonth][logDay].Insert(tempLog);
            }
            else //data of that day dont exist yet
            {
                    //Create Bst of weather
                Bst<Weather> tempBst;
                    //Insert tempLog into Bst
                tempBst.Insert(tempLog);
                    //Insert bst into map
                windLog[logYear][logMonth][logDay] = tempBst;
            }
        }
        else //data of that month, day dont exist yet
        {
                //Create Bst of weather
            Bst<Weather> tempBst;
                //Insert tempLog into Bst
            tempBst.Insert(tempLog);
                //Create new day map
            map<int, Bst<Weather>> day;
                //Insert Bst into day map
            day[logDay] = tempBst;
                //Insert day map into month map
            windLog[logYear][logMonth] = day;
        }
    }
    else //data of that year, month, day dont exist yet
    {       //Create Bst of weather
        Bst<Weather> tempBst;
            //Insert templog into Bst
        tempBst.Insert(tempLog);
            //Create new day map
        map<int, Bst<Weather>> day;
            //Insert Bst into day map
        day[logDay] = tempBst;
            //Creat new month map
        map<int, map<int, Bst<Weather>> > month;
            //Insert day map into month map
        month[logMonth] = day;
            //Insert month map into year(windLog) map
        windLog[logYear] = month;
    }
}


string LogicHelper::RemoveLeadingZeros(string input)
{
    return input.erase(0, min(input.find_first_not_of('0'), input.size() - 1));
}

float LogicHelper::AverageWindSpeedMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    BstWeatherHelper BWH;
    float totalWindSpeed = 0.0;
    int count = 0;

        //Check if data of that year exist
    if(windLog.count(year) > 0)
    {
            //Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
                //Loops through the month map for each day
                //Get Bst<Weather> of each day and get count and total wind speed of each day
            map<int, Bst<Weather>>::const_iterator it;
            for (it = windLog.at(year).at(month).begin(); it != windLog.at(year).at(month).end(); ++it)
            {
                totalWindSpeed += it->second.GetSumValueFloat(&BWH.GetWeatherWindSpeed);
                count += it->second.TreeNodeCount();
            }
        }
        else //No data of that date exist
        {
            return -1;
        }
    }
    else //No data of that date exist
    {
        return -1;
    }

    return totalWindSpeed/count;
}

float LogicHelper::AverageAirTemperatureMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    BstWeatherHelper BWH;
    float totalAirTemperature = 0.0;
    int count = 0;

        //Check if data of that year exist
    if(windLog.count(year) > 0)
    {
            //Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
                //Loops through the month map for each day
                //Get Bst<Weather> of each day and get count and total airTemp of each day
            map<int, Bst<Weather>>::const_iterator it;
            for (it = windLog.at(year).at(month).begin(); it != windLog.at(year).at(month).end(); ++it)
            {
                totalAirTemperature += it->second.GetSumValueFloat(&BWH.GetWeatherAirTemp);
                count += it->second.TreeNodeCount();
            }
        }
        else //No data of that date exist
        {
            return -1;
        }
    }
    else //No data of that date exist
    {
        return -1;
    }

    return totalAirTemperature/count;
}

float LogicHelper::SumSolarRadiationMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year)
{
    BstWeatherHelper BWH;
    float totalSolarRadiation = 0.0;
    int count = 0;

            //Check if data of that year exist
    if(windLog.count(year) > 0)
    {
            //Check if data of that year and month exist
        if(windLog.at(year).count(month) > 0)
        {
                //Loops through the month map for each day
                //Get Bst<Weather> of each day and get total solar radiation of each day
            map<int, Bst<Weather>>::const_iterator it;
            for (it = windLog.at(year).at(month).begin(); it != windLog.at(year).at(month).end(); ++it)
            {
                totalSolarRadiation += it->second.GetSumValueFloat(&BWH.GetWeatherAirTemp);
            }
        }
        else //No data of that date exist
        {
            return -1;
        }
    }
    else //No data of that date exist
    {
        return -1;
    }

    return totalSolarRadiation;
}

string LogicHelper::IntMonthToString(const int &month)
{
    switch (month)
    {
    case 1:
        return "January";
    case 2:
        return "February";
    case 3:
        return "March";
    case 4:
        return "April";
    case 5:
        return "May";
    case 6:
        return "June";
    case 7:
        return "July";
    case 8:
        return "August";
    case 9:
        return "September";
    case 10:
        return "October";
    case 11:
        return "November";
    case 12:
        return "December";
    default:
        cout << endl << "Error converting int month to string" << endl;
        return "ERROR";
    }
}

float LogicHelper::ConvertWindMStoKMH(const float &windSpeed)
{
    if(windSpeed < 0)
    {
        return 0;
    }
    return windSpeed * 3.6;
}

float LogicHelper::ConvertSolarRadiationWMtoKWH(const float &radiation)
{
    if (radiation > 0)
    {
        return radiation / 6 / 1000;
    }
    return 0;
}

void LogicHelper::WriteAppendFile(const string& fileName, const string &output)
{
    ofstream OutputFile(fileName, ofstream::app);
        //appends the string and proceed to nextline
    OutputFile << output << endl;

    OutputFile.close();
}

float LogicHelper::HighestSolarRadiationDay(const Bst<Weather>& windLog)
{
    BstWeatherHelper BWH;
    float highestSolar;

    highestSolar = windLog.InOrderGetMaxFloat(&BWH.GetWeatherSolarRad);

    return highestSolar;
}

string LogicHelper::TimeOfSolarRadiationDay(Bst<Weather>& windLog, float MaxSolarRadiation)
{
    BstWeatherHelper BWH;
    string listOfTime;

    listOfTime += windLog.GetStringByFloatValue(&BWH.GetWeatherTimeBySolarRad, MaxSolarRadiation);

    return listOfTime;
}