class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int x = k;
        unordered_set<int>st(nums.begin(), nums.end()); 
        while(st.count(x)){
            x += k;
        }
        return x;
    }
};