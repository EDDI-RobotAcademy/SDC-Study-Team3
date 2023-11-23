#include "add_service_command_handler.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"
#include "../../../../utility/file/make_file_from_format/make_file_from_format.h"
#include "../../../adapter/api/request/board_operation_request.h"





#include <stdio.h>
#include <stdlib.h>

// mapper를 통해 호출되는 함수. 게시글 추가
// keyboard_input을 받아 post_model을 작성 한 뒤, post_array에 추가한다.
void post_add()
{
    char title_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char writer_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char password_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char content_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };

    post_model *model_to_write = init_post_model_object(MAX_USER_KEYBOARD_INPUT);

     printf("제목을 입력하세요.\n");
    get_user_keyboard_input(title_input_from_user);
    set_post_model_title_from_input(model_to_write, title_input_from_user);
    
    printf("작성자를 입력하세요.\n");
    get_user_keyboard_input(writer_input_from_user);
    set_post_model_writer_from_input(model_to_write, writer_input_from_user);

    printf("비밀번호를 입력하세요.\n");
    get_user_keyboard_input(password_input_from_user);
    set_post_model_password_from_input(model_to_write, password_input_from_user);
    
    printf("내용을 입력하세요.\n");
    get_user_keyboard_input(content_input_from_user);
    set_post_model_content_from_input(model_to_write, content_input_from_user);

    add_post_model_to_post_array(model_to_write);

    write_format_to_file(model_to_write);

   
}
