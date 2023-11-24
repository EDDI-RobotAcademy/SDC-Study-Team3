#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board/adapter/out/list_out/list_out_command_handler.h"

#include "board/adapter/out/board_out_command_table.h"
#include "board/adapter/out/board_out_command.h"


#include "board/adapter/api/operation/board_operation.h"


#include "board/adapter/api/board_api_command.h"
#include "utility/keyboard_input/keyboard_input.h"

#include "utility/file/file_io/make_file.h"
#include "utility/file/file_io/read_data.h"
#include "utility/file/make_file_from_format/make_file_from_format.h"
#include "utility/file/make_format_from_file/make_format_from_file.h"



#include "board/application/service/delete/delete_service_command_handler.h"
#include "board/application/service/add/add_service_command_handler.h"
#include "board/application/service/edit/edit_service_command_handler.h"
#include "board/application/service/list/list_service_command_handler.h"
#include "board/application/service/read/read_service_command_handler.h"
#include "board/application/service/board_service_command_table.h"
#include "board/application/service/board_service_command.h"

#include "board/adapter/api/board_api_command_table_mapper.h"
#include "board/adapter/api/board_api_command_table.h"


#include "board/domain/model/post_model.h"

void make_file()
{
      post_model *m1 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    post_model *m2 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    post_model *m3 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    post_model *m4 = init_post_model_object(MAX_USER_KEYBOARD_INPUT);
    m1->title = "ASdasdasd";
    m1->content = "내내내내낸";
    m1->writer = "조정환";
    m1->password = "123";

    m2->title = "qweqweqwe";
    m2->content = "sjsjsjsjjs";
    m2->writer = "이재승";
    m2->password = "123";

     m3->title = "qsadfsadfwere";
    m3->content = "werrtyrtyrtfgh";
    m3->writer = "aqwe";
    m3->password = "123";

     m4->title = "gfjyititryu";
    m4->content = "546tryrty";
    m4->writer = "42536";
    m4->password = "123";
   
    // for(unsigned int i =0; i<4; i++)
    // {
    //     printf("%d\n",i);
    //     printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
    //         post_model_array[i]->unique_id,post_model_array[i]->title, 
    //         post_model_array[i]->writer, post_model_array[i]->content);
    //     printf("\n");
    // }

   // printf("설정 끝");
    write_file_with_array();
   // printf("파일 만들기 끗");
}

int main (void)
{
    make_file();
    
    //board_out_command_table[0]();

    //request_board_operation();

    //board_service_command_table[BOARD_SERVICE_LIST]();

    board_api_command_table[0]();

   
    return 0;
}
