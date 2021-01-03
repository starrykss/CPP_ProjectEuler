#include <iostream>
using namespace std;

#define SIZE 1000

enum { 
    ONE = 1,     TWO = 2,     THREE = 3,     FOUR = 4,      FIVE = 5,     SIX = 6,      SEVEN = 7,      EIGHT = 8,     NINE = 9,        TEN = 10,
    ELEVEN = 11, TWELVE = 12, THIRTEEN = 13, FOURTEEN = 14, FIFTEEN = 15, SIXTEEN = 16, SEVENTEEN = 17, EIGHTEEN = 18, NINETEEN = 19,   TWENTY = 20,
    THIRTY = 30, FORTY = 40,  FIFTY = 50,    SIXTY = 60,    SEVENTY = 70, EIGHTY = 80,  NINETY = 90,    HUNDRED = 100, THOUSAND = 1000, AND = 3 
};

int main () {
    int ary[SIZE + 1] = {0};
    ary[0] = 0,         ary[ONE] = 3;        ary[TWO] = 3;        ary[THREE] = 5;      ary[FOUR] = 4;       ary[FIVE] = 4; 
    ary[SIX] = 3;       ary[SEVEN] = 5;      ary[EIGHT] = 5;      ary[NINE] = 4;       ary[TEN] = 3;        ary[ELEVEN] = 6;
    ary[TWELVE] = 6;    ary[THIRTEEN] = 8;   ary[FOURTEEN] = 8;   ary[FIFTEEN] = 7;    ary[SIXTEEN] = 7;    ary[SEVENTEEN] = 9;
    ary[EIGHTEEN] = 8;  ary[NINETEEN] = 8;   ary[TWENTY] = 6;     ary[THIRTY] = 6;     ary[FORTY] = 5;      ary[FIFTY] = 5;     
    ary[SIXTY] = 5;     ary[SEVENTY] = 7;    ary[EIGHTY] = 6;     ary[NINETY] = 6;     ary[HUNDRED] = 7;    ary[THOUSAND] = 8;
    int sum = 0;

    for (int i = 1; i <= SIZE; i++) {
        if (i >= ONE && i <= TEN) {
            sum += ary[i];
            // cout << i << " " << i << " " << sum << endl;
        }
        else if (i > TEN && i < HUNDRED) {
            if (i >= 11 && i < 20) {
                sum += ary[i];                                  // 10의 자리 + 1의 자리
            }
            else {
                if (i % 10 == 0) {
                    sum += ary[(i / 10) * 10];                  // 10의 자리
                }
                else {
                    sum += ary[(i / 10) * 10];                  // 10의 자리
                    sum += ary[i % 10];                         // 1의 자리
                }
            }
            // cout << i << " " << (i / 10) * 10 << i % 10 << " " << sum << endl;
        }
        else if (i >= HUNDRED && i < THOUSAND) {
            if (i % 100 == 0) {
                sum += ary[i / 100];                            // 100의 자리
                sum += ary[100];                                // HUNDRED
            }
            else {
                sum += ary[i / 100];                            // 100의 자리
                sum += ary[100];                                // HUNDRED
                sum += AND;                                     // AND

                if ((i % 100) >= 1 && (i % 100) < 10) {
                    sum += ary[i % 10];                         // 1의 자리
                }
                else if ((i % 100) >= 10 && (i % 100) < 20) {
                    sum += ary[i % 100];                        // 10의 자리 + 1의 자리
                }
                else {
                    sum += ary[((i % 100) / 10) * 10];          // 10의 자리
                    sum += ary[i % 10];                         // 1의 자리
                }
            }
            // cout << i << " " << i / 100 << ((i % 100) / 10) * 10 << i % 10 << " " << sum << endl;
        }
        else {
            sum += ary[i / 1000];                               // 1000의 자리
            sum += ary[i];                                      // THOUSAND
            //cout << i << " " << 1000 << " " << sum << endl;
        }
    }

    cout << sum << endl;

    return 0;
}