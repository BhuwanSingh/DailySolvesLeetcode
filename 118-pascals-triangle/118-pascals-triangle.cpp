class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> temp = {1};
        res.push_back(temp);
        int i = 1;
        while(i < numRows){
            vector<int> curr(temp.size() + 1);
            for(int i = 0; i < curr.size() ; i++ ) {
                if(i == 0 || i == curr.size() - 1 ){
                    curr[i] = 1;
                } else {
                    curr[i] = temp[i] + temp[i - 1];
                }
            }
            temp = curr;
            res.push_back(curr);
            i++;
        }
        return res;
    }
};