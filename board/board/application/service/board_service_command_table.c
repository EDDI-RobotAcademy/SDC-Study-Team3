#include <stdio.h>




#include "board_service_command.h"
#include "list/list_service_command_handler.h"
#include "read/read_service_command_handler.h"
#include "add/add_service_command_handler.h"
#include "edit/edit_service_command_handler.h"
#include "delete/delete_service_command_handler.h"

#include "../../../utility/file/file_io/read_data.h"


#include "board_service_command_table.h"

void just_dummy()
{
    printf("단순 더미\n");
}



const board_service_call_ptr_t \
    board_service_command_table[BOARD_SERVICE_EXECUTE_BUFFER_COUNT] = {
        [0 ... BOARD_SERVICE_EXECUTE_BUFFER] = just_dummy,
        #include "board_service_command_table_mapper.h"
};