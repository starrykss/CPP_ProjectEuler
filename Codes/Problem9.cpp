#include <iostream>
using namespace std;

#define N 1000
#define NUM 1000

int main() {
    int x, y, z, ans;

    for (register int a = 1; a <= N; a++) {
        for (register int b = a + 1; b <= N; b++) {
            for (register int c =  b + 1; c <= N; c++) {
                if ((a * a) + (b * b) == (c * c)) {
                    if ((a + b + c) == NUM) {
                        cout << a << " " << b << " " << c << endl;
                        ans = a * b * c;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}