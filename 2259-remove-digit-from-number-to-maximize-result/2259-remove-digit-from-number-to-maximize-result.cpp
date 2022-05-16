class Solution {
public:
    string removeDigit(string nu, char d) {
        int cnt = 0;
        int n = nu.size();
        for(int i = 0; i < n ; i++){
            if( nu[i] == d) cnt++;
        }
        for(int i = 0; i < n ; i++){
            if( nu[i] == d){
                cnt--;
                if(i < n && nu[i + 1] > nu[i] || cnt == 0) return nu.substr(0 , i) + nu.substr( i + 1 );
                else if( i == n - 1) return nu.substr(0 , n - 1);
            }
        }
        return "";
    }
};