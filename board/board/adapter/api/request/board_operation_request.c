#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board_operation_request.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"


// #include "../../../application/service/board_service_command.h"
// #include "../../../application/service/board_service_command_table.h"
//#include "../../../application/service/board_service_command_table_mapper.h"




#include <stdlib.h>


// 사용자 입력을 요청하는 함수. 
// 현재는 프로그램 실행 시 게시글 목록과 함께 뜰만한 내용으로 작성되어있다. 
// 여유가 된다면 변경해야 할 1순위
void request_board_operation()
{
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    post_model *tmp_post_model = (post_model *)malloc(sizeof(post_model));

    // 사용자가 어떠한 명령어를 써야할 지 terminal에 띄우는 역할
    printf("게시판 명령어 리스트\n");
    printf("1: 게시글 읽기\n");
    printf("2: 게시글 쓰기\n");
    printf("3: 게시글 수정\n");
    printf("4: 게시글 삭제\n");
    // 유저의 입력을 받아내는 곳
    get_user_keyboard_input_with_message("명령어를 입력 해 주세요: ",keyboard_input_from_user);

    // 입력받은 내용을 int로 변환한다.
    // 추후 숫자가 아닌 입력에 대한 예외처리가 필수적으로 들어가야 하는곳
    int index = atoi(keyboard_input_from_user);

    // 현재는 명령어 인덱스가 어긋났을 경우에만 예외처리
    if(index<1 || index > 5)
    {
        printf("잘못 된 번호입니다.\n");
      //  request_board_operation();
    }
    else
    {
        
        // 아직은 board_operation_request를 통해 table을 호출하지만, 곧 지워질 내용

        //입력받은 내용을 바탕으로 적절한 service_command를 호출함
        
    }
    

    

}

