#include <iostream>
using namespace std;

#define MAX_NUM 4000000

int main() {
    int value1 = 1, value2 = 2, sum = 0;

    while (1) {
        if (value2 <= MAX_NUM) {  // 4백만 이하
            if (value2 % 2 == 0) {
                sum += value2;
            }
            // 업데이트
            int tmp = value2;
            value2 += value1;
            value1 = tmp;
        }
        else {
            break;
        }
    }

    cout << sum << endl;

    return 0;
}

/*
int main() {
    int firstValue = 1, secondValue = 2, sum = 0;

    while (secondValue <= MAX_NUM) {
        if (secondValue % 2 == 0) {
            sum += secondValue;
        }

        // Update (SecValue <- FirValue + SecValue)
        int tmp = secondValue;
        secondValue += firstValue;
        firstValue = tmp;
    }

    cout << sum << endl;

    return 0;
}
*/