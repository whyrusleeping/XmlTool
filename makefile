#one makefile to rule them all
CC=g++
OPTLEVEL=0
FLAGS=-Wall -Werror -O$(OPTLEVEL) -g
LIBS=
LIB_NAME=libxml
PROG_NAME=xmltest
OBJDIR=obj
SRCDIR=src
BINDIR=bin

SRCS = xmlCollection.cpp \
	   xmlDoc.cpp \
	   xmlElement.cpp \
	   xmlParser.cpp

TEST_SRC = $(SRCDIR)/xmlTest.cpp

OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@if [ ! -d $(OBJDIR) ]; then mkdir -p $(OBJDIR); fi
	$(CC) $(FLAGS) -c -o $@ $<

all: $(OBJS)
	@if [ ! -d $(BINDIR) ]; then mkdir -p $(BINDIR); fi
	$(CC) $(FLAGS) $(LIBS) $(OBJS) $(TEST_SRC) -o $(BINDIR)/$(PROG_NAME)

lib: $(OBJS)
	@if [ ! -d $(BINDIR) ]; then mkdir -p $(BINDIR); fi
	rm $(BINDIR)/$(LIB_NAME)
	ar r $(BINDIR)/$(LIB_NAME) $(OBJS)



clean:
	rm -rf $(OBJDIR) $(BINDIR)
