// https://cses.fi/problemset/task/1163/
#include <iostream>
#include <map>
#include <set>
#include <iterator>

void solve(int traffPos, std::map<int, int>& lp, std::multiset<int, std::greater<int>>& intervals) {
	auto t = lp.upper_bound(traffPos);
	int diff = t->first - traffPos;
	intervals.erase(intervals.find(t->second));
	t->second = diff;
	intervals.insert(diff);

	--t;
	diff = traffPos - t->first;
	intervals.insert(diff);
	lp.insert({traffPos, diff});

	std::cout << *intervals.begin() << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	int x, n;
	std::cin >> x >> n;

	std::map<int, int> lightPos;
	std::multiset<int, std::greater<int>> intervals;

	lightPos.insert({0, 0});
	lightPos.insert({x, x});
	intervals.insert(x);

	for (int i = 0; i < n; i++) {
		int a;
		std::cin >> a;
		solve(a, lightPos, intervals);
	}
}