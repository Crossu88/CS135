#include <iostream>
#include <string>
using namespace std;

struct RegionInfo
{
	string name;
	int acc;
};

int getNumAccidents(string reg)
{
	int a;

	cout << "Enter the number of accidents for the " << reg << " region: ";
	cin >> a;

	return a;
}

void findLowest(struct RegionInfo arr[])
{
	RegionInfo low = { "Nil", -1 };

	int n;

	for (n = 0; n <= 4; n++)
	{
		if (low.acc < 0)
		{
			low.acc = arr[n].acc;
			low.name = arr[n].name;
		}
		else if (arr[n].acc < low.acc)
		{
			low.acc = arr[n].acc;
			low.name = arr[n].name;
		}
	}

	cout << "The region with the lowest amount of accidents is the " << low.name << " region with an accident total of: " << low.acc << ".\n";
}

void findHighest(struct RegionInfo arr[])
{
	RegionInfo low = { "Nil", -1 };

	int n;

	for (n = 0; n <= 4; n++)
	{
		if (low.acc < 0)
		{
			low.acc = arr[n].acc;
			low.name = arr[n].name;
		}
		else if (arr[n].acc > low.acc)
		{
			low.acc = arr[n].acc;
			low.name = arr[n].name;
		}
	}

	cout << "The region with the highest amount of accidents is the " << low.name << " region with an accident total of: " << low.acc << ".\n";
}

int main()
{
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