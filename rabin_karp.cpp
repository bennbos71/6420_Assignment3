//                 Ben Bos 
//         CS 6420 
//         Assignment #3
//    Dr. Rague 
//    Due: 02/19/23 
//    Version: 1.0 
// ----------------------------------------------------------------- 
// This program finds an NxN pattern in an MxM text using
// the Rabin-Karp Algorithm
// ----------------------------------------------------------------- 
 
// Compiler directives 
#include <iostream>
#include <cmath>

#include "alg_strings.h"
 
using namespace std; 
// 2391351234231530542310615
int main() {
    string txt = "23913"
                 "51234"
                 "23153"
                 "05423"
                 "10615";
    string p = "23"
               "15";
    int row, col, tmp;
    RabinKarp rk(p);
    int location = rk.search(txt);
    if (location > -1) {
        tmp = sqrt(txt.length());
        row = location / tmp;
        col = location % tmp;
        cout << "{" << row << ", " << col << "}" << endl;
    } else if (location == -1) {
        cout << "Pattern Not Found" << endl;
    } else {
        cout << "Invalid Input" << endl;
    }
    // cout << location << endl;
    return 0;
}



// ----------------------------------------------------------------- 
// This class represents a circle that can be displayed on 
// a console window. 
// 
// Version 1.1 
// ---------------------------------------------------------- 




// Variable declarations 
//    int Num_Cases;            // The number of cases of data values to process 
//    int Installations;        // The number of installations 
//    double Yards_Of_Cable,    // The yards of cable installed 
//     Feet_Of_Cable, // The number of yards of cable converted to 
// feet 
//     Revenue;       // The revenue generated for this case of data 