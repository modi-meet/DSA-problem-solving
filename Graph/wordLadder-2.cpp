// Word Ladder-2
// Return all the shortest transformation sequences, return empty if not possible.

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        if (!set.count(endWord)) return {};

        // {word, level}
        queue<vector<string>> q;
        q.push({beginWord});
        
        vector<vector<string>> ans;
        vector<string> toBeErased; // from set

        int level = 1; int minLevel = INT_MAX;

        while(!q.empty()){
            auto vec = q.front();
            q.pop();
            string word = vec.back();

            if(vec.size() > level){ // means; we are on new level now 
                for(auto w : toBeErased) set.erase(w);
                toBeErased.clear();

                level = vec.size();                
                if(level > minLevel) break; // further paths will be longer, not required 
            }

            if(word == endWord){
                ans.push_back(vec);
                minLevel = level;
            }

            for(int i=0; i<word.length(); i++){
                char original = word[i];

                for(char ch='a'; ch <= 'z'; ch++){
                    word[i] = ch;

                    if(set.count(word)){
                        vec.push_back(word);
                        q.push(vec);

                        toBeErased.push_back(word); // word has to erased from set after the level
                        vec.pop_back(); // not required for next word
                    }
                }

                word[i] = original;
            }
        }
        return ans;
    }
};
// TC: O(n * word.length * 26 * 1) , n - words.size(), (set O(logn) / O(1) unordered_set)
// Sc: O(n * word.length) 