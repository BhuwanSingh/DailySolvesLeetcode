class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        int res = INT_MAX;
        vector<int> c(k);
        combos(cookies , c , 0 , res);
        return res;
    }
    
    void combos( vector<int>& cookies , vector<int>& c , int x , int& res ){
        if(x == cookies.size()){
            res = min(res , *max_element(c.begin() , c.end()));
            return;
        }
        
        for(int i = 0 ; i < c.size() ; i++){
            c[i] += cookies[x];
            combos(cookies , c , x + 1 , res);
            c[i] -= cookies[x];
        }
    }
};