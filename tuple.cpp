#include <iostream>
#include <tuple>
#include <algorithm>


int main() {
    std::cout << "Tuples\n";

    typedef std::tuple<int,std::string,int> i3tuple;

    std::vector <i3tuple> mytuples;
    for (int i=0; i<10; i++) {
        mytuples.push_back(i3tuple(i,"Fred",i*2) );
    }

    for(i3tuple t: mytuples)
    {
        std::cout << std::get<0>(t) << ' ';
        std::cout << std::get<1>(t) << ' ';
        std::cout << std::get<2>(t) << '\n';
    };

    auto t = std::make_tuple("String", 5.2, 1);

    std::cout 
        << std::get<0>(t) << ' '
        << std::get<1>(t) << ' '
        << std::get<2>(t) << '\n';

    return 0;
}

