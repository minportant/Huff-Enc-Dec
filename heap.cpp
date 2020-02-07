// Min Woo Kim

#include <iostream>
#include "heap.h"
#include "huffNode.h"

using namespace std;

Heap::Heap(){
  heap_size = 0;
  HuffNode* empty = new HuffNode();
  heapVector.push_back(empty);
}

Heap::Heap(vector<HuffNode*> vec) : heap_size(vec.size()) {
  heapVector = vec;
  heapVector.push_back(heapVector[0]);
  heapVector[0]->freq = 0;
  for(int i = heap_size/2; i > 0; i--){
    percolateDown(i);
  }
}

Heap::~Heap(){
}

void Heap::insert(HuffNode*& hn){
  heapVector.push_back(hn);
  percolateUp(++heap_size);
}

void Heap::percolateUp(int hole){
  HuffNode* hn = heapVector[hole];
  for(;(hole > 1) && (hn->freq < heapVector[hole/2]->freq); hole /= 2){
    heapVector[hole] = heapVector[hole/2];
  }
  heapVector[hole] = hn;
}

HuffNode* Heap::deleteMin(){
  if(heap_size == 0){
    throw "deleteMin() called on empty heap";
  }
  HuffNode* ret = heapVector[1];
  heapVector[1] = heapVector[heap_size--];
  heapVector.pop_back();
  percolateDown(1);
  return ret;
}

void Heap::percolateDown(int hole){
  HuffNode* hn = heapVector[hole];
  while(hole*2 <= heap_size){
    int child = hole*2;
    if((child+1 <= heap_size) && (heapVector[child+1]->freq < heapVector[child]->freq)){
      child++;
    }
    if(hn->freq > heapVector[child]->freq){
      heapVector[hole] = heapVector[child];
      hole = child;
    } else {
      break;
    }
  }
  heapVector[hole] = hn;
}

HuffNode* Heap::findMin(){
  if(heap_size == 0){
    throw "findMin() called on empty heap";
  }
  return heapVector[1];
}

unsigned int Heap::size(){
  return heap_size;
}

void Heap::makeEmpty(){
  heap_size = 0;
  heapVector.resize(1);
}

bool Heap::isEmpty(){
  return heap_size == 0;
}

