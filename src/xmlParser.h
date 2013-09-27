#ifndef XML_PARSER_H
#define XML_PARSER_H
#include "xmlElement.h"
#include <iostream>
#include <sstream>

using std::stringstream;
using std::ifstream;

class XmlParser {
	public:
		static XmlElement *Parse(string xml);
};

vector<string> splitString(string s, char delim);
string stripChars(string s, bool (*match)(char));
bool isWhitespace(char c);
bool isQuotes(char c);

#endif
