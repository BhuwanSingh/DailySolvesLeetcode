class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto i : timePoints){
            int temp = i[0] * 10 * 60 + i[1] * 60 + i[3] * 10 + i[4];
            v.push_back(temp);
        }
        sort(v.begin() , v.end());
        int res = INT_MAX;
        for(int i = 0; i < v.size() - 1 ; i++){
            res = min(res , v[i + 1] - v[i]);
        }
        res = min(res , 24 * 60 - v[v.size() - 1] + v[0]);
        return res;
    }
};