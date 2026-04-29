#include <bits/stdc++.h>
using namespace std;

int mod(int a, int b) {
	return ((a % b) + b) % b;
}

int main() {
	int N;
	cin >> N;

	while (N--) {
		int C;
		cin >> C;
		deque<int> d;
		while (C--) {
			int v;
			cin >> v;
			d.push_back(v);
		}

		for (int i = 0; i < d.size(); ++i) {
			if (d.back() == d.front()) {
				d.push_front(d.back());
				d.pop_back();
			} else {
				break;
			}
		}

		if (d.back() == d.front()) {
			// Una sola franja
			cout << "CELTA\n";
			continue;
		}

		int last = d.front(); d.pop_front();
		int first_run = 1;

		while (d.front() == last) {
			first_run++;
			d.pop_front();
		}

		int franjas = 1;
		int run = first_run;

		while (!d.empty()) {
			if (d.front() == last) {
				run++;
			} else {
				if (run != first_run) break;
				last = d.front();
				run = 1;
				franjas++;
			}
			d.pop_front();
		}

		if (run == first_run) cout << franjas << "\n";
		else cout << "CELTA\n";
	}
}
