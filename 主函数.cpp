#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
#include "token.h"
#include "get_token_name.h"
extern int line;
int main()
{
	char c_;
	int i_;
	freopen("in.txt", "r", stdin);
	while ((c_ = getchar()) != EOF)
	{
			ungetc(c_, stdin);
			int check = get_token();
			if (check==1) return 0;  //��һ�������û�д��󡣲�û�з�������
	}
	for (i_ = 0; i_ < line; i_++)
	{
		cout << get_token_name(i_)<<endl;
	}
	system("pause");
	return 0;
}

