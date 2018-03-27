#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION:          inputData(string array1[], int array2[])
DESCRIPTION:       Chooses method of input for the data.
RETURNS:           Nothing.
NOTES:             Is passed a pointer to an array.
----------------------------------------------------------------------------- */

void inputData(string arr1[], int arr2[])
{
	string file, a;
	int choice, i, b, ent;

	ifstream inf;

	cout << "1 - Read data from file\n2 - Enter data manually\n3 - Quit program\nType the number of the choice you'd like to select: ";
	cin >> choice;

	switch (choice)
	{
		case 1:
			cout << "Enter the name of the file you'd like to read from: ";
			cin >> file;

			inf.open(file);

			for (i = 0; inf >> a >> b; i++)
			{
				arr1[i] = a;
				arr2[i] = b;
			}

			inf.close();

			break;

		case 2:
			cout << "How many entries would you like to make?";
			cin >> ent;

			while ((ent > 20) || (ent < 1))
			{
				cout << "Invalid amount, entries must be between 1 and 20. Enter a valid number: ";
				cin >> ent;
			}

			for (i = 0; i <= (ent - 1); i++)
			{
				cout << "What is the name of the city?: ";
				cin >> arr1[i];

				cout << "How many accidents were in the city?: ";
				cin >> arr2[i];

				while (arr2[i] < 0)
				{
					cout << "Invalid amount, accident total must be a non-negative integer. Enter a valid total: ";
					cin >> acc;
				}
			}
			break;

		case 3:
			system("quit");
			break;

		default:
			cout << "Incorrect choice error.";
			system("pause");
			system("quit");
			break;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          findLowest(Regioninfo Array[])
DESCRIPTION:       Finds the region with the lowest accident total.
RETURNS:           Nothing.
NOTES:             Is passed a pointer to an array.
----------------------------------------------------------------------------- */

void outputMin(int arr1[], string arr2[])
{
	cout << "----------------------------------------------------------------\n";

	int lo = -1;
	int n;

	for (n = 0; ((n <= 19) && (arr1[n] >= 0)); n++)
	{
		if (lo < 0)
		{
			lo = arr1[n];
		}
		else if (arr1[n] < lo)
		{
			lo = arr1[n];
		}
	}

	cout << "The region(s) with the lowest amount of accidents...";

	ofstream outF;

	outF.open("regionsmin.txt");

	for (n = 0; n <= 19; n++)
	{
		if (arr1[n] == lo)
		{
			cout << "\nThe " << arr2[n] << " region with an accident total of: " << arr1[n];

			outF << arr2[n] << ": " << arr1[n] << endl;
		}

	}

	outF.close();
	cout << "\n";
}

/* -----------------------------------------------------------------------------
FUNCTION:          findHighest(Regioninfo Array[])
DESCRIPTION:       Finds the region with the highest accident total.
RETURNS:           Nothing.
NOTES:             Is passed a pointer to an array.
----------------------------------------------------------------------------- */

void outputMax(int arr1[], string arr2[])
{
	cout << "----------------------------------------------------------------\n";

	int hi = -1;
	int n;

	for (n = 0; n <= 19; n++)
	{
		if (hi < 0)
		{
			hi = arr1[n];
		}
		else if (arr1[n] > hi)
		{
			hi = arr1[n];
		}
	}

	cout << "The region(s) with the highest amount of accidents...";

	ofstream outF;

	outF.open("regionsmax.txt");

	for (n = 0; n <= 19; n++)
	{
		if (arr1[n] == hi)
		{
			cout << "\nThe " << arr2[n] << " region with an accident total of: " << arr1[n];
			outF << arr2[n] << ": " << arr1[n] << endl;
		}
	}

	outF.close();
	cout << "\n";
}


int main()
{
	string str_reg[20];
	int num_reg[20];

	int i;

	for (i = 0; i <= 19; i++)
	{
		str_reg[i] = "Nil";
		num_reg[i] = -1;
	}

	inputData(str_reg, num_reg);

	outputMin(num_reg, str_reg);
	outputMax(num_reg, str_reg);

	system("pause");
}