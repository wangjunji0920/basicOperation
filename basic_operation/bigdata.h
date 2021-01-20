#pragma once
#include<vector>
#include<istream>
#include<ostream>
#include<iostream>
#include<string>
using namespace std;
class bignum
{
public:
	bignum();
	bignum(string);
	friend istream& operator>>(istream& in, bignum&);
	friend ostream& operator<<(ostream& out, bignum);
	bignum operator+(const bignum&);
	bignum operator-(const bignum&);
	bool operator>(const bignum&);
	bool operator<(const bignum&);
	bool operator>=(const bignum&);
	bool operator<=(const bignum&);
	bool operator==(const bignum&);
	bool operator!=(const bignum&);
private:
	bool sign;
	string value;
};
istream& operator>>(istream& in, bignum& get)
{
	string tmp;
	unsigned i;
	cin >> tmp;
	get.value.resize(tmp.size() + 1);
	if (tmp[0] == '-')
	{
		get.sign = 1;
		for (i = 1; i < tmp.size(); i++)
		{
			get.value[tmp.size() - i + 1] = tmp[i];
		}
	}
	else
	{
		get.sign = 0;
		for (i = 0; i < tmp.size(); i++)
		{
			get.value[tmp.size() - i + 1] = tmp[i];
		}
	}
	return in;
}
ostream& operator<<(ostream& out, bignum get)
{
	unsigned i;
	if (get.sign == 0)
	{
		for (i = get.value.size(); i >= 1; i--)
		{
			cout << get.value[i];
		}
	}
	else
	{
		cout << '-';
		for (i = get.value.size(); i >= 1; i--)
		{
			cout << get.value[i];
		}
	}
	return out;
}
bignum::bignum()
{
	sign = 0;
}
bignum::bignum(string tmp)
{
	unsigned i;
	value.resize(tmp.size() + 1);
	if (tmp[0] == '-')
	{
		sign = 1;
		for (i = 1; i < tmp.size(); i++)
		{
			value[tmp.size() - i + 1] = tmp[i];
		}
	}
	else
	{
		sign = 0;
		for (i = 0; i < tmp.size(); i++)
		{
			value[tmp.size() - i + 1] = tmp[i];
		}
	}
}
bignum bignum::operator+(const bignum& addition)
{
	
}