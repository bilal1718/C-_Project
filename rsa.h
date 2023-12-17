// rsa.h
#ifndef RSA_H
#define RSA_H

#include <string>

int getPrimeFromUser(const std::string& prompt);
int gcd(int a, int b);
int modExp(int base, int exponent, int mod);
int rsaEncrypt(int message, int e, int n);
int rsaDecrypt(int encryptedMessage, int d, int n);
int rsa(int numbers, int encryptedMessage, int decryptedMessage, int choice);

#endif // RSA_H
