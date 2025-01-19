CC = g++
CFLAGS = -std=c++14 -Wall
OBJ = BlackJackSource.o Card.o Player.o Deck.o Dealer.o

# The target executable
TARGET = BlackJack

# Rule to build the final executable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Rule to compile each source file
BlackJackSource.o: BlackJackSource.cpp BlackJack.h
	$(CC) $(CFLAGS) -c BlackJackSource.cpp

Card.o: Card.cpp BlackJack.h
	$(CC) $(CFLAGS) -c Card.cpp

Player.o: Player.cpp BlackJack.h
	$(CC) $(CFLAGS) -c Player.cpp

Deck.o: Deck.cpp BlackJack.h
	$(CC) $(CFLAGS) -c Deck.cpp

Dealer.o: Dealer.cpp BlackJack.h
	$(CC) $(CFLAGS) -c Dealer.cpp

# Clean up object files and the executable (Windows compatible)
clean:
	del /Q BlackJackSource.o Card.o Player.o Deck.o Dealer.o $(TARGET)

# Rebuild the entire project
rebuild: clean $(TARGET)
