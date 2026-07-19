class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int , vector<int>>mp ;
        for(auto edge : edges ){
         if(mp.count(edge[0])) mp[edge[0]].push_back(edge[1]);
         else mp[edge[0]] = {edge[1]};

         if(mp.count(edge[1])) mp[edge[1]].push_back(edge[0]);
         else mp[edge[1]] = {edge[0]};

        }
        
        for(auto [key , value ] : mp ){
          // cout << key << "->" ;
          cout << mp.size() << "-> "<< value.size()-1  << " " ; 
             if(mp.size()-1  == value.size() ) return key ;
        }
        return -1 ; 
    }
};
//  create the adj list and return element which have mp.size() == mp[index].size() 