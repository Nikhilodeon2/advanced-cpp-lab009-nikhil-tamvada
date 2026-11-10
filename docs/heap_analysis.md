# Heap Analysis Laboratory

## Required data structure
Students must implement a priority queue as a max-heap using a dynamic array/vector. The heap must satisfy the max-heap property:

- every parent node is greater than or equal to its children;
- the root contains the maximum value;
- the left and right child indices follow the formulas:
  - left child index = 2 * i + 1
  - right child index = 2 * i + 2
  - parent index = (i - 1) / 2

## Required operations
Students must implement and analyze:

- `push(value)`
- `pop()`
- `top()`
- `contains(value)`
- `buildHeap(values)`
- `heapSort()`
- `heapifyUp(index)`
- `heapifyDown(index)`

## Analysis requirements
The heap is stored in a vector. Its array indices represent a complete binary
tree without allocating individual tree nodes. For an element at index `i`,
the left child is at `2 * i + 1`, the right child is at `2 * i + 2`, and the
parent is at `(i - 1) / 2` for `i > 0`. The max-heap property requires each
parent to be at least as large as its children, so the root is the maximum.

Insertion appends to the vector, then moves the value up at most one tree
height. Removing the maximum replaces the root with the last value and moves
it down at most one tree height. Since a complete binary tree has height
`O(log n)`, both operations take `O(log n)`. Reading the root takes `O(1)`.

Bottom-up construction starts at the last internal node and heapifies toward
the root. Although an individual heapify can take `O(log n)`, most nodes are
near the leaves and move only a short distance, so building a heap takes
`O(n)`. Heap sort repeatedly removes the maximum and reverses the extraction
order to return ascending values, taking `O(n log n)` time and `O(n)` space
for the returned vector. This implementation consumes the heap while sorting.

Membership checks may inspect every vector element because a heap only orders
parent-child relationships, not siblings or entire subtrees; therefore
`contains` is `O(n)`. The heap stores `n` integers in `O(n)` space.

| Operation | Time | Additional space |
|---|---:|---:|
| `push` | `O(log n)` | `O(1)` amortized |
| `pop` | `O(log n)` | `O(1)` |
| `top` | `O(1)` | `O(1)` |
| `buildHeap` | `O(n)` | `O(1)` beyond the stored vector |
| `heapSort` | `O(n log n)` | `O(n)` for the returned values |
| `contains` | `O(n)` | `O(1)` |

## Trade-offs and use cases

A heap is a good choice when an application repeatedly needs the current
minimum or maximum: it provides constant-time access to the root and
logarithmic insertion and removal. A binary search tree can also support
ordered queries and searching, but its performance depends on balance and
requires more per-node structure. A sorted vector supports logarithmic
search and constant-time access to either end, but inserting or removing an
element typically shifts `O(n)` values. A priority queue is the abstract
interface for retrieving the highest-priority item; a heap is a common
implementation of that interface, but the abstraction does not expose
arbitrary search or full sorted traversal as efficient operations.
