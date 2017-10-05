#include <iostream>
#include <thread>
using namespace std;

void func(int x) {
    cout << "Inside thread: x=" << x << endl;
}

int main() {
    cout << "Before thread th" << "\n";

    const int x=100;    
    thread th(&func, x);
    
    cout << "After thread th and before join" << "\n";
    cout << "Still after thread th and before join" << "\n";
    
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << "Still still after thread th and before join" << "\n";
    
    cout << "Before join, i.e. thread has not terminated yet" << endl;
    
    th.join();
    
    cout << "After join, i.e. thread has terminated" << endl;
    
    return 0;
}

