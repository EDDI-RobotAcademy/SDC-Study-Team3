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


post_model *init_post_model_object(
	const unsigned int uid, char *title, char* writer, 
	char* password, char* content);

void edit_post_model_object_with_data( post_model *post_model_to_set,
    const unsigned int uid, char *title, char* writer, 
	char* password, char* content);

void add_post_model_to_post_array(post_model *post_model_to_add);

post_model *find_post_model_from_array_with_uid(unsigned int uid);

unsigned int get_post_count();

#ifdef __cplusplus
}
#endif

#endif