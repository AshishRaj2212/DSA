class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        while(n--){
            if(nums[n] % 3 != 0) count++;
        }
        return count;
    }
};