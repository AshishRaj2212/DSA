class Solution {
public:
    long long countCommas(long long n) {
        long long result = 0;
        long long lower = 1000;

        if(n < 1000) return 0;
        while(lower <= n){
            result += (n-lower+1);
            lower = lower*1000;
        }
        return result;
    }
};