#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "post_model.h"



unsigned int post_model_unique_id;

unsigned int post_count;
post_model **post_model_array;


// uid가 1씩 자동으로 올라가도록 하는 지역함수
int increment_post_model_unique_id()
{
    return post_model_unique_id++;
}

/// @brief post_model을 생성하는 함수
/// @param uid : unique_id, 고유값. 신규 생성때에는 "NEW_POST"(0)를 넣으면 된다. 삭제해도 될지도?
/// @param title : 제목
/// @param writer : 작성자 
/// @param password : 비밀번호 
/// @param content : 내용
/// @return 선언을 함과 동시에 쓸 수 있도록 post_model을 리턴해준다.
post_model *init_post_model_object(const unsigned int uid, char *title, char* writer, char* password, char* content)
{
    post_model *tmp_post_model = (post_model *)malloc(sizeof(post_model));

    if(uid == NEW_POST)
    {
        tmp_post_model->unique_id = increment_post_model_unique_id();
        
    }
    else
    {
        tmp_post_model->unique_id = uid;
        
        
    }

    add_post_model_to_post_array(tmp_post_model);
    
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

    post_model_array[post_count] = tmp_post_model;

    post_count ++;
    return tmp_post_model;
}

/// @brief post_model의 내용물을 바꿀 수 있는 함수. 파라미터에 대한 고민이 조금 남아있다.
/// @param post_model_to_edit 변경 할 post_model
/// @param uid 이건 안바뀔거같아서 지워도 될듯?
/// @param title 새 제목
/// @param writer 작성자도 안바뀔거같아서 지워도 될듯?
/// @param password 이것도 바뀔일 없어서 지워도 될듯?
/// @param content 새 내용
void edit_post_model_object_with_data( post_model *post_model_to_edit,
    const unsigned int uid, char *title, char* writer, char* password, char* content)
{
      int title_length = strlen(title) + 1;
    int writer_length = strlen(writer) + 1;
    int password_length = strlen(password) + 1;
    int content_length = strlen(content) + 1;

    post_model_to_edit->title = (char *)realloc(post_model_to_edit->title, sizeof(char) * title_length);
    strncpy(post_model_to_edit->title, title, title_length);

    post_model_to_edit->writer = (char *)realloc(post_model_to_edit->writer, sizeof(char) * writer_length);
    strncpy(post_model_to_edit->writer, writer, writer_length);

    post_model_to_edit->password = (char *)realloc(post_model_to_edit->password, sizeof(char) * password_length);
    strncpy(post_model_to_edit->password, password, password_length);

    post_model_to_edit->content = (char *)realloc(post_model_to_edit->content, sizeof(char) * content_length);
    strncpy(post_model_to_edit->content, content, content_length);

    
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

