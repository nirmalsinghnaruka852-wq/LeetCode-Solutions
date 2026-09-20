class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0 ; 
        for(int index = 0 ; index < s.size() ; index++){
          sum += (index+1) * (26 - (s[index] - 'a'));
        }
        return sum ; 
    }
};
//  how u can reverse degree like this kind of question 
