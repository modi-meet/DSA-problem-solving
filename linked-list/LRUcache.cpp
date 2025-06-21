class LRUCache {
public:
    class Node {
    public:
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){ // class constructor
            key = k;
            val = v;
            prev = next = NULL;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    void addNode(Node* newNode){ // add node to the front of the Doubly LL
        Node* oldNext = head->next;

        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;    
        nextNode->prev = prevNode;
    }

    unordered_map<int, Node*> mp; // [(key) : (Node address)]
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail; 
        tail->prev = head;
    }
    
    int get(int key) {
        if(!mp.count(key)) return -1;

        Node* ansNode = mp[key];
        // first delete, then insert to make it recenty used node
        delNode(ansNode);
        addNode(ansNode);

        return ansNode->val;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){   // if already exist
            Node* oldNode = mp[key];
            delNode(oldNode);
            mp.erase(key);
        }

        if(mp.size() == limit){  // cache limit reached
            //del LRU data  
            Node* LRUnode = tail->prev;
            mp.erase(LRUnode->key);
            delNode(LRUnode);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;        
    }
};
// TIME COMPLEXITY ANALYSIS:

/*
LRUCache constructor- O(1)
get function - O(1)
put function - O(1)
addNode function - O(1)
delNode function - O(1)
*/ 

//Space Complexity : O(N) (map)

