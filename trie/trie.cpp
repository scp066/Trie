#include "trie.h"
//Node Methods

node::node(std::string word): key(word), count(1){
	for(int i=0; i<26; i++){
		this->child[i]=nullptr;
	}
}


node::~node(){


}
//trie Private Methods

void trie::destroy(){

}

node* trie::insert(node* root, std::string& word, int depth = 1){
	if(!root){
		return new node(word);
	}
	if(root->key == word){
		root->count++;
		return root;
	}
	std::string fragment = word.substr(0,depth);
	root->child[fragment[depth-1]-97]=insert(root->child[fragment[depth-1]-97], word, depth++);
	return root;
}

node* trie::search(node* root, std::string& word){

}

//trie Public Methods

trie::trie():root(new node(" ")){

}

trie::~trie(){

}

void trie::insert(std::string word){
	int length = word.length();
	for(int i=1; i<length; i++){
		std::string fragment=word.substr(0,i);
		insert(this->root, fragment);
	}
}

node* trie::search(std::string word){

}
