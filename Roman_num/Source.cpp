#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;


int main()
{

	char one[4] = { 'I','X', 'C', 'M' };
	char five[4] = { 'V', 'L', 'D', };
	char RomanNumber[30];
	int number;

	// Current index for the string RomanNumbers
	int i = 0;

	// Index for one and five arrays that inctements when we go to the next position in number
	int j = 0;

	cout << "Input arabic number: ";
	cin >> number;
	do
	{
		// We look at the last number
		switch (number % 10)
		{
		case 1:
			RomanNumber[i++] = one[j];

			break;
		case 2:
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = one[j];

			break;
		case 3:
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = one[j];

			break;
		case  4:
			RomanNumber[i++] = five[j];
			RomanNumber[i++] = one[j];

			break;
		case 5:
			RomanNumber[i++] = five[j];

			break;
		case 6:
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = five[j];

			break;
		case 7:
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = five[j];

			break;
		case 8:
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = one[j];
			RomanNumber[i++] = five[j];

			break;
		case 9:
			RomanNumber[i++] = one[j + 1];
			RomanNumber[i++] = one[j];

			break;
		}

		j++;

		//Moving on to the next position in number
		number /= 10;
	} while (number);

	RomanNumber[i] = '\0';

	cout << "Roman equivalent: ";

	for (int i = strlen(RomanNumber) - 1; i >= 0; i--) {
		cout << RomanNumber[i];
	}

	_getch();
	return 1;
}