// 231120 작업내용 :    thirteenth 파일에서 옮겨오기
//                    test 에서 post 으로 단어 변경하기
//                    int age 대신에 char *user 으로 자료형 타입 변경하기
//                    char *self_introduction 에서 char *text 으로 이름 변경하기

// 폐기 (231120 14:20)

#include "form_post.h"

#include <stdlib.h>
#include <string.h>

unsigned int post_form_unique_id;

int increment_post_form_unique_id(void)
{
    return post_form_unique_id++;
}

// post_form 변경 시 아래의 메모리 할당 수정할 것 (추후 비밀번호 추가 판단할 것)
post_form *init_post_form_with_id(int id, char *major, char *user, char *text)
{
    post_form *tmp_form = (post_form *)malloc(sizeof(post_form));
    int major_length = strlen(major) + 1;
    int user_length = strlen(user) + 1;
    int text_length = strlen(text) + 1;

    tmp_form->unique_id = id;

    tmp_form->major = (char *)malloc(sizeof(char) * major_length);
    strncpy(tmp_form->major, major, major_length);

    tmp_form->user = (char *)malloc(sizeof(char) * user_length);
    strncpy(tmp_form->user, user, user_length);

    tmp_form->text =
        (char *)malloc(sizeof(char) * text_length);
    strncpy(tmp_form->text, text, text_length);

    return tmp_form;
}

post_form *init_post_form(char *major, char *user, char *text)
{
    post_form *tmp_form = (post_form *)malloc(sizeof(post_form));
    int major_length = strlen(major) + 1;
    int user_length = strlen(user) + 1;
    int text_length = strlen(text) + 1;

    tmp_form->unique_id = increment_post_form_unique_id();
    tmp_form->major = (char *)malloc(sizeof(char) * major_length);
    strncpy(tmp_form->major, major, major_length);

    tmp_form->user = (char *)malloc(sizeof(char) * user_length);
    strncpy(tmp_form->user, user, user_length);

    tmp_form->text =
        (char *)malloc(sizeof(char) * text_length);
    strncpy(tmp_form->text, text, text_length);

    return tmp_form;
}

post_form **init_post_form_array(int count)
{
    post_form **tmp_format = (post_form **)malloc(sizeof(post_form *) * count);

    return tmp_format;
}