//#include "xmlDoc.h"
#include "libcppxml.h"

int main()
{
	XmlDocument doc("test.xml");
	XmlCollection xc = doc.root->Children().Children();
	cout << "Finished Enumeration.\n";
	for(int i = 0; i < xc.size(); i++)
	{
		cout << xc[i]->Name() << "\n";
	}
	return 0;
}
