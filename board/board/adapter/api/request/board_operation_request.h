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

void post_info_title_from_request(post_model *post_from_request, char *title);
void post_info_writer_from_request(post_model *post_from_request, char *writer);
void post_info_contents_from_request(post_model *post_from_request, char *contents);



#ifdef __cplusplus
}
#endif

#endif