
#include <stdio.h>
#include <stdlib.h>

#include "edit_service_command_handler.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"
#include "../../../adapter/api/request/board_operation_request.h"


/// @brief 게시글 수정. 수정 할 게시글의 uid를 입력받아 post_model을 찾은 뒤 제목과 내용을 수정 할 수 있다.
/// @param request 지울거니까 상관X
void post_edit(board_operation_request *request)
{
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    get_user_keyboard_input_with_message("수정 할 게시글의 uid를 입력 해 주세요: ", keyboard_input_from_user);
    
    int uid = atoi(keyboard_input_from_user);
    
    edit(find_post_model_from_array_with_uid(uid),keyboard_input_from_user);
    
}

void edit(post_model *model_to_edit, char keyboard_input[])
{
    
}