#include "xmlCollection.h"

XmlCollection::XmlCollection() {

}

XmlCollection::XmlCollection(vector<XmlElement*> lis) {
	for(unsigned int i = 0; i < lis.size(); i++) {
		_elems.push_back(lis[i]);
	}
	_iter = _elems.begin();
}

XmlElement *XmlCollection::operator[](size_t i) {
	return at(i);
}

XmlElement *XmlCollection::at(size_t i) {
	if(i >= _elems.size())
		return NULL;
	unsigned int ind = 0;
	for(_iter = _elems.begin(); _iter != _elems.end() && ind < i; _iter++, ind++);		
	return *_iter;
}

size_t XmlCollection::size() {
	return _elems.size();
}

//Returns the first element with whose name matches the parameter
XmlElement *XmlCollection::Element(string name) {
	for(list<XmlElement*>::iterator i = _elems.begin();
			i != _elems.end(); i++) {
		if((*i)->Name() == name)
			return *i;
	}
	return NULL;
}

//
XmlCollection XmlCollection::Children() {
	XmlCollection col;
	for(list<XmlElement*>::iterator i = _elems.begin();
			i != _elems.end(); i++) {
		col._combine((*i)->Children());
	}
	return col;
}

XmlCollection XmlCollection::ChildrenOfName(string name) {
	XmlCollection col;
	for(list<XmlElement*>::iterator i = _elems.begin();
			i != _elems.end(); i++) {
		col._combine((*i)->ChildrenOfName(name));
	}
	return col;
}

void XmlCollection::_combine(XmlCollection *ncol) {
	for(list<XmlElement*>::iterator i = ncol->_elems.begin();
			i != ncol->_elems.end(); i++) {
		_elems.push_back(*i);
	}
}

void XmlCollection::Add(XmlElement *e) {
	_elems.push_back(e);
}

void XmlCollection::Remove(int i) {
	_elems.erase(_elems.begin().operator++(i));
	_iter = _elems.begin();
}
