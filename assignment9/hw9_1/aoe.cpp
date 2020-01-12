#include <iostream>
#include <vector>
#include <queue>
#include <stack>

#define MAX 0x7fffffff

using namespace std;

class Edge {
	public:
		int u; // previous vertex
		int v; // next vertex
		int w; // weight

		Edge(int _u, int _v, int _w): u(_u), v(_v), w(_w) {}
		Edge() {}
};

typedef vector<Edge> EdgeList;

class Graph {
	/* Class for store the graph. */

	private:
		EdgeList _AllEdge;
		vector<EdgeList> _AdjList;

	public:
		Graph(int edges, int vertices) {
			_AllEdge.resize(edges);

			_AdjList.resize(vertices);
			for (auto &i: _AdjList)
				i.clear();
		}

		EdgeList::const_iterator begin(int u) {
			return _AdjList[u].cbegin();
		}

		EdgeList::const_iterator end(int u) {
			return _AdjList[u].cend();
		}

		void addEdge(int i, int u, int v, int w) {
			_AdjList[u].emplace_back(u, v, w);
			_AllEdge.emplace(_AllEdge.begin() + i, u, v, w);
		}

		Edge getEdge(int i) {
			return _AllEdge[i];
		}
};

int main() {
	int n;
	while (cin >> n) {

		// Read graph
		int numVertices = 0;
		vector<vector<int> > tmp;
		for (int i = 0; i < n; i++) {
			int idx, u, v, weight;
			cin >> idx >> u >> v >> weight;
			numVertices = max(numVertices, max(u, v));
			tmp.emplace_back();
			tmp[i].push_back(idx);
			tmp[i].push_back(u);
			tmp[i].push_back(v);
			tmp[i].push_back(weight);
		}
		Graph g(n, ++numVertices);
		vector<int> beConnected(numVertices, 0);
		for (auto &i: tmp) {
			int idx = i[0], u = i[1], v = i[2], weight = i[3];
			g.addEdge(idx - 1, u, v, weight);
			++beConnected[v];
		}

		// Calculate the time of "Early Event" and "Latest Event".
		vector<int> ee(numVertices), le(numVertices, MAX);
		queue<int> eeQ, critical;
		stack<int> leS;
		for (int i = 0; i < numVertices; i++)
			if (!beConnected[i]) {
				eeQ.push(i);
				ee[i] = 0;
			}
		while (!eeQ.empty()) {
			int u = eeQ.front();
			eeQ.pop();
			for (EdgeList::const_iterator it = g.begin(u), end = g.end(u); it != end; it++) {
				ee[it->v] = max(ee[it->v], ee[u] + it->w);
				--beConnected[it->v];
				if (!beConnected[it->v])
					eeQ.push(it->v);
			}
			leS.push(u);

			// ending vertex
			if (g.begin(u) == g.end(u))
				le[u] = ee[u];
		}
		while (!leS.empty()) {
			int u = leS.top();
			leS.pop();
			for (EdgeList::const_iterator it = g.begin(u), end = g.end(u); it != end; it++) 
				le[u] = min(le[u], le[it->v] - it->w);
		}

		// (a)
		cout << "event\tee\tle\t\n";
		for (int i = 0; i < numVertices; i++)
			cout << i << '\t' << ee[i] << '\t' << le[i] << '\n';

		// (b)
		cout << "\nact.\te\tl\tslack\tcritical\n";
		for (int i = 0; i < n; i++) {
			Edge tmp = g.getEdge(i);
			int e = ee[tmp.u];
			int l = le[tmp.v] - tmp.w;
			int slack = l - e;
			bool isCritical = slack == 0;

			cout << i + 1 << '\t' << e << '\t' << l << '\t' << slack << '\t' << (isCritical?"Yes":"No") << '\n';

			if (isCritical)
				critical.push(i + 1);
		}
		cout << '\n';

		// (c)
		while (!critical.empty()) {
			cout << critical.front() << ' ';
			critical.pop();
		}
		cout << '\n' << endl;
	}
	return 0;
}
