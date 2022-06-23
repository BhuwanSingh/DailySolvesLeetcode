class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , [](vector<int>&a , vector<int>&b){
            return a[1] < b[1];
        });
        int n = courses.size() , time = 0;
        priority_queue<int> pq;
        for(int i = 0; i < n ; i++){
            auto cur = courses[i];
            time += cur[0];
            pq.push(cur[0]);
            if(time > cur[1]){
                time -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};