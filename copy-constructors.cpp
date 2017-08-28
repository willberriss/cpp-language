/*
 *
 * hello.cpp
 *
*/

#include <iostream>

using namespace std;

class Line {
   public:
      int getLength( void );
      Line(int len);             // simple constructor
      Line(const Line &obj);  // copy constructor
      Line& operator=(const Line &rhs);  // assignment operator
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
   cout << "Copy constructor allocating ptr " << ptr 
        << ", copying obj.ptr " << obj.ptr << endl;
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

Line::~Line(void) {
   cout << "Destructor called - freeing memory " << ptr << endl;
   delete ptr;
}

int Line::getLength( void ) {
    cout << ptr << " getLength() called" <<endl;
    return *ptr;
}

void display(Line obj) {
   cout << "Length of line : " << obj.getLength() << endl;
}

// Main function for the program
int main( ) {
   cout << "Constructing: Line line(10);" << "\n";
   Line line(10);
   cout << "Finished construction" << "\n\n";

   cout << "Constructing: Line line2(line);" << "\n";
   Line line2(line);
   cout << "Finished construction" << "\n\n";

   // Line line3 = line; // calls copy constructor, same as "Line line3(line);"
   cout << "Constructing: Line line3 = line; (same as Line line3(line)" << "\n";
   Line line3 = line;
   cout << "Finished construction" << "\n\n";
   
   cout << "Assigning to existing line3:  line3 = line;" << "\n";
   line3 = line;
   cout << "Finished assignment" << "\n\n";

   cout << "Calling display(line);" << "\n";
   display(line);
   cout << "Returned from calling display()" << "\n\n";

   return 0;
}

