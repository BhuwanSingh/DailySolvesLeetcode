class Solution {
public:
    int maximumSwap(int num) {
        string t = to_string(num);
        int n = t.size();        
        for(int i = 0; i < n ; i++){
            auto a = max_element( t.rbegin(), t.rend() - (i + 1) );
            if( t[i] < *a ) {
                swap( t[i] , *a );
                return stoi(t);
            }
        }
        return stoi(t);
    }
};