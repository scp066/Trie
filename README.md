# Trie
Final Project Requirements:<br/>
Implement the Data Structure (using classes)<br/>
• Must store the words of an input text file<br/>
• for each word (node) in the tree, a count with the
  number of repeats must also be stored<br/>
• Ensure at least insert/search methods are correctly
  implemented<br/>
• search must also return/show the count<br/>
• Generate a DOT file for visualization<br/>

Our project can be built with any c++ compiler using the c++11 std library.<br/>
Example compilation command:
g++ trie.cpp main.cpp -o prog

The main.cpp handles file io and tests the trie with a given input file and outputs a graphvis formatted file. All test files should only contain alphabetical characters (a-z) or (A-Z) with commas separating the individual words (see test files for an example). The trie as implemented supports only alphabetical charaters. For an example graphvis file see large_test.gv.
