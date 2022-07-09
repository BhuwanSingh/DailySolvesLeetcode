class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();        
        priority_queue<pair<int , int>> pq;
        int i;
        for(i = n - 1 ; i > 0 ; i--){
            if(pq.empty()){
                pq.push({nums[i] , i});
            } else {
                while( pq.top().second - i > k ) pq.pop();
                int temp = pq.top().first + nums[i];                
                pq.push({temp , i});
            }
        }        
        while( !pq.empty() && pq.top().second - i > k ) pq.pop();
        if( pq.empty() ) return nums[0];
        return pq.top().first + nums[0];
    }
};