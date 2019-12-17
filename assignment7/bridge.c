#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) a<b?a:b

typedef struct node {
	int value;
	struct node *next;
} Node;

void push(Node **list, int value) {
	Node *tmp = malloc(sizeof(Node));
	tmp->value = value;
	tmp->next = *list;
	*list = tmp;
}

void dfs(Node **graph, int parent, int u, int *dfn, int *low) {
	int idx = low[u] = dfn[u];
	for (Node *v = graph[u]; v; v = v->next) {
		if (v->value == parent)
			continue;
		if (dfn[v->value] == -1) {
			dfn[v->value] = ++idx;
			dfs(graph, u, v->value, dfn, low);
			low[u] = min(low[u], low[v->value]);
		}
		else // back edge
			low[u] = min(low[u], dfn[v->value]);
	}
	if (low[u] == dfn[u] && parent != -1)
		printf("%d %d\n", parent, u);
}

int main() {
	Node **adjacencyList;
	int n, e, *dfn, *low;
	while (scanf("%d%d", &n, &e) == 2) {
		// allocate memory
		adjacencyList = calloc(n, sizeof(*adjacencyList));
		dfn = malloc(n*sizeof(int));
		low = malloc(n*sizeof(int));

		// solve problem
		// 1. initialize
		for (int i = 0; i < n; i++) 
			dfn[i] = low[i] = -1;
		
		// 2. read graph
		for (int i = 0; i < e; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			push(&adjacencyList[u], v);
			push(&adjacencyList[v], u);
		}
		
		// 3. DFS
		int root = 4;
		dfn[root] = 0;
		dfs(adjacencyList, -1, root, dfn, low);
		
		// free memory
		for (int i = 0; i < n; i++) {
			while (adjacencyList[i]) {
				Node *tmp = adjacencyList[i];
				adjacencyList[i] = adjacencyList[i]->next;
				free(tmp);
			}
		}
		free(adjacencyList);
		free(dfn);
		free(low);
	}
	return 0;
}
