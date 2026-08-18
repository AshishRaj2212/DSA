class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==n){
            int e = *max_element(nums.begin(),nums.end());
            return e ;
        }else if(k==1){
            unordered_map<int , int > mp ;
            for(int x : nums){
                mp[x]++;
            }

            int a = -1;

            for(auto &it : mp){
                if(it.second==1){
                    a=max(a,it.first);
                }
            }

            return a;
        }else{
            int a = nums[0];
            int b = nums[n-1];
            int c1=0;
            int c2= 0 ;

            for(int x : nums){
                if(x==a){
                    c1++;
                }
                
                if(x==b){
                    c2++;
                }
            }

            if(c1>1 && c2>1){
                return -1 ;
            }

            if(c1==1 && c2==1){
                int d = max(a,b);
                return d;
            }

            if(c1>1){
                return b;
            }else{
                return a ;
            }
     
        }
    }
};