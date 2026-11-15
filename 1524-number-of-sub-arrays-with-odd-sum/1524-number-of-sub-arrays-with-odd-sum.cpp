
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        int n = arr.size();
        vector<int> prefix(n);

        int sum = 0;

        for (int i = 0; i < n; i++) {
            sum += arr[i];
            prefix[i] = sum;
        }

        long long count = 0;
        long long odds = 0;
        long long evens = 1; // Empty prefix (sum = 0)

        for (int i = 0; i < n; i++) {
            if (prefix[i] % 2 == 0) {
                count = (count + odds) % MOD;
                evens++;
            } else {
                count = (count + evens) % MOD;
                odds++;
            }
        }

        return count;
    }
};
