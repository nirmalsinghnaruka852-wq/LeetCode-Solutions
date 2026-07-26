class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        vector<vector<int>> ans;
        int i = 0, j = 0, n = series1.size(), m = series2.size();

        while (i < n && j < m) {
            if (series1[i][0] == series2[j][0])
                ans.push_back({series1[i][0], series2[j++][1] + series1[i++][1]});
            else if (series1[i][0] > series2[j][0])
                ans.push_back({series2[j][0], series2[j++][1] + series1[i][1]});
            else
                ans.push_back({series1[i][0], series2[j][1] + series1[i++][1]});
        }

        while (i < n) {
            ans.push_back({series1[i][0], series1[i++][1]});
        }

        while (j < m) {
            ans.push_back({series2[j][0], series2[j++][1]});
        }

        return ans;
    }
};