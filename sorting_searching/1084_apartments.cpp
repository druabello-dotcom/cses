// https://cses.fi/problemset/task/1084
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int main() {
    int n, m, k;
    int counter = 0;
    std::cin >> n >> m >> k;
    std::vector<int> desiredSize(n);
    std::vector<int> availApart(m);
    for (int i = 0; i < n; i++) {
        std::cin >> desiredSize[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> availApart[i];
    }
    std::sort(desiredSize.begin(), desiredSize.end());
    std::sort(availApart.begin(), availApart.end());
    
    int i = 0;
    int j = 0;
    while (i < n && j < m) {
        int diff = abs(availApart[j] - desiredSize[i]);
        if (diff <= k) {
            i++;
            j++;
            counter++;
        } else if (k < diff) {
            if (availApart[j] < desiredSize[i]) {
                j++;
            } else if (desiredSize[i] < availApart[j]) {
                i++;
            }
        }
    }
    std::cout << counter << std::endl;
}