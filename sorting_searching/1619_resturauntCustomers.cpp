// https://cses.fi/problemset/task/1619
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

// use sweep line algorithm
int main() {
    int n;
    std::cin >> n;
    std::multiset<std::pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        times.insert({a, 1});
        times.insert({b, -1});
    }

    // count
    int max = 1;
    int count = 0;
    for (auto itr : times) {
        count += itr.second;
        if (max < count) max = count;
    }
    std::cout << max << std::endl;
}