#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
using namespace std;

string getMsg()
{
	string str;

	cout << "Enter the message you would like to encode/decode: ";
	getline(cin, str);
	getline(cin, str);

	return str;
}

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

string encodeMsg(string istr, int s)
{
	string ostr;
	int i;
	char c, n;

	for (i = 0; i <= (istr.length() - 1); i++)
	{
		c = toupper(istr.at(i));
		n = (c + s);

		if ((n <= 90) && (n >= 65))
			ostr.append(1, n);
		else if ((n < 65) && isalpha(c))
			ostr.append(1, (91 + (s + (c - 65))));
		else if ((n > 90) && isalpha(c))
			ostr.append(1, (64 + (s - (90 - c))));
		else if (!isalpha(c))
			ostr.append(1, c);
		else
			cout << "Unhandled exception during encoding.\n";
	}

	return ostr;
}

void displayMsg(string enstr)
{
	cout << "The message comes out as:\n" << enstr << endl;
}

void writeFile(string name, string msg, int shift)
{
	ofstream fout;

	fout.open("caesar_" + name);

	fout << shift << endl << msg << endl;

	fout.close();
}

int main()
{
	string msgStr, file = "default.txt", s1;
	int shift;
	char c1, c2;
	bool doRep = false;
	ifstream fin;
	

	do {
		cout << "Would you like to encrypt or decrypt a message? <E/D>: ";
		cin >> c1;
		c1 = toupper(c1);

		cout << "Would you like to enter the message and shift manually or read it from a file? <M/F>: ";
		cin >> c2;
		c2 = toupper(c2);

		cin.clear();

		switch (c2)
		{
			case 'M':
				msgStr = getMsg();
				shift = getShift();
				break;
			case 'F':
				cin.clear();

				cout << "What is the name of the file you'd like to read from?: ";
				getline(cin, file);
				getline(cin, file);

				fin.open(file);

				fin >> shift;
				while (fin >> s1)
					msgStr.append(" " + s1);

				fin.close();
				break;
			default:
				cout << "Incorrect input.";
		}

		switch (c1)
		{
			case 'E':
				msgStr = encodeMsg(msgStr, shift);
				break;
			case 'D':
				msgStr = encodeMsg(msgStr, (shift * -1));
				break;
			default:
				cout << "Incorrect input.";
		}

		displayMsg(msgStr);

		writeFile(file, msgStr, shift);

		system("pause");
	} while (doRep == true);
}