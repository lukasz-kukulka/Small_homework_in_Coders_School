 #include <iostream>
 #include <algorithm>
 #include <vector>
 #include <string>


 int main () {
    constexpr auto size = 13;
    std::vector<std::pair<int, std::string>> v {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
         };
    std::vector<int>v2(v.size());
    std::vector<std::string>v3;
    std::vector<char>v4(size);
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
    std::generate_n(begin(v4), size, [c = 'a' - 2]() mutable { return c+=2; });
    for (const auto& ele : v4) {
        std::cout << ele << ", ";
    }
    return 0;
 }