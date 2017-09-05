#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include "do_int.h"
#include "token.h"
#include "get_token_name.h"
#include <map>
extern map<string, string> Vname;
extern char all_code[500][20];
extern token get_token_name(int line);

void do_in(int start,int end)
{
	string in_name;
	string in_val;
	switch (get_token_name(start)) 
	{
		case IDENTIFIER:
		{
			in_name = all_code[start];
		}
		case Double_quotes:
		{
			in_val = all_code[start];
			cout << in_val.substr(1, in_val.size() - 2);
		}
	}

}