CC := gcc
CFLAGS = -Wall -Wextra -Werror 
FOOTBALL_OBJ = football.o football_main.o
TEMPERATURE_OBJ = temperature.o temperature_main.o
FOOTBALL_EXEC = football
TEMPERATURE_EXEC = temperature

all: $(FOOTBALL_EXEC) $(TEMPERATURE_EXEC)

$(FOOTBALL_EXEC): $(FOOTBALL_OBJ)
	$(CC) $(CFLAGS) -o $(FOOTBALL_EXEC) $(FOOTBALL_OBJ)

$(TEMPERATURE_EXEC): $(TEMPERATURE_OBJ)
	$(CC) $(CFLAGS) -o $(TEMPERATURE_EXEC) $(TEMPERATURE_OBJ)

football.o: football.c football.h
	$(CC) $(CFLAGS) -c football.c

football_main.o: football_main.c football.h
	$(CC) $(CFLAGS) -c football_main.c

temperature.o: temperature.c temperature.h
	$(CC) $(CFLAGS) -c temperature.c

temperature_main.o: temperature_main.c temperature.h
	$(CC) $(CFLAGS) -c temperature_main.c

clean:
	rm -f $(FOOTBALL_OBJ) $(FOOTBALL_EXEC) $(TEMPERATURE_OBJ) $(TEMPERATURE_EXEC)
