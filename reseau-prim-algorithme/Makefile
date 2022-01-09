CC = g++
OPTIONS = -O2 -Wall -std=c++11
SRCS = src
BUILD = build
BIN = bin
APP = tp3
EXEC = $(APP)
OBJS = $(BUILD)/coordonnee.o $(BUILD)/carte.o $(BUILD)/sommet.o $(BUILD)/arrete.o

all : $(EXEC)

$(EXEC): $(SRCS)/tp3.cpp  $(OBJS)
	$(CC) $(OPTIONS) -o tp3 $(SRCS)/tp3.cpp $(OBJS)

$(BUILD)/carte.o: $(SRCS)/carte.cpp $(SRCS)/carte.h $(SRCS)/sommet.h $(SRCS)/arrete.h
	$(MKDIR_P) $(BUILD)
	$(CC) $(OPTIONS) -c -o $(BUILD)/carte.o $(SRCS)/carte.cpp

$(BUILD)/sommet.o: $(SRCS)/sommet.cpp $(SRCS)/sommet.h
	$(MKDIR_P) $(BUILD)
	$(CC) $(OPTIONS) -c -o $(BUILD)/sommet.o $(SRCS)/sommet.cpp

$(BUILD)/arrete.o: $(SRCS)/arrete.cpp $(SRCS)/arrete.h
	$(MKDIR_P) $(BUILD)
	$(CC) $(OPTIONS) -c -o $(BUILD)/arrete.o $(SRCS)/arrete.cpp

$(BUILD)/coordonnee.o: $(SRCS)/coordonnee.cpp $(SRCS)/coordonnee.h
	$(MKDIR_P) $(BUILD)
	$(CC) $(OPTIONS) -c -o $(BUILD)/coordonnee.o $(SRCS)/coordonnee.cpp

.PHONY: clean

clean:
	rm -rf $(BUILD)
	rm $(EXEC)

MKDIR_P ?= mkdir -p
