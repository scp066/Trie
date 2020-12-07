#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trie.h"



int main(int argc, char *argv[]){
    if(argc !=2){
        std::cout<<"Usage:\n";
        std::cout<<"./prog <file in>\n";
        return 0;
    }
    std::ifstream file;
    file.open(argv[1]);
    std::string element;
    trie tree;
    std::string fname = "trie.gv";
    std::vector<std::string> searchlist;
    while(std::getline(file, element, ',')){
        int size = searchlist.size();
        bool inlist = false;
        tree.insert(element);
        for(int i=0; i<size; i++){
            if(element == searchlist[i]){
                inlist = true;
                break;
            }
        }
        if(!inlist){
            searchlist.push_back(element);
        }
    }
    int size = searchlist.size();
    for(int i=0; i<size; i++){
        node* t = tree.search(searchlist[i]);
        std::cout<<"The word \""<<t->getkey()<<"\" is in the Trie "<<t->getcount()<<" times.\n";
    }
    tree.generatedot(fname);
}
