// https://cses.fi/problemset/task/2216
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> numbers(n);
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        numbers[i] = {k, i + 1};
    }
    std::sort(numbers.begin(), numbers.end());

    int counter = 1;
    for (int i = 1; i < n; i++) {
        int compare = numbers[i - 1].second;
        int pos = numbers[i].second;
        if (pos < compare) {
            counter++;
        }
    }
    std::cout << counter << std::endl;
}