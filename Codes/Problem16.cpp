#include <iostream>
#include <string>
using namespace std;

#define MAX 100000

int myMultiply(int x, int res[], int res_size) {
    int carry = 0;

    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}

string myPower(int x, int n) {
    string result;
    int res[MAX];
    int res_size = 0;
    int temp = x;

    if (n == 0) {
        result.append(1, '1');
        return result;
    }

    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp /= 10;
    }

    for (int i = 2; i <= n; i++) {
        res_size = myMultiply(x, res, res_size);
    }

    cout << x << "^" << n << " = ";
    for (int i = res_size - 1; i >= 0; i--) {
        result.append(1, res[i] + '0');
    }

    return result;
}

int main() {
    int exp = 1000;
    int base = 2;
    unsigned long long int sum = 0;
    string ans;
    
    ans = myPower(base, exp);

    cout << ans << endl;

    for (int i = 0; i < ans.length(); i++) {
        sum += ans[i] - '0';
    }

    cout << sum << endl;

    return 0;
}