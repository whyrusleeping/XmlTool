#ifndef XML_DOC_H
#define XML_DOC_H

#include "xmlElement.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using std::stringstream;


class XmlDocument
{
	public:
		XmlDocument();
		XmlDocument(string filename);

		void Load(string filename);
		void Parse(string xml);

		XmlElement *Element(string name);
		void print();
	private:
		XmlElement *root;
		string _filename;
};

#endif
