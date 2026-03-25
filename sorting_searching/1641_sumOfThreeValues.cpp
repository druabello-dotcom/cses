// https://cses.fi/problemset/task/1641/
#include <iostream>
#include <vector>
#include <algorithm>

int solve(std::vector<std::pair<int, int>>& nums, std::vector<int>& pos, int& x) {
	for (int t = 0; t < nums.size(); t++) {
		int i = 0;
		int j = nums.size() - 1;
		while (i < j) {
			if (i == t) {
				i++;
				continue;
			} else if (j == t) {
				j--;
				continue;
			}

			int sum = nums[t].first + nums[i].first + nums[j].first;
			if (sum < x) {
				i++;
			} else if (sum == x) {
				pos.push_back(nums[t].second);
				pos.push_back(nums[i].second);
				pos.push_back(nums[j].second);
				return 0;
			} else if (x < sum) {
				j--;
			}
		}
	}
	return 0;
}
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, x;
	std::cin >> n >> x;
	std::vector<std::pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		int k;
		std::cin >> k;
		arr[i] = {k, i + 1};
	}

	std::vector<int> positions;
	std::sort(arr.begin(), arr.end());
	solve(arr, positions, x);

	if (positions.size() == 0) std::cout << "IMPOSSIBLE" << std::endl;
	else for (int i : positions) std::cout << i << ' ';
}