class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        combos(res , temp , k , n , 1);
        return res;
    }
    
    void combos(vector<vector<int>>& res , vector<int>& temp , int k , int n , int itr){
        if(n < 0 || k < 0) return;
        if(n == 0 && k == 0){
            res.push_back(temp);
            return;
        }
        for(int i = itr ; i <= 9 ; i++){
            temp.push_back(i);
            combos(res , temp , k - 1 , n - i , i + 1);
            temp.pop_back();
        }
    }
};