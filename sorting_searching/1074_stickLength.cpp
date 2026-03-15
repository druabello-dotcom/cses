// https://cses.fi/problemset/task/1074
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> sticks(n);
    for (int i = 0; i < n; i++) std::cin >> sticks[i];
    std::sort(sticks.begin(), sticks.end());

    // find median
    long long median = sticks[n / 2];
    long long cost = 0;
    for (int i = 0; i < n; i++) {
        cost += std::abs(sticks[i] - median);
    }
    std::cout << cost << std::endl;
}