#include <iostream>
#include <cmath>
using namespace std;

#define N 100

int main() {
    int numOfSum = 0, numOfTimes = 0, ans;

    for (int i = 1; i <= N; i++) {
        numOfSum += i;
        numOfTimes += pow(i, 2);
    }
    numOfSum *= numOfSum;

    ans = abs(numOfSum - numOfTimes);
    cout << ans << endl;

    return 0;
}