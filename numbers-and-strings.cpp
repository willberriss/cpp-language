#include <iostream>
#include <string>
#include <algorithm>

std::string formatNum(int num) {

    std::string s = std::to_string(num);
    std::string mystr;

    // iterate over string from the end to the start
    // if 4 numbers, insert a comma after 4th, etc, etc

    int count = 0;
    for (auto i = s.rbegin(); i != s.rend(); ++i) {
        //std::cout << "*i=" << *i << " ";
        if (count == 0) {
            mystr += *i;
        }
        else if (count % 3 == 0) {
            // insert a comma
            mystr += ',';
            mystr += *i;
        }
        else {
            mystr += *i;
        }
        
        ++count;
    }

    std::reverse(mystr.begin(), mystr.end());

    return mystr;
}
 
int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    std::string res = formatNum(num);
    std::cout << res << "\n";

    return 0;
}

