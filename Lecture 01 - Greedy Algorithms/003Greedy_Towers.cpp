/*

https://cses.fi/problemset/task/1073

input
5
3 8 2 1 5

output
2

*/

#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> sz(n); // sz[i] = size of the ith cube
	for (int i = 0; i < n; i++) {
		cin >> sz[i];
	}

	vector<int> towerTops; // towerTops[i] = top element of the ith tower
	for (int i = 0; i < n; i++) {
		// find the first tower whose top is strictly greater than sz[i]
		auto it = upper_bound(towerTops.begin(), towerTops.end(), sz[i]);
		if (it == towerTops.end()) {
			// no suitable tower found, create a new tower
			towerTops.push_back(sz[i]);
		} else {
			// place the ith cube on this tower & replace the top with current cube to keep tower tops minimal
			*it = sz[i];
		}
	}

	cout << towerTops.size() << '\n';

	// time : O(nlogn)
	// space: O(n) due to towerTops

	return 0;
}