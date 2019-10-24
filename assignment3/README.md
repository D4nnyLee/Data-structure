# Assignment 3

## Queueing in Costco

### Description

Using the data structure queue, write a program to simulate the process of queueing in Costco.
There are customers who leave the queue after completing their payment, and newcomers who are about to join the queue.
When a newcomer recognizes a friend in the queue, they will cut the line inappropriately to meet their friend.

### Input

The first row of input consists of an integer `N` (1 ≦ `N` ≦ 26), which indicates the number of groups of friends.
Assume that everyone in the same group are friends with each other, and does not know anyone from different groups.
Each of the following `N` rows describe each group respectively, beginning with an integer `M` (1 ≦ `M` ≦ 26), which is the number of people in the group, followed by `M` capital letters (A~Z) representing `M` people respectively.
Each capital letter is separated by a space.
Every customer is represented by a distinct letter.
Then, there will be several rows of input consisted of the following operations:
- `DEQUEUE` indicates the customer at the front of the queue has completed payment and left.
- `ENQUEUE P` indicates a newcomer `P` will join the queue. If there exists a friend of `P` in the queue, `P` will cut in front of the friend. If there are multiple friends of `P` in the queue, `P` will choose the friend nearest to the front of the queue. If there are no friends of `P` in the queue, `P` will join at the end of the queue. Input stops when `EOF` is read.

### Output

In separate lines, show the customer who left after each `DEQUEUE` operation.

### Algorithm

Use link list to simulate the operation of queue.

For convenience, I use `head` to point to the queue, but `head` is not in it.

Operations:
- `P` Enter queue
    1. Search from the beginning of queue. (i.e.,  `head`)
    2. Stop if reach the end or the next person and `P` are in the same group.
    3. Insert `P` into the position we got in previous step.
- Quit queue
    1. Check if the line is empty. (exit if it is empty)
    2. Move `head` to its `next`, which means that the first person quits the queue.
    3. Output `head`'s `id`, which indicates the person who was originally in the front of queue.
