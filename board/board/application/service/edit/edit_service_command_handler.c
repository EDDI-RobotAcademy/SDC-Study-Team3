
#include <stdio.h>

#include "edit_service_command_handler.h"
#include "../../../domain/model/post_model.h"

void post_edit(board_operation_request *request)
{
    find_post_model_from_array_with_uid(request->first_board->unique_id);
    
}

void edit(unsigned int uid)
{
    
}