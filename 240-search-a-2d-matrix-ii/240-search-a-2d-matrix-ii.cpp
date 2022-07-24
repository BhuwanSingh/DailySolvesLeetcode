class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() , m = matrix[0].size();
        for(int i = 0; i < n ; i++){
            auto itr = lower_bound(matrix[i].begin() , matrix[i].end() , target);
            if( itr != matrix[i].end() && *itr == target ) return true;
        }
        return false;
    }
};