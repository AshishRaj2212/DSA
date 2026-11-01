class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int minEle = *min_element(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            count += nums[i]-minEle;
        }
        return count;
    }
};