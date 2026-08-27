class Solution {
public:

    void solve(vector<int>& nums, vector<vector<int>>& result, vector<int>& curr, int idx){
        result.push_back(curr);
        for(int i = idx; i<nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]){
                continue;
            }
            curr.push_back(nums[i]);
            solve(nums, result, curr, i+1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;

        sort(nums.begin(), nums.end());

        solve(nums, result, curr, 0);
        return result;
    }
};