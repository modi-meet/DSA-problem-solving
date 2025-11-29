//  Search Suggestions System
// Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. 
// If there are more than three products with a common prefix return the three lexicographically minimums products.

class Node {
public:
    Node* links[26];
    bool flag;

    Node() { // constructor
        flag = false;

        for(int i=0; i<26; i++) links[i] = NULL;
    }

    bool contains(char ch) {
        return (links[ch- 'a'] != NULL);
    }

    void addToTrie(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }

};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                node->addToTrie(ch, new Node());
            }
            
            node = node->links[ch - 'a'];
        }

        // set end-of-word
        node->flag = true;
    }

    Node* getNode(string &word) {
        Node* node = root;

        for (char ch : word) {
            if (!node->contains(ch)) return NULL;

            node = node->links[ch - 'a'];
        }

        return node;
    }
};

void dfs(Node* node, string curr, vector<string>& temp) {
    if(temp.size() == 3) {
        // ans.push_back(temp);
        return;
    }

    if(node->flag == true) temp.push_back(curr);

    for(char c = 'a'; c <= 'z'; c++) {  // lexicographically
        if(node->contains(c)) {
            dfs(node->links[c - 'a'], curr + c, temp);
        }
    }
}

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end()); // imp
        vector<vector<string>> ans;

        Trie trie;

        // add all words to the Trie
        for(auto &word : products) trie.insert(word);

        // iterate to each character of searchWord & predict next 3 most suitable words
        string word = "";
        for(char ch : searchWord) {
            word += ch;

            vector<string> temp;
            Node* node = trie.getNode(word);

            if(node == NULL) {
                ans.push_back({});
                continue;
            }

            dfs(node, word, temp);  // get 3 words
            ans.push_back(temp);
        }

        return ans;
    }
};


// 1. Add all inventory of the words into the Tries
// 2. traverse the i-th word of searchWord
// 3. each word, find next 3 prediction of words