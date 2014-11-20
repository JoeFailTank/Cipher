#include "Cipher.h"

Caesar::Caesar ()
{
	shift = 0;
	select = true;
}

Caesar::~Caesar ()
{

}

void Caesar::setShift (int newshift)
{
	shift = newshift;
}

int Caesar::getshift ()
{
	return shift;
}

// Precondition for shift to be set
void Caesar::Encode (ifstream &in, ofstream &out)
{
	string line;
	if (select == true)
	{
		do
		{
			system ("cls");
			cout << "Please Enter appropriate shift value: ";
			cin >> shift;
		} while ((shift > 26) || (shift < -26));
	}
	while (getline (in, line))
	{
		for (int i = 0; i < line.size (); i++)
		{
			if (((int) line [i] <= 'z') && ((int) line [i] >= 'a'))
			{
				if ((int) line [i] + shift > 'z')
				{
					out << (char) ((int) line [i] + shift - (int) 'z');
				}
				else if ((int) line [i] + shift < 'a')
				{
					out << (char) ((int) line [i] + shift + (int) 'z');
				}
				else
					out << (char) ((int) line [i] + shift);
			}
			else if (((int) line [i] <= 'Z') && ((int) line [i] >= 'A'))
			{
				if ((int) line [i] + shift > 'Z')
				{
					out << (char) ((int) line [i] + shift - (int) 'Z');
				}
				else if ((int) line [i] + shift < 'A')
				{
					out << (char) ((int) line [i] + shift + (int) 'Z');
				}
				else
				{
					out << (char) ((int) line [i] + shift);
				}
			}
			else
			{
				out << line [i];
			}
		}
		out << endl;
	}
}

void Caesar::Decode (ifstream &in, ofstream &out)
{
	char alpha [26];
	int alphcount [26];
	int e = 0;
	string line;
	alpha [0] = 'a';
	for (int i = 1; i < 26; i++)
	{
		alpha [i] = alpha [i -1] + 1;
	}
	while (getline (in, line))
	{
		for (int i = 0; i < line.size (); i++)
		{
			for (int z = 0; (z < 26); z++)
			{
				if (line [i] == alpha [z])
				{
					alphcount [z]++;
				}
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (alphcount [i] > alphcount [e])
		{
			e = i;
		}
	}
	if (e < 4)
	{
		setShift (4 - e);
	}
	else if (e == 4)
	{
		setShift (0);
	}
	else
	{
		setShift (4 - e);
	}
	in.clear ();
	in.seekg (0, ios::beg);
	select = false;
	Encode (in, out);
}

Substitute::Substitute ()
{
	key [0] = 'a';
	for (int i = 1; i < 26; i++)
	{
		key [i] = key [i -1] + 1;
	}
}

Substitute::~Substitute ()
{

}

void Substitute::Encode (ifstream &in, ofstream &out)
{

}

void Substitute::Decode (ifstream &in, ofstream &out)
{

}
