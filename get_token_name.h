#include <iostream>
using namespace std;
typedef enum token_types {
	DELIMITER,//��ʾ�ָ���; | +-
	IDENTIFIER,//��ʾID��ʾ�� var hello
	KEYWORD,//�ؼ���
	SSTRING,//�ַ���
	CHARACTOR,//�ַ�
	NUMBER,//���ֳ���
	TYPE,//���� typedef int int32;��ôint32�ͱ���ʾΪTYPE

	PRECOMPILE,//Ԥ������ #define
	TEMP,//����
	SEMICOLON,//�ֺš�
	COMMA,  //����
	ASSIGNOP,//��ֵ

	SCANEOF,  //�ļ���β���

	LPRAEN,   //������
	RPRAEN,   //������
	LBLOCK,//���־ {
	RBLOCK,//���־ }
	Double_quotes,//˫����
	Single_quote,//������
	ENTER,    //�س�
	INTLITERAL, //û��ɶ��˼
	/* �������� */
	OP_plus,  //��
	OP_minus, //��
	OP_multiply,//��
	OP_divide,//��
	OP_mod,//ģ
	/* ��ϵ���� */
	OP_lt,            // С��
	OP_gt,            // ����
	OP_eq,            // ����
	OP_le,            // С�ڵ���
	OP_ge,            // ���ڵ���
	OP_ne,            // ������
	/* �߼����� */
	OP_and,           // ��
	OP_or,            // ��
	OP_not,           // ��
	//$����
	OP_link,
	//#ɾ��һ���ַ�
	OP_delete,
	key_in,  // INPUT  
	key_out,      // PRINT  
	key_while,      // WHILE   
	key_if,         // IF  
	key_else,       // ELSE
	key_int,     //int
	key_real,     //ʵ��
	key_string   //�ַ���												   
} token;
token get_token_name(int a_);
