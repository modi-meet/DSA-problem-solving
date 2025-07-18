# What is Heap? 🗂️

**A heap is a tree-based data structure. It is a "priority" line, where the most important item is always at the front.**
-
It is a CBT (Complete Binary Tree) that satisfies the heap property:
  - for every node, the value of its children is greater than or equal to its own value(depending upon max heap or min heap)
  - where the smallest (or largest) element is always at the root of the tree.
--
### Two types:

- **Max-Heap**: The parent node is always larger than its children. The root is the largest element in the entire heap. It's great for quickly finding the maximum value.
- **Min-Heap**: The parent node is always smaller than its children. The root is the smallest element. It's perfect for quickly finding the minimum value.

## Implementation in C++

`prioprity_queue<>` is used for implementing a Heap. It is included in `#include<queue>` header file.

    - Ex. priority_queue<int> pq;

Note: `priority_queue<int>` is by default a Max-Heap. 

To Implement a Min-Heap :

    - Ex. priority_queue<int, vector<int>, greater<int>> pq;

## How to Spot a Heap Problem 🕵️‍♂️

Heaps are best for problems where you need to **repeatedly** find the `maximum` or `minimum` element from a changing data. 

### Keywords and patterns:

- "k-th smallest/largest" element:

  - Example: "Find the 5th largest number in a stream of data."

> Hint: Use a Min-Heap of size k to keep track of the k largest elements seen so far.

- "top k" or "most frequent k" elements:

    - Example: "Find the top 10 most viewed products on a website."

> Hint: Use a Min-Heap to maintain the k most frequent items.

- Merging k sorted lists:

    - Example: "Merge 5 sorted arrays into a single sorted array."

> Hint: Use a Min-Heap to efficiently pull the smallest element from across all arrays.

- Finding the median in a stream:

> Hint: This is a classic two-heap problem! Use a Max-Heap for the smaller half of numbers and a Min-Heap for the larger half.

# And, that's it! 

> Extras:

`.push()` -> copies and then pushes to pq <br>
`.emplace()` -> In-place pushes to pq