class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sol = 0;
        string str = to_string(n);
        int sod = 0;

        for (auto it : str) {
            if (it != '0') {
                sol = sol * 10 + (it - '0');
            }
            sod += (it - '0');
        }

        return sol * sod;
    }
};