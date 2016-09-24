all:
	g++ -c ./controller/TTTController.cpp -o TTTController.o
	g++ -c ./model/Model.cpp -o Model.o
	g++ -c main.cpp -o Main.o
	g++ -c autoTest.cpp -o AutoTest.o
	g++ TTTController.o Model.o Main.o -o ttt
	g++ TTTController.o Model.o AutoTest.o -o test

clean:
	rm -rf *.o ttt test
                                           
