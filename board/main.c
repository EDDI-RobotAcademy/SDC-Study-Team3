#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board/application/service/delete/delete_service_command_handler.h"
#include "board/domain/model/post_model.h"
#include "board/adapter/api/request/board_operation_request.h"



#include "utility/keyboard_input/keyboard_input.h"

#include "utility/file/make_file/make_file.h"
#include "utility/file/make_file_from_format/make_file_from_format.h"




int main (void)
{
    #pragma region DELETE_TEST
    post_model *m1 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    post_model *m2 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    post_model *m3 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    post_model *m4 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    m1->title = "ASdasdasd";
    m1->content = "내내내내낸";
    m1->writer = "조정환";

    m2->title = "qweqweqwe";
    m2->content = "sjsjsjsjjs";
    m2->writer = "이재승";

     m3->title = "qsadfsadfwere";
    m3->content = "werrtyrtyrtfgh";
    m3->writer = "aqwe";

     m4->title = "gfjyititryu";
    m4->content = "546tryrty";
    m4->writer = "42536";
   
    for(unsigned int i =0; i<4; i++)
    {
        printf("%d\n",i);
        printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
            post_model_array[i]->unique_id,post_model_array[i]->title, 
            post_model_array[i]->writer, post_model_array[i]->content);
        printf("\n");
    }

    printf("설정 끝");

    //write_format_to_file(m1);

    write_file_with_array();
    printf("파일 만들기 끗");
  
    #pragma endregion
    
    // post_model* p = init_post_model_object(NEW_POST,"asd","qwe","zxc","qweasdzxc");

    // write_format_to_file(p);

    // char title_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    // char writer_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    // char password_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    // char content_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };

    // post_model *model_to_write = init_post_model_object(MAX_USER_KEYBOARD_INPUT);

    //  printf("제목을 입력하세요.\n");
    // get_user_keyboard_input(title_input_from_user);
    // set_post_model_title_from_input(model_to_write, title_input_from_user);
    
    // printf("작성자를 입력하세요.\n");
    // get_user_keyboard_input(writer_input_from_user);
    // set_post_model_writer_from_input(model_to_write, writer_input_from_user);

    // printf("비밀번호를 입력하세요.\n");
    // get_user_keyboard_input(password_input_from_user);
    // set_post_model_password_from_input(model_to_write, password_input_from_user);
    
    // printf("내용을 입력하세요.\n");
    // get_user_keyboard_input(content_input_from_user);
    // set_post_model_content_from_input(model_to_write, content_input_from_user);


    // printf("제목: %s\n작성자: %s\n비밀번호: %s\n내용: %s\n",model_to_write->title, model_to_write->writer, model_to_write->password, model_to_write->content);

    request_board_operation();
    return 0;
}
