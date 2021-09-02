#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <random>

void binarySearchVector() {
    std::random_device rd;
    std::mt19937 g(rd());
    std::vector<int> v (10000);
    std::iota(begin(v), end(v), 1);
    std::shuffle(begin(v), end(v), g);
    std::sort(begin(v), end(v));
    std::cout << " _____________________________________________BINARY SEARCH__________________________________________________\n";
    
    std::uniform_int_distribution<size_t> range(1, 10000);
    int randomSearch = range(g);
    std::cout << "Searching value: " << randomSearch << '\n';
    int steps { 1 };
    bool isFounded { false };
    auto beginIt = begin(v);
    auto midIt = begin(v) + v.size() / 2;
    auto endIt = end(v);
    auto dist = std::distance(midIt, endIt);
    
    while (dist > 0) {
        if (randomSearch > *midIt) {
            dist = std::distance(midIt, endIt) / 2;
            beginIt = midIt;
            std::cout << " MORE " << '\n';
            midIt += dist;
        } else {
            dist = std::distance(beginIt, midIt) / 2;
            endIt = midIt;
            std::cout << " LESS " << '\n';
            midIt -= dist;
        }
        steps++;
        if (*midIt == randomSearch) {
            isFounded = true;
            break;
        }
    }
    
    if (isFounded) {
        std::cout << "Value : " << randomSearch << " was founded in " << std::distance(begin(v), midIt) << " position, with " << steps << " steps.\n";
    } else {
        std::cout << "Value was't found, use a " << steps << " steps.\n";
    }
}

int main () {
    
    // napisac algorytm wyszukiwania binarnego zwraca iterator na elemant albo iterator na koniec, zobaczyc w  wektorze i liście np.
    binarySearchVector();


    // for (auto ele : v) {
    //     std::cout << ele << " ";
    // }
    return 0;
}