class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            if (a[1] == b[1])
                return a[0] > b[0];  
            return a[1] > b[1];      
        });

        int ans = 0;

        for (auto &box : boxTypes) {
            int take = min(box[0], truckSize);

            ans += take * box[1];
            truckSize -= take;

            if (truckSize == 0)
                break;
        }

        return ans;
    }
};