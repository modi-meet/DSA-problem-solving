# 🔗 Linked List

As the name suggests, it is a List whose elements are linked with other.

Imagine an array with `n` elements whose every element is connected/linked with its next adjacent element, and that is called as 'Linked list'.
- Here the elements are called nodes, which contains data about that node.
- Each node has `next` pointer, connected to the next node
- Last node of the LL is pointed to `NULL` address, incating end of the LL.

---

#### Linked list nodes cannot be accessed by index value, unlike Arrays. (memory allocated for nodes may not be contiguous)

- So, every linked list has one and only one `head` that represents the first node of the LL.
- Further nodes are connected by `next` pointer.
- Sometimes, `tail` of Linked list may be given; address of the last node of LL.

---
## Types of Linked Lists

1. **Singly Linked List**
   - Each node has one pointer to the next node.
   - Traversal: One direction only (head → tail)

2. **Doubly Linked List**
   - Each node has two pointers: `prev` and `next`.
   - Traversal: Forward and backward

3. **Circular Linked List**
   - Last node points back to the head
   - Can be singly or doubly circular

---
> And, that's it!
