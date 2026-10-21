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

    int longestStrChain(vector<string>& words) {
        n = words.size();
        sort(words.begin(), words.end(), myFunction);

        vector<int> t(n, 1);
        int maxLen = 1;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(validPredecessor(words[j], words[i])){
                    t[i] = max(t[i], t[j]+1);
                    maxLen = max(maxLen, t[i]);
                }
            }
        }
        return maxLen;
    }
};