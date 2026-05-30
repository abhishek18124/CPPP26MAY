/*

Implementation of Fractional Knapsack

input
5 7
8 4
9 3
5 2
4 4
3 2

output
18

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

typedef long long ll;

using namespace std;

// return true if you want 'a' to be ordered before 'b'
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	int v1 = a.first; int w1 = a.second;
	int v2 = b.first; int w2 = b.second;
	// return (double)v1 / w1 > (double)v2 / w2; // we avoid division to prevent floating-point precision errors.
	return 1ll * v1 * w2 > 1ll * v2 * w1;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, c;
	cin >> n >> c;

	vector<pair<int, int>> items(n);
	for (int i = 0; i < n; i++) {
		int v, w;
		cin >> v >> w;
		items[i] = {v, w};
	}

	sort(items.begin(), items.end(), cmp);

	double maxProfit = 0;

	// for(pair<int, int>& p : items) {
	// 	int v = p.first;
	// 	int w = p.second;
	// }

	for (auto& [v, w] : items) {

		if (w <= c) {
			maxProfit += v;
			c -= w;
		} else {
			maxProfit += (double)v / w * c;
			break;
		}
	}

	cout << fixed << setprecision(6) << maxProfit << '\n';

	return 0;
}