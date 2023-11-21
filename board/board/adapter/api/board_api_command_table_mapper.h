#ifndef __BOARD_API_COMMAND_TABLE_MAPPER_H__
#define __BOARD_API_COMMAND_TABLE_MAPPER_H__

#ifdef __cplusplus
extern "C"{
#endif


#include "board_api_command_table.h"


#define __BOARD_API_COMMAND_TABLE(number, function_prototype) \
    [number] = function_prototype,

//__BOARD_API_COMMAND_TABLE(BOARD_API_OPERATION, )

#ifdef __cplusplus
}
#endif


#endif