NAME = olasilik

CC = gcc

IDIR = include
SDIR = src

CFLAGS = -I$(IDIR) -lm -O3
DBGFLAGS = -Wall

OBJS = main.o yardim.o sinirlar.o interaktif.o dosya.o algoritmalar.o\
       aritmetikortalama.o medyan.o mod.o harmonikortalama.o \
       ortalamasapma.o geometrikortalama.o varyans.o standartsapma.o

HDR = $(IDIR)/main.h $(IDIR)/algoritmalar.h


$(NAME): $(OBJS)
	$(CC) $^ $(CFLAGS) -o $@

again: clean $(NAME)

build:
	$(CC) $(SDIR)/* $(CFLAGS) -o $(NAME)

%.o: $(SDIR)/%.c $(IDIR)/%.h $(HDR)
	$(CC) -c -o $@ $< $(CFLAGS) $(DBGFLAGS)


.PHONY: clean

clean:
	rm -rf *.o $(NAME)
