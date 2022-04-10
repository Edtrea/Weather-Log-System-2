/**
 * @file BSTWEATHERHELPER.H
 * @author Lim Wen Chao
 * @brief Holds all the functions that is used as parameter for BST functions in the program
 * @version 0.1
 * @date 2022-04-05
 * 
 * 
 */

#ifndef MENUHELPER_H
#define MENUHELPER_H

#include "../WEATHER.H"

class BstWeatherHelper
{
    public: 
            /**
             * @brief Get the Weather object's Wind Speed
             * 
             * @param weather - A weather object
             * @return float - the value of wind speed of weather
             */
        static float GetWeatherWindSpeed(Weather& weather);
            /**
             * @brief Get the Weather object's Air Temp
             * 
             * @param weather - A weather object
             * @return float - the value of air temperature of weather
             */
        static float GetWeatherAirTemp(Weather& weather);
            /**
             * @brief Get the Weather object's Solar Rad 
             * 
             * @param weather - A weather object
             * @return float - the value of solar radiation of weather
             */
        static float GetWeatherSolarRad(Weather& weather);
            /**
             * @brief Get the Weather's time if weather's solar radiation is equal to solarRad
             * 
             * @param weather - A weather object
             * @param solarRad - The solar radiation value to compare with weather's solar radiation
             * @return string - The 24h time 
             */
        static string GetWeatherTimeBySolarRad(Weather& weather, float solarRad);
};

#endif