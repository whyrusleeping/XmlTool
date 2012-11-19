#include "xmlCollection.h"

XmlCollection::XmlCollection()
{

}

XmlCollection::XmlCollection(vector<XmlElement*> lis)
{
	for(int i = 0; i < lis.size(); i++)
	{
		_elems.push_back(lis[i]);
	}
	_iter = _elems.begin();
	_index = 0;
}

XmlElement *XmlCollection::operator[](const int i)
{
	if(i >= _elems.size())
		return NULL;
	if(i > _index)
		for(;_index < i;_index++, _iter++);
	else
		for(;_index > i;_index--, _iter--);
	return *_iter;
}

int XmlCollection::size()
{
	return _elems.size();
}

//Returns the first element with whose name matches the parameter
XmlElement *XmlCollection::Element(string name)
{
	for(list<XmlElement*>::iterator i = _elems.begin(); i != _elems.end(); i++)
	{
		if((*i)->Name() == name)
			return *i;
	}
	return NULL;
}

//
XmlCollection XmlCollection::Children()
{
	XmlCollection col;
	for(list<XmlElement*>::iterator i = _elems.begin(); i != _elems.end(); i++)
	{
		col._combine((*i)->Children());
	}
	return col;
}

XmlCollection XmlCollection::ChildrenOfName(string name)
{
	XmlCollection col;
	for(list<XmlElement*>::iterator i = _elems.begin(); i != _elems.end(); i++)
	{
		col._combine((*i)->ChildrenOfName(name));
	}
	return col;
}

void XmlCollection::_combine(XmlCollection ncol)
{
	for(list<XmlElement*>::iterator i = ncol._elems.begin(); i != ncol._elems.end(); i++)
	{
		_elems.push_back(*i);
	}
}
