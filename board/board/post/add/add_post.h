#ifndef __ADD_POST_H__
#define __ADD_POST_H__

typedef struct Node{
    int id;
    char subject[100];
    char memo[1000];
};

typedef struct Board
{
    Node *notice;
    int list_count;
};


#endif