#ifndef __BOARD_API_COMMAND_TABLE_MAPPER_H__
#define __BOARD_API_COMMAND_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_api_command.h"
#include "list_handler/list_read_data/list_read_data_handler.h"
#include "list_handler/list/list_api.h"
#include "add/add_api_handler.h"

#define __BOARD_API_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

// api 쪽 handler 가 추가 되면 한 줄씩 추가하면 됨
// ex) ____BOARD_API_COMMAND_TABLE(board_api_command.h 에서 지정한 이름, 호출할 함수이름)
__BOARD_API_COMMAND_TABLE(BOARD_API_LIST_READ_DATA, list_api)
// __BOARD_API_COMMAND_TABLE(BOARD_API_ADD, add_api)

#ifdef __cplusplus
}
#endif

#endif