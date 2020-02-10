#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"
/**
Caesar's Cipher. This app will encrypt and decrypt using Caesar's Cipher.
However, the user will input a key (1-5) that will direct how many characters the text will be shifted. 
User must put in the same key number in order for the decrypted text to revert back to the original text.
**/

using namespace std; 

int main()
{
	CaesarsCipher myCipher; 
	cout << "Welcome to Caesars Cipher. This app is able to read your"
		<< " text files, encrypt the text, and decrypt the text." << endl;

	int number = 0;
	while (number != 3)
	{
		string filename;
		string inputText;
		// Main Menu
		cout << "Choose one of the following: " << endl;
		cout << "1. Encrypt a file " << endl;
		cout << "2. Decrypt a file " << endl;
		cout << "3. Exit" << endl;
		cin >> number;
		cin.ignore();

		switch (number)
		{
		case 1:
		{
			int key = 0;
			cout << "Upload your file to be ecrypted." << endl;
			cout << "Enter the file name by using its full file path " << endl;
			cout << "ex. 'c:\\users\\linh\\documents\\textfile.txt'" << endl;
			getline(cin, filename, '\n');
			cout << "Enter Key: (Remember this key because the same key"
				<< " is required to decrypt the file. Enter a number 1 - 5)" << endl;
			cin >> key;
			if (key < 0)
			{
				cout << "Error. Enter a number 1-5." << endl; 
				cin >> key;
			}
			cin.ignore();
			myCipher.encrypt(filename, key);
			break;
		}
		case 2:
		{
			int key = 0;
			cout << "Decrypt a file that is encrypted." << endl;
			cout << "Enter the file name by using its full file path " << endl;
			cout << "ex. 'c:\\users\\linh\\documents\\textfile.txt'" << endl;
			getline(cin, filename, '\n');
			cout << "Enter Key: (Key must be the same # used to encrypt the file." 
				<< endl; 
			cin >> key;
			if (key < 0)
			{
				cout << "Error. Enter a number 1-5" << endl;
				cin >> key;
			}
			cin.ignore();
			myCipher.decrypt(filename, key);
			break;
		}

		case 3:
		{
			break;
		}

		}
	}
	system("pause");
	return 0; 
}