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
        int idx = word[0]-'A';
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


    bool searchUtil(trieNode* root, string word){
        //Base Case
        if(word.length() == 0){
            return root->isTerminal;
        }

        int idx = word[0]-'A';
        trieNode* child;

        if(root->children[idx] != NULL){
            child = root->children[idx];
        }else{
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word){
        return searchUtil(root, word);
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

};

int main(){
    Trie* t = new Trie();

    t->insertWord("JIGNESH");
    t->insertWord("ANKIT");
    cout<<"Present or Not "<< t->searchWord("ANKIT")<<endl;
    t->deleteWord("ANKIT");
    cout<<"Present or Not "<< t->searchWord("ANKIT")<<endl;
    cout<<"Present or Not "<< t->searchWord("JIGNESH")<<endl;

    return 0;
}