
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "edit_service_command_handler.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"
#include "../../../adapter/api/request/board_operation_request.h"
#include "../../../../utility/file/make_file_from_format/make_file_from_format.h"


/// @brief 게시글 수정. 수정 할 게시글의 uid를 입력받아 post_model을 찾은 뒤 비밀번호 대조로 이행된다.
void post_edit()
{
    unsigned int uid = get_uid_from_input_with_message("수정 할 게시글의 번호를 입력 해 주세요: ");

    check_password(find_post_model_from_array_with_uid(uid));
    
    
    
}
/// @brief 비밀번호를 입력받고, 찾은 게시물의 비밀번호와 대조하는 함수. 일치하지않으면 list로 돌아가도록 해놨음
/// @param model_to_check 찾은 게시물의 post_model
void check_password(post_model *model_to_check)
{

   


    char password_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    // // 기존 모델의 비밀번호를 가져오려했는데 생각해보니 그냥 넣으면되네
    // char password[MAX_USER_KEYBOARD_INPUT] = { 0 };
     int password_length = strlen(model_to_check->password);
    // strncpy(password, model_to_check->password, password_length+1);

    get_user_keyboard_input_with_message("비밀번호를 입력 해 주세요: ", password_input_from_user);

    // 비밀번호 전체와 입력값 전체를 비교해야하기에 strcmp를 사용
    // strcmp는 두 값이 같을 경우 0을 반환함
    if(strcmp(model_to_check->password, password_input_from_user) == 0)
    {
        edit(model_to_check);
    }
    else
    {
        printf("비밀번호가 일치하지 않습니다.\n");
        //request_board_operation();
    }


}


  void confirm_to_save(post_model *model_to_save, post_model *tmp_post_model)
{
   char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
   char *input = get_user_keyboard_input_with_message("수정 내용을 저장 하시겠습니까 ? (Y/N)", keyboard_input);
   if(!strncmp(input,"Y",1) || !strncmp(input,"y",1) )
   {
        model_to_save = tmp_post_model;
        write_file_with_array();

   }
      else if(!strncmp(input,"N",1) || !strncmp(input,"n",1) )
   {
        printf("저장하지 않습니다.");
   }    
   else
   {
        printf("잘못 입력 하셨습니다.");
        confirm_to_save(model_to_save, tmp_post_model);
   }
}


/// @brief 실제 수정이 이루어질 함수. 제목과 내용만 수정 가능하다
/// @param model_to_edit 수정 할 post_model
/// @param keyboard_input 사용자 입력을 저장 할 char 배열
void edit(post_model *model_to_edit)
{   
    post_model *tmp_post_model_to_edit = (post_model *)malloc(sizeof(post_model));

    char title_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    char content_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
    printf("기존 제목: %s", model_to_edit->title);
    get_user_keyboard_input_with_message("새로운 제목을 입력 해 주세요: ", title_input);
    set_post_model_title_from_input(tmp_post_model_to_edit, title_input);

    printf("기존 내용: %s", model_to_edit->content);
    get_user_keyboard_input_with_message("새로운 내용을 입력 해 주세요: ", content_input);
    set_post_model_content_from_input(tmp_post_model_to_edit, content_input);
 
    confirm_to_save(model_to_edit, tmp_post_model_to_edit);
    
    printf("수정 완료!\n");
    printf("게시판으로 돌아갑니다!\n");

    request_board_operation();
}
