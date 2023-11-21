#ifndef __ADD_SERVICE_COMMAND_HANDLER_H__
#define __ADD_SERVICE_COMMAND_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../adapter/api/request/board_operation_request.h"

void post_add(board_operation_request *request);

void wirte_post(post_model *model_to_write, char keyboard_input[]);

#ifdef __cplusplus
}
#endif

#endif

