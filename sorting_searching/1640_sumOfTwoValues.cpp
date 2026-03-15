// https://cses.fi/problemset/task/1640
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<std::pair<int, int>> numbers(n);
    std::vector<int> positions;
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        numbers[i] = {k, i + 1};
    }
    std::sort(numbers.begin(), numbers.end());

    int i = 0;
    int j = n - 1;
    while (i < j) {
        int sum = numbers[i].first + numbers[j].first;
        if (sum == x) {
            positions.push_back(numbers[i].second);
            positions.push_back(numbers[j].second);
            break;
        } else if (x < sum) {
            j--;
            continue;
        } else if (sum < x) {
            i++;
        }
    }

    if (positions.size() == 0) std::cout << "IMPOSSIBLE" << std::endl;
    else {
        for (int p : positions) std::cout << p << " ";
        std::cout << std::endl;
    }
}