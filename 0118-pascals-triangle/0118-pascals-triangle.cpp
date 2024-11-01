class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        numRows--;
        while(numRows--){
            vector<int> temp = res.back();
            vector<int> ans = {1};
            for(int i = 1; i < temp.size() ; i++){
                ans.push_back(temp[i - 1] + temp[i]);
            }
            ans.push_back(1);
            res.push_back(ans);
        }
        return res;
    }
};