#include <iostream>
#include <memory>
#include <array>
#include <vector>
#include <set>

int main() {
    std::cout << "Initialisation\n";
    
    //std::array<int,3> test = {2,4,6};

    std::array<int,36> aCounts{};
    std::array<int,36> bCounts{};
    
/*
    for (auto c : aCounts) {
        std::cout << "aCounts c=" << c << "\n";
    }

    std::cout << "\n";
    
    for (auto c : bCounts) {
        std::cout << "bCounts c=" << c << "\n";
    }
*/
    std::string a{"abcdefghijklmnop"};
    std::string b{"mnopqrstuvwxyz"};

    for (auto c : a) {
        int idx = c - 'a';
        aCounts[idx] += 1;
    }

    for (auto c : b) {
        int idx = c - 'a';
        bCounts[idx] += 1;
    }    
    
    for (auto c : a) {
        std::cout << c;
    }
    std::cout << "\n";
    
    for (auto c : b) {
        std::cout << c;
    }
    std::cout << "\n";

    //int sum{69}; 
    //int sum = 69;

    // valgrind core dumps on cout below for sum - odd
    //std::cout << "sum=" << sum << "\n";

    //int *ptr = new int;
    //std::cout << "ptr=" << ptr << "\n";
    
    int *ptr2 = new int();
    *ptr2=66;
    std::cout << "*ptr2=" << *ptr2 << "\n";
    
    std::vector<int> myints {2,4,6,8};
    for (int i : myints) {
        std::cout << "i=" << i << "\n";
    }

    std::set<int> myset {1,2,3,4,5};
    for (int i : myset) {
        std::cout << "i=" << i << "\n";
    }

    return 0;
}

