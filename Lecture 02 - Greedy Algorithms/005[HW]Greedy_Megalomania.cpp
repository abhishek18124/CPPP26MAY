/*

https://atcoder.jp/contests/abc131/tasks/abc131_d

input
5
2 4
1 9
1 8
4 9
3 12

output
Yes

input
3
334 1000
334 1000
334 1000

output
No

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
		// storing as {deadline, duration} for easy sorting
		int duration, deadline;
		cin >> duration >> deadline;
		jobs[i] = {deadline, duration};
	}

	sort(jobs.begin(), jobs.end());

	bool flag = true; // assume Kizahashi complete all the jobs in time
	int clock = 0;

	for (auto [deadline, duration] : jobs) {
		clock += duration;
		if (clock > deadline) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "Yes";
	} else {
		cout << "No";
	}

	return 0;
}