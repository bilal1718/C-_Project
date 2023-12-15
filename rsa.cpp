#include <iostream>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Function to get prime number from the user
int getPrimeFromUser(const string& prompt) {
    int num;
    do {
        cout << prompt;
        cin >> num;
        if (!isPrime(num)) {
            cout << "Please enter a prime number." << endl;
        }
    } while (!isPrime(num));
    return num;
}

// Function to calculate the Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function for modular exponentiation
int modExp(int base, int exponent, int mod) {
    int result = 1;
    base %= mod;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent /= 2;
        base = (base * base) % mod;
    }
    return result;
}

// Function for RSA Encryption
int rsaEncrypt(int message, int e, int n) {
    return modExp(message, e, n);
}

// Function for RSA Decryption
int rsaDecrypt(int encryptedMessage, int d, int n) {
    return modExp(encryptedMessage, d, n);
}

int main() {
    int num1 = getPrimeFromUser("Enter the first prime number: ");
    int num2 = getPrimeFromUser("Enter the second prime number: ");

    int n = num1 * num2;
    int euler = (num1 - 1) * (num2 - 1);

    int message, e, d;
    cout << "Enter the message to be encrypted: ";
    cin >> message;

    // Choose e such that it is coprime to euler
    do {
        cout << "Enter a value for e (coprime to " << euler << "): ";
        cin >> e;
    } while (gcd(e, euler) != 1);

    // Calculate d such that (d * e) % euler = 1
    d = 1;
    while ((d * e) % euler != 1) {
        d++;
    }

    // Encryption and Decryption
    int encryptedMessage = rsaEncrypt(message, e, n);
    int decryptedMessage = rsaDecrypt(encryptedMessage, d, n);

    // Display results
    cout << "Encrypted message: " << encryptedMessage << endl;
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
