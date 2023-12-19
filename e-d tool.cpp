#include <iostream>
#include <string>
using namespace std;

// Caesar Cipher functions
string encryptCaesarCipher(const string& password, int shift) {
    string encryptedPassword;

    for (char ch : password) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char encryptedChar = ((ch - base + shift) % 26 + 26) % 26 + base;
            encryptedPassword += encryptedChar;
        } else {
            encryptedPassword += ch;
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

string rsaDecrypt(int encryptedMessage, int d, int n) {
    int decryptedInt = modExp(encryptedMessage, d, n);
    string decryptedMessage;

    while (decryptedInt > 0) {
char ch = decryptedInt % 256;
        decryptedMessage = ch + decryptedMessage;
        decryptedInt /= 256;
    }

    return decryptedMessage;
}

int main() {
    string input;
    int privateKey;
    string message;
    string caesarResult;
    string rsaNum = "";
    string rsaResult;
    int n1 = 13;
    int n2 = 17;
    int n = n1 * n2;
    int euler = (n1 - 1) * (n2 - 1);
    int e = 5;
    int d = 77;
    string encrptedMessage;
    string private_user1_msg;
    string private_user2_msg;
    const int maxMessages = 100;
    cout << "Enter your input: ";
    getline(cin, input);
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
       cout <<  encryptCaesarCipher(message,4);
        encrptedMessage="";
        for (char ch:message){
            char base=ch - 'A';
            encrptedMessage = to_string(ch);
        }
        cout << encrptedMessage << " ";
        int encrMsg;
        if(!encrptedMessage.empty()){
          encrMsg=stoi(encrptedMessage);
        }else {
            encrMsg = 0;
        }
        int finalValue=rsaEncrypt(encrMsg,e,n);
        // string con=to_string(finalValue);
        cout <<"Encrypted Message: " << finalValue << endl;
        string decryptedMessage = rsaDecrypt(finalValue, d, n);
        cout << "Decrypted Message: " << decryptedMessage << endl;

        privateUser1Messages[count++] = message;
        cout << "\t \t \t \t \t \t \t Enter a reply to " << public_user << " : ";
        getline(cin,private_user1_msg);
        privateUser1Messages[count++] = private_user1_msg;
    }
    }
        break;
    case 2:
    while(message != "bye" && private_user2_msg!="bye"&& count < maxMessages){
        cout << "Enter a message to " << private_user1 << " : ";
        getline(cin,message);
        privateUser2Messages[count++] = message;
        cout << "\t \t \t \t \t \t \t Enter a reply to " << public_user << " : ";
         getline(cin,private_user2_msg);
        privateUser2Messages[count++] = private_user2_msg;
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


    for (char ch : input) {
        if (isalpha(ch)) {
            // For letters, apply Caesar Cipher
            caesarResult += encryptCaesarCipher(string(1, ch), 3);
        } else if (isdigit(ch)) {
            // For digits, apply RSA
            rsaNum += ch;
        } else {
            // For other characters, leave unchanged
            caesarResult += ch;
            rsaResult += ch;
        }
    }

    // Separate RSA-encrypted numbers with a special character
    rsaResult += "|";
    int intNums;
    if (!rsaNum.empty()) {
        intNums = stoi(rsaNum);
    }
    int encryptedMessage = rsaEncrypt(intNums, e, n);
    rsaResult += to_string(encryptedMessage);

    cout << "Encryption: " << caesarResult << rsaResult << endl;

    string caesarDecrypted = decryptCaesarCipher(caesarResult, 3);
    // Separate RSA-encrypted numbers during decryption
    size_t pos = rsaResult.find("|");
    string rsaDecrypted = rsaResult.substr(pos + 1);

    // int decryptedNum = rsaDecrypt(stoi(rsaDecrypted), d, n);
    cout << "Decryption: " <<caesarDecrypted << endl;

    return 0;
}