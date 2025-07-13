# Two Pointers - Quick Guide (No Sliding Window)

The **two pointers technique** uses two indices moving across the array to solve problems **efficiently**.

> ❗ Sliding window is a subset of two-pointer technique. Find sliding window seperately here - https://github.com/modi-meet/DSA-problem-solving/tree/main/sliding-window.

---

## 🔍 When to Use Two Pointers?

| Scenario | Pointer Behavior | 
|----------|------------------|
| **Sorted Array** | One pointer at start, one at end |
| **Palindrome Check** | Start and end move toward center |
| **Merging or Comparing Arrays** | Both pointers move forward | 
| **Removing Duplicates / Partitioning** | Slow-fast or write-read pointers |

---

## Patterns to Recognize

- Array is **sorted** ➜ try start & end pointer
- Problem involves **pairing / matching elements**
- **compare characters or elements** symmetrically
- **modify the array in-place**

---

## Benefits

- Avoid nested loops when two-pointer scan suffices.
- **binary search style narrowing** (e.g., minimize/maximize problems).

---

### Tip : Use this technique when brute force involves checking all pairs — two pointers often reduce `O(n²)` to `O(n)`.

> And, that's it!
