class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n , string(n , '.'));
        combos(0 , n , temp,  res);        
        return res.size();
    }
    
    void combos(int row , int n , vector<string>& temp , vector<vector<string>>& res){
        if(row == n){
            res.push_back(temp);
            return;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(isSafe(temp , row , i)){
                temp[row][i] = 'Q';
                combos(row + 1 , n , temp ,  res); 
            }
            temp[row][i] = '.';
        }
    }
    
    bool isSafe(vector<string>& temp  , int row , int col){
        int n = temp.size();
        for(int i = 0 ; i < n ; i++){
            if(temp[row][i] == 'Q') return false;
        }
        for(int i = 0 ; i < n ; i++){
            if(temp[i][col] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (temp[i][j] == 'Q') return false;

        for (int i = row, j = col; j >= 0 && i < n; i++, j--)
            if (temp[i][j] == 'Q') return false;
        
        for (int i = row, j = col; j < n && i >= 0; i--, j++)
            if (temp[i][j] == 'Q') return false;
        
        
        return true;
    }
};
