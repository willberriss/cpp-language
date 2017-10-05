#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
using namespace std;

#include <thread>
#include <iostream>

// static method (global)
void addMoney(int x) 
{
    int y = x;
    ++y;
}

class bar {
    public:
        void foo() 
        {
            std::cout << "Hello from member function\n";
        }
};

int main()
{

    // This works
    std::thread t1(addMoney, 100);

    // As does this
    std::thread t2(&addMoney, 200);

    // But for a class, we MUST use the & in front of the method
    std::thread t(&bar::foo, bar());
    // without the & this fails because it is a non-static method
    //std::thread t(bar::foo, bar());
    // We must also supply bar() as this is a class and we need a this
    // pointer or something like that.

    // We get this error message:
    //thread-function-address.cpp:22:24: error: invalid use of non-static member
    //function ‘void bar::foo()’
    //     std::thread t(bar::foo, bar());
    
    t.join();
    
    t2.join();
    t1.join();
    
    // Aside:
    // The follwing fails due to too few args. 
    // Confusing compiler error message though!
    //std::thread t0(addMoney); // Line 54
    
    // Compiler error:
    // /usr/include/c++/4.9/functional: In instantiation of ‘struct
    //   std::_Bind_simple<void (*())(int)>’:
    // /usr/include/c++/4.9/thread:140:47:   required from
    // ‘std::thread::thread(_Callable&&, _Args&& ...) [with _Callable = void
    // (&)(int); _Args = {}]’
    //   thread-function-address.cpp:54:28:   required from here
    //
    // I think it is trying to tell me that on line 54 it can't bind a function
    // that takes an int argument  (namely addMoney) to my thread because
    // I have not supplied the argument!
    
    // A final test - that fails. Very confusing compiler error message.
    // std::thread t3(&bar::foo);
}

