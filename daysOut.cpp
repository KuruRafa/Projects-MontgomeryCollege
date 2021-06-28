// Class: CMSC140  CRN 20778
// Instructor: Margaret Tseng
// Description: project 5 days out
// Program Name:   daysOut.cpp
// Due: 11/19/2017
// Platform/Compiler: Windows 10, Microsoft Visual Studio 2017
/* I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 
 Print your Name here: Rafaela Sumie Andrade Kurumoto
 */

// Input:
//  1. Number of Employees
//  2. Employee ID
//  3. Days Absent
// Output:
//  1. Employee ID
//  2. Days Absent
//  3. Number of Employees
//  4. Total days absent
//  5. Average
// Process/Algorithm **** Main Function *****:
//  1. get number of employees
//  2. open file for output
//  3. ask and save employee ID and days missed
//  4. calculate average days missed
//  5. output number of employees, total of days absent, and average in a file
//  6. close file

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//global variables
const string PROGRAMMER = "Programmer: Rafaela Sumie Andrade Kurumoto";

//function prototypes
int numberOfEmployees();
int daysAbsent(ofstream &outFile, int numEmp);
double averageDays(int numEmp, double totalDays);

//***** MAIN FUNCTION *****
int main()
{
    //declaration & initialization
    int numEmp = -1;
    int totalDays;
    double average;
    ofstream outFile;
    
    //title
    cout << "*** Average number of days a company's employees were absent ***" << endl << endl;
    
    //get number of employees
    numEmp = numberOfEmployees();
    
    //open file for output
    outFile.open("/Users/MacUser/Desktop/Montgomery College/Intro to Programming/Project 5/RKurumoto_Project5/RKurumoto_Project5/employeeAbsences.txt", ios::out);
    
    //title of file
    outFile << "***** Employee Absence Report ******" << endl << endl;
    outFile << "Employee ID"<< "   Days Missed" << endl;
    
    //ask and save employee ID and days missed
    totalDays = daysAbsent(outFile, numEmp);
    
    //calculate average of days missed
    average = averageDays(numEmp, totalDays);
    
    //print out programmer's name on screen
    cout << "\n" << PROGRAMMER << endl;
    
    //output number of employees, total of days absent, and average in a file
    outFile << "\nThe "<< numEmp << " employees were absent for a total of " << totalDays << " days." << endl;
    outFile << fixed << setprecision(1);
    outFile << "The average number of days absent is " << average << " days."<< endl << endl;
    
    //print out programmer's name in file
    outFile << PROGRAMMER << endl;
    
    //close file
    outFile.close();
    
    return 0;
}

//******** Get number of employees ********
//Input: number of employees
//Output: number of employees
//Process:
//1. Ask and save number of employees
//2. Validate number of employees
//3. Return number of employees

int numberOfEmployees()
{
    int numEmp = 0;
    
    //Ask and save number of employees
    cout << "Please, enter the number of employees in the company: ";
    cin >> numEmp;
    
    //Validate number of employees
    while (numEmp < 1)
    {
        if (numEmp < 1)
        {
            cout << "Number of employees cannot be less than 1." << endl;
            cout << "Please, re-enter the number of employees in the company: ";
            cin >> numEmp;
        }
    }
    
    //Return number of employees
    return numEmp;
}

//****** get ID and days absent ******
//Input:
//  1. employee ID
//  2. days absent
//Output:
//  1. total of days
//Process:
//  (Repeat steps 1 to 4 for all the employees)
//  1. Ask for employee ID
//  2. Ask for number of days absent
//  3. Validade number of days absent
//  4. Output in a file employee ID and days absent
//  5. calculate total days = total days + days absent
//  6. Return total days

int daysAbsent(ofstream &outFile, int numEmp)
{
    int empId, daysMissed, count=0;
    int static totalDays;
    
    do
    {
        //Ask for employee ID
        cout << "\nPlease, enter employee's ID: ";
        cin >> empId;
        
        //Ask for number of days absent
        cout << "Please, enter number of days this employee was absent: ";
        cin >> daysMissed;
        
        //Validade number of days absent
        while (daysMissed < 0)
        {
            if (daysMissed < 0)
            {
                cout << "Numbers absent cannot be negative." << endl;
                cout << "Please, re-enter number of days this employee was absent: ";
                cin >> daysMissed;
            }
        }
        
        //output in a file employee ID and days absent
        outFile << setw(8) << right << empId << setw(11) << right << daysMissed << endl;
        
        //calculate total days = total days + days absent
        totalDays = totalDays + daysMissed;
        count++;
        
    } while (count < numEmp);
    
    //return total of days
    return totalDays;
}

//***** calculate average *****
//Input:
//  1. number of Employees
//  2. total of days
//Output:
//  1. average
//Process:
//  1. average = total of days / number of employees
//  2. return average

double averageDays(int numEmp, double totalDays)
{
    double average = 0.0;
    
    //average = total of days / number of employees
    average = totalDays / numEmp;
    
    //return average
    return average;
}



