#include <iostream>
using namespace std;

#define MAX_NUM 1000

int main() {
    int sum = 0;
    
    for (int i = 1; i < MAX_NUM; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}