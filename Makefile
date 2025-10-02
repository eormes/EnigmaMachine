# A line starting with a has is a comment, we'll build up
# the below example

TARGET = EnigmaMachine
SRC_FILES = main.cpp InputProcessor.cpp OutputProcessor.cpp Rotor.cpp Machine.cpp PlugBoard.cpp

# NO EDITS NEEDED BELOW THIS LINE

CXX = g++
CXXFLAGS = -O2
CXXFLAGS_DEBUG = -g
CXXFLAGS_WARN = -Wall -Wextra -Wunreachable-code -Wshadow -Wpedantic
CPPVERSION = -std=c++17

OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
	Q=
else
	DEL = rm -f
	Q="
endif

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CPPVERSION) $(CXXFLAGS_DEBUG) $(CXXFLAGS_WARN) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS) Makefile.bak

depend:
	@sed -i.bak '/^# DEPENDENCIES/,$$d' Makefile
	@$(DEL) sed*
	@echo $(Q)# DEPENDENCIES$(Q) >> Makefile
	@$(CXX) -MM $(SRC_FILES) >> Makefile

.PHONY: all clean depend

# DEPENDENCIES
main.o: main.cpp InputProcessor.h Rotor.h OutputProcessor.h Exchangeable.h Machine.h PlugBoard.h
InputProcessor.o: InputProcessor.h InputProcessor.cpp
OutputProcessor.o: OutputProcessor.h OutputProcessor.cpp
Rotor.o: Rotor.cpp Rotor.h Exchangeable.h
PlugBoard.o: PlugBoard.cpp PlugBoard.h Exchangeable.h
Machine.o: Machine.cpp Machine.h PlugBoard.h Rotor.h Exchangeable.h

