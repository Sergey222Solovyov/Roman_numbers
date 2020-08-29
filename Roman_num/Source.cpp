#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
using namespace std;
int getValue()
{
	while (true) // The loop continues until the user enters the correct value
	{
		std::cout << "Enter an integer arabic number which does not exceed 8999: ";
		int a;
		std::cin >> a;
		// Checking for a previous checkout
		if (std::cin.fail() || a > 8999) // If the previous extraction failed,
		{
			std::cin.clear(); // then we return cin to 'normal' operation
			std::cin.ignore(32767, '\n'); // and remove the values ​​of the previous input from the input buffer
			std::cout << "Oops, that input is invalid. Please try again.\n";
		}
		else
		{
			std::cin.ignore(32767, '\n'); // Remove unnecessary values
			return a;
		}
	}
}

int Menu()
{
	int a;

	cout << "Start menu: ";
	cout << endl << "1. Convert Arabic to Roman Numerals.";
	cout << endl << "2. Exit.";
	

	a = _getch();

	return a;
}
void ArabicToRoman()
{
	system("cls");
	char one[4] = { 'I','X', 'C', 'M' };
	char five[4] = { 'V', 'L', 'D' };
	char RomanNumber[30];
	int number;

	// Current index for the string RomanNumbers
	int i = 0;

	// Index for one and five arrays that inctements when we go to the next position in number
	int j = 0;

	number = getValue();
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
	cout << endl << "Press any key to continue...";
	_getch();
	

}

int main()
{
	while (1)
	{
		system("cls");

		switch (Menu())
		{
		case '1':

			ArabicToRoman();

			break;

		case '2':

			return 1;

		default:

			cout << "\nIncorrect input." << endl << "Press any key to continue...";

			_getch();
			break;
		}
	}

	_getch();
	return 1;
}