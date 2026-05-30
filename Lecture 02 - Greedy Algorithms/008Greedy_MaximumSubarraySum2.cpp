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

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ll x = arr[0];
	ll maxSubarraySumSoFar = x;

	ll prefixSum = arr[0];
	ll minPrefixSumSoFar = min(0ll, prefixSum);

	for (int j = 1; j < n; j++) {
		prefixSum += arr[j];
		x = prefixSum - minPrefixSumSoFar;
		maxSubarraySumSoFar = max(maxSubarraySumSoFar, x);
		minPrefixSumSoFar   = min(minPrefixSumSoFar, prefixSum);
	}

	cout << maxSubarraySumSoFar << '\n';

	return 0;
}