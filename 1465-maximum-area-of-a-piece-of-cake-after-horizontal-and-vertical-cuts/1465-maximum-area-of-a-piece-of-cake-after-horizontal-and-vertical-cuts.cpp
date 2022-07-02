class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        const int N = 1e9 + 7;
        vector<int> a , b;
        horizontalCuts.push_back(h);
        horizontalCuts.push_back(0);
        verticalCuts.push_back(w);
        verticalCuts.push_back(0);
        sort(horizontalCuts.begin() , horizontalCuts.end());
        sort(verticalCuts.begin() , verticalCuts.end());
        for(int i = 1; i < horizontalCuts.size() ; i++)
            a.push_back(horizontalCuts[i] - horizontalCuts[i - 1] );
        for(int i = 1 ; i < verticalCuts.size() ; i++)
            b.push_back(verticalCuts[i] - verticalCuts[i - 1] );    
        int f = *max_element(a.begin() , a.end());
        int g = *max_element(b.begin() , b.end());
        long long res = ( (1LL * f) * (1LL * g) ) % N;
        return int(res);
    }
};