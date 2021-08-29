PATH_HEADER = ./include/
PATH_SOURCE = ./source/
PATH_OBJECTFILES = ./objectfiles/
PATH_BUILD = ./build/

COMPILECOMMANDS = -lGL -lGLU -lglut
SOURCEFILES = $(PATH_SOURCE)utils.cpp $(PATH_SOURCE)matrix.cpp $(PATH_SOURCE)hypercube.cpp $(PATH_SOURCE)controller.cpp $(PATH_SOURCE)renderer.cpp main.cpp
HEADERFILES = $(PATH_HEADER)utils.h $(PATH_HEADER)matrix.h $(PATH_HEADER)hypercube.h $(PATH_HEADER)controller.h $(PATH_HEADER)renderer.h
OBJECTFILES = utils.o matrix.o hypercube.o main.o controller.o renderer.o

output: $(OBJECTFILES)
	g++ -o $(PATH_BUILD)output  $(OBJECTFILES) $(COMPILECOMMANDS)

$(OBJECTFILES): $(SOURCEFILES) $(HEADERFILES)
	g++ -c $(SOURCEFILES) $(COMPILECOMMANDS) 

clean:
	-rm *.o