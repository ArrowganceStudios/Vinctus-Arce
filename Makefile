CC=g++
RM=rm -f
CXXFLAGS+=-std=c++11
LIBS=-lallegro -lallegro_font -lallegro_image -lallegro_primitives -lallegro_ttf
LDFLAGS+=

SOURCEDIR=src
SOURCES=$(shell find $(SOURCEDIR) -name '*.cpp')
OBJECTS=$(SOURCES:.cpp=.o)
EXEC=vinctus-arce

all: $(SOURCES) $(EXEC)

$(EXEC): $(OBJECTS)
	$(CC) $(LIBS) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) -c $(CXXFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXEC)
