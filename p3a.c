#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void printVigenereTable()
{
    printf("Vigenere Table:\n");
    printf("  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z\n");
    for (int i = 0; i < 26; i++)
    {
        printf("%c ", 'A' + i);
        for (int j = 0; j < 26; j++)
        {
            printf("%c ", 'A' + (i + j) % 26);
        }
        printf("\n");
    }
}

void encrypt()
{
    char plaintext[128];
    char key[16];
    printf("\nEnter the plaintext (up to 128 characters): ");
    scanf(" %[^\n]", plaintext);
    printf("Enter the key (up to 16 characters): ");
    scanf(" %[^\n]", key);

    printf("Cipher Text: ");
    for (int i = 0, j = 0; i < strlen(plaintext); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        char encryptedChar = ((toupper(plaintext[i]) - 'A' + shift) % 26) + 'A';
        printf("%c", encryptedChar);
    }
    printf("\n");
}

void decrypt()
{
    char ciphertext[128];
    char key[16];
    printf("\nEnter the ciphertext: ");
    scanf(" %[^\n]", ciphertext);
    printf("Enter the key: ");
    scanf(" %[^\n]", key);

    printf("Deciphered Text: ");
    for (int i = 0, j = 0; i < strlen(ciphertext); i++, j++)
    {
        if (j >= strlen(key))
        {
            j = 0;
        }
        int shift = toupper(key[j]) - 'A';
        char decryptedChar = ((toupper(ciphertext[i]) - 'A' - shift + 26) % 26) + 'A';
        printf("%c", decryptedChar);
    }
    printf("\n");
}

int main()
{
    encrypt();
    decrypt();
    printVigenereTable();
    return 0;
}