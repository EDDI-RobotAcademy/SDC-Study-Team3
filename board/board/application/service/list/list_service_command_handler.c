
#include <stdio.h>
#include <fcntl.h>

#include "list_service_command_handler.h"

#include "../../../adapter/out/list_out/list_out_command_handler.h"

#include "../../../adapter/out/board_out_command_table.h"
#include "../../../adapter/out/board_out_command.h"

#include "../../../../utility/file/file_io/read_data.h"
#include "../../../../utility/file/file_io/make_file.h"
#include "../../../../utility/file/make_format_from_file/make_format_from_file.h"

#include "../../../domain/model/post_model.h"


#define SLAB_CACHE          32
#define SLAB_CACHE3         128


void post_list()
{
    
    read_file_to_format();

    board_out_command_table[BOARD_OUT_LIST]();
    
}