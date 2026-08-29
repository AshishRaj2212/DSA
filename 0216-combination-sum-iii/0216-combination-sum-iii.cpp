class Solution {
public:
    void solve(vector<vector<int>>& result, vector<int>& curr, int k, int n, int idx, int sumTillNow){
        if(sumTillNow > n) return;
        if(k == 0){
            if(sumTillNow == n){
                result.push_back(curr);
            }
            return;
        }
        if(idx == 10) return;

        sumTillNow += idx;
        curr.push_back(idx);
        k -= 1;
        solve(result, curr, k, n, idx+1, sumTillNow);
        k += 1;
        sumTillNow -= idx;
        curr.pop_back();

        solve(result, curr, k, n, idx+1, sumTillNow);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
          vector<vector<int>> result;
          vector<int> curr;
          solve(result, curr, k, n , 1, 0);
          return result;
    }
};