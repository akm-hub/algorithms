#A simple makefile to generate the lib file
CC := gcc
CFLAGS := -c -std=gnu99
INCLUDES := -Iinclude
RM := rm -f
	
libfft:
    mkdir build lib
	$(CC) $(CFLAGS) src/libfft_windows.c -o build/libfft_windows.o $(INCLUDES)
	ar rcs lib/libfft_windows.a build/libfft_windows.o
    
clean:
    $(RM) build/*.o
    $(RM) lib/*.a
