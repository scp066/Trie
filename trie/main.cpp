#ifndef _TRIE_H_
#define _TRIE_H_
#include <string>
class node{
    private:
        std::string key;
        node* child[26];
        int count;


    public:
        node(std::string word);
        ~node();
        int getcount();
        std::string getkey();
    friend class trie;
};

class trie{
    private:
        node* root;
        void destroy(node* root);
        void changecase(std::string& word);
        node* search(node* root, std::string& word, int depth);
        node* insert(node* root, std::string& word, int depth);

    public:
        trie();
        ~trie();
        void insert(std::string word);
        node* search(std::string word);
};

#endif
