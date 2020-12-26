#include <iostream>
#include <cmath>
using namespace std;

#define N 100000000
#define NUM 3   // NUM 번째 소수

int main() {
    int count_remainder = 0, count = 0;
    unsigned long long int ans;

    for (register int i = 1; i <= N; i++) {
        for (register int j = 1; j <= i; j++) {
            if (i % j == 0) {
                count_remainder++;
            }
        }
        if (count_remainder == 2) {
            count++;
            count_remainder = 0;
        }
        else {
            count_remainder = 0;
        }
        if (count == NUM) {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}