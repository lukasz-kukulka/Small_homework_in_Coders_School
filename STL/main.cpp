#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iterator>

int main() {
    constexpr auto size = 13;
    std::vector<std::pair<int, std::string>> v{
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};
    std::vector<int> v2(v.size());
    std::vector<std::string> v3;
    std::vector<char> v4(size);
    std::transform(begin(v), end(v), begin(v2), [](auto first) { return first.first; });
    std::transform(begin(v), end(v), std::back_inserter(v3), [](auto first) { return first.second + " : " + std::to_string(first.first); });
    for (const auto& ele : v2) {
        std::cout << ele << " ";
    }
    std::cout << "\n------------------------------------------------------------------- \n";
    for (const auto& ele : v3) {
        std::cout << ele << ", ";
    }
    std::cout << "\n------------------------------------------------------------------- \n";
    std::generate_n(begin(v4), size, [c = 'a' - 2]() mutable { return c += 2; });
    for (const auto& ele : v4) {
        std::cout << ele << ", ";
    }
    std::cout << "\n------------------------------------------------------------------- \n";
    std::vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vv.begin(), vv.end(), g);
    std::copy(vv.begin(), vv.end(), std::ostream_iterator<int>(std::cout, " "));

    std::cout << "\n------------------------------------------------------------------- \n";
    std::vector<int> v5 = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    std::sort(begin(v5), end(v5));
    for (const auto& ele : v5) {
        std::cout << ele << ", ";
    }
    v5.erase(std::unique(begin(v5), end(v5)), end(v5));
    std::cout << "\n------------------------------------------------------------------- \n";
    std::copy(begin(v5), end(v5),
              std::ostream_iterator<int>(std::cout, " "));
    std::shuffle(v5.begin(), v5.end(), g);
    std::cout << "\n------------------------------------------------------------------- \n";
    std::copy(begin(v5), end(v5),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n------------------------------------------------------------------- \n";
    return 0;
}
