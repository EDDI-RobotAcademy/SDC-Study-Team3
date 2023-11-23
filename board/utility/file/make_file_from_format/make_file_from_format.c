#include "make_file_from_format.h"

#include "../make_file/make_file.h"
#include "../make_file/write_content.h"

#include <stdio.h>
#include <fcntl.h>
#include <string.h>

#define BUDDY_PAGE_SIZE             4096

#define START_INDEX                 0


/// @brief post_model의 내용물을 한줄로 바꿔주는 함수
/// @param contents 한줄로 바뀐 내용물을 저장할 char배열
/// @param format 한줄로 바꿀 post_model
void adjust_write_contents_from_format(char *contents, post_model *format)
{
    int unique_id_size;
    int age_size;
    int major_length, self_introduction_length;

    // contents에 "id:%d,major:%s,age:%d,introduction:%s,\n" 의 형식으로 문자열을 생성함
    sprintf(contents, "id:%d,title:%s,writer:%s,password:%s,content:%s,\n", 
        format->unique_id, format->title, format->writer, format->password, format->content);
    printf("contents: %s\n", contents);
}

/// @brief post_model을 파일의 다음 항목으로써 저장하는 함수
/// @param format 저장 할 post_model
bool write_format_to_file(post_model *format)
{
    char write_contents[BUDDY_PAGE_SIZE] = { 0 };

    // O_CREAT: 없으면 만듬
    // O_RDWR: Read/Write 모드
    // O_APPEND: 파일 내용의 후속 내용 덧붙이기 가능
    // O_TRUNC: 밀어버리기
    /* 0644
    $ ls -l
    total 64
    -rw-rw-r-- 1 eddi eddi 12122 11월 16 09:13 CMakeCache.txt
    drwxrwxr-x 5 eddi eddi  4096 11월 16 15:07 CMakeFiles
    -rw-rw-r-- 1 eddi eddi  1693 11월 16 09:13 cmake_install.cmake
    -rw-rw-r-- 1 eddi eddi  2577 11월 16 12:44 compile_commands.json
    -rw-rw-r-- 1 eddi eddi 12103 11월 16 12:44 Makefile
    -rwxrwxr-x 1 eddi eddi 26368 11월 16 15:07 test_app
    -rw-r--r-- 1 eddi eddi     0 11월 16 09:24 이거만들래.txt
    */
    int created_file_descriptor = file_open(
        "/home/eddi/teamProj/SDC-Study-Team3/board/created_file/format_test.txt", 
            O_CREAT | O_RDWR | O_APPEND, 0644);

    adjust_write_contents_from_format(write_contents, format);

    write_content_in_file(created_file_descriptor, write_contents);

    file_close(created_file_descriptor);

    return true;
}

// post_model_array에서 post_model을 하나씩 꺼낸 뒤, file에 쓰는 함수
// 기존 파일 내용을 전부 지운 뒤 하나부터 다시 쓴다
// edit, delete 이후 호출되어야함
bool write_file_with_array()
{
    int post_count = get_post_count();
    int loop;
    int created_file_descriptor = file_open(
        "/home/eddi/teamProj/SDC-Study-Team3/board/created_file/format_test.txt", 
            O_CREAT | O_RDWR | O_TRUNC , 0644);

    for(loop = 0; loop < post_count; loop++)
    {
        char write_contents[BUDDY_PAGE_SIZE] = { 0 };
        adjust_write_contents_from_format(write_contents, post_model_array[loop]);
        write_content_in_file(created_file_descriptor, write_contents);
        printf("냠냠");
    }

    file_close(created_file_descriptor);



    return  true;
}