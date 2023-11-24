#include "board_operation_request.h"

#include <stdlib.h>

board_operation_request *init_board_operation_request(post_model *first_board)
{
    board_operation_request *board_request = (board_operation_request *)malloc(sizeof(board_operation_request));

    board_request->first_board = first_board;

    return board_request;
}

void print_board_operation_request(board_operation_request *board_request)
{
   // print_post_model_object(board_request->first_board);
  //  print_post_model_object(board_request->second_board);
}