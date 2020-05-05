#pragma once

#ifdef LIBRARY_EXPORTS
#define LIBRARY __declspec(dllexport)
#else
#define LIBRARY __declspec(dllimport)
#endif

#include <String>

using namespace std;

extern "C" LIBRARY void deleteConsonantsLettersFromString(string &s);
