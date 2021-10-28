all:
	rm -f fransous.exe fransous.lex.cpp fr.bison.cpp fransous.bison.h
	bison -d fransous.y -o fransous.bison.cpp
	flex -o fransous.lex.cpp fransous.l
	g++ -w fransous.lex.cpp fransous.bison.cpp -o fransous
	./fransous test.txt