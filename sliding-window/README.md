# Sliding Window

Sliding Window is an efficient technique that is used for solving problems that involve subarrays or substrings.
This includes the "*window*" that slides over the data, which can either be of a fixed or variable size.

- It uses `two-pointers` for iteration/to define current window.
    - by moving this, all the subarrays/substrings are iterated in a *Single-pass*.
- Reduces the *time complexity* by iterating through array/string only once (avoiding nested loops).

## How to indentify? 🤔
It involves: <br>
Whenever the problem stats working on `subarray` or `substring`, sliding window technique should be considered for solving.<br>
**Keywords**: Look for terms like "subarray," "substring," "contiguous," or "longest/shortest."

### Ordinary patterns

1. Fixed-size window
    - Here the size of the window is fixed.
    - So include the next element into window and remove the first elememt, throughout the operation. (likely queue)

2. Variable-size / Dynamic window
    - Since the size of the window is not fixed, 
    - We expand `right` pointer and shrink `left` pointer based on the constrains.

3. Problems asking to use different Data-Structrues
    - Few problems ask for storing data for efficient code, like-
        - Use of **Hashmap** for storing `freq` of elements/characters
        - Use of **Set** to store unique characters in substring etc.

# And, that's it! 
> keep grinding! 
