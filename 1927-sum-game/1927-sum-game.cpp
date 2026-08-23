class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int leftKnownSum = 0;
        int rightKnownSum = 0;
        int leftQnCounter = 0;
        int rightQnCounter = 0;

        for(int i = 0; i<n; i++){
            if(num[i] == '?'){
                if(i < n/2){
                    leftQnCounter++;
                }
                else{
                    rightQnCounter++;
                }
            }
            else{
                if(i < n/2){
                    leftKnownSum += num[i] - '0';
                }
                else{
                    rightKnownSum += num[i] - '0';
                }
            }
        }
        int totalQn = leftQnCounter + rightQnCounter;
        if(totalQn % 2 == 1){
            return true;
        }

        int left = 2 * leftKnownSum + 9 * leftQnCounter;
        int right = 2 * rightKnownSum + 9 * rightQnCounter;

        if(left == right) return false;
        else return true;
    }
};