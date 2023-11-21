#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "board/application/service/delete/delete_service_command_handler.h"
#include "board/domain/model/post_model.h"
#include "board/adapter/api/request/board_operation_request.h"



#include "utility/keyboard_input/keyboard_input.h"

#include "utility/file/make_file/make_file.h"
#include "utility/file/make_file_from_format/make_file_from_format.h"




int main (void)
{
    #pragma region DELETE_TEST
    //init_post_model_object(NEW_POST,"asd","qwe","zxc","qweasdzxc");
    // init_post_model_object(NEW_POST,"123","456","789","987654321");
    // init_post_model_object(NEW_POST,"iop","uio","hjk","yuirtyurh");
    // init_post_model_object(NEW_POST,"ddfgj","tryet","cvbm","gqwertxdgfhj");

    // printf("삭제 전\n\n");
    // for(unsigned int i =0; i<4; i++)
    // {
    //     printf("%d\n",i);
    //     printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
    //         post_model_array[i]->unique_id,post_model_array[i]->title, 
    //         post_model_array[i]->writer, post_model_array[i]->content);
    //     printf("\n");
    // }

    // board_operation_request *r = (board_operation_request *)malloc(sizeof(board_operation_request));
    // post_model *p = (post_model *)malloc(sizeof(post_model));
    // p->unique_id = 2;
    // r->first_board = p;

    // post_delete(r);



    // printf("삭제후후후후후\n\n");
    // for(unsigned int i =0; i<3; i++)
    // {
    //     printf("%d\n",i);
    //     printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
    //         post_model_array[i]->unique_id,post_model_array[i]->title, 
    //         post_model_array[i]->writer, post_model_array[i]->content);
    //     printf("\n");
    // }
    #pragma endregion
    
    post_model* p = init_post_model_object(NEW_POST,"asd","qwe","zxc","qweasdzxc");

    write_format_to_file(p);

    
    return 0;
}
