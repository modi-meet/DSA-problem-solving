// Dota2 Senate
// Given a string senate representing each senator's party belonging. The character 'R' and 'D' represent the Radiant party and the Dire partyThe voting for this change is a round-based procedure. In each round, each senator can exercise one of the two rights:
// Ban one senator's right: A senator can make another senator lose its rights.
// Announce the victory: If this senator found the senators who still have rights to vote are all from the same party, he can announce the victory and decide on the change in the game.
// Predict which party will finally announce the victory and change the Dota2 game. The output should be "Radiant" or "Dire".

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> rad_q;
        queue<int> dir_q;

        for(int i=0; i<n; i++){
            if(senate[i] == 'R') rad_q.push(i);
            else dir_q.push(i);
        }

        while(!dir_q.empty() && !rad_q.empty()){
            if(rad_q.front() < dir_q.front()) { // Radiants got the chance first
                dir_q.pop(); // ban the party;
                rad_q.push(rad_q.front() + n);
                rad_q.pop();
            } else { // Dire got the chance
                rad_q.pop(); // ban the party;
                dir_q.push(dir_q.front() + n);
                dir_q.pop();
            }
            // rad_q.pop();
            // dir_q.pop(); 
            // either way both parties gets popped and only one of them queued back at the end.
        }
        return rad_q.empty() ? "Dire" : "Radiant";
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n) (total)

/*
Explanation:

-Each senator in order can ban one opposite party senator.

-The next round continues with remaining senators in order.

-If a senator bans someone, they survive to the next round, shifted to the back of the queue. The one who is banned is removed now.

-This continues until one party has no senators left to ban the other.

-Tracking both parties indices with queues helps simulate the rounds efficiently. 
-The one who bans another, is pushed to the back with an incremented index(+n) for the next round.

And, that's it!
*/