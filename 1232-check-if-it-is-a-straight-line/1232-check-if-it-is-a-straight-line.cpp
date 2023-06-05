class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        sort( coordinates.begin() , coordinates.end() , [&](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        });
        
        if( coordinates[0][0] == coordinates[1][0] ){
            int x = coordinates[0][0];
            for(int i = 2 ; i < coordinates.size() ; i++){
                if( coordinates[i][0] != x )
                    return false;
            }
        }
        
        float slope = float( coordinates[1][1] - coordinates[0][1] ) / float( coordinates[1][0] - coordinates[0][0] );
        
        for(int i = 2 ; i < coordinates.size() ; i++){
            float new_slope = float( coordinates[i][1] - coordinates[0][1] ) / float( coordinates[i][0] - coordinates[0][0] );
            
            if( new_slope != slope )
                return false;
        }
        
        return true;
    }
};