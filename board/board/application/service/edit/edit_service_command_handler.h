#ifndef __EDIT_SERVICE_COMMAND_HANDLER_H__
#define __EDIT_SERVICE_COMMAND_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../adapter/api/request/board_operation_request.h"

void post_edit(board_operation_request *request);

void edit(unsigned int uid);

#ifdef __cplusplus
}
#endif

#endif