
#include "add/add_api_handler.h"

#include <stdio.h>
#include "board_api_command.h"
#include "list_handler/list/list_api.h"
#include "list_handler/list_read_data/list_read_data_handler.h"
#include "board_api_command_table.h"

//void just_dummy(vector_operation_request *nothing) -> void just_dummy(void) (231121 13:11 일단 void 처리함)
// 함수명이 다른 table 의 더미용 함수명과 동일하지 않도록 확인이 필요합니다.
void just_dummy(void)
{
    printf("단순 더미\n");
}



const board_api_call_ptr_t  \
    board_api_command_table[BOARD_API_BUFFER_COUNT] = {
        [0 ... BOARD_API_BUFFER] = just_dummy,
        #include "board_api_command_table_mapper.h"
};