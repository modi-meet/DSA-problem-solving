// Complete String
// A string is called a complete string if every prefix of this string is also present in the array ‘A’. Ninja is challenged to find the longest complete string in the array ‘A’.If there are multiple strings with the same length, 
// return the lexicographically smallest one and if no string exists, return "None".

#include <bits/stdc++.h> 
using namespace std;

class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        flag = false;

        for(int i=0; i<26; i++) links[i] = NULL;
    }

    bool contains(char ch) {
        return links[ch - 'a'] != NULL;
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

    void insertToTrie(const string& word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->contains(ch)) {
                node->addToTrie(ch, new Node());
            }

            node = node->links[ch - 'a'];
        }

        // set end of the word
        node->flag = true;
    }

    bool checkPrefExist(string &word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->contains(ch)) return false;

            node = node->links[ch - 'a'];

            if(node->flag == false) return false;
        }

        return true;
    }
};



string completeString(int n, vector<string> &a){
    Trie trie; 

    // Add all words to the trie
    for(auto& word : a) {
        trie.insertToTrie(word);
    }

    // check all prefix exist for which word
    string ans = "";
    for(auto &word : a) {
        if(trie.checkPrefExist(word)) {
            if(word.length() > ans.length()) ans = word;
            else if(word.length() == ans.length() && word < ans) ans = word;
        }
    }


    return ((ans != "") ? ans : "None");
}


int main() {
    vector<string> a = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    cout << completeString(a.size(), a) << endl;   // Output: ninja
    return 0;
}

// Time Complexity: O(N)*O(Len)