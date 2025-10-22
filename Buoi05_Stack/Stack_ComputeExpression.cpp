/*
Họ và tên : Nguyễn Lê Anh Khoa
Lớp :		THCTDL&GT - SL4 - A211
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

typedef float ItemType;
struct StackNode
{//Tạo 1 node
	ItemType Info;
	StackNode* Next;
};
//==============================================================
struct Stack
{//Tạo 1 danh sách các Node
	StackNode *Top;
};
//==============================================================
StackNode* createStackNode(ItemType x)
{//Tạo 1 node mới
	StackNode* p = new StackNode;
	if (p == NULL)
	{
		printf("Khong the cap phat bo nho !");
		getch();
		return NULL;
	}
	p->Info = x; // Gán giá trị 
	p->Next = NULL;// Giá địa chỉ (mặc dịnh là node)
	return p;
}
//==============================================================
void showStackNode(StackNode* p)
{//Hiển thị 1 Node
	printf("%d", p->Info);
}
//==============================================================
void initStack(Stack& st)
{//Set địa chỉ Top - Tail
	st.Top = NULL;
}
//==============================================================
int isEmpty(Stack st)
{// Check Stack rỗng hay không 
	return st.Top == NULL ? 1 : 0;
}
//==============================================================
int push(Stack& st, ItemType x)
{//Chèn lên đầu Stack
	StackNode*p = createStackNode(x);
	if (!x)
		return 0;
	p->Next = st.Top;
	st.Top = p;
	return 1;
}
//==============================================================
int pop(Stack &st, ItemType &x)
{
	if (isEmpty(st) == 1)
		return 0;
	StackNode *p = st.Top;
	st.Top = st.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}
//==============================================================
int getTop(Stack &st, ItemType &x)
{
	if (isEmpty(st) == 1)
		return 0;
	x = st.Top->Info;
	return 1;
}
//==============================================================
int precedence(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}
//==============================================================
void infixToPostfix(char infix[], char postfix[])
{
	Stack S;
	ItemType x;
	char token;
	int i = 0, j = 0;
	initStack(S);
	for (int i = 0; infix[i] != '\0'; i++)
	{
		token = infix[i];
		if (isalnum(token))
		{
			postfix[j++] = token;
			continue;
		}
		else
		{
			postfix[j++] = ' ';
			if (token == '(')
				push(S, '(');
			else
			{
				if (token == ')')
				{
					while (pop(S, x) == 1 && x != '(')
					{
						postfix[j++] = x;
						postfix[j++] = ' ';
					}
				}
				else
				{
					while (getTop(S, x) == 1 && precedence(token) <= precedence(x))
					{
						if (pop(S, x) == 1)
						{
							postfix[j++] = x;
							postfix[j++] = ' ';
						}
					}
					push(S, token);
				}
			}
		}
	}
	while (!isEmpty(S))
	{
		if (pop(S, x) == 1)
		{
			postfix[j++] = ' ';
			postfix[j++] = x;
		}
	}
	postfix[j] = '\0';
}
//==============================================================
float computeExpressionValue(char *Postfix)
{
	Stack S;
	char* p;
	ItemType operand1, operand2;
	float result;
	initStack(S);
	p = &Postfix[0];
	while (*p != '\0')
	{
		while (*p == ' ' || *p == '\t')
		{
			p++;
		} if (isdigit(*p))
		{
			int num = 0;
			while (isdigit(*p))
			{
				num = num * 10 + *p - 48;
				*p++;
			}
			push(S, num);
		}
		else
		{
			pop(S, operand1);
			pop(S, operand2);
			switch (*p)
			{
			case '+' :
				result = operand2 + operand1;
				break;
			case '-':
				result = operand2 - operand1;
				break;
			case '/' :
				result = operand2 / operand1;
				break;
			case '*' :
				result = operand2 * operand1;
				break;
			}
			push(S, result);
		}
		p++;
	}
	pop(S, result);
	return result;
}
//==============================================================
void Stack_ComputeExpressionValue(char strExpression[])
{
	char postfix[100] = "";
	float kq;
	infixToPostfix(strExpression, postfix);
	printf("Bieu thuc Postfix : %s", postfix);
	kq = computeExpressionValue(postfix);
	printf("\nGia tri bieu thuc : %f", kq);
}
//==============================================================
void main()
{
	char strExpression[] = "((7 + 3) * 2 - 10 / 2) + 5";
	Stack_ComputeExpressionValue(strExpression);
	getch();
}