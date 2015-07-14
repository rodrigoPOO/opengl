
SOURCE_DIR=src
PROGRAM_NAME=bomberman

SOURCES=$(wildcard $(SOURCE_DIR)/*.cpp)
HEADERS=$(wildcard $(SOURCE_DIR)/*.h)
OBJECTS=$(SOURCES:.cpp=.o)

COMPILER=g++
COMPILER_FLAGS=-std=c++11
LIBRARIES= -lGL -lGLU -lglut
LINKER=g++


.PHONY:all  clean



all: $(OBJECTS)
	$(LINKER) $^  $(LIBRARIES) -o $(PROGRAM_NAME)

		

#compile
%.o: %.cpp $(HEADERS)
	$(COMPILER) -c $(COMPILER_FLAGS) $<  -o $@ $(LIBRARIES)
	
 
clean:
	rm $(PROGRAM_NAME)
	rm $(OBJECTS)
	

