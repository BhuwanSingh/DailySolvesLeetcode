class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead = unordered_set<string>( deadends.begin() , deadends.end());
        if( dead.find("0000") != dead.end()) return -1;
        queue<string> q({"0000"});
        for(int steps = 0 ; !q.empty() ; steps++){
            for(int i = q.size() ; i > 0 ; i--){
                auto curr = q.front() ; q.pop();
                if( target == curr ) return steps;
                for(auto node : neighbours(curr)){
                    if(dead.find(node) != dead.end()) continue;
                    dead.insert(node);
                    q.push(node);
                }
            }
        }
        return -1;
    }
    
    vector<string> neighbours(string& code){
        vector<string> result;
        for(int i = 0 ; i < 4 ; i++){
            for(int diff = -1 ; diff <= 1 ; diff += 2){
                string temp = code;
                temp[i] = (temp[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(temp);
            }
        }
        return result;
    }
};