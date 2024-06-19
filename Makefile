
all: program

program:
	@mkdir -p ./out
	@cp example.txt out/conexoes.txt
	$(CC) -o ./out/main main.c -lm

clean:
	rm -r out