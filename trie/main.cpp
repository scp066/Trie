#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "trie.h"


void addtolist(const std::string& element, std::vector<std::string>& list){
    bool inlist = false;
    int size = list.size();
    for(int i=0; i<size; i++){
            if(element == list[i]){
                inlist = true;
                break;
            }
        }
        if(!inlist){
            list.push_back(element);
        }
}

void searchtrie(trie& tree, const std::vector<std::string>& list){
    int size = list.size();
    for(int i=0; i<size; i++){
        node* t = tree.search(list[i]);
        std::cout<<"The word \""<<t->getkey()<<"\" is in the Trie "<<t->getcount()<<" times.\n";
    }
}


int main(int argc, char *argv[]){
    if(argc !=3){
        std::cout<<"Usage:\n";
        std::cout<<"./prog <file in> <dot file name>\n";
        std::cout<<"Input files should only have letters and commas to separate the words!\n";
        return 0;
    }
    std::ifstream file;
    file.open(argv[1]);
    std::string element;
    trie tree;
    std::string fname = argv[2];
    std::vector<std::string> searchlist;
    while(std::getline(file, element, ',')){
        tree.insert(element);
        addtolist(element, searchlist);
    }
    searchtrie(tree, searchlist);
    tree.generatedot(fname);
}

