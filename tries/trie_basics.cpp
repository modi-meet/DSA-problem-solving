// Implement Trie (Prefix Tree)

// A trie or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. 
// There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:
// - Trie() Initializes the trie object.
// - void insert(String word) Inserts the string word into the trie.
// - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

class Node {
public:
    Node* links[26];
    bool flag;
    
    Node() {
        flag = false;
        
        for(int i=0; i<26; i++) links[i] = NULL;
    }
    
    void addToTrie(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }
    
    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
    }
};

class Trie {
  public:
    Node* root;

    Trie() {
        root = new Node();
        
    }

    void insert(string &word) {
        // insert word into Trie
        Node* node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                node->addToTrie(ch, new Node());
            }
            
            // move the node
            node = node->links[ch - 'a'];
        }
        
        // set the last node
        node->flag = true;
    }

    bool search(string &word) {
        Node* node = root;
        
        for(char ch : word) {
            if(!node->contains(ch)) return 0;
            
            node = node->links[ch-'a'];
        }
        
        return node->flag;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
         Node* node = root;
        
        for(char ch : word) {
            if(!node->contains(ch)) return 0;
            
            node = node->links[ch-'a'];
        }
        
        return true;
    }
};
// Time Complexity : O(N * Len)
