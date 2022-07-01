class Solution {
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>> dp( n , vector<vector<int>>(n , vector<int>(n)));
        return bp( boxes , 0 , n - 1 , 0 , dp);
    }
    
    int bp( vector<int>& boxes , int start , int end , int k , vector<vector<vector<int>>>& dp){
        if( start > end ) return 0;
        if( dp[start][end][k] > 0) return dp[start][end][k];
        
        int res = 0 , i = start , k_pos = k;
        for(; start + 1 <= end && boxes[start] == boxes[start + 1] ; k++ , start++);
        
        res = (k + 1) * (k + 1) + bp( boxes , start + 1 , end , 0 , dp);
        
        for(int j = start + 1 ; j <= end ; j++){
            if(boxes[i] == boxes[j]){
                res = max(res , bp(boxes , start + 1 , j - 1 , 0 , dp ) + bp(boxes , j , end , k + 1 , dp ) );
            }
        }
        return dp[i][end][k_pos] = res;
    }
};