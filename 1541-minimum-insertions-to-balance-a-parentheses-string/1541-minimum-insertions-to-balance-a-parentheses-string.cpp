class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int count = 0;
        int result = 0;
        int i = 0;

        while(i<n){
            if(s[i] == '('){
                count++;
                i++;
            }
            else{ // ')' closing bracket h
                if(count > 0){
                    count--;
                }
                else{
                    result++;
                }

                if(i+1 < n && s[i+1] == ')'){ //balance bhi to check krna h
                    i += 2;
                }
                else{
                    result++; //ek close bracket add krne k liye
                    i++;
                }
            }
        }
        if(count > 0){
            result += 2*count;
        }
        return result;
    }
};