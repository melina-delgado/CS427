/*
 * CS427: OOP
 *
 * Author: Melina Delgado
 * Due date: 10/25/17 11:59pm
 *
 * cooccur.cpp : implementation of cooccur.h file
 */

#include "cooccur.h"
#include <iomanip>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <sstream>

CooccurrenceMatrix::CooccurrenceMatrix(std::vector<std::string> keywords)
  : nkeywords(keywords.size())
{
  for(int i = 0; i < nkeywords; i++)
  {
    keys.push_back(keywords[i]);
    keyPos.insert({keywords[i], i});
    keyMap.insert({keywords[i], 0.0});
  }

  matrix.resize(nkeywords);
  for(int i = 0; i < nkeywords; i++)
  {
    matrix[i].resize(nkeywords);
    for(int j = 0; j < nkeywords; j++)
    {
      matrix[i][j] = 0.0;
    }
  }
}

std::unordered_set<std::string> CooccurrenceMatrix::readContext(std::istream& is) const
{
  std::string context;
  getline(is, context);
  std::unordered_set<std::string> ret;
  if(!context.empty())
  {
    std::istringstream w(context);
    std::string word;
    while(w >> word)
    {
      for(int i = 0; i < nkeywords; i++)
      {
        if(word == keys[i])
        {
          ret.insert(word);
          break;
        }
      }
    }
  }

  return ret;
}

void CooccurrenceMatrix::update(const std::unordered_set<std::string>& context)
{
  for(auto it = context.begin(); it != context.end(); it++)
  {
    std::string word = *it;
    keyMap[word] += 1.0;
    int row = keyPos[word];
    for(auto jt = context.begin(); jt != context.end(); jt++)
    {
      int col = keyPos[*jt];
      matrix[row][col]++;
    }
  }
}

std::vector<double> CooccurrenceMatrix::getVector(const std::string& keyword) const
{
  auto pos = keyPos.at(keyword);
  auto count = keyMap.at(keyword);
  std::vector<double> ret;
  for(int i = 0; i < nkeywords; i++)
  {
    double num = matrix[pos][i]/count;
    ret.push_back(num);
  }

  return ret;
}

