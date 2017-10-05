/*
 *
 * move-constructors-stl-performance.cpp
 *
 * The STL list class has a move constructor so we can return a list
 * by value from a method and it will move by value rather than copy by value.
 * So will be a lot faster for list with thousands of elements in them.
 *
 * So, compile this with C++98 and then run it and time it. 
 * Then compile with C++11 and run it and time it and it will run faster.
 *
 * Run using: time ./move-constructors-stl-performance
 *     real   0m0.863s
 *     user   0m0.820s
 *     sys    0m0.040s
 *
*/

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

// c++11 only
//#include <chrono>  // for high_resolution_clock

using std::cout;
using std::endl;
using std::vector;
using std::list;

class Timer
{
    public:
        Timer() { clock_gettime(CLOCK_REALTIME, &beg_); }

        double elapsed() {
            clock_gettime(CLOCK_REALTIME, &end_);
            return end_.tv_sec - beg_.tv_sec +
                (end_.tv_nsec - beg_.tv_nsec) / 1000000000.;
        }

        void reset() { clock_gettime(CLOCK_REALTIME, &beg_); }

    private:
        timespec beg_, end_;
};

class Fruit {
   public:
   private:
      int apple;
      int banana;
};

list<Fruit> f(vector<Fruit>& vec)
{
    // cout << "f() called" << "\n";
    list<Fruit> fruit(10000000);
    //copy(vec.begin(), vec.end(), back_inserter(fruit));
    return fruit; // return by value (copy in C++98, move in C++11)
}

// Main function for the program
int main( ) 
{
    //cout << "Create a vector of fruit of size 10,000,000" << "\n";
    vector<Fruit> fruitVec(10000000);

    //cout << "Call list<Fruit> f(fruitVec)" << "\n";
    
    // C++11 only :(
    // Record start time
    // auto start = std::chrono::high_resolution_clock::now();

    Timer tmr;

    //double t0 = tmr.elapsed();
    //std::cout << "t0=" << t0 << std::endl;
    
    tmr.reset();
    
    //double t1 = tmr.elapsed();
    //std::cout << "t1=" << t1 << std::endl;

    list<Fruit> fruitList = f(fruitVec);

    double t2 = tmr.elapsed();
    std::cout << "Execution time=" << t2 << "seconds" << std::endl;

    // C++11 only :(
    // Record end time
    // auto finish = std::chrono::high_resolution_clock::now();
 
    //cout << "Finished call" << "\n";

    // C++11 only :(
    // std::chrono::duration<double> elapsed = finish - start;

    //cout << "Execution time = " << elapsed.count() << "\n";

    return 0;
}

