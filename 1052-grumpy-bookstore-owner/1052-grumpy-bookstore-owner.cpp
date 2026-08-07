class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int i = 0;
        int j = 0;
        int m = customers.size();
        int sum = 0;

  
        for (int index = 0; index < m; index++) {
            if (grumpy[index] == 0)
                sum += customers[index];
        }

  
        while (j < m && j < minutes) {
            if (grumpy[j] == 1)
                sum += customers[j];
            j++;
        }

        int Max = sum;

   
        for (int index = j; index < m; index++) {
            if (grumpy[i] == 1)
                sum -= customers[i];
            i++;

            if (grumpy[index] == 1)
                sum += customers[index];

            Max = max(Max, sum);
        }

        return Max;
    }
};