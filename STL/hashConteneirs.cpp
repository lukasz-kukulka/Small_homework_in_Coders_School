#include <iostream>
#include <unordered_map>
#include <string>
#include <set>
#include <cmath>
#include <algorithm>

float radius(int x, int y);

struct Point {
    int y;
    int x;

    bool operator<(const Point point) const {
        return radius(x, y) < radius(point.x, point.y);
    }
    bool operator==(const Point point) const {
        return radius(point.x, point.y) == radius(x, y);
    }
};

float radius(int x, int y) {
    return std::sqrt(std::abs(x) * std::abs(x) + std::abs(y) * std::abs(y));
}

namespace std
{
    template<> struct hash<Point>
    {
        std::size_t operator()(Point const& p) const noexcept
        {
            std::size_t h1 = std::hash<int>{}(p.x);
            std::size_t h2 = std::hash<int>{}(p.y);
            return h1 ^ (h2 << 1); // or use boost::hash_combine
        }
    };
}

int main() {
    std::cout << "_________________________________________________________________________________________\n\n";
    std::unordered_map<std::string, Point> cities{ { "Wrocław", {17, 51}},
                                                   { "Moskwa", {37, 55} },
                                                   { "Nowy Jork", {-74, 40} },
                                                   { "Sydney", {151, -33} }, };

    for (const auto& [k, v] : cities) {
        if (radius(v.x, v.y) < 70) {
            std::cout << "Distance less then 70 have: " << k << '\n';
        }
    }
    auto searchEle = cities.find("Sydney");
    std::cout << "Coordinates of " << searchEle->first << " = (" << searchEle->second.x << ", " << searchEle->second.y << ")\n";
    std::cout << "_________________________________________________________________________________________\n\n";

    std::unordered_map<Point, std::string> cities2 { { {17, 51}, "Wrocław" },
                                                     { {37, 55}, "Moskwa" },
                                                     { {-74, 40}, "Nowy Jork" },
                                                     { {151, -33}, "Sydney" }, };
    for (const auto& [k, v] : cities2) {
        if (radius(k.x, k.y) < 70) {
            std::cout << "Distance less then 70 have: " << v << '\n';
        }
        if (v == "Sydney") {
            std::cout << "Sydney coordinates = (" << k.y << " " << k.x << ")\n";
        }
    }
    auto cos = cities2.contains("Sydney");
    return 0;
}