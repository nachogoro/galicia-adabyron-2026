#include <bits/stdc++.h>
using namespace std;

int main() {
	map<string, int> f;
	int most_common = 0;
	string winner;

	string word;
	while (cin >> word) {
		f[word]++;

		if (f[word] == most_common) winner = "";
		if (f[word] > most_common) {
			winner = word;
			most_common = f[word];
		}
	}

	if (winner.empty()) cout << "empate\n";
	else 				cout << winner << "\n";
}
