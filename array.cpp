#include <iostream>
#include <array>
#include <algorithm>

// Stashed in git

int main() {
    std::cout << "Array\n";

    const int mysize = 10;
    std::array<int, mysize> myarray;

    // External loop iterator - just wanna populate array
    for (int i=0; i < mysize; ++i)
    {
        myarray[i] = (i*2);
    }
    
    for( int e : myarray ) std::cout << e << '\n';

    auto loop_body = [](int e ) { std::cout << e << '\n'; };

    // Internal loop iterator (I think)
    std::for_each( myarray.begin(), myarray.end(), loop_body );
   
    // A new way - works on C arrays too i.e. int mycarray[66];
    std::for_each( std::begin(myarray), std::end(myarray), loop_body );

    return 0;
}

