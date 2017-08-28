/*
 *
 * rule-of-five.cpp
 *
*/

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using std::cout;

// using std::basic_string;
using namespace std;


// See https://stackoverflow.com/questions/3106110/what-are-move-semantics


int main (int argc, char* argv[]) {

    return 0;
}

class string
{
    char* data;

    public:

    string(const char* p)
    {
        size_t size = strlen(p) + 1;
        data = new char[size];
        memcpy(data, p, size);
    }

    ~string()
    {
        delete[] data;
    }

    // copy constructor
    string(const string& that)
    {
        size_t size = strlen(that.data) + 1;
        data = new char[size];
        memcpy(data, that.data, size);
    }

    // move constructor
    string(string&& that)   // string&& is an rvalue reference to a string
    {
        data = that.data;
        that.data = nullptr;
    }

    // Assignment operator
    string& operator=(string that)
    {
        std::swap(data, that.data);
        return *this;
    }

};
