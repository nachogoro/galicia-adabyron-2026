#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	cin.ignore();

	while (n--) {
		string line;
		getline(cin, line);

		stack<char> s;
		for (auto c : line) {
			if (s.empty() || s.top() != c) s.push(c);
			else s.pop();
		}

		if (s.empty()) cout << "0\n";
		else {
			stack<char> reversed;
			while (!s.empty()) {
				reversed.push(s.top());
				s.pop();
			}

			while (!reversed.empty()) {
				cout << reversed.top();
				reversed.pop();
			}
			cout << "\n";
		}
	}
}
