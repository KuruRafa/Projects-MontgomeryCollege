// Class: CMSC140 CRN 20778
// Instructor: Margaret Tseng
// Description: Project 4
// Program Name:   RKurumoto_Pr4.cpp
// Due: 11/05/2017
// Platform/Compiler: Windows 10, Microsoft Visual Studio 2017
/* I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 
 Print your Name here: Rafaela Sumie Andrade Kurumoto
 */

// Input:
//  1. employee number
//  2. gross pay
//  3. state tax
//  4. federal tax
//  5. FICA withholdings
// Output:
//  1. total gross pay
//  2. total state tax
//  3. total federal tax
//  4. total FICA withholdings
//  5. net pay
// Process/Algorithm:
/*
 1.     Declaration & initialization.
 2.     Ask for employee number.
 3.     If employee number is less than 0 display error message.
 4.     While employee number is less than 0 go back to step 2, otherwise go to step 5.
 5.     While employee number is different than 0, repeat step 6 to 31, otherwise, go to step 32.
 6.     Ask user for gross pay, save it.
 7.     If gross pay is less than 0 display error message.
 8.     While gross pay is less than 0 go back to step 6, otherwise go to step 9.
 9.     Add gross pay to total gross pay.
 10.    Ask user for state tax, save it.
 11.    While state tax is less than 0 OR state tax greater than gross pay, repeat steps 12 through 14, otherwise go to step 15.
 12.    If state tax is less than 0 display error message.
 13.    If state tax is greater than gross pay, display error message.
 14.    Ask user for state tax again, save it. Go to step 11.
 15.    Add state tax to total state tax.
 16.    Ask user for federal tax, save it.
 17.    While federal tax is less than 0 OR federal tax is greater than gross pay, repeat steps 18 through 20, otherwise go to step 21.
 18.    If federal tax is less than 0, display error message.
 19.    If federal tax is greater than gross pay, display error message.
 20.    Ask user for federal tax again, save it. Go to step 17.
 21.    Add federal tax to total federal tax.
 22.    Ask user for FICA withholdings.
 23.    While FICA withholding is less than 0 OR FICA withholding is greater than gross pay,  repeat steps 24 through 26, otherwise go to step 27.
 24.    If FICA withholding is less than 0, display error message.
 25.    If FICA withholdings is greater than gross pay, display error message.
 26.    Ask user to enter FICA withholdings again, save it. Go to step 23.
 27.    Add FICA withholdings to total FICA withholdings.
 28.    Calculate employee sum =  state tax + federal tax + FICA withholdings
 29.    If employee sum is greater than gross pay, display error message. Subtract all invalid data (gross pay, state tax, federal tax, FICA). Set sumEmp to 0, since it was invalid data. Otherwise go to step 30.
 30.    Calculate total sum = total sum + employee sum.
 31.    Ask employee number again, validate it (same as step 3).  Go back to step 5.
 32.    (after user enters 0)  calculate net pay = total gross pay - total sum.
 33.    Display total gross pay, total state tax, total federal tax, total FICA withholdings, and net pay.
 */

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    // 1.   Declaration & initialization.
    int employeeN = 0;
    double grossPay, totalGross, stateTax, totalState, fedTax;
    double totalFed, ficaWith, totalFica, sumEmp, totalSum, netPay;
    //sumEmp = the sum of taxes/withholdings for each employee.
    //totalSum = total sum of all taxes/withholdings.
    
    grossPay = totalGross = stateTax = totalState = fedTax = 0.0;
    totalFed = ficaWith = totalFica = sumEmp = totalSum = netPay = 0.0;
    
    cout << "************* PAYROLL REPORT *************" << endl << endl;
    do
    {
        // 2.   Ask for employee number.
        cout << "Enter employee number (0 to exit): ";
        cin >> employeeN;
        
        //  3.   If employee number is less than 0 display error message.
        if (employeeN < 0)
        {
            cout << "** No negative numbers allowed ** " << endl;
        }
        // 4.   While employee number is less than 0 go back to step 2, otherwise go to step 5.
    } while (employeeN < 0);
    
    
    // 5.   While employee number is different than 0, repeat step 6 to 31, otherwise, go to step 32.
    while (employeeN != 0)
    {
        do
        {
            //6.   Ask user for gross pay, save it.
            cout << "Enter gross pay: $";
            cin >> grossPay;
            
            //7.   If gross pay is less than 0 display error message.
            if (grossPay < 0)
            {
                cout << "** Gross pay cannot be less than 0 **" << endl;
            }
            
            // 8.   While gross pay is less than 0 go back to step 6, otherwise go to step 9.
        } while (grossPay < 0);
        
        //9.   Add gross pay to total gross pay.
        totalGross += grossPay;
        
        //10.   Ask user for state tax, save it.
        cout << "Enter state tax: $";
        cin >> stateTax;
        
        //11.  While state tax is less than 0 OR state tax greater than gross pay, repeat steps 12 through 14, otherwise go to step 15.
        while (stateTax < 0 || stateTax > grossPay)
        {
            //12.   If state tax is less than 0 display error message.
            if (stateTax < 0)
            {
                cout << "** State Tax cannot be less than 0 **" << endl;
            }
            
            //13.   If state tax is greater than gross pay, display error message.
            if (stateTax > grossPay)
            {
                cout << "** State Tax cannot be greater than Gross Pay **" << endl;
            }
            
            //14. Ask user for state tax again, save it. Go to step 11.
            cout << "Enter state tax: $";
            cin >> stateTax;
        }
        
        // 15.   Add state tax to total state tax.
        totalState += stateTax;
        
        //16.   Ask user for federal tax, save it.
        cout << "Enter federal tax: $";
        cin >> fedTax;
        
        //17. While federal tax is less than 0 OR federal tax is greater than gross pay, repeat steps 18 through 20, otherwise go to step 21.
        while (fedTax < 0 || fedTax > grossPay)
        {
            //18.   If federal tax is less than 0, display error message.
            if (fedTax < 0)
            {
                cout << "** Federal Tax cannot be less than 0 **" << endl;
            }
            
            //19.   If federal tax is greater than gross pay, display error message.
            if (fedTax > grossPay)
            {
                cout << "** Federal Tax cannot be greater than Gross Pay **" << endl;
            }
            
            //20.   Ask for federal tax again, save it. Go back to step 17.
            cout << "Enter federal tax: $";
            cin >> fedTax;
        }
        
        //21.   Add federal tax to total federal tax.
        totalFed += fedTax;
        
        //22.   Ask user for FICA withholdings.
        cout << "Enter FICA withholdings: $";
        cin >> ficaWith;
        
        //23.   While FICA withholding is less than 0 OR FICA withholding is greater than gross pay,  repeat steps 24 through 26, otherwise go to step 27.
        while (ficaWith < 0 || ficaWith > grossPay)
        {
            //24.   If FICA withholding is less than 0, display error message.
            if (ficaWith < 0)
            {
                cout << "** FICA Withholdings cannot be less than 0 **" << endl;
            }
            
            //25.   If FICA withholdings is greater than gross pay, display error message.
            if (ficaWith > grossPay)
            {
                cout << "** FICA withholdings cannot be greater than Gross Pay **" << endl;
            }
            
            //26.   Ask user to enter FICA withholdings again, save it. Go to step 23.
            cout << "Enter FICA withholdings: $";
            cin >> ficaWith;
        }
        
        //  27.   Add FICA withholdings to total FICA withholdings.
        totalFica += ficaWith;
        
        //28.   Calculate employee sum =  state tax + federal tax + FICA withholdings
        sumEmp = stateTax + fedTax + ficaWith;
        
        // 29.   If employee sum is greater than gross pay, display error message. Subtract all invalid data (gross pay, state tax, federal tax, FICA). Set sumEmp to 0, since it was invalid data. Otherwise go to step 30.
        if (sumEmp > grossPay)
        {
            cout << "\n** Withholdings cannot exceed Gross Pay ** " << endl;
            cout << "Please, enter the data for this employee again." << endl;
            totalGross -= grossPay; // subtracting so it won't add to the result since it
            totalState -= stateTax; // was invalid data
            totalFed -= fedTax;
            totalFica -= ficaWith;
            sumEmp = 0; // setting the sumEmp to 0 will make the program continue to next step,
            //and will erase the invalid data entered.
        }
        
        // 30.   Calculate total sum = total sum + employee sum.
        totalSum += sumEmp;
        
        
        // 31.   Ask employee number again, validate it (same as step 3).  Go back to step 5.
        do
        {
            cout << "\n\nEnter employee number (0 to exit): ";
            cin >> employeeN;
            
            if (employeeN < 0)
            {
                cout << "** No negative numbers allowed **" << endl;
            }
        } while (employeeN < 0);
    }
    
    //32.   (after user enters 0)  calculate net pay = total gross pay - total sum.
    netPay = totalGross - totalSum;
    
    //33.   Display total gross pay, total state tax, total federal tax, total FICA withholdings, and net pay.
    cout << "\n*****************************************" << endl;
    cout << fixed << setprecision(2);
    cout << setw(26) << left << "Total Gross Pay:" << right << "$ ";
    cout << setw(8) << right << totalGross << endl;
    cout << setw(26) << left << "Total State Tax:" << right << "$ ";
    cout << setw(8) << right << totalState << endl;
    cout << setw(26) << left << "Total Federal Tax:" << right << "$ ";
    cout << setw(8) << right << totalFed << endl;
    cout << setw(26) << left << "Total FICA Withholdings:" << right << "$ ";
    cout << setw(8) << right << totalFica << endl;
    cout << setw(26) << left << "Total Net Pay:" << right << "$ ";
    cout << setw(8) << right << netPay << endl << endl;
    
    return 0;
}
