/*
 * CS427: OOP
 *
 * Author: Melina Delgado
 * Due date: 10/25/17 11:59pm
 *
 * main_cooccur.cpp 
 */

#include <unordered_map>
#include <iomanip>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include "cooccur.h"

int main(int argc, char **argv)
{
  /*Read from cmdline*/
  std::vector<std::string> keywords;
  if(argc == 1)
  {
    std::cerr << "Must include a non-empty list of unique keywords" << std::endl;
    exit(1);
  }

  for(int i = 1; i < argc; i++)
  {
    if(std::find(keywords.begin(), keywords.end(), argv[i]) != keywords.end())
    {
      std::cerr << "Must include a list of unique keywords" << std::endl;
      exit(1);
    }
    else
    {
      keywords.push_back(argv[i]);
    }
  }

  /*Using class funtions*/
  std::unordered_set<std::string> readKeys;
  CooccurrenceMatrix matrix(keywords);
  while(std::cin)
  {
    readKeys = matrix.readContext(std::cin);
    matrix.update(readKeys);
  }

  std::vector<double> row;
  std::cout << std::fixed << std::setprecision(6);
  int nkeywords = keywords.size();
  for(int i = 0; i < nkeywords; i++)
  {
    row = matrix.getVector(keywords[i]);

    if(row[0] == -1.0)
    {
      break;
    }
    std::cout << keywords[i] << ": [";
    for(int j = 0; j < nkeywords - 1; j++)
    {
      std::cout << row[j] << ", "; 
    }
    std::cout << row[nkeywords - 1] << "]" << std::endl;
  }
}
