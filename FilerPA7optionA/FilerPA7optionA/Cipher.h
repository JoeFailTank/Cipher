#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::ifstream;
using std::ofstream;
using std::ios;
using std::vector;
using std::getline;

class Cipher
{
public:
	virtual void Encode (ifstream &in, ofstream &out) = 0;
	virtual void Decode (ifstream &in, ofstream &out) = 0;
};

class Caesar: public Cipher
{
public:
	Caesar ();
	~Caesar ();
	void setShift (int newshift);
	int getshift ();
	void Encode (ifstream &in, ofstream &out);
	void Decode (ifstream &in, ofstream &out);
private:
	int shift;
	bool select;
};

class Substitute: public Cipher
{
public:
	Substitute ();
	~Substitute ();
	void Encode (ifstream &in, ofstream &out);
	void Decode (ifstream &in, ofstream &out);
private:
	char key [26];
};