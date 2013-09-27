#include "xmlParser.h"

XmlElement *
XmlParser::Parse(string xml) {
	XmlElement *root = NULL;
	XmlElement *cur = NULL;

	//For reading in temporary text
	stringstream buffer;

	bool intag = false;
	for(size_t i = 0; i < xml.length(); i++) {
		if(!intag) {
			if(xml[i] == '<') {
				if(xml[i+1] == '/') {
					if(cur != NULL) {
						//The text we have been reading
						//is now the content of this tag
						cur->setContents(buffer.str());
						//Clear the buffer
						buffer.str("");
						cur = cur->getParent();
					}
					//Search for the end of the tag
					for(;i < xml.length() &&
							xml[i] != '>'; i++);
				} else {
					intag = true;
				}
			} else {
				buffer << xml[i];
			}
		} else {
			//inside tag
			if(xml[i] == '>') {
				intag = false;
				//Now that we have the text inside the opening tag, 
				//lets parse it for attributes
				//TODO: handle spaces between the equals sign and 
				//		the attr name/value
				string tag_str = buffer.str();
				vector<string> toks = splitString(tag_str, ' ');
				XmlElement *n = new XmlElement(toks[0],"");
				for (size_t j = 1; j < toks.size(); j++) {
					vector<string> split = splitString(toks[j],'=');
					n->setAttribute(split[0], stripChars(split[1], &isQuotes));
				}
				if(cur != NULL) {
					cur->addChild(n);
					cur = n;
				} else {
					root = n;
					cur = n;
				}
				buffer.str("");
			} else {
				buffer << xml[i];
			}
		}
	}
	return root;
}

bool isWhitespace(char c) {
	return c == ' ' || c == '\n' || c == '\t';
}

bool isQuotes(char c) {
	return c == '\"' || c == '\'';
}

//Strip characters matched by the given function
//from the beginning and end of the string and
//return a new string
string stripChars(string s, bool (*match)(char)) {
	stringstream ss;
	int i = 0;
	int end = s.length() - 1;
	for (; end > 0 && match(s[end]); end--);
	for (; i < end; i++) {
		if (!match(s[i])) {
			break;
		}
	}
	for (; i <= end; i++) {
		ss << s[i];
	}
	return ss.str();
}

//splits the given string by the given deliminator
vector<string> splitString(string s, char delim) {
	vector<string> strs;
	stringstream ss;
	for (size_t i = 0; i < s.length(); i++) {
		if(s[i] == delim) {
			if (ss.str().length() > 0)
				strs.push_back(ss.str());
			ss.str("");
			continue;
		}
		ss << s[i];
	}
	if (ss.str().length() > 0)
		strs.push_back(ss.str());
	return strs;
}
