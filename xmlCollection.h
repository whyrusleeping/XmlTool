#ifndef XML_COLLECT_H
#define XML_COLLECT_H

#include "xmlElement.h"
#include <list>
#include <iterator>

using std::string;
using std::list;
using std::vector;

class XmlElement;
//a 'Read Only' list of xmlElement's
class XmlCollection
{
	public: 
		XmlCollection();
		XmlCollection(vector<XmlElement*> lis);
		XmlElement *operator[] (const int i);
		int size();

		//Accessors
		XmlElement *Element(string name);
		XmlCollection Children();
		XmlCollection ChildrenOfName(string name);
	private:
		void _combine(XmlCollection ncol);
		list<XmlElement*>::iterator _iter;
		int _index;
		list<XmlElement*> _elems;
};

#endif
