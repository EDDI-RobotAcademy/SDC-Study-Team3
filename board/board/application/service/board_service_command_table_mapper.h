#ifndef __BOARD_ADD_SERVICE_COMMAND_TABLE_MAPPER_H__
#define __BOARD_ADD_SERVICE_COMMAND_TABLE_MAPPER_H__

#include "board_service_command.h"
#include "list/list_service_command_handler.h"
#include "read/read_service_command_handler.h"
#include "add/add_service_command_handler.h"
#include "edit/edit_service_command_handler.h"
#include "delete/delete_service_command_handler.h"

void dumm()
{

}


#define __BOARD_SERVICE_COMMAND_TABLE(number, function_prototype) \
        [number] = function_prototype,

__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_LIST, dumm)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_READ, post_read)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_WRITE, post_add)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_EDIT, post_edit)
__BOARD_SERVICE_COMMAND_TABLE(BOARD_SERVICE_ELETE, post_delete)



/*  BOARD_SERVICE_LIST,
    BOARD_SERVICE_READ,
    BOARD_SERVICE_WRITE,
    BOARD_SERVICE_EDIT,
    BOARD_SERVICE_DELETE,
    BOARD_SERVICE_END*/
#endif