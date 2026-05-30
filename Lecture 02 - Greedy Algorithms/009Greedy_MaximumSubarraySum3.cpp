/*

https://cses.fi/problemset/task/1643/

input
5
-3 2 -1 4 -5

output
5

input
8
-1 3 -2 5 3 -5 2 2

output
9

*/

#include<iostream>
#include<vector>
typedef long long ll;

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// time : O(n)
	// space: O(1)

	ll x = a[0];
	ll maxSubarraySumSoFar = x;

	for (int j = 1; j < n; j++) {
		x = max(x + a[j], (ll)a[j]);
		maxSubarraySumSoFar = max(maxSubarraySumSoFar, x);
	}

	cout << maxSubarraySumSoFar << '\n';

	return 0;
}