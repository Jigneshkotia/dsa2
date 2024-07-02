#include<iostream>

using namespace std;

class trieNode {
    public:
    char data;
    trieNode* children[26];
    bool isTerminal;

    trieNode(char ch){
        data=ch;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal= false;
    }
};

class Trie{
    public:
    trieNode* root;

    Trie(){
        root = new trieNode('\0');
    }


    void insertUtil(trieNode* root, string word){
        //Base Case
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        //assuming word is in Caps
        int idx = word[0]-'a';
        trieNode* child;

        //Present
        if(root -> children[idx] != NULL){
            child = root->children[idx];
        }else{
            //Absent
            child = new trieNode(word[0]);
            root -> children[idx] = child;
        }

        //Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }


    void deleteUtil(trieNode* root, string word){
        //base case
        if(word.length() == 0){
            if(root->isTerminal){
                root->isTerminal= false;
            }else{
                return;
            }
        }


        int idx = word[0] -'A';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return;
        }

        deleteUtil(child, word.substr(1));

    }

    void deleteWord(string word){
        deleteUtil(root, word);
    }

    void printSuggestions(trieNode* curr, vector<string> &temp, string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }

        for( char ch = 'a'; ch<= 'z'; ch++){
            trieNode* next = curr->children[ch-'a'];

            if(next != NULL){
                prefix.push_back(ch);
                printSuggestions(next , temp, prefix);
                prefix.pop_back();
            }
        }

    }

    vector<vector<string> > getSuggestions(string queryStr){
        trieNode* prev = root;
        vector<vector<string> > output;
        string prefix = "";

        for( int i = 0; i< queryStr.length(); i++){
            char lastCh = queryStr[i];
            prefix.push_back(lastCh);

            //check for lastch
            trieNode* curr = prev->children[lastCh - 'a'];

            //if not found
            if(curr == NULL){
                break;
            }

            //if found
            vector<string> temp;
            printSuggestions(curr, temp, prefix);

            output.push_back(temp);
            temp.clear();
            prev = curr;

        }
    return output;
    }

};


//********* Implementing a Phone Directory **********
vector<vector<string> > phoneDirectory(vector<string> &contacts, string &queryStr){
    //creation of trie
    Trie* t = new Trie();

    //insert all contacts in trie
    for( int i = 0; i< contacts.size();i++){
        t->insertWord(contacts[i]);
    }

    return t->getSuggestions(queryStr);

}
