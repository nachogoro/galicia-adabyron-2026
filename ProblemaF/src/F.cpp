#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

const ll LINF = 1e18;

vector<ll> dijkstra(int s, vector<vector<pii>>& adj) {
	int n = adj.size();
	vector<ll> dist(n, LINF);
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (d > dist[u]) continue;
		for (auto [v, w] : adj[u]) {
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({dist[v], v});
			}
		}
	}
	return dist;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<vector<pii>> adj(N);
	for (int i = 0; i < M; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		a--; b--;
		adj[a].push_back({b, d});
		adj[b].push_back({a, d});
	}

	int K;
	cin >> K;
	vector<int> candidates(K);
	for (int i = 0; i < K; ++i) {
		cin >> candidates[i];
		candidates[i]--;
	}

	ll answer = LINF;
	for (int c : candidates) {
		auto dist = dijkstra(c, adj);
		ll max_dist = *max_element(dist.begin(), dist.end());
		answer = min(answer, max_dist);
	}

	cout << answer << "\n";
}
