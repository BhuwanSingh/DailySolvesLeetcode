class Solution {
public:
    int n , count;
    vector<int> parts;
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size();
        count = n * n * 4;
        for(int i = 0; i < count ; i++)
            parts.push_back(i);
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if (i > 0) uni(g(i - 1, j, 2), g(i, j, 0));
                if (j > 0) uni(g(i , j - 1, 1), g(i , j, 3));
                if (grid[i][j] != '/') {
                    uni(g(i , j, 0), g(i , j,  1));
                    uni(g(i , j, 2), g(i , j,  3));
                }
                if (grid[i][j] != '\\') {
                    uni(g(i , j, 0), g(i , j,  3));
                    uni(g(i , j, 2), g(i , j,  1));
                }   
            }
        }
        return count;
    }
    
    int find(int x){
        if(x != parts[x])
            parts[x] = find(parts[x]);
        return parts[x];
    }
    
    void uni(int x , int y){
        x = find(x) , y = find(y);
        if( x != y){
            parts[x] = y;
            count--;
        }   
    }
    
    int g(int i , int j , int k){
        return (i * n + j) * 4 + k;
    }
};