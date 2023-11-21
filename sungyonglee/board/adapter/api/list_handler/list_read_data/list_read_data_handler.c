// 231120 작업내용 :    thirteenth 파일에서 옮겨오기
// 231121 작업내용 :    파일에서 데이터 읽으들이기 확인 완료 (09:25)


#include "list_read_data_handler.h"

#include <unistd.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE         (1)

// mapper 연결을 확인하기 위한 임시 printf 함수 (231121 13:16 sungyonglee)
void list_read_data_call(void)
{
    printf("\n\nmapper를 통한 list_read_data_handler 호출 성공\n\n");
}

void read_content_from_file_and_print(int file_descriptor, char *read_content)
{
    int read_bytes;

    while ((read_bytes = read(file_descriptor, read_content, BUDDY_PAGE_SIZE)) > 0)
    {
        write(1, read_content, read_bytes);
    }
    printf("\n");
}

void read_content_from_file(int file_descriptor, char *read_content)
{
    read(file_descriptor, read_content, 4096);
}

void reset_file_pointer(int file_descriptor)
{
    // https://elixir.bootlin.com/linux/latest/source/include/linux/fdtable.h#L49
    // https://elixir.bootlin.com/linux/latest/source/include/linux/fs.h#L1007
    lseek(file_descriptor, 0, SEEK_SET);
}