#include <iostream>
#include <string>
#include <stack>
#include "Matrix.h"
#include "Parser.h"
#include "ErrorHandler.h"
#include "Evaluator.h"

#include <iostream>
using namespace std;

token::token(Matrix* M, int C, bool b)
{
	m=M;
	c=C;
	is_op = b;
}

Matrix* token::getm()
{
	return m;
}

int token::getc()
{
	return c;
}

bool token::getis_op()
{
	return is_op;
}

token* PLUS_T = new token(NULL, '+', true);
token* STAR_T = new token(NULL, '*', true);
token* BOPEN_T = new token(NULL, '(', true);

token* PLUS()
{
	return PLUS_T;
}

token* STAR()
{
	return STAR_T;
}

token* BOPEN()
{
	return BOPEN_T;
}

token* constant(int val)
{
	token* t = new token(NULL, val, false);
	return t;
}

token* matrix(Matrix* val)
{
	token* t = new token(val, 0, false);
	return t;
}

token* v(int val)
{
	return constant(val);
}

// Converts Infix to Postfix in Stack
std::stack<token*> parse(std::string s)
{
	std::stack<token*> st;
	Matrix* m = new Matrix(3);
	token* t = matrix(m);
	const char* arr = s.c_str();
	int l = s.length();
	int brackets = 0;
	int x = 0;
	stack<token*> op;
	for (int i = 0; i < l && brackets >= 0; i++)
	{
		switch (arr[i])
		{
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				x = 10*x + (arr[i]-'0');
				if (i == l-1 || arr[i+1] > '9' || arr[i+1] < '0')
				{
					st.push(v(x));
cout << arr[i];
					x=0;
				}
				break;

			case '+':
				op.push(PLUS());
				break;

			case '*':
				op.push(STAR());
				break;

			case '(':
				if (i == l-1)
				{
					throw error_bracket_mismatch();
				}
				else if (arr[i+1]<'0' || (arr[i+1] > '9' && arr[i+1]!='A'))
				{
					throw error_operand_missing();
				}
				op.push(BOPEN());
				brackets++;
				break;

			case 'A':
				if ((i!=0 && ((arr[i-1] >='0' && arr[i-1] <='9') || arr[i-1] == 'A')
					|| (i!=l-1 && ((arr[i+1] >='0' && arr[i+1] <='9') || arr[i+1] == 'A'))
					throw error_operand_invalid();
				st.push(t);
cout << "A";
				break;

			case ')':
				if (i == 0)
				{
					throw error_bracket_mismatch();
				}
				else if (arr[i-1]<'0' || (arr[i-1] > '9' && arr[i-1]!='A'))
				{
					throw error_operand_missing();
				}
				brackets--;
				if (brackets < 0)
				{
					throw error_bracket_mismatch();
				}
				while (1)
				{
					token* tok = op.top();
					if (tok == BOPEN())
					{
						if (arr[i-1] == '(')
							throw error_empty_brackets();
						else
						{
							op.pop();
							break;
						}
					}
					st.push(tok);
cout << ((char) tok->getc());
					op.pop();
				}
				break;

			default:
				throw error_expression_invalid();
		}
	}
	if (brackets != 0)
		throw error_bracket_mismatch();
	while (op.size())
	{
		st.push(op.top());
cout << ((char) op.top()->getc());
		op.pop();
	}
cout << endl;
	return st;
}
