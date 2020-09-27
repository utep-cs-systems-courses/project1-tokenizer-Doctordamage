tokenizer: tokenizer.o tokenizerTester.o history.o

	cc -o tokenizer tokenizer.o tokenizerTester.o history.o

tokenizer.o: tokenizer.h tokenizer.c



tokenizerTester.o: tokenizerTester.c tokenizer.h history.h



history.o: history.h history.c tokenizer.h

clean:

	rm -f *.o tokenizer
