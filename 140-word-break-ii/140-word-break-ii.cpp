class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> um = unordered_set<string>( wordDict.begin() , wordDict.end() );
        set<string> res;
        string temp = "";
        combos(um , s , temp , 0 , 0 , res );
        return vector<string>(res.begin() , res.end());
    }
    
    void combos(unordered_set<string>& um , string s , string temp , int x , int y , set<string>& res){
        int n = s.size();
        // cout << "|" << temp << "|\n";
        if( y >= n && x == y){
            res.insert(temp.substr(0 , temp.size() - 1));
            return;
        }
        
        for(int i = y ; i < n ; i++){
            if( um.find(s.substr(x , i - x + 1)) != um.end() ){
                // cout << s.substr(x , i - x + 1) << " ";
                combos(um , s , temp + s.substr(x , i - x + 1) + " " , i + 1 , i + 1 , res);
                combos(um , s , temp , x , i + 1 , res);
            }
        }
    }
};