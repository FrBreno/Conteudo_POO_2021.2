all: compile link

compile:
	g++ -I src/include -c pegaPikachu.cpp 
link: 
	g++ pegaPikachu.o -o pegaPikachu -L src/lib -l sfml-graphics -l sfml-window -l sfml-system