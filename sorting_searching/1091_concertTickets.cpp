// https://cses.fi/problemset/task/1091
#include <iostream>
#include <set>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::multiset<int, std::greater<int>> tickets;
    for (int i = 0; i < n; i++) {
        int t;
        std::cin >> t;
        tickets.insert(t);
    }
    for (int i = 0; i < m; i++) {
        int k;
        std::cin >> k;
        auto it = tickets.lower_bound(k);
        if (it == tickets.end()) {
            std::cout << -1 << std::endl;
        } else {
            std::cout << *it << std::endl;
            tickets.erase(it);
        }

    }
}