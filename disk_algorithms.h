#ifndef DISK_ALGORITHMS_H
#define DISK_ALGORITHMS_H
#define NUM_CYLINDERS 3000

#include <iostream>
#include <map>
#include <cstdlib>
#include <vector>
#include <climits>
#include <algorithm>
//*******************************************************************
//
// FCFS Function
//
// This function utilizes the first come first served disk scheduling algorithm
//
// Return Value
// ------------
// int             returns an integer (tot_distance) signaling the amount of cylinders the disk head travelled
//
// Value Parameters
// ----------------
// const vector<int>		requests    a vector that stores the disk requests
// int		                initial		an integer that stores the initial position of disk head
//*******************************************************************
int FCFS(int initial, const std::vector<int> &requests);

//*******************************************************************
//
// SSTF Function
//
// This function utilizes the shortest seek time first disk scheduling algorithm
//
// Return Value
// ------------
// int             returns an integer (tot_distance) signaling the amount of cylinders the disk head travelled
//
// Value Parameters
// ----------------
// const vector<int>		requests    a vector that stores the disk requests
// int		                initial	    an integer that stores the initial position of disk head
//*******************************************************************
int SSTF(int initial, const std::vector<int> &requests);

//*******************************************************************
//
// SCAN Function
//
// This function utilizes the SCAN disk scheduling algorithm
//
// Return Value
// ------------
// int             returns an integer (tot_distance) signaling the amount of cylinders the disk head travelled
//
// Value Parameters
// ----------------
// const vector<int>		requests    a vector that stores the disk requests
// int		                initial	    an integer that stores the initial position of disk head
//*******************************************************************
int SCAN(int initial, const std::vector<int> &requests);

//*******************************************************************
//
// C-SCAN Function
//
// This function utilizes the first come first served disk scheduling algorithm
//
// Return Value
// ------------
// int             returns an integer (tot_distance) signaling the amount of cylinders the disk head travelled
//
// Value Parameters
// ----------------
// const vector<int>		requests    a vector that stores the disk requests
// int		                initial		an integer that stores the initial position of disk head
//*******************************************************************
int C_SCAN(int initial, const std::vector<int> &requests);

//*******************************************************************
//
// LOOK Function
//
// This function utilizes the first come first served disk scheduling algorithm
//
// Return Value
// ------------
// int             returns an integer (tot_distance) signaling the amount of cylinders the disk head travelled
//
// Value Parameters
// ----------------
// const vector<int>		requests    a vector that stores the disk requests
// int		                initial		an integer that stores the initial position of disk head
//*******************************************************************
int LOOK(int initial, const std::vector<int> &requests);

//*******************************************************************
//
// C_LOOK Function
//
// This function utilizes the first come first served disk scheduling algorithm
//
// Return Value
// ------------
// int             returns an integer (tot_distance) signaling the amount of cylinders the disk head travelled
//
// Value Parameters
// ----------------
// const vector<int>		requests    a vector that stores the disk requests
// int		                initial	    an integer that stores the initial position of disk head
//*******************************************************************
int C_LOOK(int initial, const std::vector<int> &requests);

#endif