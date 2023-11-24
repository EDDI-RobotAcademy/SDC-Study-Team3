#include <stdio.h>
#include "board_in_memory_command.h"
#include "list_out/list_out_command_handler.h"

#include "board_in_memory_command_table.h"

//void just_dummy(vector_operation_request *nothing) -> void just_dummy(void) (231121 13:11 일단 void 처리함)
// 함수명이 다른 table 의 더미용 함수명과 동일하지 않도록 확인이 필요합니다.
void just_dummy_adapter_out(void)
{
    printf("단순 더미\n");
}



const board_out_call_ptr_t  \
    board_out_command_table[BOARD_OUT_BUFFER_COUNT] = {
        [0 ... BOARD_OUT_BUFFER] = just_dummy_adapter_out,
        #include "board_in_memory_command_table_mapper.h"
};