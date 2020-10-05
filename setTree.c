#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct _TreeSet {
    int rank; //rank = 높이
    char data;
    struct _Set* link;
}TreeSet;

//일단 자기 자신을 가리키는 새 노드 생성
TreeSet* makeSet(char value)
{
    TreeSet* newNode = (TreeSet*)malloc(sizeof(TreeSet));
    newNode->data = value;
    newNode->link = newNode;
    newNode->rank = 0;
    return newNode;
}

//Find
TreeSet* findSet(TreeSet* root)
{
    if (root->link == root)
        return root;
    else
        findSet(root->link);
}

//Set 합치기
void treeUnion(TreeSet* firstTree, TreeSet* secondTree)
{
    TreeSet* xTreeRoot = findSet(firstTree);
    TreeSet* yTreeRoot = findSet(secondTree);
    //rank가 작은 트리의 루트의 링크를 큰 트리의 루트에 연결
    if (xTreeRoot->rank > yTreeRoot->rank)
    {
        yTreeRoot->link = xTreeRoot;
        printf("%c --> %c \n",yTreeRoot->data , xTreeRoot->data);
    }
    else
    {
        //xRank <= yRank인 경우 -> x링크를 y링크로 주고 y링크 1 추가해줌. (즉, y링크가 루트가됨)
        xTreeRoot->link = yTreeRoot;
        printf("%c --> %c \n", xTreeRoot->data, yTreeRoot->data );
        if (xTreeRoot->rank == yTreeRoot->rank)
            yTreeRoot->rank++; //rank가 같아짐을 방지
    }
}

void question1_1()
{
    TreeSet* firstTree = makeSet('a');
    TreeSet* secondTree = makeSet('b');
    treeUnion(firstTree, secondTree);
    TreeSet* thirdTree = makeSet('c');
    treeUnion(firstTree, thirdTree);
}


int main(void)
{
    question1_1();


    return 0;
}