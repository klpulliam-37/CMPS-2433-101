/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P01
*  Title:            Program 1 - Bitwise Operations
*  Course:           CMPS-2433-101 Discrete Structures - Analysis
*  Semester:         Fall 2021
* 
*  Description:
*       This program reads in integers from a file, and reverses
*       the bits of the integer. It then prints out the original 
*       and the reversed values side by side.
* 
*  Usage:
*       N/A
* 
*  Files:            (list of all source files used in this program)
        prog1Pulliam.cpp
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>

using namespace std;

void OpenFiles(ifstream& inFile, ofstream& outFile); // Opens the files
void ReadFiles(ifstream& infile, ofstream& outFile); // Reads the files
int ReverseNum(int num); // Reverses the numbers bits given to it

// Main Driver for the program
int main() {
  ifstream inFile;
  ofstream outFile;
  OpenFiles(inFile, outFile);

  outFile << "Kolten Pulliam\nProgram 1: Bitwise Operations\n";
  outFile << "\nNumber " << setw(10) << " Reverse\n";
  ReadFiles(inFile, outFile);

  cout << "The processed data is now in 'output.txt'"; 

  return 0;
}

/**
* @brief Function: OpenFiles 
* 
* Opens the files we want to use and create.
* 
* @param ifstream& inFile - The input file we are pulling data from
* @param ofstream& outFile - The output file we are sending data to
* 
* @return void
*/
void OpenFiles(ifstream& inFile, ofstream& outFile){
  string inFileName;
  string outFileName;

  cout << "Enter the input filename: ";
  cin >> inFileName; // Gets name of input file from user
  inFile.open(inFileName); // Opens the input file
  cout << "The infile is now open\n\n";
  
  cout << "Enter the output filename: ";
  cin >> outFileName; // Gets name of output file from user
  outFile.open(outFileName); // Opens the output file
  cout << "The outfile is now open\n\n";
}

/**
* @brief Function: ReadFiles 
* 
* Reads through the input file we give the program.
* 
* @param ifstream& inFile - The input file we are pulling data from
* @param ofstream& outFile - The output file we are sending data to
* 
* @return void
*/
void ReadFiles(ifstream& inFile, ofstream& outFile){
  int num = 0, result = 0;
  while (inFile >> num){
    outFile << setw(6) << num << setw(10) << ReverseNum(num) << '\n';
  }
}

/**
* @brief Function: ReverseNum
* 
* Reverses the integer we pass in based on an unsigned short integer
* 
* @param int num - The integer we want to reverse
* 
* @return int
*/
int ReverseNum(int num){
  int numRev = 0; // Sets the bits for our reversed number to zero

  // Loops sixteen times to reverse the bits in our number
  for (int i = 0; i < 16; i++){
    numRev = numRev << 1; // Shifts our reversed number to the left

    // Checks if the last bit in our integer is equal to 1
    if ((num & 1) == 1){
      // Adds a 1 to our reversed number if 
      // there is a 1 in the last bit of our integer
      numRev = numRev ^ 1; 
    }
    
    // Shifts our integer's bits to the right to text the next bit
    num = num >> 1;
  }

  // Returns the reversed number once all of the 
  // bits in our integer have been tested
  return numRev;
}