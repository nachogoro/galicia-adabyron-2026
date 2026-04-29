#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	int max_t = -1;
	int best_x = -1;

	for (int x = 0; x < n; ++x) {
		cout << "? " << x << " 0" << endl;
		int t;
		cin >> t;

		if (t > max_t) {
			best_x = x;
			max_t = t;
		}
	}

	max_t = -1;
	int best_y = -1;
	for (int y = 0; y < n; ++y) {
		cout << "? 0 " << y << endl;
		int t;
		cin >> t;

		if (t > max_t) {
			best_y = y;
			max_t = t;
		}
	}

	cout << "! " << best_x << " " << best_y << endl;

}

