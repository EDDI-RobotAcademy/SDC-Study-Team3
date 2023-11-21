#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board_operation_request.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"
#include "../board_api_command.h"
#include "../board_api_command_table.h"
#include "../board_api_command_table_mapper.h"

#include "../../../application/service/board_service_command.h"
#include "../../../application/service/board_service_command_table.h"
#include "../../../application/service/board_service_command_table_mapper.h"



#include <stdlib.h>

board_operation_request *init_board_operation_request(post_model *first_board)
{
    board_operation_request *board_request = (board_operation_request *)malloc(sizeof(board_operation_request));

    board_request->first_board = first_board;

    return board_request;
}

void post_model_title_from_request(post_model *post_from_request, char *title)
{
    int title_length = strlen(title) + 1;
    post_from_request->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(post_from_request->title, title, title_length);
}

void post_model_writer_from_request(post_model *post_from_request, char *writer)
{
    int writer_length = strlen(writer) + 1;
    post_from_request->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(post_from_request->writer, writer, writer_length);
}

void post_model_contents_from_request(post_model *post_from_request, char *contents)
{
    int contents_length = strlen(contents) + 1;
    post_from_request->content = (char *)malloc(sizeof(char) * contents_length);
    strncpy(post_from_request->content, contents, contents_length);
}

void request_board_operation()
{
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    post_model *tmp_post_model = (post_model *)malloc(sizeof(post_model));

    printf("제목을 입력하세요.\n");
    get_user_keyboard_input(keyboard_input_from_user);
    post_model_title_from_request(tmp_post_model, keyboard_input_from_user);
    
    printf("작성자를 입력하세요.\n");
    get_user_keyboard_input(keyboard_input_from_user);
    post_model_writer_from_request(tmp_post_model, keyboard_input_from_user);
    
    printf("내용을 입력하세요.\n");
    get_user_keyboard_input(keyboard_input_from_user);
    post_model_contents_from_request(tmp_post_model, keyboard_input_from_user);

    board_operation_request *r = init_board_operation_request(tmp_post_model);

    //board_service_command_table[BOARD_SERVICE_WRITE];
}

