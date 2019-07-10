all: tpp
	go build

tpp:
	gcc -I. -c jaeger-tpp.c -o jaeger-tpp.o
	ar -rc jaeger-tpp.a jaeger-tpp.o

clean:
	rm -f *.o *.a
