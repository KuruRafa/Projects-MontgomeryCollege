// Class: CMSC140   CRN 20778
// Instructor: Margaret Tseng
// Description: Project 2-2. Calculate the weight of the crystal to build a pyramid.
// Program Name:   RKurumoto_Pr2_2.cpp
// Due: 10/01/2017
// Platform/Compiler: Windows 10, Microsoft Visual Studio 2017
/* I pledge that I have completed the programming assignment independently.
 I have not copied the code from a student or any source.
 I have not given my code to any student.
 
 Print your Name here: Rafaela Sumie Andrade Kurumoto
 */

// Input:
//  1. length
//  1. width
//  3. height
// Output:
//  1. length, width, height, and weight of crystal to mold the pyramid.
// Process/Algorithm:
//  1. define constant for mold volume
//  2. declare variables length, width, height, volume, area, and pounds
//  3. ask user for pyramid's lenght. Read lenght
//  4. ask user for pyramid's width. Read width
//  5. calculate area of pyramid base (lenght * width)
//  6. ask user for pyramid's height. Read height
//  7. calculate volume of piramid ((area * height ) / 3)
//  8. calculate weight of material needed (volume / mold volume)
//  9. Display length, width, height, and weight(pounds).

#include <iostream>
#include <string>
using namespace std;

int main()
{
    //declaration
    const double MOLD_VOL = 27.7;
    double length = 0.0, width = 0.0, area = 0.0,
           height = 0.0, volume = 0.0, pounds = 0.0;
    
    //prompt user
    cout << "Enter the length of the pyramid in inches: ";
    cin >> length;
    cout << "Enter the width of the pyramid in inches: ";
    cin >> width;
    
    //calculate area of pyramid base
    area = length * width;
    
    //prompt user
    cout << "Enter the height of the pyramid in inches: ";
    cin >> height;
    
    //calculate volume and pounds of crystal needed
    volume = (area * height) / 3;
    pounds = volume / MOLD_VOL;
    
    //display results
    cout << "\nTo mold a pyramid with the length of " << length << " inches, width of " << width;
    cout << " inches, and height of " << height << " inches, you'll need " << pounds;
    cout << " pounds of crystal." << endl << endl;
 
    
    return 0;
}
