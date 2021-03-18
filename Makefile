CXX = g++
CXX_FLAGS = -I. -std=c++17 -Wfatal-errors -Wall -Wextra -Wpedantic -Wconversion -Wshadow

TMPFILE=tmpimg
GEOM?=
VARS?=

ifdef GEOM
VARS += -V geometry:"$(GEOM)"
endif

PRJ = main
SRC = $(PRJ).cpp
BIN = a.out

.PHONY : all solution imgpdf sol2pdf clean test grade

solution: sol2pdf imgpdf clean

imgpdf:
	pdftoppm $(PRJ)-t.pdf $(TMPFILE) -png
	convert $(TMPFILE)*.png $(PRJ).pdf

sol2pdf:
	enscript --color=1 -C -Ecpp -fCourier9 -o - $(PRJ).sol.* | ps2pdf - $(PRJ)-t.pdf

all: $(BIN)

test.o: test.cpp
	$(CXX) $(CXX_FLAGS) test.cpp -c

$(BIN): test.o $(PRJ).o
	g++ $(CXX_FLAGS) test.o $(SRC)

clean:
	@rm $(PRJ)-t.pdf $(TMPFILE)*.png || true
	rm $(BIN) *.o | true

test: $(BIN)
	./$(BIN)

c1: $(BIN)
	./$(BIN) -c c1

c2: $(BIN)
	./$(BIN) -c c2

c3: $(BIN)
	./$(BIN) -c c3

a1: $(BIN)
	./$(BIN) -c a1

a2: $(BIN)
	./$(BIN) -c a2

a3: $(BIN)
	./$(BIN) -c a3

