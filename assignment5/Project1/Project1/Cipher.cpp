#include <iostream>
#include <fstream>
#include <string>
#include "Cipher.h"

using namespace std;
 CaesarsCipher::CaesarsCipher()
{
	string filename = "";
	string inputText = "";
} 

int CaesarsCipher :: encrypt(string filename, int key)
{
	string encryptText = "";
	int shift = 0;
	shift = key - 1;
	// Open an existing file and read in text into inputText. 
	ifstream inputFile;
	inputFile.open(filename, ios:: _Nocreate);
	if (!inputFile)
	{
		cout << "Error: can't open file. Redirect to menu." << endl;
		return 1;
	}
	while (!inputFile.eof())
	{
		getline(inputFile, inputText, '\n');
	}
	inputFile.close();

	// Encrypt inputText
	int i;
	for (i = 0; i < inputText.length(); i++)
	{
		encryptText += char(int(inputText[i] + shift) % 127) + 1;
	}
	cout << encryptText << endl;

	// Overwrite the same file to save the encrypted text.
	ofstream outputFile;
	outputFile.open(filename);
	if (!outputFile)
	{
		cout << "Error: couldn't open file. Redirect to menu." << endl;
		return -1;
	}
	outputFile << encryptText; 
	outputFile.close();
	return 0;
}
int CaesarsCipher::decrypt(string filename, int key)
{
	string decryptText = ""; 
	int shift = 0;
	shift = key - 1; 
	// Open an existing file to read text into decryptText. 
	ifstream inputFile;
	inputFile.open(filename, ios::_Nocreate);
	if (!inputFile)
	{
		cout << "Error: can't open file. Back to menu." << endl;
		return 1;
	}
	while (!inputFile.eof())
	{
		getline(inputFile, inputText, '\n');
	}
	inputFile.close();
	// Decrypt decryptText. 
	int i;
	for (i = 0; i < inputText.length(); i++)
	{
		decryptText += char(int(inputText[i] - shift) % 127) - 1;
	}

	// Overwrite the same file with the decrypted text. 
	ofstream outputFile;
	outputFile.open(filename);
	if (!outputFile)
	{
		cout << "Error: couldn't open file. Redirect to menu." << endl;
		return -1;
	}
	outputFile << decryptText;
	outputFile.close();
	
	char answer = ' ';
	cout << "Display decrypted text? Enter: y/n" << endl; 
	cin >> answer; 
	if (answer != 'n')
	{
		cout << decryptText << endl;
	}

	return 0;

}
