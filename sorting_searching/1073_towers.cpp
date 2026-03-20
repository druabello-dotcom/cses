// https://cses.fi/problemset/task/1073
#include <iostream>
#include <vector>
#include <set>
#include <iterator>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> cubes(n);
	for (int i = 0; i < n; i++) std::cin >> cubes[i];

	std::multiset<int> tow;
	for (int i = 0; i < n; i++) {
		int c = cubes[i];
		auto itr = tow.upper_bound(c);
		if (itr != tow.end()) {
			tow.erase(itr);
		}
		tow.insert(c);
	}
	std::cout << tow.size() << std::endl;
}