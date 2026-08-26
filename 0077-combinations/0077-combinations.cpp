using vi = vector<int>;
using vvi = vector<vi>;
class Solution {
public:
     vi path ;
     vvi result ;
     void dfs(int currentNumber , int MaxNumber , int MaxSize ){
       if(path.size() == MaxSize){
        result.push_back(path);
        return  ;
       }
       for(int newNumber = currentNumber ; newNumber <= MaxNumber ; newNumber++ ){
        path.push_back(newNumber);
        dfs(newNumber+1 , MaxNumber , MaxSize);
        path.pop_back() ;
       }
       return ; 
}
    vector<vector<int>> combine(int n, int k) {
      dfs(1 , n , k);
       return result ;  
    }
};