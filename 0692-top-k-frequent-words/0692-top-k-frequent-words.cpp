class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string , int> um;
        for( auto& i : words){
            um[i]++;
        }
        vector<pair<string , int>> vp = vector<pair<string , int>>(um.begin() , um.end());
        
        sort( vp.begin() , vp.end() , [&](pair<string , int>& a , pair<string , int>& b){
            if( a.second != b.second){
                return a.second > b.second;
            } else {
                return a.first < b.first;
            }
        });
        
        vector<string> res;
        for(int i = 0; i < k ; i++){
            res.push_back(vp[i].first);
        }
        
        return res;
    }
};