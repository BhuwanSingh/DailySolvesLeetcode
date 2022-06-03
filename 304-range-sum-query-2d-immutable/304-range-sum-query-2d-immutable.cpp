class NumMatrix {
public:
    vector<vector<int>>& pre;
    
    NumMatrix(vector<vector<int>>& matrix) : pre(matrix) {
        for(int i = 0; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if( i == 0 && j == 0 ) continue;
                else if( i == 0){
                    pre[i][j] += pre[i][j - 1];
                } else if ( j == 0){
                    pre[i][j] += pre[i - 1][j];
                } else {
                    pre[i][j] += (pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1]);
                }
                cout << pre[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = pre[row2][col2];
        if(row1 > 0 ) res -= pre[row1 - 1][col2];
        if(col1 > 0 ) res -= pre[row2][col1 - 1];
        if(row1 > 0 && col1 > 0) res += pre[row1 - 1][col1 - 1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */