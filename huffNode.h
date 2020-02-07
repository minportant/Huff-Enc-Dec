// Min Woo Kim

#ifndef HUFFNODE_H
#define HUFFNODE_H

#include <vector>
#include <string>
using namespace std;

class HuffNode {
public:
  HuffNode();
  void setValue(char val){
    value = val;
  }
  void setFreq(int fq){
    freq = fq;
  }
  char getValue(){
    return value;
  }
  int getFreq(){
    return freq;
  }
  HuffNode* getRight(){
    return right;
  }
  HuffNode* getLeft(){
    return left;
  }
  void setLeft(HuffNode* n){
    left = n;
  }
  void setRight(HuffNode* n){
    right = n;
  }
private:
  HuffNode *left, *right;
  char value;
  int freq;
  friend class Heap;
};

#endif
