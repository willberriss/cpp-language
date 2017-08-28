#include <iostream>
#include <cmath>
#include <vector>
#include <thread>
using namespace std;

// GLOBAL VARIABLE
int accum = 0;

void addMoney(int x) {
    
    // 
    // It's a race to increment the shared global
    // variable accum and we deliberately increment
    // it 1 by 1 so as to access it a lot increasing 
    // the chance of each thread treading on anothers toes
    //
    for (int m=0; m<x; ++m) {
        accum++;
    }
}

int spawnThreads() {
    vector<thread> ths;

    // 
    // Add 1000 quid 20 times using 20 threads
    // it's a race to increment the shared global
    // variable accum
    //
    for (int i = 1; i <= 20; ++i) {
        ths.push_back(thread(&addMoney, 1000));
    }

    for (auto& th : ths) {
        th.join();
    }

    // Ideally returns 20000
    return accum;
}

int main() {

    int val=0;

    // Do the same experiment 150 times, a few will fail
    for (int c=0; c<150; ++c) {
        accum = 0;
        if ((val = spawnThreads()) != 20000) {
            cout << "Error at count=" << c << " value=" << val 
                 << " instead of 20000" << "\n";
        } 
        else {
            cout << "Correct at count=" << c << " value=" << val 
                 << " which is 20000" << "\n";
        }
    }

    return 0;
}


