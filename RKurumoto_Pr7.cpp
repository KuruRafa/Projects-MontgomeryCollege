// Class: CMSC140 CRN 20778
// Instructor: Margaret Tseng
// Description: Project 7
// Program Name:   RKurumoto_Pr7.cpp
// Due: 12/10/2017
// Platform/Compiler: Windows 10, Microsoft Visual Studio 2017
/* I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 
 Print your Name here: Rafaela Sumie Andrade Kurumoto
 */

// Program Input:
//  1. Name of file to read the names from
//  2. Number of names to read
//  3. Name of file to save sorted names to
// Program Output:
//  1. Names in original order
//  2. Names in alphabetical order
// Process/Algorithm:
//  (see Main Function)

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Function prototypes
int readNames(bool &openFile, string arrayNames[]);
void displayUnsorted(string arrayNames[], int size);
void displaySorted(string arrayNames[], int size);
void saveSorted(string arrayNames[], int size);

//(Main Function)
// Process/Algorithm:
//  1. call function (readNames). Assign return value to size and use boolean reference to check file.
//  2. if file opens (openFile is true) do steps 3 to 5. Otherwise go to step 6.
//  3. call function (displayUnsorted)
//  4. call function (displaySorted)
//  5. call function (saveSorted)
//  6. If open does NOT open (openFile is false), display error message and exit the program.
int main()
{
    int size = 100;
    string arrayNames[size];
    bool openFile;
    
    //** TITLE**
    cout << "****************   Sorting Names in Ascending Order   ****************" << endl << endl;
    
    //  1. call function (readNames). Assign return value to size and use boolean reference to check file.
    size = readNames(openFile, arrayNames);
    
    //  2. if file opens (openFile is true) do steps 3 to 5. Otherwise go to step 6.
    if (openFile == true)
    {
        //  3. call function (displayUnsorted)
        cout << "\n\n*****  These are the names in original order  *****" << endl << endl;
        displayUnsorted(arrayNames, size);
        
        //  4. call function (displaySorted)
        cout << "\n\n*****  These are names in alphabetical order  *****" << endl << endl;
        displaySorted(arrayNames, size);
        
        //  5. call function (saveSorted)
        saveSorted(arrayNames, size);
    }
    
    //  6. If open does NOT open (openFile is false), display error message and exit the program.
    else
    {
        cout << "Error openning the file." << endl << endl;
    return 0;
    }
}

//***** read names into array and validate file *****
//Input:
//  1. file name
//  2. number of names
//Output:
//  1. number
//Process:
//  1. ask user to enter the name of the file
//  2. ask user to enter number of names to read
//  3. open file for input
//  4. if file opens do steps 5 through 10. Otherwise go to step 11.
//  5. set openFile to true
//  6. initialize i to 0.
//  7. while i is less then number, do step 8 and 9. Otherwise go to step 10.
//  8. input line of the file into the array.
//  9. increase i by 1 (it's inside the for loop)
//  10. close file
//  11. if file does NOT open, set openFile to false.
//  12. return number
int readNames(bool &openFile, string arrayNames[])
{
    string fileName = "";
    int number = -1;
    ifstream inFile;
    
    //  1. ask user to enter the name of the file
    cout << "Please, enter the name of the file that contains the names: ";
    cin >> fileName;
    
    //  2. ask user to enter number of names to read
    cout << "Please, enter the number of names to read: ";
    cin >> number;
    
    //  3. open file for input
    inFile.open(fileName, ios::in);
    
    //  4. if file opens do steps 5 to 10. Otherwise go to step 11.
    if (inFile)
    {
        //  5. set openFile to true
        openFile = true;
        
        //  6. initialize i to 0.
        //  7. while i is less then number, do step 8 and 9. Otherwise go to step 10.
        for (int i = 0; i < number; i++)
        {
            //  8. input line of the file into the array.
            getline(inFile, arrayNames[i]);
            
            //  9. increase i by 1 (it's inside the for loop)
        }
        //  10. close file
        inFile.close();
    }
    
    //  11. if file does NOT open, set openFile to false.
    else
    {
        openFile = false;
    }
    
    //  12. return number
    return number;
}

//***** display unsorted names *****
//Input:
//1. array
//2. size
//Output:
//1. array content
//Process:
//1. set i to 0
//2. while i is less than size do steps 3 and 4. Otherwise go to step 5.
//3. display array[i]
//4. increase i by 1
//5. return to main function
void displayUnsorted(string arrayNames[], int size)
{
    //1. set i to 0
    //2. while i is less than size do steps 3 and 4. Otherwise go to step 5.
    for (int i = 0; i < size; i++)
    {
        //3. display array[i]
        cout << arrayNames[i] << endl;
        
        //4. increase i by 1 (in the for loop)
    }
    
    //5. return to main function
    return;
}

//**** sort and display sorted names ****
//Input:
//1. array
//2. size
//Output
//1. array content
//Proocess:
//1. set start to 0.
//2. while start is less than (size - 1) do steps 3 through 11. Otherwise go to step 12.
//3. set minIndex to start, and minValue to array[start]
//4. set index to (start + 1).
//5. while index is less than size do steps 6 through 8. Otherwise go to step 9.
//6. if content in array[index] is less than minValue do steps 7. Otherwise skip to step 8.
//7. set minValue to array[index], and set minIndex to index.
//8. increase index by 1 (in for loop)
//9. set temp to content in array[minIndex], and set array[minIndex] to array[start].
//10. set array[start] to temp.
//11. increase start by 1 (in for loop)
//12. set i to 0.
//13. while i is less than size do steps 14 and 15. Otherwise go to step 16.
//14. display array[i]
//15. increase i by 1 (in for loop)
//16. return to main function
void displaySorted(string arrayNames[], int size)
{
    int minIndex;
    string minValue;
    
    //1. set start to 0.
    //2. while start is less than (size - 1) do steps 3 through 11 . Otherwise go to step 12.
    for (int start = 0; start < (size - 1); start++)
    {
        //3. set minIndex to start, and minValue to array[start]
        minIndex = start;
        minValue = arrayNames[start];
        
        //4. set index to (start + 1).
        //5. while index is less than size do steps 6 through 8. Otherwise go to step 9.
        for (int index = start + 1; index < size; index++)
        {
            //6. if content in array[index] is less than minValue do steps 7. Otherwise skip to step 8.
            if (arrayNames[index] < minValue)
            {
                //7. set minValue to array[index], and set minIndex to index.
                minValue = arrayNames[index];
                minIndex = index;
            }
            //8. increase index by 1 (in for loop)
        }
        //9. set temp to content in array[minIndex], and set array[minIndex] to array[start].
        //10. set array[start] to temp.
        string temp = arrayNames[minIndex];
        arrayNames[minIndex] = arrayNames[start];
        arrayNames[start] = temp;
    
        //11. increase start by 1 (in for loop)
    }
    
    //12. set i to 0.
    //13. while i is less than size do steps 14 and 15. Otherwise go to step 16.
    for (int i=0; i < size; i++)
    {
        //14. display array[i]
        cout << arrayNames[i] << endl;
        
        //15. increase i by 1 (in for loop)
    }
    
    //16. return to main function
    return;
}

//***** Save sorted names *****
//Input:
//1. file name to save names
//2. array
//3. size
//Output:
//1. array contents
//Process
//1. ask user for file name
//2. open file
//3. set i to 0.
//4. while i is les than size do steps 5 to 6. Otherwise go to step 7.
//5. output content of array[i] into file
//6. increase i by 1
//7. close file
//8. return to main function
void saveSorted(string arrayNames[], int size)
{
    ofstream outFile;
    string fileName;
    
    //1. ask user for file name
    cout << "\nPlease, enter the name of the file to save the sorted names to: ";
    cin >> fileName;
    
    //2. open file
    outFile.open(fileName, ios::out);
    
    //3. set i to 0.
    //4. while i is les than size do steps 5 to 6. Otherwise go to step 7.
    for (int i = 0; i < size; i++)
    {
        //5. output content of array[i] into file
        outFile << arrayNames[i] << endl;
        
        //6. increase i by 1 (in for loop)
    }
    
    //7. close file
    outFile.close();
    
    //8. return to main function
    return;
}

