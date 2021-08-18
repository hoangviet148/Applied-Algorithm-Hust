// CPP program to find (a^b) % MOD where a and
#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
const ull MOD = 1000000007;

// Returns modulo exponentiation for two numbers
// represented as long long int. It is used by
// powerStrings(). Its complexity is log(n)
ull powerLL(ull x, ull n)
{
    ull result = 1;
    while (n) {
        if (n & 1)
            result = result * x % MOD;
        n = n / 2;
        x = x * x % MOD;
    }
    return result;
}

int main()
{
    ull a, b;
    cin >> a >>b;
    a %= MOD;
    b %= MOD - 1;
    cout << powerLL(a, b);
    return 0;
}
