all:
	rm -f fransous2.exe fransous2.lex.cpp fransous2.bison.cpp fransous2.bison.h
	bison -d fransous2.y -o fransous2.bison.cpp
	flex -o fransous2.lex.cpp fransous2.l
	g++ -w fransous2.lex.cpp fransous2.bison.cpp -o fransous2
	./fransous2 test.txt