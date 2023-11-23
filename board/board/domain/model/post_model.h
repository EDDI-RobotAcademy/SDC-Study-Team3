#ifndef __POST_MODEL_H__
#define __POST_MODEL_H__


#ifdef __cplusplus
extern "C" {
#endif

#define NEW_POST        (0)


typedef struct _post_model post_model;

struct _post_model
{  
    unsigned int unique_id;
	char *title;
	char *writer;
	char *password;
	char *content;	
	
};

extern post_model **post_model_array;

void set_post_model_unique_id(int uid);
void decrement_post_count();

post_model *init_post_model_object(const int max_text_length);
post_model *init_post_model_object_with_data(const unsigned int uid, char *title, char* writer, char* password, char* content);
void edit_post_model_with_new_title_and_content( post_model *post_model_to_set, char *title, char* content);
post_model **init_post_model_array_with_count(int count);
void add_post_model_to_post_array(post_model *post_model_to_add);
post_model *find_post_model_from_array_with_uid(unsigned int uid);

unsigned int get_post_count();

void set_post_model_title_from_input(post_model *post_from_request, char *title);
void set_post_model_writer_from_input(post_model *post_from_request, char *writer);
void set_post_model_password_from_input(post_model *post_from_request, char *password);
void set_post_model_content_from_input(post_model *post_from_request, char *content);

unsigned int get_uid_from_input_with_message(char message[]);

#ifdef __cplusplus
}
#endif

#endif