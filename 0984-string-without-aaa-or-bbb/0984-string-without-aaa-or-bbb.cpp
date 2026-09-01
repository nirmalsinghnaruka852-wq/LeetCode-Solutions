class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans = "";

        char lastElement = '#';
        int occurrence = 0;

        while (a != 0 || b != 0) {
            char maxOne = (a >= b) ? 'a' : 'b';

            char other = (maxOne == 'a') ? 'b' : 'a';

            if (maxOne == lastElement && occurrence == 2) {
                ans += other;

                if (other == 'a')
                    a--;
                else
                    b--;

                if (lastElement == other)
                    occurrence++;
                else {
                    lastElement = other;
                    occurrence = 1;
                }
            }
            else {
                ans += maxOne;

                if (maxOne == 'a')
                    a--;
                else
                    b--;

                if (lastElement == maxOne)
                    occurrence++;
                else {
                    lastElement = maxOne;
                    occurrence = 1;
                }
            }
        }

        return ans;
    }
};