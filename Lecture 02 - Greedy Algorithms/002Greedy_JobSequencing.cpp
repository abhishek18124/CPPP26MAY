/*

Job Sequencing

input
5
2 1
4 3
5 3
3 1
1 2

output
12

constraints

n <= 1e5
1 <= t[i] <= 1e5
1 <= p[i] <= 1e9

*/

#include<iostream>
#include<vector>
#include<algorithm>
typedef long long ll;

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<pair<int, int>> jobs(n);
	for (int i = 0; i < n; i++) {
		int p, d; cin >> p >> d;
		jobs[i] = {p, d};
		// cin >> jobs[i].first >> jobs[i].second;
	}

	// sort by profit descending

	sort(jobs.begin(), jobs.end(),
	[](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	});

	int maxDeadLine = 0;
	for (auto& [p, d] : jobs) {
		maxDeadLine = max(maxDeadLine, d);
	}

	vector<bool> occupied(maxDeadLine + 1, false);

	ll maxProfit = 0;

	for (auto& [p, d] : jobs) {
		// find the rightmost free slot <= d for scheduling the current job
		for (int t = d; t >= 1; t--) {
			if (!occupied[t]) {
				occupied[t] = true;
				maxProfit += p;
				break;
			}
		}
	}

	cout << maxProfit << '\n';

	// time : nlogn + n + n.maxDeadline
	// 10^5.log10^5 + 10^5 + 10^5.10^5 : TLE

	// space : maxDealine ~ 10^5

	return 0;
}