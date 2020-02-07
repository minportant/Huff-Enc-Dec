// Min Woo Kim

#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <map>
#include "huffNode.h"

using namespace std;

class Heap{
 public:
  Heap();
  Heap(vector<HuffNode*> vec);
  ~Heap();
  
  void insert(HuffNode*& hn);
  HuffNode* findMin();
  HuffNode* deleteMin();
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  HuffNode* getRoot(){
    return root;
  }
  void setRoot(HuffNode* r){
    root = r;
  }
 private:
  HuffNode *root;
  vector<HuffNode*> heapVector;
  unsigned int heap_size;

  void percolateUp(int hole);
  void percolateDown(int hole);
};

#endif
