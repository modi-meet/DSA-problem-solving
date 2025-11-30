// Maximum XOR With an Element From Array
// Given an array nums consisting of non-negative integers. Also given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. 
// In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.
// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.

class Node {
public:
    Node* links[2];

    Node() {
        links[0] = links[1] = NULL;
    }

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
            int bit = (num >> i) & 1;
            
            if(!node->contains(bit)) {
                node->addToTrie(bit, new Node());
            }

            node = node->links[bit];
        }
    }

    int findMaxXOR(int num) {
        Node* node = root;
        int maxNum = 0;

        for(int i=31; i>=0; i--) {
            int bit = (num >> i) & 1;
            
            if(node->contains(1-bit)) {
                maxNum = maxNum | (1<<i);
                node = node->links[1-bit];
            } else {
                node = node->links[bit];
            }
        }

        return maxNum;
    }
};


class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int q = queries.size();
        int n = nums.size();

       vector<tuple<int, int, int>> oQ; // offlineQry:  mi, xi, queryIdx

        for(int i=0; i<q; i++) {
            oQ.push_back({queries[i][1], queries[i][0], i});
        }

        sort(oQ.begin(), oQ.end());


        vector<int> ans(q, 0);

        Trie trie;

        int idx = 0;
        for(int i=0; i<q; i++) {
            int mi = get<0>(oQ[i]); 
            int xi = get<1>(oQ[i]); 
            int qryIdx = get<2>(oQ[i]); 
            
            while(idx < n && nums[idx] <= mi){
                trie.insert(nums[idx]);

                idx++;
            }

            if(idx == 0) ans[qryIdx] = -1;
            else ans[qryIdx] = trie.findMaxXOR(xi);
        }

        return ans;
    }   
};
// Time Complexity: O( Q*32 + N*32 )


// Offline query    