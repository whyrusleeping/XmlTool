#ifndef XML_ELEMENT_H
#define XML_ELEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "xmlCollection.h"

using std::ofstream;
using std::cout;
using std::vector;
using std::string;

class XmlCollection;
class XmlDocument;

class XmlElement
{
	public:
		friend XmlDocument;
		XmlElement();
		XmlElement(string name, string contents);
		~XmlElement();


		//Accessors
		XmlElement *Element(string name);
		XmlCollection Children();
		XmlCollection ChildrenOfName(string name);


		int Depth();
		string Name();
		void setName(string name);

		string Contents();
		void setContents(string contents);

		string ToString();
		void Print(int tabs);

		XmlElement *getParent();

		void addChild(XmlElement *child);
		void Remove();
	private:
		void _save(ofstream &of, int tabs);
		string _name;
		string _contents;
		XmlElement* parent;
		vector<XmlElement*> children;
};
#endif
