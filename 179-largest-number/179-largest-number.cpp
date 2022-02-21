class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nos;
        for(auto& i : nums){
            nos.push_back(to_string(i));
        }
        sort(begin(nos) , end(nos) , [&](string& a , string& b){
            return ( a + b > b + a );
        });
        string res;
        for(string& i : nos){
            // cout << i << " ";
            res += i;
        }
        while(res[0]=='0' && res.length()>1)
            res.erase(0,1);
        return res;
    }
};