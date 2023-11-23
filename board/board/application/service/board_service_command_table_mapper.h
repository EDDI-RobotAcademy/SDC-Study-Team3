#ifndef __BOARD_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __BOARD_SERVICE_COMMAND_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif



#include "board_service_command.h"

#include "../../adapter/api/request/board_operation_request.h"

#include "list/list_service_command_handler.h"
#include "read/read_service_command_handler.h"
#include "add/add_service_command_handler.h"
#include "edit/edit_service_command_handler.h"
#include "delete/delete_service_command_handler.h"

#include "board_service_command_table.h"


#define __BOARD_SERVICE_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_LIST, post_list)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_READ, post_read)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_WRITE, post_add)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_EDIT, post_edit)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_DELETE, post_delete)

#ifdef __cplusplus
}
#endif


#endif