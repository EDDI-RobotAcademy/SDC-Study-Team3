#ifndef __BOARD_API_COMMAND_TABLE_MAPPER_H__
#define __BOARD_API_COMMAND_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_api_command.h"
#include "list_handler/list_read_data/list_read_data_handler.h"

#define __BOARD_API_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__BOARD_API_COMMAND_TABLE(BOARD_API_LIST_READ_DATA, list_read_data_call)
//__BOARD_API_COMMAND_TABLE(VECTOR_SUB_SERVICE_EXECUTE, vector_sub)

#ifdef __cplusplus
}
#endif

#endif