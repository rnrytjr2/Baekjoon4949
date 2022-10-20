// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
	while (true)
	{
		stack<char> PSs;
		string balancestring;
		cin.ignore();
		getline(cin, balancestring, '.');

		if (balancestring.size() == 0)
		{
			break;
		}

		for (int i = 0; i < balancestring.size(); i++)
		{
			if (balancestring[i] == '[')
			{
				PSs.push(balancestring[i]);
			}
			else if (balancestring[i] == ']')
			{
				if (PSs.size() > 0)
				{

					if (PSs.top() == '[')
					{
						PSs.pop();
					}
					else
					{
						PSs.push('!');
						break;
					}
				}
				else
				{
					PSs.push('!');
					break;
				}
			}
			else if (balancestring[i] == '(')
			{
				PSs.push(balancestring[i]);
			}
			else if (balancestring[i] == ')')
			{
				if (PSs.size() > 0)
				{
					if (PSs.top() == '(')
					{
						PSs.pop();
					}
					else
					{
						PSs.push('!');
						break;
					}
				}
				else
				{
					PSs.push('!');
					break;
				}
			}
		}
		if (PSs.size() == 0)
		{
			cout << "yes" << '\n';
		}
		else
		{
			cout << "no" << '\n';
		}
	}
}
