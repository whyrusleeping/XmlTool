LIBNAME=libcppxml.so

all: compLib

example:
	g++ xmlTest.cpp -o xmlTest -l:libcppxml.so

srcFiles: xmlDoc.cpp xmlElement.cpp xmlCollection.cpp
	g++ -c -fPIC xmlDoc.cpp xmlElement.cpp xmlCollection.cpp

compLib: srcFiles
	g++ -shared -o $(LIBNAME) xmlDoc.o xmlElement.o xmlCollection.o

clean:
	rm *.o
