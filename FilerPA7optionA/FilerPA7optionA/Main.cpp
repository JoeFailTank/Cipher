#include "Cipher.h"

int main ()
{
	ifstream in;
	ofstream out;
	Caesar test;
	in.open ("input.txt", std::ios::in);
	out.open ("output.txt", std::ios::out);
	test.Encode (in, out);
	in.close ();
	out.close ();
	return 0;
}