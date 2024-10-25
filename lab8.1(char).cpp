#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

void Count(char* s, int& countPlus, int& countMinus, int& countEqual)
{
	countPlus = 0;
	countMinus = 0;
	countEqual = 0;

	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '+')
			countPlus++;
		else if (s[i] == '-')
			countMinus++;
		else if (s[i] == '=')
			countEqual++;
	}
}

char* Change(char* s)
{
	char* t = new char[strlen(s) * 2]; // Виділяю достатньо пам'яті для можливих змін
	int pos1 = 0, pos2 = 0;
	*t = 0;

	while (s[pos1] != '\0')
	{
		if ((s[pos1] == '+' && s[pos1 + 1] == '+') ||
			(s[pos1] == '-' && s[pos1 + 1] == '-') ||
			(s[pos1] == '=' && s[pos1 + 1] == '='))
		{
			strcat(t, "***");
			pos1 += 2; // Пропускаємо пару символів
		}
		else
		{
			strncat(t, s + pos1, 1);
			pos1++;
		}
	}
	strcpy(s, t);
	return t;
}

int main()
{
	char str[101];
	cout << "Enter string:" << endl;
	cin.getline(str, 100);

	int countPlus, countMinus, countEqual;
	Count(str, countPlus, countMinus, countEqual);

	cout << "Number of '+' symbols: " << countPlus << endl;
	cout << "Number of '-' symbols: " << countMinus << endl;
	cout << "Number of '=' symbols: " << countEqual << endl;

	char* dest = new char[151];
	dest = Change(str);

	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;

	return 0;
}
