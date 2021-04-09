# Author: Ceyhun Sen
# Please read README.md for usage

NAME = olasilik

CC = gcc

IDIR = include
SDIR = src
ODIR = obj

CFLAGS = -I$(IDIR) -lm

OBJS = main.o yardim.o aritmetikortalama.o


$(NAME): $(OBJS)
	$(CC) $^ -o $@

build: $(NAME) cleano

# Object Files
main.o: $(SDIR)/main.c $(IDIR)/main.h
	$(CC) -c -o $@ $< $(CFLAGS)

yardim.o: $(SDIR)/yardim.c $(IDIR)/yardim.h
	$(CC) -c -o $@ $< $(CFLAGS)

aritmetikortalama.o: $(SDIR)/aritmetikortalama.c $(IDIR)/aritmetikortalama.h
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean

clean:
	rm -rf *.o *~ core $(INCDIR)/*~ $(NAME) *.o

cleano:
	rm -rf *.o
