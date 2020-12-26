#include <iostream>
#include <string> // to_string()
#include <cmath>  // pow()
using namespace std;

#define DIGITS 3   // DIGITS 자리 수를 곱해 만들 수 있는 가장 큰 대칭수 

bool findPalindrome(string ary);

int main() {
    int firstNum, secondNum, sum = 0;
    bool palindrome = true;

    for (int i = pow(10, DIGITS - 1); i < pow(10, DIGITS); i++) {
        for (int j = pow(10, DIGITS - 1); j < pow(10, DIGITS); j++) {
            if (findPalindrome(to_string(i * j))) {
                if (sum < i * j) {  // 최댓값 찾기
                    sum = i * j;
                    firstNum = i;
                    secondNum = j;
                }
            }
        }
    }
    cout << firstNum << " * " << secondNum << " = " << sum;

    return 0;
}

bool findPalindrome(string ary) {
    bool isSame = true;
    for (int i = 0; i < ary.length(); i++) {
        if (ary[i] == ary[ary.length() - 1 - i]) {
            continue;
        }
        else {
            isSame = false;
        }
    }
    return isSame;
}