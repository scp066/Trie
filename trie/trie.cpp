#include "trie.h"
//Node Methods

node::node(std::string word): key(word), count(1){
	for(int i=0; i<26; i++){
		this->child[i]=nullptr;
	}
}


node::~node(){


}

int node::getcount(){
	return this->count;
}

std::string node::getkey(){
	return this->key;
}

//trie Private Methods

void trie::destroy(node* root){
	for(int i = 0; i<26; i++){
		if(root->child[i]){
			destroy(root->child[i]);
		}
	}
	delete root;
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
	int index = fragment[depth-1]-97;
	root->child[index]=insert(root->child[index], word, depth+1);
	return root;
}

node* trie::search(node* root, std::string& word, int depth =1){
	if(!root || root->key == word){
		return root;
	}
	std::string fragment = word.substr(0, depth);
	return search(root->child[fragment[depth-1]-97], word, depth+1);
}

void trie::changecase(std::string& word){
	int length = word.size()+1;
	for(int i = 0; i<length; i++){
		if(word[i]<97){
			word[i]+=32;
		}
	}
}

void trie::generatedot(node* root, std::ofstream& file){
	if(!root){
		return;
	}
	for(int i=0; i<26; i++){
		if(root->child[i]){
			if(root->key == " "){
				file<<"\"ROOT\""<<" -- \""<<root->child[i]->key<<"\";\n";
			}
			else{
				file<<"\""<<root->key<<"\" -- \""<<root->child[i]->key<<"\";\n";
			}
			generatedot(root->child[i], file);
		}
	}
}

//trie Public Methods

trie::trie():root(new node(" ")){

}

trie::~trie(){
	destroy(this->root);
}

void trie::insert(std::string word){
	changecase(word);
	int length = word.length()+1;
	for(int i=1; i<length; i++){
		std::string fragment=word.substr(0,i);
		insert(this->root, fragment);
	}
}

node* trie::search(std::string word){
	changecase(word);
	return search(this->root, word);
}

void trie::generatedot(std::string& fname){
	std::ofstream graph(fname);
	if(graph.is_open()){
	graph<<"graph Trie{\n";
	generatedot(this->root, graph);
	graph<<"}";
	graph.close();
	}
}
