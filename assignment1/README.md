# Assignment 1

---
## Ackerman function

### Definition

``` c++
A(m, n) = {
    n + 1                , if m = 0
    A(m - 1, 1)          , if n = 0
    A(m - 1, A(m, n - 1)), otherwise
}
```

### Example

Input:
```
0 1
3 1
2 0
```

Output:
```
2
13
3
```

### Algorithm

Writing down the definition of ackerman function, which is a recursion function.

I used a map to store the computed results to make my program faster.

### Bug

Command:
```sh
echo 4 2 | ./ackerman
Segment fault
```

Reason:

**Too much times of recursion and then reach the end of stack.**

---
## Powerset

### Definition

```c++
S = {a, b, c}

powerset(S) = {
    {},
    {a},
    {b},
    {c},
    {a, b},
    {a, c},
    {b, c},
    {a, b, c}
}
```

### Algorithm

We can know that if we discard the last element of all subsets of length `n`, we will get all subsets of length `n - 1`. (for all n >= 1)

So if I expand all subsets of length `n` with legal elements, I can get all subsets of length `n + 1`. (for all n >= 0)

### Example

Input:
```
k
d e
a b c
```

Output:
```
{} {k}
{} {d} {e} {d e}
{} {a} {b} {c} {a b} {a c} {b c} {a b c}
```
