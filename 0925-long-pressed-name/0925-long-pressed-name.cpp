class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0 ; 
        int j = 0 ;
        int m = name.size()  ;
        int n = typed.size();
        while(i <  m && j < n && name[i] == typed[j]){
        int counti = 0 ;
        int countj = 0 ;
        char ch = name[i];
        while(i < m  && ch == name[i]){
          i++ ;
          counti++ ; 
        }
        while(j <n && ch == typed[j]){
          j++ ;
          countj++ ; 
        }
        if(counti > countj) return false ; }
        cout<<  m << " "<< i << endl ; 
        cout << n << " " << j ;
        return i == m && j == n ; 
    }
};
//  for an charter fequency must same not the lesser then ok ; 