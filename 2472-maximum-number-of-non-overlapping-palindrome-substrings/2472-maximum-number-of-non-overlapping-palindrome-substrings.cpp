using vi = vector<int>;
using vvi = vector<vi>;
using vb = vector<bool>;
using vvb = vector<vb>;

class Solution{
    public : 
     vi dp ;
     vvb Palidram ; 

    bool isPalidram(int i , int j ){
    return Palidram[i][j];
}
void putValuesInDp(string &s) {
    int n = s.size();

    for (int i = 0; i < n; i++) {
        Palidram[i][i] = true;
    }

    for (int length = 1; length < n; length++) {
        for (int start = 0; start < n; start++) {
            int end = start + length;

            if (end >= n) break;

            if (s[start] == s[end]) {
                if (length == 1)
                    Palidram[start][end] = true;
                else
                    Palidram[start][end] = Palidram[start + 1][end - 1];
            }
        }
    }
    return ; 
}
int dfs(int currentIndex , string& s , int k  ){
    if(currentIndex >= s.size()  ) return 0 ;
    else if(dp[currentIndex ] != -1 ) return dp[currentIndex];
    // skip call ;
    int ans = dfs(currentIndex+ 1 , s , k);
    for(int index = currentIndex ; index < s.size() ; index++ ){
        if(isPalidram(currentIndex , index)&& (index - currentIndex + 1 )>= k )
          ans = max(ans , 1+ dfs(index+1 , s , k));
    } 
    return dp[currentIndex] = ans ; 
}
    int maxPalindromes(string s, int k) {
         int n = s.size() ; 
         dp.resize(n, -1 );
         Palidram.resize(n , vb(n, false ));
         putValuesInDp(s);
      return dfs(0 , s , k );
    }

};

