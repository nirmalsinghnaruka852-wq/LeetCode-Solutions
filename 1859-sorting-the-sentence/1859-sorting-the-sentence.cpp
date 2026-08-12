class Solution {
public:
    string sortSentence(string s) {
        vector<string>ans(10 , "");
        string currString = "";
        for(char ch : s ){
          if(ch >='1' && ch <='9'){
            // get the index  
            int index = ch - '0';
            ans[index]= currString;
            cout<< currString << "-?" << endl ;
            currString ="";
            
          }else if(ch != ' '){
            currString += ch ;  
          }
          

        }
        string r = "";
         for(string s2 : ans){
          if(s2 == "") continue ;
           r += s2 + " "; 
         }  
         r.pop_back() ;
         return r ;
    }
};