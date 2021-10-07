/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P02
*  Title:            Program 2 - Squares
*  Course:           CMPS-2433-101 Discrete Structures - Analysis
*  Semester:         Fall 2021
* 
*  Description:
*       This program reads in integers from a file, converts the integer to 
*       an n x n grid, and calculates how many smaller n x n square grids can 
*       fit inside of it by using iterative, recursive, and closed form solutions.
* 
*  Usage:
*       N/A
* 
*  Files:            (list of all source files used in this program)
        prog2Pulliam.cpp
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

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
void OpenFiles(ifstream& inFile, ofstream& outFile);

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
void ReadFiles(ifstream& inFile, ofstream& outFile);

/**
* @brief Function: Iterative 
* 
* Calculates the number of squares in an n x n grid using 
* an accumulator for summation.
* 
* @param int num - The number used to determine the size of
*                  the n x n grid.
* 
* @return int
*/
int Iterative(int num);

/**
* @brief Function: Recursive 
* 
* Calculates the number of squares in an n x n grid using 
* recursion to loop through the summation.
* 
* @param int num - The number used to determine the size of
*                  the n x n grid.
* 
* @return int
*/
int Recursive(int num);

/**
* @brief Function: ClosedForm
* 
* Calculates the number of squares in an n x n grid using 
* a closed-form formula derived from the hand calculations
* done on paper.
* 
* @param int num - The number used to determine the size of
*                  the n x n grid.
* 
* @return int
*/
int ClosedForm(int num);

// Main Driver
int main() {
  ifstream inFile;
  ofstream outFile;
  OpenFiles(inFile, outFile);

  outFile << "Kolten Pulliam\n";
  outFile << "Program 1: Squares\n\n";
  outFile << setw(3) << "N" << setw(10) << "LoopSum" 
          << setw(14) << "RecSoln" << setw(15) << "Closed\n";

  int numVal;
  inFile >> numVal;
  for (int i = 0; i < numVal; i++){
    ReadFiles(inFile, outFile);
  }
  
  cout << "The program has completed.\n";
  return 0;
}

// Opens the files being used
void OpenFiles(ifstream& inFile, ofstream& outFile){
  string inFileName;
  string outFileName;

  // Checks if the input file opened
  cout << "Please give the name of the input file...\n";
  cin >> inFileName;
  inFile.open(inFileName);
  while (!inFile.is_open()){
    cout << "The input file did not open, please try again...\n";
    cin >> inFileName;
  }
  cout << "The input file is now open.\n";

  // Checks if the output file opened
  cout << "Please give the name of the output file...\n";
  cin >> outFileName;
  outFile.open(outFileName);
  while (!outFile.is_open()){
    cout << "The output file did not open, please try again...\n";
    cin >> outFileName;
  }
  cout << "The output file is now open.\n";
}

// Reads and processes the data pulled from the input file
void ReadFiles(ifstream& inFile, ofstream& outFile){
  int num;
  inFile >> num;
  outFile << setw(3) << num << setw(10) << Iterative(num) 
          << setw(14) << Recursive(num) << setw(14) << ClosedForm(num) << '\n';
}

// Calculates number of squares iteratively
int Iterative(int num) {
  int iPow;
  int sum = 0;
  for (int i = 1; i <= num; i++) {
    iPow = pow(i, 2);
    sum += iPow;
  }
  return sum;
}

// Calculates number of squares recursively
int Recursive(int num) {
  if (num == 1){
    return 1;
  }
  return Recursive(num - 1) + pow(num, 2);
}

// Calculates number of squares with a closed-form formula
int ClosedForm(int num) {
  int result = (num * (num + 1) * ((2 * (num)) + 1))/6;
  return result;
}