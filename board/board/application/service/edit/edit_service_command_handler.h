#ifndef __EDIT_SERVICE_COMMAND_HANDLER_H__
#define __EDIT_SERVICE_COMMAND_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "../../../domain/model/post_model.h"

void post_edit();
void check_password(post_model *model_to_check);
void edit(post_model *model_to_edit);

#ifdef __cplusplus
}
#endif

#endif