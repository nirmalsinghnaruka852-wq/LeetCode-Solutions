using vi = vector<int>;
using vb = vector<bool>;
using vs = vector<string>;
using vvs = vector<vs>;

class Solution {
public:
    vi ans;
    vi dp;
    vb visited;

    int minOne = INT_MAX;
    vi result;

    int fullMask;

    map<string, int> mp;

    void generateSmallestSufficientTeam(
        int currentIndex , 
        vvs& peoples,
        vs& req_skills,
        map<string, int>& mp,
        int mask = 0
    ) {
        if (mask == fullMask) {
            if (minOne > ans.size()) {
                minOne = ans.size();
                result = ans;
            }
            return;
        }

        if (dp[mask] != INT_MAX && ans.size() >= dp[mask])
            return;
            dp[mask] = ans.size();


        for (int person = currentIndex; person < peoples.size(); person++) {

            if (visited[person])
                continue;

            int newMask = mask;

            for (string skill : peoples[person]) {
                newMask = newMask | (1 << mp[skill]);
            }

            visited[person] = true;
            ans.push_back(person);

            // dp[newMask] = min(dp[newMask], (int)ans.size());

            generateSmallestSufficientTeam(
              person+1 , 
                peoples,
                req_skills,
                mp,
                newMask
            );

            visited[person] = false;
            ans.pop_back();
        }
        return ; 
    }

    vector<int> smallestSufficientTeam(
        vector<string>& req_skills,
        vector<vector<string>>& people
    ) {
        int n = people.size();
        int m = req_skills.size();

        int size_dp = 1 << m;

        fullMask = (1 << m) - 1;

        visited.resize(n, false);
        dp.resize(size_dp, INT_MAX);

        for (int index = 0; index < m; index++) {
            mp[req_skills[index]] = index;
        }

        generateSmallestSufficientTeam(
           0 , 
            people,
            req_skills,
            mp
        );

        return result;
    }
};