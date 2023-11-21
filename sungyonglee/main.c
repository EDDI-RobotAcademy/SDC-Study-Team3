#include <stdio.h>
#include <fcntl.h>

#include "board/adapter/api/list_handler/list_read_data/list_read_data_handler.h"
#include "board/adapter/api/list_handler/make_file/make_file.h"

#include "board/adapter/api/list_handler/list_read_data/list_read_data_handler.h"
#include "board/adapter/api/board_api_command_table.h"
#include "board/adapter/api/board_api_command.h" 


#include "board/domain/model/post_model.h"

/*
#include "file_io/how_to_make_file.h"
#include "file_io/how_to_write_content.h"
#include "file_io/how_to_read_content.h"

#include "format_test/form_test.h"
#include "format_test/make_file_from_format.h"
#include "format_test/make_format_from_file.h"
*/

// Linux OS가 메모리를 관리 할 때 Slab 단위 및 Buddy 단위로 관리함
// Slab은 32 * 2^n 형태로 구성됨
// 그러므로 32, 64, 128, 256, ... 형태로 각을 맞추는게 좋음
// Buddy는 물리 메모리의 최소 단위인 4K (4096 바이트) = 2^12 을 기준으로 동작
#define SLAB_CACHE          32
#define SLAB_CACHE3         128

int main (void)
{
    /*
    short test_number = 32768;
    char contents[SLAB_CACHE] = "마 좀 치나 ?";
    char read_buffer[SLAB_CACHE];
*/
    post_model *format;
    char major[SLAB_CACHE] = "여긴어디나는누구";
    int age = 31;
    char self_introduction[SLAB_CACHE3] = "교수님잘못했어요";


    post_model *format2;
    char major2[SLAB_CACHE] = "시고르원조";
    char self_introduction2[SLAB_CACHE3] = "낵아 시고르원조다!";


    char read_buffer[SLAB_CACHE];

    // 0644는 8진수임
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team3/sungyonglee/created_file/format_post.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    printf("생성된 파일 디스크립터: %d\n", created_file_descriptor);
    // printf("short test = %d\n", test_number);   // 

/* 쓰기 기능 일단 주석처리 (231120 14:37)
    write_content_in_file(created_file_descriptor, contents);
    reset_file_pointer(created_file_descriptor);
*/  

    read_content_from_file_and_print(created_file_descriptor, read_buffer);

    file_close(created_file_descriptor);

    created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-Study-Team3/sungyonglee/created_file/format_post.txt", O_CREAT | O_RDWR | O_APPEND, 0644);

    file_close(created_file_descriptor);


    // 파일 내용에 쓰여지는 것에만 관여
    // format = init_post_model_object(0, major, age, 0000, self_introduction);
    // write_format_to_file(format);

    // format2 = init_post_model_object(1, major2, 20, 0001, self_introduction2);
    // write_format_to_file(format2);

    // board_api_command_table 을 강제 구동하기 위하여 호출함 (sungyonglee 231121 10:25)
    board_api_command_table[0]();



   // read_file_to_format();


    return 0;
}
