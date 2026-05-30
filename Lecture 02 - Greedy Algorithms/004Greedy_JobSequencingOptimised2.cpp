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
1 <= t[i] <= 1e9
1 <= p[i] <= 1e9

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
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
	}

	sort(jobs.begin(), jobs.end(),
	[](const pair<int, int>& a, const pair<int, int>& b) {
		return a.first > b.first;
	});

	// you only need slots up to n.
	// if a deadline greater than 1e5, it's effectively the same as n.
	set<int> slots;
	for (int i = 1; i <= n; i++) {
		slots.insert(i);
	}

	ll maxProfit = 0;

	for (auto& [p, d] : jobs) {
		d = min(d, n); // cap the deadline to n

		// find the rightmost free slot <= d for scheduling the current job
		auto it = slots.upper_bound(d);
		if (it == slots.begin()) {
			// no slot <= d available, current job cannot be scheduled
			continue;
		}
		it--; // now points to largest slot ≤ d
		slots.erase(it);
		maxProfit += p;
	}

	cout << maxProfit << '\n';

	return 0;
}