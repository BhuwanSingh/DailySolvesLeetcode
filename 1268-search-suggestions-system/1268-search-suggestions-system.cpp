class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin() , products.end());
        string t;
        vector<vector<string>> res;
        for(auto i : searchWord){
            t += i;
            vector<string> f;
            for(int j = 0; j < products.size() && f.size() < 3 ; j++){
                if( products[j].size() >= t.size() && products[j].substr(0 , t.size()) == t ){
                    f.push_back(products[j]);
                }
            }
            res.push_back(f);
        }
        return res;
    }
};