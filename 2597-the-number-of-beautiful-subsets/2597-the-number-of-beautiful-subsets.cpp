class Solution {
public:
    int result;
    int l;
    void solve(int idx, vector<int>& nums, unordered_map<int, int>& mp){
        if(idx >= nums.size()){
            result++;
            return;
        }

        //if we didn't take
        solve(idx+1, nums, mp);

        //take
        if(!mp[nums[idx] - l] && !mp[nums[idx] + l]){
            mp[nums[idx]]++;
            solve(idx+1, nums, mp);
            mp[nums[idx]]--;
        }
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        result = 0;
        l = k;
        unordered_map<int, int> mp;

        solve(0, nums, mp);
        return result - 1; // - isliye so that it would not count empty set
    }
};