class Solution {
public:
    int firstUniqChar(string s) {
       vector<int>count(26,0);
       for(int index = 0 ; index <s.size() ; index++){
        //  cout << (s[index]-'0');
            count[s[index]-'a']++;
       } 
       for(int index = 0 ; index <s.size() ; index++){
          if(count[s[index] -'a'] == 1 ) return index;   
       } 
       return -1;
    }
};