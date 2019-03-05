 #!make -f

 cxx=clang++-5.0

 all: a.out
      ./a.out

a.out: test.o
    $(cxx) $(flags) test.o
