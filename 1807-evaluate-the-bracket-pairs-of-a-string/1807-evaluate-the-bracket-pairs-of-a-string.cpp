class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string, string> mp;
        for(auto &it : knowledge){
            mp[it[0]] = it[1];
        }
        string result = "";
        int i = 0;

        while(i<n){
            if(isalpha(s[i])){
                result.push_back(s[i]);
            }
            else{
                i++;
                string temp = "";
                while(s[i] != ')' && i<n){
                    temp.push_back(s[i]);
                    i++;
                }
                result += mp.count(temp) ? mp[temp] : "?";
            }
            i++;
        }
        return result; 
    }
};