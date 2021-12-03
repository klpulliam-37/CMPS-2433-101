/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P04
*  Title:            Program 4 - Combinatorics
*  Course:           CMPS-2433-101 Discrete Structures - Analysis
*  Semester:         Fall 2021
* 
*  Description:
*       This program calculates the total number of combinations of students 
*       that are participating in an event based on the number of schools 
*       chosen.
* 
*  Usage:
*       N/A
* 
*  Files:            (list of all source files used in this program)
        prog4Pulliam.cpp
*****************************************************************************/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

/**
* @brief Function: openFiles 
* 
* Opens the files we want to use and create.
* 
* @param ifstream& inFile - The input file we are pulling data from.
* @param ofstream& outFile - The output file we are sending data to.
* 
* @return void
*/
void openFiles(ifstream& inFile, ofstream& outFile);

/**
* @brief Function: closeFiles 
* 
* Closes the files we opened at the start of the program.
* 
* @param ifstream& inFile - The input file we are pulling data from.
* @param ofstream& outFile - The output file we are sending data to.
* 
* @return void
*/
void closeFiles(ifstream& inFile, ofstream& outFile);

/**
* @brief Function: factorial 
* 
* Calculates the factorial of an integer utilizing iterations
* over recursion.
* 
* @param int x - The value we want to find the factorial of.
* 
* @return int
*/
int factorial(int x);

/**
* @brief Function: C 
* 
* Calculates the combinations based on two given values while 
* somewaht handling overflow.
* 
* @param int n - The total amount of items we are pulling from.
* @param int r - The sample of item we are allowed to choose from n.
* 
* @return unsigned long long int
*/
unsigned long long int C(int n, int r);

/**
* @brief Function: C 
* 
* Calculates the total combinations of students from all of the
* chosen schools.
* 
* @param ofstream& outFile - The output file we are sending data to.
* 
* @return void
*/
void numComb(ifstream& inFile, ofstream& outFile);

int main() {
  ifstream inFile;
  ofstream outFile;
  openFiles(inFile, outFile);

  outFile << "Kolten Pulliam\n"
  << "Program 4: Combinatorics\n\n";

  numComb(inFile, outFile);

  closeFiles(inFile, outFile);
  
  cout << "Program End...\n";
  return 0;
} 

// Opens the files being used
void openFiles(ifstream& inFile, ofstream& outFile){
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

void closeFiles(ifstream& inFile, ofstream& outFile) {
  inFile.close();
  outFile.close();
}

// Calculates the factorial of an integer
int factorial(int x) {
  int n = x - 1;
  for (int i = n; i > 0; i--) {
    x *= i;
  }
  return x;
}

// Function that calculates combinations
unsigned long long int C(int n, int r) {
    // Picks the smaller version of r
    if(r > n - r) {
      r = n - r;
    }
    unsigned long long int numComb = 1;
    int i;

    for(i = 1; i <= r; i++) {
        numComb *= n - r + i;
        numComb /= i;
    }

    return numComb;
}

// Calculates the total number of combinations 
void numComb(ifstream& inFile, ofstream& outFile) {
  int N, A, B, D;
  unsigned long long int schoolComb = 1;
  unsigned long long int studComb = 1;

  while(!inFile.eof()) {
    inFile >> N;
    inFile >> A;
    inFile >> B;
    inFile >> D;

    schoolComb = C(N,A);    
    
    studComb = 1;
    for (int i = 0; i < A; i++) {
      studComb *= C(B,D);
    }
    outFile << (schoolComb * studComb) % 1000000007 << '\n';
 }
}
