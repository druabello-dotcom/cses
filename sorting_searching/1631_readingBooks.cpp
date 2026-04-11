#include <iostream>
#include <algorithm>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	
	long long sum = 0;
	long long mx = 0;

	while (n--) {
		long long t;
		std::cin >> t;
		sum += t;
		mx = std::max(mx, t);
	}

	std::cout << std::max(sum, 2 * mx) << std::endl;
}