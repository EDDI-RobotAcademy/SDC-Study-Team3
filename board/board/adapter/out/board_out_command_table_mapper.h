#ifndef __BOARD_OUT_COMMAND_TABLE_MAPPER_H__
#define __BOARD_OUT_COMMAND_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "board_out_command.h"
#include "list_out/list_out_command_handler.h"

#define __BOARD_OUT_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,


__BOARD_OUT_COMMAND_TABLE(BOARD_OUT_LIST, list_out)

#ifdef __cplusplus
}
#endif

#endif