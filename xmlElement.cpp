#include "xmlElement.h"

XmlElement::XmlElement()
{
	parent = NULL;
}

XmlElement::XmlElement(string name, string contents)
{
	_name = name;
	_contents = contents;
	parent = NULL;
}

int XmlElement::Depth()
{
	if(parent == NULL)
		return 0;
	else
		return parent->Depth() + 1;
}

void XmlElement::addChild(XmlElement *child)
{
	child->parent = this;
	children.push_back(child);
}

string XmlElement::Name()
{
	return _name;
}

void XmlElement::setName(string name)
{
	_name = name;
}

string XmlElement::Contents()
{
	return _contents;
}

void XmlElement::setContents(string contents)
{
	_contents = contents;
}

string XmlElement::ToString()
{
	return "Jeromy Is Lazy";
}

void XmlElement::Print(int tabs)
{
	for(int i = 0; i < tabs; i++)
		cout << "\t";
	cout << "<" << _name << ">\n";

	if(_contents != "")
	{
		for(int i = 0; i < tabs+1; i++)
			cout << "\t";
		cout << _contents << "\n";
	}
	for(int i = 0; i < children.size(); i++)
		children[i]->Print(tabs + 1);
	for(int i = 0; i < tabs; i++)
		cout << "\t";
	cout << "</" << _name << ">\n";
}

XmlElement *XmlElement::getParent()
{
	return parent;
}
