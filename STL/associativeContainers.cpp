#include <iostream>
#include <map>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>



float radius(int x, int y) {
    return std::sqrt(std::abs(x) * std::abs(x) + std::abs(y) * std::abs(y));
}

struct Point {
    int y;
    int x;

    bool operator<(const Point point) const {
        return radius(x, y) < radius(point.x, point.y);
    }
};

int main() {
    std::multimap<int, std::string> map;
    map.insert({5, "Ala"});
    map.insert({5, "Ma"});
    map.insert({5, "Kota"});
    map.insert({5, "A"});
    map.insert({5, "Kot"});
    map.insert({5, "Ma"});
    map.insert({5, "Ale"});
    auto it = map.find(5);
    for (; it != map.end() ; ++it) {
        if (it->second.size() == 3) {
            std::cout << it->first << " | " << it->second << '\n';
        }
    }
    for (const auto& [k, v] : map){
        if (v.size() == 3) {
            std::cout << k << " | " << v << '\n';
        }
    }
    std::cout << "_________________________________________________________________________________________" << '\n';

    std::map<std::string, Point> map2{ { "Wrocław", {17, 51}},
                                       { "Moskwa", {37, 55} },
                                       { "Nowy Jork", {-74, 40} },
                                       { "Sydney", {151, -33} }, };
    for (const auto& [k, v] : map2) {
        if (radius(v.x, v.y) < 70) {
            std::cout << "Distance less then 70 have: " << k << '\n';
        }
    }
    auto searchEle = map2.find("Sydney");
    std::cout << searchEle->first << " distance to point 0 = " << radius(searchEle->second.x, searchEle->second.y) << '\n';
    std::cout << "_________________________________________________________________________________________" << '\n';

    std::map<Point, std::string> map3{ { {17, 51}, "Wrocław" },
                                       { {37, 55}, "Moskwa" },
                                       { {-74, 40}, "Nowy Jork" },
                                       { {151, -33}, "Sydney" }, };
    for (const auto& [k, v] : map3) {
        if (radius(k.x, k.y) < 70) {
            std::cout << "Distance less then 70 have: " << v << '\n';
        }
        if (v == "Sydney") {
            std::cout << "Sydney coordinates = (" << k.y << " " << k.x << ")\n";
        }
    }
   std::cout << "_________________________________________________________________________________________" << '\n';

    std::set<int> set;
    for (int i = 20; i >= -20; i--) {
        set.insert(i);
    }
    set.insert(-10);
    set.insert(0);
    set.insert(10);
    set.insert(-100);
    set.insert(100);

    std::multiset<int> multiset;
    for (int i = 0; i <= 40; i++) {
        multiset.insert(i);
    }
    std::cout << "----- multiset -----" << '\n';
    for (const auto & ele : multiset) {
        std::cout << ele << " ";
    }
    std::cout << "\n--------------------" << '\n';

    multiset.insert(-10);
    multiset.insert(0);
    multiset.insert(10);
    multiset.insert(-100);
    multiset.insert(100);

    std::cout << "----- multiset -----" << '\n';
    for (const auto & ele : multiset) {
        std::cout << ele << " ";
    }
    std::cout << "\n--------------------" << '\n';
    multiset.merge(set);

    std::cout << "----- multiset after merge with set  -----" << '\n';
    for (const auto & ele : multiset) {
        std::cout << ele << " ";
    }
    std::cout << "\n--------------------" << '\n';
    auto [l, h] = multiset.equal_range(0);
    for (; l != h; l++) {
        std::cout << *l << " ";
    }
    std::cout << '\n';
    auto [ln, hn] = multiset.equal_range(50);
    if (ln == hn) {
        std::cout << "No elements\n";
    }
    for (; ln != hn; ln++) {
        std::cout << *ln << " ";
    }
    std::cout << '\n';
    return 0;

}

    // Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w std::multiset
    // Wstaw nowe elementy: -10, 0, 10, 100, -100
    // Połącz oba zbiory w jeden (ma to być std::multiset)
    // Znajdź wszystkie elementy równe 0 i 50
