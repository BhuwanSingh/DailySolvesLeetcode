class Solution {
public:
    vector<int> p;
    int fnd(int x){
        while( p[x] != x ){
            x = p[x];
            p[x] = p[p[x]];
        }
        return x;
    }
    
    void uni(int x , int y ){
        int px = fnd(x);
        int py = fnd(y);
        if( px != py )
            p[px] = py;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        p.resize(300);
        for(int i = 1 ; i <= n + 1 ; i++){
            p[i] = i;
        }
        for( int i = 0; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if( isConnected[i][j] == 1 )
                    uni(i + 1 , j + 1);
            }
        }
        
        set<int> s;
        for(int i = 1 ; i <= n ; i++){
            // cout << p[i] << " ";
            s.insert(fnd(p[i]));
        }
        // cout << "\n";
        return s.size();
        
    }
};