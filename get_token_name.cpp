#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include "token.h"
#include "get_token_name.h"

extern char all_code[500][20];

token check_reserved(int token_line)  //token_line�����к�
{
	if (!strcmp(all_code[token_line], "in"))
	{
		return key_in;
	}
	else if (!strcmp(all_code[token_line], "out"))
	{
		return key_out;
	}
	else if (!strcmp(all_code[token_line], "while"))
	{
		return key_while;
	}
	else if (!strcmp(all_code[token_line], "if"))
	{
		return key_if;
	}
	else if (!strcmp(all_code[token_line], "else"))
	{
		return key_else;
	}
	else if (!strcmp(all_code[token_line], "int"))
	{
		return key_int;
	}
	else if (!strcmp(all_code[token_line], "real"))
	{
		return key_real;
	}
	else if (!strcmp(all_code[token_line], "string"))
	{
		return key_string;
	}
	else
	{
		return IDENTIFIER;
	}
}
token get_token_name(int a_)
{
	int get_name_num = 0;
	int get_name_temp = 0;
		if (isalpha(all_code[a_][get_name_num]))////�ж��ַ�ch�Ƿ�ΪӢ����ĸ����ΪӢ����ĸ�����ط�0��Сд��ĸΪ2����д��ĸΪ1������������ĸ������0��
		{
			return check_reserved(a_);//��Ϊǰ��token.cpp���Ѿ��������Ƿ�Ϊ�ؼ��ֻ��߱��������Բ������ж���
		}
		else if (isdigit(all_code[a_][get_name_num]))
		{
			return INTLITERAL; //�������ֱ�ʶ��
		}
		else if (all_code[a_][get_name_num] == '(')
		{
			return LPRAEN;
		}
		else if (all_code[a_][get_name_num] == ')')
		{
			return RPRAEN;
		}
		else if (all_code[a_][get_name_num] == ';')
		{
			return SEMICOLON;
		}
		else if (all_code[a_][get_name_num] == ',')
		{
			return COMMA;
		}
		else if (all_code[a_][get_name_num] == '+')
		{
			return OP_plus;
		}
		/*	else if (in_char == ':')
		{
		ungetc(c, stdin);
		lexical_error(in_char);
		*/
		else if (all_code[a_][get_name_num] == '=')
		{
			if (all_code[a_][get_name_num + 1] == '=')
			{
				return OP_eq;
			}
			else
			{
				return ASSIGNOP;
			}

		}
		else if (all_code[a_][get_name_num] == '-')
		{
			return OP_minus;
		}
		else if (all_code[a_][get_name_num] == '/')
		{
			return OP_divide;
		}
		else if (all_code[a_][get_name_num] == '"')
		{
			return Double_quotes;
		}
		else if (all_code[a_][get_name_num] == '*')
		{
			return OP_multiply;
		}
		else if (all_code[a_][get_name_num] == '%')
		{
			return OP_mod;
		}
		else if (all_code[a_][get_name_num] == '<')
		{

			if (all_code[a_][get_name_num + 1] == '=')
			{
				return OP_le;
			}
			else if (all_code[a_][get_name_num + 1] == '>')
			{
				return OP_ne;
			}
			else
			{
				return OP_lt;
			}
		}
		else if (all_code[a_][get_name_num] == '>')
		{
			if (all_code[a_][get_name_num + 1] == '=')
			{
				return OP_ge;
			}
			else
			{
				return OP_gt;
			}
		}
		else if (all_code[a_][get_name_num] =='&')
		{
			if (all_code[a_][get_name_num + 1] == '&')
			{
				return OP_and;
			}
			else lexical_error(all_code[a_][get_name_num]);
		}
		else if (all_code[a_][get_name_num] == '|')
		{
			if (all_code[a_][get_name_num + 1] == '|')
			{
				return OP_or;
			}
			else lexical_error(all_code[a_][get_name_num]);
		}
		else if (all_code[a_][get_name_num] == '!')
		{
			return OP_not;
		}
		else if (all_code[a_][get_name_num] == '$')
		{
			return OP_link;
		}
		else if (all_code[a_][get_name_num] == '#')
		{
			return OP_delete;
		}
		else if (all_code[a_][get_name_num] ==92)
		{
			if (all_code[a_][get_name_num + 1] == 'n')
			{
				return ENTER;
			}
		}
		else lexical_error(all_code[a_][get_name_num]);
	}
