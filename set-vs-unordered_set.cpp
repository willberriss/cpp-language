#include <iostream>
#include <chrono>
#include <unordered_set>
#include <set>
#include <string>

#include <algorithm>  // next_permutation
#include <functional> // bind

template <typename TimeT = std::chrono::milliseconds> 
struct measure 
{
    template <typename F, typename... Args> static typename TimeT::rep execution(F func, Args&&... args)
    {
        auto start = std::chrono::system_clock::now();

        // Now call the function with all the parameters you need.
        func(std::forward<Args>(args)...);
        auto duration = std::chrono::duration_cast<TimeT>(std::chrono::system_clock::now() - start);
        return duration.count();
    }
};

std::string baseString = "abcdefghi";

class SetContainer
{
public:
    void populate_unordered_set()
    {
        std::string s = baseString;
        while(std::next_permutation(begin(s), end(s))) {
            unorderedSet.insert(s);
        }
    }

    void populate_ordered_set()
    {
        std::string s = baseString;
        while(std::next_permutation(begin(s), end(s))) {
            orderedSet.insert(s);
        }
    }

    bool ordered_set_has(std::string val)
    {
        return (orderedSet.find(val) != orderedSet.end());
    }

    bool unordered_set_has(std::string val)
    {
        return (unorderedSet.find(val) != unorderedSet.end());
    }

    long iterate_ordered_set()
    {
        long count = 0;

        for(auto& s : orderedSet) {
            count++;
        }
        return count;
    }

    bool iterate_unordered_set()
    {
        long count = 0;
        for(auto& s : unorderedSet) {
            count++;
        }
        return count;
    }

private:
    std::unordered_set<std::string> unorderedSet;
    std::set<std::string> orderedSet;
};

using nsMeasure = measure<std::chrono::nanoseconds>;

int main(int argc, char** argv)
{
    SetContainer setContainer;
    std::cout << "Unordered set population time (ns) :"
              << nsMeasure::execution(std::bind(&SetContainer::populate_unordered_set, &setContainer)) << '\n';
    std::cout << "  Ordered set population time (ns) :"
              << nsMeasure::execution(std::bind(&SetContainer::populate_ordered_set, &setContainer)) << "\n\n";

    std::string searchVal = "abcdefgih";
    std::cout << "searching for " << searchVal << " :\n";

    std::cout << "Unordered Set (ns) :"
              << nsMeasure::execution(std::bind(&SetContainer::unordered_set_has, &setContainer, searchVal)) << '\n';
    std::cout << "  Ordered Set (ns) :"
              << nsMeasure::execution(std::bind(&SetContainer::ordered_set_has, &setContainer, searchVal)) << "\n\n";

    std::cout << "Unordered set's elements iteration (ns) :"
              << nsMeasure::execution(std::bind(&SetContainer::iterate_unordered_set, &setContainer)) << '\n';
    std::cout << "  Ordered set's elements iteration (ns) :"
              << nsMeasure::execution(std::bind(&SetContainer::iterate_ordered_set, &setContainer)) << "\n\n"   ;

    return 0;
}
