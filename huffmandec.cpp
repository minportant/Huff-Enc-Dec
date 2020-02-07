// Min Woo Kim

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

#include "huffNode.h"

void generateCodingTree(HuffNode* temp, string prefixSoFar, vector<char> c, vector<string> p){
  HuffNode* left = new HuffNode();
  HuffNode* right = new HuffNode();
  for(int i = 0; i < p.size(); i++){
    if(p[i] == prefixSoFar){
      temp->setValue(c[i]);
      return;
    }
  }
  temp->setLeft(left);
  generateCodingTree(temp->getLeft(), prefixSoFar + "0", c, p);
  temp->setRight(right);
  generateCodingTree(temp->getRight(), prefixSoFar + "1",c, p);
}

string decoder(HuffNode* root, string str){
  string answer = "";
  HuffNode* itr = root;
  for(int i = 0; i < str.size(); i++){
    if(str[i] == '1'){
      itr = itr->getRight();
    }else{
      itr = itr->getLeft();
    }
    if(itr->getLeft() == NULL && itr->getRight() == NULL){
      answer += itr->getValue();
      itr = root;
    }
  }
  return answer;
}
  

// main(): we want to use parameters
int main (int argc, char **argv) {
    // verify the correct number of parameters
    if ( argc != 2 ) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }
    // attempt to open the supplied file; must be opened in binary
    // mode, as otherwise whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if ( !file.is_open() ) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }
    
    vector<char> c;
    vector<string> p;
    HuffNode* root = new HuffNode();
    
    // read in the first section of the file: the prefix codes
    while ( true ) {
        string character, prefix;
        // read in the first token on the line
        file >> character;
        // did we hit the separator?
        if ( (character[0] == '-') && (character.length() > 1) )
            break;
        // check for space
        if ( character == "space" )
            character = " ";
        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '"
	// << prefix << "'" << endl;
	p.push_back(prefix);
	c.push_back(character[0]);
	
    }
    //create the coding tree
    generateCodingTree(root, "", c, p);
    
    /*cout<<root->getRight()->getRight()->getValue();
    cout<<root->getLeft()->getLeft()->getLeft()->getLeft()->getLeft()->getValue();
    cout<<root->getLeft()->getLeft()->getLeft()->getRight()->getRight()->getValue();
    cout<<root->getLeft()->getLeft()->getLeft()->getRight()->getLeft()->getValue();
    cout<<root->getLeft()->getLeft()->getRight()->getLeft()->getLeft()->getValue();
    cout<<root->getLeft()->getLeft()->getRight()->getRight()->getValue();
    cout<<root->getRight()->getLeft()->getLeft()->getLeft()->getValue();
    cout<<root->getLeft()->getLeft()->getLeft()->getLeft()->getRight()->getValue();
    cout<<root->getLeft()->getLeft()->getRight()->getLeft()->getRight()->getValue();
    cout<<root->getRight()->getLeft()->getLeft()->getRight()->getValue();
    cout<<root->getRight()->getLeft()->getRight()->getValue();
    cout<<root->getLeft()->getRight()->getValue()<<endl;;
    */

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while ( true ) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if ( bits[0] == '-' )
            break;
        // add it to the stringstream
        sstm << bits;
    }
    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();
    // print the decoded string
    //cout<<"----------------------------------------"<<endl;
    cout<<decoder(root, allbits)<<endl;
}
