# Data Structure Assignment 8

F74071158
資訊111
李韋杰

## Single Source Shortest Paths

Use the greedy strategy that if the distance of vertex can be updated, it is the shortest path.

And the vertex won't be updated another time.

Then we can simply iterate every edge and find the distance of all vertex.

`pred[v]` records the previous vertex on the path from root to `v`, so we can use this to find every path.

## All Pair Shortest Paths

Use the same method as above to find distance.

When using the same method as previous problem to find path, we should reverse the result we get.

So I change `pred` to `next` to help me record the path.

Define `next[u][v]` as the next vertex from `u` to `v`.

if `u -> v` can be updated to `u -> k -> v`, `next[u][v]` would be `next[u][k]`.

With `next`, I don't need another stack to reverse my result.
