build	:
	gcc main.c -o sinker
run	: build
	./sinker
