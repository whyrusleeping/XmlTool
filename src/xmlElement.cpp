#include "xmlElement.h"

XmlElement::XmlElement() {
	parent = NULL;
}

XmlElement::XmlElement(string name, string contents) : _name(name), _contents(contents), parent(NULL), children(new XmlCollection())
{ }

XmlElement::XmlElement(const XmlElement *e) {
	parent = NULL;
	attributes = e->attributes;
	_name = e->_name;
	_contents = e->_contents;

	for (unsigned i = 0; i < e->children->size(); i++) {
		XmlElement *tmpChild = new XmlElement(e->children->at(i));
		tmpChild->parent = this;
		children->Add(tmpChild);
	}
}

XmlElement::~XmlElement() {
	for(size_t i = 0; i < children->size(); i++) {
		delete children->at(i);
	}
}

int XmlElement::Depth() {
	if(parent == NULL)
		return 0;
	else
		return parent->Depth() + 1;
}

void XmlElement::addChild(string name, string contents) {
	XmlElement *e = new XmlElement(name, contents);
	if (e == NULL) {
		//cantalloc();
		cout << "Failed to allocate memory!\n";
		exit(1);
	}

	addChild(e);
}

void XmlElement::addChild(XmlElement *child) {
	child->parent = this;
	children->Add(child);
}

string XmlElement::Name() {
	return _name;
}

void XmlElement::setName(string name) {
	_name = name;
}

string XmlElement::Contents() {
	return _contents;
}

void XmlElement::setContents(string contents) {
	_contents = contents;
}

string XmlElement::ToString() {
	return "Jeromy Is Lazy";
}

void XmlElement::Print(int tabs) {
	for(int i = 0; i < tabs; i++) cout << "\t";
	cout << "<" << _name << ">\n";

	if(_contents.length() > 0) {
		for(int i = 0; i < tabs+1; i++) cout << "\t";
		cout << _contents << "\n";
	}
	for(size_t i = 0; i < children->size(); i++) {
		children->at(i)->Print(tabs + 1);
	}
	for(int i = 0; i < tabs; i++) cout << "\t";
	cout << "</" << _name << ">\n";
}

XmlElement *XmlElement::getParent() {
	return parent;
}

void XmlElement::_save(ofstream &of, int tabs) {
	for(int i = 0; i < tabs; i++)
		of << "\t";
	of << "<" << _name;
	for(map<string,string>::iterator i = attributes.begin();
			i != attributes.end(); i++) {
		of << " " << (*i).first << "=\"" << (*i).second << "\"";
	}
	of << ">\n";

	if(_contents != "")
	{
		for(int i = 0; i < tabs+1; i++)
			of << "\t";
		of << _contents << "\n";
	}
	for(size_t i = 0; i < children->size(); i++)
		children->at(i)->_save(of, tabs + 1);
	for(int i = 0; i < tabs; i++)
		of << "\t";
	of << "</" << _name << ">\n";
}

//Unlinks this element from its parent, does not delete it
void XmlElement::Remove() {
	if(parent != NULL)
	{
		for(size_t i = 0; i < parent->children->size(); i++)
		{
			if(parent->children->at(i) == this)
			{
				parent->children->Remove(i);
				break;
			}
		}
		parent = NULL;
	}
}

XmlElement *XmlElement::Element(string name) {
	for(size_t i = 0; i < children->size(); i++)
	{
		if(children->at(i)->_name == name)
			return children->at(i);
	}
	return NULL;
}

//Returns all child elements of all elements in this collection
XmlCollection *XmlElement::Children() {
	return children;
}

XmlCollection *XmlElement::ChildrenOfName(string name) {
	vector<XmlElement*> set;
	for(size_t i = 0; i < children->size(); i++)
	{
		if(children->at(i)->_name == name)
		{
			set.push_back(children->at(i));
		}
	}
	XmlCollection *col = new XmlCollection(set);
	return col;
}

string XmlElement::Attribute(string atrname) {
	return attributes[atrname];
}

void XmlElement::setAttribute(string name, string value) {
	attributes[name] = value;
}
