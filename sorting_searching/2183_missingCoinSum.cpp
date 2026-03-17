// https://cses.fi/problemset/task/2183
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; i++) std::cin >> numbers[i];
    std::sort(numbers.begin(), numbers.end());

    long long range = 0;
    for (int i = 0; i < n; i++) {
        if (range + 1 < numbers[i]) {
            break;
        } else {
            range += numbers[i];
        }
    }
    std::cout << range + 1 << std::endl;
}