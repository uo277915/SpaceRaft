#include "Logger.h"

void Logger::log(int ident, string from, string msg) {
	cout << std::string(ident, '\t') << "[" << from << "] " << msg << endl;
}

void Logger::log(int ident, string msg) {
	cout << std::string(ident, '\t') << msg << endl;
}