// this will get TLE
#include <iostream>
#include <list>
#include <iterator>
#include <cmath>

void solve(std::list<int>& children, int n, int k) {
	int adv = k % n;
	int t = adv + 1;
	auto point = std::next(children.begin(), adv);

	while (0 <= n) {
		n--;
		auto prev = point;
		std::cout << *point << ' ';
		if (!n) break;

		++point;
		if (point == children.end()) point = children.begin();
		children.erase(prev);

		adv = k % n;
		if (n < t) t = 1;
		if (n < t + adv) {
			int diff = n - t;
			adv = abs(adv - diff - 1);
			t = adv + 1;
			point = std::next(children.begin(), adv);
		} else {
			std::advance(point, adv);
			t += adv;
		}
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	int n, k;
	std::cin >> n >> k;
	std::list<int> li;
	for (int i = 1; i <= n; i++) li.push_back(i);

	solve(li, n, k);
}