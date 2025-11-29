// Count of distinct substrings

// Given a string of length N of lowercase alphabet characters. 
// The task is to complete the function countDistinctSubstring(), which returns the count of total number of distinct substrings of this string.

class Node {
public:
    Node* links[26];
    bool flag;
    
    Node() {
        flag = false;
        
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }
    
    bool contains(char ch) {
        return (links[ch - 'a']!=NULL);
    }
    
    void addToTrie(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }
    
    ~Node() {
        for (int i=0; i<26; ++i) {
            delete links[i];
    }}
};


int countDistinctSubstring(string s) {
    int n = s.length();
    int count = 0;
    
    Node* root = new Node();
    
    for(int i=0; i<n; i++) {
        Node* node = root;
        
        for(int j = i; j<n; j++) {
            char ch = s[j];
            
            if(!node->contains(ch)) {
                count++;
                
                node->addToTrie(ch, new Node());
            }
            
            node = node->links[ch - 'a'];
        }
        
        // node->flag = true;
        
    }
    
    
    return count+1;
}
// Time Complexity: O(n^2)


// Tip:
// If you face MLE issue: Add a function to recursively free memory.

/*
    void deleteTrie(Node* node) {
        for(int i = 0; i < 26; i++) {
            if(node->links[i]) deleteTrie(node->links[i]);
        }
        delete node;
    }
*/

// call `deleteTrie(root);` before returning count+1;