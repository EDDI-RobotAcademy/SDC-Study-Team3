#include <gtest/gtest.h>

#include <stdio.h>
#include <stdlib.h>

#include "../board/domain/model/post_model.h"
#include "../board/adapter/api/operation/board_operation.h"
#include "../utility/keyboard_input/keyboard_input.h"

#include "../board/application/service/list/list_service_command_handler.h"



TEST(에딧테스트, 수정이_되는지_확인해보자)
{
    // post_model *model_to_edit = (post_model *)malloc(sizeof(post_model));
    // char *keyboard_input = (char*)malloc(sizeof(char)*MAX_USER_KEYBOARD_INPUT);

    

    // set_post_model_title_from_input(model_to_edit,"ㄱㄷㄴㅇㄹ");
    // set_post_model_content_from_input(model_to_edit, "qweasdzxc");

    // EXPECT_NE(model_to_edit,nullptr);
    // EXPECT_EQ(model_to_edit->title, "ㄱㄷㄴㅇㄹ");
    // EXPECT_EQ(model_to_edit->content, "qweasdzxc");

    // printf("기존 제목: %s", model_to_edit->title);
    // get_user_keyboard_input_with_message("새로운 제목을 입력 해 주세요: ", keyboard_input);
    // set_post_model_title_from_input(model_to_edit, keyboard_input);

    // EXPECT_NE(model_to_edit->title,"ㄱㄷㄴㅇㄹ");

    // printf("기존 내용: %s", model_to_edit->content);
    // get_user_keyboard_input_with_message("새로운 내용을 입력 해 주세요: ", keyboard_input);
    // set_post_model_content_from_input(model_to_edit, keyboard_input);

    // EXPECT_NE(model_to_edit->title,"qweasdzxc");


    //request_board_operation();

    //post_list();
}

