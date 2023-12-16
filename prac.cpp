#include <iostream>
#include <string>
using namespace std;
string encryptCaesarCipher(const string& password, int shift,string encryptedPassword) {
    for (char ch : password) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encryptedChar = ((ch - base + shift) % 26 + 26) % 26 + base;
            encryptedPassword+=encryptedChar;
        } else {
            encryptedPassword+=ch;
        }
    }
    return encryptedPassword;
}
string decryptCaesarCipher(const string password, int shift,string encryptedPassword) {

    for (char ch : password) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char decryptedChar = ((ch - base - shift + 26) % 26 + 26) % 26 + base;
            encryptedPassword += decryptedChar;
        } else {
            encryptedPassword += ch;
        }
    }
    return encryptedPassword;
}
void selection(int choice,string password,int shift,string encryptedPassword){
    string mode;
    cout << "Select the mode: (1) for encryption, (2) for decryption "<<endl;
    cout << "Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        mode = encryptCaesarCipher(password, shift,encryptedPassword);
        break;
    case 2:
        mode = decryptCaesarCipher(password, shift,encryptedPassword);
        break;
    default:
        cout << "Invalid Number: Please try again";
        break;
    }
    string word=(choice==1) ? " Encryption: ":" Decryption: ";
      cout << "Generate" << word << mode;
}
int cipher(string characters,string encryptedPassword,int choice){
    // cout << "Enter your pssword: ";
    int shift = 3;
    selection(choice,characters,shift,encryptedPassword);
}
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
int rsa(int numbers,int encryptedMessage,int decryptedMessage,int choice){
    int num1 = 13;
    int num2 = 17;

    int n = num1 * num2;
    int euler = (num1 - 1) * (num2 - 1);

    int d;
    // int message;
    int e=5;
    // cout << "Enter the message to be encrypted: ";
    // cin >> message;

    // Choose e such that it is coprime to euler
    // do {
    //     cout << "Enter a value for e (coprime to " << euler << "): ";
    //     cin >> e;
    // } while (gcd(e, euler) != 1);

    // Calculate d such that (d * e) % euler = 1
    d = 1;
    while ((d * e) % euler != 1) {
        d++;
    }

    // Encryption and Decryption
    encryptedMessage = rsaEncrypt(numbers, e, n);
    decryptedMessage = rsaDecrypt(encryptedMessage, d, n);

    // Display results
    if(choice==1){
        return encryptedMessage;
    }else if(choice==2){
        return decryptedMessage;
    }   
}
int main() {
    int choice;
    string encryptedPassword;
    int encryptedMessage;
    int decryptedMessage;
    string password;
    string characters;
    string numbers;
    cout << "Enter your password: ";
    cin>>password;
    for(char ch:password){
        if(isalpha(ch)){
            characters +=ch;
        
        }else{
            numbers+=ch;  
        }
    }
    int message=stoi(numbers);
    cipher(characters,encryptedPassword,choice);
    // cout << rsa(message,encryptedMessage,decryptedMessage,choice);
    cout << rsa(message,encryptedMessage,decryptedMessage,choice);    
}
