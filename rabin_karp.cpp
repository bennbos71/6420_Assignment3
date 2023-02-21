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
#include <fstream>
#include <cmath>
#include <time.h>

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
    cout << endl;
    cout << "Text: ";
    for (int i = 0; i < txt.length(); i++) {
        if (i % txt_size == 0) {
            cout << endl;
        }
        cout << txt[i];
    }
    cout << endl;
    cout << endl;
    cout << "Pattern: ";
    for (int i = 0; i < p.length(); i++) {
        if (i % p_size == 0) {
            cout << endl;
        }
        cout << p[i];
    }
    cout << endl << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////Run-Time Analysis///////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
// I determined my code to run at O((n-R)m).  My reasoning is because every element area in the
// matrix is checked, minus the area to account for the radix (R), and you do that m times (for
// every area of size m)

int main() {
    cout << "2x2 Pattern & 5x5 Text" << endl;
    string txt = "1679822458836900021345711";
    string p = "9013";
    print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    rk_alg(txt,p);

    cout << "2x2 Pattern & 5x5 Text" << endl;
    txt = "1234523321091182311115094";
    p = "2315";
    print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    rk_alg(txt,p);

    cout << "2x2 Pattern & 5x5 Text" << endl;
    txt = "2391351234231530542310615";
    p = "4261";
    print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    rk_alg(txt,p);

    cout << "2x2 Pattern & 5x5 Text" << endl;
    txt = "1928377652009879876713246";
    p = "6598";
    print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    rk_alg(txt,p);

    // txt = "";
    // p = "";
    // string lines;
    // string text;
    // ifstream MyReadFile("octal.txt");
    // srand(time(0));
    // int i_index = rand() % 1000;
    // int j_index = rand() % 900;
    // int pat_index = rand() % 1000 - (100 * (16 - 1) - 16);

    // int i = 0;
    // while (getline(MyReadFile, lines)) {
    //     if (i_index == i) {
    //         text = lines;
    //         break;
    //     }
    //     i++;
    // }
    // for (int i = j_index; i < j_index + 1000; i++) {
    //     txt += text[i];
    // }
    // for (int i = 0; i < 16; i++) {
    //     for (int j = 0; j < 16; j++) {
    //         p += txt[pat_index +  (100 * i) + j];
    //         // cout << txt[pat_index +  (100 * i) + j] << endl;
    //     }
    // }
    // print_txt_pattern(txt, p, sqrt(txt.length()), sqrt(p.length()));
    // rk_alg(txt,p);

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