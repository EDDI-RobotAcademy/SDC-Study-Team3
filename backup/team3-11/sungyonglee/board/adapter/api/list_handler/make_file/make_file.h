#ifndef __HOW_TO_MAKE_FILE_H__
#define __HOW_TO_MAKE_FILE_H__

#ifdef __cplusplus
extern "C" {
#endif

#define ERROR               (-1)

int file_open(char *filename, int option, unsigned int permission);
void file_close(int file_descriptor);

#ifdef __cplusplus
}
#endif

#endif