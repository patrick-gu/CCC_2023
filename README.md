# CCC_2023

Canadian Computing Competition 2023 solutions

## S1

The amount of tape required can be calculated by taking 3 times the
number of black tiles, and subtracting 2 for each pair of tiles
which share an edge.

## S2

The problem can be solved in `O(N^2)` time.

Let `a(l, r)` denote the asymmetric value going from the `l`th
mountain to the `r`th mountain. We have the base case:

`a(l, r) = 0` if `l >= r`

As well as the state transition:

`a(l, r) = abs(h[l] - h[r]) + a(l + 1, r - 1)` if `l < r`

And we can therefore calculate `a(l, r)` for all
`1 <= l <= r <= N` in `O(N^2)` time.

We then calculate, for each `1 <= i <= N`, the maximum value
over all starting points `1 <= s <= N - i` of `a(s, s + i)`.
This takes `O(N^2)` time.

## S3

We must handle the case where `R = 0`, `C = 0`, `R = N`, and `C = M`
specially.

If none of these are met, then we can construct a grid with the top
`R` rows being `'a'`, the left `C` columns being `'a'`, and remaining
slots being `b`. For instance, with `N = 4`, `M = 5`, `R = 1`, and
`C = 2`, we can make:

```
aaaaa
aabbb
aabbb
aabbb
```

## S4

First, for any pair of nodes, if there exists more than one road
directly between them, we only consider the smallest by length,
then cost.

Next, we consider adding the roads in increasing order by length
and cost. This allows us to keep distances minimal and reduce
total cost.

For each road, we determine if there already exists a path between
the nodes that is shorter in length. If there is, we add the path to
our graph and add its cost. We use Dijkstra's algorithm to find a
path, running in `O(M log N)`.

Therefore, the solution runs in `O(NM log N)` time.

## S5

I was only able to determine that, if `N` is divisible by 3,
we can take the solutions for `N / 3`, and for each solution
`s`, we obtain two solutions `s` and `N - s`, by symmetry.
With the base case of `N = 1` being `{0, 1}`, this solves the
first test case.
