#pragma once
#include<vector>
#include<istream>
#include<ostream>
#include<iostream>
#include<string>
using namespace std;
class basic_bignum
{
public:
	basic_bignum();
	basic_bignum(string);
	friend istream& operator>>(istream& in, basic_bignum&);
	friend ostream& operator<<(ostream& out, basic_bignum);
	basic_bignum operator+(basic_bignum);
	basic_bignum operator-(const basic_bignum&);
	bool operator>(const basic_bignum&);
	bool operator<(const basic_bignum&);
	bool operator>=(const basic_bignum&);
	bool operator<=(const basic_bignum&);
	bool operator==(const basic_bignum&);
	bool operator!=(const basic_bignum&);
private:
	basic_bignum(unsigned long long size);
	bool sign;
	string value;
};
istream& operator>>(istream& in, basic_bignum& get)
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
ostream& operator<<(ostream& out, basic_bignum get)
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
basic_bignum::basic_bignum()
{
	sign = 0;
}
basic_bignum::basic_bignum(unsigned long long size)
{
	sign = 0;
	value.resize(size);
}
basic_bignum::basic_bignum(string tmp)
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
basic_bignum basic_bignum::operator+(basic_bignum adition)
{
	basic_bignum last;
	value.resize(max(value.size(), adition.value.size()));
	adition.value.resize(max(value.size(), adition.value.size()));
	last.value.resize(max(value.size(), adition.value.size()) + 1);
	return basic_bignum();
}
