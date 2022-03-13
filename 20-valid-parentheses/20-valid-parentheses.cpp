class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack <char> sa;
        for(int i = 0; i < n ; i++){
            if(s[i] == '{' || s[i] == '(' || s[i] == '['){
                sa.push(s[i]);
            }
            else {
                if(sa.empty()) return false;
                int f;
                if(s[i] == '}') f = 1;
                if(s[i] == ']') f = 2;
                if(s[i] == ')') f = 3;
                switch(f){
                    case 1:{
                        if(sa.top() == '{') sa.pop();
                        else return false;
                        break;
                    } case 2:{
                        if(sa.top() == '[') sa.pop();
                        else return false;
                        break;
                    } case 3:{
                        if(sa.top() == '(') sa.pop();
                        else return false;
                        break;
                    }
                }
            }
        }
        if(sa.empty()) return true;
        else return false;
    }
};