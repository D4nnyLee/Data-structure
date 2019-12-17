#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Edge {
	int u, v, w;
	Edge(int u, int v, int w):u(u), v(v), w(w) {}
};

bool operator<(const Edge &a, const Edge &b) {
	return a.w > b.w;
}

int main() {
#ifdef DEBUG
	freopen("./prob1.txt", "r", stdin);
#endif
	int n, m;
	while (cin >> n >> m) {
		// initialize
		vector<int> pred(n, -1), dist(n, -1);
		vector<vector<Edge> > edges(n);
		priority_queue<Edge> heap;

		// read graph
		for (int i = 0; i < m; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			edges[u].emplace_back(u, v, w);
		}

		// iterate all edges
		dist[0] = 0;
		for (Edge &e: edges[0])
			heap.push(e);
		while (!heap.empty()) {
			Edge tmp = heap.top();
			heap.pop();
			int u = tmp.u, v = tmp.v, w = tmp.w;
			if (dist[v] == -1) {
				pred[v] = u;
				dist[v] = dist[u] + w;
				for (Edge &e: edges[v])
					heap.push(e);
			}
		}

		// output answer
		for (int i = 1; i < n; i++) {
			if (pred[i] == -1) {
				cout << "Impossible\n";
				continue;
			}
			int tmp = i;
			stack<int> s;
			for (int tmp = i; tmp; tmp = pred[tmp])
				s.push(tmp);
			cout << '0';
			while (!s.empty()) {
				cout << ',' << s.top();
				s.pop();
			}
			cout << ' ' << dist[i] << '\n';
		}
		cout << '\n';
	}
	return 0;
}
