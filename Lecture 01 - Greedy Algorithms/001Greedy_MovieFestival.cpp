/*

https://cses.fi/problemset/task/1629/

input
3
3 5
4 9
5 8

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

	vector<pair<int, int>> movies(n);

	for (int i = 0; i < n; i++) {
		// storing as {end, start} for easy sorting
		int start, end; cin >> start >> end;
		movies[i] = {end, start};
		// cin >> movies[i].second >> movies[i].first;
	}

	// time : O(nlogn + n) ~ O(nlogn)
	// space: logn due to sort()

	sort(movies.begin(), movies.end());

	int maxMovies  = 0; // tracks then maximum no. of movies that can be watched
	int lastEnd = 0; // tracks the ending time of the last movie watched

	for (int i = 0; i < n; i++) {
		int end   = movies[i].first;
		int start = movies[i].second;
		if (start >= lastEnd) {
			maxMovies++;
			lastEnd = end;
		}
	}

	cout << maxMovies << "\n";

	// time : nlogn + n ~ O(nlogn)
	// space: logn

	return 0;
}