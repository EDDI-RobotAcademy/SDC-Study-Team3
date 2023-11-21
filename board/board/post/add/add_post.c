#include "add_post.h"
#include <stdio.h>


void set_post(Board *board)
{
    int i;
    for (i=0; i<board->list_count; i++)
    {
        if(board->notice[i].id == -1){break;}
    }
}

void print_post(Board *board)
{
    int i;
    for(i=0; i<board->list_count; i++)
    {
        printf("ID: %d\n", board->notice[i].id);
        printf("제목: %s\n", board->notice[i].subject);
        printf("내용: %s\n", board->notice[i].memo);
    }
}