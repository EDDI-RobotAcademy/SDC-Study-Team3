#include "list_out_command_handler.h"

#include "../../../../utility/file/make_format_from_file/make_format_from_file.h"
#include "../../../domain/model/post_model.h"

#include <stdio.h>
#include <string.h>

#define UNIQUE_LENGTH       10
#define TITLE_LENGTH        30
#define WRITER_LENGTH       15


void list_out(void)
{
   // printf("mapper 에 의한 list_out 호출 성공\n");
   
    int unique_id_loop = 0;
    
    printf("\n\n[ Team3 Board ]\n\n");
    printf("no. %c%c%cwriter  %c%c%c%ctitle\n", 32, 32, 32, 32, 32, 32, 32);

    char frame_line[40] = {" "};
    memset(frame_line, 61, 38);
    printf("%s\n", frame_line);

 
    for (unique_id_loop = 0; unique_id_loop < get_post_count(); unique_id_loop++)
    {
        // 자료의 문자 길이 산정
        int tmp_title_id_length = strlen(post_model_array[unique_id_loop]->title);
        int tmp_writer_id_length = strlen(post_model_array[unique_id_loop]->writer);

        // 자료 이후의 공백 길이 산정
        int empty_title_length = TITLE_LENGTH - tmp_title_id_length;
        int empty_writer_length = WRITER_LENGTH - tmp_writer_id_length;
        
        printf("%d",post_model_array[unique_id_loop]->unique_id);
        printf("%c%c%c%c%c%c", 32, 32, 32, 32, 32, 32);

        printf("%s",post_model_array[unique_id_loop]->writer);
        int empty_writer_loop;
        for (empty_writer_loop = 0; empty_writer_loop < empty_writer_length; empty_writer_loop++)
        {
        printf(" ");
        }

        printf("%s\n",post_model_array[unique_id_loop]->title);
        int empty_title_loop;
        for (empty_title_loop = 0; empty_title_loop < empty_title_length; empty_title_loop++)
        {
        printf(" ");
        }

        printf("\n");                                               

        // printf("\n리셋\n");
        // char tmp_text[20] = {" "};
        // memset(tmp_text, 32, 15);
        // strncpy(tmp_text, post_model_array[1]->writer, sizeof(tmp_text));
        // int tmp_length = strlen(tmp_text);
        // printf("%s, %d\n", tmp_text, tmp_length);
    // printf("\n%d, %s, %s\n", post_model_array[unique_id_loop]->unique_id, post_model_array[unique_id_loop]->title, post_model_array[unique_id_loop]->writer);
    }
}