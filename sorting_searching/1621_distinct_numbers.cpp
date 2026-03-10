// https://cses.fi/problemset/task/1621
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int counter = 1;
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < arr.size(); i++) {
        std::cin >> arr[i];
    }
    std::sort(arr.begin(), arr.end());

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] < arr[i]) {
            counter++;
        }
    }
    std::cout << counter << std::endl;
}