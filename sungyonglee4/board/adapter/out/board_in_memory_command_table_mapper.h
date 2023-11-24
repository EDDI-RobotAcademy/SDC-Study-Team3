#ifndef __BOARD_IN_MEMORY_COMMAND_TABLE_MAPPER_H__
#define __BOARD_IN_MEMORY_COMMAND_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_in_memory_command.h"
#include "list_out/list_out_command_handler.h"

#define __BOARD_OUT_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

// api 쪽 handler 가 추가 되면 한 줄씩 추가하면 됨
// ex) ____BOARD_OUT_COMMAND_TABLE(board_api_command.h 에서 지정한 이름, 호출할 함수이름)
__BOARD_OUT_COMMAND_TABLE(BOARD_OUT_LIST, list_out)
// __BOARD_OUT_COMMAND_TABLE(BOARD_API_ADD, add_api)

#ifdef __cplusplus
}
#endif

#endif