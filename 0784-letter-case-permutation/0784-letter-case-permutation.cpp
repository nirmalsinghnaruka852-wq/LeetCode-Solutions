using vs = vector<string>;

class Solution {
public:
    vs result;
    string s1 ; 
    void generateAllPossibleVaildPermutation(int currentIndex, string& s) {
        if (currentIndex >= s.size()) {
            result.push_back(s1);
            return;
        }
        s1.push_back(s[currentIndex]);
        generateAllPossibleVaildPermutation(currentIndex + 1, s);
        s1.pop_back();
        if (('a' <= s[currentIndex] && s[currentIndex] <= 'z') ||
            ('A' <= s[currentIndex] && s[currentIndex] <= 'Z')) {
              cout << s[currentIndex] << endl ;
            if (islower(s[currentIndex]))
                 s1.push_back(char(s[currentIndex] - 32));
            else
                 s1.push_back(char(s[currentIndex] + 32));
                generateAllPossibleVaildPermutation(currentIndex + 1, s);
            s1.pop_back();
        }
        return;
    }
    vector<string> letterCasePermutation(string s) {
           
 generateAllPossibleVaildPermutation(0 , s );
        return result ;
    }
};