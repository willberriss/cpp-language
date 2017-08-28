#include <iostream>
#include <thread>
using namespace std;

void func(int x) {
    cout << "Inside thread: x=" << x << endl;
}

int main() {
    cout << "Before thread th" << "\n";
    
    thread th(&func, 100);
    
    cout << "After thread th and before join" << "\n";
    cout << "Still after thread th and before join" << "\n";
    
    this_thread::sleep_for(chrono::milliseconds(1000));
    
    cout << "Still still after thread th and before join" << "\n";
    
    th.join();
    
    cout << "Outside thread" << endl;
    
    return 0;
}

