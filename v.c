#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the message using the Vigenère cipher
void encrypt(char *message, char *key, char *encryptedMessage) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    
    for (int i = 0, j = 0; i < messageLen; i++) {
        char c = message[i];
        
        // Only shift letters, skip non-alphabet characters
        if (isalpha(c)) {
            // Ensure uniformity by converting everything to uppercase
            c = toupper(c);
            char k = toupper(key[j % keyLen]) - 'A';
            
            // Shift the letter, wrapping around the alphabet
            encryptedMessage[i] = ((c - 'A' + k) % 26) + 'A';
            j++;
        } else {
            // Non-alphabet characters remain the same
            encryptedMessage[i] = c;
        }
    }
    encryptedMessage[messageLen] = '\0'; // End the string
}

// Function to decrypt the message using the Vigenère cipher
void decrypt(char *message, char *key, char *decryptedMessage) {
    int messageLen = strlen(message);
    int keyLen = strlen(key);
    
    for (int i = 0, j = 0; i < messageLen; i++) {
        char c = message[i];
        
        // Only shift letters, skip non-alphabet characters
        if (isalpha(c)) {
            // Ensure uniformity by converting everything to uppercase
            c = toupper(c);
            char k = toupper(key[j % keyLen]) - 'A';
            
            // Reverse the shift for decryption, wrapping around the alphabet
            decryptedMessage[i] = ((c - 'A' - k + 26) % 26) + 'A';
            j++;
        } else {
            // Non-alphabet characters remain the same
            decryptedMessage[i] = c;
        }
    }
    decryptedMessage[messageLen] = '\0'; // End the string
}

int main() {
    char choice;
    char message[256];
    char key[256];
    char result[256];
    
    printf("Welcome to the Vigenère Cipher Program!\n");
    printf("Choose an option: E to encrypt or D to decrypt: ");
    scanf(" %c", &choice);
    choice = toupper(choice);
    
    // Get the message
    printf("Enter your message: ");
    getchar();  // Clear the newline from the previous input
    fgets(message, 256, stdin);
    message[strcspn(message, "\n")] = '\0';  // Remove the newline character
    
    // Get the keyword
    printf("Enter your keyword: ");
    fgets(key, 256, stdin);
    key[strcspn(key, "\n")] = '\0';  // Remove the newline character
    
    // Encrypt or decrypt based on user choice
    if (choice == 'E') {
        encrypt(message, key, result);
        printf("Encrypted Message: %s\n", result);
    } else if (choice == 'D') {
        decrypt(message, key, result);
        printf("Decrypted Message: %s\n", result);
    } else {
        printf("Invalid option. Please enter E to encrypt or D to decrypt.\n");
    }

    return 0;
}
