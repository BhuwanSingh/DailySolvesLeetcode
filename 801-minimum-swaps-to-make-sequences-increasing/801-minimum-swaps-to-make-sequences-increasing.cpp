class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int n = a.size() , ns = 0 , s = 1;
        for(int i = 1 ; i < n ; i++){
            int ns2 = n , s2 = n;
            if( a[i - 1] < a[i] && b[i - 1] < b[i]){
                s2 = s + 1;
                ns2 = ns;
            }
            if( a[i - 1] < b[i] && b[i - 1] < a[i]){
                s2 = min(s2 , ns + 1);
                ns2 = min(ns2 , s);
            }
            s = s2;
            ns = ns2;
            // cout << s <<  " " << ns << "\n";
        }
        // cout << "\n\n";
        return min(ns , s);
    }
};