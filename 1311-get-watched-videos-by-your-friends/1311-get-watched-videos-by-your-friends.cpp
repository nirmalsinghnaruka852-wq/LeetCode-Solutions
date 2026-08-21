class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                          vector<vector<int>>& friends, int id,
                                          int level) {

        int n = watchedVideos.size();

        vector<bool> visited(n, false);
        queue<int> q;

        visited[id] = true;
        q.push(id);

        int k = 0;

   
        while (!q.empty() && k < level) {

            int levelSize = q.size();

            while (levelSize--) {

                int node = q.front();
                q.pop();

                for (int edge : friends[node]) {

                    if (visited[edge])
                        continue;

                    visited[edge] = true;
                    q.push(edge);
                }
            }

            k++;
        }

       
        unordered_map<string, int> freq;

        while (!q.empty()) {

            int person = q.front();
            q.pop();

            for (string video : watchedVideos[person]) {
                freq[video]++;
            }
        }

    
        vector<string> ans;

        for (auto& [video, count] : freq) {
            ans.push_back(video);
        }


        sort(ans.begin(), ans.end(), [&](string& a, string& b) {

            if (freq[a] != freq[b])
                return freq[a] < freq[b];

            return a < b;
        });

        return ans;
    }
};