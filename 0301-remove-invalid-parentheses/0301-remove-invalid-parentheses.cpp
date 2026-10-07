using vs = vector<string>;
class Solution {
public:
    vs result;
    string ans;
    int lastStingSize;
    int nextVaild(int index, string& s) {
        int nextIndex = index + 1;
        while (nextIndex < s.size() && s[nextIndex] == s[index])
            nextIndex++;
        return nextIndex;
    }
    void genrateVaildString(int currentIndex, int sum, string& s) {
        if (sum < 0)
            return;
        if (currentIndex >= s.size()) {
            if (sum != 0)
                return;

            // cout << ans << endl;
            // cout << lastStingSize <<  ;
            if (ans.size() > lastStingSize) {
                lastStingSize = ans.size();
                result.clear();
                result.push_back(ans);
            } else if (ans.size() == lastStingSize) {
                result.push_back(ans);
            }

            return;
        }

        //    skip ;
        genrateVaildString(nextVaild(currentIndex, s), sum, s);
        // take ;
        ans.push_back(s[currentIndex]);
        if (s[currentIndex] != '(' && s[currentIndex] != ')')
            sum = sum;
        else
            sum = (s[currentIndex] == '(') ? sum + 1 : sum - 1;
        genrateVaildString(currentIndex + 1, sum, s);
        ans.pop_back();
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        result.clear();
        ans.clear();
        // lastStingSize = INT_MIN;
        lastStingSize = 0 ; 
        genrateVaildString(0, 0, s);
        return result;
    }
};
//  there is only one issus which is the result array ; why that return the
//  empty ;
