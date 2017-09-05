/*
 * rvalue-ref.cpp
 *
 * Sun 19 Mar 11:50:44 GMT 2017
 *
*/

#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

// global variable x
int x;

// fn prototypes
int& getRef ();
std::string getName ();
void printReference (const string& str);
//void printReference (string&& str);

int main (int argc, char* argv[]) 
{
  getRef() = 4;
  cout << "x=" << x << endl;
  //cout << "&x=" << &x << endl;
  //cout << "&getRef()" << &getRef() << endl;

  std::string &&name = getName();
  cout << "name=" << name << endl;

  string me( "Will" );
  
  // Call the first printReference function, taking an lvalue reference
  printReference( me ); 
   
  // Calls the second printReference function if it exists, otherwise
  // calls the first function. 
  printReference( getName() ); 

  return 0;
}

int& getRef () 
{
    return x;
}

// getName() is an rvalue and it is a temporary object
std::string getName ()
{
    return "Alex";
}

void printReference (const string& str)
{
    cout << "const str = " << str << endl;
}

// The mere presence of the following overload of printReference
// makes the compiler choose this over the above method
// for the call to printReference( getName() );
//
// This second function takes a mutable rvalue reference.
// It's mutable because it's not const
// It's an rvalue reference because that's what the new && operator means
// It let's you bind a mutable reference to an rvalue, but not to an lvalue
// e.g. This parameter can bind to our rvalue getName() above 
void printReference (string&& str)
{
    cout << "secret rvalue ref temp variable str = " << str << endl;
}
