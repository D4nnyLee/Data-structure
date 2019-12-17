# Assignment 5

F74071158
資訊 111
李韋杰

---

## Monk And Champions League

### Algorithm

Use `max heap` to get the maximum value of each operation.

In each operation, I will pop out the maximum value and add it to the answer.

After the addition, I will minus it by one and push it back to the heap to update the values in heap.

---

## Height Union

### Algorithm

I write my `collapsingFind` as a recursive function because I don't want to use two for loop to find root and update all passed nodes.

### Comparison

I think `heightUnion` is better in conjunction with `collapsingFind`.

Because it is difficult to update the tree height after `collapsingFind` when doing `heightUnion` and there is no need to update tree weight when performing `weightUnion`.
