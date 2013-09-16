#include "xmlElement.h"

XmlElement::XmlElement()
{
	parent = NULL;
}

XmlElement::XmlElement(string name, string contents="") : _name(name), _contents(contents), parent(NULL)
{ }

XmlElement::~XmlElement()
{
	for(unsigned int i = 0; i < children.size(); i++)
	{
		delete children[i];
	}
}

int XmlElement::Depth()
{
	if(parent == NULL)
		return 0;
	else
		return parent->Depth() + 1;
}

void XmlElement::addChild(string name, string contents="") {
	XmlElement *e = new XmlElement(name, contents);
	if (e == NULL) {
		//cantalloc();
		cout << "Failed to allocate memory!\n";
		exit(1);
	}

	addChild(e);
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
	for(unsigned int i = 0; i < children.size(); i++)
		children[i]->Print(tabs + 1);
	for(int i = 0; i < tabs; i++)
		cout << "\t";
	cout << "</" << _name << ">\n";
}

XmlElement *XmlElement::getParent()
{
	return parent;
}

void XmlElement::_save(ofstream &of, int tabs)
{

	for(int i = 0; i < tabs; i++)
		of << "\t";
	of << "<" << _name << ">\n";

	if(_contents != "")
	{
		for(int i = 0; i < tabs+1; i++)
			of << "\t";
		of << _contents << "\n";
	}
	for(unsigned int i = 0; i < children.size(); i++)
		children[i]->_save(of, tabs + 1);
	for(int i = 0; i < tabs; i++)
		of << "\t";
	of << "</" << _name << ">\n";


}

//Unlinks this element from its parent, does not delete it
void XmlElement::Remove()
{
	if(parent != NULL)
	{
		for(unsigned int i = 0; i < parent->children.size(); i++)
		{
			if(parent->children[i] == this)
			{
				parent->children.erase(parent->children.begin() + i);
				break;
			}
		}
		parent = NULL;
	}
}

XmlElement *XmlElement::Element(string name)
{
	for(unsigned int i = 0; i < children.size(); i++)
	{
		if(children[i]->_name == name)
			return children[i];
	}
	return NULL;
}

//Returns all child elements of all elements in this collection
XmlCollection XmlElement::Children()
{
	XmlCollection col(children);
	return col;
}

XmlCollection XmlElement::ChildrenOfName(string name)
{
	vector<XmlElement*> set;
	for(unsigned int i = 0; i < children.size(); i++)
	{
		if(children[i]->_name == name)
		{
			set.push_back(children[i]);
		}
	}
	XmlCollection col(set);
	return col;
}
