class Solution {
public:
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        int count = 0;
        int i = 1000;
        while(i<=n){
            count++;
            i++;
        }
        return count;
    }
};