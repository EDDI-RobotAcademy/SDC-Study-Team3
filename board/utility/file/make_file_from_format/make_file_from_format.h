#ifndef __MAKE_FILE_FROM_FORMAT_H__
#define __MAKE_FILE_FROM_FORMAT_H__

#ifdef __cplusplus
extern "C"{
#endif

#include <stdbool.h>

#include "../../../board/domain/model/post_model.h"

bool write_format_to_file(post_model *);

#ifdef __cplusplus
}
#endif

#endif