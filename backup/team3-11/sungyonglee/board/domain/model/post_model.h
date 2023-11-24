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
	char *content;	
	char *password;

};

post_model *init_post_model_object(
	const unsigned int uid, char *title, char* writer, 
	char* password, char* content);

void set_post_model_object_with_data( post_model *post_model_to_set,
    const unsigned int uid, char *title, char* writer, 
	char* password, char* content);

post_model **init_post_model_array(int array_count);

#ifdef __cplusplus
}
#endif

#endif