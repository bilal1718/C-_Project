#include <iostream>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Function for modular exponentiation
int modExp(int base, int exponent, int mod) {
    int result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int num1 = 17;
    int num2 = 13;
    int n = num1 * num2;
    int euler = (num1 - 1) * (num2 - 1);
    int message = 10;
    int e = 5; // Public exponent

    // Check if e is coprime to euler
    if (gcd(e, euler) != 1) {
        cout << "These numbers cannot match with RSA conditions." << endl;
        return 1;
    }

    // Encryption
    int encryptedMessage = modExp(message, e, n);
    cout << "Encrypted message: " << encryptedMessage << endl;

    return 0;
}
