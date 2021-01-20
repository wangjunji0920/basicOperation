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
private:
	bool sign;
	string value;
};
istream& operator>>(istream& in, bignum& get)
{
	string tmp;
	unsigned i;
	cin >> tmp;
	if (tmp[0] == '-')get.sign = 1;
	else get.sign = 0;
	get.value.resize(tmp.size()+1);
	for (i = 0; i < tmp.size(); i++)
	{
		get.value[tmp.size() - i + 1] = tmp[i];
	}
	return in;
}
ostream& operator<<(ostream& out, bignum get)
{
	unsigned i;
	if (get.sign == 0)
	{
		cout << get.value;
		
	}
	else cout << '-';
	return out;
}
bignum::bignum()
{
	sign = 0;
}
bignum::bignum(string tmp)
{
	unsigned i;
	cin >> tmp;
	if (tmp[0] == '-')sign = 1;
	else sign = 0;
	value.resize(tmp.size() + 1);
	for (i = 0; i < tmp.size(); i++)
	{
		value[tmp.size() - i + 1] = tmp[i];
	}
}