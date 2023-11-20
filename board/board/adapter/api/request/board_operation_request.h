#ifndef __BOARD_OPERATION_REQUEST_H__
#define __BOARD_OPERATION_REQUEST_H__

#include "../../../domain/model/post_model.h"

typedef struct _board_operation_request board_operation_request;

struct _board_operation_request
{
    post_model *first_board;
    
};

board_operation_request *init_board_operation_request(post_model *);
void print_board_operation_request(board_operation_request *);

#endif