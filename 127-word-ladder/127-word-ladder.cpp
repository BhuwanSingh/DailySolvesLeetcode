class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> w = unordered_set<string>(wordList.begin() , wordList.end());
        int n = wordList.size();
        queue<string> q;
        q.push(beginWord);
        int depth = 1;
        while(!q.empty()){
            for(int i = q.size() ; i > 0 ; i--){
                string curr = q.front();
                string copy = curr;
                if(curr == endWord) return depth;
                q.pop();
                w.erase(curr);
                for(int k = 0; k < curr.size() ; k++){
                    for(int j = 0 ; j < 26 ; j++){
                        curr[k] = 'a' + j;
                        // cout << curr << " ";
                        if( w.find(curr) != w.end() ){
                            q.push(curr);
                        }
                    }
                    curr[k] = copy[k];
                }
            }
            depth++;
        }
        return 0;
    }
};