#include "xmlDoc.h"

XmlDocument::XmlDocument()
{
	_filename = "untitled.xml";
	root = NULL;
}

XmlDocument::XmlDocument(string filename)
{
	root = NULL;
	Load(filename);
}

XmlDocument::~XmlDocument()
{
	delete root;
}

void XmlDocument::Load(string filename)
{
	_filename = filename;
	ifstream inf(filename.c_str());
	stringstream ss;
	char c;
	while(inf.good())
	{
		inf >> c;
		if(c != '\t' && c != '\n')
		   ss << c;	
	}
	Parse(ss.str());
}

void XmlDocument::Parse(string xml)
{
	XmlElement *cur = NULL;

	stringstream ss;
	bool intag = false;
	for(unsigned int i = 0; i < xml.length(); i++)
	{
		if(!intag)
		{
			if(xml[i] == '<')
			{
				if(xml[i+1] == '/')
				{
					if(cur != NULL)
					{
						cur->setContents(ss.str());
						ss.str("");
						cur = cur->getParent();
					}
					for(;i < xml.length() && xml[i] != '>'; i++);
				}
				else
				{
					intag = true;
				}
			}
			else
			{
				ss << xml[i];
			}
		}	
		else
		{
			if(xml[i] == '>')
			{
				intag = false;
				XmlElement *n = new XmlElement(ss.str(), "");
				if(cur != NULL)
				{
					cur->addChild(n);
					cur = n;
				}
				else
				{
					root = n;
					cur = n;
				}
				ss.str("");
			}
			else
			{
				ss << xml[i];
			}
		}
	}
}

void XmlDocument::print()
{
	this->root->Print(0);
}

void XmlDocument::Save()
{
	Save(_filename);
}

void XmlDocument::Save(string filename)
{
	ofstream of(filename.c_str());
	root->_save(of, 0);
}

