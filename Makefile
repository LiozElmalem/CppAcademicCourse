#########################################################
# compiler stuff 
#########################################################
CC= gcc
CFLAGS= -Wall -Wvla -Werror -g
#COPTFLAGS= -O -DNDEBUG

CXX= g++
CXXFLAGS= $(CFLAGS) 

CEXELINKFLAGS=
CXXTESTLINKFLAGS= -lgtest -lgtest_main -pthread
##########################################################


##########################################################
# sources files
##########################################################
SRCSEXENOMAIN= List.c
SRCSEXEMAIN= ListMain.c
SRCSEXE = $(SRCSEXENOMAIN) $(SRCSEXEMAIN)

# There is no SRCTESTMAIN as we are linking with gtest_main that has main
SRCSTESTNOMAIN= ListTest.cpp 
##########################################################


#######################
# executables name
#######################
EXE= ListDemo
TEST= ListTest
#######################


#########################################################
# actions
#########################################################
all: $(EXE) $(TEST)
	@read -p "Press [Enter] key to start memory check of executable..." MEMCHK
	valgrind --leak-check=full -v ./$(EXE)
	@read -p "Press [Enter] key to start memory check of test executable..." MEMCHK
	valgrind --leak-check=full -v ./$(TEST)

$(EXE): $(subst .c,.o,$(SRCSEXE))
	$(CC) $(CFLAGS) $(CEXELINKFLAGS) $^ -o $@

$(TEST): $(subst .c,.o,$(SRCSEXENOMAIN)) $(subst .cpp,.o,$(SRCSTESTNOMAIN))
	$(CXX) $(CXXFLAGS) $^ -o $@ $(CXXLINKFLAGS) $(CXXTESTLINKFLAGS)
	./$@

clean:
	rm *.o $(EXE) $(TEST) -f

depend: $(SRCSEXE) $(SRCSTESTNOMAIN)
	makedepend -Y -- $(CXXFLAGS) -- $^

##############################################
# installs that should be done once
##############################################
installonce: gtestinstall makedependinstall valgrindinstall

gtestinstall: 
	sudo apt-get install libgtest-dev
	sudo apt-get install cmake
	cd /usr/src/gtest; \
	sudo cmake CMakeLists.txt; \
	sudo make; \
	sudo cp *.a /usr/lib
	sudo chmod u+r /usr/lib/libgtest.a
	sudo chmod u+r /usr/lib/libgtest_main.a

makedependinstall:
	sudo apt-get install xutils-dev

valgrindinstall:
	sudo apt-get install valgrind
##############################################

.PHONY: all clean depend installonce gtestinstall makedependinstall valgrindinstall


# DO NOT DELETE THIS LINE -- make depend depends on it.

List.o: List.h
ListMain.o: List.h
ListTest.o: List.h
