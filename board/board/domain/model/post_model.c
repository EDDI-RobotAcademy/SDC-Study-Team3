#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "post_model.h"
#include "../../../utility/keyboard_input/keyboard_input.h"



unsigned int post_model_unique_id;

unsigned int post_count;
post_model **post_model_array;


void set_post_model_unique_id(int uid)
{
    post_model_unique_id = uid+1;
}

// uid가 1씩 자동으로 올라가도록 하는 지역함수
int increment_post_model_unique_id()
{
    return post_model_unique_id++;
}

/// @brief post_model을 생성하는 함수
/// @param max_text_length 사용자 입력 최대값. 메모리 공간을 미리 확보하기 위해 선언
/// @return 선언을 함과 동시에 쓸 수 있도록 post_model을 리턴해준다.
post_model *init_post_model_object(const int max_text_length)
{
    post_model *tmp_post_model = (post_model *)malloc(sizeof(post_model));
    tmp_post_model->unique_id = increment_post_model_unique_id();
   

    
    
    tmp_post_model->title = (char *)malloc(sizeof(char) * max_text_length);

    tmp_post_model->writer = (char *)malloc(sizeof(char) * max_text_length);

    tmp_post_model->password = (char *)malloc(sizeof(char) * max_text_length);

    tmp_post_model->content = (char *)malloc(sizeof(char) * max_text_length);

    add_post_model_to_post_array(tmp_post_model);

    return tmp_post_model;
}

post_model *init_post_model_object_with_data(
    const unsigned int uid, char *title, char* writer, char* password, char* content)
{
    post_model *tmp_post_model = (post_model *)malloc(sizeof(post_model));

    
    tmp_post_model->unique_id = uid;
    
    int title_length = strlen(title) + 1;
    int writer_length = strlen(writer) + 1;
    int password_length = strlen(password) + 1;
    int content_length = strlen(content) + 1;

    tmp_post_model->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(tmp_post_model->title, title, title_length);

    tmp_post_model->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(tmp_post_model->writer, writer, writer_length);

    tmp_post_model->password = (char *)malloc(sizeof(char) * password_length);
    strncpy(tmp_post_model->password, password, password_length);

    tmp_post_model->content = (char *)malloc(sizeof(char) * content_length);
    strncpy(tmp_post_model->content, content, content_length);

    printf("post_count: %d",post_count);
    post_model_array[post_count] = tmp_post_model;

    post_count++;
    return tmp_post_model;
}

/// @brief post_model의 내용물을 바꿀 수 있는 함수. 파라미터에 대한 고민이 조금 남아있다.
/// @param post_model_to_edit 변경 할 post_model
/// @param title 새 제목
/// @param content 새 내용
void edit_post_model_with_new_title_and_content( post_model *post_model_to_edit, char *title, char* content)
{
    int title_length = strlen(title) + 1;
    int content_length = strlen(content) + 1;

    post_model_to_edit->title = (char *)realloc(post_model_to_edit->title, sizeof(char) * title_length);
    strncpy(post_model_to_edit->title, title, title_length);

    post_model_to_edit->content = (char *)realloc(post_model_to_edit->content, sizeof(char) * content_length);
    strncpy(post_model_to_edit->content, content, content_length);

    
}


post_model **init_post_model_array_with_count(int count)
{
    post_model_array = (post_model **)malloc(sizeof(post_model *) * count);
    return post_model_array;
}

/// @brief 생성된 post_model을 post_model_array에 추가하는 함수. 만약 첫 게시글이라면 malloc을 통해 메모리를 확보하고, 기존의 배열에 추가하는 경우 realloc을 통해 배열을 확장한다.
/// @param post_model_to_add 추가 할 post_model
void add_post_model_to_post_array(post_model *post_model_to_add)
{
    if(post_count == 0)
    {
        post_model_array = (post_model **)malloc(sizeof(post_model*));
        
    }
    else
    {
        post_model_array = (post_model **)realloc(post_model_array, sizeof(post_model*) * (post_count+1));
    }

    post_model_array[post_count] = post_model_to_add;
    post_count++;
}


/// @brief 파라미터를 통해 전달받은 uid를 통해 post_model을 색인하는 함수
/// @param uid 찾을 post_model의 unique_id. 게시글 번호
/// @return 만약 적절한 값을 입력했다면 찾아주고, 아니면 NULL을 리턴
post_model *find_post_model_from_array_with_uid(unsigned int uid)
{
    for(int i = 0; i < post_count; i++)
    {
        if(post_model_array[i]->unique_id == uid)
        {
            return post_model_array[i];
        }
    }
    return NULL;
}


/// @brief 게시글 갯수를 리턴하는 함수...인데 쓸일이 있을진 미지수
unsigned int get_post_count()
{
    return post_count;
}

/// @brief 입력받은 내용을 post_model->title에 저장하는 함수.
/// @param post_from_request 저장 할 post_model
/// @param title 저장 될 내용. user가 직접 입력한 값이다.
void set_post_model_title_from_input(post_model *post_from_request, char *title)
{
    int title_length = strlen(title) - 1;
    //post_from_request->title = (char *)malloc(sizeof(char) * title_length);
    strncpy(post_from_request->title, title, title_length);
}

/// @brief 입력받은 내용을 post_model->writer에 저장하는 함수.
/// @param post_from_request 저장 할 post_model
/// @param writer 저장 될 내용. user가 직접 입력한 값이다.
void set_post_model_writer_from_input(post_model *post_from_request, char *writer)
{
    int writer_length = strlen(writer) - 1;
    //post_from_request->writer = (char *)malloc(sizeof(char) * writer_length);
    strncpy(post_from_request->writer, writer, writer_length);
}

/// @brief 입력받은 내용을 post_model->password에 저장하는 함수.
/// @param post_from_request 저장 할 post_model
/// @param password 저장 될 내용. user가 직접 입력한 값이다.
void set_post_model_password_from_input(post_model *post_from_request, char *password)
{
    int password_length = strlen(password) - 1;
    //post_from_request->password = (char *)malloc(sizeof(char) * password_length);
    strncpy(post_from_request->password, password, password_length);
}

/// @brief 입력받은 내용을 post_model->content에 저장하는 함수.
/// @param post_from_request 저장 할 post_model
/// @param content 저장 될 내용. user가 직접 입력한 값이다.
void set_post_model_content_from_input(post_model *post_from_request, char *content)
{
    int content_length = strlen(content) - 1;
    //post_from_request->content = (char *)malloc(sizeof(char) * content_length);
    strncpy(post_from_request->content, content, content_length);
}


/// @brief 사용자로부터 입력받은 숫자를 unique_id로써 리턴하는 함수. 예외처리가 필요하다
/// @param message 화면에 띄울 메세지 ex) 번호를 입력 해 주세요
/// @return 입력받은 숫자
unsigned int get_uid_from_input_with_message(char message[])
{
    char keyboard_input_from_user[MAX_USER_KEYBOARD_INPUT] = { 0 };
    get_user_keyboard_input_with_message(message, keyboard_input_from_user);
    
    unsigned int uid = atoi(keyboard_input_from_user);

    return uid;
}