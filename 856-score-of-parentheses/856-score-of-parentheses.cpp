class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<char> st;
        for(int i = 0; i < s.size() ; i++){
            if( s[i] == '('){
                st.push(score);
                score = 0;
            } else {
                score += st.top() + max(score , 1);
                st.pop();
            }
        }
        return score;
    }
};