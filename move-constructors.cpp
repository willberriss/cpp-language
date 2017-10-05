/*
 *
 * move-constructors.cpp
 *
*/

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

// GLOBAL
int numCopyConstructorCalls = 0;

class Line {
   public:
      int getLength( void ) const;
      Line(int len=0);        // simple constructor
      Line(const Line &obj);  // copy constructor
      Line& operator=(const Line &rhs);  // copy assignment operator (op=)
 
      Line(Line &&obj); // C++11 move constructor
      Line& operator=(Line &&rhs); //C++11 move assignment operator (op=)

      ~Line();                     // destructor

   private:
      int *ptr;
};

// Member functions definitions including constructor
Line::Line(int len) {
   // allocate memory for the pointer;
   ptr = new int;
   *ptr = len;
   cout << "Normal constructor allocating ptr " << ptr << endl;
}

Line::Line(const Line &obj) {
   ptr = new int;
   *ptr = *obj.ptr; // copy the value
   
   ++numCopyConstructorCalls;

   cout << "Copy constructor allocating ptr " << ptr 
        << ", copying obj.ptr " << obj.ptr << endl;
}

// A move constructor alters obj (makes it nullptr), so it cannot be const
Line::Line(Line &&obj) {
   ptr = obj.ptr; // steal it
   obj.ptr = nullptr; // make safe
   cout << "Move constructor for ptr " << ptr << "\n";
}

Line& Line::operator=(const Line &rhs) {
   if (this != &rhs) // protect against invalid self-assignment
   {
       *ptr = *rhs.ptr; // copy the value, not the address
   }
   cout << "Assignment operator allocating ptr " << ptr
        << ", copying rhs.ptr " << rhs.ptr << endl;
   return *this;
}

// move constructor alters arg, so cannot be const
Line& Line::operator=(Line &&rhs) {
   if (this != &rhs) // protect against invalid self-assignment
   {
       ptr = rhs.ptr; // steal the address
       rhs.ptr = nullptr; // make safe
   }
   cout << "Move Assignment operator for ptr " << ptr << "\n";
   return *this;
}

Line::~Line(void) {
   cout << "Destructor called - freeing memory " << ptr << endl;
   delete ptr;
}

int Line::getLength( void ) const {
    cout << ptr << " getLength() called" <<endl;
    return *ptr;
}

// Passing by ref avoids the call to the copy constructor here
void display(Line &obj) {
   cout << "Length of line : " << obj.getLength() << endl;
}

vector<Line> doubleValues(const vector<Line>& v)
{
    cout << "doubleValues() called" << "\n";
    vector<Line> new_values;
    new_values.reserve(v.size());
    for (auto itr = v.begin(), end_itr = v.end(); itr != end_itr; ++itr )
    {
        new_values.push_back( Line(2 * (itr->getLength() )) );
    }
    return new_values;
}

// Main function for the program
int main( ) {
   cout << "Constructing: Line line(10);" << "\n";
   Line line(10);
   cout << "Finished construction" << "\n\n";

   cout << "Constructing: Line line2(line);" << "\n";
   Line line2(line);
   cout << "Finished construction" << "\n\n";

//   cout << "Constructing: Line line4 = std::move(line);" << "\n";
//   Line line4 = std::move(line);
//   cout << "Finished construction" << "\n\n";
   
   cout << "Calling display(line2);" << "\n";
   display(line2);
   cout << "Returned from calling display()" << "\n\n";

   cout << "Using a vector of Lines" << "\n";
   vector<Line> v;
   for ( int i = 0; i < 3; i++ )
   {
       v.push_back( Line(i) );
   }

   cout << "Calling doubleValues()" << "\n";
   v = doubleValues( v );
   cout << "Returned from doubleValues()" << "\n";
   cout << "Done using a vector of Lines" << "\n\n";

   cout << "numCopyConstructorCalls=" << numCopyConstructorCalls << "\n\n";

   return 0;
}

