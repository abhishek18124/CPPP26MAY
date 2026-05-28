/*

https://cses.fi/problemset/task/1632

input
5 2
1 5
8 10
3 6
2 5
6 9

output
4

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

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> movies(n);

	for (int i = 0; i < n; i++) {
		// storing as {end, start} for easy sorting
		int start, end;
		cin >> start >> end;
		movies[i] = {end, start};
	}

	// sort by end time to ensure we always pick movies that finish earliest
	sort(movies.begin(), movies.end());

	// multiset stores the end times of movies currently being watched by the k members.
	multiset<int> ms;
	for (int i = 0; i < k; i++) {
		ms.insert(0); // all members free at time 0
	}

	int maxMovies  = 0; // tracks maximum no. of movies

	for (int i = 0; i < n; i++) {
		int end   = movies[i].first;
		int start = movies[i].second;
		// find the member to assign the ith movie to

		// find the first member who finishes AFTER this movie starts
		auto it = ms.upper_bound(start);
		if (it == ms.begin()) {
			// no members is free to watch the ith movie
			continue;
		}

		it--;
		ms.erase(it);
		ms.insert(end);
		maxMovies++;

	}

	cout << maxMovies << "\n";

	return 0;
}