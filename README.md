# .txt File Encoder and Decoder

The goal of this project is to compress and decompress .txt files by implementing the Huffman encoding algorithm using binary heap. The encoder will take in a normal .txt file and output the keys of each letter as well as the encoded text. The decoder takes the encoded file and brings it back to original file.

## Getting Started

To begin, just clone or download this repository. Unzip the file if necessary. Open terminal in the folder. Type 'make' to execute Makefile. When the program is ready, you will be prompted with the message 'READY!'

## Running the Program

To encode a .txt file, you will need to execute the encoder (./encoder <Example Text Here>). To decode the encoded file, you will need to execute the decoder (./decoder <Example Text Here>). An example using the given example text files are shown below.

```
./decoder ExampleText.txt
./encoder EncodedExample.txt
```

### Example Encoder Output

```
space 00
" 01011111
) 010111100
, 010110
- 010111010
. 010000
; 01011100
A 010111101
I 1011110
M 011110111
.
.
.
v 01111010
w 01010
x 011110110
y 101110
----------------------------------------
010111011 1111 01010 010110 00 1100 1000 1110 01100 10100 1000 01110 01110 101110 010110 00 1101 1100 00 01010 10100 1101 1110 1101 1100 011111 00 1001 01100 10110 10101 00 1000 01011100 00 1000 1100 01101 00 1001 1111 00 1110 01010 1101 1001 1110 00 1000 00 1110 
.
.
.
1111 010110 00 1100 1111 01010 00 1110 1111 00 011111 1111 00 1111 1100 00 01010 1101 1110 10101 00 1110 10101 1101 1001 00 1111 01101 01101 00 10110 1111 1100 1110 10100 1000 1011111 1110 1101 1111 1100 010000 010000 010000  
----------------------------------------
```
### Example Decoder Output (from Gatsby)

```
Now, naturally, in writing such a story as this, with its conditions as laid down in its Introduction, it is not surprising that an occasional "rough spot" in composition is found. So I trust that a critical public will hold constantly in mind that I am voluntarily avoiding words containing that symbol which is, by far, of most common inclusion in writing our Anglo-Saxon as it is, today. Many of our most common words cannot show; so I must adopt synonyms; and so twist a thought around as to say what I wish with as much clarity as I can.) So, now to go on with this odd contraption...
```


