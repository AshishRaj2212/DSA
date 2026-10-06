class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int openBrack = 0;
        int size = 0;

        for(int i = 0; i<n; i++){
            if(s[i] == '('){
                size++;
            }
            else if(s[i] == ')' && size > 0){
                size--;
            }
            else{
                openBrack++;
            }
        }
        return openBrack + size;
    }
};