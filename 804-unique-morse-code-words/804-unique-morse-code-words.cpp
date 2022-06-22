class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> a = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.." };
        unordered_set<string> s;
        for(auto i : words){
            string temp;
            for(auto j : i){
                temp += a[j - 'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};