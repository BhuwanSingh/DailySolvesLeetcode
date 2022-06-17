class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack <int> s;
        int n = heights.size();
        vector<int> v(n);
        for(int i = 0; i < n ; i++){
            while(!s.empty() && heights[s.top()] <= heights[i] ){
                v[s.top()]++;
                s.pop();
            }
            if(!s.empty()){
                v[s.top()]++;
            }
            s.push(i);
        }
        return v;
    }
};