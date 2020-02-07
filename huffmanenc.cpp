//Min Woo Kim

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;

#include "heap.h"
#include "huffNode.h"
#include <map>
#include <vector>

void createCharTable(HuffNode* root, string str, map<char,string> &charTable){
  if(root == NULL){
    return;
  }
  if(!root->getLeft() && !root->getRight()){
    charTable[root->getValue()] = str;
  }
  createCharTable(root->getLeft(), str + "0", charTable);
  createCharTable(root->getRight(), str + "1", charTable);
}


Heap h;

int main(int argc, char **argv){
  map<char, int> freqTable;
  map<char, string > charTable;
  
  if(argc != 2){
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  FILE *fp = fopen(argv[1], "r");

  if(fp==NULL) {
    cout<<"File '"<<argv[1]<<"' does not exist!" << endl;
    exit(2);
  }

  // creating freq table with char
  char g;
  while((g = fgetc(fp)) != EOF){
    freqTable[g]++;
  }
  
  // putting freq to heap
  map<char, int>::iterator itr = freqTable.begin();
  while(itr != freqTable.end()){
    HuffNode* hn = new HuffNode();
    hn->setValue(itr->first);
    hn->setFreq(itr->second);
    h.insert(hn);
    itr++;
  }
  h.deleteMin();
  
  // creating char tree
  while(h.size() != 1){ 
    HuffNode *child0, *child1;
    HuffNode *top = new HuffNode();
    child0 = h.findMin();
    //cout<<child0->getValue()<<":"<<child0->getFreq()<<endl;
    h.deleteMin();
    child1 = h.findMin();
    //cout<<child1->getValue()<<":"<<child1->getFreq()<<endl;
    h.deleteMin();
    top->setFreq(child0->getFreq() + child1->getFreq());
    top->setValue('$');
    top->setLeft(child0);
    top->setRight(child1);
    h.insert(top);
  }
  
  // setting root to findMin()
  h.setRoot(h.findMin());
  
  // creating char table
  createCharTable(h.getRoot(), "",charTable);

  // printing the code
  map<char, string>::iterator itr2 = charTable.begin();
  while(itr2 != charTable.end()){
    if(itr2->first == ' '){
      cout<<"space "<<itr2->second<<endl;
    }else{
      cout<<itr2->first<<" "<<itr2->second<<endl;
    }
    itr2++;
  }
  
  cout<<"----------------------------------------"<<endl;

  rewind(fp);
  
  vector<char> lst;
  string totalBit = "";
  while((g = fgetc(fp)) != EOF){
    cout << charTable[g] << " ";
    totalBit += charTable[g];
  }
  
  cout<<endl;
  cout<<"----------------------------------------"<<endl;

  int totSym = h.findMin()->getFreq();
  int totDis = charTable.size()-1;
  int bitComp = totalBit.size();
  double compRatio = (double)(totSym*8)/bitComp;
  //cout<<"There are a total of " << totSym << " symbols that are encoded." <<endl;
  //cout<<"There are " << totDis << " distinct symbols used." <<endl;
  //cout<<"There were "<< totSym*8 << " bits in the original file." <<endl;
  //cout<<"There were "<< bitComp << " bits in the compressed file." << endl;
  //cout<<"This gives a compression ratio of "<<compRatio<<"."<<endl;
  //cout<<"The cost of the Huffman tree is "<<(double)(8/compRatio)<<" bits per character."<<endl;
  
  fclose(fp);
}
