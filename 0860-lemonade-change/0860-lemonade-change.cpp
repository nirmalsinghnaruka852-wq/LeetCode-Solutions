class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0;
        int tens = 0;

        for (int index = 0; index < bills.size(); index++) {

            int remaining = bills[index] - 5;
            if (remaining >= 10 && tens >= 1) {
                tens--;
                remaining -= 10;
            }

            if (remaining >= 5) {
                int needed = remaining / 5;

                if (needed > fives)
                    return false;

                fives -= needed;
                remaining -= needed * 5;
            }

            if (remaining != 0)
                return false;

            
            if (bills[index] == 5)
                fives++;
            else if (bills[index] == 10)
                tens++;
        }

        return true;
    }
};