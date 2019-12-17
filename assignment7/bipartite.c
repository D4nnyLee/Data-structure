#include <stdio.h>
#include <stdlib.h>

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

int pop(Node **list) {
	Node *tmp = *list;
	int ret = tmp->value;
	*list = (*list)->next;
	free(tmp);
	return ret;
}

int main() {
	Node **adjacencyList;
	Node *stack;
	int n, e, *set, isBipartite;
	while (scanf("%d%d", &n, &e) == 2) {
		// allocate memory
		adjacencyList = calloc(n, sizeof(*adjacencyList));
		set = calloc(n, sizeof(int));
		stack = NULL;

		// solve problem
		// 1. read graph
		for (int i = 0; i < e; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			push(&adjacencyList[u], v);
			push(&adjacencyList[v], u);
		}

		// 2. DFS
		isBipartite = 1;

		for (int i = 0; i < n && isBipartite; i++) {
			if (set[i])
				continue;
			set[i] = 1;
			push(&stack, i);
			while (stack && isBipartite) {
				int u = pop(&stack);
				for (Node *v = adjacencyList[u]; v; v = v->next) {
					if (set[v->value] == 0) {
						set[v->value] = set[u]==1?2:1;
						push(&stack, v->value);
					}
					if (set[v->value] == set[u]) {
						isBipartite = 0;
						break;
					}
				}
			}
		}

		// 3. print answer
		if (isBipartite) {
			puts("true");
			for (int i = 0; i < n; i++) 
				if (set[i] == 1)
					printf("%d ", i);
			putchar(10);
			for (int i = 0; i < n; i++) 
				if (set[i] == 2)
					printf("%d ", i);
			putchar(10);
		}
		else 
			puts("false");

		// free memory
		free(set);
		for (int i = 0; i < n; i++) {
			while (adjacencyList[i]) {
				Node *tmp = adjacencyList[i];
				adjacencyList[i] = tmp->next;
				free(tmp);
			}
		}
		free(adjacencyList);
		while (stack) {
			Node *tmp = stack;
			stack = stack->next;
			free(tmp);
		}
	}
	return 0;
}
