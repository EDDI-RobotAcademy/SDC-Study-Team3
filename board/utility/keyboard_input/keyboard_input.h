#ifndef __USER_KEYBOARD_INPUT_H__
#define __USER_KEYBOARD_INPUT_H__

#ifdef __cplusplus
extern "C"{
#endif

#define MAX_USER_KEYBOARD_INPUT         128

char* get_user_keyboard_input(char *keyboard_input);
char* get_user_keyboard_input_with_message(char *output_message, char *keyboard_input);

#ifdef __cplusplus
}
#endif

#endif