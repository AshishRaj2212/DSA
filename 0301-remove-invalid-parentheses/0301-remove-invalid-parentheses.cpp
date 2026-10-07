class Solution {
public:
    int n;
    unordered_set<string> st;

    void solve(const string& s, int idx, string& curr, int count, int& max_len){
        if(count < 0) return;
        if(idx == n){
            if(count == 0){
                if(curr.length() > max_len){
                    max_len = curr.length();
                    st.clear();
                }
                if(curr.length() == max_len){
                    st.insert(curr);
                }
            }
            return;
        }
        if(s[idx] != '(' && s[idx] != ')'){
            curr.push_back(s[idx]);
            solve(s, idx+1, curr, count, max_len);
            curr.pop_back();
            return;
        }
        curr.push_back(s[idx]);
        solve(s, idx+1, curr, count + (s[idx] == '(' ? 1 : -1), max_len);
        curr.pop_back();
        solve(s, idx+1, curr, count, max_len);
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        st.clear();
        int max_len = 0;

        string curr = "";

        solve(s, 0, curr, 0, max_len);

        return vector<string>(st.begin(), st.end());
    }
};