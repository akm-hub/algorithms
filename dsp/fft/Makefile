#A simple makefile to generate the lib file
CC := gcc
CFLAGS := -c -std=gnu99
INCLUDES := -Iinclude
RM := rm -f
	
libfft: 
	$(CC) $(CFLAGS) src/libfft_windows.c -o bin/libfft_windows.o $(INCLUDES)
	ar rcs lib/libfft_windows.a bin/libfft_windows.o
    
clean:
    $(RM) bin/*.o
    $(RM) lib/*.a
