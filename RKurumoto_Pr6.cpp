// Class: CMSC140 CRN 20778
// Instructor: Margaret Tseng
// Description: Project 6
// Program Name:   RKurumoto_Pr6.cpp
// Due:
// Platform/Compiler: Windows 7, Microsoft Visual Studio 2013
/* I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 
 Print your Name here: Rafaela Sumie Andrade Kurumoto
 */

// Input:
//  1. File name
// Output:
//  1. Lowest number
//  2. Highest number
//  3. Total sum
//  4. Average
// Process/Algorithm (Main Function):
//  1. Declaration & initialization
//  2. Ask user for file name
//  3. Open the file for input
//  4. If the file opened, process it (step 5 to 11), else go to step 12
//  5. Call funtion to fill array with numbers from the file
//  6. Close the file
//  7. Call function to calculate lowest
//  8. Call funtion to calculate highest
//  9. Call function to calculate total sum
//  10.Call function to calculate average
//  11.Display output
//  12.If file does not open, display error message and exit the program

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//prototypes
void inputNumbers (ifstream &inFile, int arrayNum[], int size);
int calculateLowest (int array[], int size);
int calculateHighest (int array[], int size);
int calculateTotal (int array[], int size);
double calculateAverage (double total, int size);

int main()
{
    //1. Declaration & initialization
    ifstream inFile;
    string fileName="";
    const int SIZE = 12;
    int arrayNum[SIZE];
    int lowestNumber = -1, highestNumber = -1;
    double totalSum = -1, average = -1.0;
    
    //2. Ask user for file name
    cout << "Please, enter the name of the file: ";
    cin >> fileName;
    
    //3. Open the file for input
    inFile.open(fileName, ios::in);
    
    //4. If the file opened, process it
    if (inFile)
    {
        //5. Fill array with numbers from the file
        inputNumbers (inFile, arrayNum, SIZE);
        
        //6. Close file
        inFile.close();
        
        //7. Calculate lowest
        lowestNumber = calculateLowest (arrayNum, SIZE);
        
        //8. Calculate highest
        highestNumber = calculateHighest (arrayNum, SIZE);
        
        //9. Calculate total
        totalSum = calculateTotal (arrayNum, SIZE);
        
        //10. Calculate average
        average = calculateAverage (totalSum, SIZE);
        
        //11. Display results
        cout << endl << setw(31) << left << "The lowest number is: " << setw(5) << left << lowestNumber << endl;
        cout << setw(31) << left << "The highest number is: " << setw(5) << left << highestNumber << endl;
        cout << setw(31) << left << "The total of the numbers is: " << setw(5) << left << totalSum << endl;
        cout << setprecision(2) << fixed;
        cout << setw(31) << left << "The average of the numbers is: " << setw(5) << left << average << endl << endl;
    }
    //12. If file does not open, display error message and exit the program
    else
    {
        cout << "Error opening the file." << endl << endl;
    }
    
    return 0;
}


//*** Input numbers ***
//Input
//1. Name of file
//2. Numbers from file
//3. Size of array
//Output:
//None
//Process:
//  1. set i to 0
//  2. while i is less than size repeat step 3 to 4. Otherwise go to step 5.
//  3. input number from file into array[i]
//  4. increase i by 1
//  5. return to main function

void inputNumbers (ifstream &inFile, int array[], int size)
{
    for (int i=0; i < size; i++)
    {
        inFile >> array[i];
    }
    return;
}

//***** Calculate the lowest ****
//Input
//1. Array
//2. Size of array
//Output:
// 1. Lowest
//Process:
//  1. set lowest to array[0]
//  2. set count to 1
//  3. while count is less than size repeat step 4 to 5. Otherwise go to step 6.
//  4. if array[count] is less then lowest, set lowest to array[count].
//  5. increase count by 1
//  6. return lowest

int calculateLowest (int array[], int size)
{
    int lowest;
    
    lowest = array[0];
    
    for (int count=1; count < size; count++)
    {
        if (array[count] < lowest)
        {
            lowest = array[count];
        }
    }
    
    return lowest;
}

//*** Calculate the highest *****
//Input
//1. Array
//2. Size of array
//Output:
// 1. Highest
//Process:
//  1. set highest to array[0]
//  2. set count to 1
//  3. while count is less than size repeat step 4 to 5. Otherwise go to step 6.
//  4. if array[count] is greater then highest, set highest to array[count].
//  5. increase count by 1
//  6. return highest

int calculateHighest (int array[], int size)
{
    int highest;
    
    highest = array[0];
    
    for (int count=1; count < size; count++)
    {
        if (array[count] > highest)
        {
            highest = array[count];
        }
    }
    
    return highest;
}


// **** Calculate total sum *****
//Input
//1. Array
//2. Size of array
//Output:
// 1. total
//Process:
//  1. set count to 0
//  2. while count is less than size repeat step 3 to 4. Otherwise go to step 5.
//  3. total = total + array[count]
//  4. increase count by 1
//  5. return total

int calculateTotal (int array[], int size)
{
    double total = 0;
    
    for (int count=0; count < size; count++)
    {
        total = total + array[count];
    }
    return total;
}

//**** Calculate average *****
//Input
//1. Total
//2. Size of array
//Output:
//1. Average
//Process:
//  1. avg = total / size
//  2. return avg

double calculateAverage (double total, int size)
{
    double avg = 0.0;
    
    avg = total / size;
    
    return avg;
}

