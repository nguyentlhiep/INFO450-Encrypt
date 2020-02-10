#pragma once
#include <iostream>
#include <fstream>
#include "string.h"
using namespace std; 

class CaesarsCipher
{
	string filename;
	string inputText;

public: 
	CaesarsCipher();
	int encrypt(string filename, int key); 
	int decrypt(string filename, int key);
};
