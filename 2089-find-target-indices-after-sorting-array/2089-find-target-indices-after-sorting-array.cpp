class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int count = 0; //it'll count numbers less than target

        for(auto& it : nums){
            if(it < target){
                count++;
            }
        }

        vector<int> result;
        for(int i = 0; i<n; i++){
            if(nums[i] == target){
                result.push_back(count);
                count++;
            }
        }
        return result;
    }
};