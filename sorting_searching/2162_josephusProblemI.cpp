#include <iostream>
#include <list>
#include <iterator>

int main() {
	int n;
	std::cin >> n;
	std::list<int> children;
	for (int i = 1; i <= n; i++) children.push_back(i);

	auto point = std::next(children.begin());
	int mx = *children.rbegin();
	int i = 0;
	while (i <= n) {
		i++;
		auto prev = point;
		int c = *point;
		std::cout << c << ' ';

		if (c == mx) {
			point = std::next(children.begin());
		} else if (c == *std::next(children.rbegin())) {
			point = children.begin();
		} else point = std::next(point, 2);
		if (i == n) break;

		children.erase(prev);
		mx = *children.rbegin();
		if (i == n - 1) point = children.begin();
	}
}