class Solution {
public:
    int N, M, K;
    int MOD = 1e9+7;
    int t[51][51][101];

    int solve(int idx, int searchCount, int maxVal){
        if(idx == N){
            if(searchCount == K){
                return 1;
            }
            else return 0;
        }

        if(t[idx][searchCount][maxVal] != -1)
            return t[idx][searchCount][maxVal];

        int result = 0;
        for(int i = 1; i <= M; i++){
            if(i > maxVal){
                result = (result + solve(idx+1, searchCount+1, i)) % MOD;
            }
            else{
                result = (result + solve(idx+1, searchCount, maxVal)) % MOD;
            }
        }
        return t[idx][searchCount][maxVal] = result % MOD;
    }

    int numOfArrays(int n, int m, int k) {
        N = n;
        M = m;
        K = k;
        memset(t, -1, sizeof(t));

        return solve(0, 0, 0);
    }
};