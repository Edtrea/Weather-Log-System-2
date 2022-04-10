/**
 * @file TESTFUNCTIONHELPER.CPP
 * @author Lim Wen Chao
 * @brief 
 * @version 0.1
 * @date 2022-04-09
 * 
 * 
 */

#include "Helper/FUNCTIONHELPER.H"


using namespace std;

int testFunc_main ()
{
    FunctionHelper funcHelp;
    LogicHelper TestLogic;
    map<int, map<int, map<int, Bst<Weather>>>> testLog;
    ifstream indexFile("data/test_index.txt");
    TestLogic.LoadMultiDataFileCSV(indexFile, testLog);
    //Check that DisplayMenu function can successfully display the menu
    cout << "Test DisplayMenu function" << endl;
    cout << funcHelp.DisplayMenu() << endl;
    //Check that FindAverageWindTempMonth can correctly carry out the function of option 1 of menu given map, month and year input
    cout << "Test FindAverageWindTempMonth function for option 1" << endl;
    cout << funcHelp.FindAverageWindTempMonth(testLog, 1, 2010);
    cout << endl;
    //Check that FindAverageWindTempMonth can correctly carry out the function of option 2 of menu given map and year input
    cout << "Test FindAverageWindTempMonth function for option 2" << endl;
    cout << funcHelp.FindAverageWindTempMonth(testLog, 2010);
    cout << endl;
    //Check that FindSumSolarRadMonth can correctly carry out the function of option 3 of menu given map and year input
    cout << "Test FindSumSolarRadMonth function for option 3" << endl;
    cout << funcHelp.FindSumSolarRadMonth(testLog, 2010);
    cout << endl;
    //Check that OutputFileAverageWindTempSolarMonth can correctly carry out the function of option 4 of menu given map and year input
    cout << "Test OutputFileAverageWindTempSolarMonth function for option 4" << endl;
    funcHelp.OutputFileAverageWindTempSolarMonth(testLog, 2010);
    cout << endl;
    //Check that FindHighestSolarTimeByDate can correctly carry out the function of option 5 of menu given map, day, month and year input
    cout << "Test FindHighestSolarTimeByDate function for option 5" << endl;
    cout << funcHelp.FindHighestSolarTimeByDate(testLog, 1,1,2010) << endl;
    cout << endl;

    return 0;
}