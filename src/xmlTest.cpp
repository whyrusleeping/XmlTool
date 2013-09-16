#include "xmlDoc.h"

int main()
{
	/*
	XmlDocument doc("test.xml");

	if (doc.root != NULL) {
		XmlCollection xc = doc.root->Children().Children();
		cout << "Finished Enumeration.\n";
		for(int i = 0; i < xc.size(); i++)
		{
			cout << xc[i]->Name() << "\n";
		}
	}
	*/
	XmlDocument *d = new XmlDocument();
	d->root = new XmlElement("TOP");
	d->root->addChild("next");
	d->root->addChild("other", "something");
	d->root->addChild("athing", "whatever");
	d->root->addChild("next");
	d->root->addChild("next");
	d->root->addChild("first");
	d->root->addChild("next");
	d->Save("out.xml");
	return 0;
}
