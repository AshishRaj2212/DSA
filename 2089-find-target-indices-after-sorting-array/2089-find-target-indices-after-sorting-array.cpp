class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        int count1 = 0; //it'll count numbers less than target
        int count2 = 0; //it'll count numbers equal to target

        for(auto& it : nums){
            if(it < target){
                count1++;
            }
            else if(it == target){
                count2++;
            }
        }

        vector<int> result;
        for(int i = count1; i < count1 + count2; i++){
                result.push_back(i);
        }
        return result;
    }
};