#include <stdio.h>
#include <fcntl.h>
#include "list_api.h"

#include "../list_read_data/list_read_data_handler.h"
#include "../make_file/make_file.h"
#include "../make_format_from_file/make_format_from_file.h"

#include "../../../../domain/model/post_model.h"

#define SLAB_CACHE          32
#define SLAB_CACHE3         128


// board_api_command_table_mapper 로 부터 호출 받는 함수 (list_handler 구동하는 첫 함수)
// list 폴더, list_read_data 폴더, make_file 폴더, make_format_from_file 폴더가 구동됩니다.
// list 폴더 : 파일을 여는 작업, 나머지 3개 폴더를 구동하는 작업(read_file_to_format())
void list_api(void)
{
 
    char read_buffer[SLAB_CACHE];

    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team3/sungyonglee4/created_file/format_post.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    // list_read_data_handler 에 함수 명시. 파일을 읽어서 read_content 에 값 대입
    read_content_from_file_and_print(created_file_descriptor, read_buffer);

    file_close(created_file_descriptor);

    // created_file_descriptor = file_open(
    //     "/home/eddi/proj/SDC-Study-Team3/sungyonglee4/created_file/format_post.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    // file_close(created_file_descriptor);

    // make_format-from_file 의 134 번째 줄을 호출
    read_file_to_format();

}