#include "make_format_from_file.h"

#include "../list_read_data/list_read_data_handler.h"
#include "../../../../domain/model/post_model.h"
#include "../make_file/make_file.h" 

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUDDY_PAGE_SIZE         4096

int file_total_length (int file_descriptor)
{
    // lseek의 리턴 값은 두 번째 인자부터 3번째 인자까지 file pointer를 이동한 숫자
    return lseek(file_descriptor, 0, SEEK_END);
}

int find_enter_line_for_format_count(char *buffer, int total_length)
{
    int i;
    int count = 0;

    for (i = 0; i < total_length; i++)
    {
        if (!strncmp(&buffer[i], "\\n", 1))
        {
            count++;
        }
    }

    return count;
}

post_model **set_test_form_with_read_contents(
    post_model **post_model_array, int object_count, char *read_contents)
{
    int i;
    int field_count = 0;
    unsigned int unique_id;
    char title[32];
    char writer[32];
    char content[128];
    char password[32];
    

    int start, finish;
    bool started = false;
    int read_contents_length = strlen(read_contents);

    // 읽은 내용을 1 바이트씩 순회
    for (i = 0; i < read_contents_length; i++)
    {
        // ":" 찾기
        // 왜 찾는가 ?
        // format이 아래와 같으니까
        // id:1,major:시고르원조,age:20,introduction:낵아 시고르원조다!,
        if (!started && !strncmp(&read_contents[i], ":", 1))
        {
            start = i;
            started = true;
        }

        // "," 찾기
        if (started && !strncmp(&read_contents[i], ",", 1))
        {
            finish = i;
            started = false;
            printf("start = %d, finish = %d\n", start, finish);

            // ":" 과 "," 사이의 값이 객체에 배치해야하는 정보임
            if (field_count % 5 == 0)
            {
                char tmp_str[32] = { 0 };
                strncpy(tmp_str, &read_contents[start + 1], finish - start - 1);
                unique_id = atoi(tmp_str);
                printf("unique_id = %d\n", unique_id);
            }

            if (field_count % 5 == 1)
            {
                char tmp_str[32] = { 0 };
                // major 배열이 기존 정보를 유지하고 있을 가능성이 있으므로
                // 전체 배열을 0 으로 초기화 시키는 작업임
                memset(title, 0x00, 32);
                strncpy(title, &read_contents[start + 1], finish - start - 1);
                printf("title = %s\n", title);
            }

            if (field_count % 5 == 2)
            {
                char tmp_str[32] = { 0 };
                memset(writer, 0x00, 32);
                strncpy(writer, &read_contents[start + 1], finish - start - 1);
                printf("writer = %s\n", writer);
            }

            if (field_count % 5 == 3)
            {
                char tmp_str[32] = { 0 };
                memset(content, 0x00, 32);
                strncpy(content, &read_contents[start + 1], finish - start - 1);
                printf("content = %s\n", content);
            }

            if (field_count % 5 == 4)
            {
                char tmp_str[128] = { 0 };
                memset(password, 0x00, 128);
                strncpy(password, &read_contents[start + 1], finish - start - 1);
                printf("password: %s\n", password);

                post_model_array[field_count / 5] = 
                init_test_form_with_id(unique_id, title, writer, content, password);
            }

            // if (field_count % 4 == 0) {
            //     test_format_array[field_count++ / 4] 
            // }

            field_count++;
        }
    }

    return post_model_array;
}

post_model **read_file_to_format(void)
{
    char read_contents[BUDDY_PAGE_SIZE] = { 0 };
    int object_count;
    int total_length;

    post_model **post_model_array;

    // O_RDONLY: 읽기 전용
    int created_file_descriptor = file_open(
        "/home/eddi/proj/SDC-AI-LectureNotes/"
        "c/sungyonglee/thirteenth/created_file/format_test.txt", 
            O_RDONLY, 0644);

    //read_content_from_file_and_print(created_file_descriptor, read_contents);
    read_content_from_file(created_file_descriptor, read_contents);
    printf("read_contents: %s\n", read_contents);

    total_length = file_total_length(created_file_descriptor);
    file_close(created_file_descriptor);

    object_count = find_enter_line_for_format_count(read_contents, total_length);
    post_model_array = init_test_form_array(object_count);
    printf("object_count: %d\n", object_count);

    post_model_array = set_test_form_with_read_contents(post_model_array, object_count, read_contents);
    printf("test_format_array: 0x%x\n", post_model_array);
}