/*****************************************************************************
*                    
*  Author:           Kolten Pulliam
*  Email:            klpulliam44@gmail.com
*  Label:            P03
*  Title:            Program 3 - Greedy Scheduling
*  Course:           CMPS-2433-101 Discrete Structures - Analysis
*  Semester:         Fall 2021
* 
*  Description:
*       This program optimizes a list of activities for a schedule.
* 
*  Usage:
*       N/A
* 
*  Files:            (list of all source files used in this program)
        prog3Pulliam.cpp
*****************************************************************************/
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/**
 * Activity
 * @description: A class to represent a specific activity
 * @methods:
 * private:
 *      
 * public:
 *      Activity()
 *      Activity(int s, int l)
 *      void Print(ostream& outFile)
 *      Activity& operator= (const Activity& other)
 *      
 */
class Activity{
  private:
    
  
  public:
    int start, length, finish;
    Activity(){
      start = 0;
      length = 0;
      finish = start + length;
    }
    
    Activity(int s, int l): start(s), length(l){
      finish = start + length;
    }

    void Print(ostream& outFile){
      outFile << setw(2) << start << setw(14) << length << setw(14) << finish << '\n';
    }

    Activity& operator= (const Activity& other){
      this->start = other.start;
      this->length = other.length;
      this->finish = other.finish;

      return *this;
    }
};

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
* @brief Function: insertionSort 
* 
* Sorts the vector that you pass in based on finish times of activity
* 
* @param vector<Activity>& act - The original vector to be sorted
* 
* @return void
*/
void insertionSort(vector<Activity>& act);

/**
* @brief Function: OptimizeActivity 
* 
* Creates the optimal schedule based on start times and length
* of activities
* 
* @param vector<Activity>& act - original sorted vector
* @param vector<Activity>& oAct - vector containing optimized schedule
* @param int size - size of the original sorted vector
* 
* @return void
*/
void OptimizeActivity(vector<Activity>& act, vector<Activity>& oAct, int size);


int main() {
  // Open files
  ifstream inFile;
  ofstream outFile;
  OpenFiles(inFile, outFile);

  // Create vector of activites
  vector<Activity> act;
  vector<Activity> oAct;

  // Read in values for act
  int size, start, length;
  inFile >> size;
  for (int i = 0; i < size; i++) {
    inFile >> start;
    inFile >> length;
    act.emplace_back(start, length);
  }

  // Sorts original vector
  insertionSort(act);

  // Optimizes sorted vector
  OptimizeActivity(act, oAct, act.size());

  outFile << "Kolten Pulliam\n"
    << "Program 3: Greedy Scheduling/Sorting Program\n"
    << setw(10) << "Start Time" 
    << setw(10) << "Length" 
    << setw(19) << "Finish Time\n";
  for (int i = 0; i < oAct.size(); i++) {
    oAct[i].Print(outFile);
  }
  outFile << "\nMaximun number of activities is " << oAct.size() << '\n';

  inFile.close();
  outFile.close();

  cout << "Program End\n";

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

/* Function to sort an array using insertion sort*/
void insertionSort(vector<Activity>& act)
{
  int size = act.size();
  Activity tmp;
  for(int i =1; i< size; i++){
    for(int j = i; j > 0; j--){
      if(act.at(j).finish < act.at(j-1).finish){
        tmp = act.at(j);
        act.at(j) = act.at(j-1);
        act.at(j-1) = tmp;
      }
    }
  }
}

// Optimizes schedule
void OptimizeActivity(vector<Activity>& act, vector<Activity>& oAct, int size){
  int curStart = act.at(0).finish;
  int curLength = act.at(0).length;
  oAct.push_back(act.at(0));
  // Checks if there are any times that are better
  for(int i = 1; i < size; i++){
    if (curStart <= act.at(i).start){
      curStart = act.at(i).finish;
      curLength = act.at(i).length;
      oAct.push_back(act.at(i));
      // Checks if there are any repeats of new value
      for (int j = i; j < size; j++){
        if (curLength > act.at(j).length 
        && curStart == act.at(j).start){
          curStart = act.at(j).finish;
          curLength = act.at(j).length;
          oAct.push_back(act.at(j));
        }
      }
    }
  }
}
