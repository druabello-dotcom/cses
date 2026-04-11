#include <iostream>
#include <vector>
#include <set>
#include <iterator>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	std::set<int> win;
	for (int i = 0; i < n; i++) std::cin >> arr[i];

	long long c = 0;
	int i = 0, j = 0;
	while (i<n && j<n) {
		if (win.find(arr[j]) != win.end()) {
			win.erase(arr[i]);
			i++;
		} else {
			win.insert(arr[j]);
			j++;
			c += win.size();
		}
	}
	std::cout << c;
}