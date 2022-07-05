class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> low;
        multiset<pair<int , int>> high;
        for(int i = 0; i < profits.size() ; i++){
            if( profits[i] && capital[i] <= w ){
                low.push(profits[i]);
            } else {
                high.insert({capital[i] , profits[i]});
            }
        }
        while( k-- && low.size() ){
            w += low.top() , low.pop();
            for(auto i = high.begin() ; high.size() && i->first <= w ; i = high.erase(i) ) 
                low.push(i->second);
        }
        return w;
    }
};