/***********
 * Author :   Mohammed Akram
 * Date  :   28 OCT,  2023
 * Version :  2.0
************/

/******************************************************************************
 * Version          Date                         Author
 * 2.0              30 OCT, 2023               Mohammed Akram
***************************************************************************/
#ifndef HElperFunctions_hpp
#define HElperFunctions_hpp


#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <assert.h>

using namespace std;

/*   Helper functions */
vector<string> ReadFileLines(const string &path) ;
	

void WriteFileLines(const string &path, const vector<string> &lines, bool append = true) ;

vector<string> SpilitStringToVector(const string &str, const string &delimiter = ",") ;

int StringToInt(const string &str) ;

int ReadInt(int low, int high);

int ShowReadMenu(const vector<string> &choices) ;


#endif