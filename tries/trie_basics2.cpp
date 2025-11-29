// Implement Trie 2

// Implement the Trie class:
// - Trie() Initializes the trie object.
// - void insert(String word) Inserts the string word into the trie.
// - int countWordsEqualTo(String word) Returns the number of instances of the string word in the trie.
// - int countWordsStartingWith(String prefix) Returns the number of strings in the trie that have the string prefix as a prefix.
// - void erase(String word) Erases the string word from the trie.

class Node {
public:
    Node* links[26];

    int prefixCnt;
    int wordEndCnt;

    Node(){
        prefixCnt = 0, wordEndCnt = 0;

        for(int i=0; i<26; i++) links[i] = NULL;
    }
    
    bool contains(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void addToTrie(char ch, Node* newNode) {
        links[ch - 'a'] = newNode;
    }

    void increasePref() {
        prefixCnt++;
    }
    void incWordEndCnt() {
        wordEndCnt++;
    }
    void decreasePrefix() {
        prefixCnt--;
    }
    
};

class Trie{
    private:
        Node* root;

    public:

    Trie(){
        root = new Node();
    }

    void insert(const string &word){
        Node *node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                node->addToTrie(ch, new Node());
            }

            node = node->links[ch - 'a'];
            node->increasePref();
        }

        node->incWordEndCnt();
    }

    int countWordsEqualTo(const string &word){
        Node *node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                return 0;
            }

            node = node->links[ch - 'a'];
        }

        return node->wordEndCnt;
    }

    int countWordsStartingWith(const string &word){
        Node *node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                return 0;
            }

            node = node->links[ch - 'a'];
        }

        return node->prefixCnt;
    }

    void erase(const string &word){
        Node *node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                return;
            }

            node->decreasePrefix();
            node = node->links[ch - 'a'];
        }

        node->wordEndCnt--;
    }
};
// Time Complexity: O(N)