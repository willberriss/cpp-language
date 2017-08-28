#include <iostream>

struct C {
    C() {}
    C(const C&) { std::cout << "C's copy constructor. A copy was made.\n"; }
    void useme() { std::cout << "I've been used\n"; }
};

C f() {
    return C();
}

int main() {
    std::cout << "RVO - Return value optimisation\n";
    C obj = f();
    obj.useme();
    return 0;
}

