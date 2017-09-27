/*
 *
 * Distance.cpp 
 *
 * Author: Melina Delgado
 * CPSC 427
 *
 */

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;
using std::cerr;
using std::istringstream;
using std::signbit;

int main(int argc, char **argv)
{
  string lat1;
  string long1;
  string lat2;
  string long2;
 
  double deg = 0.0;
  double min = 0.0;
  double sec = 0.0;
  double DD_lat1 = 0.0;
  double DD_long1 = 0.0;
  double DD_lat2 = 0.0;
  double DD_long2 = 0.0;
  bool deg_neg = false;
  /*get latitude of first point*/
  getline(cin, lat1);
  if(lat1.empty())      //check if given empty input
  {
    cerr << "Longitudes and latitudes must be a number" << endl;
    exit(1);
  }
  else      //read deg, mins, secs
  {
    istringstream ss(lat1);
    if(ss >> deg)
    {
      if(deg < 0 || signbit(deg))
      {
        deg_neg = true;
      }
      if(ss >> min)
      {
        if(min < 0.0)
        {
          cerr << "minutes can't be negative" << endl;
          exit(1);
        }
        min = min/60.0;

        if(deg_neg)
        {
          min = -1 * min;
        }
        if(ss >> sec)
        {
          if(sec < 0.0)
          {
            cerr << "seconds can't be negative" << endl;
            exit(1);
          }
          sec = sec/3600.0;
          if(deg_neg)
          {
            sec = -1 * sec;
          }
        }
      }
      DD_lat1 = deg + min + sec;
    }
    else
    {
      cerr << "error parsing deg, mins, sec" << endl;
      exit(1);
    }
  }
  deg = 0.0;
  min = 0.0;
  sec = 0.0;
  deg_neg = false;

  /*get longitude of first point*/
  getline(cin, long1);
  if(long1.empty())
  {
    cerr << "Cannot have blank longitudes and latitudes" << endl;
    exit(1);
  }
  else      //read deg, mins, secs
  {
    istringstream ss(long1);
    if(ss >> deg)
    {
      if(deg < 0 || signbit(deg))
      {
        deg_neg = true;
      }
      if(ss >> min)
      {
        if(min < 0.0)
        {
          cerr << "minutes can't be negative" << endl;
          exit(1);
        }
        min = min/60.0;
        if(deg_neg)
        {
          min = -1 * min;
        }
        if(ss >> sec)
        {
          if(sec < 0.0)
          {
            cerr << "seconds can't be negative" << endl;
            exit(1);
          }
          sec = sec/3600.0;
          if(deg_neg)
          {
            sec = -1 * sec;
          }
        }
      }
      DD_long1 = deg + min + sec;
    }
    else
    {
      cerr << "error parsing deg, mins, sec" << endl;
      exit(1);
    }
  }

  deg = 0.0;
  min = 0.0;
  sec = 0.0;
  deg_neg = false;

  /*get latitude of second point*/
  getline(cin, lat2);
  if(lat2.empty())
  {
    cerr << "Cannot have blank longitudes and latitudes" << endl;
    exit(1);
  }
  else      //read deg, mins, secs
  {
    istringstream ss(lat2);
    if(ss >> deg)
    {
      if(deg < 0 || signbit(deg))
      {
        deg_neg = true;
      }
      if(ss >> min)
      {
        if(min < 0.0)
        {
          cerr << "minutes can't be negative" << endl;
          exit(1);
        }
        min = min/60.0;
        if(deg_neg)
        {
          min = -1 * min;
        }
        if(ss >> sec)
        {
          if(sec < 0.0)
          {
            cerr << "seconds can't be negative" << endl;
            exit(1);
          }
          sec = sec/3600.0;
          if(deg_neg)
          {
            sec = -1 * sec;
          }
        }
      }
      DD_lat2 = deg + min + sec;
    }
    else
    {
      cerr << "error parsing deg, mins, sec" << endl;
      exit(1);
    }
  }
  
  deg = 0.0;
  min = 0.0;
  sec = 0.0;
  deg_neg = false;

  /*get longitude of second point*/
  getline(cin, long2);
  if(long2.empty())
  {
    cerr << "Cannot have blank longitudes and latitudes" << endl;
    exit(1);
  }
  else      //read deg, mins, secs
  {
    istringstream ss(long2);
    if(ss >> deg)
    {
      if(deg < 0 || signbit(deg))
      {
        deg_neg = true;
      }
      if(ss >> min)
      {
        if(min < 0.0)
        {
          cerr << "minutes can't be negative" << endl;
          exit(1);
        }
        min = min/60.0;
        if(deg_neg)
        {
          min = -1 * min;
        }
        if(ss >> sec)
        {
          if(sec < 0.0)
          {
            cerr << "seconds can't be negative" << endl;
            exit(1);
          }
          sec = sec/3600.0;
          if(deg_neg)
          {
            sec = -1 * sec;
          }
        }
      }
      DD_long2 = deg + min + sec;
    }
    else
    {
      cerr << "error parsing deg, mins, sec" << endl;
      exit(1);
    }
  }
  //compute colatitudes
  double colatitude1 = 0.0;
  double colatitude2 = 0.0;

  //colatitudes are ok with negative latitudes
  colatitude1 = (90.0 - DD_lat1) * (M_PI / 180.0);
  colatitude2 = (90.0 - DD_lat2) * (M_PI / 180.0);
  
  //compute diff in longitude C between the two points
  double C = 0.0;
  C = (DD_long1 - DD_long2) * (M_PI / 180.0);
  if(C < 0.0)
  {
    C = (-1.0) * C;
  }
  
  //compute size c of the angle between the two points with the center of the earth as the vertex
  double c = 0.0;
  c = acos(cos(colatitude1) * cos(colatitude2) + sin(colatitude1) * sin(colatitude2) * cos(C));
  
  //convert the angle to a distance by multiplying radius of the Earth
  double finaldistance = 0.0;
  finaldistance = c * 3959.0;
  
  cout << finaldistance << endl;
}


