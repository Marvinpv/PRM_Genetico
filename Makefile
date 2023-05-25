OBJ=obj
BIN=bin
SRC=src
INC=include
TEST = test

$(BIN)/test: $(OBJ)/test.o $(OBJ)/bitmap.o $(OBJ)/imageES.o $(OBJ)/point.o $(OBJ)/chromosome.o
	g++ -I$(INC) -o  $(BIN)/test $(OBJ)/test.o $(OBJ)/bitmap.o $(OBJ)/imageES.o $(OBJ)/point.o $(OBJ)/chromosome.o

$(OBJ)/bitmap.o: $(INC)/bitmap.hpp $(SRC)/bitmap.cpp $(INC)/imageES.hpp $(SRC)/imageES.cpp $(INC)/point.hpp $(SRC)/point.cpp
	g++ -c -o  $(OBJ)/bitmap.o -I$(INC) $(SRC)/bitmap.cpp

$(OBJ)/test.o: $(INC)/bitmap.hpp $(TEST)/test.cpp $(SRC)/bitmap.cpp 
	g++ -c -o  $(OBJ)/test.o -I$(INC) $(TEST)/test.cpp

$(OBJ)/imageES.o: $(SRC)/imageES.cpp $(INC)/imageES.hpp
	g++ -g -c -o $(OBJ)/imageES.o -I$(INC) $(SRC)/imageES.cpp

$(OBJ)/point.o: $(SRC)/point.cpp $(INC)/point.hpp
	g++ -g -c -o $(OBJ)/point.o -I$(INC) $(SRC)/point.cpp

$(OBJ)/chromosome.o: $(SRC)/chromosome.cpp $(INC)/chromosome.hpp
	g++ -g -c -o $(OBJ)/chromosome.o -I$(INC) $(SRC)/chromosome.cpp
clean:
	printf "%sLimpiando archivos temporales...\n"
	rm $(OBJ)/*.o
