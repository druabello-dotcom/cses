// https://cses.fi/problemset/task/1090
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> weightArr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> weightArr[i];
    }
    std::sort(weightArr.begin(), weightArr.end());

    int i = 0;
    int j = n - 1;
    int gondolas = 0;
    while (i <= j) {
        if (weightArr[i] + weightArr[j] <= x) {
            i++;
            j--;
        } else {
            j--;
        }
        gondolas++;
    }
    std::cout << gondolas << std::endl;
}