#include <iostream>
   

using std::cout;
using std::endl;
            
class MyClass
{
    public:
        // Not OK because a gets initialised before b
        // See warning in gcc output
        MyClass(int x) : b(x), a(b-1), c(0)
        { cout << "a=" << a
               << "\nb=" << b
               << "\nc=" << c << "\n"; 
        };

    private:
        int a;
        int b;
        int c;
};

