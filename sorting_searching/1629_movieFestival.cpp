// https://cses.fi/problemset/task/1629
#include <iostream>
#include <set>
#include <iterator>

int main() {
    int n;
    std::cin >> n;
    std::multiset<std::pair<int, int>> movieTimes;
    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        movieTimes.insert({b, a});
    }

    auto itr = movieTimes.begin();
    int greatestEnd = 0;
    int count = 0;
    while (itr != movieTimes.end()) {
        int start = itr->second;
        int end = itr->first;
        if (greatestEnd <= start) {
            greatestEnd = end;
            count++;
        }
        itr++;
    }
    std::cout << count << std::endl;
}