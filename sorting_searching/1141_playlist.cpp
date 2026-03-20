// https://cses.fi/problemset/task/1141
#include <iostream>
#include <vector>
#include <map>
#include <iterator>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> playlist(n);
	for (int i = 0; i < n; i++) std::cin >> playlist[i];

	int counter = 1;
	int i = 0;
	int j = 1;
	std::map<int, bool> map;
	map.insert({playlist[i], true});
	while (j < n && i < n) {
		int curr = playlist[j];
		if (map.find(curr) != map.end()) {
			map.erase(playlist[i]);
			if (i == j - 1) {
				i++;
				j++;
				map.insert({playlist[i], true});
			} else i++;
		}  else {
			map.insert({playlist[j], true});
			j++;
		}

		if (counter < map.size()) counter = map.size();
	}
	std::cout << counter << std::endl;
}