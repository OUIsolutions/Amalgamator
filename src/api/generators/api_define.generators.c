
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.api_declare.h"
//silver_chain_scope_end



CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation(
    const char*filename,
    long max_content_size,
    int max_recursion,
    short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
    void *args
){
    CTextStack *final = newCTextStack_string_empty();
    DtwStringArray *already_included = newDtwStringArray();
    char *include_error_name = NULL;
    char *filename_error = NULL;
    int error  = private_CAmalgamator_generate_amalgamation(
        filename,
        NULL, //include code
        final,
        already_included,
        &include_error_name,
        &filename_error,
        max_content_size,
        0, //recursion size
        max_recursion,
        generator_handler,
        args
    );
    DtwStringArray_free(already_included);
    if(error){
        long size = final->size;
        CTextStack_free(final);

        if(error == CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED && include_error_name){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED,
                include_error_name,
                filename_error,
                "include:'%s' at file '%s' not found",
                include_error_name,
                filename_error
            );
        }

        if(error == CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED,
                NULL,
                filename_error,
                "file '%s' not found",
                filename_error
            );
        }
        if(error == CAMALGAMATOR_MAX_RECURSION_CALL && filename_error){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_RECURSION_CALL,
                include_error_name,
                filename_error,
                "mex recursion call of: %d  reached at file '%s'\n"
                "if these its not a recursion problem on your files, increase the limit by"
                "typing --maxreq <your_limit>",
                max_recursion,
                filename_error
            );
        }

        if(error == CAMALGAMATOR_MAX_RECURSION_CALL){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_RECURSION_CALL,
                include_error_name,
                filename_error,
                "mex recursion call of: %d  reached \n"
                "if these its not a problem on your files, increase the limit by"
                "typing --maxreq <your_limit>",
                max_recursion
            );
        }

        if(error == CAMALGAMATOR_MAX_CONTENT_SIZE && filename_error){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_CONTENT_SIZE,
                include_error_name,
                filename_error,
                "reached the max content size of %ld bytes in %ld bytes in file '%s'",
                max_content_size,
                size - max_content_size,
                filename_error
            );
        }

        if(error == CAMALGAMATOR_MAX_CONTENT_SIZE){
            return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_MAX_CONTENT_SIZE,
                include_error_name,
                filename_error,
                "reached the max content size of %ld bytes in %ld bytes",
                max_content_size,
                size - max_content_size
            );
        }

        return Private_new_CAmalgamatorErrorOrString_as_error(
                CAMALGAMATOR_UNEXPECTED_ERROR,
                include_error_name,
                filename_error,
                "unexpected behavior"
        );

    }
    char *content =  CTextStack_self_transform_in_string_and_self_clear(final);
    return Private_new_CAmalgamatorErrorOrString_as_ok(content);
}

CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation_simple(const char*filename,long max_content_size,int max_recursion){
    return CAmalgamator_generate_amalgamation(filename,max_content_size,max_recursion,NULL,NULL);
}
