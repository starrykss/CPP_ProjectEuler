#include <iostream>
using namespace std;

long long num = 600851475143; // 입력받을 숫자
int k = 2;                    // 2부터 1씩 증가

int main() {
   while (num != 1) {
       if (num % k == 0) {
           // cout << k << " ";
           num /= k;   // Update
       }
       else {
           k++;
       }
   }

    cout << k << endl;
    
    return 0;
}