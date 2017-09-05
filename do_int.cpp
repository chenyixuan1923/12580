#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#include "token.h"
#include <map>
map<string, string> Vname;
extern char all_code[500][20];
//extern void do_assign();

void do_int(int start, int end)
{
	for (int do_i = start; do_i != end; do_i++)
	{
		string name = all_code[do_i];
		Vname[name] = "1";

		if ((do_i + 1) != end)
		{
			if (!strcmp(all_code[do_i + 1], ","))
			{
				continue;
			}
			else if (!strcmp(all_code[do_i + 1], "="))
			{
				char RIGHT[10];
				memset(RIGHT, 0, sizeof(RIGHT));
				//do_assign();
				Vname[name].replace(1, Vname[name].size() - 1, RIGHT);
			}
		}
	}
}