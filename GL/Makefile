ECHO=@echo
RM=@rm
COMP=g++
EDL=g++
CPPFLAGS=-g -Wall -ansi -std=c++11 -pedantic -o0 #-D MAP
EDLFLAGS=
RMFLAGS=-f
EXE=main
INT=lexer.h symbole.h etat.h automate.h etats.h
REAL=$(INT:.h=.cpp)
OBJ=$(REAL:.cpp=.o) $(EXE).o
INCPATH=
LIBPATH=

LIBS=

.PHONY: clean

$(EXE) : $(OBJ)
	$(ECHO) "EDL de $(EXE)"
	$(EDL) $(EDLFLAGS) -o $(EXE) $(OBJ)
%.o : %.cpp
	$(ECHO) "Compilation de $<"
	$(COMP) $(CPPFLAGS) -o $@ -c $<
clean :
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core *.csv *.gch
