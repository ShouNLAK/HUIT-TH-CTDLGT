#ifndef string_H
#define string_H

#include <string.h>

void StringToUpper(char str[]);
void StringToLower(char str[]);
void LowerTheFirstCharater(char str[]);
void UpperTheFirstCharater(char str[]);
int StringCompare(const char str1[], const char str2[]);
int StringICompare(const char str1[], const char str2[]);
void StringExtract(const char str[], int pos, int len, char strkq[]);
void DeleteEnter(char str[]);

#endif