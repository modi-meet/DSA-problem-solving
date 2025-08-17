// Word Ladder
// Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());

        // {word, level}
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        set.erase(beginWord);

        while(!q.empty()){
            auto [word, level] = q.front();
            q.pop();

            if(word == endWord) return level;

            // hat
            for(int i=0; i<word.size(); i++){
                char ch1 = word[i]; // h

                for(char ch2='a'; ch2<='z'; ch2++){
                    word[i] = ch2; 
                    // aat , bat, cat, dat,... ,zat

                    if(set.count(word)) {
                        q.push({word, level+1});
                        set.erase(word);
                        // if(word == endWord) return level+1;
                    }
                }
                word[i] = ch1;
            }
        }
        return 0;
    }
};
// TC: O(n * word.length * 26 * 1) , n - words.size(), (set O(logn) / O(1) unordered_set)
// Sc: O(n)

// Use a Set - to efficiently find the generated string is present in wordList or not.
// Important - remove the found word from list, no duplicate word get pushed in queue

// Queue store the sequence in BFS manner. {word, level}