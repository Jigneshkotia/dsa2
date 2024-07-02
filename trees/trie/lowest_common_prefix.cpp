#include<iostream>
using namespace std;

//******** Directly *********** (more optiomised)
string longestCommonPrefix(vector<string > &arr, int n){
    string ans;

    for( int i = 0; i<arr[0].length();i++){
        char ch = arr[0][i];

        bool match = true;

        for( int j = 0;j<n; j++ ){

            if(arr[j].size() < i || ch != arr[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }else{
            ans.push_back(ch);
        }
    }
    return ans;
}


//********* Using Tries ********** (less optimised)
class trieNode {
    public:
    char data;
    trieNode* children[26];
    int childCount;
    bool isTerminal;

    trieNode(char ch){
        data=ch;
        for(int i = 0; i<26; i++){
            children[i] = NULL;
        }
        childCount = 0;
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
            root->childCount++;
            root -> children[idx] = child;
        }

        //Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    void lcp(string word , string ans){
        for( int i = 0; i<word.length(); i++){
            char ch = word[i];
            if(root->childCount == 1){
                ans.push_back(ch);

                int idx = ch-'a';
                root = root->children[idx];
            }else{
                break;
            }

            if(root->isTerminal){
                break;
            }
        }

    }
};


string longestCommonPrefix_Trie(vector<string> & arr, int n){
    Trie* t = new Trie();

    for( int i = 0 ; i<n; i++){
        t->insertWord(arr[i]);
    }

    string first = arr[0];
    string ans = "";
    t->lcp(first, ans);

    return ans;

}



int main(){
    return 0;
}