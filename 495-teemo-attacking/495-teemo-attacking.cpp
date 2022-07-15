class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size() , res = 0;
        for(int i = 0; i < n - 1 ; i++){
            res += min(timeSeries[i] + duration ,  timeSeries[i + 1] ) - timeSeries[i];
        }
        res += duration;
        return res;
    }
};