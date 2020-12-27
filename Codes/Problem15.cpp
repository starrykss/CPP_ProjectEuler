#include <iostream>
#include <iomanip>  //setw()
using namespace std;

#define SIZE 20     // 20 x 20
#define WIDTH 11    // 출력 너비

int main() {
    unsigned long long int ary[SIZE + 1][SIZE + 1] = {0};

    for (int i = 1; i <= SIZE; i++) {
        ary[0][i] = 1;
        ary[i][0] = 1;
    }

    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= SIZE; j++) {
            ary[i][j] = ary[i - 1][j] + ary[i][j - 1];
        }
    }

    // 출력
    for (int i = 0; i <= SIZE; i++) {
        for (int j = 0; j <= SIZE; j++) {
            cout << setw(WIDTH) << ary[i][j] << " ";
        }
        cout << endl;
    }

    cout << ary[SIZE][SIZE] << endl;

    return 0;
}