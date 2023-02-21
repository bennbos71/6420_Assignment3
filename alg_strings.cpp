/******************************************************************************
 *  File: alg_strings.cpp
 * 
 *  An implementation of string-matching classes.
 *
 ******************************************************************************/

#include <iostream>
#include <stack>
#include <list>
#include <string>
#include <random>
#include <chrono>
#include <cmath>
#include <vector>
#include <queue>
#include "alg_strings.h"

/******************************************************************************
 *  Class: RabinKarp
 *  A class implementing the Rabin-Karp algorithm
 ******************************************************************************/
long RabinKarp::long_random_prime(){
  int min = 0, max = 49;
  long primes[] = {
    2094665479L, 1783990163L, 2094521287L, 2134397081L, 2126326253L, 
    1957216747L, 1436547389L, 1428780767L, 2075625529L, 1593123733L, 
    2132587157L, 1965562429L, 1164701777L, 1568991883L, 2130061793L, 
    1075370311L, 1711832929L, 2054631589L, 1587361861L, 1435348609L, 
    1332084959L, 1465215911L, 2088173753L, 1933073123L, 1319415599L, 
    1211741129L, 1487473783L, 1656920599L, 1817614213L, 1838911937L, 
    1697951429L, 1673793083L, 1971101663L, 1570547117L, 1869368041L, 
    1855484017L, 2057695543L, 1806695647L, 2082498797L, 2090345119L, 
    1349212999L, 1456810283L, 1271362889L, 1959057733L, 1073964823L, 
    1315871351L, 1308843649L, 1543027127L, 1230659387L, 1828780297L };
  
  static std::default_random_engine en;
  en.seed(std::chrono::system_clock::now().time_since_epoch().count());
  static std::uniform_int_distribution<int> dist{min, max}; 
    
  return primes[dist(en)];
}

//  Changed original m to l
long RabinKarp::hash(const std::string &key, int l) const {
  long h = 0;
  for (int j = 0; j < l; j++) {
    h = (R * h + key[j]) % q;
  }
  return h;
}

bool RabinKarp::check(const std::string &txt) const {
  for (int i = 0; i < m; i++) {
    if (pat[i] != txt[i]) {
      return false;
    }
  }

  return true;
}

RabinKarp::RabinKarp(const std::string &pat):pat(pat), R(256) {
  m = pat.size();
  m_sqrt = sqrt(m); //  variable to represent the conversion of the string of size M to an MxM matrix
  q = long_random_prime();

  RM = 1;
  for (int i = 1; i <= m-1; i++){
    RM = (R * RM) % q;
  }
  pat_hash = hash(pat, m);
}

// ----------------------------------------------------------------- 
// This method converts a string array to a regular string to help
// with processing in other parts of the program
// 
// Version 1.1 
// ---------------------------------------------------------- 
std::string RabinKarp::strarr_to_str(std::string *hash_str) const {
  std::string ret_str;
  for (int i = 0; i < m; i++) {
    ret_str += hash_str[i];
  }
  return ret_str;
}

int RabinKarp::search(const std::string &txt) const {
  //  check if the size of the text is less than the size of the pattern
  int n = sqrt(txt.length());
  if (txt.length() < m) return -2;

  //  variables to be used
  std::string* p_search = new std::string[m];
  long hash_long;
  int j, a, b;
  std::string hash_str;
  std::string checkStr = "";

  //  Iterate through the text variable while interpretting
  //  it as a 2D array.  Check for pattern matches
  for (int i = 0; i < n - m_sqrt + 1; i++) {
    j = 0;
    a = 0;
    //  Retrieve all but the right most column for our pattern check
    while (a < m_sqrt) {
      p_search[(a*m_sqrt)] = txt[((i+a)*n)];
      a++;
    }
    //  Iterate through each row in the text variable
    for (; j < n - m_sqrt + 1; j++) {
      a = 0;
      //  Get the pattern to check starting from a specific index
      while (a < m_sqrt) {
        b = 1;
        while (b < m_sqrt) {
          p_search[(a*m_sqrt)+b] = txt[((i+a)*n)+(j+b)];
          b++;
        }
        a++;
      }
      //  Hasing the pattern retrieved and checking if it is correct
      hash_str = strarr_to_str(p_search);
      hash_long = hash(hash_str, m);
      if (pat_hash == hash_long) {
        if (check(hash_str)) {
          return ((i*n)+j);
        }
      }
      a = 0;
      //  Shifting all the columns 1 to the left
      while (a < m) {
        p_search[a] = p_search[a+1];
        p_search[a+1] = "";
        a++;
        if ((a+1) % m_sqrt == 0) {
          a++;
        }
      }
    }
  }

  return -1; // no match
}