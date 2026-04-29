#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;

	while (T--) {
		int N, E, K;
		cin >> N >> E >> K;
		vector<int> people(E);
		for (int i = 0; i < E; ++i) {
			cin >> people[i];
		}

		sort(people.begin(), people.end());

		int needed = 0;
		int covered_up_to = -1;
		for (auto p : people) {
			if (p > covered_up_to) {
				++needed;
				covered_up_to = p + 2*K;
			}
		}

		cout << needed << "\n";
	}
}
