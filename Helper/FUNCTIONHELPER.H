/**
 * @file MENUHELPER.H
 * @author Lim Wen Chao
 * @brief Each function here represents a option for the program. In addition, the function to display the menu is here too.
 * @version 0.1
 * @date 2022-04-05
 * 
 * 
 */

#ifndef FUNCTIONHELPER_H
#define FUNCTIONHELPER_H

#include "LOGICHELPER.H"

#include <iostream>
#include <cstdio>

using namespace std;

class FunctionHelper
{
    public: 
                /**
                * @brief Displays the menu
                * 
                */
        string DisplayMenu();
                /**
                 * @brief Function 1
                 * 
                 * @param windLog - The maps of bst of weather 
                 * @param monthInput - The month to search
                 * @param yearInput - The year to search
                 * @return string - The result string
                 */
        string FindAverageWindTempMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int monthInput, int yearInput);
                /**
                 * @brief Function 2
                 * 
                 * @param windLog - The maps of bst of weather
                 * @param yearInput - The year to search
                 * @return string - The result string
                 */
        string FindAverageWindTempMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput);
                /**
                 * @brief Function 3
                 * 
                 * @param windLog - The maps of bst of weather
                 * @param yearInput - The year to search
                 * @return string - The result string
                 */
        string FindSumSolarRadMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput);
                /**
                 * @brief Function 4
                 * 
                 * @param windLog - The maps of bst of weather
                 * @param yearInput - The year to search
                 */
        void OutputFileAverageWindTempSolarMonth(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int yearInput);
                /**
                 * @brief Function 5
                 * 
                 * @param windLog - The maps of bst of weather
                 * @param day - The day to search
                 * @param month - The month to search
                 * @param year - The year to search
                 * @return string - The result string
                 */
        string FindHighestSolarTimeByDate(map<int, map<int, map<int, Bst<Weather>>>>& windLog, int day, int month, int year);
};

#endif