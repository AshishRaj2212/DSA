class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> mp;

        long long ans = INT_MIN;

        for(int i = 0; i<n; i++){
            auto it = mp.upper_bound(nums[i] - i); //directly find that element which is greater than nums[i]-i

            long long currAns = nums[i];

            if(it != mp.begin()){
                it--;
                currAns += (*it).second;
            }
            mp[nums[i] - i] = max(mp[nums[i]-i], currAns);

            it = mp.upper_bound(nums[i] - i);

            while(it != mp.end() && (*it).second <= currAns){
                mp.erase(it++);
            }
            ans = max(ans, currAns);
        }
        return ans;
    }
};