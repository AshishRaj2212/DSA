class Solution {
public:
    int n;
    long long t[100001][2];
    long long solve(int idx, vector<int>& nums, bool isEven){
        if(idx >= n)
            return 0;

        if(t[idx][isEven] != -1)
            return t[idx][isEven];

        long long skip = solve(idx + 1, nums, isEven);

        int val = nums[idx];
        if(isEven == false){
            val = -val;
        }
        long long take = solve(idx+1, nums, !isEven) + val;

        return t[idx][isEven] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        
        return solve(0, nums, true);
    }
};