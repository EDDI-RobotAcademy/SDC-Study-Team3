#include <stdlib.h>
#include <stdio.h>

#include "delete_service_command_handler.h"
#include "../board_service_command.h"
#include "../../../domain/model/post_model.h"

// request를 통해 호출될 함수
// mapper를 통해 table이랑 연결된다.
// request_form의 구조를 변경할지 고민중
void post_delete(board_operation_request *request_form)
{
   delete_post_model_from_post_array(request_form->first_board->unique_id);
}
// 실제 구동 될 함수
void delete_post_model_from_post_array(unsigned int uid)
{
    unsigned int loop;
    unsigned int current_post_count = get_post_count();

    // 임시 배열을 만들고, uid에 해당되는 post_model을 제외한 나머지post_model을 넣는다.
    unsigned int tmp_post_count = 0;
    post_model **tmp_array = (post_model **)malloc(sizeof(post_model*) * (current_post_count-1));
    
    for(loop = 0; loop < current_post_count; loop ++)
    {
        if( post_model_array[loop]->unique_id == uid)
        {
         // 삭제된 post_model은 free와 ptr*=NULL을 통해서 완전 초기화시킨다.
         free(post_model_array[loop]);
         post_model_array[loop] = NULL;
         continue;
        }
      
            
        tmp_array[tmp_post_count] = post_model_array[loop];
       
        tmp_post_count++;
    }

    post_model_array = (post_model **)realloc(post_model_array, sizeof(post_model*) * (current_post_count-1));

    post_model_array = tmp_array;

   

}

void delete_test()
{
   init_post_model_object(NEW_POST,"asd","qwe","zxc","qweasdzxc");
    init_post_model_object(NEW_POST,"123","456","789","987654321");
    init_post_model_object(NEW_POST,"iop","uio","hjk","yuirtyurh");
    init_post_model_object(NEW_POST,"ddfgj","tryet","cvbm","gqwertxdgfhj");

    printf("삭제 전\n\n");
    for(unsigned int i =0; i<4; i++)
    {
        printf("%d\n",i);
        printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
            post_model_array[i]->unique_id,post_model_array[i]->title, 
            post_model_array[i]->writer, post_model_array[i]->content);
        printf("\n");
    }
    delete_post_model_from_post_array(2);


    printf("삭제 후\n\n");
    for(unsigned int i =0; i<3; i++)
    {
        printf("%d\n",i);
        printf("uid: %d\ntitle: %s\nwriter: %s\ncontents: %s\n", 
            post_model_array[i]->unique_id,post_model_array[i]->title, 
            post_model_array[i]->writer, post_model_array[i]->content);
        printf("\n");
    }
    
}

