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
    //  Example 01 Input
    string input1 = "ababaca";
    string* output1 = new string[input1.length()];
    output1 = compute_prefix(input1);

    cout << input1 << "--->";
    for (int i = 0; i < output1->size(); i++) {
        cout << "[" << output1[i] << "]";
    }
    cout << endl;

    //  Example 02 Input
    string input2 = "01111000110101011010";
    string* output2 = new string[input2.length()];
    output2 = compute_prefix(input2);

    cout << input2 << "--->";
    for (int i = 0; i < output2->size(); i++) {
        cout << "[" << output2[i] << "]";
    }
    cout << endl;

    //  Example 03 Input
    string input3 = "aaaaaaaabbbbbbbb";
    string* output3 = new string[input3.length()];
    output3 = compute_prefix(input3);

    cout << input3 << "--->";
    for (int i = 0; i < output3->size(); i++) {
        cout << "[" << output3[i] << "]";
    }
    cout << endl;

    //  Example 04 Input
    string input4 = "abab";
    string* output4 = new string[input4.length()];
    output4 = compute_prefix(input4);

    cout << input4 << "--->";
    for (int i = 0; i < output4->size(); i++) {
        cout << "[" << output4[i] << "]";
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