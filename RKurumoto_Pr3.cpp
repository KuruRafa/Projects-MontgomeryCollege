// Class: CMSC140   CRN 20778
// Instructor: Margaret Tseng
// Description: Project 3- Calculate shipping charges.
// Program Name:   RKurumoto_Pr3.cpp
// Due: oct/15/2017
// Platform/Compiler: Windows 10, Microsoft Visual Studio 2017
/* I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 
 Print your Name here: Rafaela Sumie Andrade Kurumoto
 */

// Input:
//  1. weight
//  2. distance
// Output:
//  1. charges
/* Process/Algorithm:
1. Declare and initialize double variables for weight and charges. Integer variables for distance.
2. Prompt  and save weight and distance.
3. Validade inputs. If one of the inputs is NOT valid display error message and exit the program.
4. Calculate charges based on weight and distance:
 a. weight is 2 kg or less, charge will be $1.10 per 500 miles
    (distance + 499) / 500 * 1.10
 b. weight is over 2 kg but not more than 6 kg, charge will be $2.20 per 500 miles
    (distance + 499) / 500 * 2.20
 c. weight is over 6 kg but not more than 10 kg, charge will be $3.70 per 500 miles
    (distance + 499) / 500 * 3.70
 d. weight is over 10 kg but not more than 20 kg, charge will be $4.80 per 500 miles
    (distance + 499) / 500 * 4.80
 e. else display error message.
5. Display charges.
*/

/*******Explanation of calculation:
 Rounding up the distance in miles to next 500’s to calculate:
 Since the charges are per 500 per miles shipped, in the calculation, I add 499 to the distance and then I divide it by 500 to have the integer of how many times I have to multiply the rate by.
 Example: If the user enters 10 miles, and I divide it by 500, it would get 0. So adding 499 to it I will get 509, dividing by 500 = 1 (integer division). So the rate can be applied properly. (ex, a 2 kg package, from 10 miles to 500 = $1.10).
 If the user enters 501, it will get to the next 500’s, since it’s one number over 500. Example: 501 + 499) / 500 = 2, for a package of 2 kg, from 501 miles to 1000 miles, it would be 2 * 1.10 = 2.20.
 ********/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    //declare and initialize
    double weight = 0.0, charge = 0.0;
    int distance = 0;
    
    //prompt and save
    cout << "-----------------Shipping Charges Calculation--------------------" << endl;
    cout << "Enter the weight of the package in kilograms (max 20 kg): ";
    cin >> weight;
    cout << "Enter the distance in miles the package is to be shipped (min 10 max 3000 miles): ";
    cin >> distance;
    
    //validation
    if (weight > 20)
        cout << "Maximum weight is 20 kg. Program ending." << endl;
    else if (weight <= 0)
        cout << "Invalid weight. Program ending." << endl;
    else if (distance < 10 || distance > 3000)
        cout << "Minimum distance is 10 miles. Maximum distance is 3000 miles." << endl;
    else
        {
            //claculation
            if (weight <= 2)
                charge = (distance + 499) / 500 * 1.10;
            else if (weight > 2 && weight <= 6)
                charge = (distance + 499) / 500 * 2.20;
            else if (weight > 6 && weight <= 10)
                charge = (distance + 499) / 500 * 3.70;
            else if (weight > 10 && weight <= 20)
                charge = (distance + 499) / 500 * 4.80;
            else
                cout << "Error. Program Ending." << endl;
            
            //display charges
            cout << setprecision(2) << fixed;
            cout << "\nYour total charges will be $" << charge << endl;
        }
    //I did the calculation and output inside of curly braces
    //so the output charge will show only if valid inputs are entered.
    
    return 0;
}
