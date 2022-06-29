class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> arr2 = arr;
        long long s1 = 0 , s2 = 0 , res = 0;
        sort(arr2.begin() , arr2.end());
        for(int i = 0; i < arr.size() ; i++){
            s1 += arr[i];
            s2 += arr2[i];
            res += s1 == s2;
        }
        return int(res);
    }
};