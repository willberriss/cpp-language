#include <iostream>
#include <memory>


int main() {
    std::cout << "Smart pointers\n";

    // shared_ptr
    std::shared_ptr<int> myPtr1(new int { 6 });

    // Better way
    std::shared_ptr<int> myPtr2 = std::make_shared<int>(10);

    // better still
    auto myPtr3 = std::make_shared<int>(16);

    std::cout << "myPtr3=" << myPtr3 << "\n";
    std::cout << "*myPtr3=" << *myPtr3 << "\n";

    // unique_ptr
    // create and initialize (pointer to) string:
    std::unique_ptr<std::string> up(new std::string("nico"));
    
    (*up)[0] = 'N';                // replace first character
    up->append("lai");             // append some characters

    // up = nullptr;
    if (up != nullptr) {
        std::cout << *up << std::endl; // print whole string
    }

    std::unique_ptr<std::string> up1(new std::string("One"));

    if (up1 != nullptr) {
        std::cout << "*up1=" << *up1 << std::endl; // print whole string
    }

    std::cout << "up1=" << up1.get() << "\n"; // can't print address of unique ptr

    std::unique_ptr<std::string> up2 (std::move(up1)); 
    
    std::cout << "up1=" << up1.get() << std::endl; // can't print address
    if (up1 != nullptr) {
        std::cout << "*up1=" << *up1 << std::endl; // print whole string
    }
    
    if (up2 != nullptr) {
        std::cout << "*up2=" << *up2 << std::endl; // print whole string
    }

    return 0;
}

