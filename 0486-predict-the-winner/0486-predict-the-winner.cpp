class Solution {
   public:
       bool dfs(int left , int right , int player1 , int player2 , char chance,
         vector<int>&nums){
          cout << left << " " << right << endl ; 
        if(left > right) return player1 >= player2;
        if(chance == '1')
        return dfs(left + 1 , right , player1 + nums[left] , player2 , '2' , nums)|| 
             dfs(left , right -1 , player1 + nums[right] , player2 , '2' ,nums);
        else return  dfs(left + 1 , right , player1 , player2 + nums[left] , '1', nums)&& 
             dfs(left , right -1 , player1 , nums[right] + player2 , '1' ,nums); 
       }
    bool predictTheWinner(vector<int>& nums) {
      // if(nums.size ==1 ) return true ; 
       return dfs(0 , nums.size()-1 , 0 , 0 , '1' , nums );  
    }
};