#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct TrieNode{
    char data;
    TrieNode * children[26];
    int is_leaf;
}TrieNode;

TrieNode* make_trienode(char data) {
    // Allocate memory for a TrieNode
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    for (int i=0; i<26; i++)
        node->children[i] = NULL;
    node->is_leaf = 0;
    node->data = data;
    return node;
}

TrieNode* insert( TrieNode *ppTrie, char *word){
    TrieNode* temp = ppTrie;

    for (int i=0; word[i] != '\0'; i++) {
        int idx = (int) word[i] - 'a';
        if (temp->children[idx] == NULL) {
            
            temp->children[idx] = make_trienode(word[i]);
        }
        else {

        }
        temp = temp->children[idx];
    }
    temp->is_leaf = 1;
    return ppTrie;

}

int numberOfOccurances(struct Trie *pTrie, char *word);

struct Trie *deallocateTrie(struct Trie *pTrie){

    for(int i=0; i<26; i++) {
        if (node->children[i] != NULL) {
            deallocateTrie(node->children[i]);
        }
        else {
            continue;
        }
    }
    free(node);
    return pTrie;
}

int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
      for (int i=0;i<5;i++)
      {
          printf("\t%s : %d\n",pWords[i], numberOfOccurances(&trie, pWords[i]));
     }
    trie = deallocateTrie(&trie);
    if (trie != NULL)
       printf("There is an error in this program\n");
    return 0;
}