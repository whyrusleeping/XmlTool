#one makefile to rule them all
CC=g++
OPTLEVEL=0
FLAGS=-Wall -Werror -O$(OPTLEVEL) -g
LIBS=
LIB_NAME=xmlfun
OBJDIR=obj
SRCDIR=src
BINDIR=bin

SRCS = xmlCollection.cpp \
	   xmlDoc.cpp \
	   xmlElement.cpp \
	   xmlTest.cpp
	

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if [ ! -d $(OBJDIR) ]; then mkdir -p $(OBJDIR); fi
	$(CC) $(FLAGS) -c -o $@ $<

all: $(OBJS)
	@if [ ! -d $(BINDIR) ]; then mkdir -p $(BINDIR); fi
	$(CC) $(FLAGS) $(LIBS) $(OBJS) -o $(BINDIR)/$(LIB_NAME)

clean:
	rm -rf $(OBJDIR) $(BINDIR)
