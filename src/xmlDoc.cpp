#include "xmlDoc.h"

XmlDocument::XmlDocument() {
	_filename = "untitled.xml";
	root = NULL;
}

XmlDocument::XmlDocument(string filename) {
	root = NULL;
	Load(filename);
}

XmlDocument::~XmlDocument() {
	delete root;
}

void XmlDocument::Load(string filename) {
	_filename = filename;
	ifstream inf(filename.c_str());
	if (!inf.good()) {
		cout << "Could not open file " << filename << std::endl;
		return;
	}
	stringstream ss;
	char c;
	while(inf.good()) {
		c = inf.get();
		if(c != '\t' && c != '\n')
		   ss << c;	
	}
	root = XmlParser::Parse(ss.str());
}

void XmlDocument::print() {
	root->Print(0);
}

void XmlDocument::Save() {
	Save(_filename);
}

void XmlDocument::Save(string filename) {
	ofstream of(filename.c_str());
	root->_save(of, 0);
}

