all: compile link

compile:
	g++ -I src/include -c jogoDaDigitacao.cpp 
link: 
	g++ jogoDaDigitacao.o -o jogoDaDigitacao -L src/lib -l sfml-graphics -l sfml-window -l sfml-system