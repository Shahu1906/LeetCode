class Solution {
public:
    int res(int n) {
        if (n == 0)
            return 0;
        int r = n;
        int product = 1;
        while (r != 0) {
            int digit = r % 10;
            product = product * digit;
            r /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int k = n;
        while (true) {
            if ((res(k) % t) == 0)
                return k;
            k++;
        }
        return 0;
    }
};