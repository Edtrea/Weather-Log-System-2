/**
 * @file MAIN.CPP
 * @author Lim Wen Chao
 * @brief Controls the cin and cout of the program
 * @version 0.1
 * @date 2022-02-21
 * 
 * @version 0.2
 * @date 2022-03-09
 * Updated check to be < 0 instead of == -1
 * 
 * @version 1.0
 * @date 2022-04-08
 * Move function logic to functionHelper class.
 * 
 */
#include "Helper/LOGICHELPER.H"
#include "Helper/VALIDATIONHELPER.H"
#include "Helper/FUNCTIONHELPER.H"
#include "DATE.H"
#include "TIME.H"
#include "WEATHER.H"
#include "BST.H"

#include <iostream>
#include <sstream>

using namespace std;


int main ()
{
        //Initialize LogicHelper and Validationhelper for use
    LogicHelper logicHelp;
    ValidationHelper validateHelp;
    FunctionHelper menuHelp;
        //Initialize map(year) of map(month) of map(day) of Bst of Weather
        //map<int, Bst<Weather>> day;
        //map<int, map<int, Bst<Weather>> > month;
    map<int, map<int, map<int, Bst<Weather>>>> windLog;

   ifstream indexFile("data/met_index.txt");
   //ifstream indexFile("data/test_index.txt");

    if(indexFile.is_open() == false)
    {
        cout << "Error: 'met_index.txt' file is not found." << endl;
        return EXIT_FAILURE;
    }

    logicHelp.LoadMultiDataFileCSV(indexFile, windLog);
    indexFile.close();

    bool flag = true;
    string input;
    while(flag)
    {
            //Get User input for which function
        cout << menuHelp.DisplayMenu() << endl;
        cin >> input;
            //Check which function user wants to use
        if(input == "1")
        {
                //Ask user which month and year they want to search for and validate those input
            string monthInput, yearInput;
            cout << "Input month to search(1-12)" << endl;
            cin >> monthInput;
            monthInput = logicHelp.RemoveLeadingZeros(monthInput);
            while(validateHelp.IsInteger(monthInput) == false)
            {
                cout << "Error: invalid month. Expects integer." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
            }
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }
            while(validateHelp.IsValidDate(stoi(monthInput), stoi(yearInput)) == false)
            {
                cout << "Error: invalid date." << endl;
                cout << "Input month to search(1-12)" << endl;
                cin >> monthInput;
                monthInput = logicHelp.RemoveLeadingZeros(monthInput);
                while(validateHelp.IsInteger(monthInput) == false)
                {
                    cout << "Error: invalid month. Expects integer." << endl;
                    cout << "Input month to search(1-12)" << endl;
                    cin >> monthInput;
                }
                cout << "Input year to search" << endl;
                cin >> yearInput;
                while(validateHelp.IsInteger(yearInput) == false)
                {
                    cout << "Error: invalid year. Expects integer." << endl;
                    cout << "Input year to search" << endl;
                    cin >> yearInput;
                }
            }

            cout << menuHelp.FindAverageWindTempMonth(windLog, stoi(monthInput), stoi(yearInput)) << endl;
        }
        else if (input == "2")
        {
                //Ask user for year to search for and validate the input
            string yearInput;
            cout << "Input year to search(YYYY)" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false ||yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            cout << yearInput << endl;

            cout << menuHelp.FindAverageWindTempMonth(windLog, stoi(yearInput)) << endl;
        }
        else if (input == "3")
        {
                //Ask user for which year to search and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false || yearInput.size() != 4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            cout << yearInput << endl;
            
            cout << menuHelp.FindSumSolarRadMonth(windLog, stoi(yearInput));
        }
        else if(input == "4")
        {
                //Ask user for which year to search for and validate the input
            string yearInput;
            cout << "Input year to search" << endl;
            cin >> yearInput;
            while(validateHelp.IsInteger(yearInput) == false || yearInput.size() !=4)
            {
                cout << "Error: invalid year. Expects integer." << endl;
                cout << "Input year to search" << endl;
                cin >> yearInput;
            }

            menuHelp.OutputFileAverageWindTempSolarMonth(windLog, stoi(yearInput));
        }
        else if (input == "5")
        {
                //Ask user for which date to search
            string dateInput;
            cout << "Input a date(d/m/yyyy)" << endl;
            cin >> dateInput;

            istringstream date(dateInput);
            string day, month, year;
            getline(date, day, '/');    //day part of date
            getline(date, month, '/');  //month part of date
            getline(date, year, '/');   //year part of date
            date.clear();
                //Remove leading zeros when storing date
            day = logicHelp.RemoveLeadingZeros(day);
            month = logicHelp.RemoveLeadingZeros(month);
            year = logicHelp.RemoveLeadingZeros(year);
                //Validate date
            while(validateHelp.IsInteger(day) == false || validateHelp.IsInteger(month) == false || validateHelp.IsInteger(year) == false)
            {
                cout << "Error: Invalid date" << endl;
                cout << dateInput << endl;
                cout << "Date is not integer" << endl;
                    //Ask user for which date to search
                cout << "Input a date(d/m/yyyy)" << endl;
                cin >> dateInput;

                date.str(dateInput);
                getline(date, day, '/');    //day part of date
                getline(date, month, '/');  //month part of date
                getline(date, year, '/');   //year part of date
                date.clear();
                    //Remove leading zeros when storing date
                day = logicHelp.RemoveLeadingZeros(day);
                month = logicHelp.RemoveLeadingZeros(month);
                year = logicHelp.RemoveLeadingZeros(year);
            }

            while(validateHelp.IsValidDate(stoi(day), stoi(month), stoi(year)) == false)
            {
                cout << "Error: Invalid date" << endl;
                cout << "Error Data: " << dateInput << endl;
                cout << "Accepted date format: dd/mm/yyyy" << endl;
                        //Ask user for which date to search

                cout << "Input a date(d/m/yyyy)" << endl;
                cin >> dateInput;

                date.str(dateInput);
                getline(date, day, '/');    //day part of date
                getline(date, month, '/');  //month part of date
                getline(date, year, '/');   //year part of date
                date.clear();
                    //Remove leading zeros when storing date
                day = logicHelp.RemoveLeadingZeros(day);
                month = logicHelp.RemoveLeadingZeros(month);
                year = logicHelp.RemoveLeadingZeros(year);
                    //Validate date
                while(validateHelp.IsInteger(day) == false || validateHelp.IsInteger(month) == false || validateHelp.IsInteger(year) == false)
                {
                    cout << "Error: Invalid date" << endl;
                    cout << dateInput << endl;
                    cout << "Date is not integer" << endl;
                        //Ask user for which date to search
                    cout << "Input a date(d/m/yyyy)" << endl;
                    cin >> dateInput;

                    date.str(dateInput);
                    getline(date, day, '/');    //day part of date
                    getline(date, month, '/');  //month part of date
                    getline(date, year, '/');   //year part of date
                    date.clear();
                        //Remove leading zeros when storing date
                    day = logicHelp.RemoveLeadingZeros(day);
                    month = logicHelp.RemoveLeadingZeros(month);
                    year = logicHelp.RemoveLeadingZeros(year);
                }
            }

                //Get max Solar radiation of that date
            cout << menuHelp.FindHighestSolarTimeByDate(windLog, stoi(day), stoi(month), stoi(year)) << endl;

        }
        else if (input == "6")
        {
            flag = false;
        }
        else
        {
            cout << "Error: Unknown command. Only numbers 1-6 accepted." << endl;
        }
        
    }
    return 0;
}