#ifndef XML_DOC_H
#define XML_DOC_H

#include "xmlElement.h"
#include <sstream>

using std::ifstream;
using std::stringstream;


class XmlDocument
{
	public:
		XmlDocument();
		XmlDocument(string filename);
		~XmlDocument();

		void Load(string filename);
		void Save();
		void Save(string filename);
		void Parse(string xml);

		XmlElement *root;
		void print();
	private:
		string _filename;
};

#endif
