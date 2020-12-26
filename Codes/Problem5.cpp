#include <iostream>
#include <climits>
using namespace std;

#define N 30

int main() {
    unsigned long long int i, j, ans = 0;
    
    for (i = 0; i < ULLONG_MAX; i++) {   // unsigned long long int 최댓값까지
        for (j = 1; j <= N; j++) {
            if (i % j == 0) {
                if (j == N) {
                    ans = i;
                    break;
                }
            }
            else {
                break;
            }
        }
        if (ans != 0) {
            break;
        }
    }

    cout << ans << endl;
    
    return 0;
}

