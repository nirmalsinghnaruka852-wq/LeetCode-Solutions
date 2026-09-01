class Solution {
public:
    string getSmallestString(int n, int k) {
        int remaining = n;
        int currentSum = k;
        string ans = "";

        while (remaining != 0) {

            int maxRemaining = (remaining - 1) * 26;
            if (currentSum - 1 <= maxRemaining) {
                ans += 'a';
                currentSum -= 1;
            }
            else {
                
                int extra = currentSum - maxRemaining;

                ans += char('a' + extra - 1);
                currentSum -= extra;
            }

            remaining--;
        }

        return ans;
    }
};