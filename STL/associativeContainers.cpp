#include <iostream>
#include <map>
#include <string>
#include <cmath>

float distanceToZeroPoint(int x, int y) {
    return std::sqrt(std::abs(x) * std::abs(x) + std::abs(y) * std::abs(y));
}

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

    struct Point {
        int y;
        int x;

        bool operator<(const Point point) const {
            return (std::sqrt(std::abs(point.x) * std::abs(point.x) + std::abs(point.y) * std::abs(point.y))) < 
                   (std::sqrt(std::abs(x) * std::abs(x) + std::abs(y) * std::abs(y)));
        }
    };



    std::map<std::string, Point> map2{ { "Wrocław", {17, 51}},
                                       { "Moskwa", {37, 55} },
                                       { "Nowy Jork", {-74, 40} },
                                       { "Sydney", {151, -33} }, };
    for (const auto& [k, v] : map2) {
        if (distanceToZeroPoint(v.x, v.y) == 70) {
            std::cout << "Distance 70 have " << k << '\n';
        }
    }
    auto searchEle = map2.find("Sydney");
    std::cout << searchEle->first << " distance to point 0 = " << distanceToZeroPoint(searchEle->second.x, searchEle->second.y) << '\n';
    std::cout << "_________________________________________________________________________________________" << '\n';

    std::map<Point, std::string> map3{ { {17, 51}, "Wrocław" },
                                       { {37, 55}, "Moskwa" },
                                       { {-74, 40}, "Nowy Jork" },
                                       { {151, -33}, "Sydney" }, };
    for (const auto& [k, v] : map3) {
        if (distanceToZeroPoint(k.x, k.y) == 70) {
            std::cout << "Distance 70 have " << v << '\n';
        }
        if (v == "Sydney") {
            std::cout << "Sydney coordinates = (" << k.y << " " << k.x << ")\n";
        }
    }

    return 0;
}