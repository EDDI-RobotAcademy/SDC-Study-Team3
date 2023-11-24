// 폐기 (231120 14:20)

#ifndef __FORM_POST_H__
#define __FORM_POST_H__

extern unsigned int post_form_unique_id;

typedef struct _post_form post_form;

struct _post_form
{
    int unique_id;
    char *major;
    char *user;         // int age -> char *user (231120)
    char *text;     // char *self_introduction -> char *contents (231120)
};

int increment_post_form_unique_id(void);
post_form *init_post_form_with_id(int id, char *major, char *user, char *text);
post_form *init_post_form(char *, char *, char *);
post_form **init_post_form_array(int count);

#endif