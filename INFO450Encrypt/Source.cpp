//Caesar Cypher ROT13 
//For some reason only works with caps??
#include <iostream>
#include<stdio.h>
#include<string>
#include<fstream>
#include<map>
using namespace std;
map <char, int> key_map1;	// Map to lookup the index of alphabets 
map <int, char> key_map2;	// to the index after shift 
void KeyGen()	// Funciton to create map to lookup 
{
	for (int i = 1; i < 27; i++)
		key_map1[char(64 + i)] = i;

	key_map2[0] = 'Z';

	for (int i = 1; i < 26; i++)
		key_map2[i] = char(64 + i);

	return;
}
string encrypt(string message, int shift)	// Function to encrypt the string 
{
	string cipher = "";
	for (int i = 0; i < message.size(); i++)
	{
		if (message[i] != ' ')	// checks for space 
		{
			int num = (key_map1[message[i]] + shift) % 26;	// looks up the map and adds the shift to the index 

			cipher += key_map2[num];	// looks up the second map for the shifted alphabets and adds them 
		}
		else
		{
			cipher += " ";	// adds space 
		}
	}
	return cipher;
}
string decrypt(string message, int shift)		// Function to decrypt the string 
{
	string decipher = "";
	for (int i = 0; i < message.size(); i++)
	{
		// checks for space 
		if (message[i] != ' ')
		{

			int num = (key_map1[message[i]] - shift + 26) % 26;		// looks up the map and subtracts the shift from the index 

			decipher += key_map2[num];		// looks up the second map for the shifted alphabets and adds them 
		}
		else
		{
			decipher += " ";	// adds space 
		}
	}
	return decipher;
}

int main()
{
	int x;
	KeyGen();
	string message, filename;
	ofstream outputFile;
	ifstream inputFile;
	int shift;

	cout << "################## Welcome to Thomas' Caesar Cypher Rotation Program ################## \n";
	cout << "***********   User Menu *********** ";
	cout << "\nPlease choose following options:\n";
	cout << "1 = Encrypt the file.\n";
	cout << "2 = Decrypt the file.\n";
	cout << "3 = Exit the program.\n";
	cin >> x;

	switch (x) {	//using switch statements
	case 1:		//first case for Encryption
		cout << "enter the key for encryption: \n";
		cout << "Ex; an integer between 1-26 to shift characters by.\n";
		cin.ignore();
		cin >> shift;
		cout << "Please enter the filename (full path) to read from: \n";
		cout << "Example of working filename: C:\\Users\\<username>\\<text file directory>\\test.txt \n";
		cin.ignore();
		getline(cin, filename);

		inputFile.open(filename);
		if (inputFile.bad()) {
			cout << "Error: Cant open File!" << endl;
			return 1;
		}
		while (!inputFile.eof()) {
			if (inputFile.good())
				getline(inputFile, message);
			break;
		}
		inputFile.close();

		message = encrypt(message, shift);

		outputFile.open(filename);	//output Encrypted contents to file
		if (outputFile.bad()) {
			cout << "Error - File has Failed to Open" << endl;
			return -1;
		}
		while (!outputFile.eof()) {
			if (outputFile.good())
			{
				outputFile << message << endl;
				break;
			}
		}
		outputFile.close();
		break;
	case 2:	//second case for Decrypting file
		inputFile.open(filename);
		if (inputFile.bad()) {
			cout << "Error: Cant open File!" << endl;
			return 1;
		}
		while (!inputFile.eof()) {
			if (inputFile.good())
				getline(inputFile, message);
			break;
		}
		inputFile.close();

		message = decrypt(message, shift);

		outputFile.open(filename);	//output Encrypted contents to file
		if (outputFile.bad()) {
			cout << "Error - File has Failed to Open" << endl;
			return -1;
		}
		while (!outputFile.eof()) {
			if (outputFile.good())
			{
				outputFile << message << endl;
				break;
			}
		}
		outputFile.close();
		break;
	case 3:
		cout << "Thank you.\n";
		cout << "Exiting Program..." << endl;
		system("exit");
	}
	cout << "***********   User Menu *********** ";
	cout << "\nPlease choose following options:\n";
	cout << "1 = Encrypt the file.\n";
	cout << "2 = Decrypt the file.\n";
	cout << "3 = Exit the program.\n";
	cin >> x;

	system("pause");
	return 0;
}