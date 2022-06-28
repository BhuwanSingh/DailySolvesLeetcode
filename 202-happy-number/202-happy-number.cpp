class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        int res = n;
        while(true){
            string str = to_string(res);
            res = 0;
            for(auto i : str){
                res += (i - '0') * (i - '0');
            }
            if(res == 1) return true;
            if( s.find(res) != s.end() ) return false;
            s.insert(res);
        }
        return true;
    }
};