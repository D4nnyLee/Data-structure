# Assignment 5

F74071158
資訊 111
李韋杰

## Bipartite graph

### Algorithm

Iterate all vertices.

If find a vertices that haven't been put into any group, take it as root and traverse all the other vertices which have at least one path between them.

While traversing, put the vertices into groups according to the rule mentioned in description.

### Complexity

Each tree $t_i$ in the forest has $n_i$ nodes and $e_i$ edges.

Traversing each $t_i$ will have the time complexity $O(n_i + e_i)$

$\therefore$ time complexity = $O \left( \sum(n_i + e_i) \right) = O(n + e)$

## Bridge

### Algorithm

Calculate the `dfn` and `low` for every vertex.

If the `dfn` and `low` of a vertex `v` are equal, `v` is the toppest node of an circle.

Denote the parent of `v` as `u`.

Edge $(u, v)$ is the answer we want.

### Complexity

I use DFS to traverse the graph so the complexity should be $O(n + e)$.
