class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> vu(numCourses);
        for(auto i : prerequisites){
            vu[i[0]].insert(i[1]);
        }
        vector<int> res;
        vector<bool> vis(numCourses);
        while(res.size() < numCourses){
            bool pos = false;
            for(int i = 0 ; i < numCourses ; i++){
                if( vis[i] == true) continue;
                if(vu[i].size() == 0) {
                    pos = true;
                    vis[i] = true;
                    res.push_back(i);
                    for(auto& j : vu){
                        j.erase(i);
                    }
                }
            }
            if(!pos) return {};
        }
        return res;
    }
};