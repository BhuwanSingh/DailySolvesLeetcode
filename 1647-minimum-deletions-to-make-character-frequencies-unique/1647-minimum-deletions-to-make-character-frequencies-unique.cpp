class Solution {
public:
    int minDeletions(string s) {
        int res = 0;
        vector<int> cnt(26);
        for(auto i : s){
            cnt[i - 'a']++;
        }
        vector<int> b;
        for(auto i :cnt){
            if(i > 0) b.push_back(i);
        }
        sort(b.begin() , b.end());
        for(int i = b.size() - 1; i > 0 ; i--){
            while( b[i] <= b[ i - 1] && b[i - 1] > 0){
                res++;
                b[i - 1]--;
            }
        }
        return res;
    }
};