using vc = vector<char>;
using vs = vector<string>;
class Solution {
public:
    string s ;
    vs result ;
    void generatePhoneCombinations(int startIndex , string digits , map<int , vc>&mp ){
      // cout<< '1' << endl ; 
      if(startIndex >= digits.size() ){
        cout << s << endl ; 
        result.push_back(s);
        return ; 
      }
      // cout<< '1' << endl ; 
      for(char ch : mp[digits[startIndex]- '0']){
        // cout << ch << endl ;
        s += ch ;
        generatePhoneCombinations(startIndex +1 , digits , mp);
        s.pop_back() ; 
      }
      return ; 
    }
    
    vector<string> letterCombinations(string digits) {
        map<int, vc> mp;
        mp[2] = vector<char>{'a', 'b', 'c'};
        mp[3] = vector<char>{'d', 'e', 'f'};
        mp[4] = vector<char>{'g', 'h', 'i'};
        mp[5] = vector<char>{'j', 'k', 'l'};
        mp[6] = vector<char>{'m', 'n', 'o'};
        mp[7] = vector<char>{'p', 'q', 'r', 's'};
        mp[8] = vector<char>{'t', 'u', 'v'};
        mp[9] = vector<char>{'w', 'x', 'y', 'z'};


        generatePhoneCombinations(0 , digits , mp );
        return result ; 
    }
};