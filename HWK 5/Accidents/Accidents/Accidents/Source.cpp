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
STRUCTURE:		  RegionInfo
USE:			  Containing data of a region's name
				  and the total number of accidents.
----------------------------------------------------------------------------- */

struct RegionInfo
{
	string name;
	int acc;
};

/* -----------------------------------------------------------------------------
FUNCTION:          getNumAccients(string region name)
DESCRIPTION:       Prompts the user to input accident total for a region.
RETURNS:           Returns the accident total.
NOTES:             N/A.
----------------------------------------------------------------------------- */

int getNumAccidents(string reg)
{
	int a;

	cout << "Enter the number of accidents for the " << reg << " region: ";
	cin >> a;

	while (a < 0)
	{
		cout << "Please enter a valid accident total for the " << reg << " region: ";
		cin >> a;
	}

	return a;
}

/* -----------------------------------------------------------------------------
FUNCTION:          findLowest(Regioninfo Array[])
DESCRIPTION:       Finds the region with the lowest accident total.
RETURNS:           Nothing.
NOTES:             Is passed a pointer to an array.
----------------------------------------------------------------------------- */

void findLowest(struct RegionInfo arr[])
{
	cout << "----------------------------------------------------------------\n";

	RegionInfo lo = { "Nil", -1 };

	int n;

	for (n = 0; n <= 4; n++)
	{
		if (lo.acc < 0)
		{
			lo.acc = arr[n].acc;
			lo.name = arr[n].name;
		}
		else if (arr[n].acc < low.acc)
		{
			lo.acc = arr[n].acc;
			lo.name = arr[n].name;
		}
	}

	cout << "The region(s) with the lowest amount of accidents...";

	for (n = 0; n <= 4; n++)
	{
		if (arr[n].acc == lo.acc)
		{
			cout << "\nThe " << arr[n].name << " region with an accident total of: " << arr[n].acc;
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

void findHighest(struct RegionInfo arr[])
{
	cout << "----------------------------------------------------------------\n";

	RegionInfo hi = { "Nil", -1 };

	int n;

	for (n = 0; n <= 4; n++)
	{
		if (hi.acc < 0)
		{
			hi.acc = arr[n].acc;
			hi.name = arr[n].name;
		}
		else if (arr[n].acc > hi.acc)
		{
			hi.acc = arr[n].acc;
			hi.name = arr[n].name;
		}
	}

	cout << "The region(s) with the highest amount of accidents...";

	for (n = 0; n <= 4; n++)
	{
		if (arr[n].acc == hi.acc)
		{
			cout << "\nThe " << arr[n].name << " region with an accident total of: " << arr[n].acc;
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

	RegionInfo arr_regions[5];

	arr_regions[0] = { "Central", 0 };
	arr_regions[1] = { "North", 0 };
	arr_regions[2] = { "East", 0 };
	arr_regions[3] = { "South", 0 };
	arr_regions[4] = { "West", 0 };

	int num;

	for (num = 0; num <= 4; num++)
		arr_regions[num].acc = getNumAccidents(arr_regions[num].name);

	findLowest(arr_regions);
	findHighest(arr_regions);

	system("pause");
}