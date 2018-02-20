#include <iostream>
using namespace std;

/*------------------------------------------------------
FUNCTION NAME: getWidth.
FUNCTION USE: Prompts for and returns a width.
DESCRIPTION: Uses iostream to return a width given by the user.
------------------------------------------------------*/

double getWidth()
{
	double w;
	cout << "Enter a width: ";
	cin >> w;
	return w;
}

/*------------------------------------------------------
FUNCTION NAME: getLength.
FUNCTION USE: Prompts for and returns a length.
DESCRIPTION: Uses iostream to return a length given by the user.
------------------------------------------------------*/

double getLength()
{
	double l;
	cout << "Enter a length: ";
	cin >> l;
	return l;
}

/*------------------------------------------------------
FUNCTION NAME: getArea.
FUNCTION USE: Calculated an area of a rectangle.
DESCRIPTION: Using two arguments in order to calculate the area of a square.
------------------------------------------------------*/

double getArea(double x, double y)
{
	return (x * y);
}

/*------------------------------------------------------
FUNCTION NAME: displayData.
FUNCTION USE: Displays data about the rectangle.
DESCRIPTION: Uses the three data points calculated above and displays them.
------------------------------------------------------*/

void displayData(double a, double b, double c)
{
	cout << "The width of the rectangle is: " << a << ",\nThe length of the rectangle is: " << b << ",\nAnd the area of the rectangle is: " << c << endl;
	system("pause");
}

/*------------------------------------------------------
FUNCTION NAME: Main.
FUNCTION USE: Calls displayData which calls all other functions
in order to calculate and display data of a rectangle.
DESCRIPTION: Called by operating system.
------------------------------------------------------*/

int main()
{
	double w, l, a;

	cout << "Welcome to the rectangle calculator!" << "\n------------------------------------------------------\n";

	w = getWidth();
	l = getLength();

	cout << "\n------------------------------------------------------\n";

	displayData(w, l, getArea(w, l));
}