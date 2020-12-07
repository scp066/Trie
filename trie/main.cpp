#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "trie.h"



int main(int argc, char *argv[]){

    /* For test automation
    if(argc !=2){
        std::cout<<"Usage:\n";
        std::cout<<"./prog <fname>\n";
        return 0;
    }
    std::ifstream file;
    file.open(argv[1]);
    std::string element;
    trie tree;
    while(std::getline(file, element, ',')){
        tree.insert(element);
    }
    */
    //Test Cases
    trie tree;
    tree.insert("hello");
    if(tree.search("hell")){
        std::cout<<"Found!"<<std::endl;
    }
    tree.insert("hello");
    tree.insert("Hello");
    node* temp = tree.search("Hello");
    if(temp){
        std::cout<<temp->getcount()<<std::endl;
    }
}

