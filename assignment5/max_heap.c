#include <stdio.h>
#include <stdlib.h>

// heap[0] stores the size of heap
int heap[1000010];

void push(int value) {
	int i;
	for (i = ++heap[0]; i > 1 && value > heap[i/2]; i /= 2) 
		heap[i] = heap[i/2];
	heap[i] = value;
}

int pop() {
	int returnValue = heap[1], lastValue = heap[heap[0]], i, maxIndex;
	for (i = 1; 2*i < heap[0]; i = maxIndex) {
		maxIndex = 2*i;
		if (2*i + 1 < heap[0] && heap[2*i + 1] > heap[maxIndex])
			++maxIndex;
		if (heap[maxIndex] <= lastValue) 
			break;
		heap[i] = heap[maxIndex];
	}
	heap[i] = lastValue;
	return returnValue;
}

int main() {
	int T, m, n, x, ans;
	while (scanf("%d", &T) == 1) {
		while (T-- && scanf("%d%d", &m, &n) == 2) {
			heap[0] = ans = 0;
			while (m--) {
				scanf("%d", &x);
				push(x);
			}
			while (n--) {
				x = pop();
				ans += x;
				push(x - 1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
