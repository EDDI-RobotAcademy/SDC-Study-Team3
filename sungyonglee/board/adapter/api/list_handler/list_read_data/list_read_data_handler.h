#ifndef __LIST_READ_DATA_HANDLER_H__
#define __LIST_READ_DATA_HANDLER_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void list_read_data_call (void);
void read_content_from_file_and_print(int, char *);
void read_content_from_file(int, char *);
void reset_file_pointer(int);

#ifdef __cplusplus
}
#endif

#endif