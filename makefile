all : make

make : main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF

test : main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF
	./SRF test

triangle : main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF
	./SRF triangle

user : main.cpp
	g++ -std=c++17 main.cpp src/parser.cpp src/SRF.cpp tests/unitTests.cpp -o SRF
	./SRF user