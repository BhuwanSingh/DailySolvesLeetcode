class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        for(int i = stations.size() - 1 ; i > 0 ; i--){
            stations[i][0] -= stations[i - 1][0];
        }
        priority_queue<int> pq;
        int stops = 0 , distance = 0;
        for(auto i : stations){
            // cout << "station " <<  i[0] << " " << i[1] << "\n";
            startFuel -= i[0];
            while( startFuel < 0 && !pq.empty()){
                // cout << pq.top() << " ";
                startFuel += pq.top();
                pq.pop();
                stops++;
            }
            if( pq.empty() && startFuel < 0) return -1;
            pq.push(i[1]);
            if( distance + startFuel >= target ) return stops;
            distance += i[0];
        }
        while( !pq.empty() && startFuel + distance < target){
            startFuel += pq.top();
            pq.pop();
            stops++;
        }
        if( distance + startFuel >= target ) return stops;
        else return -1;
    }
};