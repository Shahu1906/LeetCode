class Solution {
public:
    bool checkDivisibility(int n) {
        long long product = 1, sum = 0;
        int r = n;
        while (r > 0) {
            int digit = r % 10;
            sum += digit;
            product *= digit;
            r = r / 10;
        }
        sum += product;
        if (n % sum == 0)
            return true;
        return false;
    }
};