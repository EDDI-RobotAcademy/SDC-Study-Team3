#include "add_service_command_handler.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"
#include "../../../adapter/api/request/board_operation_request.h"



#include <stdio.h>

/// @brief mapper를 통해 호출되는 함수. 게시글 추가
/// @param request 곧 사라질 파라미터
void post_add(board_operation_request *request)
{
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    wirte_post(request->first_board, keyboard_input_from_user);
}
/// @brief keyboard_input을 받아 post_model을 작성 한 뒤, post_array에 추가하는 함수
/// @param model_to_write 사라져도 무방한 함수. 함수 내부에서 malloc하여 새로 선언하면 된다.
/// @param keyboard_input 키보드 입력을 저장할 char배열. MAX_USER_KEYBOARD_INPUT = 128로 제한을 둔다.
void wirte_post(post_model *model_to_write, char keyboard_input[])
{
     printf("제목을 입력하세요.\n");
    get_user_keyboard_input(keyboard_input);
    set_post_model_title_from_input(model_to_write, keyboard_input);
    
    printf("작성자를 입력하세요.\n");
    get_user_keyboard_input(keyboard_input);
    set_post_model_writer_from_input(model_to_write, keyboard_input);

    printf("비밀번호를 입력하세요.\n");
    get_user_keyboard_input(keyboard_input);
    set_post_model_password_from_input(model_to_write, keyboard_input);
    
    printf("내용을 입력하세요.\n");
    get_user_keyboard_input(keyboard_input);
    set_post_model_content_from_input(model_to_write, keyboard_input);

    add_post_model_to_post_array(model_to_write);
}