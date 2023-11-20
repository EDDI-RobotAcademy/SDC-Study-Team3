#include <stdlib.h>
#include <stdio.h>

#include "delete_service_command_handler.h"
#include "../board_service_command.h"
#include "../../../domain/model/post_model.h"


void post_delete()
{

}

void delete_post_model_from_post_array(unsigned int uid)
{
   unsigned int loop;
   unsigned int current_post_count = get_post_count();


   unsigned int tmp_post_count = 0;
   post_model **tmp_array = (post_model **)malloc(sizeof(post_model*) * (current_post_count-1));

   for(loop = 0; loop < current_post_count; loop ++)
   {
      if( get_post_model_array()[loop]->unique_id == uid)
      {
         printf("지워져라\n");
         // free(get_post_model_array()[loop]);
         // get_post_model_array()[loop] = NULL;
         continue;
      }
      else
      {
         printf("안지워졌냐\n");
      }
      
     
      tmp_array[tmp_post_count] = get_post_model_array()[loop];
       
      tmp_post_count++;
   }

   post_model_array = (post_model **)realloc(post_model_array, sizeof(post_model*) * (current_post_count-1));

   post_model_array = tmp_array;

   //free(tmp_array);

}