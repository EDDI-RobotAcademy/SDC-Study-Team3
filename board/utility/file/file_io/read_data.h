#ifndef __READ_DATA_H__
#define __READ_DATA_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

void read_content_from_file_and_print(int, char *);
void read_content_from_file(int, char *);
void reset_file_pointer(int);

#ifdef __cplusplus
}
#endif

#endif