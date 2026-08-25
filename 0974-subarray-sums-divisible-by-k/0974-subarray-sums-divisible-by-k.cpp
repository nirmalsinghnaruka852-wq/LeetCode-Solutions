using vi = vector<int>;
using mii = map<int, int>;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;

        mii mp;
        mp[0] = 1;

        for (int index = 0; index < nums.size(); index++) {
            sum += nums[index];

            int remainder = ((sum % k) + k) % k;

            count += mp[remainder];

            mp[remainder]++;
        }

        return count;
    }
};