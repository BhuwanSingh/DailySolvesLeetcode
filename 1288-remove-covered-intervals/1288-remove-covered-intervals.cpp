class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& in) {
        sort(begin(in) , end(in) , [&](vector<int>& a , vector<int>& b){
            if( a[0] != b[0] ) return a[0] < b[0];
            else return b[1] < a[1];
            
        });
        int n = in.size();
        vector<vector<int>> fin;
        fin.push_back(in[0]);
        for(int i = 1; i < n ; i++){
            if( fin.back()[0] <= in[i][0] && fin.back()[1] >= in[i][1]) continue;
            fin.push_back(in[i]);
        }
        return fin.size();
    }
};