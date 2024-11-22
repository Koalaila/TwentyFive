#include <iostream>
#include <string>
#include <cctype>

using namespace std;
class EncryptionApp
{
private:
    string encrypt(string plaintext, string keyword)
    {
        string ciphertext = "";
        int keyword_len = keyword.length();

        for (int i = 0; i < plaintext.length(); i++)
        {
            char c = plaintext[i];
            if (isalpha(c))
            {
                int shift = toupper(keyword[i % keyword_len]) - 'A';
                c = toupper(c);
                c = (c - 'A' + shift) % 26 + 'A';
            }
            ciphertext += c;
        }
        return ciphertext;
    }

    string decrypt(string ciphertext, string keyword)
    {
        string plaintext = "";
        int keyword_len = keyword.length();

        for (int i = 0; i < ciphertext.length(); i++)
        {
            char c = ciphertext[i];
            if (isalpha(c))
            {
                int shift = toupper(keyword[i % keyword_len]) - 'A';
                c = toupper(c);
                c = (c - 'A' - shift + 26) % 26 + 'A';
            }
            plaintext += c;
        }

        return plaintext;
    }

public:
    void runApp()
    {
        string choice;
        string input;
        string key;
        // While loop to continue the app until user hits quit
        while (true)
        {
            cout << "Encryption App" << std::endl;
            cout << "1. Encrypt" << std::endl;
            cout << "2. Decrypt" << std::endl;
            cout << "3. Quit" << std::endl;
            cin >> choice;

            if (choice == "1")
            {
                cout << "Enter one word: ";
                cin >> input;
                cout << "Enter key: ";
                cin >> key;
                string ciphertext = encrypt(input, key);
                cout << "Ciphertext: " << ciphertext << std::endl;
            }
            else if (choice == "2")
            {
                cout << "Enter ciphertext: ";
                cin >> input;
                cout << "Enter key: ";
                cin >> key;
                string plaintext = decrypt(input, key);
                cout << "Plaintext: " << plaintext << endl;
            }
            else if (choice == "3")
            {
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main()
{
    EncryptionApp app;
    app.runApp();
    return 0;
}