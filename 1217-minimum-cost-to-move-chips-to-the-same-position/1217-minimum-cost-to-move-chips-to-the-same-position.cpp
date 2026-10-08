class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int MinOneCost = INT_MAX ;
        for(int i = 0 ; i < position.size() ; i++  ){
            int cost = 0 ;
         for(int j = 0 ; j < position.size() ; j++  ){
            //  if both are at the same position 
             if(position[i] == position[j]) continue ;
             cost += abs(position[i] - position[j]) % 2 ;
        }
          MinOneCost = min(MinOneCost , cost );
          
        }
        return MinOneCost ; 
    }
};