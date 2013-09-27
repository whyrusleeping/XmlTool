#include "xmlDoc.h"

int main()
{
	//*/
	XmlDocument doc("test.xml");

	if (doc.root != NULL) {
		XmlCollection *xc = doc.root->Children();
		cout << "Finished Enumeration.\n";
		for(size_t i = 0; i < xc->size(); i++)
		{
			cout << xc->at(i)->Name() << "\n";
		}
	}
	doc.Save("output.xml");
	//*/

	//*/
	XmlDocument *d = new XmlDocument();
	d->root = new XmlElement("TOP");
	d->root->setAttribute("fish", "herring");
	d->root->addChild("next");
	d->root->addChild("other", "something");
	d->root->addChild("athing", "whatever");
	d->root->addChild("next");
	d->root->addChild("next");
	d->root->addChild("first");
	d->root->addChild("next");
	d->Save("out.xml");
	//*/

	return 0;
}
