#ifndef XML_DOC_H
#define XML_DOC_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class XmlDocument
{
	public:
		XmlDocument();
		XmlDocument(string filename);

		void Load(string filename);

	private:

}

#endif
