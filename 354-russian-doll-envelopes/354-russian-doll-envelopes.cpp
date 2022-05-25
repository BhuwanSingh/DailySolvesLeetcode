class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<pair<int, int> > temp, seq;
        int n = envelopes.size();
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = envelopes[i][0];
            p.second = envelopes[i][1];
            temp.push_back(p);
        }
        sort(temp.begin(), temp.end(), [](pair<int, int> a, pair<int, int>b){
		return a.first < b.first || (a.first==b.first && a.second > b.second);
	    });
        vector<int> collector;
        for(auto& pair: temp)
        {
            auto iter = lower_bound(collector.begin(), collector.end(), pair.second);
            if(iter == collector.end()) collector.push_back(pair.second);
            else if(*iter > pair.second) *iter = pair.second;
            // int left = 0, right = collector.size(), mid;
            // while(left < right) {
            //     mid = left + (right - left) / 2;
            //     if (collector[mid] < pair.second) {
            //         left = mid + 1;
            //     } else {
            //         right = mid;
            //     }
            // }
            // if(left < collector.size() && collector[left] < pair.second) {
            //    left++;
            // }
            // if (left == collector.size()) {
            //     collector.push_back(pair.second);
            // } else {
            //     collector[left] = pair.second;
            // }
        }
        return collector.size();
    }
};