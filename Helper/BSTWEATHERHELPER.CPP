/**
 * @file BSTWEATHERHELPER.CPP
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-04-05
 * 
 * 
 */

#include "BSTWEATHERHELPER.H"

float BstWeatherHelper::GetWeatherWindSpeed(Weather& weather)
{
    return weather.GetWindSpeed();
}
float BstWeatherHelper::GetWeatherAirTemp(Weather& weather)
{
    return weather.GetAirTemperature();
}
float BstWeatherHelper::GetWeatherSolarRad(Weather& weather)
{
    return weather.GetSolarRadiation();
}
string BstWeatherHelper::GetWeatherTimeBySolarRad(Weather& weather, float solarRad)
{
    if(weather.GetSolarRadiation() == solarRad)
    {
        return weather.GetTime().Display24HTime() + "\n";
    }
    return "";
}