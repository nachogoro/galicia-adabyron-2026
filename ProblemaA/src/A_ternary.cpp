#include <bits/stdc++.h>
using namespace std;

int query(int x, int y) {
	cout << "? " << x << " " << y << endl;
	int t;
	cin >> t;
	return t;
}

int ternary_search(int lo, int hi, int fixed, bool fix_y) {
	while (hi - lo > 2) {
		int m1 = lo + (hi - lo) / 3;
		int m2 = hi - (hi - lo) / 3;

		int t1 = fix_y ? query(m1, fixed) : query(fixed, m1);
		int t2 = fix_y ? query(m2, fixed) : query(fixed, m2);

		if (t1 < t2) lo = m1 + 1;
		else hi = m2 - 1;
	}

	int best = lo;
	int best_t = fix_y ? query(lo, fixed) : query(fixed, lo);
	for (int i = lo + 1; i <= hi; ++i) {
		int t = fix_y ? query(i, fixed) : query(fixed, i);
		if (t > best_t) {
			best_t = t;
			best = i;
		}
	}
	return best;
}

int main() {
	int n;
	cin >> n;

	int x0 = ternary_search(0, n - 1, 0, true);
	int y0 = ternary_search(0, n - 1, 0, false);

	cout << "! " << x0 << " " << y0 << endl;
}
