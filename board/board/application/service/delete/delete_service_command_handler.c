#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "delete_service_command_handler.h"
#include "../board_service_command.h"
#include "../../../domain/model/post_model.h"
#include "../../../../utility/file/make_file_from_format/make_file_from_format.h"
#include "../../../../utility/keyboard_input/keyboard_input.h"





void confirm_to_delete(unsigned int uid)
{
   char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
   char *input = get_user_keyboard_input_with_message("정말 삭제 하시겠습니까 ? (Y/N)", keyboard_input);
   post_model *model_to_delete = find_post_model_from_array_with_uid(uid);
   if(!strncmp(input,"Y",1) || !strncmp(input,"y",1) )
   {
        check_password_delete(model_to_delete);
   }
   else if(!strncmp(input,"N",1) || !strncmp(input,"n",1) )
   {
        printf("삭제하지 않습니다.");
   }    
   else
   {
        confirm_to_delete(uid);
   }
}



// 실제 구동 될 함수
void delete_post_model_from_post_array(post_model *model_to_delete)
{
    unsigned int loop;
    unsigned int current_post_count = get_post_count();

    // 임시 배열을 만들고, uid에 해당되는 post_model을 제외한 나머지post_model을 넣는다.
    unsigned int tmp_post_count = 0;
    post_model **tmp_array = (post_model **)malloc(sizeof(post_model*) * (current_post_count-1));
    
    for(loop = 0; loop < current_post_count; loop ++)
    {
        if( post_model_array[loop] == model_to_delete)
        {
         // 삭제된 post_model은 free와 ptr*=NULL을 통해서 완전 초기화시킨다.
        // free(post_model_array[loop]);
        // post_model_array[loop] = NULL;
         continue;
        }
      
            
        tmp_array[tmp_post_count] = post_model_array[loop];
       
        tmp_post_count++;
    }
    decrement_post_count();
    post_model_array = (post_model **)realloc(post_model_array, sizeof(post_model*) * (current_post_count));
    
    post_model_array = tmp_array;
    
   
    write_file_with_array();
  

    board_operation();

}

// request를 통해 호출될 함수
// mapper를 통해 table이랑 연결된다.
void post_delete()
{
    unsigned int uid = get_uid_from_input_with_message("삭제 할 게시글의 번호를 입력 해 주세요: ");
    confirm_to_delete(uid);
    
}



void check_password_delete(post_model *model_to_check)
{

   


    char password_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    // // 기존 모델의 비밀번호를 가져오려했는데 생각해보니 그냥 넣으면되네
    // char password[MAX_USER_KEYBOARD_INPUT] = { 0 };
     int password_length = strlen(model_to_check->password);
     
    // strncpy(password, model_to_check->password, password_length+1);

    get_user_keyboard_input_with_message("비밀번호를 입력 해 주세요: ", password_input_from_user);

    // 비밀번호 전체와 입력값 전체를 비교해야하기에 strcmp를 사용
    // strcmp는 두 값이 같을 경우 0을 반환함
  
    int input_length = strlen(password_input_from_user)-1;
    if(strncmp(model_to_check->password, password_input_from_user,input_length) == 0)
    {
        delete_post_model_from_post_array(model_to_check);
    }
    else
    {
        printf("비밀번호가 일치하지 않습니다.\n");
        board_operation();
    }


}

