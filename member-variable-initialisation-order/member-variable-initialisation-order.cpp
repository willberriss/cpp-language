/*
 *
 * member-variable-initialisation-order.cpp
 *
 * c++98
 *
 * Expected output by make:
 *
 *
 * will@zen:~/computer/git/cpp98-fun$ make build-member-variable-initialisation-order
 * g++ -std=c++98 -pedantic -Wall -Werror    member-variable-initialisation-order.cpp   -o member-variable-initialisation-order
 * member-variable-initialisation-order.cpp: In constructor ‘MyClass::MyClass(int)’:
 * member-variable-initialisation-order.cpp:32:13: error: ‘MyClass::b’ will be initialized after [-Werror=reorder]
 *         int b;
 *             ^
 * member-variable-initialisation-order.cpp:31:13: error:   ‘int MyClass::a’ [-Werror=reorder]
 *        int a;
 *            ^
 * member-variable-initialisation-order.cpp:20:9: error:   when initialized here [-Werror=reorder]
 *        MyClass(int x) : b(x), a(b-1), c(0) 
 *        ^
 * cc1plus: all warnings being treated as errors
 * <builtin>: recipe for target 'member-variable-initialisation-order' failed
 * make: *** [member-variable-initialisation-order] Error 1
 *
 *
 * As you can see, the message is spread over multiple errors. What it is
 * saying is, 
 *   "‘MyClass::b’ will be initialized after ‘int MyClass::a’ when initialized
 *   here: MyClass(int x) : b(x), a(b-1), c(0)"
 *
*/

#include <iostream>
#include <cstring>

using std::cout;
using std::endl;

class MyClass
{
    public:
        // Not OK because a gets initialised before b
        // see warning output
        MyClass(int x) : b(x), a(b-1), c(0) 
        // OK, a, b and c are used in the correct order
        //MyClass(int x) : a(x), b(a-1), c(0) 
        
        // c++11 test
        //MyClass(int x) : a(b), b(x)
        { cout << "a=" << a
             << "\nb=" << b
             << "\nc=" << c << "\n"; };

    private:
        int a;
        int b;
        int c;
        // c++11 test
        //int a=10;
        //int b=20;
        //int c=30;
};

int main()
{
    MyClass m(3);
    return 0;
}

