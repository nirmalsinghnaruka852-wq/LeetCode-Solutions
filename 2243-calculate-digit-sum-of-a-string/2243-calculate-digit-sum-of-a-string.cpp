class Solution {
public:
    string digitSum(string s, int k) {
    // start 
    string ans = s ;
    while(ans.size() > k ){
        int sum = 0 ;
        string result = "";
        for(int index = 0 ; index < ans.size() ; index++){
            int number = ans[index]- '0';
            cout << number << endl; 
           sum += number ;
           if((index+1) %k == 0 || index == ans.size()-1 ){
             result += to_string(sum);
               sum =0 ; 
           }
           
        }

        // cout << result << endl ; 
        ans = result;
    }
    return ans ; 
    }
};