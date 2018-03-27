/* -----------------------------------------------------------------------------

FILE:				Source.CPP

DESCRIPTION:		Calculates the lowest and the highest
					accident totals in 5 regions.

NOTES:				N/A

MODIFICATION HISTORY:

Author					 Date                Version
---------------			 ----------          --------------
Holden Bowman            2018-02-20			 1.0

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>
using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION:          getNumAccients(string region name)
DESCRIPTION:       Prompts the user to input accident total for a region.
RETURNS:           Returns the accident total.
NOTES:             N/A.
----------------------------------------------------------------------------- */

void getNumAccidents( int arr1[], string arr2[] )
{
	int i;

	for (i = 0; i <= 4; i++)
	{
		int a;

		cout << "Enter the number of accidents for the " << arr2[i] << " region: ";
		cin >> a;

		while (a < 0)
		{
			cout << "Please enter a valid accident total for the " << arr2[i] << " region: ";
			cin >> a;
		}

		arr1[i] = a;
	}
}

/* -----------------------------------------------------------------------------
FUNCTION:          findLowest(Regioninfo Array[])
DESCRIPTION:       Finds the region with the lowest accident total.
RETURNS:           Nothing.
NOTES:             Is passed a pointer to an array.
----------------------------------------------------------------------------- */

void findLowest( int arr1[], string arr2[] )
{
	cout << "----------------------------------------------------------------\n";

	int lo = -1;

	int n;

	for (n = 0; n <= 4; n++)
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

	for (n = 0; n <= 4; n++)
	{
		if (arr1[n] == lo)
		{
			cout << "\nThe " << arr2[n] << " region with an accident total of: " << arr1[n];
		}
			
	}
	cout << "\n";
}

/* -----------------------------------------------------------------------------
FUNCTION:          findHighest(Regioninfo Array[])
DESCRIPTION:       Finds the region with the highest accident total.
RETURNS:           Nothing.
NOTES:             Is passed a pointer to an array.
----------------------------------------------------------------------------- */

void findHighest(int arr1[], string arr2[])
{
	cout << "----------------------------------------------------------------\n";

	int hi = -1;

		int n;

	for (n = 0; n <= 4; n++)
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

	for (n = 0; n <= 4; n++)
	{
		if (arr1[n] == hi)
		{
			cout << "\nThe " << arr2[n] << " region with an accident total of: " << arr1[n];
		}
	}
	cout << "\n";
}

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Initializes program.
RETURNS:           Nothing.
NOTES:             N/A.
----------------------------------------------------------------------------- */

int main()
{
	cout << "Welcome to the accident total data assessment tool!\n----------------------------------------------------------------\n";

	string str_regions[5];
	int num_regions[5];

	str_regions[0] = "Central";
	str_regions[1] = "North";
	str_regions[2] = "East";
	str_regions[3] = "South";
	str_regions[4] = "West";

	num_regions[0] = 0;
	num_regions[1] = 0;
	num_regions[2] = 0;
	num_regions[3] = 0;
	num_regions[4] = 0;

	getNumAccidents( num_regions, str_regions );

	findLowest( num_regions, str_regions );
	findHighest( num_regions, str_regions );

	system("pause");
}