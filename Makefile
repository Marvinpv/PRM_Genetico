OBJ=obj
BIN=bin
SRC=src
INC=include
TEST = test



$(BIN)/test: $(OBJ)/test.o $(OBJ)/bitmap.o $(OBJ)/imageES.o $(OBJ)/point.o $(OBJ)/chromosome.o $(OBJ)/utilities.o
	g++ -ggdb -Wall -I$(INC) -o  $(BIN)/test $(OBJ)/test.o $(OBJ)/bitmap.o $(OBJ)/imageES.o $(OBJ)/point.o $(OBJ)/chromosome.o $(OBJ)/utilities.o

$(BIN)/fitness_test: $(OBJ)/fitness_test.o $(OBJ)/bitmap.o $(OBJ)/imageES.o $(OBJ)/point.o $(OBJ)/chromosome.o $(OBJ)/utilities.o
	g++ -ggdb -Wall -I$(INC) -o  $(BIN)/fitness_test $(OBJ)/fitness_test.o $(OBJ)/bitmap.o $(OBJ)/imageES.o $(OBJ)/point.o $(OBJ)/chromosome.o $(OBJ)/utilities.o

$(OBJ)/bitmap.o: $(INC)/bitmap.hpp $(SRC)/bitmap.cpp $(INC)/imageES.hpp $(SRC)/imageES.cpp $(INC)/point.hpp $(SRC)/point.cpp
	g++ -ggdb -Wall -c -o  $(OBJ)/bitmap.o -I$(INC) $(SRC)/bitmap.cpp

$(OBJ)/test.o: $(INC)/bitmap.hpp $(TEST)/test.cpp $(SRC)/bitmap.cpp $(SRC)/chromosome.cpp
	g++ -ggdb -Wall -c -o  $(OBJ)/test.o -I$(INC) $(TEST)/test.cpp

$(OBJ)/fitness_test.o: $(INC)/bitmap.hpp $(TEST)/fitness_test.cpp $(SRC)/bitmap.cpp 
	g++ -ggdb -Wall -c -o  $(OBJ)/fitness_test.o -I$(INC) $(TEST)/fitness_test.cpp

$(OBJ)/imageES.o: $(SRC)/imageES.cpp $(INC)/imageES.hpp
	g++ -ggdb -Wall -c -o $(OBJ)/imageES.o -I$(INC) $(SRC)/imageES.cpp

$(OBJ)/point.o: $(SRC)/point.cpp $(INC)/point.hpp
	g++ -ggdb -Wall -c -o $(OBJ)/point.o -I$(INC) $(SRC)/point.cpp

$(OBJ)/chromosome.o: $(SRC)/chromosome.cpp $(INC)/chromosome.hpp $(INC)/utilities.hpp $(SRC)/utilities.cpp
	g++ -ggdb -Wall -c -o $(OBJ)/chromosome.o -I$(INC) $(SRC)/chromosome.cpp
	

$(OBJ)/utilities.o : $(SRC)/utilities.cpp $(INC)/utilities.hpp
	g++ -ggdb -Wall -c -o $(OBJ)/utilities.o -I$(INC) $(SRC)/utilities.cpp

clean:
	printf "%sLimpiando archivos temporales...\n"
	rm $(OBJ)/*.o

all: $(BIN)/test $(BIN)/fitness_test 

