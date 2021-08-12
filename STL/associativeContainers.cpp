#include <iostream>
#include <map>

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
    return 0;
}