/**
 * @file LOGICHELPER.H
 * @author Lim Wen Chao
 * @brief A helper class for main.cpp
 * Handles task such as displaying menu, converting of data types, addition..
 * Function for writing to file will be including in this helper class in this program as there is only 1 function in this program that will write output to file.
 * @version 0.1
 * @date 2022-02-21
 * 
 * @version 0.2
 * @date 2022-03-09
 * Change LoadDataFileCSV function to return bool
 * 
 * @version 1.0
 * @date 2022-04-08
 * Moved Display menu to functionHelper class
 * Changed all function that accept vector of weather to accepting maps of bst of weather instead
 */

#ifndef LOGICHELPER_H
#define LOGICHELPER_H

#include "../BST.H"
#include "../DATE.H"
#include "../TIME.H"
#include "../WEATHER.H"
#include "VALIDATIONHELPER.H"
#include "BSTWEATHERHELPER.H"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class LogicHelper
{
    public: 
            /**
             * @brief Reads the inputfile line by line for filename pass to LoadDataFileCSV function to read and load data into the windlog
             * 
             * @param inputFile - Input file with the list of data file name to read and load
             * @param windLog - The maps of bst of weather for storing Weather object which will store data from data file. This will be passed to LoadDataFileCSV function to load file by file
             */
        void LoadMultiDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog);
        
            /**
             * @brief Load the data of an input data file and store it in a maps of bst of weather
             * 
             * @param inputFile - The input file
             * @param WindLog - The maps of bst of weather
             * @return true - Load successful
             * @return false - Load unsuccessful
             */
        bool LoadDataFileCSV(ifstream& inputFile, map<int, map<int, map<int, Bst<Weather>>>>& windLog);
            /**
             * @brief Inserts tempLog into windlog
             * 
             * @param windLog - The maps of bst of weather
             * @param tempLog - The weather object to be inserted into windLog
             */
        void InsertWeatherToMap(map<int, map<int, map<int, Bst<Weather>>>>& windLog, Weather& tempLog);

            /**
             * @brief Removes leading 0s from a given string
             * 
             * @param input - The input string
             * @return string - The string after removing leading 0s
             */
        string RemoveLeadingZeros(string input);
            /**
             * @brief Search and Calculates the average wind speed of a month when given the month and year to search for
             * 
             * @param array - The maps of bst of weather to search in
             * @param month - The month to search for
             * @param year - The year to search for
             * @return float - The average wind speed of a month
             */
        float AverageWindSpeedMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);
            /**
             * @brief Search and Calculates the average air temperature of a month when given the month and year to search for
             * 
             * @param array - The maps of bst of weather to search in
             * @param month - The month to search for
             * @param year - The year to search for
             * @return float - The average air temperature of a month
             */
        float AverageAirTemperatureMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);
            /**
             * @brief Search and Calculates the total solar radiation of a month when given the month and year to search for
             * 
             * @param array - The maps of bst of weather to search in
             * @param month - The month to search for
             * @param year - The year to search for
             * @return float - The total solar radiation of a month
             */
        float SumSolarRadiationMonth(const map<int, map<int, map<int, Bst<Weather>>>>& windLog, const int month, const int year);
            /**
             * @brief Converts a given integer month to string month
             * 
             * @param month - A month in integer
             * @return string - A month in string
             */
        string IntMonthToString(const int& month);
            /**
             * @brief Converts wind speed m/s  to km/h
             * 
             * @param windSpeed - wind speed in m/s
             * @return float - wind speed in km/h
             */
        float ConvertWindMStoKMH(const float& windSpeed);
            /**
             * @brief Converts solar radiation from W per 10 min to kWh
             * 
             * @param radiation - Radiation in W per 10min
             * @return float - Radiation in kWh
             */
        float ConvertSolarRadiationWMtoKWH(const float& radiation);
            /**
             * @brief Create/Appends a given string into "WindTempSolar.csv"
             * 
             * @param output - The string to append
             */
        void WriteAppendFile(const string& fileName, const string& output);
            /**
             * @brief Search for the highest solar radiation value found in a day's worth of weather logs
             * 
             * @param windLog - A bst of weather
             * @return float - The highest solar radiation value found in a day's record
             */
        float HighestSolarRadiationDay(const Bst<Weather>& windLog);
            /**
             * @brief Find the list of time where solar radiation value is the same as MaxSolarRadiation
             * 
             * @param windLog - A bst of weather
             * @param MaxSolarRadiation - The solar radiation to match
             * @return string - The list of time
             */
        string TimeOfSolarRadiationDay(Bst<Weather>& windLog, float MaxSolarRadiation);
};

#endif