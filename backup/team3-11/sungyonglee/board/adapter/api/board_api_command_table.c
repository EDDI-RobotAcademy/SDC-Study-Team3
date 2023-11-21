#include "board_api_command_table.h"
#include "list_handler/list_read_data/list_read_data_handler.h"

#include <stdio.h>
#include "board_api_command.h"

//void just_dummy(vector_operation_request *nothing) -> void just_dummy(void) (231121 13:11 일단 void 처리함)
void just_dummy(void)
{
    printf("단순 더미\n");
}

const board_api_call_ptr_t  \
    board_api_command_table[BOARD_API_BUFFER_COUNT] = {
        [0 ... BOARD_API_BUFFER] = just_dummy,
        #include "board_api_command_table_mapper.h"
};