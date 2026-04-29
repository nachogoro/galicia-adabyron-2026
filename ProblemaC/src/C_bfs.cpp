#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;

	vector<int> portal_in_room(N);
	for (int i = 0; i < N; ++i) {
		cin >> portal_in_room[i];
	}

	vector<int> portal_to_vertex(K + 1, -1);
	vector<int> room_to_vertex(N);
	int vertex = 0;
	for (int i = 0; i < N; ++i) {
		int p = portal_in_room[i];
		if (p == 0) {
			room_to_vertex[i] = vertex++;
		} else {
			if (portal_to_vertex[p] == -1)
				portal_to_vertex[p] = vertex++;
			room_to_vertex[i] = portal_to_vertex[p];
		}
	}

	vector<vector<int>> adj(vertex);
	for (int i = 0; i < M; ++i) {
		int u, v;
		cin >> u >> v;
		u = room_to_vertex[u - 1];
		v = room_to_vertex[v - 1];
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int src = room_to_vertex[0];
	int dst = room_to_vertex[N - 1];

	vector<int> dist(vertex, -1);
	queue<int> q;
	dist[src] = 0;
	q.push(src);

	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	cout << dist[dst] << "\n";
}
