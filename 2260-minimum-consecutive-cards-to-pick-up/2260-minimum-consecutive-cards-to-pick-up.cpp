class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map< int , int> um;
        int n = cards.size();
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            if(um.find(cards[i]) != um.end()){
                res = min(res , i - um[cards[i]] + 1);
            }
            um[cards[i]] = i;
        }
        return res != INT_MAX ? res : -1;
    }
};