class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini = *min_element(nums1.begin(), nums1.end());
        if(mini % 2 == 1){ //if minimum element is odd, then we can convert all even to odd
            return true;
        }
        //even tbhi possible h if every element is even
        for(int &it : nums1){
            if(it % 2 == 1)
                return false;
        }
        return true;
    }
};