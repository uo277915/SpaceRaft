#pragma once

#include <iostream>
#include <string>
using namespace std;

static class Logger
{
public:
	static void log(int ident, string from, string msg);
	static void log(int ident, string msg);

};

