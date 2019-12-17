#include <stdio.h>
#include <string.h>

int idx(char c) {
	return c - 'A';
}

int main(int argc, char const *argv[]) {
	#ifdef DEBUG
	freopen("QueueingInput.txt", "r", stdin);
	#endif
	int group[26];
	char queue[26], operation[8];
	int n, length = 0;
	scanf("%d", &n);
	memset(group, 0, 26*sizeof(int));
	for (int i = 1; i <= n; i++) {
		int m;
		scanf("%d", &m);
		while (m-- && getchar()) {
			char c = getchar();
			group[idx(c)] = i;
		}
	}
	while (scanf("%s", operation) == 1) {
        if (!strcmp(operation, "ENQUEUE") && getchar()) {
            char person = getchar();
            if (!group[idx(person)]) {
                queue[length++] = person;
                continue;
            }
            int i = 0;
			while (i < length && (!group[idx(queue[i])] || group[idx(queue[i])] != group[idx(person)])) ++i;
            if (i == length)
                queue[length++] = person;
            else {
                memmove(queue + i + 1, queue + i, length++ - i);
                queue[i] = person;
            }
        }
        else {
            printf("%c\n", queue[0]);
            memmove(queue, queue + 1, length-- - 1);
        }
	}
	return 0;
}
