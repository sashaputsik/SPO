#include "Library.h"

extern "C" void deleteConsonantsLettersFromString(string &s)
{
	string letters = "БВГДЖЗКЛМНПРСТЧЩШбвгджзклмнпрстчщшBCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvwxyz";

	for (int i = 0; i < s.size(); i++)
		if (letters.find(s[i]) != string::npos)
		{
			s.erase(i, 1);
			i--;
		}
}
