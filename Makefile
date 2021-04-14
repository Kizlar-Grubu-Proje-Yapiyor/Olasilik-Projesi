# Author: Ceyhun Sen
# Please read README.md for usage

NAME = olasilik

CC = gcc

IDIR = include
SDIR = src

CFLAGS = -I$(IDIR) -lm

OBJS = main.o yardim.o sinirlar.o interaktif.o dosya.o \
       aritmetikortalama.o medyan.o mod.o

HDR = $(IDIR)/main.h $(IDIR)/algoritmalar.h

$(NAME): $(OBJS)
	$(CC) $^ -o $@

build:
	$(CC) $(SDIR)/* $(CFLAGS) -o $(NAME)

%.o: $(SDIR)/%.c $(IDIR)/%.h $(HDR)
	$(CC) -c -o $@ $< $(CFLAGS)


.PHONY: clean

clean:
	rm -rf *.o $(NAME)
