all: tpp
	CGO_LDFLAGS_ALLOW="jaeger-tpp.a" go build

tpp:
	gcc -I. -c jaeger-tpp.c
	ar rcs jaeger-tpp.a jaeger-tpp.o

clean:
	rm -f main *.o