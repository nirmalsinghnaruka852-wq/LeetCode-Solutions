class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum  = 0  ;
        string ans = "";
        string result = "";
        for(char ch : s){
            sum += (ch == '(') ? 1 : -1 ;
            if(ans.size() == 0 &&  sum == 1 ) continue ;
            else ans += ch ;
            if(sum == 0 ){
                ans.pop_back() ;
                 result += ans ;
                 ans = "";
            }
        }
        return result ; 
        
        
    }
};