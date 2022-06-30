class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int g) {
        map<int , int> m;
        for(auto i : hand)
            m[i]++;
        for(auto i : m)
            if( i.second > 0)
                for(int j = g - 1; j >= 0 ; j--)
                    if( (m[i.first + j] -= m[i.first]) < 0 )
                        return false;
        return true;
    }
};