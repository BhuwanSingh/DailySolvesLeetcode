class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end() , [](vector<int>& a , vector<int>& b){
            return a[1] > b[1];
        });
        int res = 0;
        for(int i = 0; i < boxTypes.size() ; i++){
            int k = min(truckSize , boxTypes[i][0]);
            if(!k) break;
            res += k * boxTypes[i][1];
            truckSize -= k;
        }
        return res;
    }
};