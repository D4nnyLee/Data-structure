#include <stdio.h>
#include <stdlib.h>

#define MAX (1<<31)-1

int main() {
#ifdef DEBUG
	freopen("./prob2.txt", "r", stdin);
#endif
	int n, m;
	while (scanf("%d%d", &n, &m) == 2) {
		int **dist, **next;
		dist = (int**)malloc(n*sizeof(*dist));
		next = (int**)malloc(n*sizeof(*next));
		for (int u = 0; u < n; u++) {
			dist[u] = (int*)malloc(n*sizeof(**dist));
			next[u] = (int*)malloc(n*sizeof(**next));
			for (int v = 0; v < n; v++) {
				dist[u][v] = MAX;
				next[u][v] = -1;
			}
			dist[u][u] = 0;
		}
		for (int i = 0; i < m; i++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			dist[u][v] = w;
			next[u][v] = v;
		}
		for (int k = 0; k < n; k++) {
			for (int u = 0; u < n; u++) {
				for (int v = 0; v < n; v++) {
					int newLen = dist[u][k] + dist[k][v];
					if (newLen < dist[u][v]) {
						dist[u][v] = newLen;
						next[u][v] = next[u][k];
					}
				}

			}
		}
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (next[u][v] == -1) 
					continue;
				printf("%d", u);
				int t = u;
				do {
					t = next[t][v];
					printf(",%d", t);
				}
				while (t != v);
				printf(" %d\n", dist[u][v]);
			}
		}
		putchar(10);
	}
	return 0;
}
