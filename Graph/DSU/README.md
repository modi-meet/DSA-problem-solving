# Disjoint Set Union (DSU)

## DSU BASIC IDEA:
Consider every edge as a set (e.g. [2,4] = S1 = {2,4})
Now, there will multiple edges connection nodes.
If the edge contains vertices from different sets, then perform Union. (e.g. [2,4], [1,4] => S3 = (s1) *U* (S2) = {1,2,4})

## DSU DATA STRUCTRUE
How to perform union grahically,
Connect a child node to a parent node. And similarly, to connect/to perform union, we add lower ranked component(child) to higher ranked component(parent).

(aka Union Find)

- OPERATION:
1. Union - combine two sets
2. Find - tell if two nodes belongs to same set/component or not.

- TYPES OF UNION:
1. union by rank,
2. union by size.


## HOW TO DETECT CYCLE?
We actually don't need to perform union operation mathematically.
**BASIC** - Generally, DSU is used to detect cycle, So if two vertices belongs the same set; cycle detected.
**GRAPHICAL** - if the ultimate parent node are same; cycle detected.
**ARRAY** - check for child's(i) parent's(arr[i]) parent(arr[arr[i]]).... if their parents turns out to be same; cycle detected.

## PATH COMPRESSION (collapsing find)
Instead of going/relying on parent's parent series (time consuming),
We can dirently join sub-children to their Ultimate parent. Because it is their ultimate parent & we use ultimate parent to detect the cycle.
Graphically, we can directly connect sub-child to their ultimate parent.
Hence, reducing the time by providing direct look up to ultimate parent in constant time.