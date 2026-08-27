using vs = vector<string>;
using vvs = vector<vs>;
class Solution {
public:
    vvs ans;
    vs Partition;
    bool vaild(string s ){
      int i = 0 ;
      int j = s.size() -1  ;
      while(i < j ){
        if(s[i] != s[j]) return false  ;
        i++ ;
        j-- ; 
      }
      return true ; 
    }
    void genrateAllPosiblePartition(int currentIndex, string s) {
        if (currentIndex >= s.size()) {
            ans.push_back(Partition);
            return;
        }
        string firstPart = "";
        for (int index = currentIndex; index < s.size(); index++) {
            firstPart += s[index];
            if (vaild(firstPart)) {
                Partition.push_back(firstPart);
                genrateAllPosiblePartition(index + 1, s);
                Partition.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        genrateAllPosiblePartition(0, s);
        return ans;
    }
};