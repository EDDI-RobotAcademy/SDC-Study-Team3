// 231120 작업내용 :    thirteenth 파일에서 옮겨오기
// 231121 작업내용 :    파일에서 데이터 읽으들이기 확인 완료 (09:25)


#include "read_data.h"

#include <unistd.h>
#include <stdio.h>

#define BUDDY_PAGE_SIZE         (1)

void read_content_from_file_and_print(int file_descriptor, char *read_content)
{
    int read_bytes;

    // 파일을 읽어서 read_content 에 대입
    while ((read_bytes = read(file_descriptor, read_content, BUDDY_PAGE_SIZE)) > 0)
    {
        write(1, read_content, read_bytes);
    }
    printf("\n\n");
}

    // 일단 사용되지 않는 함수
void read_content_from_file(int file_descriptor, char *read_content)
{
    read(file_descriptor, read_content, 4096);
}

    // 파일을 읽고 난 후의 지점을 리셋하여, 추후 read_content 에서 항목별 내용을 뽑아내기 위한 준비를 함
void reset_file_pointer(int file_descriptor)
{
    lseek(file_descriptor, 0, SEEK_SET);
}