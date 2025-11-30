// Maximum XOR of Two Numbers in an Array
// Given an integer array nums, return the maximum result of nums[i] XOR nums[j].

class Node {
public:
    Node* links[2]; // 0 or 1

    bool contains(int bit) {
        return (links[bit] != NULL);
    }

    void addToTrie(int bit, Node* newNode) {
        links[bit] = newNode;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node(); 
    }

    void insert(int num) {
        Node* node = root;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i)&1; // i-th bit in a 32-bit number

            if(!node->contains(bit)) {
                node->addToTrie(bit, new Node());
            }

            node = node->links[bit];
        }

        // end of the number
    }

    int findMaxXOR(int num) {
        Node* node = root;
        int maxNum = 0;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i)&1;

            // find the reverse bit exist or not

            if(!node->contains(1 - bit)) { // find opposite bit
                node = node->links[bit];
            }
            else {
                maxNum = maxNum | (1 << i); // set the i-th bit
                node = node->links[1-bit];
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;

        for(auto &x : nums) {
            trie.insert(x);
        }

        int ans = 0;

        for(auto &n : nums) {
            ans = max(ans, trie.findMaxXOR(n));
        }

        return ans;
    }
};
// Time Complexity: O(N * 32) + O(N * 32)

// add all numbers into the Trie
// For each number `nums[i]` find the opposite bits in the trie (that will give the maximum XOR possible for nums[i])   - Think about it!

