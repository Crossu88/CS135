/* -----------------------------------------------------------------------------

FILE:              Source.CPP

DESCRIPTION:       Caesar Cipher for project 1 submission/



NOTES:             Put other information here ...

MODIFICATION HISTORY:

Author                  Date                Version
---------------			----------			--------------
Holden Bowman			2017-04-07			1.00

----------------------------------------------------------------------------- */

#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION:          getMsg()
DESCRIPTION:       Prompts the user for a message.
RETURNS:           The message to be shifted.
NOTES:             N/A
----------------------------------------------------------------------------- */

string getMsg()
{
	string str;

	cout << "Enter the message you would like to encode/decode: ";
	cin >> str;

	return str;
}

/* -----------------------------------------------------------------------------
FUNCTION:          getShift()
DESCRIPTION:       Prompts the user for the shift in the cipher.
RETURNS:           The shift for the caesar cipher.
NOTES:             N/A
----------------------------------------------------------------------------- */

int getShift()
{
	int shift;

	cout << "Enter a positive or negative number for the shift: ";
	cin >> shift;

	while (abs(shift) > 26)
	{
		if (shift < 0)
			shift = (shift + 26);
		else
			shift = (shift - 26);
	}

	return shift;
}

/* -----------------------------------------------------------------------------
FUNCTION:          encodeMsg(string inputstring, int shift)
DESCRIPTION:       Encodes a message.
RETURNS:           Returns the encoded message in all capital letters.
NOTES:             Must be done per message, can not do arrays!
----------------------------------------------------------------------------- */

string encodeMsg(string istr, int shift)
{
	string ostr;
	int i;
	char ch, newCh;

	for (i = 0; i <= (istr.length() - 1); i++)
	{
		ch = toupper(istr.at(i));
		newCh = (ch + shift);

		if ((newCh <= 90) && (newCh >= 65))
			ostr.append(1, newCh);
		else if ((newCh < 65) && isalpha(ch))
			ostr.append(1, (91 + (shift + (ch - 65))));
		else if ((newCh > 90) && isalpha(ch))
			ostr.append(1, (64 + (shift - (90 - ch))));
		else if (!isalpha(ch))
			ostr.append(1, ch);
		else
			cout << "Unhandled exception during encoding.\n";
	}

	return ostr;
}

/* -----------------------------------------------------------------------------
FUNCTION:          caesarFile()
DESCRIPTION:       Initialized the file entering menu.
RETURNS:           Nothing (Void Function)
NOTES:             May read a maximum of 10 entries
----------------------------------------------------------------------------- */

void caesarFile()
{
	ifstream fin;
	ofstream fout;
	string msgStr[10], file, readStr, newStr;
	char choice;
	int shift[10], i, coeff;

	cout << "\nWhat is the name of the file you'd like to read from?: ";
	cin >> file;

	cout << "\nWould you like to encrypt or decrypt the message? <E/D>: ";
	cin >> choice;
	choice = toupper(choice);

	cout << "\n-----------------------------------------------\n";

	switch (choice)
	{
	case 'E':
		coeff = 1;
		break;
	case 'D':
		coeff = -1;
		break;
	default:
		cout << "Incorrect input";
	}

	fin.open(file);

	i = 0;

	fin >> shift[i];

	while ((fin >> readStr) && (i <= 9))
	{
		if (isdigit(readStr.at(0)))
		{
			i++;

			shift[i] = (readStr.at(0) - 48) * coeff;
		}
		else
			msgStr[i].append(readStr + " ");
	}

	fin.close();

	switch (choice)
	{
	case 'E':
		fout.open("caesar_" + file);
		break;
	case 'D':
		fout.open(file + "_decrypted");
		break;
	default:
		cout << "Incorrect input";
	}

	for (int x = 0; x <= i; x++)
	{
		newStr = encodeMsg(msgStr[x], shift[x]);
		cout << "\nMessage " << x + 1 << " comes out as: " << newStr << endl;
		fout << shift[x] << endl << newStr << endl;
	}

	fout.close();

	cout << "\n-----------------------------------------------\n";
}

/* -----------------------------------------------------------------------------
FUNCTION:          caesarManual()
DESCRIPTION:       Starts the manual caesar cipher process.
RETURNS:           Nothing (Void Function).
NOTES:             Calls functions for the message and shift input.
----------------------------------------------------------------------------- */

void caesarManual()
{
	string msgStr, newStr, file = "default.txt";
	int shift;
	char choice;

	msgStr = getMsg();
	shift = getShift();

	cout << "Would you like to encrypt or decrypt the message? <E/D>: ";
	cin >> choice;
	choice = toupper(choice);

	switch (choice)
	{
	case 'E':
		newStr = encodeMsg(msgStr, shift);
		break;
	case 'D':
		newStr = encodeMsg(msgStr, (shift * -1));
		break;
	default:
		cout << "Incorrect input.";
	}

	cout << "The message comes out as: " << newStr << endl;

	ofstream fout;

	fout.open("caesar_" + file);

	fout << shift << endl << newStr << endl;

	fout.close();
}

/* -----------------------------------------------------------------------------
FUNCTION:          caesar()
DESCRIPTION:       Initialized the main menu for the caesar cipher.
RETURNS:           Nothing (Void Function).
NOTES:             Caesar cipher outputs in all capital letters.
----------------------------------------------------------------------------- */

void caesar()
{
	cout << "\n-----------------------------------------------\n\n";

	char choice;
	bool quit = false;

	do {
		cout << "Would you like to enter the message and shift manually, read from a file, or quit? <M/F/Q>: ";
		cin >> choice;
		choice = toupper(choice);

		switch (choice)
		{
		case 'M':
			caesarManual();
			break;
		case 'F':
			caesarFile();
			break;
		case 'Q':
			cout << "Goodbye!\n";
			quit = true;
			break;
		default:
			cout << "Incorrect input.";
		}
		system("pause");
	} while (!quit);
}

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Creates the main menu in which to enter the Caesar Cipher
RETURNS:           Nothing (Void Function).
NOTES:             Simple menu with little input.
----------------------------------------------------------------------------- */

int main()
{
	int choice;
	bool con = true;

	do {
		cout << "What would you like to do today?\n1. Caesar Cipher\n2. Stub\n3. Stub\n\nEnter a choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			caesar();
			break;
		case 2:
			cout << "Currently unavailable.\n";
			break;
		case 3:
			cout << "Currently unavailable.\n";
			break;
		case 4:
			cout << "Goodbye!.\n";
			con = true;
			break;
		default:
			cout << "Incorrect choice.";
		}
	} while (con);

	system("pause");
}