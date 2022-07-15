class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int maxval = 0 , cnt = 0;
        for(auto i : rectangles){
            int t = min(i[0] , i[1]);
            if( t > maxval ){
                cnt = 1;
                maxval = t;
            } else if( t == maxval){
                cnt++;
            }
        }
        return cnt;
    }
};