class Node{
    public : 
    char character ;
    int Occuerence ;
    Node(char character , int Occuerence ) : character(character) ,Occuerence(Occuerence){}
};
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<Node*>st ;
        for(int index =0 ; index < s.size() ; index++ ){
            char ch = s[index];
            if(!st.empty() && st.top()->character == ch)
                st.top()->Occuerence++ ;
            else st.push(new Node(ch  ,  1 ));
            if(st.top()->Occuerence == k) st.pop() ; 
        }
         string ans = ""; 
        while(!st.empty()){
          while(st.top()->Occuerence != 0 ){
            ans += st.top()->character ;
            st.top()->Occuerence-- ; 
          }
          st.pop() ;   
        }
        reverse(ans.begin() , ans.end() );
        return ans ; 
    }
};