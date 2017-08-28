/*
 *
 * base-derived-virtual-destructor.cpp
 *
 * c++98
 *
 * Show difference between a virtual and non-virtual destructor
 *
*/

#include <iostream>
#include <vector>
#include <cstring>

using std::cout;
using std::endl;
using std::vector;

// GLOBAL
int numCopyConstructorCalls = 0;

class Line {
   public:
       Line(int len=0);        // simple constructor
       Line& operator=(const Line &rhs);  // assignment operator
       ~Line();                     // destructor

   //private:
       int *ptr;
       //char *myStr;
       // chars seems to behave oddly so using an int instead
       // which makes it say:
       // *** Error in `./base-derived-virtual': double free or corruption
       // (fasttop): 0x01ddc018 ***
       // Aborted
       //
       int *myStr;
};

// Member functions definitions including constructor
Line::Line(int len) {
   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;

   myStr = new int[len+1];
   //strncpy(myStr, "444444", len);

   cout << "Line constructor allocating ptr " << ptr 
        << " and myStr " << myStr << endl;

}

Line::~Line(void) {
   cout << "Line destructor called - freeing memory ptr " << ptr
        << " and myStr " << myStr << endl;
 
   delete ptr;
   delete [] myStr;
}

// Copy Constructor
/*
Line::Line(const Line &obj) {
   // what a default copy ctr would do!
   ptr = obj.ptr;
   
   // proper full/deep copy
   //ptr = new int;
   // *ptr = *obj.ptr; // copy the value
   
   ++numCopyConstructorCalls;

   // what a default copy ctr would do!
   myStr = obj.myStr; 
   
   // proper full/deep copy
   //myStr = new int[*(obj.ptr)+1];
   ////strcpy(myStr, obj.myStr); use memcpy perhaps?
   
   cout << "Copy constructor allocating ptr=" << ptr 
        << " myStr=" << myStr
        << ", copying obj.ptr " << obj.ptr
        << " and obj.myStr " << (obj.myStr) << endl;
}
*/

// Copy Assignment Operator (aka operator=)
Line& Line::operator=(const Line &rhs) {
   if (this != &rhs) // protect against invalid self-assignment
   {
       *ptr = *rhs.ptr; // copy the value, not the address
   }
   cout << "Assignment operator allocating only ptr " << ptr
        << ", copying rhs.ptr " << rhs.ptr << endl;
   return *this;
}

void PrintString(Line obj) {
   cout << "PrintString : " << obj.myStr << endl;
}

class DerivedLine : public Line
{
    public:
        DerivedLine(int n);
        ~DerivedLine();
};

// Make this derived ctr all a ctr other than the default base class dtr
DerivedLine::DerivedLine(int n) : Line(n)
{
    cout << "DerivedLine constructor called with ptr = " << ptr 
         << " and myStr = " << myStr << endl;
}

DerivedLine::~DerivedLine()
{
    cout << "DerivedLine destructor called - freeing memory ptr " << ptr 
        << " and myStr " << myStr << endl;
}

// N.B. 
// No copy constructor, so when we call PrintLine it will mean
// the default copy ctr is used which means the pointer to the
// char *string is simply copied. This should cause a seg fault
// on return exit as dtr will be called a 2nd time on the same
// memory address


// Main function for the program
int main( ) {
   cout << "Constructing: Line *baseLine = new DerivedLine(5);" << "\n";
   Line *baseLine = new DerivedLine(5);
   cout << "Finished construction" << "\n\n";

   cout << "baseLine=" << baseLine << "\n";

   cout << "Calling PrintString()" << "\n";
   PrintString(*baseLine);
   cout << "Returned from PrintString()" << "\n";

   cout << "numCopyConstructorCalls=" << numCopyConstructorCalls << "\n\n";

   delete baseLine;

   return 0;
}

