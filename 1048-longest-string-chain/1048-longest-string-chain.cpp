class Solution {
public:
    int n;
    int t[1001][1001];

    static bool myFunction(string &word1, string &word2){
        return word1.length() < word2.length();
    }

    bool validPredecessor(string &prev, string &curr){
        if(curr.length() - prev.length() != 1 || prev.length() >= curr.length()){
            return false;
        }
        int i = 0, j = 0;
        while(i<prev.length() && j<curr.length()){
            if(prev[i] == curr[j]){
                i++;
            }
            j++;
        }
        return i == prev.length();
    }
    int solve(int idx, int prev, vector<string>& words){
        if(idx >= n) return 0;

        if(prev != -1 && t[prev][idx] != -1)
            return t[prev][idx];

        int take = 0;
        if(prev == -1 || validPredecessor(words[prev], words[idx])){
            take = 1 + solve(idx+1, idx, words);
        }
        int skip = solve(idx+1, prev, words);

        if(prev != -1)
            t[prev][idx] = max(take, skip);

        return max(take, skip);
    }

    int longestStrChain(vector<string>& words) {
        memset(t, -1, sizeof(t));
        n = words.size();
        sort(words.begin(), words.end(), myFunction);

        return solve(0, -1, words);
    }
};