class Solution {
public:
    unordered_map< char , unordered_map<char , char>> uum;
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        for(auto& i : mappings)
            uum[i[0]][i[1]] = 1;        
        for(int i = 0 ; i < s.size() ; i++)
            if(check(i , sub , s)) return true;
        return false;
    }
    bool check(int pos , string& sub , string& s){
        if( pos + sub.size() > s.size() ) return false;
        int index = 0;
        for(int i = pos ; i < pos + sub.size() ; i++){
            if( sub[index] == s[i] || (uum[sub[index]][s[i]] == 1) ) index++;
            else return false;
        }
        return true;
    }
};