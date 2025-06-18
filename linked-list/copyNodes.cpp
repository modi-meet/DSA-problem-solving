/** Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*//* PROBLEM STATEMENT : 
// Given a Unique LL, 
Each node contains an additional random pointer, which could point to any node in the list, or null.
The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node.
    - Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
    - None of the pointers in the new list should point to nodes in the original list.
*/ 
// Approach 1 - Using Hashmap
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        unordered_map<Node*, Node*> mp;
        // map stores - head nodes : duplicate nodes
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            mp[temp] = newNode;
            temp = temp->next;
        }

        temp = head;       
        while(temp){
            Node* duplicate = mp[temp];
            duplicate->next = mp[temp->next];
            duplicate->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};
// Time complexity : O(2*N), Space Complexity : O(N) + O(N) (map + duplicate nodes)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        // insert duplicate nodes in between
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;

            temp = temp->next->next;
        }
        // connect random pointers of duplicate nodes
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next; //*
            temp = temp->next->next; // move by two
        }
        // separating head nodes and duplicate nodes apart
        temp = head;    
        Node* newHead = head->next;
        Node* duplicate = newHead;
        while(temp){
            temp->next = temp->next->next;
            if(duplicate->next) duplicate->next = duplicate->next->next;

            temp = temp->next;          
            duplicate = duplicate->next;
        }

        return newHead;
    }
};
// Time complexity : O(N), Space Complexity : O(1) + O(N) (duplicate nodes)

/* Explanation
Approach 1 : use hashmap to store duplicate nodes
Step 1 - create duplicate nodes for every node in LL; store them in the map    
Step 2 - connect next & random pointers of duplicate nodes 

Appraoch 2 : Space optimization
Logic - we used map to store duplicate nodes, because in order to form connections later on, we require their node address
      - If the address was not stored previously, then it is not possible to access those duplicate nodes

Instead of storing how about creating a new node and insert it b/w the existing two head nodes.
After all the nodes are created and connected; break their connection with head nodes and vice-versa.
Step 1 - Add a duplicate node of every node in between existing two head node.
Step 2 - form bridge connection, connect head node->next pointer to newNode and newNode->next pointer to next head node
Step 3 - repeat for all node
Step 4 - Break head nodes connection with duplicate ones while connecting all duplicate nodes with each other.

And, that's it!
*/