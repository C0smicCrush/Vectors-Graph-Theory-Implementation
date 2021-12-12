
# compiler include search paths
INCS = -I./



SDIR = ./
ODIR = ./obj

OPT = -g
CCflags = -std=c++17 $(OPT)
STATLibs = -static-libstdc++ -static-libgcc -static

### OBJECT FILES

OBJ = $(ODIR)/main.o $(ODIR)/graph.o $(ODIR)/stack.o $(ODIR)/linkedlist.o

### COMPILE

$(ODIR)/main.o : main.cpp
	g++ -o  $@ -c main.cpp $(INCS) $(CCflags)
$(ODIR)/graph.o : graph.cpp
	g++ -o  $@ -c graph.cpp $(INCS) $(CCflags)
$(ODIR)/stack.o : stack.cpp
	g++ -o  $@ -c stack.cpp $(INCS) $(CCflags)
$(ODIR)/linkedlist.o : linkedlist.cpp
	g++ -o  $@ -c linkedlist.cpp $(INCS) $(CCflags)


#### LINKS

test : $(OBJ)
	g++ -o ../bin/test.exe \
		$(OBJ) $(WEXLIBS) $(STATLibs) $(OPT)

### CLEAN

.PHONY: clean
clean:
	del /q ..\obj