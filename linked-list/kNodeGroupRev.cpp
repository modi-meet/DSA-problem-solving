// Given the head of a linked list, reverse the nodes of the list k at a time, 
// Return the modified list.
//***********BRUTE FORCE*************** 
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL;
        vector<int> arr;
        ListNode* temp = head;
        // convert LL to array
        while(temp){ 
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        int n = arr.size();
        ListNode* newHead = new ListNode(-1);
        temp = newHead;
        for(int i=0; i<=n-k; i+=k){ // reverse in k chunks
            reverse(arr.begin()+i, arr.begin()+i+k);
        }
        // A new List from the array
        for(int i=0; i<n; i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }

        return newHead->next;
    }
}; 
// TIME COMPLEXITY : O(N), Space Complexity : O(N)+O(N) (array + dummy nodes)

// ***********Optimal Approach***************
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL) return NULL; 
        ListNode* temp = head; // for traversal
        ListNode* prevNode = NULL; // to connect reversed LL with previous node 

        while(temp) {
            ListNode* kThNode = getKthNode(temp, k);
            if(kThNode == NULL) { // reversal not required; only connect the original nodes with previous reversed subLL's head  
                if(prevNode) prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kThNode->next;
            kThNode->next = NULL;
            reverseLL(temp);
            if(temp == head) // first subLL
                head = kThNode; //  update new head
            else
                prevNode->next = kThNode;

            prevNode = temp;
            temp = nextNode;
        }
        return head;

    }
private: 
    ListNode* getKthNode(ListNode* temp, int k){
        int i=1;
        while(temp && i<k){
            temp = temp->next;
            i++;
        }
        return temp;
    }

    ListNode* reverseLL(ListNode* temp){
        ListNode* prev = NULL;
        
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }
}; // TIME COMPLEXITY : O(N), Space Complexity : O(1)

/*
EXPLANATION

Before reversing the sub LinkedList,
- previous node should be prevented; to be connected with kth Node after reversal
- next node of the kth Node should be prevented; for next traversal

Important Connection : 
- Changing of the original head after first subLL reversal to Kth node
- connect kth node to prevNode->next each time.
- Point the kThnode's next pointer to NULL; seperate the sub LL
- if remaining node's are less than k, connect prevNode->next to temp; original LL

Steps-
1. get kth node
2. prevent kth node's next pointer
3. seperate sub LL
4. reverse the seaprated LL
5. connect prevNode's next pointer

And, that's it!
*/
