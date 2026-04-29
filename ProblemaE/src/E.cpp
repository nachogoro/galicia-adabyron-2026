#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 1000001;

int spf[MAXVAL];

void build_sieve() {
	for (int i = 2; i < MAXVAL; ++i) {
		if (spf[i] == 0) {
			for (int j = i; j < MAXVAL; j += i) {
				if (spf[j] == 0) spf[j] = i;
			}
		}
	}
}

vector<int> factorize(int x) {
	vector<int> primes;
	while (x > 1) {
		int p = spf[x];
		primes.push_back(p);
		while (x % p == 0) x /= p;
	}
	return primes;
}

int main() {
	build_sieve();

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	vector<vector<int>> factors(n);
	for (int i = 0; i < n; ++i) factors[i] = factorize(a[i]);

	// used[p] = posición del elemento más a la derecha en la ventana que
	// contiene el primo p
	unordered_map<int, int> used;
	long long count = 0;
	int l = 0; // extremo izquierdo de la ventana

	for (int r = 0; r < n; ++r) {
		// Buscar el conflicto más a la derecha: la posición más alta
		// dentro de la ventana que comparte algún primo con a[r].
		// Si no hay conflicto, queda como l-1 (antes de la ventana).
		int conflict = l - 1;
		for (int p : factors[r]) {
			if (used.count(p)) {
				conflict = max(conflict, used[p]);
			}
		}

		// Avanzar l hasta pasar el conflicto, limpiando los primos
		// de cada elemento que sale de la ventana.
		while (l <= conflict) {
			for (int p : factors[l]) {
				used.erase(p);
			}
			l++;
		}

		// Registrar los primos de a[r] con su posición
		for (int p : factors[r]) {
			used[p] = r;
		}

		// Todas las subsecuencias que terminan en r y empiezan en [l..r]
		// son armoniosas
		count += (r - l + 1);
	}

	cout << count << "\n";
}
