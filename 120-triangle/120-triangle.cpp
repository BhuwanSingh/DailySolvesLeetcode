class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> t(n , vector<int>(n , -1e5));
        return dfs(triangle , t , 0 , 0);
    }
    
    int dfs(vector<vector<int>>& triangle , vector<vector<int>>& t , int x , int y){
        int n = t.size();
        if( x >= n || y > x ) return 0;
        if(t[x][y] != -1e5) return t[x][y];
        t[x][y] = min(dfs(triangle ,t , x + 1 , y) , dfs(triangle ,t , x + 1 , y + 1)) + triangle[x][y];
        return t[x][y];
    }
};