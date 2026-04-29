#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool ok(ll target, vector<int>& cap, vector<int>& spill) {
	ll exceso = 0;
	for (int i = 0; i < cap.size(); ++i) {
		// El exceso acumulado (positivo o negativo) debe extenderse hacia la
		// derecha si, siendo positivo, es rentable transferir ese exceso a la
		// derecha usando la conexión; o siempre si es negativo (déficit),
		// porque es necesario que fluya hacia la derecha para que todos
		// lleguen a target.
		if ((exceso > 0 && exceso > spill[i-1]) || (exceso < 0)) {
			exceso -= spill[i-1];
		} else {
			exceso = 0;
		}

		auto sobrante = cap[i] - target;
		exceso += sobrante;
	}

	return exceso >= 0;
}

int main() {
	int N;
	cin >> N;
	vector<int> capacity(N);
	for (int i = 0; i < N; ++i) {
		cin >> capacity[i];
	}

	vector<int> spill(N-1);
	for (int i = 0; i < N - 1; ++i) {
		cin >> spill[i];
	}

	ll lo = *min_element(capacity.begin(), capacity.end()), hi = *max_element(capacity.begin(), capacity.end()) + 1;
	while (lo < hi) {
		ll mid = lo + (hi - lo) / 2;
		if (!ok(mid, capacity, spill)) hi = mid;
		else lo = mid+ 1;
	}

	cout << lo-1 << "\n";
}
