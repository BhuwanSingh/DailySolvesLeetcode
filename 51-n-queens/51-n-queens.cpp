class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp( n , std::string(n , '.')) ;
        combos(res , temp , 0 , n);
        return res;
    }
    
    void combos(vector<vector<string>>& res , vector<string>& temp , int x , int n){
        if( x > n ) return;
        if( x == n ){
            res.push_back(temp);
            return;
        }        
        for(int j = 0 ; j < n ; j++){
            if(check( temp , x , j)){
                temp[x][j] = 'Q';
                combos( res , temp , x + 1 , n);
                temp[x][j] = '.';
            }
        }
    }
    
    bool check(vector<string>& v , int x , int y){
        int n = v[0].size();
        for(int i = 0; i < n ; i++){
            if( v[x][i] == 'Q') return false;
        }
        for(int i = 0; i < n ; i++){
            if( v[i][y] == 'Q') return false;
        }
        int a = x , b = y;
        while( a > 0 && b > 0) a-- , b--;
        
        for( ; a < n && b < n ; a++ , b++){
            if( v[a][b] == 'Q') return false;
        }
        a = x , b = y;
        while( a < n - 1 && b > 0) a++ , b--;
        for( ; a >= 0 && b < n ; a-- , b++){
            if( v[a][b] == 'Q') return false;
        }
        return true;
    }
};