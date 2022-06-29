class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n = people.size();
        sort(people.begin() , people.end() , [](vector<int>& a , vector<int>&b){
            if( a[0] != b[0]){
                return a[0] > b[0];
            } else {
                return a[1] < b[1];
            }
        });
        // for(int i = 0; i < n ; i++){
        //     cout << people[i][0] << "," << people[i][1] << " ";
        // }
        // cout << "\n";
        int curr = people[0][0];
        vector<vector<int>> res = {people[0]};
        for(int i = 1 ; i < n; i++){
            if( people[i][0] == curr){
                res.push_back(people[i]);
            } else {
                res.insert( res.begin() + people[i][1] , people[i]);
            }
        }
        return res;
    }
};