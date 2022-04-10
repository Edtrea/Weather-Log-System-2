/**
 * @file VECTORTEST.CPP
 * @author Lim Wen Chao
 * @brief 
 * @version 0.1
 * @date 2022-02-25
 * 
 * 
 */

#include "BST.H"
#include "Helper/BSTWEATHERHELPER.H"

using namespace std;

int testBst_main ()
{
    //Check that Constructor can correctly initialize an empty BST and Operator[] will throw out of range exception
    Bst<Weather> weatherTree1;
    cout << "Test Constructor" << endl;
    cout << weatherTree1.TreeNodeCount() << endl;
    cout << endl;

    //Check that the copy constructor can correctly deep copy another Vector
    cout << "Test Copy constructor" << endl;
    Bst<int> intTree1;
    intTree1.Insert(1);
    Bst<int> intTree2(intTree1);
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << "Tree2 values after copying Tree1 and deleting Tree1: ";
    intTree1.DeleteTree();
    intTree2.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that the deconstructor can successfully delete the Vector
    cout << "Test deconstructor" << endl;
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << "Tree2 values: ";
    intTree2.InOrderTraversal();
    cout << endl;
    intTree2.~Bst();
    cout << "Tree2 values after decontructed: ";
    intTree2.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that BST is correctly deleted using deleteTree function
    cout << "Test DeleteTree function" << endl;
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    intTree1.DeleteTree();
    cout << "Tree1 values after deleting tree: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that Operator= can correctly deep copy another Vector
    cout << "Test = operator" << endl;
    intTree1.Insert(1);
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << "Tree2 values after copying Tree1 and deleting Tree1: ";
    intTree2 = intTree1;
    intTree1.DeleteTree();
    intTree2.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that Search function can correctly determine if a value exist in BST
    cout << "Test Search function" << endl;
    cout << "Value found: " << intTree2.Search(1) << endl;
    cout << "Value not found: " << intTree2.Search(2) << endl;
    cout << endl;
    //Check that Insert function can correctly insert into BST
    cout << "Test Insert function" << endl;
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << "After insert" << endl;
    intTree1.Insert(1);
    intTree1.Insert(2);
    intTree1.Insert(5);
    intTree1.Insert(4);
    intTree1.Insert(3);
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that DeleteNode function can correctly delete a node in BST by value given
    cout << "Test DeleteNode function" << endl;
    cout << "Tree1 values: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << "Deletes node" << endl;
    intTree1.DeleteNode(1);
    cout << "Tree1 values after delete: ";
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that TreeNodeCount function can return the correct number of node in BST
    cout << "Test TreeNodeCount function" << endl;
    cout << "Count: " << intTree1.TreeNodeCount() << endl;
    cout << endl;
        //Create and insert weather objects
        BstWeatherHelper BST;

        Weather testWeather1;
        Date testDate1(16,3,2016);
        testWeather1.SetDate(testDate1);
        Time testTime2(9,15);
        testWeather1.SetTime(testTime2);
        testWeather1.SetWindSpeed(23.1);
        testWeather1.SetSolarRadiation(53.15);
        testWeather1.SetAirTemp(53.25);

        Weather testWeather2;
        Date testDate2(16,3,2016);
        testWeather2.SetDate(testDate2);
        Time testTime3(9,15);
        testWeather2.SetTime(testTime3);
        testWeather2.SetWindSpeed(33.1);
        testWeather2.SetSolarRadiation(53.15);
        testWeather2.SetAirTemp(53.25);

        Weather testWeather3;
        Date testDate3(16,3,2016);
        testWeather3.SetDate(testDate3);
        Time testTime4(9,15);
        testWeather3.SetTime(testTime4);
        testWeather3.SetWindSpeed(13.1);
        testWeather3.SetSolarRadiation(53.15);
        testWeather3.SetAirTemp(57.25);

        weatherTree1.Insert(testWeather1);
        weatherTree1.Insert(testWeather2);
        weatherTree1.Insert(testWeather3);
    //Check that InOrderTraversal function can traverse the BST in an in order way
    cout << "Test InOrderTraversal function" << endl;
    intTree1.Insert(1);
    intTree1.InOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that PreOrderTraversal function can traverse the BST in a pre order way
    cout << "Test PreOrderTraversal function" << endl;
    intTree1.PreOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that PostOrderTraversal function can traverse the BST in a post order way
    cout << "Test PostOrderTraversal function" << endl;
    intTree1.PreOrderTraversal();
    cout << endl;
    cout << endl;
    //Check that InOrderGetMaxFloat function can correctly get the largest value in BST
    cout << "Test InOrderGetMaxFloat function" << endl;
    cout << intTree1.InOrderGetMaxFloat() << endl;
    cout << "Test InOrderGetMaxFloat with function as parameter" << endl;
    cout << weatherTree1.InOrderGetMaxFloat(BST.GetWeatherWindSpeed) << endl;
    cout << endl;
    //Check that GetSumValueFloat function can correctly get the total value of all nodes in BST
    cout << "Test GetSumValueFloat function" << endl;
    cout << intTree1.GetSumValueFloat() << endl;
    cout << "Test GetSumValueFloat with function as parameter" << endl;
    cout << weatherTree1.GetSumValueFloat(BST.GetWeatherWindSpeed) << endl;
    cout << endl;
    //Check that GetStringByFloatValue function can return correct string based on given float value
    cout << "Test GetStringByFloatValue with function as parameter" << endl;
    cout << weatherTree1.GetStringByFloatValue(BST.GetWeatherTimeBySolarRad, 53.15);
    cout << endl;

    return 0;
}

