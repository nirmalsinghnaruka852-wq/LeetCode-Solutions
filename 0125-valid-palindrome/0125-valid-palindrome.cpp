class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;
        while (i <= j) {
            if (((s[i] >= 'a' && s[i] <= 'z' ) ||
                 (s[i] >= '0' && s[i] <= '9' ) ||
                 (s[i] >= 'A' && s[i] <= 'Z')) &&
                ((s[j] >= 'a' && s[j] <= 'z') ||
                (s[j] >= '0' && s[j] <= '9' ) ||
                 (s[j] >= 'A' && s[j] <= 'Z'))) {
                if (tolower(s[i]) != tolower(s[j]))
                    return false;
                i++;
                j--;
            } else if ((s[i] >= 'a' && s[i] <= 'z') ||
                       (s[i] >= 'A' && s[i] <= 'Z') || 
                       (s[i] >= '0' && s[i] <= '9' )  )
                j--;
            else
                i++;
        }
        return true;
    }
};