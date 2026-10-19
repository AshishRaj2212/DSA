class Solution {
public:
    int n;
    int t[2501][2501];
    int solve(int idx, int prev, vector<int>& nums){
        if(idx >= n) 
            return 0;

        if(prev != -1 && t[idx][prev] != -1)
            return t[idx][prev];

        int take = 0;
        if(prev == -1 || nums[idx] > nums[prev]){
            take = 1 + solve(idx+1, idx, nums);
        }
        
        int skip = solve(idx+1, prev, nums);

        if(prev != -1){
            t[idx][prev] = max(take, skip);
        }
        return max(take, skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));

        return solve(0, -1, nums);
    }
};