#include <stdio.h>
#include <string.h>

int tree[100010];

int min(int a, int b) {
	return a<b?a:b;
}

int collapsingFind(int i, int *cnt) {
	if (tree[i] < 0)
		return i;
	*cnt += 2;
	return tree[i] = collapsingFind(tree[i], cnt);
}

void heightUnion(int i, int j) {
	int totalHeight = min(tree[i], tree[j]);
	if (tree[i] > tree[j]) {
		tree[i] = j;
		tree[j] = totalHeight;
	}
	else if (tree[i] < tree[j]) {
		tree[j] = i;
		tree[i] = totalHeight;
	}
	else {
		tree[j] = i;
		tree[i] = totalHeight - 1;
	}
}

int main() {
	int t, n;
	char operation[8];
	while (scanf("%d", &t) == 1) {
		while (t-- && scanf("%d", &n) == 1) {
			while (n--) {
				int idx, val;
				scanf("%d%d", &idx, &val);
				tree[idx] = val;
			}
		}
		while (scanf("%s", operation) == 1 && strcmp(operation, "STOP")) {
			if (!strcmp(operation, "UNION")) {
				int i, j;
				scanf("%d%d", &i, &j);
				heightUnion(i, j);
			}
			else {
				int p, cnt = -1;
				scanf("%d", &p);
				collapsingFind(p, &cnt);
				printf("%d\n", cnt);
			}
		}
	}
	return 0;
}
