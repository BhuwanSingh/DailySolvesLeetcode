class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int a = pref.size() , res = 0;
        for(auto i : words){
            if( i.substr(0 , a) == pref) res++;
        }
        return res;
    }
};