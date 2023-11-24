#include <stdlib.h>
#include <string.h>

#include "post_model.h"



unsigned int post_model_unique_id;

int increment_post_model_unique_id()
{
    return post_model_unique_id++;
}


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

    return tmp_post_model;
}

void set_post_model_object_with_data( post_model *post_model_to_set,
    const unsigned int uid, char *title, char* writer, char* password, char* content)
{
    post_model_to_set->unique_id = uid;
    post_model_to_set->title =  title; 
    post_model_to_set->writer = writer;
    post_model_to_set->password = password;
    post_model_to_set->content = content;
    
}


post_model **init_post_model_array(int array_count)
{
    post_model **tmp_model = (post_model **)malloc(sizeof(post_model *) * array_count);

    return tmp_model;
}