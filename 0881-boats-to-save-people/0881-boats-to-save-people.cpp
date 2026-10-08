class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int boat = 0;
        int i = 0;
        int j = people.size() - 1;
        while (i <= j) {
            if(i == j ) return boat+1 ;  
            else if (people[i] + people[j] <= limit) {
                i++;
                j--;
                boat++;
            } else {
                j--;
                boat++;
            }
        }
        if(i == j ) boat++ ;

        return boat;
    }
};