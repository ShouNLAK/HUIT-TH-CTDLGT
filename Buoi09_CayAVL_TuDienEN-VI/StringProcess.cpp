#include "StringProcess.h"
//==============================================================
void StringToUpper(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}
//==============================================================
void StringToLower(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}
//==============================================================
void LowerTheFirstCharater(char str[])
{
	if (str[0] >= 'A' && str[0] <= 'Z')
		str[0] += 32;
}
//==============================================================
void UpperTheFirstCharater(char str[])
{
	if (str[0] >= 'a' && str[0] <= 'z')
		str[0] -= 32;
}
//==============================================================
int StringCompare(const char str1[], const char str2[])
{
	int i, j;
	i = j = 0;
	while (str1[i] != '\0' && str2[j] != '\0')
	{
		if (str1[i] > str2[j])
			return 1;
		if (str1[i] < str2[j])
			return -1;
		i++;
		j++;
	}
	if (str1[i] != '\0')
		return 1;
	if (str2[j] != '\0')
		return -1;
	return 0;
}
//==============================================================
void StringExtract(const char str[], int pos, int len, char strkq[])
{
	int j = 0;
	for (int i = pos; i < (pos + len); i++)
		strkq[j++] = str[i];
	strkq[j] = '\0';
}
//==============================================================
void DeleteEnter(char str[])
{
	StringExtract(str, 0, strlen(str) - 1, str);
}