# Min Woo Kim

CXX=clang++
DEBUG=-Wall
OFILES1=heap.o huffmanenc.o huffNode.o
OFILES2=huffmandec.o huffNode.o
.SUFFIXES: .o .cpp
	
all: HuffmanEncoder HuffmanDecoder
	
HuffmanEncoder: $(OFILES1)
	$(CXX) $(DEBUG) $(OFILES1) -o encoder
	
HuffmanDecoder: $(OFILES2)
	$(CXX) $(DEBUG) $(OFILES2) -o decoder
	
clean:
	-rm -f *.o *~ a.out
	
heap.o: heap.cpp heap.h huffNode.h
huffNode.o: huffNode.cpp huffNode.h
huffmanenc.o: huffmanenc.cpp heap.h huffNode.h
huffmandec.o: huffmandec.cpp huffNode.h
