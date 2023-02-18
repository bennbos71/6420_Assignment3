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
  m_sqrt = sqrt(m);
  q = long_random_prime();

  RM = 1;
  for (int i = 1; i <= m-1; i++){
    RM = (R * RM) % q;
  }
  pat_hash = hash(pat, m);
}

int RabinKarp::search(const std::string &txt) const {
  int n = sqrt(txt.length());
  // change to return -2 instead of n to represent invalid input
  if (n < m_sqrt) return n;
  long hashA, hashB;
  int j;
  std::string strA1, strA2, strB1, strB2;
  std::string checkStr = "";
  // check for hash match; if hash match, check for exact match
  for (int i = 0; i < n - m_sqrt + 1; i++) {
    j = 0;
    strA1 = txt[(i*n)+j];
    strA2 = txt[((i+1)*n)+j];
    hashA = hash((strA1 + strA2), m_sqrt);
    for (; j < n - m_sqrt + 1; j++) {
      strB1 = txt[(i*n)+(j+1)];
      strB2 = txt[((i+1)*n)+(j+1)];
      hashB = hash((strB1 + strB2), m_sqrt);
      std::cout << "A1 [" << strA1 << "] B1 [" << strB1 << "] A2 [" << strA2 << "] B2 [" << strB2  << "]" << std::endl;
      if (pat_hash == (hashA * hashB)) {
        checkStr = strA1 + strB1 + strA2 + strB2;
        if (check(checkStr)) {
          return ((i*n)+j);
        }
      }
      hashA = hashB;
      strA1 = strB1;
      strA2 = strB2;
    }
  }

  return -1; // no match
}