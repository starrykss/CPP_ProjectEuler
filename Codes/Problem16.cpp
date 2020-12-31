#include <iostream>
#include <string>
using namespace std;

#define MAX 100000

int myMultiply(int x, int res[], int res_size) {
    int carry = 0;

    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry) {
        res[res_size] = carry % 10;
        carry /= 10;
        res_size++;
    }
    return res_size;
}

string myPower(int x, int n) {
    string result;
    int res[MAX];
    int res_size = 0;
    int temp = x;

    if (n == 0) {
        result.append(1, '1');
        return result;
    }

    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp /= 10;
    }

    for (int i = 2; i <= n; i++) {
        res_size = myMultiply(x, res, res_size);
    }

    cout << x << "^" << n << " = ";
    for (int i = res_size - 1; i >= 0; i--) {
        result.append(1, res[i] + '0');
    }

    return result;
}

int main() {
    int exp = 1000;
    int base = 2;
    unsigned long long int sum = 0;
    string ans;
    
    ans = myPower(base, exp);

    cout << ans << endl;

    for (int i = 0; i < ans.length(); i++) {
        sum += ans[i] - '0';
    }

    cout << sum << endl;

    return 0;
}
































// [참고] https://www.geeksforgeeks.org/writing-power-function-for-large-numbers/?
/*
#include <iostream>
using namespace std;
 
// Maximum number of digits in 
// output
#define MAX 100000
 
// This function multiplies x
// with the number represented by res[].
// res_size is size of res[] or
// number of digits in the number
// represented by res[]. This function
// uses simple school mathematics
// for multiplication.
// This function may value of res_size
// and returns the new value of res_size
int multiply(int x, int res[], int res_size) {
 
// Initialize carry
int carry = 0;
 
// One by one multiply n with
// individual digits of res[]
for (int i = 0; i < res_size; i++) {
    int prod = res[i] * x + carry;
 
    // Store last digit of
    // 'prod' in res[]
    res[i] = prod % 10;
 
    // Put rest in carry
    carry = prod / 10;
}
 
// Put carry in res and
// increase result size
while (carry) {
    res[res_size] = carry % 10;
    carry = carry / 10;
    res_size++;
}
return res_size;
}
 
// This function finds
// power of a number x
void power(int x, int n) 
{
    
    //printing value "1" for power = 0
    if(n == 0 ){ 
        cout<<"1";
        return;
    }
    
    
    int res[MAX];
    int res_size = 0;
    int temp = x;
    
    // Initialize result
    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp = temp / 10;
    }
    
    // Multiply x n times
    // (x^n = x*x*x....n times)
    for (int i = 2; i <= n; i++)
        res_size = multiply(x, res, res_size);
    
    cout << x << "^" << n << " = ";
    for (int i = res_size - 1; i >= 0; i--) {
        cout << res[i];
    }
}
 
// Driver program
int main() {
    int exponent = 1000;
    int base = 2;

    power(base, exponent);
    return 0;
}

/*
// [참고] https://www.geeksforgeeks.org/multiply-large-numbers-represented-as-strings/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define N 1000  // 지수

string multiply(string num1, string num2) 
{ 
    int len1 = num1.size(); 
    int len2 = num2.size(); 
    if (len1 == 0 || len2 == 0) 
    return "0"; 
  
    // will keep the result number in vector 
    // in reverse order 
    vector<int> result(len1 + len2, 0); 
  
    // Below two indexes are used to find positions 
    // in result.  
    int i_n1 = 0;  
    int i_n2 = 0;  
      
    // Go from right to left in num1 
    for (int i=len1-1; i>=0; i--) 
    { 
        int carry = 0; 
        int n1 = num1[i] - '0'; 
  
        // To shift position to left after every 
        // multiplication of a digit in num2 
        i_n2 = 0;  
          
        // Go from right to left in num2              
        for (int j=len2-1; j>=0; j--) 
        { 
            // Take current digit of second number 
            int n2 = num2[j] - '0'; 
  
            // Multiply with current digit of first number 
            // and add result to previously stored result 
            // at current position.  
            int sum = n1*n2 + result[i_n1 + i_n2] + carry; 
  
            // Carry for next iteration 
            carry = sum/10; 
  
            // Store result 
            result[i_n1 + i_n2] = sum % 10; 
  
            i_n2++; 
        } 
  
        // store carry in next cell 
        if (carry > 0) 
            result[i_n1 + i_n2] += carry; 
  
        // To shift position to left after every 
        // multiplication of a digit in num1. 
        i_n1++; 
    } 
  
    // ignore '0's from the right 
    int i = result.size() - 1; 
    while (i>=0 && result[i] == 0) 
    i--; 
  
    // If all were '0's - means either both or 
    // one of num1 or num2 were '0' 
    if (i == -1) 
    return "0"; 
  
    // generate the result string 
    string s = ""; 
      
    while (i >= 0) 
        s += std::to_string(result[i--]); 
  
    return s; 
} 


int main() {
    string ans = "2", num1 = "2", num2 = "2";

    for (int i = 1; i < N; i++) {
        ans = multiply(ans, num2);
    }

    cout << ans << endl;
    

    return 0;
}
*/