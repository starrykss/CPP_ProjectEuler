#include <iostream>
#include <cmath>
using namespace std;

#define N 500

int checkCommonDivisor(unsigned long long int n) {
    int count = 0;
    for (register int i = 1; i <= n; i++) {
        if (n % i == 0) {
            count++;
        }
    }
    return count;
}

// O(n^1/3)
int countDivisors(int n) {
    int count = 0;
    for (register int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i) {
                count++;
            }
            else {  // Otherwise count both
                count = count + 2;
            }
        }
    }
    return count;
}

int main() {
    int cnt = 0, n = 1, tripleNum = 0;
    
    while (1) {
        for (register int i = 1; i <= n; i++) {
            tripleNum += i;
        }
        cnt = countDivisors(tripleNum);
        cout << tripleNum << ": " << cnt << endl;
        if (cnt >= N) {
            break;
        }
        n++;
        tripleNum = 0;
    }
    
    cout << tripleNum << endl;

    return 0;
}

// 참고
// https://www.geeksforgeeks.org/count-divisors-n-on13/?