#ifndef __DELETE_SERVICE_COMMAND_HANDLER_H__
#define __DELETE_SERVICE_COMMAND_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../domain/model/post_model.h"

#include "../../../adapter/api/request/board_operation_request.h"

void post_delete2(void);

void post_delete(board_operation_request *request);


void delete_test();

void delete_post_model_from_post_array(unsigned int);

#ifdef __cplusplus
}
#endif

#endif