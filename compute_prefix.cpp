//                 Ben Bos 
//         CS 6420 
//         Assignment #3
//    Dr. Rague 
//    Due: 02/19/23 
//    Version: 1.0 
// ----------------------------------------------------------------- 
// This program finds a prefix within a given text using
// the Knuth-Morris-Pratt Algorithm
// ----------------------------------------------------------------- 
 
// Compiler directives 
#include <iostream>
#include "alg_strings.h"
 
using namespace std; 

// ----------------------------------------------------------------- 
// This function computes the prefix function pi and returns it as
// a string
// 
// Version 1.0
// -----------------------------------------------------------------
string* compute_prefix(string P){
    int m = P.length();
    string* pi = new string[m];
    pi[0] = to_string(0);
    int k = 0;
    for (int q = 2; q < m; q++) {
        while (k > 0 && P[k + 1] != P[q]) {
            k = stoi(pi[k]);
        }
        if (P[k + 1] == P[q]) {
            k = k + 1;
        }
        pi[q] = k;
    }
    return pi;
}

int main() {
    string input = "01111000110101011010";
    string* output = new string[input.length()];
    output = compute_prefix(input);

    cout << input << "--->";
    for (int i = 0; i < input.length(); i++) {
        cout << "[" << output[i] << "]";
    }
    cout << endl;

    return 0;
}








// Variable declarations 
//    int Num_Cases;            // The number of cases of data values to process 
//    int Installations;        // The number of installations 
//    double Yards_Of_Cable,    // The yards of cable installed 
//     Feet_Of_Cable, // The number of yards of cable converted to 
// feet 
//     Revenue;       // The revenue generated for this case of data 