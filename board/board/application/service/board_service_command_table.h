#ifndef __BOARD_SERVICE_COMMAND_TABLE_H__
#define __BOARD_SERVICE_COMMAND_TABLE_H__

#include "board_service_command.h"
#include "../../adapter/api/request/board_operation_request.h"

//#include "../../adapter/in/api/request/vector_operation_request.h"

// void (* A) (void) <<<--- 함수 포인터
// 함수 포인터는 리턴 타입과 입력 파라메터를 모두 명시해줘야 함
// 리턴타입 (* 포인터 변수) (파라메터) 형태로 작성해야함
// 여기 typedef는 void (*)(void) 형태를
// vector_service_call_ptr_t로 대체해서 적겠음을 의미함
typedef void (* board_service_call_ptr_t) (board_operation_request *);

// 결국 아래는 함수 포인터 배열을 의미함
extern const board_service_call_ptr_t 
    board_service_command_table[BOARD_SERVICE_EXECUTE_BUFFER_COUNT];

#endif
