#include <iostream>
using namespace std;

#define N 1000000

long long slow_hailstone(long long num) {
    long long n, count = 0, max = 0, ans = 0;

    for (register long long i = 1; i <= num; i++) {
        n = i;
        while (n != 1) {
            count++;
            (n % 2 == 0) ? (n /= 2) : (n = (3 * n + 1));
        } 
        if (max < count) {  // 최댓값 갱신
            max = count;
            ans = i;
            cout << ans << ": " << max << endl;   // 출력
        }
        count = 0;
    }

    return max;
}

long long fast_hailstone(long long num) {
    long long i, n, count = 0, max = 0, ans = 0;

    i = 1;
    n = 1;
    while (i <= num) {
        while (i != 1) {
            count++;
            (i % 2 == 0) ? (i /= 2) : (i = (3 * i + 1));
        }
        if (max < count) {
            max = count;
            ans = n;
            cout << ans << ": " << max << endl;   // 출력
        }
        
        count = 0;
        i += n;
        n++;
    }

    return ans;
}

int main() {
    cout << slow_hailstone(N) << endl;

    return 0;
}

// long long 자료형으로 선언하지 않을 경우 113383에서 멈춤.

/* 
long long hailstone(long long n) {
    int count = 0;

    while (n != 1) {
        count++;
        (n % 2 == 0) ? (n = n / 2) : (n = (3 * n + 1));
    } 
    return count;
}

int main() {
    long long count = 0, max = 0, ans = 0;

    for (register long long i = 1; i <= N; i++) {
        count = hailstone(i);
        cout << i << ": " << count << endl;
        if (max < count) {  // 최댓값 갱신
            max = count;
            ans = i;
        }
    }

    cout << ans << ": " << max << endl;

    return 0;
} 
*/