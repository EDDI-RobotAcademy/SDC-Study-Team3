#ifndef __BOARD_API_COMMAND_H__
#define __BOARD_API_COMMAND_H__

#ifdef __cplusplus
extern "C"{
#endif

enum board_api_command
{
    BOARD_API_OPERATION,
    BOARD_API_END
};

#define BOARD_CALL_BUFFER_COUNT       (BOARD_API_END)
#define BOARD_CALL_BUFFER             ((BOARD_API_END) - 1)

#ifdef __cplusplus
}
#endif


#endif