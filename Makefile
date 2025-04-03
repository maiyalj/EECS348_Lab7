CC := gcc

all: football.exe temperature.exe

football.exe: football_main.c football.c
	@$(CC) football_main.c football.c -o football.exe
	@./football.exe
	@rm -f football.exe
temperature.exe: temperature_main.c temperature.c
	@$(CC) temperature_main.c temperature.c -o temperature.exe
	@./temperature.exe
	@rm -f temperature.exe
