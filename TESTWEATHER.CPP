/**
 * @file TESTWEATHER.CPP
 * @author Lim Wen Chao
 * @brief Unit Test for Weather.cpp
 * @version 0.1
 * @date 2022-02-27
 * 
 * 
 */

#include "WEATHER.H"

int testWeather_main()
{
    //Check that constructor correctly initialize the data and all getters can retrieve the data
    cout << "Check constructor" << endl;
    Weather testWeather1;
    cout << "Date: " << testWeather1.GetDate().DisplayFullDate() << endl;
    cout << "Time: " << testWeather1.GetTime().Display24HTime() << endl;
    cout << "Wind Speed: " << testWeather1.GetWindSpeed() << endl;
    cout << "Solar Radiation" << testWeather1.GetSolarRadiation() << endl;
    cout << "Air Temperature: " << testWeather1.GetAirTemperature() << endl;
    cout << endl;
    //Check that setters are working correctly
    Weather testWeather2;
    cout << "Test Setters" << endl;
    cout << endl;
    //Check that Date setter are working correctly
    cout << "Test Date setter" << endl;
    Date testDate(16,3,2016);
    testWeather2.SetDate(testDate);
    cout << "Date: " << testWeather2.GetDate().DisplayFullDate() << endl;
    cout << endl;

    //Check that Time setter are working correctly
    cout << "Test Time setter" << endl;
    Time testTime(9,15);
    testWeather2.SetTime(testTime);
    cout << "Time: " << testWeather2.GetTime().Display24HTime() << endl;
    cout << endl;

    //Check that Wind Speed setter are working correctly
    cout << "Test Wind Speed Setter" << endl; 
    testWeather2.SetWindSpeed(23.1);
    cout << "Wind Speed: " << testWeather2.GetWindSpeed() << endl;
    cout << endl;

    //Check that Solar Radiation setter are working correctly
    cout << "Test Solar radiation Setter" << endl;
    testWeather2.SetSolarRadiation(53.15);
    cout << "Solar Radiation" << testWeather2.GetSolarRadiation() << endl;
    cout << endl;

    //Check that Air Temperature setter are working correctly
    cout << "Test Air temp setter" << endl;
    testWeather2.SetAirTemp(53.25);
    cout << "Air Temperature: " << testWeather2.GetAirTemperature() << endl;
    cout << endl;

    //Check that < operator can correctly compare the time of weather object
    cout << "Test < operator" << endl;
    cout << "Time of weather 1: " << testWeather1.GetTime().Display24HTime() << endl;
    cout << "Time of weather 2: " << testWeather2.GetTime().Display24HTime() << endl;
    cout << "Compare weather1 < weather2: " << (testWeather1 < testWeather2) << endl;
    cout << endl;

    //Check that > operator can correclt compare the time of weather object
    cout << "Test > operator" << endl;
    cout << "Time of weather 1: " << testWeather1.GetTime().Display24HTime() << endl;
    cout << "Time of weather 2: " << testWeather2.GetTime().Display24HTime() << endl;
    cout << "Compare weather1 > weather2: " << (testWeather1 > testWeather2) << endl;
    cout << endl;

    return 0;
}