class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n = arr2.size();
        int count = 0;
        
        for(int i = 0; i<arr1.size(); i++){
            int j = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - begin(arr2);

            if(j == 0){ // sare hi elements gretaer or equal than h arr1[i] se
                count += (arr2[0] - arr1[i]) > d;
            }
            else if(j >= n){ // sare hi elements smaller than h arr1[i] se
                count += (arr1[i] - arr2[n-1]) > d;
            }
            else{
                count += (arr2[j] - arr1[i] > d) && (arr1[i] - arr2[j-1] > d);
            }
        }
        return count;
    }
};