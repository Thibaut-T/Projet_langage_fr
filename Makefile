all:
	rm -f fransous.exe fransous.lex.cpp fr.bison.cpp fransous.bison.h
	bison -d fransous2.y -o fransous.bison.cpp
	flex -o fransous.lex.cpp fransous2.l
	g++ -w fransous.lex.cpp fransous.bison.cpp -o fransous
	./fransous testfransous2.txt