# Define the compiler to use
CXX = g++
# Define any compile-time flags
CXXFLAGS = -Wall -g
# Define any directories containing header files
INCLUDES =
# Define any libraries to link into executable
LFLAGS =
# Define any libraries to include
LIBS =

# Define a list of source files
SOURCES = $(wildcard *.cpp)
# Define a list of object files based on source files
OBJECTS = $(SOURCES:.cpp=.o)
# Define a list of executable files based on source files
EXECUTABLES = $(SOURCES:.cpp=)

# Default target
all: $(EXECUTABLES)

# Rule to create executable files
%: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $< $(LFLAGS) $(LIBS)

# Clean target
clean:
	rm -f $(OBJECTS) $(EXECUTABLES)

# Dependency target
depend: .depend

.depend: $(SOURCES)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ > ./.depend;

include .depend
