#ifndef XML_ELEMENT_H
#define XML_ELEMENT_H

#include <vector>
#include <string>
#include <iostream>

using std::cout;
using std::vector;
using std::string;

class XmlElement
{
	public:
		XmlElement();
		XmlElement(string name, string contents);

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
		string _name;
		string _contents;
		XmlElement* parent;
		vector<XmlElement*> children;
};
#endif
