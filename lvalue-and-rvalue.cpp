/*
 * lvalue-and-rvalue.cpp
 *
 * Tue  5 Sep 09:35:00 BST 2017
 *
*/

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;


// Experiment #1 
// - error: lvalue required as left operand of assignment
int foo() { return 1; }

// Experiment #2
// - error: invalid initialization of non-const reference of type ‘int&’ from 
//   an rvalue of type ‘int’
// int& foo() { return 2; }

// Experiment #3 
// - error: returning reference to temporary
// - error: assignment of read-only location ‘foo()’
//
// const int& foo() { return 3; }


// Experiment #4

// A global variable 
int globalvar = 20;

int& bar() { return globalvar; }


// int main()
int main (int argc, char* argv[]) 
{
    // int &myref = 8; // forbidden
    const int &myref = 8; // allowed
    cout << "myref=" << myref << "\n";

    // foo() = 16; // Experiments #1 to #3 all cause compilation failures

    cout << "BEFORE: globalvar=" << globalvar << "\n";
    bar() = 7; // Experiment #4 Allowed
    cout << "AFTER: globalvar=" << globalvar << "\n";

    // Assignment instead of comparison (often a mistake!)
    int x=0;
    //if (x = 666)
    //if (666 = x)
    if ((x = 666)) // yes I want to use = not == for some bizzare reason :-)
    {
        cout << "x=" << x << "\n";
    }

    return 0;
}

