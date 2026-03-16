// https://cses.fi/problemset/task/1643
#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];

    long long max = arr[0];
    long long count = arr[0];
    for (int i = 1; i < n; i++) {
        if (count < arr[i] && count < 0) {
            count = 0;
        }
        count += arr[i];
        if (max < count) {
            max = count;
        }
    }
    std::cout << max << std::endl;
}