#include <iostream>
#include <string>
using namespace std;
string encryptCaesarCipher(const string& password, int shift) {
    string encryptedPassword;

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
string decryptCaesarCipher(const string password, int shift) {
    string encryptedPassword = "";

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
void selection(int choice,string password,int shift){
    string mode;
    cout << "Select the mode: (1) for encryption, (2) for decryption "<<endl;
    cout << "Enter your choice: ";
    cin>>choice;
    switch (choice)
    {
    case 1:
        mode = encryptCaesarCipher(password, shift);
        break;
    case 2:
        mode = decryptCaesarCipher(password, shift);
        break;
    default:
        cout << "Invalid Number: Please try again";
        break;
    }
    string word=(choice==1) ? " Encryption: ":" Decryption: ";
     cout << "Generate" << word << mode << endl;
}

int main() {
    int choice;
    cout << "Enter your password: ";
    string password;
    getline(cin, password);
    int shift = 3;
    selection(choice,password,shift);
    return 0;
}
