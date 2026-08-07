class Solution {
public:
    struct Factors {
        int two = 0;
        int three = 0;
        int five = 0;
        int seven = 0;
    };

    struct Contribution {
        int two;
        int three;
        int five;
        int seven;
    };

    Contribution digitFactor[10] = {
        {0,0,0,0}, // 0
        {0,0,0,0}, // 1
        {1,0,0,0}, // 2
        {0,1,0,0}, // 3
        {2,0,0,0}, // 4
        {0,0,1,0}, // 5
        {1,1,0,0}, // 6
        {0,0,0,1}, // 7
        {3,0,0,0}, // 8
        {0,2,0,0}  // 9
    };

    bool factorize(long long t, Factors &f) {
        while (t % 2 == 0) {
            f.two++;
            t /= 2;
        }

        while (t % 3 == 0) {
            f.three++;
            t /= 3;
        }

        while (t % 5 == 0) {
            f.five++;
            t /= 5;
        }

        while (t % 7 == 0) {
            f.seven++;
            t /= 7;
        }

        return t == 1;
    }

    void useDigit(int digit, Factors &need) {
        need.two = max(0, need.two - digitFactor[digit].two);
        need.three = max(0, need.three - digitFactor[digit].three);
        need.five = max(0, need.five - digitFactor[digit].five);
        need.seven = max(0, need.seven - digitFactor[digit].seven);
    }

    // Minimum number of digits needed to satisfy remain
    int minDigits(Factors f) {
        int ans = f.five + f.seven;

        // Use 8 for groups of three 2s
        ans += f.two / 3;
        f.two %= 3;

        // Use 9 for groups of two 3s
        ans += f.three / 2;
        f.three %= 2;

        // Remaining factors
        if (f.two == 0 && f.three == 0) {
            return ans;
        }

        if (f.two == 1 && f.three == 1) {
            // 2 * 3 = 6
            ans += 1;
        }
        else if (f.two == 2 && f.three == 1) {
            // 2^2 * 3 = 4 * 3 -> needs 2 digits
            ans += 2;
        }
        else {
            // remaining 2s or 3s
            ans += (f.two > 0);
            ans += (f.three > 0);
        }

        return ans;
    }

    bool canFill(int slots, Factors remain) {
        return minDigits(remain) <= slots;
    }

    string buildSuffix(int slots, Factors remain) {
        string suffix;

        while (slots > 0) {
            for (int d = 1; d <= 9; d++) {
                Factors temp = remain;
                useDigit(d, temp);

                if (canFill(slots - 1, temp)) {
                    suffix += char('0' + d);
                    remain = temp;
                    break;
                }
            }

            slots--;
        }

        return suffix;
    }

    string smallestNumber(string num, long long t) {
        Factors need;

        // t contains some prime other than 2,3,5,7
        if (!factorize(t, need))
            return "-1";

        int n = num.size();

        // prefixNeed[i] = factors still needed after num[0...i-1]
        vector<Factors> prefixNeed(n + 1);
        prefixNeed[0] = need;

        int firstZero = n;

        for (int i = 0; i < n; i++) {
            prefixNeed[i + 1] = prefixNeed[i];

            if (num[i] == '0') {
                firstZero = min(firstZero, i);
            } else {
                useDigit(num[i] - '0', prefixNeed[i + 1]);
            }
        }

        // num itself is already valid
        if (firstZero == n && canFill(0, prefixNeed[n])) {
            return num;
        }

        /*
            Try changing a digit from right to left.

            Example:
                num = 1234

            Try:
                1235...
                124...
                13...
                2...

            First valid answer found while going right -> left
            gives smallest number >= num.
        */
        for (int i = n - 1; i >= 0; i--) {

            // If there was a zero before i, keeping that prefix is impossible
            if (i > firstZero)
                continue;

            int current = num[i] - '0';

            for (int d = current + 1; d <= 9; d++) {
                Factors remain = prefixNeed[i];

                useDigit(d, remain);

                int slots = n - i - 1;

                if (canFill(slots, remain)) {
                    string ans = num.substr(0, i);

                    ans += char('0' + d);

                    ans += buildSuffix(slots, remain);

                    return ans;
                }
            }
        }

        /*
            No answer with same length.

            Build a number with more digits.
        */
        int len = n + 1;

        // At most a few extra digits are required because
        // t <= 1e14.
        while (!canFill(len, need))
            len++;

        return buildSuffix(len, need);
    }
};