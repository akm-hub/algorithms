#A simple makefile to generate the lib file

#WARNING: This makefile contains non-portable commands
#You should use autoconf if portability is required.

CC := gcc
CFLAGS := -c -std=gnu99
INCLUDES := -Iinclude
RM := rm -f

libfft:
	mkdir -p build lib 
	$(CC) $(CFLAGS) src/libfft_windows.c -lm -o build/libfft_windows.o $(INCLUDES)
	ar rcs lib/libfft_windows.a build/libfft_windows.o

clean:
	$(RM) build/*.o
	$(RM) lib/*.a
