#ifndef XML_ELEMENT_H
#define XML_ELEMENT_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include "xmlCollection.h"

using std::ofstream;
using std::cout;
using std::vector;
using std::string;
using std::map;

class XmlCollection;
class XmlDocument;

class XmlElement
{
	public:
		friend XmlDocument;
		XmlElement();
		XmlElement(string name, string contents="");
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

		string Attribute(string atrname);
		void setAttribute(string name, string value);
		
		string ToString();
		void Print(int tabs);

		XmlElement *getParent();

		void addChild(XmlElement *child);
		void addChild(string name, string contents="");
		void Remove();
	private:
		void _save(ofstream &of, int tabs);
		string _name;
		string _contents;
		XmlElement* parent;
		vector<XmlElement*> children;
		map<string,string> attributes;
};
#endif
