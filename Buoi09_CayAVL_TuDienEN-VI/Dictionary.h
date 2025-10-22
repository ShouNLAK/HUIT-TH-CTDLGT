#ifndef _DICTIONARY_H
#define _DICTIONARY_H
#include "AVLTree.h"
#include "StringProcess.h"
//==============================================================
void LoadDictionary(char *filename, AVLTree &avl, int &countWord)
{
	ItemType in_word;
	char strLine[255], temp[100];
	FILE *fio = fopen(filename, "rt");
	if (!fio)
	{
		printf("Error load file!");
		return;
	}
	countWord = 0;
	while (fgets(strLine, 255, fio) != NULL)
	{
		char*pdest = strstr(strLine, ":");
		int pos = (int)(pdest - strLine);
		StringExtract(strLine, 0, pos, temp);
		strcpy(in_word.Word, temp);
		StringExtract(strLine, pos + 2, strlen(strLine) - 1, temp);
		DeleteEnter(temp);
		strcpy(in_word.Meaning, temp);
		UpperTheFirstCharater(in_word.Word);
		UpperTheFirstCharater(in_word.Meaning);

		AVLNode *p = createAVLNode(in_word);
		if (insertAVLNode(avl.Root, p) == 0) continue;
		countWord++;
	}
	fclose(fio);
}
//==============================================================
void WriteInformationAVLNode(FILE *fio, ItemType x)
{
	if (strlen(x.Word) == 0) return;
	fprintf(fio, "\n%s: %s", x.Word, x.Meaning);
}
//==============================================================
void WriteAVLTree(FILE *fio, AVLNode*T)
{
	if (!T) return;
	WriteInformationAVLNode(fio, T->Info);
	WriteAVLTree(fio, T->Left);
	WriteAVLTree(fio, T->Right);
}
//==============================================================
void WriteDictionary(char* fileName, AVLTree avl)
{
	FILE *fio = fopen(fileName, "wt");
	if (!fio)
	{
		printf("Error load file!");
		return;
	}
	WriteAVLTree(fio, avl.Root);
	fclose(fio);
	printf("\nWrite success to file!");
}
//==============================================================
void WriteAddDictionary(char *fileName, ItemType x)
{
	FILE *fio = fopen(fileName, "a");
	if (!fio)
	{
		printf("Error load file!");
		return;
	}
	WriteInformationAVLNode(fio, x);
	fclose(fio);
	printf("\nInput and write success to file!");
}

#endif