#ifndef __BOARD_SERVICE_COMMAND_H__
#define __BOARD_SERVICE_COMMAND_H__

#ifdef __cplusplus
extern "C" {
#endif

enum board_service_command
{
    BOARD_SERVICE_LIST,
    BOARD_SERVICE_READ,
    BOARD_SERVICE_WRITE,
    BOARD_SERVICE_EDIT,
    BOARD_SERVICE_DELETE,
    BOARD_SERVICE_END
};

#define BOARD_SERVICE_EXECUTE_BUFFER_COUNT       (BOARD_SERVICE_END)
#define BOARD_SERVICE_EXECUTE_BUFFER             ((BOARD_SERVICE_END) - 1)

#ifdef __cplusplus
}
#endif

#endif