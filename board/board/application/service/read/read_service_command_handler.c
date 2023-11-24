
#include "read_service_command_handler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../board_service_command.h"

#include "../../../../utility/keyboard_input/keyboard_input.h"
#include "../../../adapter/api/operation/board_operation.h"
#include "../../../../utility/file/make_file_from_format/make_file_from_format.h"

#include "../board_service_command_table.h"


// 뒤로가기 버튼을 입력받는 함수. 
// 만약 다른걸 누를 시 한번 더 호출되며 입력을 대기한다.
// Y나 y를 입력하기 전까지 대기하는 무한의 굴레
void check_return_to_list_with_keyboard_input_from_read()
{
   char keyboard_input[MAX_USER_KEYBOARD_INPUT] = { 0 };
   char *input = get_user_keyboard_input_with_message("뒤로 가기를 원하십니까? (Y/N)", keyboard_input);
   

   if(!strncmp(input,"Y",1) || !strncmp(input,"y",1) )
   {
      // board_service_command_table[BOARD_SERVICE_LIST]();
      request_board_operation();
   }
   else if(!strncmp(input,"N",1) || !strncmp(input,"n",1) ) 
   {
      check_return_to_list_with_keyboard_input_from_read();
   }
   else
   {
      printf("잘못 입력 하셨습니다.");
      check_return_to_list_with_keyboard_input_from_read();
   }
}

void print_post_model(post_model *model_to_read)
{
   printf("번호: %d\n", model_to_read->unique_id);
   printf("제목: %s\n", model_to_read->title);
   printf("작성자: %s\n", model_to_read->writer);
   printf("내용: %s\n", model_to_read->content);

   
   check_return_to_list_with_keyboard_input_from_read();
   
}

// mapper에서 호출되는 함수.
// 실제 구동되는 내부 함수
void post_read()
{
   unsigned int uid = get_uid_from_input_with_message("읽을 게시글의 번호를 입력 해 주세요: ");

   print_post_model(find_post_model_from_array_with_uid(uid));


}


