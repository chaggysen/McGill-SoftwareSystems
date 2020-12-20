secretapp : main.o secret.o
        gcc -o secretapp main.o secret.o

main.o: main.c secret.h
        gcc -c main.c

secret.o: secret.c
        gcc -c secret.c

clean:
        rm -f main main.o secret.o