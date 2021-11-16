#include<iostream>
#include<string>
using namespace std;
class num
{
public :
	num(string x = "0")
	{
		initial(x);
	}
	void initial(string number)
	{
		int tmp = 0;
		if (number[0] == 45)
		{
			sign = -1;
			size = number.length() - 1; 
			tmp = 1;
		}
		else
		{
			sign = 1;
			size = number.length();
			tmp = 0;
		}
		A = new int[size];
		for (int i = 0 + tmp; i < size + tmp;i++)
		{
			A[i - tmp] = number[i]-48;
		}
	}
	int getsize()
	{
		return size;
	}
	int getsign()
	{
		return sign;
	}
	void printnumber()
	{
		if (sign == -1)
		{
			cout << "-";
		}
		for (int i = 0; i < size; i++)
		{
			cout << to_string(A[i]);
		}
	}
	int& operator[](int x)
	{
		if (x<0||x < size)
		{
			return A[x];
		}
	}
private:
	int* A;
	int sign;
	int size;
};
void addition(num*, num, num);
void subtraction(num*, num, num);
void multiplication(num*, num, num);
int main()
{
	string A;
	string B;
	cin >> A;
	cin >> B;
	num num1(A);
	num num2(B);
	num result1;
	num result2;
	num result3;
	addition(&result1, num1, num2);
	result1.printnumber();
	cout << endl;
	subtraction(&result2, num1, num2);
	result2.printnumber();
	cout << endl;
	multiplication(&result3, num1, num2);
	result3.printnumber();
	cout << endl;
	return 0;
}
void addition(num* result1, num num1, num num2)
{
	int sznum1 = num1.getsize();
	int sznum2 = num2.getsize();
	string sign = "";
	string result = "0";
	string tmp = "0";

	if (num1.getsign() == num2.getsign())
	{
 		if (num1.getsign() == 1)
		{
			sign = "";
		}
		else
		{
			sign = "-";
		}
		int a = 0;
		int b = 0;
		int alpha = 0;
		int i = 0;
		while (i <= sznum1 || i <= sznum2)
		{
			if (i < sznum1 && i< sznum2)
			{
				a = num1[sznum1 - i - 1];
				b = num2[sznum2 - i - 1];
			}
			else if(i>=sznum2||i>=sznum1)
			{
				if (i < sznum1)
				{
					a = num1[sznum1 - i - 1];
					b = 0;
				}
				else if (i < sznum2)
				{
					a = 0;
					b = num2[sznum2 - i - 1];
				}
				else if (i >= sznum1 && i >= sznum2)
				{
					a = 0;
					b = 0;
				}
			}
			
			if (tmp.length() >= i + 1)
			{
				tmp[tmp.length() - i - 1] = (a + b + alpha) % 10 + '0';
			}
			else
			{
				tmp.insert(0,to_string(( a + b + alpha) % 10));
			}
			if (( a + b + alpha < 10))
			{
				alpha = 0;
			}
			else
			{
				alpha = 1;
			}
			i = i + 1;
		} 
	}
	else
	{
		string inputA = "";
		string inputB = "";
		for (int i = 0; i < num1.getsize(); i++)
		{
			inputA.insert(0,to_string(num1[i]));
		}
		for (int j = 0; j < num1.getsize(); j++)
		{
			inputB.insert(0, to_string(num2[j]));
		}
		num input1(inputA);
		num input2(inputB);
		num result2;
		subtraction(&result2, input1, input2);
		if (num1.getsign() == 1)
		{
			sign = "";
		}
		else
		{
			sign = "-";
		}
		for (int k = 0; k < result2.getsize(); k++)
		{
			tmp.insert(0, to_string(result2[k]));
		}
	}
	if (tmp == "0")
	{
		tmp = "";
	}
	else
	{
		tmp.insert(0, sign);
	}
	if (tmp != "")
	{
		result1->initial(tmp);
	}
	else
	{
		result1->initial(result);
	}
}
void subtraction(num* result1, num num1, num num2)
{
	int sznum1 = num1.getsize();
	int sznum2 = num2.getsize();
	string sign = "";
	string result = "0";
	string tmp = "";
	char casetype;
	if (num1.getsign() != num2.getsign())
	{
		if (num1.getsign() == 1)
		{
			sign = "";
		}
		else
		{
			sign = "-";
		}
		string inputA = "";
		string inputB = "";
		for (int i = 0; i < num1.getsize(); i++)
		{
			inputA.insert(0, to_string(num1[i]));
		}
		for (int j = 0; j < num1.getsize(); j++)
		{
			inputB.insert(0, to_string(num2[j]));
		}
		num input1(inputA);
		num input2(inputB);
		num result2;
		addition(&result2, input1, input2);
		for (int i = 0; i < result2.getsize(); i++)
		{
			tmp.insert(0, to_string(result2[i]));
		}
	}
	else
	{
		if (num1.getsize() == num2.getsize())
		{
			for (int i = 0; i < num1.getsize(); i++)
			{
				if (num1[i] > num2[i])
				{
					casetype = 'A';
					break;
				}
				else if (num1[i] < num2[i])
				{
					casetype = 'B';
					break;
				}
				else
				{
					if (i == num1.getsize() - 1)
					{
						sign = "";
						casetype = 'C';
					}
				}
			}
		}
		else if(num1.getsize() > num2.getsize())
		{
			casetype = 'A';
		}
		else
		{
			casetype = 'B';
		}

		if (casetype == 'A')
		{
			if (num1.getsign() == 1)
			{
				sign = "";
			}
			else
			{
				sign = "-";
			}
			int alpha = 0;
			for (int i = 0; i < sznum1; i++)
			{
				if (i == 0)
				{
					for (int j = 0; j < sznum2; j++)
					{
						tmp.insert(0, to_string(num2[sznum2 - j - 1]));
					}
				}
				if (i < sznum2)
				{
					if (tmp[sznum2 - i - 1] - '0' <= (num1[sznum1 - i - 1] + alpha))
					{
						tmp[sznum2 - i - 1] = (num1[sznum1 - i - 1] + '0') - tmp[sznum2 - i - 1] + alpha + '0';
					}
					else
					{
						tmp[sznum2 - i - 1] = (tmp[sznum2 - i - 1] + '0') - num1[sznum1 - i - 1] + alpha + '0';
						alpha = -1;
					}

				}
				else
				{
					tmp.insert(0, to_string(num2[sznum1 - i - 1] + alpha));
				}
			}
		}
		else if (casetype == 'B')
		{
			if (num2.getsign() == 1)
			{
				sign = "-";
			}
			else
			{
				sign = "";
			}
			string inputA = "";
			string inputB = "";
			for (int i = 0; i < num1.getsize(); i++)
			{
				inputA.insert(0, to_string(num1[i]));
			}
			for (int j = 0; j < num1.getsize(); j++)
			{
				inputB.insert(0, to_string(num2[j]));
			}
			num input1(inputA);
			num input2(inputB);
			num result2;
			subtraction(&result2, input1, input2);
			for (int i = 0; i < result2.getsize(); i++)
			{
				tmp.insert(0, to_string(result2[i]));
			}
		}
	}
	if (tmp == "0")
	{
		tmp = "";
	}
	else
	{
		tmp.insert(0, sign);
	}	if (tmp != "")
	{
		result1->initial(tmp);
	}
	else
	{
		result1->initial(result);
	}
}
void multiplication(num* result1, num num1, num num2)
{
	int sznum1 = num1.getsize();
	int sznum2 = num2.getsize();
	string sign = "";
	string result = "0";
	string tmp="";
	int alpha = 0;
	int beta = 0;
	int theta = 0;
	if (num1.getsign() == num2.getsign())
	{
		sign = "";
	}
	else
	{
		sign = "-";
	}
	for (int i = sznum2 - 1; i >= 0; i--)
	{
		for (int j = sznum1 - 1; j >= 0; j--)
		{
			beta = (num1[j] * num2[i] + alpha) % 10;
			if (tmp.length() == sznum1 + sznum2 - (i + j) - 2)
			{
				alpha = (alpha + (num1[j]) * (num2[i])) / 10;
				if (alpha != 0)
				{
					tmp.insert(0, to_string(beta));
					tmp.insert(0, to_string(alpha));
				}
				else
				{
					tmp[tmp.length() - sznum1 - sznum2 + i + j + 1] = (tmp[tmp.length() - sznum1 - sznum2 + i + j + 1] - '0' + beta) % 10 + '0';
				}
			}
			else
			{
				alpha = (alpha + num1[j] * num2[i] + tmp[tmp.length() - sznum1 - sznum2 + i + j + 1] - '0') / 10;
				tmp[tmp.length()-sznum1-sznum2+i+j+1] = (tmp[tmp.length() - sznum1 - sznum2 + i + j + 1] - '0' + beta) % 10 + '0';
			}
		}
		alpha = 0;
	}
	if (tmp == "0")
	{
		tmp = "";
	}
	else
	{
		tmp.insert(0, sign);
	}
	if (tmp != "")
	{
		result1->initial(tmp);
	}
	else
	{
		result1->initial(result);
	}
}
