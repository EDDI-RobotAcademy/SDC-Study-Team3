#ifndef __BOARD_OPERATION_REQUEST_H__
#define __BOARD_OPERATION_REQUEST_H__


#ifdef __cplusplus
extern "C" {
#endif


#include "../../../domain/model/post_model.h"

typedef struct _board_operation_request board_operation_request;

struct _board_operation_request
{
    post_model *first_board;
    
};

board_operation_request *init_board_operation_request(post_model *);
void request_board_operation();

void set_post_model_title_from_input(post_model *post_from_request, char *title);
void set_post_model_writer_from_input(post_model *post_from_request, char *writer);
void set_post_model_password_from_input(post_model *post_from_request, char *password);
void set_post_model_content_from_input(post_model *post_from_request, char *content);


#ifdef __cplusplus
}
#endif

#endif