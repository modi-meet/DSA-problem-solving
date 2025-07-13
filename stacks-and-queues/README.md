# 🧱 Stacks & Queues

Stacks and Queues are linear data structures used for **order-based** operations.

Imagine Stack as-
- Pile of books put one on the another, you can only access the first book at a time.
- following the **Last In, First Out (LIFO)** rule.


And Queue as-
- People lining up at a ticket counter—new arrivals join the end of the line, and the person in front gets served first.
- It follows the **First In, First Out (FIFO)** principle.


---

| Pattern / Keyword | Structure | Tip to Recognize |
|------------------|-----------|------------------|
| **Undo / Backtracking / Recursion** | Stack | LIFO order (Last In First Out) |
| **Sliding Window** | Queue / Deque | FIFO, with monotonic queue |
| **Balanced Parentheses / Expression Evaluation** | Stack | Push on open, pop when close |
| **Next Greater / Smaller Element** | Stack | Monotonic stack |
| **Task Scheduling / Waiting Line / BFS** | Queue | FIFO behavior required |

---

## 🔄 Stack Types

- **Array / LinkedList Based Stack**
- **Monotonic Stack** (Increasing or Decreasing)

## 🔁 Queue Types

- **Simple Queue** (FIFO)
- **Deque (Double-ended Queue)**
- **Priority Queue / Min-Heap / Max-Heap**
- **Circular Queue**

---

## 🧠 How to identify the pattern?

- Think **stack** when:
  - You need to reverse something.
  - Matching pairs like `()` parenthesis or HTML tags.
  - Problems that involve **"wait for the next..."** like Next Greater Element.

- Think **queue** when:
  - Processing elements in **arrival order**.
  - BFS traversal in trees or graphs.
  - Fixed window problems (often solved using deque).

- Watch for **invariants**(maintaining a specific order) in monotonic stack/queue problems.

- Use **deque** for flexible two-sided access — e.g., **sliding window maximum**.
  
---

> And, that's it! 💪
