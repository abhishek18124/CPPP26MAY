/*

https://codeforces.com/problemset/problem/1183/D

input
3
8
1 4 8 4 5 6 3 8
16
2 1 3 3 4 3 4 4 1 3 2 2 2 4 1 1
9
2 2 4 4 4 7 7 7 7

output
3
10
9

*/

#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>
#include<map>
typedef long long ll;

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;

	while (q--) {

		int n; cin >> n;

		map<int, int> freqMap;
		for (int i = 0; i < n; ++i) {
			int type;
			cin >> type;
			freqMap[type]++;
		}

		vector<int> frequencies;
		frequencies.reserve(n);
		for (auto const& [type, freq] : freqMap) {
			frequencies.push_back(freq);
		}

		// sort descending so we can take the largest groups first
		sort(frequencies.rbegin(), frequencies.rend());

		int ans = frequencies[0];
		int lastTaken = frequencies[0];
		for (int i = 1; i < (int)frequencies.size(); i++) {
			int take = min(frequencies[i], lastTaken - 1);
			if (take == 0) break;
			ans += take;
			lastTaken = take;
		}

		cout << ans << "\n";

	}

	return 0;
}