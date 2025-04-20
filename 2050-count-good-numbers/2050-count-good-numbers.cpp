class Solution {
public:
    const int MOD = 1e9 + 7;

    long long power(long long x, long long n) {
        long long res = 1;
        while (n > 0) {
            if (n % 2 == 1)
                res = (res * x) % MOD;
            x = (x * x) % MOD;
            n /= 2;
        }
        return res;
    }

    int countGoodNumbers(long long n) {
        long long evenCount = (n + 1) / 2;
        long long oddCount = n / 2;
        long long result = (power(5, evenCount) * power(4, oddCount)) % MOD;
        return result;
    }
};
