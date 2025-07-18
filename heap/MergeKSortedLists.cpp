// Merge K Sorted Lists
// Given an array of k sorted linked lists, merge them into one sorted linked list.

// Optimal Approach
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> min_heap; // min heap <val, node>

        for(auto &list : lists) { // storing all 0th index elements in the priority queue with their address
            if(list != NULL) min_heap.push({list->val, list}); 
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!min_heap.empty()){
            ListNode* smallest = min_heap.top().second;
            temp->next = smallest;

            if(smallest->next != NULL) min_heap.push({smallest->next->val, smallest->next});
            
            min_heap.pop();

            temp = smallest;
        }

        ListNode* head = dummy->next;
        delete dummy;
        return head;
    }
};

/*
Approach 1: Brute Force

Concept: Collect all nodes into a single array, sort the array, then build a new list.
TC: O(N log N) - N total nodes, for sorting.
SC: O(N) - for the temporary array of N node values.

Approach 2: Optimized using Min Heap

Concept: Use a min-heap to keep track of the smallest current node from each of the k lists. 
         Repeatedly extract the minimum, add it to the result, and push its next node into the heap.
TC: O(N log k) - N total nodes, k lists. Each node pushed/popped from a heap of size k.
SC: O(k) - for the min-heap, storing up to one node from each list.
*/