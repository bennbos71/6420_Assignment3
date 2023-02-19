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

// ----------------------------------------------------------------- 
// This method holds the instructions for calling the search fuction
// and then processing the returned result and interpretting it as
// a readable result.
// 
// Version 1.1 
// ---------------------------------------------------------- 

void rk_alg(string txt, string p) {
    int row, col, tmp;
    RabinKarp rk(p);
    int location = rk.search(txt);
    if (location > -1) {
        tmp = sqrt(txt.length());
        row = location / tmp;
        col = location % tmp;
        cout << "Pattern found at row, column index:" << endl;
        cout << "{" << row << ", " << col << "}" << endl;
    } else if (location == -1) {
        cout << "NOT FOUND" << endl;
    } else {
        cout << "Invalid Input" << endl;
    }
}

void print_txt_pattern(string txt, string p, int txt_size, int p_size) {
    cout << "Text: ";
    for (int i = 0; i < txt.length(); i++) {
        if (i % txt_size == 0) {
            cout << endl;
        }
        cout << txt[i];
    }
    cout << endl;
    cout << "Pattern: ";
    for (int i = 0; i < p.length(); i++) {
        if (i % p_size == 0) {
            cout << endl;
        }
        cout << p[i];
    }
    cout << endl;
}

int main() {
    string txt = "2391351234231530542310615";
    string p = "2315";
    // print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    // rk_alg(txt,p);

    // txt = "123456233212091182231113150942998763";
    // p = "2315";
    // print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    // rk_alg(txt,p);

    // txt = "2391351234231530542310615";
    // p = "4261";
    // print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    // rk_alg(txt,p);

    txt = "1928374635"
          "7765241328"
          "0098718263"
          "9876789653"
          "1324657980"
          "0897646102"
          "1029384756"
          "1111111111"
          "1987263599"
          "1232175844";
    p = "652987767";
    // print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    rk_alg(txt,p);
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