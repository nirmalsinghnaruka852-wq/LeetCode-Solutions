class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0;
        int j = 0;
        int totalVol = 0;
        while (j < s.size() && j < k) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
                s[j] == 'u')
                totalVol++;
            j++;
        }
        int Max = totalVol;
        for (int index = k; index < s.size(); index++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                s[i] == 'u')
                totalVol--;
            i++;
            if (s[index] == 'a' || s[index] == 'e' || s[index] == 'i' || s[index] == 'o' ||
                s[index] == 'u')
                totalVol++;
            Max = max(Max , totalVol);    
        }
        return Max ; 
    }
};