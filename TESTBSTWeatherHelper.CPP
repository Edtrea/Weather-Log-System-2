/**
 * @file TESTBSTWeatherHelper.CPP
 * @author Lim Wen Chao
 * @brief Unit Test for BstWeatherHelper.cpp
 * @version 0.1
 * @date 2022-04-08
 * 
 * 
 */

#include "Helper/BSTWEATHERHELPER.H"

int testBstWeather_main()
{
    BstWeatherHelper BST;
    Weather testWeather;
    Date testDate(16,3,2016);
    testWeather.SetDate(testDate);
    Time testTime(9,15);
    testWeather.SetTime(testTime);
    testWeather.SetWindSpeed(23.1);
    testWeather.SetSolarRadiation(53.15);
    testWeather.SetAirTemp(53.25);

    //Check that GetWeatherWindSpeed function can correctly get the wind speed data from given weather object
    cout << "Test GetWeatherWindSpeed" << endl;
    cout << BST.GetWeatherWindSpeed(testWeather) << endl;
    cout << endl;
    //Check that GetWeatherAirTemp function can correctly get the air temperature data from given weather object
    cout << "Test GetWeatherAirTemp" << endl;
    cout << BST.GetWeatherAirTemp(testWeather) << endl;
    cout << endl;
    //Check that GetWeatherSolarRad function can correctly get the solar radiation data 
    cout << "Test GetWeatherSolarRad" << endl;
    cout << BST.GetWeatherSolarRad(testWeather) << endl;
    cout << endl;
    //Check that GetWeatherTimeBySolarRad function can correctly get the time data from given weather object based on given solar radiation value
    cout << "Test GetWeatherTimeBySolarRad" << endl;
    cout << "Found match: " << BST.GetWeatherTimeBySolarRad(testWeather, 53.15) << endl;
    cout << "Match not found: " << BST.GetWeatherTimeBySolarRad(testWeather, 42.5) << endl;
    cout << endl;

    return 0;
}