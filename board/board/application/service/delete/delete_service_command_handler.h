#ifndef __DELETE_SERVICE_COMMAND_HANDLER_H__
#define __DELETE_SERVICE_COMMAND_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../domain/model/post_model.h"

#include "../../../adapter/api/operation/board_operation.h"

void post_delete();


void confirm_to_delete(unsigned int uid);
void check_password_delete(post_model *model_to_check);

void delete_post_model_from_post_array(post_model *model_to_delete);

#ifdef __cplusplus
}
#endif

#endif
