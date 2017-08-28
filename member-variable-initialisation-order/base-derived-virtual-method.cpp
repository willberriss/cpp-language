/*
 *
 * base-derived-virtual-method.cpp
 *
 * c++98
 *
 * Show difference between a virtual and non-virtual method
 * when calling from a base class pointer
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


// TODO
//  nisum-technologies-interview-questions
//
//  Class B
//  {
//  Public:
//  Void disp();
//  Void show();
//  };
//  Class D : public B
//  {
//  Public:
//  Void disp();
//  Void show(D &);
//  };
//
//  int main()
//  {
//  B *b = new D();
//  b->disp();
//  b->show()//base clas show will be called
//  */b->show(D)how call derive class show? */
//  }
//
//  Q. How to call Derived class show function with base class pointer?
//  A. I say fix the D class so that show is virtual!

class B1
{
    public:
        void display() { cout << "B1::display() called" << "\n"; };
        void show(){ cout << "B1::show() called" << "\n"; };
};

class B2
{
    public:
        void display() { cout << "B2::display() called" << "\n"; };

        // Make base class method VIRTUAL!
        virtual void show(){ cout << "B2::show() called" << "\n"; };
};

class D1 : public B1
{
    public:
        void display() { cout << "D1::display() called" << "\n"; };
        void show(){ cout << "D1::show() called" << "\n"; };
};

class D2 : public B2
{
    public:
        void display(){ cout << "D2::display() called" << "\n"; };
        virtual void show(){ cout << "D2::show() called" << "\n"; };
        
        // In c++11, append the keyword override, to ensure it is overridding
        // a method in the base class. (You don't have to specify
        // virtual here in the derived class, but it's good to do so.)
        // The following two are equivalent
        //virtual void show() override { cout << "B2::show() called" << "\n"; };
        //void show() override { cout << "B2::show() called" << "\n"; };
};

int main()
{
    B1 *b1 = new D1();
    cout << "b1 calls" << "\n";
    b1->display();
    b1->show(); //base class show will be called

    B2 *b2 = new D2();
    cout << "\nb2 calls" << "\n";
    b2->display();
    b2->show();

   return 0;
}

