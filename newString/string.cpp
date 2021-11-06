#include<iostream>
#include<Windows.h>
using namespace std;

int stringLenght(char str[]);
int wordLenght(char str[]);
void upperString(char str[]);
void lowerString(char str[]);
int occurrenceSymbol(char str[], char symbol);
int occurrenceSymbolLenght(char str[], char symbol);
int indexOccurrence(char str[], char string[]);
int entranceString(char str[], char string[]);
void coupString(char str[]);
void removingSigns(char str[]);
int comparisonStrings(char str[], char str2[]);
void ConcatenationStrings(char str[], const char str2[]);
void print(char str[]);
void receivingString(char str2[], char str3[], int num);

int main()
{

	const int num = 255;
	char str[num],
		str2[num],
		str3[num];


	cout << "Enter string" << endl;
	cin.getline(str,num);

	cout << "Enter string" << endl;
	cin.getline(str2, num);

	cout << str2 << endl;

	const int lenght = stringLenght(str) + stringLenght(str2) - 1;

	cout << lenght << endl;

	cout << stringLenght(str) << endl;

	cout << wordLenght(str) << endl;

	upperString(str);

	cout << str << endl;

	lowerString(str);
	
	print(str);

	char symbol;

	cout << "Enter symbol: ";
	cin >> symbol;

	if (occurrenceSymbol(str, symbol))
	{
		cout << "YES" << endl;
		cout << occurrenceSymbolLenght(str, symbol) << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	char string[num];

	cout << "Enter string:" << endl;
	cin >>string;

	cout << indexOccurrence(str, string) << endl;

	if (entranceString(str, string))
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}

	coupString(str);

	cout << str << endl;

	removingSigns(str);

	cout << str << endl;

	if (comparisonStrings(str, str2))
	{
		cout << "The lines are the same" << endl;
	}
	else
	{
		cout << "The lines are different" << endl;
	}

	const int number = stringLenght(str) + stringLenght(str2);

	cout << number << endl;


	cout << stringLenght(str) << endl;

	ConcatenationStrings(str, str2);

	print(str);

	int num2;

	cout << "Enter number: ";
	cin >> num2;

	receivingString(str2, str3, num2);

	print(str3);

	return 0;
}

int stringLenght(char str[])
{
	int i = 0;
	for (; str[i]; ++i);
	return i;
}

int wordLenght(char str[])
{
	int counter = 1;
	
	for (int i = 0; str[i]; ++i)
	{
		if (!(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z'))
		{
			++counter;
		}
	}

	return counter;
}

void upperString(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
	}
}

void lowerString(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
}

int occurrenceSymbol(char str[], char symbol)
{
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == symbol)
		{
			return true;
		}
	}
	return false;
}

int occurrenceSymbolLenght(char str[], char symbol)
{
	int counter = 0;
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == symbol)
		{
			++counter;
		}
	}
	return counter;
}

int indexOccurrence(char str[], char string[])
{
	bool n = false;
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == string[0])
		{
			n = true;

			for (int j = 0; string[j]; ++j)
			{
				if (str[i + j] != string[j])
				{
					n = false;
					break;
				}
			}

			if (n == true)
			{
				return i;
			}
		}
	}
	return -1;
}

int entranceString(char str[], char string[])
{
	bool n = false;
	for (int i = 0; str[i]; ++i)
	{
		if (str[i] == string[0])
		{
			n = true;

			for (int j = 0; string[j]; ++j)
			{
				if (str[i + j] != string[j])
				{
					n = false;
					break;
				}
			}

			if (n == true)
			{
				return n;
			}
		}
	}
	return n;
}

void coupString(char str[])
{
	int lenght = stringLenght(str) - 1;
	const int num = 255;
	char str2[num];

	for (int i = 0; str[i]; ++i)
	{
		str2[i] = str[lenght - i];
	}

	for (int i = 0; str[i]; ++i)
	{
		str[i] = str2[i];
	}
	
}

void removingSigns(char str[])
{

	for (int i = 0; str[i]; ++i)
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'a' && str[i] <= 'z' || str[i] == ' '))
		{

			for (int j = i; str[j]; ++j)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

int comparisonStrings(char str[], char str2[])
{
	if (stringLenght(str) != stringLenght(str2))
	{
		return false;
	}

	for (int i = 0; str[i]; ++i)
	{
		if (str[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}

void ConcatenationStrings(char str[], const char str2[])
{
	
	for (int i = 0; i <= stringLenght(str); ++i)
	{
		if (i == stringLenght(str))
		{
			while (*str2)
			{
				str[i] = *str2++;
				i++;
			}
		}
	}
}

void print(char str[])
{
	for (int i = 0; str[i]; ++i)
	{
		cout << str[i];
	}
}

void receivingString(char str2[], char str3[], int num)
{
	if (num >= stringLenght(str2))
	{
		for (int i = 0; str2[i]; ++i)
		{
			str3[i] = str2[i];
		}
	}
	else
	{
		for (int i = 0; i < num; ++i)
		{
			str3[i] = str2[i];
		}
	}
}

