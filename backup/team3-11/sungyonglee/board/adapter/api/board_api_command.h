#ifndef __BOARD_API_COMMAND_H__
#define __BOARD_API_COMMAND_H__

#ifdef __cplusplus
extern "C" {
#endif

enum board_api_command
{
    BOARD_API_LIST_READ_DATA,
    // BOARD_API_READ,
    // BOARD_API_DELETE,
    // BOARD_API_WRITE,
    // BOARD_API_EDIT,
    BOARD_API_END
};

#define BOARD_API_BUFFER_COUNT         (BOARD_API_END)
#define BOARD_API_BUFFER               ((BOARD_API_END) - 1)

#ifdef __cplusplus
}
#endif

#endif