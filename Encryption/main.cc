#include <iostream>
#include <string>
#include <fstream>

// Define a class for our encryption app
class EncryptionApp {
private:
    // Define a function to encrypt a string
    std::string encrypt(const std::string& plaintext, const std::string& key) {
        // TO DO: implement your encryption algorithm here
        // For now, just return the plaintext
        return plaintext;
    }

    // Define a function to decrypt a string
    std::string decrypt(const std::string& ciphertext, const std::string& key) {
        // TO DO: implement your decryption algorithm here
        // For now, just return the ciphertext
        return ciphertext;
    }

public:
    // Define a function to handle user input and output
    void runApp() {
        std::string choice;
        std::string input;
        std::string key;

        while (true) {
            std::cout << "Encryption App" << std::endl;
            std::cout << "1. Encrypt" << std::endl;
            std::cout << "2. Decrypt" << std::endl;
            std::cout << "3. Quit" << std::endl;
            std::cin >> choice;

            if (choice == "1") {
                std::cout << "Enter plaintext: ";
                std::cin >> input;
                std::cout << "Enter key: ";
                std::cin >> key;
                std::string ciphertext = encrypt(input, key);
                std::cout << "Ciphertext: " << ciphertext << std::endl;
            } else if (choice == "2") {
                std::cout << "Enter ciphertext: ";
                std::cin >> input;
                std::cout << "Enter key: ";
                std::cin >> key;
                std::string plaintext = decrypt(input, key);
                std::cout << "Plaintext: " << plaintext << std::endl;
            } else if (choice == "3") {
                break;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        }
    }
};

int main() {
    EncryptionApp app;
    app.runApp();
    return 0;
}