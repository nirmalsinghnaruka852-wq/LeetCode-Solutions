class Solution {
public:
    string removeOuterParentheses(string s) {
        int sum = 0;
        string ans = "";
        string result = "";

        for (int index = 0; index < s.size(); index++) {
            // cout<< index << endl ; 
            // sum = sum +  (s[index] == '(') ? +1 : -1;
            if(s[index] == '(') sum += 1 ;
            else sum -= 1 ; 
            // cout << sum << endl ; 
            if(sum == 1 && ans.size() == 0 ) continue  ; 
            else  ans += s[index];
            if(sum == 0 ){
                // cout << sum << endl ;
                cout << ans << endl ; 
                if(ans.size() > 2 ){  
                    ans.pop_back() ; 
                    result += ans ;}
                ans = "";
            }
        }
        return result;
    }
};

// you have to  remove the outer vaild parenthese ;
//  the given string is also vaild , the task is to retervie the vaild
//  parenthese from that ;

//  we can say whenever the sum become zero which the inside the string are
//  vaild ok ; and also the created new string length is greater then 2 then we
//  have to add that  else skip and start countg from new ;
