
#include <stdio.h>
#include <fcntl.h>

#include "list_service_command_handler.h"

#include "../../../adapter/out/list_out/list_out_command_handler.h"

#include "../../../adapter/out/board_out_command_table.h"
#include "../../../adapter/out/board_out_command.h"

#include "../../../../utility/file/file_io/read_data.h"
#include "../../../../utility/file/file_io/make_file.h"
#include "../../../../utility/file/make_format_from_file/make_format_from_file.h"

#include "../../../domain/model/post_model.h"


#define SLAB_CACHE          32
#define SLAB_CACHE3         128


void post_list()
{
//      char read_buffer[SLAB_CACHE];

//     int created_file_descriptor = file_open(
//         "/home/eddi/teamProj/SDC-Study-Team3/board/created_file/format_post.txt", O_CREAT | O_RDONLY, 0644);

//     // list_read_data_handler 에 함수 명시. 파일을 읽어서 read_content 에 값 대입
//    // read_content_from_file_and_print(created_file_descriptor, read_buffer);

//     file_close(created_file_descriptor);

    // created_file_descriptor = file_open(
    //     "/home/eddi/sungyonglee3/SDC-Study-Team3/sungyonglee3/created_file/format_post.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    // file_close(created_file_descriptor);

    // make_format-from_file 의 134 번째 줄을 호출
    read_file_to_format();

    board_out_command_table[BOARD_OUT_LIST]();
    
}