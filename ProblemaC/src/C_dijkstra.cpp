#include <bits/stdc++.h>
using namespace std;


using ll = long long;
using pii = pair<int, int>;

const ll LINF = 1e18;

vector<ll> dijkstra(int s, vector<vector<pii>>& adj) {
	int n = adj.size();
	vector<ll> dist(n, LINF);

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

	dist[s] = 0; pq.push({0, s});
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
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> portal_in_room(N, 0);
	for (int i = 0; i < N; ++i) {
		cin >> portal_in_room[i];
	}

	vector<int> portal_to_vertex(K+1, -1);
	vector<int> room_to_vertex(N, -1);
	int vertex = 0;
	for (int i = 0; i < N; ++i) {
		if (portal_in_room[i] == 0) {
			room_to_vertex[i] = vertex++;
		} else {
			if (portal_to_vertex[portal_in_room[i]] == -1) {
				// First occurrence of portal
				portal_to_vertex[portal_in_room[i]] = vertex++;
			}

			room_to_vertex[i] = portal_to_vertex[portal_in_room[i]];
		}
	}

	vector<vector<pii>> adj(vertex);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u = room_to_vertex[u-1];
		v = room_to_vertex[v-1];

		adj[u].push_back({v, 1});
		adj[v].push_back({u, 1});
	}

	auto dist = dijkstra(0, adj);
	if (dist[room_to_vertex[N-1]] == LINF) cout << "-1\n";
	else cout << dist[room_to_vertex[N-1]] << "\n";
}
