#ifndef __BOARD_OUT_COMMAND_H__
#define __BOARD_OUT_COMMAND_H__

#ifdef __cplusplus
extern "C" {
#endif


// out handler 추가되면 아래 주석 자리를 활성화 할 것
// board_out_command_table_mapper.h 에도 관련 문구 추가해야 합니다.
enum board_out_command
{
    BOARD_OUT_LIST,
    // BOARD_OUT_READ,
    // BOARD_OUT_DELETE,
    // BOARD_OUT_ADD,
    // BOARD_OUT_EDIT,
    BOARD_OUT_END
};

#define BOARD_OUT_BUFFER_COUNT         (BOARD_OUT_END)
#define BOARD_OUT_BUFFER               ((BOARD_OUT_END) - 1)

#ifdef __cplusplus
}
#endif

#endif