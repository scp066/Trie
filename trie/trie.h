#ifndef _TRIE_H_
#define _TRIE_H_
#include <vector>
#include <string>
class trie{
    private:
        *node root;
        void destroy();
        *node search(*node root, std::string& word);
        void insert(*node root, std::string& word);

    public:
        trie();
        ~trie();
        void insert(std::string word);
        *node search(std::string word);
};



class node{
    private:
        std::string key;
        std::vector<*node> children;
        int count;

    public:
        node();
        node(char data);
        ~node();
    friend class trie;
};

#endif
