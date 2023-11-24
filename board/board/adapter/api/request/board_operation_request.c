#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board_operation_request.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"

#include "../../out/list_out/list_out_command_handler.h"

#include "../../out/board_out_command_table.h"
#include "../../out/board_out_command.h"

//#include "../board_api_command.h"
#include "../../../application/service/board_service_command.h"


#include "../../../../utility/file/file_io/make_file.h"
#include "../../../../utility/file/file_io/read_data.h"
#include "../../../../utility/file/make_file_from_format/make_file_from_format.h"
#include "../../../../utility/file/make_format_from_file/make_format_from_file.h"


#include "../../../application/service/add/add_service_command_handler.h"
#include "../../../application/service/delete/delete_service_command_handler.h"
#include "../../../application/service/edit/edit_service_command_handler.h"
#include "../../../application/service/list/list_service_command_handler.h"
#include "../../../application/service/read/read_service_command_handler.h"
#include "../../../application/service/board_service_command_table.h"

// #include "../board_api_command_table_mapper.h"
// #include "../board_api_command_table.h"









// 사용자 입력을 요청하는 함수. 
// 현재는 프로그램 실행 시 게시글 목록과 함께 뜰만한 내용으로 작성되어있다. 
// 여유가 된다면 변경해야 할 1순위
void request_board_operation()
{
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    post_model *tmp_post_model = (post_model *)malloc(sizeof(post_model));

    board_service_command_table[BOARD_SERVICE_LIST]();

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
    if(index<1 || index > 4)
    {
        printf("잘못 된 번호입니다.\n");
      //  request_board_operation();
    }
    else
    {
        // 아직은 board_operation_request를 통해 table을 호출하지만, 곧 지워질 내용

        //입력받은 내용을 바탕으로 적절한 service_command를 호출함
        board_service_command_table[index]();


        // 매퍼가 자꾸 터져서 일단은 스위치문으로 돌림

        // switch (index)
        // {
        //     case 1:
        //         post_read();
        //         break;
        //     case 2:
        //         post_add();
        //         break;
        //     case 3:
        //         post_edit();
        //         break;
        //     case 4:
        //         post_delete();
        //         break;
            
        //     default:
        //         break;
        // }
    }
    

    

}

