
# CXXFLAGS is a special variable for telling Make what options to give the
# compiler when using its builtin rules.
CXXFLAGS += -Wall -Werror -g -O0

# What are we building?
TARGET := Movies.exe

# Collect the names of all the .cpp files.
SOURCE := $(wildcard *.cpp)

# Replace .cpp with .o to get the object file list.
OBJECT := $(patsubst %.cpp, %.o, $(SOURCE))

# all is the tradidional name for the frst target.
.PHONY: all
all: .depend $(TARGET)

# clean is the tradidional rule for cleaning up junk
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJECT) .depend

# Link the objects for the binary.
# $@ = Name of the rule's target, $(TARGET) = Movies.exe
# $^ = List of the rule's dependencies, $(OBJECT)
$(TARGET): $(OBJECT)
	$(CXX) $(CFLAGS) -o $@ $^ 

# Accout for changes in included headers within the source files.
# gc -MM generates a list of Make rules for this, we then include it.
depend: .depend
.depend: $(SOURCE)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF  ./.depend;

include .depend

# The rest of the files are built with one of Make's builtin rules:
# %.o: %.cpp
#	$(CXX) $(CXXFLAGS) -c $@ $^

