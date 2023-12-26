#include <iostream>
#include <string>
using namespace std;

// Caesar Cipher functions
string encryptCaesarCipher(const string& password, int shift) {
    string encryptedPassword = " ";

    for (char ch : password) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encryptedChar = ((ch - base + shift) % 26 + 26) % 26 + base;
            encryptedPassword += encryptedChar;
        } else {
            encryptedPassword +=ch;
        }
    }
    return encryptedPassword;
}

// Decrypts the encrypted number back into a string
string decryptCaesarCipher(const string& password, int shift) {
    string decryptPassword = " ";

    for (char ch : password) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char decryptedChar = ((ch - base - shift) % 26 + 26) % 26 + base;
            decryptPassword += decryptedChar;
        } else {
            decryptPassword +=ch;
        }
    }
    return decryptPassword;
}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

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

int rsaEncrypt(int encrptedMessage, int e, int n) {
    return modExp(encrptedMessage, e, n);
}

int rsaDecrypt(int decryptedMessage, int d, int n) {
    return modExp(decryptedMessage, d, n);
}

int main() {
    int privateKey;
    string encryptedMessage;
    int charValue;
    int rsaNew;
    int rsaNum;
    int rsaDecrypted;
    string message;
    int rsaMessage=0;
     string caesarDecrypted;
    string caesarResult;
    string rsaResult;
    int n1 = 29;
    int n2 = 23;
    int n = n1 * n2;
    int euler = (n1 - 1) * (n2 - 1);
    int e = 5;
    int d = 145;
    string encrptedMessage;
    string private_user1_msg;
    string private_user2_msg;
    const int maxMessages = 100;
    string public_user,private_user1,private_user2;
    cout << "Enter the public user name: ";
    cin >> public_user;
    cout << "Enter the first private user: ";
    cin>>private_user1;
    cout << "Enter the second private user: ";
    cin >> private_user2;
    int choice;
    string privateUser1Messages[maxMessages]={};
    string privateUser2Messages[maxMessages]={};
    int count=0;
    do{
    cout << "Contact List: " << endl;
    cout <<"\t 1- "<<private_user1 << endl;
    cout <<"\t 2- "<<private_user2 << endl;
    cout <<"\t 3- "<<"Chat History"<< endl;
    cout <<"\t 4- "<<"Exit"<< endl;
    cout << "With whom do you want to chat?" << endl;
    cin >> choice;
    cin.ignore();
    cout << endl;
    switch (choice)
    {
    case 1:
    cout << private_user1 << " , enter your private key (d): ";
    cin >> privateKey;
    cin.ignore();
    if(privateKey != d){
       cout << "You does not have a private key! ";
    }else{
    while(message != "bye" && private_user1_msg !="bye" && count < maxMessages){
        cout << "Enter a message to " << private_user1 << " : ";
        getline(cin,message);

        // RSA Encryption
        int rsaMessage=0;
       for (char ch : message) {
    int charValue = static_cast<int>(ch);
    rsaMessage += (charValue);
       }
        rsaNum = rsaEncrypt(rsaMessage, e, n);
        cout << "RSA Encryption: " << rsaNum << endl;

        // RSA Decryption
        rsaDecrypted = rsaDecrypt(rsaNum, d, n);
        cout << "RSA Decryption: " << rsaDecrypted << endl;

        // Caesar Cipher Encryption
        string encryptedMessage=encryptCaesarCipher(message,3);
        cout << "Caesar Cipher Encryption: " << encryptedMessage << endl;

        // Caesar Cipher Decryption
        string caesarDecrypted = decryptCaesarCipher(encryptedMessage, 3);
        cout << "Caesar Cipher Decryption: " << caesarDecrypted << endl;

        privateUser1Messages[count++] = message;
        cout << "\t \t \t \t \t \t \t Enter a reply to " << public_user << " : ";
        getline(cin,private_user1_msg);
        int rsaPrivate_user_Message=0;
       for (char ch : private_user1_msg) {
        int charValue = static_cast<int>(ch);
        rsaPrivate_user_Message += (charValue);
       }
       // RSA Encryption
       int rsa_private_Num = rsaEncrypt(rsaPrivate_user_Message, e, n);
        cout << "\t \t \t \t \t \t \t RSA Encryption: " << rsa_private_Num << endl;

        // RSA Decryption
        int rsa_private_user_Decrypted = rsaDecrypt(rsa_private_Num, d, n);
        cout << "\t \t \t \t \t \t \t RSA Decryption: " << rsa_private_user_Decrypted << endl;
        // Caesar Cipher Encryption for the reply
        string private_user_encryptedMessage=encryptCaesarCipher(private_user1_msg,3);
        cout << "\t \t \t \t \t \t \t Caesar Cipher Encryption: " << private_user_encryptedMessage << endl;

        // Caesar Cipher Decryption for the reply
        string private_user_caesarDecrypted = decryptCaesarCipher(private_user_encryptedMessage, 3);
        cout << "\t \t \t \t \t \t \t Caesar Cipher Decryption: " << private_user_caesarDecrypted << endl;

        privateUser1Messages[count++] = private_user1_msg;
    }
    }
        break;
        case 2:
        cout << private_user2 << " , enter your private key (d): ";
    cin >> privateKey;
    cin.ignore();
    if(privateKey != d){
       cout << "You does not have a private key! ";
    }else{
    while(message != "bye" && private_user2_msg !="bye" && count < maxMessages){
        cout << "Enter a message to " << private_user2 << " : ";
        getline(cin,message);

        // RSA Encryption
       for (char ch : message) {
       int charValue = static_cast<int>(ch);
       rsaMessage += (charValue);
       }
        rsaNum = rsaEncrypt(rsaMessage, e, n);
        cout << "RSA Encryption: " << rsaNum << endl;

        // RSA Decryption
        rsaDecrypted = rsaDecrypt(rsaNum, d, n);
        cout << "RSA Decryption: " << rsaDecrypted << endl;

        // Caesar Cipher Encryption
        encryptedMessage=encryptCaesarCipher(message,3);
        cout << "Caesar Cipher Encryption: " << encryptedMessage << endl;

        // Caesar Cipher Decryption
        caesarDecrypted = decryptCaesarCipher(encryptedMessage, 3);
        cout << "Caesar Cipher Decryption: " << caesarDecrypted << endl;

        privateUser1Messages[count++] = message;
        cout << "\t \t \t \t \t \t \t Enter a reply to " << public_user << " : ";
        getline(cin,private_user2_msg);
        int rsaPrivate_user_Message2=0;
       for (char ch : private_user2_msg) {
        int charValue = static_cast<int>(ch);
        rsaPrivate_user_Message2 += (charValue);
       }
       // RSA Encryption
       int rsa_private_Num2 = rsaEncrypt(rsaPrivate_user_Message2, e, n);
        cout << "\t \t \t \t \t \t \t RSA Encryption: " << rsa_private_Num2 << endl;

        // RSA Decryption
        int rsa_private_user_Decrypted = rsaDecrypt(rsa_private_Num2, d, n);
        cout << "\t \t \t \t \t \t \t RSA Decryption: " << rsa_private_user_Decrypted << endl;
        // Caesar Cipher Encryption for the reply
        string private_user_encryptedMessage2=encryptCaesarCipher(private_user2_msg,3);
        cout << "\t \t \t \t \t \t \t Caesar Cipher Encryption: " << private_user_encryptedMessage2 << endl;

        // Caesar Cipher Decryption for the reply
        string private_user_caesarDecrypted2 = decryptCaesarCipher(private_user_encryptedMessage2, 3);
        cout << "\t \t \t \t \t \t \t Caesar Cipher Decryption: " << private_user_caesarDecrypted2 << endl;

        privateUser2Messages[count++] = private_user2_msg;
    }
    }
        break;
         case 3:
    char chat_choose;
    cout << "\t a- Chat History With " << private_user1 << endl;
    cout << "\t b- Chat History With " << private_user2 << endl;
    cin >> chat_choose;
    if(count==0){
             cout << "There is no chat history" << endl;
        }
    switch(chat_choose){
        case 'a':
        for(int i=0; i < count; i++){
            if (i % 2 ==0){
            cout << public_user << "'s message: " << endl;
            cout << privateUser1Messages[i] << endl;
            }else{
                cout << private_user1 << "'s messages: " << endl;
                cout << privateUser1Messages[i] << endl;
            }
        }
        break;
        case 'b':
        for(int i=0; i < count; i++){
            if (i % 2 ==0){
            cout << public_user << "'s message: " << endl;
            cout << privateUser2Messages[i] << endl;
            }else{
                cout << private_user2 << "'s messages: " << endl;
                cout << privateUser2Messages[i] << endl;
            }
        }
        break;
        default:
        cout << "Please enter a or b. Enter Valid character ";
    }
        break;
        case 4:
        cout << "The program has been ended";
        break;
        default:
        cout << "Invalid choice, enter numbers";
    }
    }
    while(choice!=4);

    return 0;
}