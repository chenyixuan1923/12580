#include <iostream>
#include <string>
#include "token.h"
using namespace std;

int p_ = 0;
int line = 0;
char all_code[500][20] = { '0' };


void save_char(char ch)
{
	all_code[line][p_] = ch;
	p_++;
}

int lexical_error(char b_)
{
	cout << "lexical_error!"<< b_<< endl;
	return 1;
}

int get_token(void)
{
	char in_char, c;
	if (feof(stdin))
		return 0;

	while ((in_char = getchar()) != EOF)
	{
		p_ = 0;
		if (isspace(in_char)) //����ո�
			continue;
		else if (isalpha(in_char))//�ж��ַ�ch�Ƿ�ΪӢ����ĸ����ΪӢ����ĸ�����ط�0��Сд��ĸΪ2����д��ĸΪ1������������ĸ������0��
		{
			save_char(in_char);
			for (c = getchar(); isalnum(c); c = getchar())//�ж��ַ�����c�Ƿ�Ϊ��ĸ�����֣������򷵻ط��㣬���򷵻��㡣
				save_char(c);
			ungetc(c, stdin);//��c�˻ص���������
			line++;    //������λ��һ
			return 0;
		}
		else if (isdigit(in_char))
		{
			save_char(in_char);
			for (c = getchar(); isdigit(c)||c=='.'; c = getchar())
				save_char(c);
			line++;
			ungetc(c, stdin);
			return 0;
		}
		else if (in_char == '(')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == ')')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == ';')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == ',')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '+')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		/*	else if (in_char == ':')
		{
		ungetc(c, stdin);
		lexical_error(in_char);
		*/
		else if (in_char == '=')
		{
			save_char(in_char);
			c = getchar();
			if (c == '=')
			{
				save_char(c);
				line++;
				return 0;
			}
			else
			{
				ungetc(c, stdin);
				line++;
				return 0;
			}

		}
		else if (in_char == '-')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '/')
		{
			c = getchar();
			if (c == '/')
			{
				while ((in_char = getchar()) != '\n');
			}
			else
			{
				ungetc(c, stdin);
				save_char(in_char);
				line++;
				return 0;
			}
		}
		else if (in_char == '"')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '*')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '%')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '<')
		{
			save_char(in_char);
			c = getchar();
			if (c == '=')
			{
				save_char(c);
				line++;
				return 0;
			}
			else if (c == '>')
			{
				save_char(c);
				line++;
				return 0;
			}
			else
			{
				ungetc(c, stdin);
				line++;
				return 0;
			}
		}
		else if (in_char == '>')
		{
			save_char(in_char);
			c = getchar();
			if (c == '=')
			{
				save_char(c);
				line++;
				return 0;
			}
			else
			{
				ungetc(c, stdin);
				line++;
				return 0;
			}
		}
		else if (in_char == '&')
		{
			save_char(in_char);
			c = getchar();
			if (c == '&')
			{
				save_char(c);
				line++;
				return 0;
			}
			else lexical_error(in_char);
		}
		else if (in_char == '|')
		{
			save_char(in_char);
			c = getchar();
			if (c == '|')
			{
				save_char(c);
				line++;
				return 0;
			}
			else lexical_error(in_char);
		}
		else if (in_char == '!')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '$')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == '#')
		{
			save_char(in_char);
			line++;
			return 0;
		}
		else if (in_char == 92)
		{
			save_char(92);
			c = getchar();
			if (c == 'n')
			{
				save_char(c);
				line++;
				return 0;
			}
			return 0;
		}
		else lexical_error(in_char);
	}
}
