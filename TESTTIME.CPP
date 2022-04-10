/**
 * @file TimeTEST.CPP
 * @author Lim Wen Chao
 * @brief Unit test for Time
 * @version 0.1
 * @date 2022-02-24
 * 
 * 
 */
#include "TIME.H"

#include <iostream>

using namespace std;

int testTime_main ()
{
    //Check constructor correctly initializes the data and all getters are able to retrieve the data
    Time testTime1;
    cout << "Default Constructor" << endl;
    cout << "Hour: " << testTime1.GetHour() << endl;
    cout << "Minute: " << testTime1.GetMinute() << endl << endl;

    Time testTime2(1,1);
    cout << "Constructor" << endl;
    cout << "Hour: " << testTime2.GetHour() << endl;
    cout << "Minute: " << testTime2.GetMinute() << endl << endl;

    //Check that setters are working correctly
    cout << "Test Setters" << endl;

    //Check that hour setter are working correctly
    cout << "Test Hour setter" << endl;
    testTime2.SetHour(3);
    cout << "Hour: " << testTime2.GetHour() << endl;

    //Check that minute setter are working correctly
    cout << "Test Minute setter" << endl;
    testTime2.SetMinute(3);
    cout << "Minute: " << testTime2.GetMinute() << endl << endl;

    //Check that < operator overload function can correctly compare 2 Time objects
    cout << "Test < operator" << endl;
    testTime1.SetHour(5);
    testTime1.SetMinute(5);
    cout << "Test Time 1: " << testTime1.Display24HTime() << endl;
    cout << "Test Time 2: " << testTime2.Display24HTime() << endl;
    cout << "Compare testTime1 < testTime2: " << (testTime1 < testTime2) << endl;

    //Check that > operator overload function can correctly compare 2 Time objects
    cout << "Test > operator" << endl;
    cout << "Compare testTime1 > testTime2: " << (testTime1 > testTime2) << endl;

    return 0;
}