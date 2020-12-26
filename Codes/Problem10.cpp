#include <iostream>
using namespace std;

#define N 2000000

bool isPrimeNum(int n);

int main() {
    unsigned long long int sum = 0;

    for (register int i = 2; i <= N; i++) {
        if (isPrimeNum(i) == true) {
            sum += i;
            cout << i << endl;
        }
    }

    cout << sum << endl;

    return 0;
}

bool isPrimeNum(int n) {
    for (int i = 2; i < n; i++) {
        if ((n % i == 0) && (n != i)) {
            return false;
        }
    }
    return true;
}