class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        combos( candidates , res , temp , 0 , target);
        return res;
    }
    
    void combos(vector<int>& candidates, vector<vector<int>>& res , vector<int> temp , int x , int target){
        if( target == 0){
            res.push_back(temp);
        }
        
        for(int i = x ; i < candidates.size() ; i++){
            if( target >= candidates[i]){
                temp.push_back(candidates[i]);
                combos( candidates , res , temp , i , target - candidates[i]);
                temp.pop_back();
            }
        }
    }
};