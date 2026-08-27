using vb = vector<bool>;

class Solution {
public:
    int count = 0;
    string ans;
    string s1;
    vb visited;
    int MaxNumber;
    int k;

    void generateKthPermutation() {
        if (s1.size() == MaxNumber) {
            count++;

            if (count == k)
                ans = s1;

            return;
        }

        for (int index = 1; index <= MaxNumber; index++) {
            if (visited[index])
                continue;

            visited[index] = true;

            s1 += char('0' + index);

            generateKthPermutation();

            s1.pop_back();

            visited[index] = false;

            if (ans.size() >= 1 )
                return;
        }
    }

    string getPermutation(int n, int k) {
        MaxNumber = n;
        this->k = k;

        visited.assign(n + 1, false);

        generateKthPermutation();

        return ans;
    }
};