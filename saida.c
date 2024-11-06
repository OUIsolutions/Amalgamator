
//#define  CAMALGAMATOR_DEBUG
//silver_chain_scope_start
//mannaged by silver chain
#ifndef camalgamator_api_dependencies
#define camalgamator_api_dependencies

#ifndef  CTEXTENGINE_H
#ifndef  CTEXTENGINE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>



#ifndef PRIVATE_CTEXT_CONST
#define PRIVATE_CTEXT_CONST


#define CTEXT_BY_OWNESHIP 1
#define CTEXT_BY_COPY 2
#define CTEXT_BY_REFERENCE 3




#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "

#define CTEXT_LONG 1
#define CTEXT_DOUBLE 2
#define CTEXT_BOOL 3
#define CTEXT_STRING 4


//
// Created by jurandi on 18-04-2023.
//
#define CTEXT_HTML "html"
#define CTEXT_BODY "body"
#define CTEXT_DIV "div"
#define CTEXT_H1 "h1"
#define CTEXT_H2 "h2"
#define CTEXT_H3 "h3"
#define CTEXT_H4 "h4"
#define CTEXT_H5 "h5"
#define CTEXT_H6 "h6"
#define CTEXT_P "p"
#define CTEXT_SPAN "span"
#define CTEXT_A "a"
#define CTEXT_IMG "img"
#define CTEXT_INPUT "input"
#define CTEXT_BUTTON "button"
#define CTEXT_TABLE "table"
#define CTEXT_TR "tr"
#define CTEXT_TD "td"
#define TH "th"
#define CTEXT_THEAD "thead"
#define CTEXT_TBODY "tbody"
#define CTEXT_TFOOT "tfoot"
#define CTEXT_UL "ul"
#define CTEXT_LI "li"
#define CTEXT_OL "ol"
#define CTEXT_FORM "form"
#define CTEXT_LABEL "label"
#define CTEXT_SELECT "select"
#define CTEXT_OPTION "option"
#define CTEXT_TEXTAREA "textarea"
#define CTEXT_SCRIPT "script"
#define CTEXT_STYLE "style"
#define CTEXT_META "meta"
#define CTEXT_LINK "link"
#define CTEXT_HEAD "head"
#define CTEXT_BASE "base"
#define CTEXT_BR "br"
#define CTEXT_HR "hr"
#define CTEXT_TITLE "title"
#define CTEXT_IFRAME "iframe"
#define CTEXT_NAV "nav"
#define CTEXT_HEADER "header"
#define CTEXT_FOOTER "footer"
#define CTEXT_SECTION "section"
#define CTEXT_ARTICLE "article"
#define CTEXT_ASIDE "aside"
#define CTEXT_DETAILS "details"
#define CTEXT_SUMMARY "summary"
#define CTEXT_DIALOG "dialog"
#define MENU "menu"
#define MENUITEM "menuitem"
#define CTEXT_MAIN "main"
#define CTEXT_CANVAS "canvas"
#define CTEXT_AUDIO "audio"
#define CTEXT_VIDEO "video"
#define CTEXT_SOURCE "source"
#define CTEXT_TRACK "track"
#define CTEXT_EMBED "embed"
#define CTEXT_PARAM "param"
    





#endif



#ifndef PRIVATE_CTEXT_MACROS
#define PRIVATE_CTEXT_MACROS

#define CTextScope(s,t)\
ctext_open(s, t);\
for(int snaunduwwqwetjsdvda = 0; snaunduwwqwetjsdvda < 1; ctext_close(s, t), ++snaunduwwqwetjsdvda)

#define CTextScope_format(s,t, ...)\
CTextStack_open_format(s,t,__VA_ARGS__);\
for(int snaunduwwqwetjsdvda = 0; snaunduwwqwetjsdvda < 1; ctext_close(s, t), ++snaunduwwqwetjsdvda)


#endif






#ifndef PRIVATE_CTEXT_STACK_TYPE_H
#define PRIVATE_CTEXT_STACK_TYPE_H
typedef struct CTextStack{

    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t size;

    char *line_breaker;
    char *separator;
    int ident_level;

}CTextStack;
#endif



#ifndef  PRIVATE_CTEXT_ARRAY_TYPE_H
#define PRIVATE_CTEXT_ARRAY_TYPE_H
typedef struct CTextArray{

    CTextStack **stacks;
    long size;


}CTextArray;

#endif






#ifndef PRIVATE_CTEXT_ARRAY_NAMESPACE_MODULE
#define PRIVATE_CTEXT_ARRAY_NAMESPACE_MODULE
typedef struct CTextArrayModule{
    CTextArray *(*newArray)();
    void (*append)(CTextArray *self,CTextStack *element);
    void (*append_string)(CTextArray *self,const char *element);
    CTextStack * (*join)(CTextArray *self,const char *separator);

    CTextArray * (*map)(CTextArray *self, CTextStack *(caller)(CTextStack* element));
    CTextArray * (*filter)(CTextArray *self, bool (caller)(CTextStack* element));
    void  (*foreach)(CTextArray *self, void (*caller)(CTextStack* element));
    bool (*includes)(CTextArray *self,const char *element);
    void (*represent)(CTextArray *self);
    void (*free)(CTextArray *self);

}CTextArrayModule;
#endif








#ifndef  PRIVATE_CTEXT_STACK_NAMESPACE_MODULE
#define PRIVATE_CTEXT_STACK_NAMESPACE_MODULE

typedef struct CTextStackModule{

    //admnistrative methods
    CTextStack  *(*newStack)(const char *line_breaker, const char *separator);
    CTextStack *(*newStack_string)(const char *starter);
    CTextStack *(*newStack_string_format)(const char *format, ...);

    CTextStack *(*newStack_string_getting_ownership)(const char *starter);
    CTextStack *(*newStack_string_empty)();

    void (*free)(struct CTextStack *self);
    struct CTextStack *(*clone)(struct CTextStack *self);
    void (*represent)(struct CTextStack *self);
    char *(*self_transform_in_string_and_self_clear)(struct CTextStack *self);
    void (*restart)(struct CTextStack *self);

    //render methods
    void (*text)(struct CTextStack *self, const char *element);

    void (*segment_text)(struct CTextStack *self, const char *element);

    void (*format)(struct CTextStack *self, const char *format, ...);

    void (*segment)(struct CTextStack *self);

    void (*segment_format)(struct CTextStack *self, const char *format, ...);

    void (*open_format)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*only_open_format)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*auto_close_format)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*open)(struct CTextStack *self, const char *tag);

    void (*close)(struct CTextStack *self, const char *tag);


    //algorithm methods
    struct CTextStack * (*substr)(struct CTextStack *self, long starter, long end);
    void  (*self_substr)(struct CTextStack *self, long starter, long end);


    struct CTextStack *(*pop)(struct CTextStack *self, long starter, long end);
    void(*self_pop)(struct CTextStack *self, long starter, long end);



    struct CTextStack *(*insert_at)(struct CTextStack *self,long point, const char *element);
    void (*self_insert_at)(struct CTextStack *self,long point, const char *element);

    struct CTextStack *(*replace)(struct CTextStack *self,const char *element, const char *element_to_replace);
    void (*self_replace)(struct CTextStack *self,const char *element, const char *element_to_replace);


    struct CTextStack *(*replace_long)(struct CTextStack *self,const char *element, long element_to_replace);
    void(*self_replace_long)(struct CTextStack *self,const char *element, long element_to_replace);


    struct CTextStack *(*replace_double)(struct CTextStack *self,const char *element, double element_to_replace);
    void (*self_replace_double)(struct CTextStack *self,const char *element, double element_to_replace);


    struct CTextStack * (*lower)(struct CTextStack *self);
    void(*self_lower)(struct CTextStack *self);

    struct CTextStack * (*upper)(struct CTextStack *self);
    void(*self_upper)(struct CTextStack *self);

    struct CTextStack *(*captalize)(struct CTextStack *self);
    void (*self_captalize)(struct CTextStack *self);

    struct CTextStack * (*reverse)(struct CTextStack *self);
    void(*self_reverse)(struct CTextStack *self);

    struct CTextStack * (*trim)(struct CTextStack *self);
    void(*self_trim)(struct CTextStack *self);

    bool (*starts_with)(struct CTextStack *self, const char *element);
    bool (*ends_with)(struct CTextStack *self, const char *element);

    bool (*equal)(struct  CTextStack *self,const char *element);
    int (*typeof_element)(struct CTextStack *self);
    bool (*is_a_num)(struct CTextStack *self);

    const char * (*typeof_in_str)(struct CTextStack *self);
    bool  (*parse_to_bool)(struct CTextStack *self);
    long  (*parse_to_integer)(struct CTextStack *self);
    double  (*parse_to_double)(struct CTextStack *self);

    long (*index_of)(struct CTextStack *self, const char *element);
    long (*index_of_char)(struct CTextStack *self, char element);
}CTextStackModule;


#endif



#ifndef PRIVATE_CTEXT_NAMESPACE_TYPE
#define PRIVATE_CTEXT_NAMESPACE_TYPE
typedef struct CTextNamespace{

    CTextArrayModule array;
    CTextStackModule stack;

}CTextNamespace;
#endif










#ifndef PRIVATE_CTEXT_FUNCTION_DECLARATION
#define PRIVATE_CTEXT_FUNCTION_DECLARATION















char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self);

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack);

void CTextStack_restart(struct CTextStack *self);

void CTextStack_represent(struct CTextStack *self);

void CTextStack_free(struct CTextStack *self);

 CTextStack * CTextStack_clone(struct CTextStack *self);







 CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end);


void CTextStack_self_substr(struct CTextStack *self, long starter, long end);

struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace);

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace);


struct CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace);



void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace);


struct CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace);


void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace);


long CTextStack_index_of(struct  CTextStack *self, const char *element);

long CTextStack_index_of_char(struct  CTextStack *self, char element);

bool CTextStack_starts_with(struct  CTextStack *self, const char *element);


bool CTextStack_ends_with(struct  CTextStack *self, const char *element);



struct CTextStack *CTextStack_lower(struct CTextStack *self);

void CTextStack_self_lower(struct CTextStack *self);


struct CTextStack *CTextStack_upper(struct CTextStack *self);


CTextStack *CTextStack_captalize(struct CTextStack *self);

void CTextStack_self_captalize(struct CTextStack *self);


void CTextStack_self_upper(struct CTextStack *self);


 CTextStack *CTextStack_reverse(struct CTextStack *self);

void CTextStack_self_reverse(struct CTextStack *self);


CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end);


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end);



CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element);


void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element);

CTextStack *CTextStack_trim(struct CTextStack *self);

void CTextStack_self_trim(struct CTextStack *self);

bool CTextStack_equal(  CTextStack *self,const char *element);





 CTextStack * newCTextStack(const char *line_breaker, const char *separator);

 CTextStack *newCTextStack_string(const char *starter);


 CTextStack *newCTextStack_string_format(const char *format, ...);


 CTextStack *newCTextStack_string_getting_ownership(const char *starter);

 CTextStack *newCTextStack_string_empty();





int CTextStack_typeof(struct CTextStack *self);

bool CTextStack_is_a_num(struct CTextStack *self);

const char * CTextStack_typeof_in_str(struct CTextStack *self);

bool  CTextStack_parse_to_bool(struct CTextStack *self);

long  CTextStack_parse_to_integer(struct CTextStack *self);

double  CTextStack_parse_to_double(struct CTextStack *self);





void private_ctext_text_double_size_if_reachs(struct CTextStack *self);


void CTextStack_text(struct CTextStack *self, const char *text);



void CTextStack_segment_text(struct CTextStack *self, const char *text);


void CTextStack_format(struct CTextStack *self, const char *format, ...);


void CTextStack_segment_format(struct CTextStack *self, const char *format, ...);



void CTextStack_segment(struct CTextStack *self);


void CTextStack_open_format(struct CTextStack *self, const char *tag, const char *format, ...);




void CTextStack_only_open_format(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_auto_close_format(struct CTextStack *self, const char *tag, const char *format, ...);


void ctext_open(struct CTextStack *self, const char *tag);



void ctext_close(struct CTextStack *self, const char *tag);








CTextArray * newCTextArray();


void CTextArray_append(CTextArray *self,CTextStack *element);


void CTextArray_append_string(CTextArray *self,const char *element);

CTextStack * CTextArray_join(CTextArray *self,const char *separator);

CTextArray * CTextArray_split(const char *element,const char *target);

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element));

CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element));

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element));

bool CTextArray_includes(CTextArray *self,const char *element);

void  CTextArray_free(CTextArray *self);

void CTextArray_represent(CTextArray *self);





CTextStackModule newCTextStackModule();







CTextArrayModule newCTextArrayModule();






CTextNamespace newCTextNamespace();





long private_CText_transform_index(long size, long value);


void private_ctext_generate_formated_text(
    struct CTextStack *stack,
    const char *format,
    va_list argptr
    );

#endif


#define  CTEXTENGINE_H
#ifdef __cplusplus
}
#endif
#endif
















char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    char *result = self->rendered_text;
    free(self);
    return result;
}

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack){

    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);

    self->rendered_text_alocation_size = new_stack->rendered_text_alocation_size;
    self->size = new_stack->size;
    self->ident_level = new_stack->ident_level;


    self->line_breaker = new_stack->line_breaker;
    self->separator = new_stack->separator;
    self->rendered_text = new_stack->rendered_text;
    free(new_stack);

}
void CTextStack_restart(struct CTextStack *self){
    free(self->rendered_text);
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
}

void CTextStack_represent(struct CTextStack *self){
    printf("%s\n",self->rendered_text);
}


void CTextStack_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}

 CTextStack * CTextStack_clone(struct CTextStack *self){
    CTextStack *new_stack = newCTextStack(self->line_breaker,self->separator);
    new_stack->ident_level = self->ident_level;
    CTextStack_text(new_stack,self->rendered_text);
    return new_stack;
}







 CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CText_transform_index(self->size, starter);
    long formated_end = private_CText_transform_index(self->size, end);

    if(formated_starter == formated_end){
        CTextStack_format(new_element,"%c",self->rendered_text[formated_starter]);
        return new_element;
    }

    for(long i =formated_starter; i < formated_end; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }

    return new_element;

}

void CTextStack_self_substr(struct CTextStack *self, long starter, long end){
    CTextStack *new_stack = CTextStack_substr(self,starter,end);
    private_CTextStack_parse_ownership(self,new_stack);

}


 CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long element_size = (long)strlen(element);
    for(long i = 0; i < self->size;i++){
        CTextStack  *possible_ocurrence  = CTextStack_substr(self,i,i+element_size);

        if(strcmp(possible_ocurrence->rendered_text,element)== 0){
            CTextStack_text(new_element,element_to_replace);
            i+=element_size -1;
        }

        else{
            CTextStack_format(new_element,"%c",self->rendered_text[i]);
        }

        CTextStack_free(possible_ocurrence);

    }
    return new_element;
}

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace){
    CTextStack  *new_stack = CTextStack_replace(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


 CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    char num_conversion[20] = {0};
    sprintf(num_conversion,"%ld",element_to_replace);
    return CTextStack_replace(self,element,num_conversion);
}


void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_long(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


 CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
    CTextStack  *num_formated = newCTextStack_string_empty();
    CTextStack_format(num_formated,"%f",element_to_replace);
    CTextStack  *result = CTextStack_replace(self,element,num_formated->rendered_text);
    CTextStack_free(num_formated);
    return result;
}


void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_double(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}



long CTextStack_index_of(struct  CTextStack *self, const char *element){
    long element_size = (long)strlen(element);
    for(int i = 0; i < self->size; i++){
        CTextStack  *possible_element = CTextStack_substr(self,i,i+element_size);
        if(strcmp(possible_element->rendered_text,element) == 0){
            CTextStack_free(possible_element);
            return i;
        }
        CTextStack_free(possible_element);

    }
    return -1;
}


long CTextStack_index_of_char(struct  CTextStack *self, char element){
    for(int i = 0; i < self->size; i++) {
        if(self->rendered_text[i] == element){
            return i;
        }
    }
    return -1;
}
bool CTextStack_starts_with(struct  CTextStack *self, const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,0,element_size);
    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}

bool CTextStack_ends_with(struct  CTextStack *self, const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,self->size -element_size,-1);

    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}



struct CTextStack *CTextStack_lower(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i =0; i < self->size; i++){
        char current = self->rendered_text[i];
        CTextStack_format(new_element,"%c",tolower(current));
    }
    return new_element;
}

void CTextStack_self_lower(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_lower(self);
    private_CTextStack_parse_ownership(self,new_stack);
}

struct CTextStack *CTextStack_upper(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i =0; i < self->size; i++){
        char current = self->rendered_text[i];
        CTextStack_format(new_element,"%c",toupper(current));
    }
    return new_element;
}

struct CTextStack *CTextStack_captalize(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    if(self->size  ==0){
        return  new_element;
    }

    CTextStack_format(new_element,"%c", toupper(self->rendered_text[0]));

    for(long i =1; i < self->size; i++){
        char  last = self->rendered_text[i-1];
        char current = self->rendered_text[i];


        if(last == ' '){
            CTextStack_format(new_element,"%c",toupper(current));
        }
        else{
            CTextStack_format(new_element,"%c", tolower(current));

        }

    }
    return new_element;
}

void CTextStack_self_captalize(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_captalize(self);
    private_CTextStack_parse_ownership(self,new_stack);
}


void CTextStack_self_upper(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_upper(self);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_reverse(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i = (long)self->size; i >= 0 ; i--){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;

}

void CTextStack_self_reverse(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_reverse(self);
    private_CTextStack_parse_ownership(self,new_stack);
}



struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CText_transform_index(self->size, starter);
    long formated_end = private_CText_transform_index(self->size, end);

    for(int i =0; i < self->size; i ++){
        if(i >= formated_starter && i <= formated_end){
            continue;
        }
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end){
    CTextStack  *new_stack = CTextStack_pop(self, starter, end);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long converted_point = private_CText_transform_index(self->size, point);
    for(long i = 0; i < converted_point; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    CTextStack_text(new_element,element);
    for(long i = converted_point; i < self->size; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}

void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element){
    CTextStack  *new_stack = CTextStack_insert_at(self, point,element);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_trim(struct CTextStack *self){

    CTextStack  *invalid_elements = newCTextStack_string("\t\r\n ");
    long start_point = 0;
    for(int i = 0; i < self->size; i ++){
        char current_char =self->rendered_text[i];
        long invalid_point = CTextStack_index_of_char(invalid_elements, current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            start_point = i;
            break;
        }
    }
    long end_point = -1;
    for(long i = (long)self->size -1; i >= 0; i--){

        char current_char =self->rendered_text[i];
        long invalid_point = CTextStack_index_of_char(invalid_elements, current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            end_point = i+1;
            break;
        }
    }
    CTextStack_free(invalid_elements);
    return CTextStack_substr(self,start_point,end_point);

}


void CTextStack_self_trim(struct CTextStack *self){
    CTextStack  *new_stack = CTextStack_trim(self);
    private_CTextStack_parse_ownership(self,new_stack);
}


bool CTextStack_equal(  CTextStack *self,const char *element){
    return strcmp(self->rendered_text,element) == 0;
}





 CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    *self = (CTextStack){0};
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;

    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);


    return self;
}

 CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        CTextStack_format(self,"%s", starter);
    }
    return self;
}

 CTextStack *newCTextStack_string_format(const char *format, ...){
    CTextStack *self = newCTextStack("","");
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
     va_end(argptr);

    return self;
}

 CTextStack *newCTextStack_string_getting_ownership(const char *starter){
    CTextStack *self = newCTextStack("","");
    free(self->rendered_text);
    self->rendered_text = (char*)starter;
    self->size = strlen(starter);
    self->rendered_text_alocation_size = self->size;
    return self;
}
 CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}





int CTextStack_typeof(struct CTextStack *self){
    if(self->size == 0){
        return CTEXT_STRING;
    }

    if(CTextStack_equal(self,"true") ||CTextStack_equal(self,"false") ){
        return CTEXT_BOOL;
    }

    double data;
    int result = sscanf(self->rendered_text,"%lf",&data);
    if(!result){
        return CTEXT_STRING;
    }
    if(CTextStack_index_of(self,".") == -1){
        return CTEXT_LONG;
    }
    return CTEXT_DOUBLE;


}
bool CTextStack_is_a_num(struct CTextStack *self){
    int type = CTextStack_typeof(self);
    if(type == CTEXT_DOUBLE || type == CTEXT_LONG){
        return true;
    }
    return false;
}


const char * CTextStack_typeof_in_str(struct CTextStack *self){
    int current_type = CTextStack_typeof(self);

    if(current_type == CTEXT_BOOL){
        return "bool";
    }

    else if(current_type == CTEXT_STRING){
        return "string";
    }

    else if(current_type == CTEXT_LONG){
        return "long";
    }

    else if(current_type == CTEXT_DOUBLE){
        return "double";
    }

    else{
        return "invalid";
    }
}

bool  CTextStack_parse_to_bool(struct CTextStack *self){
    if(CTextStack_equal(self,"true")){
        return true;
    }
    return false;
}

long  CTextStack_parse_to_integer(struct CTextStack *self){
    long value;
    int result = sscanf(self->rendered_text,"%ld",&value);
    if(!result){
        return -1;
    }
    return value;
}

double  CTextStack_parse_to_double(struct CTextStack *self){
    double value;
    int result = sscanf(self->rendered_text,"%lf",&value);
    if(!result){
        return -1;
    }
    return value;
}





void private_ctext_text_double_size_if_reachs(struct CTextStack *self){

    while(self->size >= (self->rendered_text_alocation_size - 2)){
        self->rendered_text_alocation_size  =  (self->rendered_text_alocation_size  * 2)+2;
        self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
        ));
    }
}

void CTextStack_text(struct CTextStack *self, const char *text){

    if (!text || !text[0]) {
        // Tratar caso de ponteiro nulo ou string vazia
        return;
    }

    size_t text_size = strlen(text);

    self->size += text_size;
    private_ctext_text_double_size_if_reachs(self);

    memcpy(
            self->rendered_text + self->size - text_size,
        text,
        text_size
    );
    self->rendered_text[self->size] = '\0';
}



void CTextStack_segment_text(struct CTextStack *self, const char *text){
    CTextStack_segment(self);
    CTextStack_text(self,text);
}


void CTextStack_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
    va_end(argptr);

}

void CTextStack_segment_format(struct CTextStack *self, const char *format, ...){
    CTextStack_segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
    va_end(argptr);

}


void CTextStack_segment(struct CTextStack *self){

    CTextStack_text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        CTextStack_text(self,self->separator);

    }


}

void CTextStack_open_format(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');
    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
        va_end(argptr);

    }
    CTextStack_format(self, "%c",'>');


    self->ident_level += 1;
}



void CTextStack_only_open_format(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
        va_end(argptr);

    }
    CTextStack_format(self, "%c",'>');


}

void CTextStack_auto_close_format(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
        va_end(argptr);
    }
    CTextStack_text(self,"/>");

}

void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }
    CTextStack_open_format(self, tag, NULL);
}



void ctext_close(struct CTextStack *self, const char *tag){

    if(tag==NULL){
        self->ident_level -= 1;

        return;
    }
    self->ident_level -= 1;
    CTextStack_segment(self);


    CTextStack_text(self,"</");
    CTextStack_text(self,tag);
    CTextStack_format(self, "%c",'>');

}







CTextArray * newCTextArray(){
    CTextArray  *self = (CTextArray*) malloc(sizeof (CTextArray));
    self->size = 0;
    self->stacks = (CTextStack**) malloc(0);
    return self;
}

void CTextArray_append(CTextArray *self,CTextStack *element){
    self->stacks =  (CTextStack**) realloc(
            self->stacks,
            (self->size+1)* sizeof (CTextStack*)
            );

    self->stacks[self->size] = element;
    self->size+=1;
}



void CTextArray_append_string(CTextArray *self,const char *element){
    CTextStack *new_element = newCTextStack_string(element);
    CTextArray_append(self,new_element);
}

CTextStack * CTextArray_join(CTextArray *self,const char *separator){
    CTextStack  *result  = newCTextStack_string_empty();
    for(int i = 0; i < self->size; i++){
        if(i < self->size -1){
            CTextStack_format(result,"%t%s",self->stacks[i],separator);
        }
        else{
            CTextStack_format(result,"%t",self->stacks[i]);

        }

    }
    return result;
}

CTextArray *CTextArray_split(const char *element,const char *target){
    CTextArray *self = newCTextArray();
    CTextStack *text = newCTextStack_string(element);
    long target_size = (long)strlen(target);
    CTextStack  *acumulated = newCTextStack_string_empty();

    for(int i = 0; i <text->size; i++){
        CTextStack  *possible_division = CTextStack_substr(text,i,target_size + i);
        if(CTextStack_equal(possible_division,target)){
            CTextArray_append(self,acumulated);
            acumulated = newCTextStack_string_empty();
            CTextStack_free(possible_division);
            continue;
        }
        CTextStack_free(possible_division);

        CTextStack_format(acumulated,"%c",text->rendered_text[i]);
    }

    CTextArray_append(self,acumulated);
    CTextStack_free(text);
    return self;
}



void  CTextArray_free(CTextArray *self){
    for(int i = 0; i < self->size; i++){
            CTextStack_free(self->stacks[i]);
    }
    free(self->stacks);
    free(self);
}

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();
    for(int i = 0; i < self->size; i++){
        CTextStack *result = caller(self->stacks[i]);
        CTextArray_append(new_array,result);
    }
    return new_array;
}


CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();

    for(int i = 0; i < self->size; i++){
        if(caller(self->stacks[i])){

            CTextArray_append(new_array, CTextStack_clone(self->stacks[i]));
        }
    }

    return new_array;
}

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element)){
    for(int i = 0; i < self->size; i++){
        caller(self->stacks[i]);
    }
}

bool CTextArray_includes(CTextArray *self,const char *element){
    for(int i = 0 ; i < self->size;i++){
        if(CTextStack_equal(self->stacks[i],element)){
            return true;
        }
    }
    return false;
}


void CTextArray_represent(CTextArray *self){
    for(int i =0; i < self->size; i++){
        CTextStack_represent(self->stacks[i]);
    }
}





CTextStackModule newCTextStackModule(){
    struct CTextStackModule self = {0};
    self.newStack = newCTextStack;
    self.newStack_string = newCTextStack_string;
    self.newStack_string_format = newCTextStack_string_format;
    self.newStack_string_empty = newCTextStack_string_empty;
    self.newStack_string_getting_ownership = newCTextStack_string_getting_ownership;
    self.text = CTextStack_text;
    self.segment_text = CTextStack_segment_text;
    self.format = CTextStack_format;
    self.segment = CTextStack_segment;
    self.segment_format = CTextStack_segment_format;
    self.open_format = CTextStack_open_format;
    self.only_open_format =CTextStack_only_open_format;
    self.auto_close_format = CTextStack_auto_close_format;
    self.open = ctext_open;
    self.close = ctext_close;
    self.free =  CTextStack_free;
    self.clone = CTextStack_clone;
    self.represent = CTextStack_represent;
    self.self_transform_in_string_and_self_clear = CTextStack_self_transform_in_string_and_self_clear;
    self.restart = CTextStack_restart;
    self.substr = CTextStack_substr;
    self.self_substr =CTextStack_self_substr;

    self.pop = CTextStack_pop;
    self.self_pop =CTextStack_self_pop;

    self.replace = CTextStack_replace;
    self.self_replace = CTextStack_self_replace;

    self.replace_long = CTextStack_replace_long;
    self.self_replace_long =CTextStack_self_replace_long;


    self.replace_double = CTextStack_replace_double;
    self.self_replace_double =CTextStack_self_replace_double;

    self.insert_at = CTextStack_insert_at;
    self.self_insert_at  = CTextStack_self_insert_at;


    self.index_of = CTextStack_index_of;
    self.index_of_char = CTextStack_index_of_char;

    self.lower = CTextStack_lower;
    self.self_lower = CTextStack_self_lower;

    self.upper = CTextStack_upper;
    self.self_upper = CTextStack_self_upper;

    self.captalize = CTextStack_captalize;
    self.self_captalize = CTextStack_self_captalize;

    self.starts_with = CTextStack_starts_with;
    self.ends_with = CTextStack_ends_with;

    self.equal = CTextStack_equal;
    self.reverse = CTextStack_reverse;
    self.self_reverse = CTextStack_self_reverse;


    self.typeof_element = CTextStack_typeof;
    self.is_a_num = CTextStack_is_a_num;
    self.typeof_in_str = CTextStack_typeof_in_str;
    self.parse_to_bool = CTextStack_parse_to_bool;
    self.parse_to_integer = CTextStack_parse_to_integer;
    self.parse_to_double = CTextStack_parse_to_double;

    self.trim = CTextStack_trim;
    self.self_trim = CTextStack_self_trim;


    return self;
}






CTextArrayModule newCTextArrayModule(){
    CTextArrayModule module = {0};
    module.newArray = newCTextArray;
    module.append = CTextArray_append;
    module.append_string = CTextArray_append_string;
    module.join = CTextArray_join;
    module.map  = CTextArray_map;
    module.filter = CTextArray_filter;
    module.foreach = CTextArray_foreach;
    module.represent = CTextArray_represent;
    module.includes = CTextArray_includes;
    module.free = CTextArray_free;
    return module;
}






CTextNamespace newCTextNamespace(){
    CTextNamespace self  = {0};
    self.stack = newCTextStackModule();
    self.array = newCTextArrayModule();
    return self;
}






void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    long  text_size = strlen(format);

    int i;
    for(i =0;i < text_size -1 ;i++){

        char single_test[3] = {format[i],format[i+1],'\0'};
        char double_test[4] = {0};


        if(i < text_size -2){
            strcpy(double_test,single_test);
            double_test[2] = format[i+2];
            double_test[3] = '\0';

        }

        if(strcmp(single_test,"%d") == 0 || strcmp(single_test,"%i") == 0) {
            int value = va_arg(argptr,int);
            char result[20] ={0};
            sprintf(result,"%d", value);



            CTextStack_text(stack,result);

            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%ld") == 0 ) {

            int value = va_arg(argptr,int);
            char result[20] ={0};
            sprintf(result,"%d", value);

            CTextStack_text(stack,result);

            i+=2;
            continue;
        }


        else if(strcmp(single_test,"%f") == 0 ) {
            char result_text[20]= {0};

            sprintf(result_text,"%lf", va_arg(argptr,double ));

            for(int t = 18; t > 0; t--){
                char current_char = result_text[t];
                if(current_char != '0' && current_char != '\0'){

                    if(current_char == '.'){
                        result_text[t+2]  = '\0';
                    }
                    else{
                        result_text[t+1]  = '\0';
                    }

                    break;
                }
            }
            CTextStack_text(stack,result_text);
            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%lf") == 0 ) {
            char result_text[20]= {0};

            sprintf(result_text,"%lf", va_arg(argptr,double ));

            for(int t = 18; t > 0; t--){
                char current_char = result_text[t];
                if(current_char != '0' && current_char != '\0'){

                    if(current_char == '.'){
                        result_text[t+2]  = '\0';
                    }
                    else{
                        result_text[t+1]  = '\0';
                    }

                    break;
                }
            }
            CTextStack_text(stack,result_text);
            i+=2;
            continue;
        }
        else if(strcmp(single_test,"%c") == 0){
            char result = va_arg(argptr,int);
            char element[2] = {result,'\0'};
            CTextStack_text(stack,element);
            i+=1;
            continue;
        }


        else if(strcmp(single_test,"%b") == 0){
            bool value = va_arg(argptr,int);
            if(value){
                CTextStack_text(stack,"true");
            }else{
                CTextStack_text(stack,"false");
            }
            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%sc") == 0){
            char *value = va_arg(argptr,char*);
            if(value){
                CTextStack_text(stack,value);
                free(value);
            }
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%s") == 0){
            const char *value = va_arg(argptr,const char*);
            if(value){
                CTextStack_text(stack,value);
            }

            i+=1;
            continue;
        }
        else if(strcmp(double_test,"%tc") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            if(new_stack){
                char *result = CTextStack_self_transform_in_string_and_self_clear(new_stack);
                CTextStack_text(stack,result);
                free(result);
            }
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%t") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            if(new_stack){
                CTextStack_text(stack,new_stack->rendered_text);
            }
            i+=1;
            continue;
        }

        char element[2] = {format[i],'\0'};
        CTextStack_text(stack,element);

        }



    if(text_size > 0 && text_size> i){
        char element[2] = {format[text_size-1],'\0'};
        CTextStack_text(stack,element);
    }

    va_end(argptr);
}


long private_CText_transform_index(long size , long value){
    long formated_value = value;

    if(formated_value >= size){
        formated_value = size;
    }

    if(formated_value  < 0){
        formated_value = size + (formated_value +1);
    }
    if(formated_value <0){
        formated_value = 0;
    }
    return formated_value;
}






#define  CTEXTENGINE_H
#endif


// USE  THIS FILE ONLY FOR PRODUCTION
// This file is part of the DoTheWorld project.
// Do not edit this file, it is automatically generated.
// See the README.md file for more information.
/*
MIT License

Copyright (c) 2023 Mateus Moutinho Queiroz

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef DO_THE_WORLD_H

#define DO_THE_WORLD_ONE





#ifdef __cplusplus
extern "C" {
#endif

#ifndef DO_THE_WORLD_H
#define DO_THE_WORLD_H


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

#include <stdarg.h>

#include <errno.h>
#include <sys/file.h>
#include <sys/time.h>



#ifdef __linux__
#include <sys/wait.h>
  #include <dirent.h>
  #include <unistd.h>
#elif _WIN32
  #include <windows.h>
  #include <tchar.h>
  #include <wchar.h>
  #include <locale.h>
  #include <direct.h>
#endif


#ifndef PRIVATE_DTW_CONSTS_H
#define PRIVATE_DTW_CONSTS_H

#define DTW_FILE_TYPE 1
#define DTW_FOLDER_TYPE 2
#define DTW_ALL_TYPE 3
#define DTW_NOT_FOUND -1

#define DTW_COMPLEX_BINARY 10
#define DTW_COMPLEX_STRING_TYPE 11
#define DTW_COMPLEX_LONG_TYPE 12
#define DTW_COMPLEX_DOUBLE_TYPE 13
#define DTW_COMPLEX_BOOL_TYPE 14

#define DTW_MERGE true


#define DTW_NOT_MERGE false

#define DTW_NOT_NUMERICAL -2
#define DTW_NOT_BOOL -3

#define DTW_CONCAT_PATH true
#define DTW_NOT_CONCAT_PATH false
#define WIN32_FILETYPE 32


#define DTW_MULTIFILE_LOCKER_TOTAL_CHECK 500
#define DTW_MULTIFILE_LOCKER_MAX_TIMEOUT 10
#define DTW_MULFILE_LOCKER_MAX_WAIT 10


#define DTW_LOCKER_LOCKED 0
#define DTW_LOCKER_IMPOSSIBLE_TO_CREATE_FILE_DESCRIPTOR 5
#define DTW_LOCKER_FLCTL_FAIL 6
#define DTW_LOCKER_WAIT_ERROR 21
#define DTW_LOCKER_OS_NOT_PREDICTIBLE -1



#define DTW_RESOURCE_ELEMENT_IS_NULL -1
#define DTW_RESOURCE_OK 0
#define DTW_RESOURCE_ELEMENT_NOT_EXIST 1
#define DTW_RESOURCE_ELEMENT_NOT_BOOL 2
#define DTW_RESOURCE_ELEMENT_NOT_LONG 3
#define DTW_RESOURCE_ELEMENT_NOT_DOUBLE 4
#define DTW_RESOURCE_ELEMENT_NOT_STRING 5
#define DTW_RESOURCE_PRIMARY_KEY_ALREADY_EXIST 6
#define DTW_RESOURCE_PRIMARY_KEY_CANNOT_HAVE_SUB_RESOURCE 7
#define DTW_IMPOSSIBLE_TO_RENAME_A_PRIMARY_KEY 8
#define DTW_RESOURCE_RENAMED_RESOURCE_CANNOT_HAVE_SONS 9
#define DTW_RESOURCE_IMPSSIBLE_TO_ADD_INSERTION_OUTSIDE_ROOT_SCHEMA 10
#define DTW_RESOURCE_IMPOSSIBLE_TO_ADD_SUB_RESOURCE_INSIDE_SCHEMA_STRUCT 11
#define DTW_RESOURCE_ONLY_ROOT_SCHEMA_CAN_FIND_BY_ID_OR_PK 12
#define DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES 13
#define DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS 14


#define PRIVATE_DTW_SCHEMA_ROOT  1
#define PRIVATE_DTW_SCHEMA_VALUE 2
#define PRIVATE_DTW_SCHEMA_ELEMENT 3
#define PRIVATE_DTW_SCHEMA_ELEMENT_PROP 4
#define PRIVATE_DTW_SCHEMA_INDEX 5
#define PRIVATE_DTW_SCHEMA_PK_FOLDER 6
#define PRIVATE_DTW_SCHEMA_PK_VALUE 7


#define DTW_SCHEMA_DEFAULT_VALUES_NAME "value"
#define DTW_SCHEMA_DEFAULT_INDEX_NAME "index"

#define DTW_RESOURCE_ALL -1


enum {

    JSON_TRANSACTION_WRONG_TYPE,
    JSON_TRANSACTION_NOT_PRESENT_VALUE,
    JSON_TRANSACTION_INVALID_ACTION
};


enum {
    DTW_ACTION_FILE_NOT_FOUND,
    DTW_ACTION_ITS_NOT_JSON,
    DTW_ACTION_WRITE,
    DTW_ACTION_MOVE,
    DTW_ACTION_MOVE_MERGING,
    DTW_ACTION_COPY,
    DTW_ACTION_COPY_MERGING,
    DTW_ACTION_DELETE
};





#define DTW_NOT_MIMIFY 1
#define DTW_MIMIFY 2

#define DTW_NOT_LOAD 1
#define DTW_LOAD 2

#define DTW_HIDE 1
#define DTW_INCLUDE 2




#define DTW_IS_BINARY true
#define DTW_IS_NOT_BINARY false
#define DTW_IGNORE true
#define DTW_NOT_IGNORE false

#define DTW_SET_AS_ACTION 1
#define DTW_EXECUTE_NOW 2

#define DTW_MODIFY 1
#define DTW_WRITE 2
#define DTW_REMOVE 3


#define DTW_JSON_TYPE_ERROR 1
#define DTW_JSON_SYNTAX_ERROR 2
#define DTW_JSON_REQUIRED_KEY_ERROR 3
#define DTW_JSON_REQUIRED_VALUE_ERROR 4
#define DTW_JSON_NOT_FOUND_ERROR 5
#define DTW_ACTION_ERROR (-1)



#endif



#ifndef PRIVATE_DTW_MACROS_H
#define PRIVATE_DTW_MACROS_H

#ifdef __linux__
#define dtw_create_dir(path) mkdir(path,0777)
#elif _WIN32
#define dtw_create_dir(path) _mkdir(path)

#endif





#define DtwSchemaRebase self->root_props->schema_unsafe =old;
#define privateDtwSchemaUnsafe(scope){\
    bool old = self->root_props->schema_unsafe;\
    self->root_props->schema_unsafe = true;\
    scope;\
    DtwSchemaRebase\
}


#endif


#ifndef cJSON__h
/*
  Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

#ifndef cJSON__h
#define cJSON__h

#ifdef __cplusplus
extern "C"
{
#endif

#if !defined(__WINDOWS__) && (defined(WIN32) || defined(WIN64) || defined(_MSC_VER) || defined(_WIN32))
#define __WINDOWS__
#endif

#ifdef __WINDOWS__

/* When compiling for windows, we specify a specific calling convention to avoid issues where we are being called from a project with a different default calling convention.  For windows you have 3 define options:

CJSON_HIDE_SYMBOLS - Define this in the case where you don't want to ever dllexport symbols
CJSON_EXPORT_SYMBOLS - Define this on library build when you want to dllexport symbols (default)
CJSON_IMPORT_SYMBOLS - Define this if you want to dllimport symbol

For *nix builds that support visibility attribute, you can define similar behavior by

setting default visibility to hidden by adding
-fvisibility=hidden (for gcc)
or
-xldscope=hidden (for sun cc)
to CFLAGS

then using the CJSON_API_VISIBILITY flag to "export" the same symbols the way CJSON_EXPORT_SYMBOLS does

*/

#define CJSON_CDECL __cdecl
#define CJSON_STDCALL __stdcall

/* export symbols by default, this is necessary for copy pasting the C and header file */
#if !defined(CJSON_HIDE_SYMBOLS) && !defined(CJSON_IMPORT_SYMBOLS) && !defined(CJSON_EXPORT_SYMBOLS)
#define CJSON_EXPORT_SYMBOLS
#endif

#if defined(CJSON_HIDE_SYMBOLS)
#define CJSON_PUBLIC(type)   type CJSON_STDCALL
#elif defined(CJSON_EXPORT_SYMBOLS)
#define CJSON_PUBLIC(type)   __declspec(dllexport) type CJSON_STDCALL
#elif defined(CJSON_IMPORT_SYMBOLS)
#define CJSON_PUBLIC(type)   __declspec(dllimport) type CJSON_STDCALL
#endif
#else /* !__WINDOWS__ */
#define CJSON_CDECL
#define CJSON_STDCALL

#if (defined(__GNUC__) || defined(__SUNPRO_CC) || defined (__SUNPRO_C)) && defined(CJSON_API_VISIBILITY)
#define CJSON_PUBLIC(type)   __attribute__((visibility("default"))) type
#else
#define CJSON_PUBLIC(type) type
#endif
#endif

/* project version */
#define CJSON_VERSION_MAJOR 1
#define CJSON_VERSION_MINOR 7
#define CJSON_VERSION_PATCH 18

#include <stddef.h>

/* cJSON Types: */
#define cJSON_Invalid (0)
#define cJSON_False  (1 << 0)
#define cJSON_True   (1 << 1)
#define cJSON_NULL   (1 << 2)
#define cJSON_Number (1 << 3)
#define cJSON_String (1 << 4)
#define cJSON_Array  (1 << 5)
#define cJSON_Object (1 << 6)
#define cJSON_Raw    (1 << 7) /* raw json */

#define cJSON_IsReference 256
#define cJSON_StringIsConst 512

/* The cJSON structure: */
typedef struct cJSON
{
    /* next/prev allow you to walk array/object chains. Alternatively, use GetArraySize/GetArrayItem/GetObjectItem */
    struct cJSON *next;
    struct cJSON *prev;
    /* An array or object item will have a child pointer pointing to a chain of the items in the array/object. */
    struct cJSON *child;

    /* The type of the item, as above. */
    int type;

    /* The item's string, if type==cJSON_String  and type == cJSON_Raw */
    char *valuestring;
    /* writing to valueint is DEPRECATED, use cJSON_SetNumberValue instead */
    int valueint;
    /* The item's number, if type==cJSON_Number */
    double valuedouble;

    /* The item's name string, if this item is the child of, or is in the list of subitems of an object. */
    char *string;
} cJSON;

typedef struct cJSON_Hooks
{
      /* malloc/free are CDECL on Windows regardless of the default calling convention of the compiler, so ensure the hooks allow passing those functions directly. */
      void *(CJSON_CDECL *malloc_fn)(size_t sz);
      void (CJSON_CDECL *free_fn)(void *ptr);
} cJSON_Hooks;

typedef int cJSON_bool;

/* Limits how deeply nested arrays/objects can be before cJSON rejects to parse them.
 * This is to prevent stack overflows. */
#ifndef CJSON_NESTING_LIMIT
#define CJSON_NESTING_LIMIT 1000
#endif

/* returns the version of cJSON as a string */
CJSON_PUBLIC(const char*) cJSON_Version(void);

/* Supply malloc, realloc and free functions to cJSON */
CJSON_PUBLIC(void) cJSON_InitHooks(cJSON_Hooks* hooks);

/* Memory Management: the caller is always responsible to free the results from all variants of cJSON_Parse (with cJSON_Delete) and cJSON_Print (with stdlib free, cJSON_Hooks.free_fn, or cJSON_free as appropriate). The exception is cJSON_PrintPreallocated, where the caller has full responsibility of the buffer. */
/* Supply a block of JSON, and this returns a cJSON object you can interrogate. */
CJSON_PUBLIC(cJSON *) cJSON_Parse(const char *value);
CJSON_PUBLIC(cJSON *) cJSON_ParseWithLength(const char *value, size_t buffer_length);
/* ParseWithOpts allows you to require (and check) that the JSON is null terminated, and to retrieve the pointer to the final byte parsed. */
/* If you supply a ptr in return_parse_end and parsing fails, then return_parse_end will contain a pointer to the error so will match cJSON_GetErrorPtr(). */
CJSON_PUBLIC(cJSON *) cJSON_ParseWithOpts(const char *value, const char **return_parse_end, cJSON_bool require_null_terminated);
CJSON_PUBLIC(cJSON *) cJSON_ParseWithLengthOpts(const char *value, size_t buffer_length, const char **return_parse_end, cJSON_bool require_null_terminated);

/* Render a cJSON entity to text for transfer/storage. */
CJSON_PUBLIC(char *) cJSON_Print(const cJSON *item);
/* Render a cJSON entity to text for transfer/storage without any formatting. */
CJSON_PUBLIC(char *) cJSON_PrintUnformatted(const cJSON *item);
/* Render a cJSON entity to text using a buffered strategy. prebuffer is a guess at the final size. guessing well reduces reallocation. fmt=0 gives unformatted, =1 gives formatted */
CJSON_PUBLIC(char *) cJSON_PrintBuffered(const cJSON *item, int prebuffer, cJSON_bool fmt);
/* Render a cJSON entity to text using a buffer already allocated in memory with given length. Returns 1 on success and 0 on failure. */
/* NOTE: cJSON is not always 100% accurate in estimating how much memory it will use, so to be safe allocate 5 bytes more than you actually need */
CJSON_PUBLIC(cJSON_bool) cJSON_PrintPreallocated(cJSON *item, char *buffer, const int length, const cJSON_bool format);
/* Delete a cJSON entity and all subentities. */
CJSON_PUBLIC(void) cJSON_Delete(cJSON *item);

/* Returns the number of items in an array (or object). */
CJSON_PUBLIC(int) cJSON_GetArraySize(const cJSON *array);
/* Retrieve item number "index" from array "array". Returns NULL if unsuccessful. */
CJSON_PUBLIC(cJSON *) cJSON_GetArrayItem(const cJSON *array, int index);
/* Get item "string" from object. Case insensitive. */
CJSON_PUBLIC(cJSON *) cJSON_GetObjectItem(const cJSON * const object, const char * const string);
CJSON_PUBLIC(cJSON *) cJSON_GetObjectItemCaseSensitive(const cJSON * const object, const char * const string);
CJSON_PUBLIC(cJSON_bool) cJSON_HasObjectItem(const cJSON *object, const char *string);
/* For analysing failed parses. This returns a pointer to the parse error. You'll probably need to look a few chars back to make sense of it. Defined when cJSON_Parse() returns 0. 0 when cJSON_Parse() succeeds. */
CJSON_PUBLIC(const char *) cJSON_GetErrorPtr(void);

/* Check item type and return its value */
CJSON_PUBLIC(char *) cJSON_GetStringValue(const cJSON * const item);
CJSON_PUBLIC(double) cJSON_GetNumberValue(const cJSON * const item);

/* These functions check the type of an item */
CJSON_PUBLIC(cJSON_bool) cJSON_IsInvalid(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsFalse(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsTrue(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsBool(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsNull(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsNumber(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsString(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsArray(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsObject(const cJSON * const item);
CJSON_PUBLIC(cJSON_bool) cJSON_IsRaw(const cJSON * const item);

/* These calls create a cJSON item of the appropriate type. */
CJSON_PUBLIC(cJSON *) cJSON_CreateNull(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateTrue(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateFalse(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateBool(cJSON_bool boolean);
CJSON_PUBLIC(cJSON *) cJSON_CreateNumber(double num);
CJSON_PUBLIC(cJSON *) cJSON_CreateString(const char *string);
/* raw json */
CJSON_PUBLIC(cJSON *) cJSON_CreateRaw(const char *raw);
CJSON_PUBLIC(cJSON *) cJSON_CreateArray(void);
CJSON_PUBLIC(cJSON *) cJSON_CreateObject(void);

/* Create a string where valuestring references a string so
 * it will not be freed by cJSON_Delete */
CJSON_PUBLIC(cJSON *) cJSON_CreateStringReference(const char *string);
/* Create an object/array that only references it's elements so
 * they will not be freed by cJSON_Delete */
CJSON_PUBLIC(cJSON *) cJSON_CreateObjectReference(const cJSON *child);
CJSON_PUBLIC(cJSON *) cJSON_CreateArrayReference(const cJSON *child);

/* These utilities create an Array of count items.
 * The parameter count cannot be greater than the number of elements in the number array, otherwise array access will be out of bounds.*/
CJSON_PUBLIC(cJSON *) cJSON_CreateIntArray(const int *numbers, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateFloatArray(const float *numbers, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateDoubleArray(const double *numbers, int count);
CJSON_PUBLIC(cJSON *) cJSON_CreateStringArray(const char *const *strings, int count);

/* Append item to the specified array/object. */
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToArray(cJSON *array, cJSON *item);
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item);
/* Use this when string is definitely const (i.e. a literal, or as good as), and will definitely survive the cJSON object.
 * WARNING: When this function was used, make sure to always check that (item->type & cJSON_StringIsConst) is zero before
 * writing to `item->string` */
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObjectCS(cJSON *object, const char *string, cJSON *item);
/* Append reference to item to the specified array/object. Use this when you want to add an existing cJSON to a new cJSON, but don't want to corrupt your existing cJSON. */
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item);
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToObject(cJSON *object, const char *string, cJSON *item);

/* Remove/Detach items from Arrays/Objects. */
CJSON_PUBLIC(cJSON *) cJSON_DetachItemViaPointer(cJSON *parent, cJSON * const item);
CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromArray(cJSON *array, int which);
CJSON_PUBLIC(void) cJSON_DeleteItemFromArray(cJSON *array, int which);
CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObject(cJSON *object, const char *string);
CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObjectCaseSensitive(cJSON *object, const char *string);
CJSON_PUBLIC(void) cJSON_DeleteItemFromObject(cJSON *object, const char *string);
CJSON_PUBLIC(void) cJSON_DeleteItemFromObjectCaseSensitive(cJSON *object, const char *string);

/* Update array items. */
CJSON_PUBLIC(cJSON_bool) cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem); /* Shifts pre-existing items to the right. */
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemViaPointer(cJSON * const parent, cJSON * const item, cJSON * replacement);
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem);
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObject(cJSON *object,const char *string,cJSON *newitem);
CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObjectCaseSensitive(cJSON *object,const char *string,cJSON *newitem);

/* Duplicate a cJSON item */
CJSON_PUBLIC(cJSON *) cJSON_Duplicate(const cJSON *item, cJSON_bool recurse);
/* Duplicate will create a new, identical cJSON item to the one you pass, in new memory that will
 * need to be released. With recurse!=0, it will duplicate any children connected to the item.
 * The item->next and ->prev pointers are always zero on return from Duplicate. */
/* Recursively compare two cJSON items for equality. If either a or b is NULL or invalid, they will be considered unequal.
 * case_sensitive determines if object keys are treated case sensitive (1) or case insensitive (0) */
CJSON_PUBLIC(cJSON_bool) cJSON_Compare(const cJSON * const a, const cJSON * const b, const cJSON_bool case_sensitive);

/* Minify a strings, remove blank characters(such as ' ', '\t', '\r', '\n') from strings.
 * The input pointer json cannot point to a read-only address area, such as a string constant,
 * but should point to a readable and writable address area. */
CJSON_PUBLIC(void) cJSON_Minify(char *json);

/* Helper functions for creating and adding items to an object at the same time.
 * They return the added item or NULL on failure. */
CJSON_PUBLIC(cJSON*) cJSON_AddNullToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddTrueToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddFalseToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddBoolToObject(cJSON * const object, const char * const name, const cJSON_bool boolean);
CJSON_PUBLIC(cJSON*) cJSON_AddNumberToObject(cJSON * const object, const char * const name, const double number);
CJSON_PUBLIC(cJSON*) cJSON_AddStringToObject(cJSON * const object, const char * const name, const char * const string);
CJSON_PUBLIC(cJSON*) cJSON_AddRawToObject(cJSON * const object, const char * const name, const char * const raw);
CJSON_PUBLIC(cJSON*) cJSON_AddObjectToObject(cJSON * const object, const char * const name);
CJSON_PUBLIC(cJSON*) cJSON_AddArrayToObject(cJSON * const object, const char * const name);

/* When assigning an integer value, it needs to be propagated to valuedouble too. */
#define cJSON_SetIntValue(object, number) ((object) ? (object)->valueint = (object)->valuedouble = (number) : (number))
/* helper for the cJSON_SetNumberValue macro */
CJSON_PUBLIC(double) cJSON_SetNumberHelper(cJSON *object, double number);
#define cJSON_SetNumberValue(object, number) ((object != NULL) ? cJSON_SetNumberHelper(object, (double)number) : (number))
/* Change the valuestring of a cJSON_String object, only takes effect when type of object is cJSON_String */
CJSON_PUBLIC(char*) cJSON_SetValuestring(cJSON *object, const char *valuestring);

/* If the object is not a boolean type this does nothing and returns cJSON_Invalid else it returns the new type*/
#define cJSON_SetBoolValue(object, boolValue) ( \
    (object != NULL && ((object)->type & (cJSON_False|cJSON_True))) ? \
    (object)->type=((object)->type &(~(cJSON_False|cJSON_True)))|((boolValue)?cJSON_True:cJSON_False) : \
    cJSON_Invalid\
)

/* Macro for iterating over an array or object */
#define cJSON_ArrayForEach(element, array) for(element = (array != NULL) ? (array)->child : NULL; element != NULL; element = element->next)

/* malloc/free objects using the malloc/free functions that have been set with cJSON_InitHooks */
CJSON_PUBLIC(void *) cJSON_malloc(size_t size);
CJSON_PUBLIC(void) cJSON_free(void *object);

#ifdef __cplusplus
}
#endif

#endif

#define PRIVATE_DTW_CJSON_DEFINED_IN_DO_THE_WORLD
#endif //cJSON__h

#ifndef SHA_256_H
#ifndef SHA_256_H
#define SHA_256_H

#include <stdint.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * @brief Size of the SHA-256 sum. This times eight is 256 bits.
 */
#define SIZE_OF_SHA_256_HASH 32

/*
 * @brief Size of the chunks used for the calculations.
 *
 * @note This should mostly be ignored by the user, although when using the streaming API, it has an impact for
 * performance. Add chunks whose size is a multiple of this, and you will avoid a lot of superfluous copying in RAM!
 */
#define SIZE_OF_SHA_256_CHUNK 64

/*
 * @brief The opaque SHA-256 type, that should be instantiated when using the streaming API.
 *
 * @note Although the details are exposed here, in order to make instantiation easy, you should refrain from directly
 * accessing the fields, as they may change in the future.
 */
struct Sha_256 {
	uint8_t *hash;
	uint8_t chunk[SIZE_OF_SHA_256_CHUNK];
	uint8_t *chunk_pos;
	size_t space_left;
	uint64_t total_len;
	uint32_t h[8];
};

/*
 * @brief The simple SHA-256 calculation function.
 * @param hash Hash array, where the result is delivered.
 * @param input Pointer to the data the hash shall be calculated on.
 * @param len Length of the input data, in byte.
 *
 * @note If all of the data you are calculating the hash value on is available in a contiguous buffer in memory, this is
 * the function you should use.
 *
 * @note If either of the passed pointers is NULL, the results are unpredictable.
 *
 * @note See note about maximum data length for sha_256_write, as it applies for this function's len argument too.
 */
void calc_sha_256(uint8_t hash[SIZE_OF_SHA_256_HASH], const void *input, size_t len);

/*
 * @brief Initialize a SHA-256 streaming calculation.
 * @param sha_256 A pointer to a SHA-256 structure.
 * @param hash Hash array, where the result will be delivered.
 *
 * @note If all of the data you are calculating the hash value on is not available in a contiguous buffer in memory,
 * this is where you should start. Instantiate a SHA-256 structure, for instance by simply declaring it locally, make
 * your hash buffer available, and invoke this function. Once a SHA-256 hash has been calculated (see further below) a
 * SHA-256 structure can be initialized again for the next calculation.
 *
 * @note If either of the passed pointers is NULL, the results are unpredictable.
 */
void sha_256_init(struct Sha_256 *sha_256, uint8_t hash[SIZE_OF_SHA_256_HASH]);

/*
 * @brief Stream more input data for an on-going SHA-256 calculation.
 * @param sha_256 A pointer to a previously initialized SHA-256 structure.
 * @param data Pointer to the data to be added to the calculation.
 * @param len Length of the data to add, in byte.
 *
 * @note This function may be invoked an arbitrary number of times between initialization and closing, but the maximum
 * data length is limited by the SHA-256 algorithm: the total number of bits (i.e. the total number of bytes times
 * eight) must be representable by a 64-bit unsigned integer. While that is not a practical limitation, the results are
 * unpredictable if that limit is exceeded.
 *
 * @note This function may be invoked on empty data (zero length), although that obviously will not add any data.
 *
 * @note If either of the passed pointers is NULL, the results are unpredictable.
 */
void sha_256_write(struct Sha_256 *sha_256, const void *data, size_t len);

/*
 * @brief Conclude a SHA-256 streaming calculation, making the hash value available.
 * @param sha_256 A pointer to a previously initialized SHA-256 structure.
 * @return Pointer to the hash array, where the result is delivered.
 *
 * @note After this function has been invoked, the result is available in the hash buffer that initially was provided. A
 * pointer to the hash value is returned for convenience, but you should feel free to ignore it: it is simply a pointer
 * to the first byte of your initially provided hash array.
 *
 * @note If the passed pointer is NULL, the results are unpredictable.
 *
 * @note Invoking this function for a calculation with no data (the writing function has never been invoked, or it only
 * has been invoked with empty data) is legal. It will calculate the SHA-256 value of the empty string.
 */
uint8_t *sha_256_close(struct Sha_256 *sha_256);

#ifdef __cplusplus
}
#endif

#endif

#define PRIVATE_DTW_SHA_DEFINED_IN_DO_THE_WORLD
#endif  //SHA_256_H

#ifndef PRIVATE_DTW_TYPES_H
#define PRIVATE_DTW_TYPES_H
#ifndef PRIVATE_DTW_STRING_ARRAY_TYPE_H
#define PRIVATE_DTW_STRING_ARRAY_TYPE_H
typedef struct DtwStringArray {
    int size;
    char **strings;
}DtwStringArray;
#endif




#ifndef PRIVATE_DTW_PATH_TYPE_H
#define PRIVATE_DTW_PATH_TYPE_H
typedef struct DtwPath {
    char *original_path_string;
    char *path;
    DtwStringArray *garbage;


}DtwPath;
#endif


#ifndef  PRIVATE_DTW_HASH_TYPE_H
#define PRIVATE_DTW_HASH_TYPE_H
typedef  struct DtwHash{
    char *hash;
}DtwHash;
#endif


#ifndef  PRIVATE_DTW_LOCKED_ELEMENT_TYPE_H
#define PRIVATE_DTW_LOCKED_ELEMENT_TYPE_H
typedef struct {

    char *filename;
    int file_descriptor;


}privateDtwFlockLockedElement;
#endif





#ifndef  PRIVATE_DTW_FLOCK_ARRAY_TYPE_H
#define PRIVATE_DTW_FLOCK_ARRAY_TYPE_H

typedef struct {
    privateDtwFlockLockedElement **elements;
    int size;
}privateDtwFlockArray;
#endif





#ifndef PRIVATE_DTW_FLOCK_LOCKER_TYPE_H
#define PRIVATE_DTW_FLOCK_LOCKER_TYPE_H
typedef struct {
    const char *temp_folder;
    privateDtwFlockArray  *locked_files;
}DtwFlockLocker;
#endif






#ifndef PRIVATE_DTW_MULTIFILE_LOCKER_TYPE_H
#define PRIVATE_DTW_MULTIFILE_LOCKER_TYPE_H

typedef struct {

    int total_checks;
    int process;
    int max_wait;
    int max_lock_time;
    DtwStringArray *locked_elements;


}DtwMultiFileLocker;
#endif








#ifndef PRIVATE_DTW_LOCKER_TYPE_H
#define PRIVATE_DTW_LOCKER_TYPE_H
typedef struct {
#ifdef __linux__
    DtwFlockLocker *locker;
#endif
#ifdef _WIN32
    DtwMultiFileLocker  *locker;
#endif

} DtwLocker;
#endif





#ifndef PRIVATE_DTW_RANDONIZER_TYPE_H
#define PRIVATE_DTW_RANDONIZER_TYPE_H
typedef struct DtwRandonizer{
    long internal_seed;
    long seed;
    long actual_generation;

}DtwRandonizer;
#endif


#ifndef PRIVATE_DTW_ACTION_TRANSACTION_TYPE_H
#define PRIVATE_DTW_ACTION_TRANSACTION_TYPE_H
typedef struct DtwActionTransaction{
    short action_type;
    unsigned  char *content;
    long size;
    bool is_binary;

    char *dest;
    char *source;

}DtwActionTransaction;
#endif


#ifndef PRIVATE_DTW_JSON_TRANSACTION_ERROR_TYPE_H
#define PRIVATE_DTW_JSON_TRANSACTION_ERROR_TYPE_H
typedef struct DtwJsonTransactionError{
    int code;
    char *mensage;
    char *path;


}DtwJsonTransactionError;
#endif





#ifndef PRIVATE_DT_TRANSACTION_TYPE_H
#define PRIVATE_DT_TRANSACTION_TYPE_H

typedef struct DtwTransaction{

    DtwActionTransaction  **actions;
    long size;

}DtwTransaction;
#endif



#ifndef PRIVATE_DTW_JSON_TREE_ERROR_TYPE_H
#define PRIVATE_DTW_JSON_TREE_ERROR_TYPE_H
typedef struct DtwJsonTreeError {
    int code;
    int position;
    const char *menssage;


}DtwJsonTreeError;
#endif


#ifndef PRIVATE_DTW_TREE_PROPS_TYPE_H
#define PRIVATE_DTW_TREE_PROPS_TYPE_H
typedef struct DtwTreeProps{
    int minification;
    int content;
    int path_atributes;
    int hadware_data;
    int content_data;
    int ignored_elements;

}DtwTreeProps;
#endif






#ifndef PRIVATE_DTW_TREE_PART_TYPE_H
#define PRIVATE_DTW_TREE_PART_TYPE_H

typedef struct DtwTreePart{

    DtwPath *path;
    void *owner;
    long content_size;
    long  hardware_content_size;
    bool content_exist_in_hardware;
    bool ignore;
    bool is_binary;
    bool metadata_loaded;
    char *current_sha;
    char * last_modification_in_str;
    long last_modification_time;
    char *hawdware_content_sha;

    unsigned char *content;
    int pending_action;

}DtwTreePart;
#endif





#ifndef PRIVATE_DTW_TRANSACTION_REPORT_TYPE_H
#define PRIVATE_DTW_TRANSACTION_REPORT_TYPE_H
typedef struct DtwTreeTransactionReport{
    DtwStringArray *write;
    DtwStringArray *modify;
    DtwStringArray *remove;

}DtwTreeTransactionReport;
#endif





#ifndef  PRIVATE_DTW_TREE_TYPE_H
#define  PRIVATE_DTW_TREE_TYPE_H
typedef struct  DtwTree{
    int size;
    DtwTreePart **tree_parts;

}DtwTree;
#endif






#ifndef  PRIVATE_DTW_DATABASE_SCHEMA_TYPE_H
#define PRIVATE_DTW_DATABASE_SCHEMA_TYPE_H
typedef struct DtwDatabaseSchema{

    const char *value_name;
    const char *index_name;
    struct DtwSchema **sub_schemas;
    int size;
}DtwDatabaseSchema;
#endif


#ifndef PRIVATE_DTW_SCHEMA_TYPE_H
#define PRIVATE_DTW_SCHEMA_TYPE_H



typedef struct DtwSchema{


    const char *value_name;
    const char *index_name;

    char *name;
    struct DtwSchema **sub_schemas;
    int size;
    DtwStringArray  *primary_keys;
}DtwSchema;

#endif









#ifndef PRIVATE_DTW_ROOT_PROPS_RESOURCE_TYPE_H
#define PRIVATE_DTW_ROOT_PROPS_RESOURCE_TYPE_H
typedef struct {
    DtwTransaction  *transaction;
    DtwRandonizer  *randonizer;
    DtwLocker *locker;
    bool schema_unsafe;
    int error_code;
    char *error_path;
    char *error_message;

}privateDtwResourceRootProps;
#endif









#ifndef PRIVATE_DTW_RESOURCE_TYPE_H
#define PRIVATE_DTW_RESOURCE_TYPE_H

typedef struct DtwResource{

    bool allow_transaction;
    bool use_locker_on_unique_values;


    privateDtwResourceRootProps *root_props;
    struct DtwResource *mother;
    char *name;
    char *path;


    //in the schema struct there is:
    //|/root
    //|/root/values
    //|root/values/element  <-----------------------------|
    //|root/values/element/pk_name ->any(write_point)     |
    //|root/values/element/element_prop ->any(write_point)|
    //|root/index                                         |
    //|root/index/pk_name/pk_sha ->txt  -------------------
    DtwSchema *attached_schema;
    DtwDatabaseSchema *datatabase_schema;
    struct DtwResource *values_resource;
    struct DtwResource *index_resource;
    int schema_type;

    bool loaded;
    bool is_binary;
    bool were_renamed;
    unsigned char *value_any;
    long value_size;

    //cache implementation
    bool cache_sub_resources;
    void *sub_resources;

}DtwResource;



#endif





#ifndef PRIVATE_DTW_RESORCE_ARRAY_TYPE_H
#define PRIVATE_DTW_RESORCE_ARRAY_TYPE_H
typedef struct DtwResourceArray{
    DtwResource **resources;
    long size;

}DtwResourceArray;
#endif







#ifndef PRIVATE_DTW_CJSON_ELEMENT_AND_KEY_TYPE
#define PRIVATE_DTW_CJSON_ELEMENT_AND_KEY_TYPE
typedef  struct{
    char *key;
    bool free_key;
    cJSON *element;
}privateDtw_cJSON_element_and_key;

#endif







#ifndef PRIVATE_DTW_RESOURCE_CJSON_ARRAY_MAP_PROPS
#define PRIVATE_DTW_RESOURCE_CJSON_ARRAY_MAP_PROPS
typedef  struct{
    bool(*filtrage_callback)(DtwResource *item, void *args_filter);
    int (*ordenation_callback)(DtwResource *item1, DtwResource *item2, void *args);
    cJSON *(*callback)(DtwResource *item, void *args);
    void *args;
    int start;
    int qtd;
} DtwResourcecJSONArrayMapProps;
#endif







#ifndef PRIVATE_DTW_RESOURCE_CJSON_OBJECT_MAP_PROPS
#define PRIVATE_DTW_RESOURCE_CJSON_OBJECT_MAP_PROPS
typedef  struct{
    char *(*key_provider_callback)(DtwResource *item,void *args);
    bool free_key;
    bool(*filtrage_callback)(DtwResource *item, void *args_filter);
    int (*ordenation_callback)(DtwResource *item1, DtwResource *item2, void *args);
    cJSON *(*callback)(DtwResource *item, void *args);
    void *args;
    int start;
    int qtd;
} DtwResourcecJSONObjectMapProps;
#endif







#ifndef PRIVATE_DTW_RESOURCE_MAP_ELEMENT_TYPE_H
#define PRIVATE_DTW_RESOURCE_MAP_ELEMENT_TYPE_H

typedef struct {
    void *result;
    void *args;
    DtwResource *current;
    int (*ordenation_callback)(DtwResource *item1, DtwResource *item2, void *args);
}privateDtwResource_map_element;
#endif





#ifndef PRIVATE_DTW_RESOURCE_PRIVATE_MAP_PROPS
#define PRIVATE_DTW_RESOURCE_PRIVATE_MAP_PROPS
    typedef struct {
        void *main_array;
        void(*append)(void *main_array_arg, void *item);
        bool(*filtrage_callback)(DtwResource *item, void *args);
        int (*ordenation_callback)(DtwResource *item1, DtwResource *item2, void *args);
        void *(*callback)(DtwResource *item, void *args);
        void *args;
        int start;
        int qtd;
    }DtwResourceMapProps;
#endif


#ifdef DTW_ALLOW_CHASH


#define DTW_ALLOW_CHASH

#ifndef PRIVATE_DTW_CHASH_ELEMENT_AND_KEY_TYPE
#define PRIVATE_DTW_CHASH_ELEMENT_AND_KEY_TYPE
typedef  struct{
    char *key;
    CHash *element;
    bool free_key;
}privateDtw_CHash_element_and_key;

#endif







#ifndef PRIVATE_DTW_RESOURCE_CHASH_ARRAY_MAP_PROPS
#define PRIVATE_DTW_RESOURCE_CHASH_ARRAY_MAP_PROPS
typedef  struct{
    bool(*filtrage_callback)(DtwResource *item, void *args_filter);
    int (*ordenation_callback)(DtwResource *item1, DtwResource *item2, void *args);
    CHash *(*callback)(DtwResource *item, void *args);
    void *args;
    int start;
    int qtd;
} DtwResourceCHashrrayMapProps;
#endif







#ifndef PRIVATE_DTW_RESOURCE_CHASH_OBJECT_MAP_PROPS
#define PRIVATE_DTW_RESOURCE_CHASH_OBJECT_MAP_PROPS
typedef  struct{
    char *(*key_provider_callback)(DtwResource *item,void *args);
    bool(*filtrage_callback)(DtwResource *item, void *args_filter);
    int (*ordenation_callback)(DtwResource *item1, DtwResource *item2, void *args);
    CHash *(*callback)(DtwResource *item, void *args);
    void *args;
    bool free_key;
    int start;
    int qtd;
} DtwResourceCHashObjectMapProps;
#endif




#endif





#ifndef PRIVATE_DTW_RESOURCE_FOREACH_PROPS_TYPE
#define PRIVATE_DTW_RESOURCE_FOREACH_PROPS_TYPE
typedef struct{
    bool(*filtrage_callback)(DtwResource *item, void *args_filter);
    void(*callback)(DtwResource *item, void *args);
    void *args;
    int start;
    int qtd;
}DtwResourceForeachProps;
#endif





























#ifndef PRIVATE_DTW_RESOURCE_ARRAY_MODULE_TYPE_H
#define PRIVATE_DTW_RESOURCE_ARRAY_MODULE_TYPE_H
typedef struct DtwResourceArrayModule{

    void (*append)(DtwResourceArray *self, DtwResource *element);
    DtwResource * (*get_by_name)(DtwResourceArray *self, const char *name);
    void (*represent)(DtwResourceArray *self);
    void (*free)(DtwResourceArray *self);

}DtwResourceArrayModule;
#endif







#ifndef PRIVATE_DTW_RESOURCE_MODULE_TYPE_H
#define PRIVATE_DTW_RESOURCE_MODULE_TYPE_H
typedef struct DtwResourceModule{

    DtwResource *(*newResource)(const char *path);
    int (*get_error_code)(DtwResource *self);
    bool (*error)(DtwResource *self);


    DtwResourceForeachProps (*create_foreach_props)( void(*callback)(DtwResource *item, void *args));
    void (*each)(DtwResource *self,DtwResourceForeachProps props);
    void (*schema_each)(DtwResource *self,DtwResourceForeachProps props);

    DtwResourceMapProps (*create_map_props)(
        void *main_array,
        void(*append)(void *main_array_arg, void *item),
        void *(*callback)(DtwResource *item, void *args)
    );
    void (*map)(DtwResource *self,DtwResourceMapProps props);
    void (*schema_map)(DtwResource *self,DtwResourceMapProps props);

    DtwResourcecJSONArrayMapProps (*create_cJSONArrayMapProps)(cJSON *(*callback)(DtwResource *item, void *args));
    cJSON *(*map_cJSONArray)(DtwResource *self,DtwResourcecJSONArrayMapProps props);
    cJSON *(*schema_map_cJSONArray)(DtwResource *self,DtwResourcecJSONArrayMapProps props);

    DtwResourcecJSONObjectMapProps (*create_cJSONObjectProps)(
        cJSON *(*callback)(DtwResource *item, void *args),
        char *(*key_provider_callback)(DtwResource *item,void *args)
    );

    cJSON *(*map_cJSONObject)(DtwResource *self,DtwResourcecJSONObjectMapProps props);
    cJSON *(*schema_map_cJSONObject)(DtwResource *self,DtwResourcecJSONObjectMapProps props);


    #ifdef DTW_ALLOW_CHASH
    DtwResourceCHashrrayMapProps  (*create_CHashrrayMapProps)(    CHash *(*callback)(DtwResource *item, void *args));


    CHashArray *(*map_CHashArray)(DtwResource *self,DtwResourceCHashrrayMapProps props);
    CHashArray *(*schema_map_CHashArray)(DtwResource *self,DtwResourceCHashrrayMapProps props);

    DtwResourceCHashObjectMapProps (*createCHashObjectMapProps)(
        CHash *(*callback)(DtwResource *item, void *args),
        char*(*key_provider)(DtwResource *item, void *args_filter)
    );

    CHashObject *(*map_CHashObject)(DtwResource *self,DtwResourceCHashObjectMapProps props);
    CHashObject *(*schema_map_CHashObject)(DtwResource *self,DtwResourceCHashObjectMapProps props);


    #endif

    char * (*get_error_message)(DtwResource *self);
    bool (*is_file)(DtwResource *self);
    void (*destroy_sub_resource)(DtwResource *self, const char *key);
    void (*rename_sub_resource)(DtwResource *self,const char *old_name,const  char *new_name);
    DtwResource * (*sub_resource)(struct DtwResource *self,const  char *format,...);
    unsigned char *(*get_any_from_sub_resource)(DtwResource *self, long *size, bool *is_binary,const char *format,...);
    unsigned char *(*get_binary_from_sub_resource)(DtwResource *self, long *size,const char *format,...);
    char *(*get_string_from_sub_resource)(DtwResource *self,const char *format,...);
    long (*get_long_from_sub_resource)(DtwResource *self,const char *format,...);
    double (*get_double_from_sub_resource)(DtwResource *self,const char *format,...);
    bool (*get_bool_from_sub_resource)(DtwResource *self,const char *format,...);
    void (*set_any_in_sub_resource)(DtwResource *self,const char *key, unsigned char *element, long size,bool is_binary);
    void (*set_binary_in_sub_resource)(DtwResource *self,const char *key, unsigned char *element, long size);
    void (*set_string_in_sub_resource)(DtwResource *self,const char *key,const  char *element);
    void (*set_long_in_sub_resource)(DtwResource *self,const char *key,long element);
    void (*set_double_in_sub_resource)(DtwResource *self,const char *key,double element);
    void (*set_bool_in_sub_resource)( DtwResource *self,const char *key,bool element);
    void (*set_binary_sha)(DtwResource *self, unsigned  char *value, long size);
    void (*set_string_sha)(DtwResource *self,const char *value);
    void (*set_binary_sha_in_sub_resource)(DtwResource *self,const char *key, unsigned  char *value, long size);
    void (*set_string_sha_in_sub_resource)(DtwResource *self,const char *key,const char *value);



    DtwResource * (*new_schema_insertion)(DtwResource *self);
    DtwResource  *(*find_by_name_id)(DtwResource *self, const char *name);
    DtwResource * (*find_by_primary_key_with_binary)(DtwResource *self, const char *primary_key, unsigned  char *value, long size);
    DtwResource * (*find_by_primary_key_with_string)(DtwResource *self, const char *key, const char *value);
    void (*dangerous_remove_schema_prop)(DtwResource*self,const char *prop);
    void (*dangerous_rename_schema_prop)(DtwResource*self,const char *prop,const char *new_name);
    DtwDatabaseSchema * (*newDatabaseSchema)(DtwResource *self);

    char * (*get_error_path)(DtwResource *self);
    DtwResourceArray * (*get_schema_values)(DtwResource *self);


    DtwResource * (*sub_resource_ensuring_not_exist)(DtwResource *self,const  char *format, ...);
    DtwResource * (*sub_resource_next)(DtwResource *self, const char *end_path);
    DtwResource * (*sub_resource_now)(DtwResource *self, const char *end_path);

    DtwResource * (*sub_resource_now_in_unix)(DtwResource *self,const char *end_path);
    DtwResource * (*sub_resource_random)(DtwResource *self,const char *end_path);


    void (*load)(DtwResource *self);

    void (*unload)(DtwResource *self);

    int (*lock)(DtwResource *self);
    void (*unlock)(DtwResource *self);

    void (*destroy)(DtwResource *self);
    void  (*clear_errors)(DtwResource *self);
    unsigned char *(*get_any)(struct DtwResource *self, long *size, bool *is_binary);

    unsigned char *(*get_binary)(struct DtwResource *self, long *size);

    char *(*get_string)(struct DtwResource *self);

    long (*get_long)(struct DtwResource *self);

    double (*get_double)(struct DtwResource *self);

    bool (*get_bool)(struct DtwResource *self);
    void (*set_any)(DtwResource *self, unsigned char *element, long size,bool is_binary);
    void (*set_binary)(DtwResource *self, unsigned char *element, long size);

    void (*set_string)(DtwResource *self,const  char *element);

    void (*set_long)(DtwResource *self,long element);

    void (*set_double)(DtwResource *self,double element);

    void (*set_bool)(DtwResource *self,bool element);



    DtwStringArray *(*list_names)(DtwResource *self);

    long (*size)(DtwResource *self);
    int (*type)(DtwResource *self);

    const char *(*type_in_str)(DtwResource *self);
    void (*commit)(DtwResource *self);

    void (*represent)(DtwResource *self);

    void (*rename)(DtwResource *self,const char *new_name);

    void (*free)(DtwResource *self);
    DtwResourceArray * (*sub_resources)(DtwResource *self);
    DtwResourceArrayModule array;


}DtwResourceModule;

#endif








#ifndef PRIVATE_DTW_ACTION_TRANSACTION_MODULE_TYPE_H
#define PRIVATE_DTW_ACTION_TRANSACTION_MODULE_TYPE_H
typedef struct DtwActionTransactionModule{

    DtwActionTransaction *(*newAction)();

    DtwActionTransaction * (*write_any)(const char *source,unsigned  char *content,long size,bool is_binary);

    DtwActionTransaction * (*move_any)(const char *source, const char *dest);
    DtwActionTransaction * (*move_any_merging)(const char *source, const char *dest);
    DtwActionTransaction * (*copy_any_merging)(const char *source, const char *dest);

    DtwActionTransaction * (*copy_any)(const char *source, const char *dest);

    DtwActionTransaction * (*delete_any)(const char *source);

    short (*convert_action_to_integer)(char *action);

    const char * (*convert_action_to_string)(int action);

    void (*commit)(DtwActionTransaction* self,const char *path);

    void (*represent)(DtwActionTransaction* self);

    void (*free)(DtwActionTransaction* self);

}DtwActionTransactionModule;
#endif



#ifndef PRIVATE_DTW_JSON_TRANSACTION_MODULE_TYPE_H
#define PRIVATE_DTW_JSON_TRANSACTION_MODULE_TYPE_H
typedef struct DtwJsonTransactionErrorModule{
    void (*represent)(struct DtwJsonTransactionError *self);
    void (*free)(struct DtwJsonTransactionError *self);

}DtwJsonTransactionErrorModule;
#endif








#ifndef PRIVATE_DTW_TRANSACTION_MODULE_TYPE_H
#define PRIVATE_DTW_TRANSACTION_MODULE_TYPE_H
typedef struct DtwTransactionModule{
    DtwTransaction *(*newTransaction)();
    DtwTransaction * (*newTransaction_from_json)(cJSON *json_entry);
    DtwTransaction * (*newTransaction_from_json_file)(const char *filename);
    DtwJsonTransactionError * (*validate_json_transaction_file)(const char *filename);

    void (*remove_from_index)(DtwTransaction *self,long index);
    void (*remove_from_source)(DtwTransaction *self,const char *source);
    void (*filter)(DtwTransaction *self,bool (*callback)(DtwActionTransaction *action));

    void (*append_action)(struct DtwTransaction *self,struct DtwActionTransaction  *action);
    void (*write_any)(struct DtwTransaction *self,const char *path,unsigned char *content, long size,bool is_binary);
    void (*write_string)(struct DtwTransaction *self,const char *path,const char *content);

    void (*write_long)(struct DtwTransaction *self,const char *path,long value);
    void (*write_bool)(struct DtwTransaction *self,const char *path,bool value);
    void (*write_double)(struct DtwTransaction *self,const char *path,double value);

    void (*move_any_merging)(struct DtwTransaction *self,const char *source,const char *dest);
    void (*copy_any_merging)(struct DtwTransaction *self,const char *source,const char *dest);


    void (*move_any)(struct DtwTransaction *self,const char *source,const char *dest);
    void (*copy_any)(struct DtwTransaction *self,const char *source,const char *dest);
    void (*delete_any)(struct DtwTransaction *self,const char *source);

    cJSON *(*dumps_transaction_to_json)(struct DtwTransaction *self);
    void (*dumps_transaction_to_json_file)(struct DtwTransaction *self,const char *filename);

    void (*commit)(struct DtwTransaction *self,const char *source);
    void (*represent)(struct DtwTransaction *self);
    void (*free)(struct DtwTransaction *self);

    DtwActionTransactionModule action;
    DtwJsonTransactionErrorModule json_error;


}DtwTransactionModule;
#endif






#ifndef PRIVATE_DTW_JSON_TREE_ERROR_MODULE_TYPE_H
#define PRIVATE_DTW_JSON_TREE_ERROR_MODULE_TYPE_H
typedef struct DtwJsonTreeErrorModule{

    DtwJsonTreeError * (*validate_json_tree_by_cJSON)(cJSON *json_tree);
    DtwJsonTreeError * (*validate_json_tree_by_content)(const char *content);
    void (*free)(struct DtwJsonTreeError *self);
    void (*represent)(struct DtwJsonTreeError *self);

}DtwJsonTreeErrorModule;
#endif


#ifndef PRIVATE_DTW_TRANSACTION_REPORT_MODULE_TYPE_H
#define PRIVATE_DTW_TRANSACTION_REPORT_MODULE_TYPE_H
typedef struct  DtwTreeTransactionReportModule{

    void (*represent)(struct DtwTreeTransactionReport *report);
    void (*free)(struct DtwTreeTransactionReport *report);

}DtwTreeTransactionReportModule;
#endif





#ifndef PRIVATE_DTW_TREE_PART_MODULE_TYPE_H
#define PRIVATE_DTW_TREE_PART_MODULE_TYPE_H

typedef struct DtwTreePartModule{

    DtwTreePart  *(*newPart)(const char *path, DtwTreeProps props);
    DtwTreePart  *(*newPartEmpty)(const char *path);
    DtwTreePart * (*newPartLoading)(const char *path);

    char *(*get_content_string_by_reference)(struct DtwTreePart *self);
    unsigned char *(*get_content_binary_by_reference)(struct DtwTreePart *self);

    char *(*get_content_sha)(struct DtwTreePart *self);
    void (*set_any_content)(struct DtwTreePart *self,unsigned char *content,long content_size,bool is_binary);
    void (*set_string_content)(struct DtwTreePart *self,const char *content);
    void (*set_binary_content)(struct DtwTreePart *self,unsigned char *content,long content_size);
    void (*load_content_from_hardware)(struct DtwTreePart *self);
    void (*free_content)(struct DtwTreePart *self);
    void(*represent)(struct DtwTreePart *self);

    bool(*hardware_remove)(struct DtwTreePart *self, int transaction);
    bool(*hardware_write)(struct DtwTreePart *self, int transaction);
    bool(*hardware_modify)(struct DtwTreePart *self, int transaction);
    bool(*hardware_commit)(struct DtwTreePart *self);

    void (*free)(struct DtwTreePart *self);
    struct DtwTreePart *(*self_copy)(struct DtwTreePart *self);
}DtwTreePartModule;
#endif











#ifndef PRIVATE_DTW_TREE_MODULE_TYPE_H
#define PRIVATE_DTW_TREE_MODULE_TYPE_H
typedef struct DtwTreeModule{

    DtwTree  *(*newTree)();
    void (*add_tree_part_by_copy)(
             DtwTree *self,
             DtwTreePart *tree_part
    );

    void (*remove_tree_part)(
             DtwTree *self,
            int position
    );

    void (*add_tree_part_getting_owenership)(
             DtwTree *self,
             DtwTreePart *tree_part
    );
    void (*add_tree_part_referencing)(
            DtwTree *self,
            DtwTreePart *tree_part
    );
        void (*add_tree_parts_from_string_array)(
            struct DtwTree *self,
            struct DtwStringArray *paths,
            DtwTreeProps props
    );

    struct DtwTree *(*get_sub_tree)(
            struct DtwTree *self,
            const char *path,
            bool copy_content
    );

    void (*add_tree_from_hardware)(
            struct DtwTree *self,
            const char *path,
            DtwTreeProps props
    );
    //Listage Functions

    DtwTreePart *(*find_tree_part_by_function)(
            struct DtwTree *self,
            bool (*caller)(struct  DtwTreePart *part,void *args),
            void *args
    );

    DtwTree *(*filter)(
            struct DtwTree *self,
            bool (*caller)(struct  DtwTreePart *part)
    );

    DtwTree *(*map)(
            struct DtwTree *self,
            struct  DtwTreePart*(*caller)(struct  DtwTreePart *part)
    );


    DtwStringArray * (*list_files)(struct DtwTree *self, const char *path,bool concat_path);
    DtwStringArray * (*list_dirs)(struct DtwTree *self, const char *path,bool concat_path);
    DtwStringArray * (*list_all)(struct DtwTree *self, const char *path,bool concat_path);

    DtwStringArray * (*list_files_recursively)(struct DtwTree *self, const char *path,bool concat_path);
    DtwStringArray * (*list_dirs_recursively)(struct DtwTree *self, const char *path,bool concat_path);
    DtwStringArray * (*list_all_recursively)(struct DtwTree *self, const char *path,bool concat_path);


    struct DtwTreePart *(*find_tree_part_by_name)( struct DtwTree *self,const char *name);
    struct DtwTreePart *(*find_tree_part_by_path)(   struct DtwTree *self,const char *path);


    struct DtwTreeTransactionReport * (*create_report)(struct DtwTree *self);

    bool (*loads_json_tree)(
            struct DtwTree *self,
            const char *content
    );


    bool (*loads_json_tree_from_file)(
            struct DtwTree *self,
            const char *path
    );

    char *(*dumps_json_tree)(
            struct DtwTree *self,
            DtwTreeProps props
    );

    void (*dumps_json_tree_to_file)(
            struct DtwTree *self,
            const char *path,
            DtwTreeProps  props
    );

    void (*represent)(struct DtwTree *self);
    void (*insecure_hardware_remove_tree)(struct DtwTree *self);
    void (*insecure_hardware_write_tree)(struct DtwTree *self);
    void (*hardware_commit_tree)(struct DtwTree *self);
    void (*free)(struct DtwTree *self);

    DtwTreeTransactionReportModule transaction_report;

    DtwTreePartModule part;
    DtwJsonTreeErrorModule json_error;

}DtwTreeModule;
#endif







#ifndef PRIVATE_DTW_DATABASE_SCHEMA_MODULE_TYPE_H
#define PRIVATE_DTW_DATABASE_SCHEMA_MODULE_TYPE_H
typedef struct {
    DtwSchema * (*sub_schema)(DtwDatabaseSchema *self,const char *name);
}DtwDatabaseSchemaModule;
#endif




#ifndef PRIVATE_DTW_SCHEMA_MODULE_TYPE_H
#define PRIVATE_DTW_SCHEMA_MODULE_TYPE_H
typedef struct {
    void (*add_primary_key)(DtwSchema *self, const char *primary_key);
    DtwSchema * (*sub_schema)(DtwSchema *self,const char *name);
}DtwSchemaModule;
#endif






#ifndef PRIVATE_DTW_HASH_MODULE_TYPE_H
#define PRIVATE_DTW_HASH_MODULE_TYPE_H

typedef struct DtwHashModule{
    DtwHash * (*newHash)();
    bool  (*digest_any)(DtwHash *self,unsigned char *content,long size);
    bool (*digest_string)(DtwHash * self, const char *content);
    void (*digest_long)(DtwHash * self,long content);
    void (*digest_double)(DtwHash * self,double content);
    void (*digest_bool)(DtwHash * self,bool content);
    bool  (*digest_file)(DtwHash * self, const char *path);
    bool  (*digest_entity_last_modification)(DtwHash * self, const char *path);
    bool (*digest_string_array)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_last_modifications)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_last_modifications_adding_name)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_content)(DtwHash *self,DtwStringArray *element);
    bool (*digest_string_array_content_adding_name)(DtwHash *self,DtwStringArray *element);
    bool (*digest_folder_by_last_modification)(DtwHash *self,const char *path);
    bool (*digest_folder_by_content)(DtwHash *self,const char *path);
    void  (*free)(DtwHash *self);

}DtwHashModule;
#endif





#ifndef PRIVATE_DTW_LOCKER_MODULE_TYPE_H
#define PRIVATE_DTW_LOCKER_MODULE_TYPE_H
typedef struct DtwLockerModule{
    DtwLocker * (*newLocker)();
    int (*lock)(DtwLocker *self, const  char *element);
    void (*unlock)(DtwLocker *self, const  char *element);
    void (*represemt)(DtwLocker *self);
    void (*free)(DtwLocker *self);

}DtwLockerModule;

#endif






#ifndef PRIVATE_DTW_PATH_MODULE_TYPE_H
#define PRIVATE_DTW_PATH_MODULE_TYPE_H
typedef struct DtwPathModule{
    //Getters

    DtwPath * (*newPath)(const char *path);
    bool  (*changed)(struct DtwPath *self);
    char *(*get_full_name) (struct DtwPath *self);
    char *(*get_name) (struct DtwPath *self);
    char *(*get_extension) (struct DtwPath *self);

    char *(*get_path) (struct DtwPath *self);
    char *(*get_dir) (struct DtwPath *self);

    int (*get_total_dirs)(DtwPath *self);
    char *(*get_sub_dirs_from_index)(DtwPath *self, int start,int end);
    void (*insert_dir_at_index)(DtwPath *self,int index,const char *dir);
    void (*remove_sub_dirs_at_index)(DtwPath *self,int start,int end);
    void (*insert_dir_after)(DtwPath *self,const char *str,const char *dir);
    void (*insert_dir_before)(DtwPath *self,const char *str,const char *dir);
    void (*replace_dirs)(DtwPath *self,const char *str,const char *dir);
    void (*remove_sub_dirs_at)(DtwPath *self,const char *str);


    //Setters
    void (*set_extension) (struct DtwPath *self, const char *extension);
    void (*set_name) (struct DtwPath *self, const char *name);
    void (*set_dir) (struct DtwPath *self, const char *path);
    void (*set_full_name) (struct DtwPath *self, const char *full_name);
    void (*set_path) (struct DtwPath *self, const char *target_path);

    void (*add_start_dir)(struct DtwPath *self, const char *start_dir);
    void (*add_end_dir)(struct DtwPath *self, const char *end_dir);

    void (*represent)(struct DtwPath *self);
    void (*free) (struct DtwPath *self);

}DtwPathModule;
#endif






#ifndef PRIVATE_DTW_RANDONIZER_MODULE_TYPE_H
#define PRIVATE_DTW_RANDONIZER_MODULE_TYPE_H
typedef struct  DtwRandonizerModule{
    DtwRandonizer * (*newRandonizer)();
    int (*generate_num)(DtwRandonizer *self,int max);
    char * (*generate_token)(DtwRandonizer*self, int size);
    void (*free)(DtwRandonizer *self);
}DtwRandonizerModule;
#endif




#ifndef PRIVATE_DTW_STRING_ARRAY_MODULE_TYPE_H
#define PRIVATE_DTW_STRING_ARRAY_MODULE_TYPE_H
typedef struct DtwStringArrayModule{
    DtwStringArray *(*newStringArray)();

    void (*set_value)(struct DtwStringArray *self,int index,const char *value);

    void (*append)(struct DtwStringArray *self,const char *string);

    void (*pop)(struct DtwStringArray *self, int position);

    void (*merge)(struct DtwStringArray *self, struct DtwStringArray *other);

    void (*represent)(struct DtwStringArray *self);

    int (*find_position)(struct DtwStringArray *self,const char *string);

    void (*sort)(struct DtwStringArray *self);

    void (*free)(struct DtwStringArray *self);


}DtwStringArrayModule;
#endif























#ifndef PRIVATE_DTW_NAMESPACE_MODULE_TYPE_H
#define PRIVATE_DTW_NAMESPACE_MODULE_TYPE_H
typedef struct DtwNamespace{
    //IO
    void (*create_dir_recursively)(const char *path);

    bool (*remove_any)(const char* path);

    char *(*get_current_dir)();

    unsigned char *(*load_any_content)(const char * path,long *size,bool *is_binary);

    char *(*get_absolute_path)(const char *path);

    char *(*load_string_file_content)(const char * path);

    unsigned char *(*load_binary_content)(const char * path,long *size);

    bool (*write_any_content)(const char *path,unsigned  char *content,long size);

    bool (*write_string_file_content)(const char *path,const char *content);

    int (*entity_type)(const char *path);

    int (*complex_entity_type)(const char *path);

    const char *(*convert_entity)(int entity_type);

    bool (*copy_any)(const char* src_path,const  char* dest_path,bool merge);

    bool (*move_any)(const char* src_path, const char* dest_path,bool merge);

    //numeral io

    long (*load_long_file_content)(const char * path);

    double (*load_double_file_content)(const char * path);

    bool (*load_bool_file_content)(const char * path);



    void (*write_long_file_content)(const char *path, long value);

    void (*write_bool_file_content)(const char *path, bool value);

    void (*write_double_file_content)(const char *path,double value);



    //listage

    DtwStringArray * (*list_files)(const char *path, bool concat_path);
    DtwStringArray * (*list_dirs)(const char *path, bool concat_path);

    DtwStringArray *  (*list_all)(const char *path,  bool concat_path);
    DtwStringArray * (*list_dirs_recursively)(const char *path,bool concat_path);
    DtwStringArray *  (*list_files_recursively)(const char *path,bool concat_path);
    DtwStringArray * (*list_all_recursively)(const char *path,bool concat_path);


    //extras

    char * (*generate_sha_from_file)(const char *path);

    char * (*generate_sha_from_string)(const char *string);

    char * (*generate_sha_from_any)(void *anything , long size);

    long int (*get_entity_last_motification_in_unix)(const char *path);

    char * (*convert_unix_time_to_string)(long int unix_time);

    char * (*get_entity_last_motification_in_string)(const char *path);

    char *(*concat_path)(const char *path1, const char *path2);


    //base64

    char *(*base64_encode)(unsigned char *data, long input_length);

    unsigned char *(*base64_decode)(const char *data, long *output_length);

    char *(*convert_binary_file_to_base64)(const char *path);
    //string array

    DtwStringArrayModule string_array;

    DtwPathModule path;

    DtwLockerModule locker;

    DtwSchemaModule schema;
    DtwDatabaseSchemaModule database_schema;
    DtwTreeModule tree;
    DtwHashModule  hash;
    DtwTransactionModule transaction;

    DtwResourceModule resource;
    DtwRandonizerModule randonizer;

}DtwNamespace;
#endif





#endif


//# include "../../extras/CHashManipulator.h"














// End the structure with a semicolon
int  DtwStringArray_find_position( DtwStringArray *self, const char *string);


void DtwStringArray_append_getting_ownership( DtwStringArray *self, char *string);

void DtwStringArray_append( DtwStringArray *self, const char *string);

void DtwStringArray_pop( DtwStringArray *self, int position);

void DtwStringArray_merge( DtwStringArray *self,  DtwStringArray *other);
void DtwStringArray_represent( DtwStringArray *self);
void DtwStringArray_free( DtwStringArray *self);

int private_dtw_string_cmp(const void *a, const void *b);
void DtwStringArray_sort( DtwStringArray *self);

void DtwStringArray_set_value( DtwStringArray *self, int index, const char *value);

 DtwStringArray * newDtwStringArray();

char * privateDtwStringArray_append_if_not_included(DtwStringArray *self,char *value);

DtwStringArray * DtwStringArray_clone(DtwStringArray *self);





char * calc_sha_256_returning_string(const void *input, size_t len);

void calc_sha_256_from_string(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *input);

int calc_sha_256_from_file(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *filename);

char * calc_sha_256_from_string_returning_string(const char *input);

char * calc_sha_256_from_file_returning_string(const char *filename);

char * sha256_open_file(const char *filename, int *size);





char *dtw_base64_encode(unsigned char *data, long input_length);


unsigned char *dtw_base64_decode(const char *data, long *output_length);


char *dtw_convert_binary_file_to_base64(const char *path);









DtwRandonizer * newDtwRandonizer();

int DtwRandonizer_generate_num(DtwRandonizer *self,int max);

char * DtwRandonizer_generate_token(struct DtwRandonizer*self, int size);
void DtwRandonizer_free(struct DtwRandonizer *self);





char * dtw_generate_sha_from_file(const char *path);
char * dtw_generate_sha_from_string(const char *string);
char * dtw_generate_sha_from_any(void *anything , long size);

long int dtw_get_entity_last_motification_in_unix(const char *path);
char * dtw_convert_unix_time_to_string(long int unix_time);
char * dtw_get_entity_last_motification_in_string(const char *path);
const char * private_dtw_convert_action_to_string(short action);
short private_dtw_convert_string_to_action(const char *action);
void private_dtw_add_end_bar_to_dirs_string_array(struct DtwStringArray * dirs);

long private_dtw_convert_index(long index,long size);


long dtw_get_time();






char *dtw_concat_path(const char *path1, const char *path2);

DtwStringArray* private_dtw_remove_start_path(struct DtwStringArray *paths,const char *path_to_remove);

char *private_dtw_format_path(const char *path);

void private_dtw_remove_double_bars_from_string_array(struct DtwStringArray*path);

char * private_dtw_format_vaarg(const char *expresion, va_list args);

char *private_dtw_realoc_formatting(char *ptr,const char *format,...);

char *private_dtw_formatt(const char *format,...);

char * private_dtw_sub_str(const char *str, long start,long end);

bool dtw_is_string_at_point(
        const char *str,
        long str_size,
        const char *target,
        long target_size,
        long target_point
);

long  dtw_index_of_string(const char *str,const char *element);

bool dtw_starts_with(const char *string, const char *prefix);
bool dtw_ends_with(const char *string, const char *suffix);
char *private_dtw_replace_string_once(const char *target, const char *old_element, const char *new_element);
char* dtw_replace_string(const char *target, const char *old_element, const char *new_element);

char *private_dtw_change_beginning_of_string(const char *target,int start_element_to_remove_size, const char *new_element);

double private_dtw_convert_string_to_number(const char *num, bool *its_a_number);




void dtw_create_dir_recursively(const char *path);

bool dtw_remove_any(const char* path);

char *dtw_get_current_dir();

long dtw_get_total_itens_of_dir(const char *path);

unsigned char *dtw_load_any_content(const char * path,long *size,bool *is_binary);

char *dtw_get_absolute_path(const char *path);

char *dtw_load_string_file_content(const char * path);

unsigned char *dtw_load_binary_content(const char * path,long *size);


bool dtw_write_any_content(const char *path,unsigned  char *content,long size);
bool dtw_write_string_file_content(const char *path,const char *content);



int dtw_entity_type(const char *path);



int dtw_complex_entity_type(const char *path);

const char *dtw_convert_entity(int entity_type);


bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge);



bool dtw_move_any(const char* src_path, const char* dest_path,bool merge);






long dtw_load_long_file_content_setting_error(const char *path,int *error);

long dtw_load_long_file_content(const char * path);

double dtw_load_double_file_content_setting_error(const char * path, int *error);

double dtw_load_double_file_content(const char * path);

bool dtw_load_bool_file_content_setting_error(const char * path, int *error);


bool dtw_load_bool_file_content(const char * path);


void dtw_write_long_file_content(const char *path, long value);

void dtw_write_bool_file_content(const char *path, bool value);

void dtw_write_double_file_content(const char *path,double value);






 DtwStringArray * dtw_list_files(const char *path, bool concat_path);
DtwStringArray * dtw_list_dirs(const char *path, bool concat_path);

DtwStringArray *  dtw_list_all(const char *path,  bool concat_path);





#ifdef __linux__

bool private_dtw_verify_if_add(const int expected_type, int d_type);
bool private_dtw_verify_if_skip(struct dirent *entry);

#endif


#ifdef _WIN32

bool private_dtw_verify_if_add(const int expected_type, WIN32_FIND_DATAA entry);
bool private_dtw_verify_if_skip(WIN32_FIND_DATAA *entry);
#endif



struct DtwStringArray * dtw_list_basic(const char *path,int expected_type,bool concat_path);





 DtwStringArray * dtw_list_dirs_recursively(const char *path,bool concat_path);


 DtwStringArray *  dtw_list_files_recursively(const char *path,bool concat_path);


 DtwStringArray * dtw_list_all_recursively(const char *path,bool concat_path);








DtwPath * newDtwPath(const char *path);

bool DtwPath_changed(struct DtwPath *self);




void DtwPath_represent(struct DtwPath *self);



void DtwPath_free(struct DtwPath *self);






char * DtwPath_get_name(DtwPath *self);

char * DtwPath_get_extension(struct DtwPath *self);


char * DtwPath_get_full_name(struct DtwPath *self);


char * DtwPath_get_dir(struct DtwPath *self);


char * DtwPath_get_path(struct DtwPath *self);




void DtwPath_set_extension(struct DtwPath *self, const char *extension);


void DtwPath_set_name(struct DtwPath * self, const char * name);


void DtwPath_set_full_name(struct DtwPath * self, const char * full_name);


void DtwPath_set_dir(struct DtwPath *self, const char *dir);



void DtwPath_set_path(struct DtwPath *self, const char *target_path);


void DtwPath_add_start_dir(struct DtwPath *self, const char *start_dir);


void DtwPath_add_end_dir(struct DtwPath *self, const char *end_dir);


void DtwPath_replace_dirs(DtwPath *self,const char *str,const char *dir);





int DtwPath_get_total_dirs(DtwPath *self);

char *DtwPath_get_sub_dirs_from_index(DtwPath *self, int start, int end);


int private_dtw_count_dirs_before(const char *dirs,int index);

void DtwPath_insert_dir_at_index(DtwPath *self, int index, const char *dir);

void DtwPath_remove_sub_dirs_at_index(DtwPath *self, int start, int end);





void DtwPath_insert_dir_after(DtwPath *self,const char *str,const char *dir);


void DtwPath_insert_dir_before(DtwPath *self,const char *str,const char *dir);


void DtwPath_remove_sub_dirs_at(DtwPath *self,const char *str);









DtwTreeProps DtwTreeProps_format_props(DtwTreeProps props);







DtwJsonTreeError * newDtwJsonError();

DtwJsonTreeError * DtwJsonTreeError_validate_json_tree_by_cJSON(cJSON *json_tree);

DtwJsonTreeError * DtwJsonTreeError_validate_json_tree_by_content(const char *content);

void DtwJsonTreeError_represent(struct DtwJsonTreeError *self);

void DtwJsonTreeError_free(struct DtwJsonTreeError *self);




struct DtwTreeTransactionReport * newDtwTreeTransactionReport();
void  DtwTreeTransactionReport_represent(struct DtwTreeTransactionReport *report);
void  DtwTreeTransactionReport_free(struct DtwTreeTransactionReport *report);





void private_DtwTreePart_set_last_modification(DtwTreePart *self,long last_modification);

char *DtwTreePart_get_content_string_by_reference( DtwTreePart *self);
unsigned char *DtwTreePart_get_content_binary_by_reference( DtwTreePart *self);
char *DtwTreePart_get_content_sha( DtwTreePart *self);
void DtwTreePart_set_any_content( DtwTreePart *self, unsigned char *content, long content_size, bool is_binary);
void DtwTreePart_set_string_content( DtwTreePart *self, const char *content);
void DtwTreePart_set_binary_content( DtwTreePart *self, unsigned char *content, long content_size);
void DtwTreePart_load_content_from_hardware( DtwTreePart *self);
void DtwTreePart_free_content( DtwTreePart *self);
void DtwTreePart_represent( DtwTreePart *self);

bool DtwTreePart_hardware_remove( DtwTreePart *self,int transaction);
bool DtwTreePart_hardware_write( DtwTreePart *self,int transaction);
bool DtwTreePart_hardware_modify( DtwTreePart *self,int transaction);


bool DtwTreePart_hardware_commit(struct DtwTreePart *self);

void DtwTreePart_free(struct DtwTreePart *self);
struct DtwTreePart * DtwTreePart_self_copy(struct DtwTreePart *self);

struct DtwTreePart * newDtwTreePart(const char *path, DtwTreeProps props);
struct DtwTreePart * newDtwTreePartEmpty(const char *path);
struct DtwTreePart * newDtwTreePartLoading(const char *path);








 DtwTree *DtwTree_get_sub_tree(
     DtwTree *self,
    const char *path,
    bool copy_content
);

 DtwTreePart *DtwTree_find_tree_part_by_function(
     DtwTree *self,
     bool (*caller)(  DtwTreePart *part,void *args),
     void *args
 );


 DtwTree *DtwTree_map(DtwTree *self, DtwTreePart* (*caller)( DtwTreePart *part));


 DtwTree *DtwTree_filter(DtwTree *self,bool (*caller)(struct  DtwTreePart *part));


 DtwTreePart *DtwTree_find_tree_part_by_name( DtwTree *self, const char *name);
 DtwTreePart *DtwTree_find_tree_part_by_path( DtwTree *self, const char *path);

//listages
 DtwStringArray *DtwTree_list_files( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_dirs( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_all( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_files_recursively( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_dirs_recursively( DtwTree *self, const char *path,bool concat_path);

 DtwStringArray *DtwTree_list_all_recursively( DtwTree *self, const char *path,bool concat_path);


void DtwTree_remove_tree_part( DtwTree *self, int position);

void DtwTree_add_tree_part_copy( DtwTree *self,  DtwTreePart *tree_part);

void DtwTree_add_tree_part_getting_onwership( DtwTree *self,  DtwTreePart *tree_part);

void DtwTree_add_tree_part_referencing( DtwTree *self,  DtwTreePart *tree_part);

void DtwTree_free( DtwTree *self);
void DtwTree_represent( DtwTree *self);

void DtwTree_add_tree_parts_from_string_array(DtwTree *self,DtwStringArray *paths,DtwTreeProps props);

void DtwTree_add_tree_from_hardware(DtwTree *self,const char *path,DtwTreeProps props);

 DtwTreeTransactionReport * DtwTree_create_report( DtwTree *self);



void DtwTree_insecure_hardware_remove_tree( DtwTree *self);

void DtwTree_insecure_hardware_write_tree( DtwTree *self);

void DtwTree_hardware_commit_tree( DtwTree *self);

bool DtwTree_loads_json_tree( DtwTree *self, const char *content);

bool DtwTree_loads_json_tree_from_file( DtwTree *self, const char *path);

char * DtwTree_dumps_tree_json(DtwTree *self,DtwTreeProps  props);

void DtwTree_dumps_tree_json_to_file(DtwTree *self,const char *path,DtwTreeProps  props);

  DtwTree * newDtwTree();








DtwMultiFileLocker *newDtwMultiFileLocker();

int DtwMultiFIleLocker_lock(DtwMultiFileLocker *self, const  char *element);

void DtwMultifileLocker_unlock(DtwMultiFileLocker *self, const  char *element);

void DtwMultiFileLocker_represemt(DtwMultiFileLocker *self);

void DtwMultiFileLocker_free(DtwMultiFileLocker *self);


#ifdef __linux__




privateDtwFlockLockedElement * private_new_privateDtwFlockLockedElement(const char *filename, int file_descriptor);

void privateDtwFlockLockedElement_represent(privateDtwFlockLockedElement *self);

void privateDtwFlockLockedElement_free(privateDtwFlockLockedElement *self);









privateDtwFlockArray * private_new_privateFlockArray();

int  privateDtwFlockArray_index_of(privateDtwFlockArray *self, const char *filename);

void privateDtwFlockArray_append(privateDtwFlockArray *self, const char *filename, int file_descriptor);

void privateDtwFlockArray_destroy_by_index(privateDtwFlockArray *self, int position);

void privateDtwFlockArray_represent(privateDtwFlockArray *self);

void privateDtwFlockArray_free(privateDtwFlockArray *self);










DtwFlockLocker * newFlockLocker();

void private_FlockLocker_unlock_by_index(DtwFlockLocker *self, int index);

void DtwFlockLocker_unlock(DtwFlockLocker *self, const char *filename);

int DtwFlockLocker_lock(DtwFlockLocker *self, const char *filename);

void  DtwFlockLocker_represent(DtwFlockLocker *self);

void  DtwFlockLocker_free(DtwFlockLocker *self);



#endif




DtwLocker *newDtwLocker();

int DtwLocker_lock(DtwLocker *self, const  char *element);

void DtwLocker_unlock(DtwLocker *self, const  char *element);

void DtwLocker_represemt(DtwLocker *self);

void DtwLocker_free(DtwLocker *self);







DtwJsonTransactionError * private_new_DtwJsonTransactionError( int code,const char *mensage,const  char *path);

void DtwJsonTransactionError_represent(struct DtwJsonTransactionError *self);

void DtwJsonTransactionError_prepend_path(struct DtwJsonTransactionError *self,char *path);

void DtwJsonTransactionError_free(struct DtwJsonTransactionError *self);





DtwActionTransaction *newDtwActionTransaction();

DtwJsonTransactionError * private_dtw_validate_json_action_transaction(cJSON *json_obj);


DtwActionTransaction * private_DtwActionTransaction_parse_json_object(cJSON *json_obj);


DtwActionTransaction * DtwActionTransaction_write_any(const char *source,unsigned  char *content,long size,bool is_binary);

DtwActionTransaction * DtwActionTransaction_move_any(const char *source, const char *dest);

DtwActionTransaction * DtwActionTransaction_copy_any(const char *source, const char *dest);

DtwActionTransaction * DtwActionTransaction_move_any_merging(const char *source, const char *dest);

DtwActionTransaction * DtwActionTransaction_copy_any_merging(const char *source, const char *dest);

DtwActionTransaction * DtwActionTransaction_delete_any(const char *source);

short DtwActionTransaction_convert_action_to_integer(char *action);


const char * DtwActionTransaction_convert_action_to_string(int action);


cJSON *  private_DtwActionTransaction_create_json_object(DtwActionTransaction* self);


void DtwActionTransaction_commit(DtwActionTransaction* self,const char *path);

void DtwActionTransaction_represent(DtwActionTransaction* self);

void DtwActionTransaction_free(DtwActionTransaction* self);





DtwTransaction * newDtwTransaction();

DtwTransaction * newDtwTransaction_from_json(cJSON *json_entry);

DtwJsonTransactionError * dtw_validate_json_transaction(cJSON *json_entry);

DtwJsonTransactionError * dtw_validate_json_transaction_file(const char *filename);


DtwTransaction * newDtwTransaction_from_json_file(const char *filename);

void DtwTransaction_remove_from_index(DtwTransaction *self,long index);

void DtwTransaction_remove_from_source(DtwTransaction *self,const char *source);

void DtwTransaction_filter(DtwTransaction *self,bool (*callback)(DtwActionTransaction *action));

void DtwTransaction_append_action(struct DtwTransaction *self,struct DtwActionTransaction  *action);

void DtwTransaction_write_any(struct DtwTransaction *self,const char *path,unsigned char *content, long size,bool is_binary);

void DtwTransaction_write_string(struct DtwTransaction *self,const char *path,const char *content);

void DtwTransaction_write_long(struct DtwTransaction *self,const char *path,long value);

void DtwTransaction_write_bool(struct DtwTransaction *self,const char *path,bool value);

void DtwTransaction_write_double(struct DtwTransaction *self,const char *path,double value);

void DtwTransaction_move_any(struct DtwTransaction *self,const char *source,const char *dest);

void DtwTransaction_move_any_merging(struct DtwTransaction *self,const char *source,const char *dest);

void DtwTransaction_copy_any_merging(struct DtwTransaction *self,const char *source,const char *dest);

void DtwTransaction_copy_any(struct DtwTransaction *self,const char *source,const char *dest);

void DtwTransaction_delete_any(struct DtwTransaction *self,const char *source);

cJSON * DtwTransaction_dumps_to_json(struct DtwTransaction *self);

void DtwTransaction_dumps_to_json_file(struct DtwTransaction *self,const char *filename);

void DtwTransaction_commit(struct DtwTransaction *self,const char *path);

void DtwTransaction_represent(struct DtwTransaction *self);


void DtwTransaction_free(struct DtwTransaction *self);








privateDtwResourceRootProps *private_newDtwResourceRootProps();


void privateDtwResourceRootProps_free(privateDtwResourceRootProps *self);






DtwSchema *private_newDtwSchema(const char *name);

DtwSchema * privateDtwSchema_get_sub_schema(DtwSchema *self,const char *name);


DtwSchema * (DtwSchema_new_subSchema)(DtwSchema *self,const char *name);

void DtwSchema_add_primary_key(DtwSchema *self,const char *name);

void private_newDtwSchema_free(DtwSchema *self);









DtwDatabaseSchema *private_newDtwDtatabaseSchema();

DtwSchema * privateDtwDtatabaseSchema_get_sub_schema(DtwDatabaseSchema *self,const char *name);

DtwSchema * DtwDtatabaseSchema_new_subSchema(DtwDatabaseSchema *self,const char *name);

void private_new_DtwDtatabaseSchema_free(DtwDatabaseSchema *self);






DtwResource *new_DtwResource(const char *path);

DtwResource * DtwResource_sub_resource(DtwResource *self,const  char *format, ...);

DtwResource * DtwResource_sub_resource_ensuring_not_exist(DtwResource *self,const  char *format, ...);

void DtwResource_free(DtwResource *self);






DtwResource * DtwResource_sub_resource_next(DtwResource *self, const char *end_path);


DtwResource * DtwResource_sub_resource_now(DtwResource *self, const char *end_path);

DtwResource * DtwResource_sub_resource_now_in_unix(DtwResource *self, const char *end_path);

DtwResource * DtwResource_sub_resource_random(DtwResource *self, const char *end_path);





void private_DtwResurce_destroy_primary_key(DtwResource *self);


void private_DtwResource_destroy_all_primary_keys(DtwResource *self);

void DtwResource_destroy(DtwResource *self);


void DtwResource_destroy_sub_resource(DtwResource *self, const char *key);







bool DtwResource_error(DtwResource *self);

int DtwResource_get_error_code(DtwResource *self);


char * DtwResource_get_error_message(DtwResource *self);

char * DtwResource_get_error_path(DtwResource *self);

void  DtwResource_clear_errors(DtwResource *self);


void  private_DtwResource_raise_error(DtwResource *self, int error_code, const char *format,...);

void DtwResource_rename(DtwResource *self,const char *new_name);

void DtwResource_rename_sub_resource(DtwResource *self,const char *old_name,const  char *new_name);

int DtwResource_lock(DtwResource *self);

void DtwResource_unlock(DtwResource *self);


void DtwResource_commit(DtwResource *self);

long DtwResource_size(DtwResource *self);



DtwStringArray *DtwResource_list_names(DtwResource *self);

int DtwResource_type(DtwResource *self);

bool DtwResource_is_file(DtwResource *self);


const char * DtwResource_type_in_str(DtwResource *self);

void DtwResource_represent(DtwResource *self);





unsigned char *DtwResource_get_any(DtwResource *self, long *size, bool *is_binary);


unsigned char *DtwResource_get_any_from_sub_resource(DtwResource *self, long *size, bool *is_binary,const char *format,...);

unsigned char *DtwResource_get_binary(DtwResource *self, long *size);

unsigned char *DtwResource_get_binary_from_sub_resource(DtwResource *self, long *size,const char *format,...);

char *DtwResource_get_string(DtwResource *self);

char *DtwResource_get_string_from_sub_resource(DtwResource *self,const char *format,...);


long DtwResource_get_long(DtwResource *self);



long DtwResource_get_long_from_sub_resource(DtwResource *self,const char *format,...);


double DtwResource_get_double(DtwResource *self);

double DtwResource_get_double_from_sub_resource(DtwResource *self,const char *format,...);

bool DtwResource_get_bool(DtwResource *self);

bool DtwResource_get_bool_from_sub_resource(DtwResource *self,const char *format,...);






void DtwResource_unload(DtwResource *self);


void DtwResource_load(DtwResource *self);

void DtwResource_load_if_not_loaded(DtwResource *self);





bool private_DtwResource_its_a_pk(DtwResource *self);

void privateDtwResource_ensure_its_possible_to_sub_resource(DtwResource *self);

DtwResource * DtwResource_new_schema_insertion(DtwResource *self);

DtwResource  *DtwResource_find_by_name_id(DtwResource *self, const char *name);

DtwResource * DtwResource_find_by_primary_key_with_binary(DtwResource *self, const char *primary_key, unsigned  char *value, long size);

DtwResource * DtwResource_find_by_primary_key_with_string(DtwResource *self, const char *key, const char *value);

void DtwResource_dangerous_remove_schema_prop(DtwResource*self,const char *prop);

void DtwResource_dangerous_rename_schema_prop(DtwResource*self,const char *prop,const char *new_name);



DtwDatabaseSchema * DtwResource_newDatabaseSchema(DtwResource *self);






void private_dtw_resource_set_primary_key(DtwResource *self, unsigned  char *element, long size);

void DtwResource_set_any(DtwResource *self, unsigned char *element, long size,bool is_binary);

void DtwResource_set_binary(DtwResource *self, unsigned char *element, long size);


void DtwResource_set_string(DtwResource *self,const  char *element);

void DtwResource_set_binary_sha(DtwResource *self, unsigned  char *value, long size);


void DtwResource_set_string_sha(DtwResource *self,const char *value);


void DtwResource_set_long(DtwResource *self,long element);


void DtwResource_set_double(DtwResource *self,double element);

void DtwResource_set_bool( DtwResource *self,bool element);





void DtwResource_set_any_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size,bool is_binary);


void DtwResource_set_binary_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size);


void DtwResource_set_binary_sha_in_sub_resource(DtwResource *self, const char *key, unsigned  char *value, long size);


void DtwResource_set_string_sha_in_sub_resource(DtwResource *self, const char *key, const char *value);

void DtwResource_set_string_in_sub_resource(DtwResource *self, const char *key, const  char *element);

void DtwResource_set_long_in_sub_resource(DtwResource *self, const char *key, long element);

void DtwResource_set_double_in_sub_resource(DtwResource *self, const char *key, double element);

void DtwResource_set_bool_in_sub_resource(DtwResource *self,const char *key, bool element);






DtwResourceForeachProps DtwResource_create_foreach_props( void(*callback)(DtwResource *item, void *args));

void DtwResource_foreach(DtwResource *self,DtwResourceForeachProps props);

void DtwResource_schema_foreach(DtwResource *self,DtwResourceForeachProps props);





int  private_dtwResource_compare(const void *item1,const void*item2);

DtwResourceMapProps DtwResource_create_map_props(
    void *main_array,
    void(*append)(void *main_array_arg, void *item),
    void *(*callback)(DtwResource *item, void *args)
);

void DtwResource_map(DtwResource *self,DtwResourceMapProps props);

void DtwResource_schema_map(DtwResource *self,DtwResourceMapProps props);






DtwResourcecJSONArrayMapProps DtwResource_create_cJSONArrayMapProps(cJSON *(*callback)(DtwResource *item, void *args));

cJSON *DtwResource_map_cJSONArray(DtwResource *self,DtwResourcecJSONArrayMapProps props);

cJSON *DtwResource_schema_map_cJSONArray(DtwResource *self,DtwResourcecJSONArrayMapProps props);

void  *private_dtw_cJSONArray_callback(DtwResource *item,void *args);

bool private_dtw_cJSONArray_filtrage(DtwResource *item,void *args);

int private_dtw_cJSONArray_ordenation(DtwResource *item1,DtwResource *item2,void *args);

void privateDtwResource_add_to_item_to_cJSONArray_array(void* array, void *item);







DtwResourcecJSONObjectMapProps DtwResource_create_cJSONObjectProps(
    cJSON *(*callback)(DtwResource *item, void *args),
    char *(*key_provider_callback)(DtwResource *item,void *args)
);

cJSON *DtwResource_map_cJSONObject(DtwResource *self,DtwResourcecJSONObjectMapProps props);

cJSON *DtwResource_schema_map_cJSONObject(DtwResource *self,DtwResourcecJSONObjectMapProps props);

void  *private_dtw_cJSONArray_callback(DtwResource *item,void *args);

bool private_dtw_cJSONArray_filtrage(DtwResource *item,void *args);

int private_dtw_cJSONArray_ordenation(DtwResource *item1,DtwResource *item2,void *args);

void privateDtwResource_add_to_item_to_cJSONObject(void* object, void *item);




#ifdef DTW_ALLOW_CHASH
#define DTW_ALLOW_CHASH



DtwResourceCHashrrayMapProps  DtwResource_create_CHashrrayMapProps(    CHash *(*callback)(DtwResource *item, void *args));

CHashArray *DtwResource_map_CHashArray(DtwResource *self,DtwResourceCHashrrayMapProps props);

CHashArray *DtwResource_schema_map_CHashArray(DtwResource *self,DtwResourceCHashrrayMapProps props);

void  *private_dtw_CHashArray_callback(DtwResource *item,void *args);

bool private_dtw_CHashArray_filtrage(DtwResource *item,void *args);

int private_dtw_CHashArray_ordenation(DtwResource *item1,DtwResource *item2,void *args);

void privateDtwResource_add_to_item_to_CHashArray_array(void* array, void *item);



#define DTW_ALLOW_CHASH



DtwResourceCHashObjectMapProps DtwResource_createCHashObjectMapProps(
    CHash *(*callback)(DtwResource *item, void *args),
    char *(*filtrage_callback)(DtwResource *item, void *args_filter)
);

CHash *DtwResource_map_CHashObject(DtwResource *self,DtwResourceCHashObjectMapProps props);

CHash *DtwResource_schema_map_CHashObject(DtwResource *self,DtwResourceCHashObjectMapProps props);

void  *private_dtw_CHashArray_callback(DtwResource *item,void *args);

bool private_dtw_CHashArray_filtrage(DtwResource *item,void *args);

int private_dtw_CHashArray_ordenation(DtwResource *item1,DtwResource *item2,void *args);

void privateDtwResource_add_to_item_to_CHashObject(void* object, void *item);




#endif








DtwResourceArray * DtwResource_get_schema_values(DtwResource *self);

DtwResourceArray * DtwResource_sub_resources(DtwResource *self);







DtwResourceArray * newDtwResourceArray();

void DtwResourceArray_append(DtwResourceArray *self, DtwResource *element);


DtwResource * DtwResourceArray_get_by_name(DtwResourceArray *self, const char *name);




void DtwResourceArray_represent(DtwResourceArray *self);

void DtwResourceArray_free(DtwResourceArray *self);









DtwHash * newDtwHash();

bool  DtwHash_digest_any(DtwHash *self,unsigned char *content,long size);

bool DtwHash_digest_string(DtwHash * self, const char *content);

void DtwHash_digest_long(DtwHash * self,long content);

void DtwHash_digest_double(DtwHash * self,double content);

void DtwHash_digest_bool(DtwHash * self,bool content);

bool  DtwHash_digest_file(DtwHash * self, const char *path);

bool DtwHash_digest_entity_last_modification(DtwHash * self, const char *path);

bool DtwHash_digest_folder_by_last_modification(DtwHash *self,const char *path);

bool DtwHash_digest_folder_by_content(DtwHash *self,const char *path);


bool DtwHash_digest_string_array(DtwHash *self,DtwStringArray *element);

bool DtwHash_digest_string_array_last_modifications(DtwHash *self,DtwStringArray *element);

bool DtwHash_digest_string_array_last_modifications_adding_name(DtwHash *self,DtwStringArray *element);


bool DtwHash_digest_string_array_content(DtwHash *self,DtwStringArray *element);

bool DtwHash_digest_string_array_content_adding_name(DtwHash *self,DtwStringArray *element);


void  DtwHash_free(DtwHash *self);






DtwRandonizerModule newDtwRandonizerModule();





DtwPathModule newDtwPathModule();






DtwStringArrayModule newDtwStringArrayModule();





DtwTreePartModule newDtwTreePartModule();





DtwJsonTreeErrorModule newDtwJsonTreeErrorModule();






DtwTreeTransactionReportModule newDtwTreeTransactionReportModule();





DtwTreeModule newDtwTreeModule();








DtwLockerModule newDtwLockerModule();






DtwActionTransactionModule newDtwActionTransactionModule();






DtwJsonTransactionErrorModule newDtwJsonTransactionErrorModule();






DtwTransactionModule newDtwTransactionModule();







DtwResourceArrayModule newDtwResourceArrayModule();






DtwResourceModule newDtwResourceModule();







DtwHashModule newDtwHashModule();






DtwSchemaModule newDtwSchemaModule();






DtwDatabaseSchemaModule newDtwDatabaseSchemaModule();






DtwNamespace newDtwNamespace();






#endif

#ifdef __cplusplus
}
#endif



//doTheWorldDeclarationEnd







#ifndef DTW_GLOBALS_H
#define DTW_GLOBALS_H
const char dtw_base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
#endif




//# include "../../extras/CHashManipulator.h"







char * calc_sha_256_returning_string(const void *input, size_t len)
{


    uint8_t hash[SIZE_OF_SHA_256_HASH];
    calc_sha_256(hash, input, len);
    char *hash_string = (char*)malloc(SIZE_OF_SHA_256_HASH * 2 + 1);
    for (unsigned int i = 0; i < SIZE_OF_SHA_256_HASH; i++) {
        sprintf(hash_string + i * 2, "%02x", hash[i]);
    }
    return hash_string;
}

void  calc_sha_256_from_string(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *input)
{
    calc_sha_256(hash, input, strlen(input));

}

char * calc_sha_256_from_string_returning_string(const char *input)
{
    return calc_sha_256_returning_string(input, strlen(input));
}

int calc_sha_256_from_file(uint8_t hash[SIZE_OF_SHA_256_HASH], const char *filename)
{
    int size;
    char *content = sha256_open_file(filename, &size);
    if(content == NULL){
        return -1;
    }
    calc_sha_256(hash, content, size);
    free(content);
    return 0;
}

char * calc_sha_256_from_file_returning_string(const char *filename)
{
    int size;
    char *content = sha256_open_file(filename, &size);
    if(content == NULL){
        return NULL;
    }
    char *hash_string = calc_sha_256_returning_string(content, size);
    free(content);
    return hash_string;

}
char * sha256_open_file(const char *filename, int *size){
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }
    fseek(file,0,SEEK_END);
    *size = ftell(file);
    fseek(file,0,SEEK_SET);
    char *content = (char*)malloc(*size +1);
    fread(content,1,*size,file);
    fclose(file);
    return content;
}






char *dtw_base64_encode(unsigned char *data, long input_length){
    if (data == NULL) return NULL;

    size_t output_length = 4 * ((input_length + 2) / 3);

    char *encoded_data = (char *)malloc(output_length + 1);


    long i, j;
    for (i = 0, j = 0; i < input_length; ) {
        unsigned char b0 = i < input_length ? data[i++] : 0;
        unsigned char b1 = i < input_length ? data[i++] : 0;
        unsigned char b2 = i < input_length ? data[i++] : 0;

        unsigned char b = b0 >> 2;
        encoded_data[j++] = dtw_base64_table[b];

        b = (b0 << 4) & 0x3F;
        b |= b1 >> 4;
        encoded_data[j++] = dtw_base64_table[b];

        b = (b1 << 2) & 0x3F;
        b |= b2 >> 6;
        encoded_data[j++] = i <= input_length + 1 ? dtw_base64_table[b] : '=';

        b = b2 & 0x3F;
        encoded_data[j++] = i <= input_length ? dtw_base64_table[b] : '=';
    }

    encoded_data[j] = '\0';
    return encoded_data;
}


unsigned char *dtw_base64_decode(const char *data, long *output_length){
    long input_length = (long)strlen(data);
    if (input_length % 4 != 0) return NULL;

    *output_length = input_length / 4 * 3;
    if (data[input_length - 1] == '=') (*output_length)--;
    if (data[input_length - 2] == '=') (*output_length)--;

    unsigned char *decoded_data = (unsigned char*) malloc(*output_length +2);


    long i, j;
    for (i = 0, j = 0; i < input_length; ) {
        unsigned char b0 = data[i] == '=' ? 0 & i++ : strchr(dtw_base64_table, data[i++]) - dtw_base64_table;
        unsigned char b1 = data[i] == '=' ? 0 & i++ : strchr(dtw_base64_table, data[i++]) - dtw_base64_table;
        unsigned char b2 = data[i] == '=' ? 0 & i++ : strchr(dtw_base64_table, data[i++]) - dtw_base64_table;
        unsigned char b3 = data[i] == '=' ? 0 & i++ : strchr(dtw_base64_table, data[i++]) - dtw_base64_table;

        unsigned char b = (b0 << 2) | (b1 >> 4);
        decoded_data[j++] = b;

        if (j < *output_length) {
            b = (b1 << 4) | (b2 >> 2);
            decoded_data[j++] = b;
        }
        if (j < *output_length) {
            b = (b2 << 6) | b3;
            decoded_data[j++] = b;
        }
    }
    decoded_data[*output_length] = '\0';

    return decoded_data;
}

char *dtw_convert_binary_file_to_base64(const char *path){
     long size;
     unsigned char *data  = dtw_load_binary_content(path, &size);
    char *b64   = dtw_base64_encode(data, size);
    free(data);
    return b64;
}








DtwRandonizer * newDtwRandonizer(){
    DtwRandonizer *self = (DtwRandonizer*) malloc(sizeof (DtwRandonizer));
    *self =(DtwRandonizer){0};

    #ifndef DTW_DEBUG_TIME

            #ifdef _WIN32
                FILETIME ft;
                LARGE_INTEGER li;

                GetSystemTimeAsFileTime(&ft);
                li.LowPart = ft.dwLowDateTime;
                li.HighPart = ft.dwHighDateTime;

                self->internal_seed = li.QuadPart;
                self->internal_seed ^= GetCurrentProcessId();
            #else
                struct timespec ts;
                clock_gettime(CLOCK_REALTIME, &ts);

                self->internal_seed = (uint64_t)ts.tv_sec + (uint64_t)ts.tv_nsec;
                self->internal_seed += getpid();
            #endif
    #endif
    return self;
}

int DtwRandonizer_generate_num(DtwRandonizer *self,int max) {
    self->actual_generation+=1;
    srand(  self->internal_seed + self->actual_generation + self->seed);
    int value = rand() % max;
    return value;
}
char * DtwRandonizer_generate_token(struct DtwRandonizer*self, int size){
    static const char chars[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789";

    int total_size = sizeof(chars) - 1;
    char *token = (char*)malloc(size +1);

    for (int i = 0; i < size; ++i) {
        int index = DtwRandonizer_generate_num(self,total_size);
        token[i] = chars[index];
    }

    token[size] = '\0';
    return token;
}

void DtwRandonizer_free(struct DtwRandonizer *self){
    free(self);
}





char * dtw_generate_sha_from_file(const char *path){
    return calc_sha_256_from_file_returning_string(path);
}

char * dtw_generate_sha_from_any(void *anything , long size){
    if(anything ==NULL) {
        return NULL;
    }
    return calc_sha_256_returning_string(anything,size);
}

char * dtw_generate_sha_from_string(const char *string){
    if(string == NULL) {
        return  NULL;
    }
    return calc_sha_256_from_string_returning_string(string);
}


long int dtw_get_entity_last_motification_in_unix(const char *path){
    struct stat attr;
    if(stat(path, &attr) != 0) {
        return -1;
    }

    time_t last_modification_in_unix = attr.st_mtime;

    return last_modification_in_unix;
}

char * dtw_convert_unix_time_to_string(long int unix_time){
    struct tm * timeinfo;
    #ifdef _WIN32
        //get timeinfo from windows
        time_t rawtime = unix_time;
        timeinfo = localtime(&rawtime);
    #else
        timeinfo = localtime(&unix_time);
    #endif
    char *time_string = (char *)malloc(100);
    strftime(time_string, 100, "%Y-%m-%d %H:%M:%S", timeinfo);
    return time_string;
}

char * dtw_get_entity_last_motification_in_string(const char *path){
    long int last_modification_in_unix = dtw_get_entity_last_motification_in_unix(path);
    char *last_modification_in_string = dtw_convert_unix_time_to_string(last_modification_in_unix);
    return last_modification_in_string;
}

const char * private_dtw_convert_action_to_string(short action){
    switch (action){
        case DTW_REMOVE:
            return "remove";
        case DTW_WRITE:
            return "write";
        case DTW_MODIFY:
            return "modify";
    }
    return NULL;
}

short private_dtw_convert_string_to_action(const char *action){
    if(strcmp(action,"remove") == 0){
        return DTW_REMOVE;
    }
    if(strcmp(action,"write") == 0){
        return DTW_WRITE;
    }
    if(strcmp(action,"modify") == 0){
        return DTW_MODIFY;
    }
    return -1;
}

void private_dtw_add_end_bar_to_dirs_string_array(struct DtwStringArray * dirs){
    for(int i = 0; i < dirs->size; i++){

        if(!dtw_ends_with(dirs->strings[i], "/") || !dtw_ends_with(dirs->strings[i],"\\")){
            char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 3);
            sprintf(formated_dir,"%s/",dirs->strings[i]);
            DtwStringArray_set_value(dirs, i, formated_dir);
            free(formated_dir);
        }


    }
}



struct DtwStringArray* private_dtw_remove_start_path(struct DtwStringArray *paths,const char *rm_path){

    char *path_to_remove = dtw_replace_string(rm_path,"//","/");

    int size_to_remove = strlen(path_to_remove) +1;

    if(dtw_ends_with(path_to_remove,"/")){
        size_to_remove-=1;
    }


    struct DtwStringArray *new_array = newDtwStringArray();

    for(int i =0; i < paths->size; i++){

        char *current_path_string = paths->strings[i];
        int current_path_string_size = strlen(current_path_string);

        char *new_string = (char*)malloc(current_path_string_size +2);
        new_string[current_path_string_size] =0;

        strcpy(new_string,current_path_string);
        memmove(
                new_string,
                current_path_string+size_to_remove,
                strlen(current_path_string) - size_to_remove +1
        );
        if(strcmp(new_string,"/") == 0  || strcmp(new_string,"") == 0){
            free(new_string);
            continue;
        }

        DtwStringArray_append(new_array, new_string);
        free(new_string);

    }
    free(path_to_remove);
    return new_array;
}


long dtw_get_time(){
#ifdef DTW_DEBUG_TIME
    return 0;
#endif
    return time(NULL);
}
long private_dtw_convert_index(long index,long size){

    long converted_index = index;

    if(converted_index < 0){
        converted_index = size + converted_index;
    }

    if(converted_index >= size){
       return -1;
    }

    if(converted_index < 0){
        return -1;
    }

    return converted_index;
}





void private_dtw_remove_double_bars_from_string_array(struct DtwStringArray*path){
    for(int i =0;i< path->size;i++){
        char *buffer = private_dtw_format_path(path->strings[i]);
        free(path->strings[i]);
        path->strings[i] = buffer;
    }
}

char *dtw_concat_path(const char *path1, const char *path2){

    if(!path1){
        return strdup(path2);
    }

    if(!path2){
        return strdup(path1);
    }

    char *path = (char *)malloc(strlen(path1) + strlen(path2) + 3);

    if(dtw_ends_with(path1, "/") || dtw_ends_with(path1, "\\")){
        sprintf(path,"%s%s",path1,path2);

    }
    else{
        sprintf(path,"%s/%s",path1,path2);

    }
    return path;
}

char * private_dtw_format_vaarg(const char *expresion, va_list args){

    va_list args_copy;
    va_copy(args_copy, args);
    long required_size = vsnprintf(NULL, 0,expresion,args_copy);
    va_end(args_copy);
    char *buffer = (char*)malloc(sizeof(char) * required_size + 2);
    vsnprintf(buffer,sizeof (char) * required_size+1,expresion,args);
    return buffer;
}

char *private_dtw_format_path(const char *path){
    int path_size = (int)strlen(path);
    char *buffer = (char*)malloc((path_size+2) * sizeof(char));
    int buffer_size = 0;
    bool already_concatened = false;
    for(long i = 0; i < path_size;i++){
        char current_char = path[i];

        bool is_a_divisor =current_char == '\\' || current_char == '/';

        if(is_a_divisor && already_concatened){
            continue;
        }
        if(is_a_divisor){
#ifdef __linux
            buffer[buffer_size] = '/';
#else
            buffer[buffer_size] = '\\';
#endif
            buffer_size+=1;
            already_concatened = true;
            continue;
        }

        already_concatened = false;
        buffer[buffer_size] = current_char;
        buffer_size+=1;

    }
    buffer[buffer_size] = '\0';
    return buffer;
}


char * private_dtw_sub_str(const char *str, long start,long end){
    long size = end - start;
    char *value = (char*)malloc(size+ 2);

    for(long i = 0; i <size; i++){
        value[i] = str[i+start];
    }
    value[size] = '\0';
    return value;
}


bool dtw_starts_with(const char *string, const char *prefix){
    if(!string || !prefix){
        return false;
    }
    if(strncmp(string, prefix, strlen(prefix)) == 0){
        return true;
    }
    return false;
}

bool dtw_ends_with(const char *string, const char *suffix){
    if(strlen(string) < strlen(suffix)){
        return false;
    }
    if(strcmp(string + strlen(string) - strlen(suffix), suffix) == 0){
        return true;
    }
    return false;
}

char *private_dtw_replace_string_once(const char *target, const char *old_element, const char *new_element) {

    const char *pos = strstr(target, old_element);

    int size_of_old_element = (int)strlen(old_element);
    int size_of_new_element = (int)strlen(new_element);
    // Allocate memory for the new string
    char *result = (char *)malloc(strlen(target) + size_of_new_element - size_of_old_element + 1);

    // Copy the part of the original string before the old substring
    strncpy(result, target, pos - target);

    // Copy the new substring to the result string
    strcpy(result + (pos - target), new_element);

    // Copy the rest of the original string after the old substring
    strcpy(result + (pos - target) + size_of_new_element, pos + size_of_old_element);

    return result;



}

char* dtw_replace_string(const char *target, const char *old_element, const char *new_element) {
    char *result = (char *)malloc(strlen(target) + 1);
    strcpy(result, target);
    char *temp = NULL;
    while (strstr(result, old_element) != NULL) {
        temp = private_dtw_replace_string_once(result, old_element, new_element);
        free(result);
        result = temp;
    }
    return result;
}



char *private_dtw_change_beginning_of_string(const char *target,int start_element_to_remove_size, const char *new_element) {
    int target_size = (int)strlen(target);
    int new_element_size = (int)strlen(new_element);
    char *result = (char *)malloc(target_size- start_element_to_remove_size + new_element_size   +2);
    strcpy(result, new_element);
    char *new_target = (char *)malloc(target_size - start_element_to_remove_size + 2);
    strcpy(new_target, target + start_element_to_remove_size);
    strcat(result, new_target);
    free(new_target);
    return result;
}



char *private_dtw_realoc_formatting(char *ptr,const char *format,...){

    va_list args;
    va_start(args, format);
    char *value = private_dtw_format_vaarg(format,args);
    va_end(args);
    if(ptr){
        free(ptr);
    }

    return value;
}
char *private_dtw_formatt(const char *format,...){

    va_list args;
    va_start(args, format);
    char *value = private_dtw_format_vaarg(format,args);
    va_end(args);
    return value;
}
bool dtw_is_string_at_point(
        const char *str,
        long str_size,
        const char *target,
        long target_size,
        long target_point
        ){

    if(target_size + target_point > str_size){
        return false;
    }
    for(long i = 0; i < target_size; i++ ){
        char current_char = target[i];
        char char_to_compare = str[i+target_point];
        if(current_char != char_to_compare){
            return  false;
        }
    }
    return true;
}

long  dtw_index_of_string(const char *str,const char *element){
    long str_size = (long)strlen(str);
    long element_size = (long)strlen(element);

    for(int i = 0; i <str_size; i++){
        if(dtw_is_string_at_point(str,str_size,element,element_size,i)){
            return i;
        }
    }
    return -1;
}

double private_dtw_convert_string_to_number(const char *num, bool *its_a_number){

    long size_num = strlen(num);

    if(size_num == 0){
        *its_a_number = false;
        return -1;
    }

    bool dot_found = false;

    for(int i = 0; i < size_num; i++){
        char current = num[i];

        if(current == '.'){
            if(i == 0 || dot_found || i == size_num - 1){
                *its_a_number = false;
                return -1;
            }

            dot_found = true;
            continue;
        }

        if(current == '0'){
            continue;
        }

        if(current == '1'){
            continue;
        }

        if(current == '2'){
            continue;
        }

        if(current == '3'){
            continue;
        }

        if(current == '4'){
            continue;
        }

        if(current == '5'){
            continue;
        }

        if(current == '6'){
            continue;
        }

        if(current == '7'){
            continue;
        }

        if(current == '8'){
            continue;
        }

        if(current == '9'){
            continue;
        }

        *its_a_number = false;

        return -1;
    }

    *its_a_number = true;

    return atof(num);


}







void dtw_create_dir_recursively(const char *path){

    int entity =dtw_entity_type(path);

    if(entity == DTW_FOLDER_TYPE){
        return;
    }

    if(entity == DTW_FILE_TYPE){
        remove(path);
    }


    long size_path = strlen(path);
    for(int i=0;i <  size_path;i++){
        if((path[i] == '\\'  || path[i] == '/' )  &&( i != size_path - 1)){

            char * current_path = (char*)malloc(i + 1);
            current_path[i] = '\0';
            strncpy(current_path,path,i);

            if(dtw_entity_type(current_path) == DTW_FILE_TYPE){
                remove(current_path);
            }

            dtw_create_dir(current_path);

            free(current_path);
        }
    }

    dtw_create_dir(path);
}
char *dtw_get_absolute_path(const char *path){
    char absolute_path[PATH_MAX] ={0};

    #ifdef __linux__
     // Usa realpath para obter o caminho absoluto
     if (realpath(path, absolute_path) != NULL) {
         return strdup(absolute_path);
     }
     #endif
     #ifdef _WIN32
     if (_fullpath(absolute_path, relative_path, _MAX_PATH) != NULL) {
            return strdup(absolute_path);
    }
     #endif

     return NULL;

}
char *dtw_get_current_dir(){
    char *path = (char*)malloc(1024);
    getcwd(path,1024);
    char*path_with_bar = (char*)malloc(strlen(path) + 2);
    sprintf(path_with_bar,"%s/",path);
    free(path);
    return path_with_bar;
}



bool dtw_remove_any(const char* path) {
    //means is an file
    if(remove(path) == 0){
        return true;
    }

    struct DtwStringArray *files = dtw_list_files_recursively(path,DTW_CONCAT_PATH);
    int files_size = files->size;
    for(int i = 0; i < files_size; i++){
        remove(files->strings[i]);
    }
    DtwStringArray_free(files);


    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);
    int dirs_size = dirs->size;
    for(int i = dirs->size -1; i >=0; i--){
        rmdir(dirs->strings[i]);
    }
    DtwStringArray_free(dirs);
    //remove / to the path
    if(files_size ||dirs_size){
        return true;
    }
    return false;


}



unsigned char *dtw_load_any_content(const char * path,long *size,bool *is_binary){

    *is_binary = false;
    *size = 0;

    int entity = dtw_entity_type(path);
    if(entity != DTW_FILE_TYPE){
        return NULL;
    }
    FILE  *file = fopen(path,"rb");

    if(file ==NULL){
        return NULL;
    }


    if(fseek(file,0,SEEK_END) == -1){
        fclose(file);
        return NULL;
    }


    *size = ftell(file);

    if(*size == -1){
        fclose(file);
        return NULL;
    }

    if(*size == 0){
        fclose(file);
        return (unsigned char*)strdup("");
    }


    if(fseek(file,0,SEEK_SET) == -1){
        fclose(file);
        return NULL;
    }

    unsigned char *content = (unsigned char*)malloc(*size +1);
    int bytes_read = fread(content,1,*size,file);
    if(bytes_read <=0 ){
        free(content);
        fclose(file);
        return NULL;
    }


    *is_binary = false;
    for(int i = 0;i < *size;i++){
        if(content[i] == 0){
            *is_binary = true;
            break;
        }
    }
    content[*size] = '\0';

    fclose(file);
    return content;
}


char *dtw_load_string_file_content(const char * path){
    long size;
    bool is_binary;
    unsigned char *element = dtw_load_any_content(path,&size,&is_binary);
    if(element == NULL){
        return NULL;
    }

    if(is_binary){
        free(element);
        return NULL;
    }
    return (char*)element;
}


unsigned char *dtw_load_binary_content(const char * path,long *size){
    bool is_binary;
    return dtw_load_any_content(path,size,&is_binary);
}


bool dtw_write_any_content(const char *path,unsigned  char *content,long size){
    //Iterate through the path and create directories if they don't exist
    int entity_type =dtw_entity_type(path);
    if(entity_type == DTW_FOLDER_TYPE){
        dtw_remove_any(path);
    }


    if(entity_type == DTW_NOT_FOUND){
        long path_size = (long)strlen(path);
        for(long i = path_size-1;i > 0;i--){
            //runs in negative mode til / or \ is found
            if(path[i] == '\\' || path[i] == '/'){
                char *dir_path =(char*)malloc(i +2);
                dir_path[i] = '\0';
                strncpy(dir_path,path,i);

                dtw_create_dir_recursively(dir_path);
                free(dir_path);

                break;
            }
        }
    }

    FILE *file = fopen(path,"wb");
    if(file == NULL){

        return false;
    }

    fwrite(content, sizeof(char),size, file);

    fclose(file);
    return true;
}


bool dtw_write_string_file_content(const char *path,const char *content){
    long size;
    if(content == NULL){
        size = 0;
    }
    else{
        size = (long)strlen(content);
    }
    return dtw_write_any_content(path,(unsigned char*)content,size);
}


int dtw_entity_type(const char *path){
    //returns 1 for file, 2 for directory, -1 for not found
    struct stat path_stat;

    if(stat(path,&path_stat) == 0){
        if(S_ISREG(path_stat.st_mode)){
            return DTW_FILE_TYPE;
        }else if(S_ISDIR(path_stat.st_mode)){
            return DTW_FOLDER_TYPE;
        }
    }
    return DTW_NOT_FOUND;

}


int dtw_complex_entity_type(const char *path){
    int entity = dtw_entity_type(path);
    if(entity != DTW_FILE_TYPE){
        return entity;
    }
    long size;
    bool is_binary;
    char *data = (char*)dtw_load_any_content(path,&size,&is_binary);
    if(is_binary){
        free(data);
        return DTW_COMPLEX_BINARY;
    }

    if(
       strcmp(data,"t") == 0 ||
       strcmp(data,"f") == 0 ||
       strcmp(data,"true") == 0 ||
       strcmp(data,"false") == 0
       ){
        free(data);
        return DTW_COMPLEX_BOOL_TYPE;
    }


    double value;
    int result = sscanf(data,"%lf",&value);
    if(result == 0){
        free(data);
        return DTW_COMPLEX_STRING_TYPE;
    }
    for(int i = 0; i < size; i++){
        char current = data[i];
        if(current == '.'){
            free(data);
            return DTW_COMPLEX_DOUBLE_TYPE;
        }
    }
    free(data);
    return DTW_COMPLEX_LONG_TYPE;
}

long dtw_get_total_itens_of_dir(const char *path){

    #ifdef __linux__

        DIR *dir = opendir(path);
        if (dir == NULL) {
        return -1;
        }
        int i = 0;
        while ((readdir(dir)) != NULL){
            i++;
        }
        closedir(dir);
        return i -2;
    #endif
    #ifdef _WIN32
        WIN32_FIND_DATA findFileData;
            HANDLE hFind = FindFirstFile(path, &findFileData);

            if (hFind == INVALID_HANDLE_VALUE) {
                return -1;
            }

            int i = 0;
            do {
                if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
                    i++;
                }
            } while (FindNextFile(hFind, &findFileData) != 0);

            FindClose(hFind);
            return i;

    #endif
}

const char *dtw_convert_entity(int entity_type){
    if(entity_type == DTW_FILE_TYPE){
        return "file";
    }
    if(entity_type == DTW_FOLDER_TYPE){
        return "folder";
    }
    if(entity_type == DTW_NOT_FOUND){
        return "null";
    }
    if(entity_type == DTW_COMPLEX_BINARY){
        return "binary";
    }
    if(entity_type == DTW_COMPLEX_STRING_TYPE){
        return "string";
    }
    if(entity_type == DTW_COMPLEX_BOOL_TYPE){
        return "bool";
    }
    if(entity_type == DTW_COMPLEX_LONG_TYPE){
        return "long";
    }
    if(entity_type == DTW_COMPLEX_DOUBLE_TYPE){
        return "double";
    }
    return "invalid";
}

bool dtw_copy_any(const char* src_path,const  char* dest_path,bool merge) {

    //verify if is an file
    int type = dtw_entity_type(src_path);
    if(type == DTW_NOT_FOUND){
        return false;
    }

    if(type == DTW_FILE_TYPE){

        long size;
        bool is_binary;
        unsigned char *content = dtw_load_any_content(src_path,&size,&is_binary);
        bool result =  dtw_write_any_content(dest_path,content,size);
        free(content);
        return result;
    }
    //means is an directory

    //remove the previous directory if merge is false
    if(!merge){
        dtw_remove_any(dest_path);
    }
    //creating dirs
    struct DtwStringArray *dirs = dtw_list_dirs_recursively(src_path,DTW_CONCAT_PATH);

    int size = dirs->size;
    int src_path_size = strlen(src_path);

    for(int i = 0; i < size; i++){
        char *new_path_dir = private_dtw_change_beginning_of_string(dirs->strings[i],src_path_size,dest_path);
        dtw_create_dir_recursively(new_path_dir);
        free(new_path_dir);
    }
    DtwStringArray_free(dirs);


    struct DtwStringArray *files = dtw_list_files_recursively(src_path,DTW_CONCAT_PATH);

    for(int i = 0; i < files->size; i++){
        long file_size;
        bool is_binary;
        unsigned char *content = dtw_load_any_content(files->strings[i],&file_size,&is_binary);
        char *new_path = private_dtw_change_beginning_of_string(files->strings[i],src_path_size,dest_path);

        dtw_write_any_content(new_path,content,file_size);
        free(content);
        free(new_path);


    }

    DtwStringArray_free(files);

    return true;

}

bool dtw_move_any(const char* src_path, const char* dest_path,bool merge) {
    bool result = dtw_copy_any(src_path,dest_path,merge);
    dtw_remove_any(src_path);
    return result;
}





long dtw_load_long_file_content_setting_error(const char *path,int *error){
    char *data = dtw_load_string_file_content(path);
    if(!data){
        *error = DTW_NOT_FOUND;
        return DTW_NOT_FOUND;
    }
    long value = -1;
    int result = sscanf(data,"%ld",&value);
    free(data);
    if(result){
        return value;
    }
    *error = DTW_NOT_NUMERICAL;
    return DTW_NOT_NUMERICAL;
}


long dtw_load_long_file_content(const char * path){
   int error;
   return dtw_load_long_file_content_setting_error(path,&error);
}


double dtw_load_double_file_content_setting_error(const char * path, int *error){
    char *data = dtw_load_string_file_content(path);
    if(!data){
        *error = DTW_NOT_FOUND;
        return DTW_NOT_FOUND;
    }
    double value = -1;
    int result = sscanf(data,"%lf",&value);
    free(data);
    if(result){

        return value;
    }
    *error = DTW_NOT_NUMERICAL;
    return DTW_NOT_NUMERICAL;
}


double dtw_load_double_file_content(const char * path){
    int error;
    return dtw_load_double_file_content_setting_error(path,&error);
}


bool dtw_load_bool_file_content_setting_error(const char * path, int *error){
    char *data = dtw_load_string_file_content(path);
    if(!data){
        *error = DTW_NOT_FOUND;
        return false;
    }

    if(strcmp(data,"true") == 0 || strcmp(data,"t") == 0){
        free(data);
        return true;
    }

    if(strcmp(data,"false") == 0 || strcmp(data,"f") == 0){
        free(data);
        return false;
    }
    free(data);
    *error = DTW_NOT_BOOL;
    return false;

}


bool dtw_load_bool_file_content(const char * path){
    int error;
    return dtw_load_bool_file_content_setting_error(path,&error);

}



void dtw_write_long_file_content(const char *path, long value){
    char result[30] ={0};
    sprintf(result,"%ld",value);
    dtw_write_string_file_content(path,result);
}


void dtw_write_double_file_content(const char *path,double value){
    char result[30] ={0};
    sprintf(result,"%lf",value);
    dtw_write_string_file_content(path,result);
}


void dtw_write_bool_file_content(const char *path, bool value){
    if(value){
        dtw_write_string_file_content(path,"t");
    }
    else{
        dtw_write_string_file_content(path,"f");
    }
}






 DtwStringArray * dtw_list_files(const char *path, bool concat_path){
    return dtw_list_basic(path,  DTW_FILE_TYPE, concat_path);
}

 DtwStringArray * dtw_list_dirs(const char *path, bool concat_path){
    return dtw_list_basic(path,DTW_FOLDER_TYPE, concat_path);
}

 DtwStringArray *  dtw_list_all(const char *path,  bool concat_path){
    return dtw_list_basic(path, DTW_ALL_TYPE, concat_path);
}






#ifdef __linux__

bool private_dtw_verify_if_add(const int expected_type, int d_type){
    if (expected_type == DTW_FILE_TYPE  && d_type == DT_REG) {
        return true;
    }

    if (expected_type == DTW_FOLDER_TYPE && d_type == DT_DIR) {
        return true;
    }

    if (expected_type == DTW_ALL_TYPE) {

        return true;
    }
    return false;
}
bool private_dtw_verify_if_skip(struct dirent *entry){
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            return true;
        }
        return false;
}

struct DtwStringArray * dtw_list_basic(const char *path,int expected_type,bool concat_path){

    DIR *dir;
    struct dirent *entry;

    //array of directories
    struct DtwStringArray *dirs = newDtwStringArray();
    int i = 0;

    //means that the directory is not found
    if ((dir = opendir(path)) == NULL) {
        return dirs;
    }

    //reads the directory and adds the directories to the array
    while ((entry = readdir(dir)) != NULL) {
        //means is not a directory
        if (private_dtw_verify_if_skip(entry)){
            continue;
        }

        if (private_dtw_verify_if_add(expected_type,entry->d_type)) {


            if(concat_path){
                //allocates memory for the directory
                char *generated_dir = (char*)malloc(strlen(path) + strlen(entry->d_name) + 2);
                if(path[strlen(path) - 1] == '/'){
                    sprintf(generated_dir, "%s%s", path, entry->d_name);
                }
                else{
                    sprintf(generated_dir, "%s/%s", path, entry->d_name);
                }

                DtwStringArray_append(dirs, generated_dir);
                free(generated_dir);
            }
            else{
                DtwStringArray_append(dirs, entry->d_name);

            }

            i++;
        }
    }

    if(expected_type == DTW_FOLDER_TYPE){
        private_dtw_add_end_bar_to_dirs_string_array(dirs);
    }
    closedir(dir);

    return dirs;
}

#endif





#ifdef _WIN32


bool private_dtw_verify_if_add(const int expected_type, WIN32_FIND_DATAA entry){

    if (expected_type == DTW_FILE_TYPE && entry.dwFileAttributes == WIN32_FILETYPE) {
        return true;
    }

    if (expected_type == DTW_FOLDER_TYPE && entry.dwFileAttributes != WIN32_FILETYPE){
        return true;
    }

    if (expected_type == DTW_ALL_TYPE) {
        return true;
    }

    return false;
}

bool private_dtw_verify_if_skip(WIN32_FIND_DATAA *entry){
    if (strcmp(entry->cFileName, ".") == 0 || strcmp(entry->cFileName, "..") == 0) {
        return true;
    }
    return false;
}

struct DtwStringArray *  dtw_list_basic(const char *path,int expected_type,bool concat_path){

    WIN32_FIND_DATAA file_data;
    HANDLE file_handle;
    char search_path[MAX_PATH];

    //array of directories
    struct DtwStringArray *dirs = newDtwStringArray();
    int i = 0;

    // build the search path string
    snprintf(search_path, MAX_PATH, "%s\\*", path);

    // try to open the directory
    if ((file_handle = FindFirstFileA(search_path, &file_data)) == INVALID_HANDLE_VALUE) {
        return dirs;
    }

    do {
        // skip "." and ".." directories
        if (private_dtw_verify_if_skip(&file_data)){
            continue;
        }

        // verify if it's a file or directory
        if (private_dtw_verify_if_add(expected_type, file_data)) {

            if(concat_path){
                // allocate memory for the directory
                if(path[strlen(path) - 1] == '\\' || path[strlen(path) - 1] == '/'){
                    char *generated_dir = (char*)malloc(strlen(path) + strlen(file_data.cFileName) + 1);
                    sprintf(generated_dir, "%s%s", path, file_data.cFileName);
                    DtwStringArray_append(dirs, generated_dir);
                    free(generated_dir);
                }
                else{
                    char *generated_dir = (char*)malloc(strlen(path) + strlen(file_data.cFileName) + 2);


                    sprintf(generated_dir, "%s/%s", path, file_data.cFileName);

                    DtwStringArray_append(dirs, generated_dir);
                    free(generated_dir);
                }


            }
            else{
                DtwStringArray_append(dirs, file_data.cFileName);

            }

            i++;
        }
    } while (FindNextFileA(file_handle, &file_data) != 0);

        if(expected_type == DTW_FOLDER_TYPE){
            private_dtw_add_end_bar_to_dirs_string_array(dirs);
        }

    FindClose(file_handle);

    return dirs;
}
#endif





 DtwStringArray * dtw_list_dirs_recursively(const char *path,bool concat_path){

        struct  DtwStringArray *dirs  = newDtwStringArray();
        //verify if the path is a directory

        int entity_type = dtw_entity_type(path);
        if(entity_type != DTW_FOLDER_TYPE){
                return dirs;
        }


        DtwStringArray_append(dirs, (char*)path);

        private_dtw_add_end_bar_to_dirs_string_array(dirs);
        int i = 0;
        //The size of dirs will increase til it reaches the end of the array
        while(i < dirs->size){
                struct DtwStringArray *sub_dirs = dtw_list_basic(
                    dirs->strings[i],
                    DTW_FOLDER_TYPE,
                    true
                    );
                //merge the two dirs
            DtwStringArray_merge(dirs, sub_dirs);
                DtwStringArray_free(sub_dirs);
                i++;

        }
        //unsifth path in dirs
     private_dtw_remove_double_bars_from_string_array(dirs);

        if(!concat_path){

            struct DtwStringArray *removed =  private_dtw_remove_start_path(dirs,path);
            DtwStringArray_free(dirs);
            return removed;
        }
        return dirs;
}



 DtwStringArray *  dtw_list_files_recursively(const char *path,bool concat_path){

    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);

    struct  DtwStringArray *files = newDtwStringArray();
    for(int i = 0; i < dirs->size; i++){
        struct DtwStringArray *sub_files = dtw_list_basic(dirs->strings[i],DTW_FILE_TYPE,DTW_CONCAT_PATH);
        DtwStringArray_merge(files, sub_files);
        DtwStringArray_free(sub_files);
    }

    DtwStringArray_free(dirs);

    if(!concat_path){

        struct DtwStringArray *removed =  private_dtw_remove_start_path(files,path);
        DtwStringArray_free(files);
        return removed;
    }

    return files;
}


 DtwStringArray * dtw_list_all_recursively(const char *path,bool concat_path){

    struct DtwStringArray *dirs = dtw_list_dirs_recursively(path,DTW_CONCAT_PATH);

    struct DtwStringArray *all = newDtwStringArray();

    for(int i = 0; i < dirs->size; i++){

        if(!dtw_ends_with(dirs->strings[i], "/") || !dtw_ends_with(dirs->strings[i], "\\") ){

            char *formated_dir =  (char*)malloc(strlen(dirs->strings[i]) + 2);
            sprintf(formated_dir,"%s/",dirs->strings[i]);
            DtwStringArray_append(all, formated_dir);
            free(formated_dir);
        }

        else{
            DtwStringArray_append(all, dirs->strings[i]);
        }

        struct DtwStringArray *sub_files = dtw_list_basic(dirs->strings[i],DTW_FILE_TYPE,true);
        DtwStringArray_merge(all,sub_files);
        DtwStringArray_free(sub_files);
    }
    DtwStringArray_free(dirs);
     private_dtw_remove_double_bars_from_string_array(all);
    if(!concat_path){

        struct DtwStringArray *removed =  private_dtw_remove_start_path(all,path);
        DtwStringArray_free(all);
        return removed;
    }
    return all;
}









struct DtwPath * newDtwPath(const char *path) {
    struct DtwPath *self = (struct DtwPath *)malloc(sizeof(struct DtwPath));
    self->garbage = newDtwStringArray();
    self->path = private_dtw_format_path(path);
    self->original_path_string = strdup(self->path);


    return self;
}
bool DtwPath_changed(struct DtwPath *self){
    return strcmp(self->path,self->original_path_string) != 0;
}




void DtwPath_represent(struct DtwPath *self){
    char  *path = DtwPath_get_path(self);
    char *full_name = DtwPath_get_full_name(self);
    char *dir = DtwPath_get_dir(self);
    char *name = DtwPath_get_name(self);
    char *extension = DtwPath_get_extension(self);
    bool changed = DtwPath_changed(self);

    printf("First Path: %s\n", self->original_path_string ? self->original_path_string : "NULL");
    printf("Path: %s\n", path  ? path : "NULL");
    printf("Path Changed: %s\n", changed ? "true" : "false");
    printf("Dir: %s\n", dir ? dir : "NULL");
    printf("Full Name: %s\n", full_name ? full_name : "NULL");
    printf("Name: %s\n", name ? name : "NULL");
    printf("Extension: %s\n", extension ? extension : "NULL");


}



void DtwPath_free(struct DtwPath *self) {
    DtwStringArray_free(self->garbage);
    free(self->original_path_string);
    free(self->path);
    free(self);
}






char * DtwPath_get_name(struct DtwPath *self){

    long path_size = (long)strlen(self->path);
    long start = 0;
    long end = path_size;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '/' || current_char == '\\'){
            start = i+1;
            break;
        }
        if(current_char == '.'){
            end = i;
        }
    }
    if(end - start == 0){
        return NULL;
    }

    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);

}
char * DtwPath_get_extension(struct DtwPath *self){
    long path_size = (long)strlen(self->path);
    long start = -1;
    long end = path_size;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '.'){
            start = i+1;
            break;
        }
    }
    if(start == -1){
        return  NULL;
    }
    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}

char * DtwPath_get_full_name(struct DtwPath *self){
    long path_size = (long)strlen(self->path);
    long start = 0;
    long end = path_size;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '/' || current_char == '\\'){
            start = i+1;
            break;
        }
    }
    if(end - start == 0){
        return NULL;
    }
    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}

char * DtwPath_get_dir(struct DtwPath *self){
    long path_size = (long)strlen(self->path);
    long start = 0;
    long end = -1;
    for(long i = path_size-1; i >=0; i--){
        char current_char = self->path[i];
        if(current_char == '/' || current_char == '\\'){
            end = i+1;
            break;
        }
    }
    if(end == -1){
        return NULL;
    }

    char *buffer = private_dtw_sub_str(self->path,start,end);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}

char * DtwPath_get_path(struct DtwPath *self){
    return self->path;
}






void DtwPath_set_extension(struct DtwPath *self, const char *extension){

    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    const char *name = DtwPath_get_name(self);
    if(!name){
        name = "";
    }
    free(self->path);
    char *formated_extension = dtw_replace_string(extension,".","");
    self->path= private_dtw_formatt("%s%s.%s",dir,name,formated_extension);
    free(formated_extension);
}


void DtwPath_set_name(struct DtwPath * self, const char * name){
    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    char *extension = DtwPath_get_extension(self);
    free(self->path);

    if(extension){
        self->path = private_dtw_formatt("%s%s.%s",dir,name,extension);
    }
    if(!extension){
        self->path = private_dtw_formatt("%s%s",dir,name);
    }
}



void DtwPath_set_full_name(struct DtwPath * self, const char * full_name){
    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    free(self->path);
    self->path = private_dtw_formatt("%s%s",dir,full_name);

}


void DtwPath_set_dir(struct DtwPath *self, const char *dir){
    const char * full_name = DtwPath_get_full_name(self);
    if(!full_name){
        full_name = "";
    }
    free(self->path);
    char *buffer = private_dtw_formatt("%s/%s",dir,full_name);
    self->path = private_dtw_format_path(buffer);
    free(buffer);

}


void DtwPath_set_path(struct DtwPath *self, const char *target_path) {
    free(self->path);
    self->path = private_dtw_format_path(target_path);
}


void DtwPath_add_start_dir(struct DtwPath *self, const char *start_dir){
    char *element = dtw_concat_path(start_dir,self->path);
    free(self->path);
    self->path = private_dtw_format_path(element);
    free(element);
}

void DtwPath_add_end_dir(struct DtwPath *self, const char *end_dir){
    const char *dir = DtwPath_get_dir(self);
    if(!dir){
        dir = "";
    }
    const char * full_name = DtwPath_get_full_name(self);
    if(!full_name){
        full_name = "";
    }
    free(self->path);

    char *buffer = private_dtw_formatt("%s/%s/%s",dir,end_dir,full_name);
    self->path = private_dtw_format_path(buffer);
    free(buffer);
}

void DtwPath_replace_dirs(DtwPath *self,const char *str,const char *dir){
    char *self_dir = DtwPath_get_dir(self);

    char *formatted_entry = NULL;
    if(dtw_starts_with(self_dir,str)){
       formatted_entry = private_dtw_formatt("%s/",dir);
    }
    else{
        formatted_entry = private_dtw_formatt("/%s/",dir);

    }
    char * formated_dir = dtw_replace_string(self_dir,str,formatted_entry);
    DtwPath_set_dir(self,formated_dir);
    free(formated_dir);
    free(formatted_entry);

}





int DtwPath_get_total_dirs(DtwPath *self){
    int size = 0;
    int path_size = (int)strlen(self->path);
    for(int i = 0; i < path_size;i++){
        char current = self->path[i];
        if(current == '/' || current =='\\'){
            size+=1;
        }
    }
    return size;
}

char *DtwPath_get_sub_dirs_from_index(DtwPath *self, int start, int end){

    int size = DtwPath_get_total_dirs(self);
    if(size == 0){
        return NULL;
    }
    int converted_start_index = (int)private_dtw_convert_index(start, size);
    int converted_end_index = (int)private_dtw_convert_index(end, size);

    if(converted_start_index == -1  || converted_end_index == -1){
        return  NULL;
    }

    char *dir = DtwPath_get_dir(self);
    int  dirs_string_size = (int)strlen(dir);
    int total_dirs = 0;
    bool start_defined = false;
    bool end_defined  = false;
    int start_point = 0;
    int end_point = dirs_string_size;

    for(int i= 0 ;i < dirs_string_size;i++ ){
        char current = dir[i];
        if(current == '/' || current =='\\'){
            total_dirs+=1;
            continue;
        }
        if(total_dirs == converted_start_index  &&!start_defined){
            start_point = i;
            start_defined = true;
        }

        if(total_dirs == (converted_end_index + 1)&&!end_defined){
            end_point = i;
            end_defined = true;
        }
    }
    char *buffer = private_dtw_sub_str(dir,start_point,end_point);
    return privateDtwStringArray_append_if_not_included(self->garbage,buffer);
}



int private_dtw_count_dirs_before(const char *dirs,int index){
    int total = 0;
    for(int i =index; i >=0; i--){
        char current_char = dirs[i];
        if(current_char == '\\' || current_char == '/' ){
            total+=1;
        }
    }
    return  total;
}

void DtwPath_insert_dir_at_index(DtwPath *self, int index, const char *dir){

    int size = DtwPath_get_total_dirs(self);
    int converted_index = (int)private_dtw_convert_index(index,size+1);

    if(converted_index == -1){
        return  ;
    }
    char * starter = NULL;
    if(converted_index > 0){
        starter = DtwPath_get_sub_dirs_from_index(self, 0, converted_index - 1);
    }

    const char *rest =NULL;
    if(converted_index < size){
        rest = DtwPath_get_sub_dirs_from_index(self, converted_index, -1);
    }


     char *buffer =NULL;
    if(starter && rest){
        buffer = private_dtw_formatt("%s/%s/%s",starter,dir,rest);
    }
    if(starter && rest==NULL){
        buffer = private_dtw_formatt("%s/%s",starter,dir);
    }
    if(starter == NULL && rest){
        buffer = private_dtw_formatt("%s/%s",dir,rest);
    }

    if(!starter && !rest){
        buffer = (char*)dir;
    }

    DtwPath_set_dir(self,buffer);

    if(starter || rest){
        free(buffer);
    }
}



void DtwPath_remove_sub_dirs_at_index(DtwPath *self, int start, int end){

    int size = DtwPath_get_total_dirs(self);
    if(size == 0){
        return ;
    }
    int converted_start_index = (int)private_dtw_convert_index(start, size);
    int converted_end_index = (int)private_dtw_convert_index(end, size);

    if(converted_start_index == -1  || converted_end_index == -1){
        return  ;
    }
    char *start_dir = NULL;
    if(converted_start_index != 0){
        start_dir = DtwPath_get_sub_dirs_from_index(self,0,converted_start_index-1);
    }

    char *end_dir = DtwPath_get_sub_dirs_from_index(self,converted_end_index+1,-1);

    if(start_dir != NULL  && end_dir != NULL){
        char *full_dir = dtw_concat_path(start_dir,end_dir);
        DtwPath_set_dir(self,full_dir);
        free(full_dir);
        return ;
    }
    if(start_dir != NULL){
        DtwPath_set_dir(self,start_dir);
    }

    if(end_dir != NULL){
        DtwPath_set_dir(self,end_dir);
    }


}





void DtwPath_insert_dir_after(DtwPath *self,const char *str,const char *dir){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }

    int start = private_dtw_count_dirs_before(current_dir,index)+1;
    DtwPath_insert_dir_at_index(self, start, dir);
}

void DtwPath_insert_dir_before(DtwPath *self,const char *str,const char *dir){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }
    int start = private_dtw_count_dirs_before(current_dir,index);
    DtwPath_insert_dir_at_index(self, start, dir);
}

void DtwPath_remove_sub_dirs_at(DtwPath *self,const char *str){
    char *current_dir = DtwPath_get_dir(self);
    int index = (int)dtw_index_of_string(current_dir,str);
    if(index == -1){
        return;
    }

    int start = private_dtw_count_dirs_before(current_dir,index);
    int end = private_dtw_count_dirs_before(current_dir,index+ (int)strlen(str));
    DtwPath_remove_sub_dirs_at_index(self, start, end - 1);
}








struct DtwStringArray * newDtwStringArray(){
    struct DtwStringArray *self = ( DtwStringArray*)malloc(sizeof(struct DtwStringArray));
    self->size = 0;

    self->strings = (char**)malloc(1);

    return self;
}

int DtwStringArray_find_position( DtwStringArray *self, const char *string){
    for(int i = 0; i < self->size; i++){
        if(strcmp(self->strings[i], string) == 0){
            return i;
        }
    }
    return -1;
}


void DtwStringArray_set_value( DtwStringArray *self, int index, const char *value){
    if(index < self->size && index >= 0){
        int size = strlen(value);
        self->strings[index] = (char*)realloc(self->strings[index], size + 1);
        self->strings[index][size] = '\0';
        strcpy(self->strings[index], value);
    }
}
void DtwStringArray_append_getting_ownership( DtwStringArray *self, char *string){
    self->strings =  (char**)realloc(self->strings, (self->size+ 1) * sizeof(char*));
    self->strings[self->size] = string;
    self->size+=1;
}

// Function prototypes
void DtwStringArray_append( DtwStringArray *self, const  char *string){

    self->strings =  (char**)realloc(self->strings, (self->size+ 1) * sizeof(char*));
    self->strings[self->size] = strdup(string);
    self->size+=1;
}

void DtwStringArray_pop( DtwStringArray *self, int position){
    free(self->strings[position]);
    for(int i = position; i < self->size -1; i++){
        self->strings[i] = self->strings[i+1];
    }
    self->size-=1;
}

void DtwStringArray_merge( DtwStringArray *self,  DtwStringArray *other){
    for(int i = 0; i < other->size; i++){
        DtwStringArray_append(self, other->strings[i]);
    }
}


void DtwStringArray_represent( DtwStringArray *self){
    for(int i = 0; i < self->size; i++){
        printf("%s\n", self->strings[i]);
    }
}

int private_dtw_string_cmp(const void *a, const void *b){

    bool a_its_number;

    double a_num_value = private_dtw_convert_string_to_number(*(const char **)a, &a_its_number);

    if(a_its_number){
        bool b_its_number;

        double b_num_value = private_dtw_convert_string_to_number(*(const char **)b, &b_its_number);

        if(b_its_number){


            return a_num_value - b_num_value;
        }
    }

    const char *str_a = *(const char **)a;
    const char *str_b = *(const char **)b;
    return strcmp(str_a, str_b);
}

void DtwStringArray_sort(struct DtwStringArray *self) {

    qsort(self->strings, self->size, sizeof(char*), private_dtw_string_cmp);
}

 DtwStringArray * DtwStringArray_clone(DtwStringArray *self){
    DtwStringArray  *clone = newDtwStringArray();
    for(int i = 0; i< self->size; i++){
        DtwStringArray_append(clone,self->strings[i]);
    }
    return clone;
}

char * privateDtwStringArray_append_if_not_included(DtwStringArray *self,char *value){
    long position=DtwStringArray_find_position(self,value);
    if(position != -1){
        free(value);
        return self->strings[position];
    }
    DtwStringArray_append_getting_ownership(self,value);
    return value;
}
void DtwStringArray_free(struct DtwStringArray *self){
    for(int i = 0; i < self->size; i++){
            free(self->strings[i]);
    }

    free(self->strings);
    free(self);
}





DtwTreeProps DtwTreeProps_format_props(DtwTreeProps props){
    DtwTreeProps result = props;

    if(!result.minification){
        result.minification = DTW_NOT_MIMIFY;
    }
    if(!result.content){
        result.content = DTW_INCLUDE;
    }
    if(!result.path_atributes){
        result.path_atributes = DTW_INCLUDE;
    }
    if(!result.hadware_data){
        result.hadware_data = DTW_INCLUDE;
    }
    if(!result.content_data){
        result.content_data = DTW_INCLUDE;
    }
    if(!result.ignored_elements){
        result.ignored_elements = DTW_HIDE;
    }
    return result;
}





DtwJsonTreeError * newDtwJsonError(){
     DtwJsonTreeError *self =(DtwJsonTreeError*)malloc(sizeof(struct DtwJsonTreeError));
    return self;
}

DtwJsonTreeError * DtwJsonTreeError_validate_json_tree_by_cJSON(cJSON *json_tree){
     struct DtwJsonTreeError *json_error = newDtwJsonError();
    //verifiy if json_tre is not null
    if(json_tree == NULL){
        json_error->code = DTW_JSON_SYNTAX_ERROR;
        json_error->menssage = "json_tree is null";
        return json_error;
    }

    //verifiy if json_tre is an array
    if(!cJSON_IsArray(json_tree)){
        cJSON_Delete(json_tree);
        json_error->code = DTW_JSON_TYPE_ERROR;
        json_error->menssage = "json_tree is not an array";
        return json_error;
    }

    int size = cJSON_GetArraySize(json_tree);
    for(int i = 0; i < size; i++){
        json_error->position = i;
        cJSON *json_tree_part = cJSON_GetArrayItem(json_tree, i);
        cJSON *path = cJSON_GetObjectItemCaseSensitive(json_tree_part, "path");
        cJSON *original_path = cJSON_GetObjectItemCaseSensitive(json_tree_part, "original_path");
        cJSON *hardware_sha = cJSON_GetObjectItemCaseSensitive(json_tree_part, "hardware_sha256");
        cJSON *hardware_content_size = cJSON_GetObjectItemCaseSensitive(json_tree_part, "hardware_content_size");
        cJSON *last_modification_in_unix_time = cJSON_GetObjectItemCaseSensitive(json_tree_part, "last_modification_in_unix_time");
        cJSON *content_size = cJSON_GetObjectItemCaseSensitive(json_tree_part, "content_size");
        cJSON *is_binary = cJSON_GetObjectItemCaseSensitive(json_tree_part, "is_binary");
        cJSON *content = cJSON_GetObjectItemCaseSensitive(json_tree_part, "content");
        cJSON *ignore = cJSON_GetObjectItemCaseSensitive(json_tree_part, "ignore");
        cJSON *pending_action = cJSON_GetObjectItemCaseSensitive(json_tree_part, "pending_action");
        //path is required
        if(!cJSON_IsString(path)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_KEY_ERROR;
            json_error->menssage = "path is not a string";
            return json_error;
        }

        //Others are not required
        if(original_path != NULL && !cJSON_IsString(original_path)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "original_path is not a string";
            return json_error;
        }
        if(hardware_sha != NULL && !cJSON_IsString(hardware_sha)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "hardware_sha is not a string";
            return json_error;
        }
        if(hardware_content_size != NULL && !cJSON_IsNumber(hardware_content_size)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "hardware_content_size is not a number";
            return json_error;
        }
        if(last_modification_in_unix_time != NULL && !cJSON_IsNumber(last_modification_in_unix_time)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "last_modification_in_unix_time is not a number";
            return json_error;
        }
        if(content_size != NULL && !cJSON_IsNumber(content_size)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "content_size is not a number";
            return json_error;
        }

        if(is_binary != NULL && !cJSON_IsBool(is_binary)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "is_binary is not a bool";
            return json_error;
        }
        if(content != NULL && !cJSON_IsString(content)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "content is not a string";
            return json_error;
        }
        if(ignore != NULL && !cJSON_IsBool(ignore)){
            cJSON_Delete(json_tree);
            json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
            json_error->menssage = "ignore is not a bool";
            return json_error;
        }

        if(pending_action != NULL && cJSON_IsNull(pending_action) == false){

            if(cJSON_IsString(pending_action)){

                int action = private_dtw_convert_string_to_action(
                    cJSON_GetStringValue(pending_action)
                );
                if(action == DTW_ACTION_ERROR){
                    cJSON_Delete(json_tree);
                    json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
                    json_error->menssage = "pending_action is not a valid action";
                    return json_error;
                }
            }
            else{
                cJSON_Delete(json_tree);
                json_error->code = DTW_JSON_REQUIRED_VALUE_ERROR;
                json_error->menssage = "pending_action is not a valid action";
                return json_error;
            }


        }

    }
     DtwJsonTreeError_free(json_error);
     return NULL;
 }

 DtwJsonTreeError * DtwJsonTreeError_validate_json_tree_by_content(const char *content){
     cJSON *json_tree = cJSON_Parse(content);
     DtwJsonTreeError *json_error = DtwJsonTreeError_validate_json_tree_by_cJSON(json_tree);
     cJSON_Delete(json_tree);
     return json_error;
 }




void DtwJsonTreeError_represent( DtwJsonTreeError *self){

    if(self == NULL){
        return;
    }
    printf("code: %d\n", self->code);
    printf("position: %d\n", self->position);
    printf("menssage: %s\n", self->menssage);
}

void DtwJsonTreeError_free(struct DtwJsonTreeError *self){
     if(self){
         free(self);
     }
}






struct DtwTreeTransactionReport * newDtwTreeTransactionReport(){
    struct DtwTreeTransactionReport *new_report = (struct DtwTreeTransactionReport *)malloc(sizeof(struct DtwTreeTransactionReport));
    new_report->write = newDtwStringArray();
    new_report->modify = newDtwStringArray();
    new_report->remove = newDtwStringArray();
    return new_report;
}

void  DtwTreeTransactionReport_represent(struct DtwTreeTransactionReport *report){
    printf("Write:---------------------------------------\n");
    DtwStringArray_represent(report->write);
    printf("Modify:--------------------------------------\n");
    DtwStringArray_represent(report->modify);
    printf("Remove:--------------------------------------\n");
    DtwStringArray_represent(report->remove);
    puts("");
}

void  DtwTreeTransactionReport_free(struct DtwTreeTransactionReport *report){
    DtwStringArray_free(report->write);
    DtwStringArray_free(report->modify);
    DtwStringArray_free(report->remove);
    free(report);
}






void private_DtwTreePart_set_last_modification(DtwTreePart *self,long last_modification) {
    self->last_modification_time = last_modification;
    if(self->last_modification_in_str) {
        free(self->last_modification_in_str);
    }
    self->last_modification_in_str = dtw_convert_unix_time_to_string(last_modification);
}
 DtwTreePart * newDtwTreePart(const char *path, DtwTreeProps props){
    DtwTreeProps formated_props = DtwTreeProps_format_props(props);

    DtwTreePart *self = (DtwTreePart *)malloc(sizeof(struct DtwTreePart));
    *self = (DtwTreePart){0};
    self->path = newDtwPath(path);


    if(formated_props.content == DTW_INCLUDE || formated_props.hadware_data == DTW_INCLUDE){

        DtwTreePart_load_content_from_hardware(self);
        if(formated_props.hadware_data == DTW_INCLUDE && self->content){

            self->metadata_loaded = true;
            private_DtwTreePart_set_last_modification(self,dtw_get_entity_last_motification_in_unix(path));
            free(self->hawdware_content_sha);
            self->hawdware_content_sha = dtw_generate_sha_from_string((const char*)self->content);
        }

        if(formated_props.content == DTW_HIDE){
            DtwTreePart_free_content(self);
        }
    }

    return self;
}
char *DtwTreePart_get_content_string_by_reference(struct DtwTreePart *self){
    return (char *)self->content;
}

unsigned char *DtwTreePart_get_content_binary_by_reference(struct DtwTreePart *self){
    return self->content;
}


  DtwTreePart * DtwTreePart_self_copy( DtwTreePart *self){
    char *path = DtwPath_get_path(self->path);

    DtwTreeProps props = {.content =DTW_NOT_LOAD,.hadware_data = DTW_NOT_LOAD};
    DtwTreePart *new_tree_part = newDtwTreePart(
            path,
            props
    );

    new_tree_part->content_exist_in_hardware = self->content_exist_in_hardware;
    new_tree_part->is_binary = self->is_binary;
    new_tree_part->ignore = self->ignore;
    new_tree_part->content_size = self->content_size;

    char * current_sha = DtwTreePart_get_content_sha(self);

    if(current_sha) {
        new_tree_part->current_sha = strdup(current_sha);
    }

    if(self->hawdware_content_sha){
        new_tree_part->hawdware_content_sha = strdup(self->hawdware_content_sha);
    }

    if(self->content) {
        new_tree_part->content = (unsigned char *)malloc(self->content_size + 2);
        memcpy(new_tree_part->content,self->content,self->content_size);

        if(self->is_binary == false){
            new_tree_part->content[self->content_size] = '\0';
        }

    }



    return new_tree_part;
}

void DtwTreePart_set_any_content( DtwTreePart *self, unsigned char *content, long content_size, bool is_binary){

    DtwTreePart_free_content(self);
    self->is_binary = is_binary;
    self->content = (unsigned char *)malloc(content_size+2);
    memcpy(self->content,content,content_size);
    self->content_size = content_size;


}

void DtwTreePart_set_string_content( DtwTreePart *self, const char *content){
    DtwTreePart_set_any_content(
        self,
        (unsigned char*)content,
        strlen(content),
        false
    );

    self->content[self->content_size] = '\0';
}

void DtwTreePart_set_binary_content( DtwTreePart *self, unsigned char *content, long content_size){
    DtwTreePart_set_any_content(self,content,content_size,true);
}


char *DtwTreePart_get_content_sha( DtwTreePart *self){
    if(self->content == NULL) {
        return NULL;
    }
    if(self->current_sha) {
        free(self->current_sha);
    }
    self->current_sha =dtw_generate_sha_from_any(self->content,self->content_size);;
    return self->current_sha;
}







void DtwTreePart_represent(struct DtwTreePart *self){
    printf("------------------------------------------------------------\n");
    DtwPath_represent(self->path);
    printf("Content Exist in Memory: %s\n",self->content ? "true" : "false");
    printf("Ignore: %s\n",self->ignore ? "true" : "false");

    printf("Content Exist In Hardware: %s\n",self->content_exist_in_hardware ? "true" : "false");
    printf("Is Binary: %s\n",self->is_binary ? "true" : "false");

    if(self->last_modification_in_str){
        printf("Last Modification Time in Unix: %li\n",self->last_modification_time);
        printf("Last Modification Time: %s\n",self->last_modification_in_str);
    }

    printf("Content Size: %ld\n",(long)self->content_size);

    char *content_sha = DtwTreePart_get_content_sha(self);
    if(content_sha){
        printf("Content SHA:  %s\n",content_sha);
    }
    if(self->content && self->is_binary == false){
        printf ("Content: %s\n",(char*)self->content);
    }

    if(self->hawdware_content_sha) {
        printf("Original Hardware SHA:%s\n",self->hawdware_content_sha);
    }

    if(self->is_binary == true){
        printf("Content: Binary\n");
    }

    const char *action = private_dtw_convert_action_to_string(self->pending_action);
    if(action){
        printf("Pending Action: %s\n",action);

    }

}


void DtwTreePart_free_content(struct DtwTreePart *self){
    if(self->content){
        free(self->content);
    }
    self->content = NULL;

}
void DtwTreePart_free(struct DtwTreePart *self){
    if(self->path) {
        DtwPath_free(self->path);
    }

    if(self->hawdware_content_sha) {
        free(self->hawdware_content_sha);
    }
    if(self->current_sha) {
        free(self->current_sha);
    }
    if(self->last_modification_in_str) {
        free(self->last_modification_in_str);
    }
    DtwTreePart_free_content(self);
    free(self);
}

 DtwTreePart * newDtwTreePartEmpty(const char *path){
    DtwTreeProps  props = {.content =DTW_NOT_LOAD,.hadware_data = DTW_NOT_LOAD};
    return newDtwTreePart(
            path,
         props
    );

}


 DtwTreePart * newDtwTreePartLoading(const char *path){
    DtwTreeProps  props = {.content =DTW_LOAD,.hadware_data = DTW_LOAD};
    return newDtwTreePart(
            path,
            props
    );
}










void DtwTreePart_load_content_from_hardware(struct DtwTreePart *self){

    char *path = DtwPath_get_path(self->path);

    if(path == NULL){
        return;
    }


    if(dtw_entity_type(path) != DTW_FILE_TYPE){
        return;
    }

    DtwTreePart_free_content(self);
    self->content = dtw_load_any_content(path,&self->content_size,&self->is_binary);
    self->hardware_content_size = self->content_size;
    self->content_exist_in_hardware = true;


}



bool DtwTreePart_hardware_remove(struct DtwTreePart *self, int transaction){
     if(self->ignore == true){
        return false;
     }
     if(transaction == DTW_SET_AS_ACTION){
        self->pending_action = DTW_REMOVE;
        return false;
     }

    char *path =DtwPath_get_path(self->path);

    remove(path);

    self->content_exist_in_hardware = false;
    return true;
}

bool DtwTreePart_hardware_write(struct DtwTreePart *self, int transaction){
    if(self->ignore == true){
        return false;
    }
    if(transaction == DTW_SET_AS_ACTION){
        self->pending_action = DTW_WRITE;
        return false;
    }
    //means that the content not exist in memory
    if(self->content == NULL){
        char *path = DtwPath_get_path(self->path);
        char *dir = DtwPath_get_dir(self->path);
        int entity_type = dtw_entity_type(path);

        if(entity_type== DTW_NOT_FOUND && dir!= NULL){
            dtw_create_dir_recursively(dir);

        }


        return true;
    }
    char *path = DtwPath_get_path(self->path);

    dtw_write_any_content(path,self->content,(long)self->content_size);
    free(self->hawdware_content_sha);
    self->hawdware_content_sha = dtw_generate_sha_from_any(self->content,self->content_size);
    self->content_exist_in_hardware = true;
    private_DtwTreePart_set_last_modification(self,dtw_get_time());
    return true;

}

bool DtwTreePart_hardware_modify(struct DtwTreePart *self, int transaction){
    if(self->ignore == true){
        return false;
    }
    if(transaction == DTW_SET_AS_ACTION){
        self->pending_action = DTW_MODIFY;
        return false;
    }
    bool changed_path =DtwPath_changed(self->path);


    if(changed_path == true && self->content == NULL){
        char *old_path = self->path->original_path_string;
        char *new_path = DtwPath_get_path(self->path);
        remove(old_path);
        dtw_create_dir_recursively(new_path);
        return true;
    }

    if(changed_path == false  && self->content == NULL){
        return  false;
    }

    bool write = false;
    if(changed_path == true){
        char *old_path = self->path->original_path_string;
        remove(old_path);
        write = true;
    }

    if(changed_path== false){
        if(self->metadata_loaded == true){
            char *hardware_sha = self->hawdware_content_sha;
            char *memory_sha = DtwTreePart_get_content_sha(self);
            if(strcmp(hardware_sha,memory_sha) != 0){
                write = true;
            }
        }
        else{
            write = true;
        }
    }

    if(write){
        char *path = DtwPath_get_path(self->path);
        dtw_write_any_content(
            path,
            self->content,
            (long)self->content_size
        );
        free(self->hawdware_content_sha);
        self->hawdware_content_sha = dtw_generate_sha_from_string((const char *)self->content);
        self->content_exist_in_hardware = true;
        private_DtwTreePart_set_last_modification(self,dtw_get_time());


        return true;
    }
    return false;
}

bool DtwTreePart_hardware_commit(struct DtwTreePart *self){
    if(self->ignore == true){
        return false;
    }
    if(self->pending_action == DTW_REMOVE){
        return DtwTreePart_hardware_remove(self,DTW_EXECUTE_NOW);
    }
    if(self->pending_action == DTW_WRITE){
        return DtwTreePart_hardware_write(self,DTW_EXECUTE_NOW);
    }
    if(self->pending_action == DTW_MODIFY){
        return DtwTreePart_hardware_modify(self,DTW_EXECUTE_NOW);
    }
    return false;
}







bool DtwTree_loads_json_tree(struct DtwTree *self, const char *all_tree){
    //load json
    cJSON *json_tree = cJSON_Parse(all_tree);
    if(json_tree == NULL){
        return false;
    }
    DtwJsonTreeError *json_error = DtwJsonTreeError_validate_json_tree_by_cJSON(json_tree);
    if(json_error){
        DtwJsonTreeError_free(json_error);
        return  false;
    }

    int size = cJSON_GetArraySize(json_tree);
    for(int i = 0; i < size; i++){

        cJSON *json_tree_part = cJSON_GetArrayItem(json_tree, i);
        cJSON *path = cJSON_GetObjectItemCaseSensitive(json_tree_part, "path");
        cJSON *original_path = cJSON_GetObjectItemCaseSensitive(json_tree_part, "original_path");
        cJSON *hardware_sha = cJSON_GetObjectItemCaseSensitive(json_tree_part, "hardware_sha256");
        cJSON *hardware_content_size = cJSON_GetObjectItemCaseSensitive(json_tree_part, "hardware_content_size");
        cJSON *last_modification_in_unix_time = cJSON_GetObjectItemCaseSensitive(json_tree_part, "last_modification_in_unix_time");
        cJSON *content_size = cJSON_GetObjectItemCaseSensitive(json_tree_part, "content_size");
        cJSON *is_binary = cJSON_GetObjectItemCaseSensitive(json_tree_part, "is_binary");
        cJSON *content = cJSON_GetObjectItemCaseSensitive(json_tree_part, "content");
        cJSON *pending_action = cJSON_GetObjectItemCaseSensitive(json_tree_part, "pending_action");
        cJSON *ignore = cJSON_GetObjectItemCaseSensitive(json_tree_part, "ignore");

        struct DtwTreePart *part = newDtwTreePartEmpty(
                path->valuestring
                );

        if(original_path != NULL){
            if(  part->path->original_path_string){
                free(  part->path->original_path_string);
            }
            part->path->original_path_string = strdup(original_path->valuestring);

        }

        if(hardware_sha != NULL){
            part->content_exist_in_hardware = true;
            part->hawdware_content_sha = (char *)realloc(part->hawdware_content_sha,strlen(hardware_sha->valuestring)+1);
            strcpy(part->hawdware_content_sha,hardware_sha->valuestring);

        }

        if(hardware_content_size != NULL){
            part->content_exist_in_hardware = true;
            part->hardware_content_size = hardware_content_size->valueint;
        }

        if(last_modification_in_unix_time != NULL){
            part->last_modification_time = last_modification_in_unix_time->valueint;
        }

        if(is_binary != NULL){
            part->is_binary = is_binary->valueint;
        }

        if(content_size != NULL){
            part->content_size = content_size->valueint;
        }

        if(content != NULL){

            if(part->is_binary){
                long out_size;
                unsigned char *decoded =dtw_base64_decode(
                    content->valuestring,
                    &out_size
                );
                DtwTreePart_set_binary_content(part,decoded,out_size);
                free(decoded);
            }
           else{
                DtwTreePart_set_string_content(part,content->valuestring);
           }
        }
        if(pending_action != NULL &&  pending_action->valuestring){

            part->pending_action = private_dtw_convert_string_to_action(
                pending_action->valuestring
            );
        }
        if(ignore != NULL){
            part->ignore = ignore->valueint;
        }

        DtwTree_add_tree_part_getting_onwership(self, part);

    }
    cJSON_Delete(json_tree);
    return  true;
}


bool DtwTree_loads_json_tree_from_file( DtwTree *self, const char *path){
    char *content = dtw_load_string_file_content(path);
    if(content == NULL){
        return false;
    }
    bool result = DtwTree_loads_json_tree(self,content);
    free(content);
    return result;
}

char * DtwTree_dumps_tree_json( DtwTree *self, DtwTreeProps  props){


    DtwTreeProps formated_props = DtwTreeProps_format_props(props);

    cJSON *json_array = cJSON_CreateArray();
    for(int i = 0; i < self->size; i++){

        cJSON *json_tree_part = cJSON_CreateObject();
        DtwTreePart *tree_part = self->tree_parts[i];
        char *path_string = DtwPath_get_path(tree_part->path);
        if(path_string ==NULL){
            cJSON_Delete(json_tree_part);
            continue;
        }

        if(formated_props.ignored_elements == DTW_INCLUDE && tree_part->ignore){
            continue;
        }

        if(tree_part->ignore){
            cJSON_AddItemToObject(
                json_tree_part,
                "ignore",
                cJSON_CreateBool(true)
            );
        }

        cJSON_AddItemToObject(
            json_tree_part,
            "path",
            cJSON_CreateString(path_string)
        );



        if(formated_props.path_atributes == DTW_INCLUDE ){
                char *dir_string = DtwPath_get_dir(tree_part->path);
                char *full_name_string = DtwPath_get_full_name(tree_part->path);
                char *name_string = DtwPath_get_name(tree_part->path);
                char *extension_string = DtwPath_get_extension(tree_part->path);
                if(tree_part->path->original_path_string != path_string){
                    cJSON_AddItemToObject(
                        json_tree_part,
                        "original_path",
                        cJSON_CreateString(tree_part->path->original_path_string)
                    );
                }
                cJSON_AddItemToObject(
                    json_tree_part,
                    "dir",
                    cJSON_CreateString(dir_string)
                );

                cJSON_AddItemToObject(
                    json_tree_part,
                    "full_name",
                    cJSON_CreateString(full_name_string)
                );

                cJSON_AddItemToObject(
                    json_tree_part,
                    "name",
                    cJSON_CreateString(name_string)
                );

                cJSON_AddItemToObject(
                    json_tree_part,
                    "extension",
                    cJSON_CreateString(extension_string)
                );


        }


        if(formated_props.hadware_data == DTW_INCLUDE && tree_part->metadata_loaded){
            cJSON_AddItemToObject(
                json_tree_part,
                "hardware_sha256",
                cJSON_CreateString(tree_part->hawdware_content_sha)
            );
            cJSON_AddItemToObject(
                json_tree_part,
                "last_modification_in_unix",
                cJSON_CreateNumber(tree_part->last_modification_time)
            );

            cJSON_AddItemToObject(
                json_tree_part,
                "hardware_content_size",
                cJSON_CreateNumber(tree_part->hardware_content_size)
            );

            cJSON_AddItemToObject(
                json_tree_part,
                "last_modification",
                cJSON_CreateString(tree_part->last_modification_in_str)
            );
        }

        if(formated_props.content_data == DTW_INCLUDE && tree_part->content){
            char *content_sha = DtwTreePart_get_content_sha(tree_part);
            cJSON_AddItemToObject(
                json_tree_part,
                "content_size",
                cJSON_CreateNumber(tree_part->content_size)
            );

            cJSON_AddItemToObject(
                json_tree_part,
                "content_sha256",
                cJSON_CreateString(content_sha)
            );

        }

        if(formated_props.content == DTW_INCLUDE && tree_part->content){

            cJSON_AddItemToObject(
                json_tree_part,
                "is_binary",
                cJSON_CreateBool(tree_part->is_binary)
            );
            if(tree_part->is_binary == false){
                cJSON_AddItemToObject(
                    json_tree_part,
                    "content",
                    cJSON_CreateString(DtwTreePart_get_content_string_by_reference(tree_part))
                );
            }
            else{
                char *content_base64 = dtw_base64_encode(tree_part->content, tree_part->content_size);


                cJSON_AddItemToObject(
                    json_tree_part,
                    "content",
                    cJSON_CreateString(content_base64)
                );
                free(content_base64);
            }
        }

        //adding action
        const char *action_string = private_dtw_convert_action_to_string(tree_part->pending_action);
        if(action_string != NULL){
            cJSON_AddItemToObject(
                json_tree_part,
                "pending_action",
                cJSON_CreateString(action_string)
            );
        }
        //Add json_tree_part
        cJSON_AddItemToArray(json_array,json_tree_part);

    }

    char *json_string = cJSON_Print(json_array);
    //set ident to 4 spaces
    if(formated_props.minification == DTW_MIMIFY){
        cJSON_Minify(json_string);
    }
    cJSON_Delete(json_array);
    return json_string;
}

void  DtwTree_dumps_tree_json_to_file(struct DtwTree *self, const char *path, DtwTreeProps  props){
    char *json_string = DtwTree_dumps_tree_json(self,props);
    dtw_write_string_file_content(path,json_string);
    free(json_string);
}





struct DtwTreePart *DtwTree_find_tree_part_by_function(
        struct DtwTree *self,
        bool (*caller)(struct  DtwTreePart *part,void *args),
        void *args
){
    for(int i = 0;i < self->size; i++){
        struct DtwTreePart *current = self->tree_parts[i];
        bool result = caller(current,args);
        if(result){
            return current;
        }
    }
    return NULL;
}

struct DtwTree *DtwTree_filter(
        struct DtwTree *self,
        bool (*caller)(struct  DtwTreePart *part)
){
    DtwTree *filtered_tree = newDtwTree();

    for(int i = 0;i < self->size; i++){

        DtwTreePart *current = self->tree_parts[i];

        bool result = caller(current);

        if(result){
            DtwTree_add_tree_part_copy(filtered_tree,current);
        }

    }
    return filtered_tree;
}


 DtwTree *DtwTree_map(DtwTree *self,DtwTreePart *(*caller)( DtwTreePart *part)){
     DtwTree *mapped_tree = newDtwTree();

    for(int i = 0;i < self->size; i++){
         DtwTreePart *current = self->tree_parts[i];
         DtwTreePart *copy = DtwTreePart_self_copy(current);
         DtwTreePart *result = caller(copy);
        DtwTree_add_tree_part_getting_onwership(mapped_tree, result);
    }
    return mapped_tree;
}


 DtwTreePart *DtwTree_find_tree_part_by_name( DtwTree *self, const char *name){
    for(int i = 0;i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_name = DtwPath_get_full_name(current_path);
        if(current_name){

            if(strcmp(current_name, name) == 0){
                return current;
            }
        }

    }

    return NULL;
}

 DtwTreePart *DtwTree_find_tree_part_by_path( DtwTree *self, const char *path){
    for(int i = 0;i < self->size; i++){
         DtwTreePart *current = self->tree_parts[i];
         DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);
        if(current_path_string){
            if(strcmp(current_path_string, path) == 0){
                return current;
            }
        }

    }

    return NULL;
}





//listages
 DtwStringArray *DtwTree_list_files( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char =='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            //means its not an path from these dimension
            int path_size = strlen(path);
            bool insert = true;

            for(int i =path_size +1; i < size;i++){
                if(current_path_string[i] == '/'){
                    insert = false;
                    continue;
                }
            }

            if(insert){
                DtwStringArray_append(formated_elements,current_path_string);
            }

        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

 DtwStringArray *DtwTree_list_dirs( DtwTree *self, const char *path,bool concat_path){

    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char !='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            //means its not an path from these dimension
            int path_size = strlen(path);

            int total_found = 0;
            for(int i =path_size +1; i < size;i++){
                if(current_path_string[i] == '/'){
                    total_found+=1;
                    continue;
                }
            }

            if(total_found ==1){
                DtwStringArray_append(formated_elements,current_path_string);
            }

        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

struct DtwStringArray *DtwTree_list_all( DtwTree *self, const char *path,bool concat_path){

    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        if(dtw_starts_with(current_path_string,path)){
            //means its not an path from these dimension
            int path_size = strlen(path);
            long size = strlen(current_path_string);
            char last_char = current_path_string[size-1];

            int total_found = 0;
            for(int i =path_size+1; i < size;i++){
                if(current_path_string[i] == '/'){
                    total_found+=1;
                    continue;
                }
            }

            if(total_found ==1 && last_char == '/'){
                DtwStringArray_append(formated_elements,current_path_string);
            }
            if(total_found ==0){
                DtwStringArray_append(formated_elements,current_path_string);

            }



        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;

}

 DtwStringArray *DtwTree_list_files_recursively( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);


        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char =='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            DtwStringArray_append(formated_elements,current_path_string);

        }


    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}

 DtwStringArray *DtwTree_list_dirs_recursively( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);

        long size = strlen(current_path_string);
        char last_char = current_path_string[size-1];
        if(last_char !='/'){
            continue;
        }

        if(dtw_starts_with(current_path_string,path)){
            DtwStringArray_append(formated_elements,current_path_string);

        }

    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}


 DtwStringArray *DtwTree_list_all_recursively( DtwTree *self, const char *path,bool concat_path){
    DtwStringArray *formated_elements = newDtwStringArray();
    for(int i = 0; i < self->size; i++){
        DtwTreePart *current = self->tree_parts[i];
        DtwPath *current_path = current->path;
        char *current_path_string = DtwPath_get_path(current_path);



        if(dtw_starts_with(current_path_string,path)){
            DtwStringArray_append(formated_elements,current_path_string);

        }

    }
    if(!concat_path){

        DtwStringArray  *not_concatened = private_dtw_remove_start_path(formated_elements,path);
        DtwStringArray_free(formated_elements);
        return not_concatened;
    }


    return formated_elements;
}







struct  DtwTree * newDtwTree(){

    struct DtwTree *self = (struct DtwTree*)malloc(sizeof(struct DtwTree));
    self->size = 0;
    self->tree_parts = (struct DtwTreePart**)malloc(1);

    return self;
}


struct DtwTree *DtwTree_get_sub_tree(struct DtwTree *self, const char *path, bool copy_content){
    struct DtwTree *sub_tree = newDtwTree();
    for(int i = 0; i < self->size; i++){
        struct DtwTreePart *tree_part = self->tree_parts[i];
        char *current_path =  DtwPath_get_path(tree_part->path);
        if(dtw_starts_with(current_path,path)){
            if(copy_content){
                DtwTree_add_tree_part_copy(sub_tree,tree_part);
            }
            if(!copy_content){
                DtwTree_add_tree_part_referencing(sub_tree, tree_part);
            }
        }
    }
    return sub_tree;
}

void DtwTree_add_tree_part_referencing(struct DtwTree *self, struct DtwTreePart *tree_part) {
    self->size++;
    self->tree_parts =  (struct DtwTreePart**)realloc(self->tree_parts, self->size * sizeof(struct DtwTreePart *));
    self->tree_parts[self->size - 1] = tree_part;
}

void DtwTree_add_tree_part_copy( DtwTree *self,  DtwTreePart *tree_part){
    self->size++;
    self->tree_parts =  (struct DtwTreePart**)realloc(self->tree_parts, self->size * sizeof(struct DtwTreePart *));
    DtwTreePart *copy = DtwTreePart_self_copy(tree_part);
    copy->owner = (void*)self;
    self->tree_parts[self->size - 1] = copy;

}

void DtwTree_remove_tree_part(struct DtwTree *self, int position){

    self->size--;
    DtwTreePart_free(self->tree_parts[position]);

    for(int i = position; i<self->size; i++){
        self->tree_parts[i] = self->tree_parts[i+1];
    }


}

struct DtwTreeTransactionReport * DtwTree_create_report(struct DtwTree *self){
    struct DtwTreeTransactionReport *report = newDtwTreeTransactionReport();
    for(int i = 0; i < self->size; i++){
        struct DtwTreePart *tree_part = self->tree_parts[i];
        int pending_action = tree_part->pending_action;
        char *path = DtwPath_get_path(tree_part->path);

        if (pending_action == DTW_WRITE){
            DtwStringArray_append(report->write, path);
        }

        else if (pending_action == DTW_MODIFY){
            DtwStringArray_append(report->modify, path);
        }

        else if (pending_action == DTW_REMOVE){
            DtwStringArray_append(report->remove, path);
        }


    }
    return report;
}


void DtwTree_add_tree_part_getting_onwership( DtwTree *self,  DtwTreePart *tree_part){
    DtwTree_add_tree_part_referencing(self,tree_part);
    tree_part->owner = (void*)self;
}



void DtwTree_represent( DtwTree *self){
    for(int i = 0; i < self->size; i++){
        DtwTreePart_represent(self->tree_parts[i]);
    }
}

void DtwTree_add_tree_parts_from_string_array( DtwTree *self,  DtwStringArray *paths,DtwTreeProps props){
    for(int i = 0; i < paths->size; i++){

        const char *current_path = paths->strings[i];
         DtwTreePart *tree_part = newDtwTreePart(
                current_path,
                props
        );

        DtwTree_add_tree_part_getting_onwership(self, tree_part);
    }
}


void DtwTree_add_tree_from_hardware( DtwTree *self,const char *path, DtwTreeProps props){
    DtwTreeProps formated_props = DtwTreeProps_format_props(props);
    struct DtwStringArray *path_array = dtw_list_all_recursively(path,DTW_CONCAT_PATH);
    DtwStringArray_sort(path_array);
    DtwTree_add_tree_parts_from_string_array(self, path_array,props);
    DtwStringArray_free(path_array);


    if(formated_props.path_atributes == DTW_INCLUDE){
        return;
    }
    if(self->size == 0){
        return;
    }
    DtwTree_remove_tree_part(self,0);

    int size_to_remove = strlen(path);
    if(!dtw_ends_with(path,"/")){
        size_to_remove+=1;
    }

    for(int i =0; i < self->size; i++){
         DtwTreePart *current_part = self->tree_parts[i];
         DtwPath *current_path = current_part->path;
        char *current_path_string = DtwPath_get_path(current_path);
        //remove the size toremove from string

        memmove(
                current_path_string,
                current_path_string+size_to_remove,
                strlen(current_path_string) - size_to_remove +1
                );
        DtwPath_set_path(current_path,current_path_string);

        current_path->original_path_string = current_path_string;

    }

}

void DtwTree_free( DtwTree *self){
    for(int i = 0; i < self->size; i++){
        DtwTreePart * part = self->tree_parts[i];
        if(part->owner == (void*)self) {
            DtwTreePart_free(part);

        }

    }

    free(self->tree_parts);
    free(self);
}
void DtwTree_insecure_hardware_remove_tree(struct DtwTree *self){
    for(int i = 0; i < self->size; i++){
        DtwTreePart_hardware_remove(self->tree_parts[i],DTW_EXECUTE_NOW);
    }
}

void DtwTree_insecure_hardware_write_tree(struct DtwTree *self){

    for(int i = 0; i < self->size; i++){
        struct DtwTreePart *tree_part = self->tree_parts[i];
        DtwTreePart_hardware_write(tree_part,DTW_EXECUTE_NOW);
    }
}

void DtwTree_hardware_commit_tree(struct DtwTree *self){
    for(int i = 0; i < self->size; i++){
        DtwTreePart_hardware_commit(self->tree_parts[i]);
    }
}













DtwMultiFileLocker *newDtwMultiFileLocker(){
    DtwMultiFileLocker *self = (DtwMultiFileLocker*) malloc(sizeof (DtwMultiFileLocker));

    self->process = getpid();
    self->total_checks = DTW_MULTIFILE_LOCKER_TOTAL_CHECK;
    self->max_lock_time = DTW_MULTIFILE_LOCKER_MAX_TIMEOUT;
    self->max_wait = DTW_MULFILE_LOCKER_MAX_WAIT;
    self->locked_elements = newDtwStringArray();

    return self;
}




int  DtwMultiFIleLocker_lock(DtwMultiFileLocker *self, const char *element) {

    if(DtwStringArray_find_position(self->locked_elements,element) != -1){
        return DTW_LOCKER_LOCKED;
    }

    const char *LOCK_FOLDER = ".lock";
    const int LOCK_FOLDER_SIZE = (int)strlen(LOCK_FOLDER);
    char *file = (char*)malloc(strlen(element) +  LOCK_FOLDER_SIZE + 10);
    sprintf(file,"%s%s",element,LOCK_FOLDER);
    long started_time = time(NULL);

    while (true){


        long now = time(NULL);
        if((now - started_time) > self->max_wait){
            free(file);
            return DTW_LOCKER_WAIT_ERROR;
        }


         bool write = false;
         int entity_type = dtw_entity_type(file);
         if(entity_type== DTW_NOT_FOUND){
            write = true;
         }

         if(entity_type== DTW_FILE_TYPE){
             long last_modification  = dtw_get_entity_last_motification_in_unix(file);
             if ((now - self->max_lock_time) > last_modification ) {
                 write = true;
             }
         }

         if(entity_type == DTW_FOLDER_TYPE){
             dtw_remove_any(file);
             continue;
         }


         if(!write) {
             continue;
         }
        dtw_write_long_file_content(file,self->process);
        bool break_loop = true;
         for(int i = 0;i < self->total_checks;i++){
            long result = dtw_load_long_file_content(file);
            if(result != self->process && result != -1){
                break_loop = false;
                break;
            }
        }

        if(break_loop){
            break;

        }


    }
    DtwStringArray_append(self->locked_elements,element);
    free(file);
    return DTW_LOCKER_LOCKED;

}

void DtwMultifileLocker_unlock(DtwMultiFileLocker *self, const  char *element){
    bool found = false;
    for(long i = 0; i < self->locked_elements->size;i++){
        if(strcmp(self->locked_elements->strings[i],element)==0){
            found = true;
            break;
        }
    }

    if(!found){
        return;
    }


    const char *LOCK_FOLDER = ".lock";
    const int LOCK_FOLDER_SIZE = (int)strlen(LOCK_FOLDER);
    char *file = (char*)malloc(strlen(element) +  LOCK_FOLDER_SIZE + 10);
    sprintf(file,"%s%s",element,LOCK_FOLDER);
    dtw_remove_any(file);
    free(file);
}


void DtwMultiFileLocker_represemt(DtwMultiFileLocker *self){
    printf("locked:\n");
    for(int i = 0 ; i < self->locked_elements->size;i++){
        char *element = self->locked_elements->strings[i];
        char *unformated = dtw_replace_string(element,".lock","");
        printf("\t%s\n",unformated);
        free(unformated);
    }
}

void DtwMultiFileLocker_free(DtwMultiFileLocker *self){

    for(int i = 0 ; i < self->locked_elements->size;i++){
        char *element = self->locked_elements->strings[i];
        DtwMultifileLocker_unlock(self, element);
    }

    DtwStringArray_free(self->locked_elements);
    free(self);
}


#ifdef __linux__
    



privateDtwFlockLockedElement * private_new_privateDtwFlockLockedElement(const char *filename, int file_descriptor){
    privateDtwFlockLockedElement *self = (privateDtwFlockLockedElement*) malloc(sizeof (privateDtwFlockLockedElement));
    self->filename = strdup(filename);
    self->file_descriptor = file_descriptor;
    return  self;
}

void privateDtwFlockLockedElement_represent(privateDtwFlockLockedElement *self){
    printf("file: %s\n",self->filename);
    printf("if: %d\n",self->file_descriptor);

}
void privateDtwFlockLockedElement_free(privateDtwFlockLockedElement *self){
    free(self->filename);
    free(self);

}





privateDtwFlockArray * private_new_privateFlockArray(){
    privateDtwFlockArray * self = (privateDtwFlockArray*) malloc(sizeof (privateDtwFlockArray));
    self->elements = (privateDtwFlockLockedElement **) malloc(0);
    self->size = 0;
    return self;
}


int  privateDtwFlockArray_index_of(privateDtwFlockArray *self, const char *filename){
    for(int i = 0 ; i <self->size;i++){
        privateDtwFlockLockedElement  *current = self->elements[i];
        if(strcmp(current->filename,filename) ==0){
            return  i;
        }
    }
    return  -1;
}
void privateDtwFlockArray_append(privateDtwFlockArray *self, const char *filename, int file_descriptor){

    self->elements = (privateDtwFlockLockedElement**) realloc(
            self->elements,
            sizeof(privateDtwFlockLockedElement**) * (self->size + 1)
            );
    privateDtwFlockLockedElement  *created = private_new_privateDtwFlockLockedElement(filename, file_descriptor);
    self->elements[self->size] = created;
    self->size+=1;
}

void privateDtwFlockArray_destroy_by_index(privateDtwFlockArray *self, int position){
    if(position >= self->size){
        return ;
    }
    privateDtwFlockLockedElement *finded = self->elements[position];
    privateDtwFlockLockedElement_free(finded);
    for(int i = position; i  < self->size-1; i++){
        self->elements[i] = self->elements[i+1];
    }
    self->size-=1;
}


void privateDtwFlockArray_represent(privateDtwFlockArray *self){
    for(int i = 0 ; i <self->size;i++){

        privateDtwFlockLockedElement  *current = self->elements[i];
        printf("=============================\n");
        privateDtwFlockLockedElement_represent(current);
    }
}

void privateDtwFlockArray_free(privateDtwFlockArray *self){
    for(int i = 0 ; i <self->size;i++){
        privateDtwFlockLockedElement  *current = self->elements[i];
        privateDtwFlockLockedElement_free(current);
    }
    free(self->elements);
    free(self);
}






DtwFlockLocker * newFlockLocker(){

    DtwFlockLocker *self = (DtwFlockLocker*) malloc(sizeof (DtwFlockLocker));
    *self  = (DtwFlockLocker){0};
    self->locked_files = private_new_privateFlockArray();
    self->temp_folder = "/tmp/";

    return self;
}
int  DtwFlockLocker_lock(DtwFlockLocker *self, const char *filename) {
    if (privateDtwFlockArray_index_of(self->locked_files, filename) != -1) {
        return DTW_LOCKER_LOCKED;
    }

    char *file_sha = dtw_generate_sha_from_string(filename);
    const char *EXTENSION = "lock";
    char *formatted = (char *) malloc(
            strlen(file_sha) +
            strlen(self->temp_folder) +
            strlen(EXTENSION) +
            3
    );
    sprintf(formatted, "%s/%s.%s", self->temp_folder, file_sha, EXTENSION);

    free(file_sha);
    int fd = open(formatted, O_RDWR | O_CREAT, 0644);
    free(formatted);
    if (fd == -1) {
        return DTW_LOCKER_IMPOSSIBLE_TO_CREATE_FILE_DESCRIPTOR;
    }
    if (flock(fd, LOCK_EX) == -1) {
        close(fd);
        return DTW_LOCKER_FLCTL_FAIL;
    }
    privateDtwFlockArray_append(self->locked_files, filename, fd);
    return  DTW_LOCKER_LOCKED;
}

void private_FlockLocker_unlock_by_index(DtwFlockLocker *self, int index){
    privateDtwFlockLockedElement  *element = self->locked_files->elements[index];
    flock(element->file_descriptor, LOCK_UN);
    close(element->file_descriptor);
}
void DtwFlockLocker_unlock(DtwFlockLocker *self, const char *filename){
    int index = privateDtwFlockArray_index_of(self->locked_files, filename);
    if(index == -1){
        return;
    }
    private_FlockLocker_unlock_by_index(self,index);
}
void  DtwFlockLocker_represent(DtwFlockLocker *self){
    privateDtwFlockArray_represent(self->locked_files);
}
void  DtwFlockLocker_free(DtwFlockLocker *self){
    for(int i = 0 ; i < self->locked_files->size; i++){
        private_FlockLocker_unlock_by_index(self,i);
    }
    privateDtwFlockArray_free(self->locked_files);
    free(self);
}



#endif





DtwLocker *newDtwLocker(){

    DtwLocker *self = (DtwLocker*)malloc(sizeof(DtwLocker));
#ifdef __linux__
    self->locker = newFlockLocker();
#endif
#ifdef _WIN32
    self->locker = newDtwMultiFileLocker();
#endif
    return self;
}

int DtwLocker_lock(DtwLocker *self, const  char *element){

#ifdef __linux__
    return DtwFlockLocker_lock(self->locker,element);
#endif
#ifdef _WIN32
    return DtwMultiFIleLocker_lock(self->locker,element);
#endif
    return  DTW_LOCKER_OS_NOT_PREDICTIBLE;
}

void DtwLocker_unlock(DtwLocker *self, const  char *element){

#ifdef __linux__
    DtwFlockLocker_unlock(self->locker,element);
#endif
    #ifdef _WIN32
         DtwMultifileLocker_unlock(self->locker,element);
    #endif
}

void DtwLocker_represemt(DtwLocker *self){

#ifdef __linux__
    DtwFlockLocker_represent(self->locker);
#endif
#ifdef _WIN32
     DtwMultiFileLocker_represemt(self->locker);
#endif
}

void DtwLocker_free(DtwLocker *self){

#ifdef __linux__
    DtwFlockLocker_free(self->locker);
#endif

#ifdef _WIN32
     DtwMultiFileLocker_free(self->locker);
#endif
    free(self);
}







DtwSchema *private_newDtwSchema(const char *name){
    DtwSchema *self = (DtwSchema*) malloc(sizeof (DtwSchema));
    *self = (DtwSchema){0};
    self->value_name = DTW_SCHEMA_DEFAULT_VALUES_NAME;
    self->index_name = DTW_SCHEMA_DEFAULT_INDEX_NAME;
    self->sub_schemas = ( DtwSchema **)malloc(0);
    if(name){
        self->primary_keys = newDtwStringArray();
        self->name = strdup(name);
    }

    return  self;
}


DtwSchema * privateDtwSchema_get_sub_schema(DtwSchema *self,const char *name){

    for(int i = 0; i < self->size; i++){
        DtwSchema  *current = self->sub_schemas[i];

        if(strcmp(current->name,name) == 0){
            return  current;
        }
    }
    return NULL;
}

DtwSchema * DtwSchema_new_subSchema(DtwSchema *self,const char *name){
    DtwSchema *subSchema = private_newDtwSchema(name);
    self->sub_schemas = ( DtwSchema **) realloc(self->sub_schemas, (self->size + 1) * sizeof( DtwSchema *));
    self->sub_schemas[self->size] = subSchema;
    self->size+=1;
    return subSchema;
}


void DtwSchema_add_primary_key(DtwSchema *self,const char *name){
    DtwStringArray_append(self->primary_keys,name);
}

void private_newDtwSchema_free(DtwSchema *self){


    for (int i = 0; i < self->size; i++) {
        private_newDtwSchema_free((DtwSchema *) self->sub_schemas[i]);
    }

    free(self->sub_schemas);
    if(self->name){
        free(self->name);
    }
    if(self->primary_keys){
        DtwStringArray_free(self->primary_keys);
    }
    free(self);
}





DtwDatabaseSchema *private_newDtwDtatabaseSchema(){
    DtwDatabaseSchema *self = (DtwDatabaseSchema*) malloc(sizeof (DtwDatabaseSchema));
    *self = (DtwDatabaseSchema){0};
    self->value_name = DTW_SCHEMA_DEFAULT_VALUES_NAME;
    self->index_name = DTW_SCHEMA_DEFAULT_INDEX_NAME;
    self->sub_schemas = (struct DtwSchema **)malloc(0);
    return  self;
}


DtwSchema * privateDtwDtatabaseSchema_get_sub_schema(DtwDatabaseSchema *self,const char *name){

    for(int i = 0; i < self->size; i++){
        DtwSchema  *current = self->sub_schemas[i];

        if(strcmp(current->name,name) == 0){
            return  current;
        }

    }
    return NULL;
}

DtwSchema * DtwDtatabaseSchema_new_subSchema(DtwDatabaseSchema *self,const char *name){
    DtwSchema *subSchema = private_newDtwSchema(name);
    self->sub_schemas = ( DtwSchema **) realloc(self->sub_schemas, (self->size + 1) * sizeof( DtwSchema *));
    self->sub_schemas[self->size] = subSchema;
    self->size+=1;
    return subSchema;
}



void private_new_DtwDtatabaseSchema_free(DtwDatabaseSchema *self){
    for (int i = 0; i < self->size; i++) {
        private_newDtwSchema_free((DtwSchema *) self->sub_schemas[i]);
    }
    free(self->sub_schemas);
    free(self);
}






privateDtwResourceRootProps *private_newDtwResourceRootProps(){
    privateDtwResourceRootProps *self  = (privateDtwResourceRootProps*) malloc(sizeof (privateDtwResourceRootProps));
    *self = (privateDtwResourceRootProps){0};
    self->transaction = newDtwTransaction();
    self->randonizer = newDtwRandonizer();
    self->locker = newDtwLocker();
    self->error_code = DTW_RESOURCE_OK;

    return self;
}


void privateDtwResourceRootProps_free(privateDtwResourceRootProps *self){
    DtwTransaction_free(self->transaction);
    DtwRandonizer_free(self->randonizer);
    DtwLocker_free(self->locker);
    if(self->error_path){
        free(self->error_path);
    }

    if(self->error_message){
        free(self->error_message);
    }



    free(self);
}






DtwResource *new_DtwResource(const char *path){
    DtwResource *self = (DtwResource*) malloc(sizeof (DtwResource));
    *self =(DtwResource){0};

    self->path = strdup(path);
    self->name = strdup(path);
    self->sub_resources = newDtwResourceArray();
    self->allow_transaction = true;
    self->use_locker_on_unique_values = true;
    self->cache_sub_resources = true;
    self->root_props = private_newDtwResourceRootProps();

    return self;
}

DtwResource * DtwResource_sub_resource(DtwResource *self,const  char *format, ...){
    if(DtwResource_error(self)){
        return NULL;
    }


    privateDtwResource_ensure_its_possible_to_sub_resource(self);

    if(DtwResource_error(self)){
        return NULL;
    }


    if(self->were_renamed){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_RENAMED_RESOURCE_CANNOT_HAVE_SONS,
                "you cannot create a sub resurce from a renamed resource",
                self->name
        );
        return NULL;
    }


    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource * Already_Exist = DtwResourceArray_get_by_name((DtwResourceArray*)self->sub_resources,name);
    if(Already_Exist){
        free(name);
        return Already_Exist;
    }

    DtwResource *new_element = (DtwResource*) malloc(sizeof (DtwResource));
    *new_element =(DtwResource){0};

    if(self->schema_type == PRIVATE_DTW_SCHEMA_VALUE){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_ELEMENT;
    }
    if(self->schema_type ==PRIVATE_DTW_SCHEMA_ELEMENT){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_ELEMENT_PROP;
    }

    if(self->schema_type == PRIVATE_DTW_SCHEMA_INDEX){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_PK_FOLDER;
    }
    if(self->schema_type == PRIVATE_DTW_SCHEMA_PK_FOLDER){
        new_element->schema_type = PRIVATE_DTW_SCHEMA_PK_VALUE;
    }



    new_element->allow_transaction = self->allow_transaction;
    new_element->use_locker_on_unique_values = self->use_locker_on_unique_values;
    new_element->root_props = self->root_props;
    //copied elements

    new_element->mother = self;
    new_element->path = dtw_concat_path(self->path, name);
    new_element->name = strdup(name);


    new_element->cache_sub_resources = self->cache_sub_resources;
    new_element->sub_resources = newDtwResourceArray();

    if(self->datatabase_schema && self->root_props->schema_unsafe == false){
        new_element->attached_schema = privateDtwDtatabaseSchema_get_sub_schema(self->datatabase_schema, name);
    }

    if(self->schema_type == PRIVATE_DTW_SCHEMA_ELEMENT){
        DtwResource * ancestor = self->mother->mother;
        new_element->attached_schema = privateDtwSchema_get_sub_schema(ancestor->attached_schema, name);
    }



    if(new_element->attached_schema){
        privateDtwSchemaUnsafe({
            new_element->schema_type = PRIVATE_DTW_SCHEMA_ROOT;
            new_element->values_resource = DtwResource_sub_resource(new_element,DTW_SCHEMA_DEFAULT_VALUES_NAME);
            new_element->values_resource->schema_type = PRIVATE_DTW_SCHEMA_VALUE;
            new_element->index_resource = DtwResource_sub_resource(new_element,DTW_SCHEMA_DEFAULT_INDEX_NAME);
            new_element->index_resource->schema_type = PRIVATE_DTW_SCHEMA_INDEX;
        })

    }



    if(self->cache_sub_resources){
        DtwResourceArray_append((DtwResourceArray*)self->sub_resources,new_element);
    }


    free(name);
    return new_element;

}
DtwResource * DtwResource_sub_resource_ensuring_not_exist(DtwResource *self,const  char *format, ...){
    if(DtwResource_error(self)){
        return NULL;
    }
    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);
;

    DtwResource *possible_emptiy  = DtwResourceArray_get_by_name(
            (DtwResourceArray*)self->sub_resources,
            name
    );
    if(possible_emptiy){
        free(name);
        return NULL;
    }

    bool old_cache_value = self->cache_sub_resources;
    self->cache_sub_resources = false;
    possible_emptiy = DtwResource_sub_resource(self,"%s",name);
    possible_emptiy->cache_sub_resources = old_cache_value;
    self->cache_sub_resources = old_cache_value;
    if(self->use_locker_on_unique_values){
        DtwResource_lock(possible_emptiy);
    }

    int type = DtwResource_type(possible_emptiy);

    if(type == DTW_NOT_FOUND){


            if(self->cache_sub_resources){
                DtwResourceArray_append((DtwResourceArray*)self->sub_resources,possible_emptiy);
            }
            free(name);
            return possible_emptiy;
    }
    DtwResource_unlock(possible_emptiy);
    DtwResource_free(possible_emptiy);
    free(name);
    return  NULL;

}

void DtwResource_free(DtwResource *self){
    if(!self){
        return;
    }

    bool is_root = self->mother == NULL;
    if(is_root){
        privateDtwResourceRootProps_free(self->root_props);
    }

    if(self->datatabase_schema){
        private_new_DtwDtatabaseSchema_free(self->datatabase_schema);
    }

    DtwResourceArray_free((DtwResourceArray*)self->sub_resources);



    if(self->value_any){
        free(self->value_any);
    }


    free(self->path);
    free(self->name);
    free(self);
}






DtwResource * DtwResource_sub_resource_next(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    long  size = dtw_get_total_itens_of_dir(self->path);
    if(size < 0){
        size = 0;
    }
    while(true){

        char *path = NULL;
        if(end_path){
            path = private_dtw_realoc_formatting(path,"%ld%s",size,end_path);
        }

        else{
            path = private_dtw_realoc_formatting(path,"%ld",size);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(
            self,"%s",
            path
        );
        free(path);

        if(DtwResource_error(self)){
            return NULL;
        }

        if(new_element){
            return new_element;
        }
        size = size+1;
    }
}


DtwResource * DtwResource_sub_resource_now(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    bool empty_already_exist = false;


    while(true){

        long now = dtw_get_time();
        char *time = dtw_convert_unix_time_to_string(now);
        char *path = NULL;

        if(empty_already_exist){
            char *token = DtwRandonizer_generate_token(self->root_props->randonizer,10);
            path = private_dtw_realoc_formatting(path,"%s--%s",time,token);
            free(token);
        }
        else{
            path = private_dtw_realoc_formatting(path,"%s",time);
        }

        free(time);

        if(end_path){
            path = private_dtw_realoc_formatting(path,"%s%s",path,end_path);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);

        free(path);


        if(DtwResource_error(self)){
            return NULL;
        }
        if(new_element){
            return new_element;
        }
        empty_already_exist = true;
    }
}


DtwResource * DtwResource_sub_resource_now_in_unix(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    bool empty_already_exist = false;

    while(true){

        long now = dtw_get_time();
        char *path = NULL;

        if(empty_already_exist){
            char *token = DtwRandonizer_generate_token(self->root_props->randonizer,10);
            path = private_dtw_realoc_formatting(path,"%ld--%s",now,token);
            free(token);
        }
        else{
            path = private_dtw_realoc_formatting(path,"%ld",now);
        }

        if(end_path){
            path = private_dtw_realoc_formatting(path,"%s%s",path,end_path);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);

        free(path);


        if(DtwResource_error(self)){
            return NULL;
        }
        if(new_element){
            return new_element;
        }
        empty_already_exist = true;
    }
}

DtwResource * DtwResource_sub_resource_random(DtwResource *self, const char *end_path){
    if(DtwResource_error(self)){
        return NULL;
    }
    while(true){

        char *path = NULL;
        char *token = DtwRandonizer_generate_token(self->root_props->randonizer,15);
        path = private_dtw_realoc_formatting(path,"%s",token);
        free(token);

        if(end_path){
            path = private_dtw_realoc_formatting(path,"%s%s",path,end_path);
        }

        DtwResource *new_element = DtwResource_sub_resource_ensuring_not_exist(self,"%s",path);
        free(path);
        if(DtwResource_error(self)){
            return NULL;
        }

        if(new_element){
            return new_element;
        }

    }
}





void private_DtwResurce_destroy_primary_key(DtwResource *self) {


    if (!DtwResource_is_file(self)) {
        return;
    }

    DtwResource *root = self->mother->mother->mother;
    DtwResource *pk_index_folder = DtwResource_sub_resource(root->index_resource, "%s", self->name);
    long size;
    bool is_binary;
    unsigned char *possible_pk_value = DtwResource_get_any(self, &size, &is_binary);
    char *pk_sha = dtw_generate_sha_from_any(possible_pk_value, size);

    DtwResource *pk_index_value = DtwResource_sub_resource(pk_index_folder, "%s", pk_sha);

    if(DtwResource_error(self)){
        return;
    }

    free(pk_sha);
    if (self->allow_transaction) {
        DtwTransaction_delete_any(self->root_props->transaction, pk_index_value->path);
    } else {
        dtw_remove_any(pk_index_value->path);
    }


}
void private_DtwResource_destroy_all_primary_keys(DtwResource *self){
    DtwSchema * schema = (DtwSchema*)self->mother->mother->attached_schema;
    for(int i = 0; i < schema->primary_keys->size; i++){
        char *current_pk = schema->primary_keys->strings[i];
        DtwResource *son = DtwResource_sub_resource(self,"%s",current_pk);
        private_DtwResurce_destroy_primary_key(son);

        if(DtwResource_error(self)){
            return;
        }

    }
}
void DtwResource_destroy(DtwResource *self){
    if(DtwResource_error(self)){
        return;
    }


    if(self->schema_type == PRIVATE_DTW_SCHEMA_ELEMENT){
        privateDtwSchemaUnsafe({
            private_DtwResource_destroy_all_primary_keys(self);

        })
    }

    if(private_DtwResource_its_a_pk(self)){
        privateDtwSchemaUnsafe({
            private_DtwResurce_destroy_primary_key(self);
        })
    }

    if(DtwResource_error(self)){
        return;
    }

    if(self->root_props->schema_unsafe == false){
        if(
                self->schema_type == PRIVATE_DTW_SCHEMA_VALUE
                || self->schema_type == PRIVATE_DTW_SCHEMA_INDEX
                || self->schema_type == PRIVATE_DTW_SCHEMA_PK_FOLDER
                || self->schema_type == PRIVATE_DTW_SCHEMA_PK_VALUE
        ){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS,
                    "you cannot delete a internal schema part"
            );
        }
    }

    if(DtwResource_error(self)){
        return;
    }


    if(self->allow_transaction){
        DtwTransaction_delete_any(self->root_props->transaction,self->path);
    }
    else{
        dtw_remove_any(self->path);
    }

}

void DtwResource_destroy_sub_resource(DtwResource *self, const char *key){
    if(DtwResource_error(self)){
        return;
    }
    DtwResource *son = DtwResource_sub_resource(self, "%s",key);
    DtwResource_destroy(son);
}







bool DtwResource_error(DtwResource *self){
    if(self==NULL){
        return true;
    }
    if(DtwResource_get_error_code(self) == DTW_RESOURCE_OK){
        return false;
    }
    return true;
}



int DtwResource_get_error_code(DtwResource *self){
    if(self == NULL){
        return DTW_RESOURCE_ELEMENT_IS_NULL;
    }
    return self->root_props->error_code;
}
char * DtwResource_get_error_path(DtwResource *self){
    if(self == NULL){
        return NULL;
    }

    if(self->root_props == NULL){
        return NULL;
    }
    return self->root_props->error_path;
}


char * DtwResource_get_error_message(DtwResource *self){

    if(self== NULL){
        return (char*)"element its null";
    }

    return self->root_props->error_message;
}
void  DtwResource_clear_errors(DtwResource *self){
    if(!DtwResource_error(self)){
        return;
    }
    free(self->root_props->error_message);
    self->root_props->error_message = NULL;
    free(self->root_props->error_path);
    self->root_props->error_path = NULL;
    self->root_props->error_code = DTW_RESOURCE_OK;

}


void  private_DtwResource_raise_error(DtwResource *self, int error_code, const char *format,...){

    va_list args;
    va_start(args, format);
    char *error_message = private_dtw_format_vaarg(format,args);
    va_end(args);

    self->root_props->error_code = error_code;
    self->root_props->error_path = strdup(self->path);
    self->root_props->error_message = dtw_replace_string(error_message,"#path#",self->path);
    free(error_message);
}

void DtwResource_rename(DtwResource *self,const char *new_name){
    if(DtwResource_error(self)){
        return;
    }
    if(private_DtwResource_its_a_pk(self)){
        private_DtwResource_raise_error(
                self,
                DTW_IMPOSSIBLE_TO_RENAME_A_PRIMARY_KEY,
                "primary key %s cannot be renamed",
                self->name
        );
        return;
    }
    DtwResourceArray *sons =(DtwResourceArray*)self->sub_resources;
    if(sons->size > 0){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_RENAMED_RESOURCE_CANNOT_HAVE_SONS,
                "you cannot rename a resource with active sons",
                self->name
        );
        return;
    }

    self->were_renamed = true;
    char *old_path = strdup(self->path);
    free(self->path);
    free(self->name);

    if(self->mother){
        self->path  = dtw_concat_path(self->mother->path, new_name);
    }
    if(self->mother==NULL){
        self->path = strdup(new_name);
    }

    self->name = strdup(new_name);

    if(self->allow_transaction){
        DtwTransaction_move_any(self->root_props->transaction,old_path,self->path);
    }
    else{
        dtw_move_any(old_path,self->path,DTW_NOT_MERGE);
    }

    free(old_path);

}

void DtwResource_rename_sub_resource(DtwResource *self,const char *old_name,const  char *new_name){
    if(DtwResource_error(self)){
        return;
    }

    DtwResource *created = DtwResource_sub_resource(self,"name");
    DtwResource_rename(created,new_name);
}

int DtwResource_lock(DtwResource *self){
    if(DtwResource_error(self)){
        return -1;
    }
    return DtwLocker_lock(self->root_props->locker, self->path);
}

void DtwResource_unlock(DtwResource *self){
    if(DtwResource_error(self)){
        return ;
    }
    DtwLocker_unlock(self->root_props->locker, self->path);

}



void DtwResource_commit(DtwResource *self){
    if(DtwResource_error(self)){
        return ;
    }
    DtwTransaction_commit(self->root_props->transaction,NULL);
}

long DtwResource_size(DtwResource *self){
    if(DtwResource_error(self)){
        return -1;
    }
    return dtw_get_total_itens_of_dir(self->path);
}



DtwStringArray *DtwResource_list_names(DtwResource *self){
    if(DtwResource_error(self)){
        return NULL;
    }
    return dtw_list_all(self->path,DTW_NOT_CONCAT_PATH);
}

int DtwResource_type(DtwResource *self){
    if(DtwResource_error(self)){
        return -1;
    }
    DtwResource_load_if_not_loaded(self);

    if(self->value_any == NULL){
        return dtw_entity_type(self->path);
    }

    if(self->value_size == 0){
        return DTW_COMPLEX_STRING_TYPE;
    }
    if(self->is_binary){
        return DTW_COMPLEX_BINARY;
    }

    char *data_in_string = DtwResource_get_string(self);

    if(
            strcmp(data_in_string,"t") == 0 || strcmp(data_in_string,"true") == 0  ||
                    strcmp(data_in_string,"f") == 0 || strcmp(data_in_string,"false") == 0

    ){
        return DTW_COMPLEX_BOOL_TYPE;
    }


    double data_double;
    int result = sscanf(data_in_string,"%lf",&data_double);
    if(result == 0){
        return DTW_COMPLEX_STRING_TYPE;

    }


    for(int i = 0; i < self->value_size; i++){
        char current = data_in_string[i];
        if(current == '.'){
            return  DTW_COMPLEX_DOUBLE_TYPE;
        }
    }
    return  DTW_COMPLEX_LONG_TYPE;

}
bool DtwResource_is_file(DtwResource *self){
    if(DtwResource_error(self)){
        return -1;
    }
    DtwResource_load_if_not_loaded(self);

    if(self->value_any){
        return true;
    }
    return  false;

}

const char * DtwResource_type_in_str(DtwResource *self){
    if(DtwResource_error(self)){
        return NULL;
    }
     return dtw_convert_entity(DtwResource_type(self));
}

void DtwResource_represent(DtwResource *self){
    if(DtwResource_error(self)){
        return;
    }

    if(DtwResource_error(self)){
        printf("error code: %d\n", DtwResource_get_error_code(self));
        printf("error message: %s\n", DtwResource_get_error_message(self));
        return ;
    }

    printf("path: %s\n", self->path);
    printf("name: %s\n",self->name);
    if(self->loaded){
        printf("type: %s\n",DtwResource_type_in_str(self));
        int type = DtwResource_type(self);
        if(type == DTW_COMPLEX_STRING_TYPE){
            printf("value: %s\n", DtwResource_get_string(self));
        }
        if(type == DTW_COMPLEX_LONG_TYPE){
            printf("value: %ld\n", DtwResource_get_long(self));
        }

        if(type == DTW_COMPLEX_DOUBLE_TYPE){
            printf("value: %lf\n", DtwResource_get_double(self));
        }

        if(type == DTW_COMPLEX_BOOL_TYPE){
            printf("value: %s\n",DtwResource_get_bool(self) ?"true": "false");
        }

    }


}





unsigned char *DtwResource_get_any(DtwResource *self, long *size, bool *is_binary){
    if(DtwResource_error(self)){
        return NULL;
    }
    DtwResource_load_if_not_loaded(self);
    *size = self->value_size;
    *is_binary = self->is_binary;

    if(!self->value_any){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_EXIST,
                "element at #path# not exist"
                );
        return NULL;
    }

    return self->value_any;


}

unsigned char *DtwResource_get_any_from_sub_resource(DtwResource *self, long *size, bool *is_binary,const char *format,...){
    if(DtwResource_error(self)){
        return NULL;
    }
    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);

    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_any(element,size,is_binary);

}

unsigned char *DtwResource_get_binary(DtwResource *self, long *size){
    if(DtwResource_error(self)){
        return NULL;
    }
    bool is_binary;

    return DtwResource_get_any(self,size,&is_binary);
}

unsigned char *DtwResource_get_binary_from_sub_resource(DtwResource *self, long *size,const char *format,...){
    if(DtwResource_error(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);

    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_binary(element,size);
}


char *DtwResource_get_string(DtwResource *self){
    if(DtwResource_error(self)){
        return NULL;
    }

    long size;
    bool is_binary;
    char *result =  (char *)DtwResource_get_any(self,&size,&is_binary);

    if(is_binary){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_STRING,
                "element at #path# its an binary"
        );
        return NULL;
    }

    return result;
}


char *DtwResource_get_string_from_sub_resource(DtwResource *self,const char *format,...){
    if(DtwResource_error(self)){
        return NULL;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_string(element);
}


long DtwResource_get_long(DtwResource *self){

    if(DtwResource_error(self)){
        return -1;
    }

    char *element = DtwResource_get_string(self);

    if(DtwResource_error(self)){
        return -1;
    }

    long value;
    int result = sscanf(element,"%ld",&value);
    if(result == 0){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_LONG,
                "element at #path# its not long"
        );
        return -1;
    }
    return value;
}


long DtwResource_get_long_from_sub_resource(DtwResource *self,const char *format,...){
    if(DtwResource_error(self)){
        return -1;
    }
    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_long(element);
}


double DtwResource_get_double(DtwResource *self){
    if(DtwResource_error(self)){
        return -1;
    }

    char *element = DtwResource_get_string(self);
    if(DtwResource_error(self)){
        return -1;
    }

    double value;
    int result = sscanf(element,"%lf",&value);
    if(result == 0){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ELEMENT_NOT_DOUBLE,
                "element at #path# its not long"
        );
        return-1;
    }
    return value;
}

double DtwResource_get_double_from_sub_resource(DtwResource *self,const char *format,...){

    if(DtwResource_error(self)){
        return -1;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);


    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_double(element);
}


bool DtwResource_get_bool(DtwResource *self){
    if(DtwResource_error(self)){
        return false;
    }
    char *element = DtwResource_get_string(self);
    if(DtwResource_error(self)){
        return false;
    }

    if(strcmp(element,"true") == 0 || strcmp(element,"t") == 0){
        return true;
    }
    if(strcmp(element,"false") == 0 || strcmp(element,"f") == 0){
        return false;
    }

    private_DtwResource_raise_error(
            self,
            DTW_RESOURCE_ELEMENT_NOT_BOOL,
            "element at #path# its not bool"
    );
    return false;
}

bool DtwResource_get_bool_from_sub_resource(DtwResource *self,const char *format,...){
    if(DtwResource_error(self)){
        return false;
    }

    va_list args;
    va_start(args, format);
    char *name = private_dtw_format_vaarg(format,args);
    va_end(args);

    DtwResource *element = DtwResource_sub_resource(self,"%s",name);
    free(name);
    return DtwResource_get_bool(element);
}






void DtwResource_unload(DtwResource *self){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->loaded == false){
        return;
    }
    if(self->value_any){
        free(self->value_any);
    }

    self->value_any = NULL;
    self->is_binary = false;
    self->value_size = 0;
}

void DtwResource_load(DtwResource *self){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource_unload(self);
    self->value_any = dtw_load_any_content(self->path,&self->value_size,&self->is_binary);

    self->loaded = true;

}
void DtwResource_load_if_not_loaded(DtwResource *self){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->loaded == false){
        DtwResource_load(self);
    }
}





bool private_DtwResource_its_a_pk(DtwResource *self){
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ELEMENT_PROP){
        return false;
    }
    DtwResource *ancestor = self->mother->mother->mother;
    DtwSchema * schema = ancestor->attached_schema;
    return DtwStringArray_find_position(schema->primary_keys,self->name) !=-1;
}

void privateDtwResource_ensure_its_possible_to_sub_resource(DtwResource *self){

    if(self->root_props->schema_unsafe){
        return;
    }

    if(self->schema_type == 0){

        return;
    }


    if(self->schema_type != PRIVATE_DTW_SCHEMA_ELEMENT && self->schema_type != PRIVATE_DTW_SCHEMA_ELEMENT_PROP){

        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_IMPOSSIBLE_TO_ADD_SUB_RESOURCE_INSIDE_SCHEMA_STRUCT,
                "impossible to add sub resource inside schema struct "
        );
        return ;
    }

    if(private_DtwResource_its_a_pk(self)){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_PRIMARY_KEY_CANNOT_HAVE_SUB_RESOURCE,
                "primary key %s cannot have a sub resource",
                self->name
        );
        return;
    }

}


DtwResource * DtwResource_new_schema_insertion(DtwResource *self){

    if(DtwResource_error(self)){
        return NULL;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT || self->datatabase_schema){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_IMPSSIBLE_TO_ADD_INSERTION_OUTSIDE_ROOT_SCHEMA,
                "only root schema can generate insertions");
        return NULL;
    }
    privateDtwSchemaUnsafe({
        DtwResource  *created = DtwResource_sub_resource_random(self->values_resource,NULL);
        DtwSchemaRebase
        return created;
    })


}

DtwResource  *DtwResource_find_by_name_id(DtwResource *self, const char *name){

    if(DtwResource_error(self)){
        return NULL;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CAN_FIND_BY_ID_OR_PK,
                "only root schema can find by id or pk"
                );
        return NULL;
    }
    privateDtwSchemaUnsafe({
        DtwResource *element = DtwResource_sub_resource(self->values_resource,name);

        if(DtwResource_type(element) == DTW_NOT_FOUND){
            DtwSchemaRebase
            return NULL;
        }
        DtwSchemaRebase
        return element;
    })

}
DtwResource * DtwResource_find_by_primary_key_with_binary(DtwResource *self, const char *primary_key, unsigned  char *value, long size){
    if(DtwResource_error(self)){
        return NULL;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CAN_FIND_BY_ID_OR_PK,
                "only root schema can find by id or pk"
                );
        return NULL;
    }
    privateDtwSchemaUnsafe({
        DtwResource *primary_key_folder = DtwResource_sub_resource(self->index_resource, "%s", primary_key);
        char *sha = dtw_generate_sha_from_any(value,size);
        DtwResource *index_value = DtwResource_sub_resource(primary_key_folder,"%s",sha);
        free(sha);
        if(DtwResource_type(index_value) == DTW_NOT_FOUND){
            DtwSchemaRebase
            return NULL;
        }
        char *element_folder = DtwResource_get_string(index_value);
        if(DtwResource_error(self)){
            DtwSchemaRebase
            return NULL;
        }
        if(element_folder == NULL){
            DtwSchemaRebase
            return NULL;
        }

        DtwResource *founded_resource = DtwResource_sub_resource(self->values_resource, "%s", element_folder);
        DtwSchemaRebase
        return founded_resource;
    })


}



DtwResource * DtwResource_find_by_primary_key_with_string(DtwResource *self, const char *key, const char *value){
    if(DtwResource_error(self)){
        return NULL;
    }
    return DtwResource_find_by_primary_key_with_binary(self,key,(unsigned char*)value, (long)strlen(value));
}


void DtwResource_dangerous_remove_schema_prop(DtwResource*self,const char *prop){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS,
                "only root schema can modify schema props"
        );
        return;
    }
    privateDtwSchemaUnsafe({

        bool allow_transaction = self->allow_transaction;

            DtwResourceArray * all_values = DtwResource_sub_resources(self->values_resource);
            DtwTransaction * transaction = self->root_props->transaction;
            for(int i = 0; i < all_values->size; i++){
                DtwResource *current = all_values->resources[i];
                DtwResource *prop_to_remove = DtwResource_sub_resource(current,"%s",prop);
                if(allow_transaction){
                    DtwTransaction_delete_any(transaction,prop_to_remove->path);
                }else{
                    dtw_remove_any(prop_to_remove->path);
                }

            }
            DtwResource *index_element = DtwResource_sub_resource(self->index_resource,"%s",prop);
            if(allow_transaction){
                DtwTransaction_delete_any(transaction,index_element->path);
            }else{
                dtw_remove_any(index_element->path);
            }
            DtwSchemaRebase
    })

}


void DtwResource_dangerous_rename_schema_prop(DtwResource*self,const char *prop,const char *new_name){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_CANN_MODIFY_SCHEMA_PROPS,
                "only root schema can modify schema props"
        );
        return;
    }
    privateDtwSchemaUnsafe({
        bool allow_transaction = self->allow_transaction;

        DtwResourceArray * all_values = DtwResource_sub_resources(self->values_resource);
        DtwTransaction * transaction = self->root_props->transaction;
        for(int i = 0; i < all_values->size; i++){
            DtwResource *current = all_values->resources[i];
            DtwResource *prop_to_remove = DtwResource_sub_resource(current,"%s",prop);
            DtwResource *new_prop = DtwResource_sub_resource(current,"%s",new_name);
            if(allow_transaction){
                DtwTransaction_move_any_merging(transaction,prop_to_remove->path,new_prop->path);
            }else{
                dtw_move_any(prop_to_remove->path,new_prop->path,DTW_MERGE);
            }

        }


        DtwResource *index_element = DtwResource_sub_resource(self->index_resource,"%s",prop);
        DtwResource *new_index = DtwResource_sub_resource(self->index_resource,"%s",new_name);
        if(allow_transaction){
            DtwTransaction_move_any_merging(transaction,index_element->path,new_index->path);
        }else{
            dtw_move_any(index_element->path,new_index->path,DTW_MERGE);
        }
        DtwSchemaRebase
    })


}



DtwDatabaseSchema * DtwResource_newDatabaseSchema(DtwResource *self){
    if(DtwResource_error(self)){
        return  NULL;
    }
    privateDtwResource_ensure_its_possible_to_sub_resource(self);

    if(DtwResource_error(self)){
        return  NULL;
    }

    if(self->datatabase_schema){
        return self->datatabase_schema;
    }

    self->datatabase_schema = private_newDtwDtatabaseSchema();
    return self->datatabase_schema;
}






void private_dtw_resource_set_primary_key(DtwResource *self, unsigned  char *element, long size){

privateDtwSchemaUnsafe({
    DtwResource * ancestor = self->mother->mother->mother;
    DtwResource *index_resource =ancestor->index_resource;
    DtwResource *pk_folder = DtwResource_sub_resource(index_resource,"%s",self->name);

    char *sha = dtw_generate_sha_from_any(element,size);
    DtwResource  *pk_value = DtwResource_sub_resource(pk_folder,sha);
    free(sha);
    char *mothers_name =self->mother->name;

    if(DtwResource_is_file(pk_value)) {
        char *content = DtwResource_get_string(pk_value);
        if (DtwResource_error(self)) {
            DtwSchemaRebase
            return;
        }

        //means its the same
        if (strcmp(content, mothers_name) == 0) {
            DtwSchemaRebase
            return;
        }

        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_PRIMARY_KEY_ALREADY_EXIST,
                "primary key: %s already exist",
                self->name
        );
        DtwSchemaRebase
        return;

    }
    DtwResource_set_string(pk_value,mothers_name);
    DtwSchemaRebase
})

}
void DtwResource_set_any(DtwResource *self, unsigned char *element, long size,bool is_binary){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource_unload(self);

    if(private_DtwResource_its_a_pk(self)){
        private_dtw_resource_set_primary_key(self, element, size);
    }

    if(DtwResource_error(self)){
        return;
    }

    if(self->allow_transaction){
        DtwTransaction_write_any(self->root_props->transaction,self->path,element,size,is_binary);
    }
    else{
        dtw_write_any_content(self->path,element,size);
    }

    self->loaded = true;
    self->value_size = size;
    self->is_binary = is_binary;
    self->value_any = (unsigned  char *) malloc(size+1);

    self->value_any[size]= '\0';
    memcpy(self->value_any,element,size);
}
void DtwResource_set_binary(DtwResource *self, unsigned char *element, long size){
    DtwResource_set_any(self,element,size,true);
}

void DtwResource_set_string(DtwResource *self,const  char *element){
    DtwResource_set_any(self,(unsigned char *)element,strlen(element),false);
}

void DtwResource_set_binary_sha(DtwResource *self, unsigned  char *value, long size){
    if(DtwResource_error(self)){
        return ;
    }
    char *generated_sha = dtw_generate_sha_from_any(value,size);
    DtwResource_set_string(self,generated_sha);
    free(generated_sha);
}

void DtwResource_set_string_sha(DtwResource *self,const char *value){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource_set_binary_sha(self,(unsigned char*)value, (long)strlen(value));
}








void DtwResource_set_long(DtwResource *self,long element){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->allow_transaction){
        DtwTransaction_write_long(self->root_props->transaction,self->path,element);
    }
    else{
        dtw_write_long_file_content(self->path,element);
    }
    DtwResource_unload(self);
    self->loaded = true;
    char result[20] ={0};
    sprintf(result,"%ld",element);
    self->value_any = (unsigned char *)strdup(result);

}

void DtwResource_set_double(DtwResource *self,double element){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->allow_transaction){
        DtwTransaction_write_double(self->root_props->transaction,self->path,element);
    }
    else{
        dtw_write_double_file_content(self->path,element);
    }
    DtwResource_unload(self);
    self->loaded = true;
    char result[20] ={0};
    sprintf(result,"%lf",element);
    self->value_any = (unsigned char *)strdup(result);


}

void DtwResource_set_bool( DtwResource *self,bool element){
    if(DtwResource_error(self)){
        return ;
    }
    if(self->allow_transaction){
        DtwTransaction_write_bool(self->root_props->transaction,self->path,element);
    }
    else{
        dtw_write_bool_file_content(self->path,element);
    }

    DtwResource_unload(self);
    self->loaded = true;
    if(element){
        self->value_any = (unsigned char*)strdup("true");
    }
    else{
        self->value_any = (unsigned char*)strdup("false");

    }

}





void DtwResource_set_any_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size,bool is_binary) {
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_any(created, element, size,is_binary);
}

void DtwResource_set_binary_in_sub_resource(DtwResource *self,const char *key, unsigned char *element, long size){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_binary(created, element, size);
}

void DtwResource_set_binary_sha_in_sub_resource(DtwResource *self, const char *key, unsigned  char *value, long size){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_binary_sha(created,value,size);
}


void DtwResource_set_string_sha_in_sub_resource(DtwResource *self, const char *key, const char *value){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_string_sha(created,value);
}

void DtwResource_set_string_in_sub_resource(DtwResource *self, const char *key, const  char *element){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_string(created,element);
}

void DtwResource_set_long_in_sub_resource(DtwResource *self, const char *key, long element){
    if(DtwResource_error(self)){
        return ;
    }
    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_long(created,element);
}

void DtwResource_set_double_in_sub_resource(DtwResource *self, const char *key, double element){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_double(created,element);
}

void DtwResource_set_bool_in_sub_resource(DtwResource *self,const char *key, bool element){
    if(DtwResource_error(self)){
        return ;
    }

    DtwResource *created = DtwResource_sub_resource(self,"%s",key);
    DtwResource_set_bool(created,element);
}








DtwResourceForeachProps DtwResource_create_foreach_props( void(*callback)(DtwResource *item, void *args)){
    DtwResourceForeachProps props = {0};
    props.callback = callback;
    props.qtd = DTW_RESOURCE_ALL;
    return props;
}

void DtwResource_foreach(DtwResource *self,DtwResourceForeachProps props){
    if(DtwResource_error(self)){
        return;;
    }
    DtwResourceArray *itens = NULL;
    privateDtwSchemaUnsafe({
        itens = DtwResource_sub_resources(self);
    })

    if(DtwResource_error(self)){
        return;;
    }
    int total = 0;

    int total_skipded = 0;

    for(int i = 0; i < itens->size; i++){
        DtwResource *current = itens->resources[i];

        if(props.filtrage_callback){
            bool result = props.filtrage_callback(current, props.args);
            if(DtwResource_error(self)){
                return;;
            }
            if(!result){
                continue;
            }
        }

        total_skipded++;

        if(total_skipded <= props.start){
            continue;
        }

        total++;

        if(total > props.qtd && props.qtd != -1){
            break;
        }

        props.callback(current, props.args);
        if(DtwResource_error(self)){
            return;;
        }
    }
}

void DtwResource_schema_foreach(DtwResource *self,DtwResourceForeachProps props){

    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
        private_DtwResource_raise_error(
                self,
                DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                "only root schema have schema values"
        );
        return ;
    }
    DtwResource_foreach(self->values_resource,props);
}





DtwResourceMapProps DtwResource_create_map_props(
    void *main_array,
    void(*append)(void *main_array_arg, void *item),
    void *(*callback)(DtwResource *item, void *args)
){
    DtwResourceMapProps props = {0};
    props.main_array = main_array;
    props.append = append;
    props.callback = callback;
    props.qtd = DTW_RESOURCE_ALL;
    return  props;
}

int  private_dtwResource_compare(const void *item1,const void*item2){
    privateDtwResource_map_element *item1_converted = *(privateDtwResource_map_element**)item1;
    privateDtwResource_map_element *item2_converted = *(privateDtwResource_map_element**)item2;

    return item1_converted->ordenation_callback(item1_converted->current,item2_converted->current,item1_converted->args);
}

void DtwResource_map(DtwResource *self,DtwResourceMapProps props){
    //printf("%p\n",ordenation_callback);
    if(DtwResource_error(self)){
        return;;
    }

    DtwResourceArray *itens = NULL;
    privateDtwSchemaUnsafe({
        itens = DtwResource_sub_resources(self);
    })

    if(DtwResource_error(self)){
        return;
    }

    privateDtwResource_map_element **mapped_elements= NULL;
    int total_mapped_elements = 0;
    if(props.ordenation_callback) {
        mapped_elements = (privateDtwResource_map_element**)malloc(
            (itens->size+1) * sizeof(privateDtwResource_map_element**)
            );
    }

    int total = 0;
    int total_skipded = 0;
    for(int i = 0; i < itens->size; i++){

        DtwResource *current = itens->resources[i];

        if(props.filtrage_callback){
            bool result = props.filtrage_callback(current, props.args);
            if(DtwResource_error(self)){
                return;;
            }
            if(!result){
                continue;
            }
        }

        total_skipded++;

        if(total_skipded <= props.start){
            continue;
        }

        if(total + 1 > props.qtd && props.qtd != -1){
            break;
        }

        void* result = props.callback(current, props.args);
        if(DtwResource_error(self)){
            if(result){
                props.append(props.main_array,result);
            }
            return;
        }
        if(result == NULL){
            continue;
        }
        total+=1;

        if(props.ordenation_callback == NULL) {
            props.append(props.main_array,result);
            if(DtwResource_error(self)){
                return;;
            }
        }

        if(props.ordenation_callback){
            privateDtwResource_map_element *created  = (privateDtwResource_map_element*)malloc(sizeof(privateDtwResource_map_element));
            *created = (privateDtwResource_map_element){0};
            created->result = result;
            created->current = current;
            created->ordenation_callback = props.ordenation_callback;
            created->args =props.args;
          //  printf("criado %p\n",created);
            mapped_elements[total_mapped_elements] = created;
            total_mapped_elements+=1;
        }

    }

    if(props.ordenation_callback) {

        qsort(
            mapped_elements,
            total_mapped_elements,
            sizeof(privateDtwResource_map_element*),
            private_dtwResource_compare
            );
        if(DtwResource_error(self)){
            return;;
        }
        for(int i = 0; i< total_mapped_elements; i++) {
            privateDtwResource_map_element *current = mapped_elements[i];
            props.append(props.main_array,current->result);
            free(current);
        }
        free(mapped_elements);
    }


}
void DtwResource_schema_map(DtwResource *self,DtwResourceMapProps props){

    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                    "only root schema have schema values"
            );
            return ;
        }

        DtwResource_map(self->values_resource, props);

}




DtwResourcecJSONArrayMapProps DtwResource_create_cJSONArrayMapProps(cJSON *(*callback)(DtwResource *item, void *args)){
    DtwResourcecJSONArrayMapProps props = {0};
    props.callback= callback;
    props.qtd =DTW_RESOURCE_ALL;
    return  props;
}

void  *private_dtw_cJSONArray_callback(DtwResource *item,void *args) {

    DtwResourcecJSONArrayMapProps *formmate_args = (DtwResourcecJSONArrayMapProps*)args;
    return (void*)formmate_args->callback(item,formmate_args->args);
}

bool private_dtw_cJSONArray_filtrage(DtwResource *item,void *args) {

    DtwResourcecJSONArrayMapProps *formmate_args = (DtwResourcecJSONArrayMapProps*)args;
    return formmate_args->filtrage_callback(item,formmate_args->args);
}

int private_dtw_cJSONArray_ordenation(DtwResource *item1,DtwResource *item2,void *args) {
    DtwResourcecJSONArrayMapProps *formmate_args = (DtwResourcecJSONArrayMapProps*)args;
    return formmate_args->ordenation_callback(item1,item2,formmate_args->args);
}

void privateDtwResource_add_to_item_to_cJSONArray_array(void* array, void *item){
    cJSON_AddItemToArray((cJSON *)array, (cJSON *)item);
}

cJSON *DtwResource_map_cJSONArray(DtwResource *self,DtwResourcecJSONArrayMapProps props){

    cJSON *itens = cJSON_CreateArray();

    DtwResourceMapProps mapped_props = DtwResource_create_map_props(
        itens,
        privateDtwResource_add_to_item_to_cJSONArray_array,
        private_dtw_cJSONArray_callback
    );

    mapped_props.args = (void*)&props;

    if(props.filtrage_callback) {
        mapped_props.filtrage_callback = private_dtw_cJSONArray_filtrage;
    }

    if(props.ordenation_callback) {
        mapped_props.ordenation_callback = private_dtw_cJSONArray_ordenation;
    }
    
    if(props.qtd){
        mapped_props.qtd = props.qtd;
    }
    if(props.start){
        mapped_props.start = props.start;
    }

    DtwResource_map(self,mapped_props);

    return itens;
}

cJSON *DtwResource_schema_map_cJSONArray(DtwResource *self,DtwResourcecJSONArrayMapProps props){
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                    "only root schema have schema values"
            );
            return NULL;
    }
    return  DtwResource_map_cJSONArray(self->values_resource, props);

}





DtwResourcecJSONObjectMapProps DtwResource_create_cJSONObjectProps(
    cJSON *(*callback)(DtwResource *item, void *args),
    char *(*key_provider_callback)(DtwResource *item,void *args)
){
    DtwResourcecJSONObjectMapProps props = {0};
    props.callback  = callback;
    props.key_provider_callback = key_provider_callback;
    props.qtd = DTW_RESOURCE_ALL;
    return  props;
}

void  *private_dtw_cJSONObject_callback(DtwResource *item,void *args) {
    DtwResourcecJSONObjectMapProps *formmate_args = (DtwResourcecJSONObjectMapProps*)args;
    privateDtw_cJSON_element_and_key *created = (privateDtw_cJSON_element_and_key*)malloc(sizeof(privateDtw_cJSON_element_and_key));
    created->key = formmate_args->key_provider_callback(item,args);
    created->free_key = formmate_args->free_key;
    created->element =formmate_args->callback(item,formmate_args->args);
    return (void*)created;
}

bool private_dtw_cJSONObject_filtrage(DtwResource *item,void *args) {
    DtwResourcecJSONObjectMapProps *formmate_args = (DtwResourcecJSONObjectMapProps*)args;
    return formmate_args->filtrage_callback(item,formmate_args->args);
}

int private_dtw_cJSONObject_ordenation(DtwResource *item1,DtwResource *item2,void *args) {
    DtwResourcecJSONObjectMapProps *formmate_args = (DtwResourcecJSONObjectMapProps*)args;
    return formmate_args->ordenation_callback(item1,item2,formmate_args->args);
}

void privateDtwResource_add_to_item_to_cJSONObject(void* object, void *item){
    privateDtw_cJSON_element_and_key *casted = (privateDtw_cJSON_element_and_key*)item;
    cJSON_AddItemToObject((cJSON*)object,casted->key,casted->element);
    if(casted->free_key){
        free(casted->key);
    }
    free(casted);
}


cJSON *DtwResource_map_cJSONObject(DtwResource *self,DtwResourcecJSONObjectMapProps props){

    cJSON *itens = cJSON_CreateObject();

    DtwResourceMapProps map_props = DtwResource_create_map_props(
        itens,
        privateDtwResource_add_to_item_to_cJSONObject,
        private_dtw_cJSONObject_callback
    );
    map_props.args = (void*)&props;
    if(props.filtrage_callback) {
        map_props.filtrage_callback = private_dtw_cJSONObject_filtrage;
    }

    if(props.ordenation_callback) {
        map_props.ordenation_callback = private_dtw_cJSONObject_ordenation;
    }
    if(props.qtd){
        map_props.qtd = props.qtd;
    }
    if(props.start){
        map_props.start = props.start;
    }
    DtwResource_map(self,map_props);

    return itens;
}

cJSON *DtwResource_schema_map_cJSONObject(DtwResource *self,DtwResourcecJSONObjectMapProps props){
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                    "only root schema have schema values"
            );
            return NULL;
    }
    return  DtwResource_map_cJSONObject(self->values_resource,props);

}




#ifdef DTW_ALLOW_CHASH
#define DTW_ALLOW_CHASH


DtwResourceCHashrrayMapProps  DtwResource_create_CHashrrayMapProps(    CHash *(*callback)(DtwResource *item, void *args)){
    DtwResourceCHashrrayMapProps props = {0};
    props.callback = callback;
    props.qtd = DTW_RESOURCE_ALL;
    return  props;
}

void  *private_dtw_CHashArray_callback(DtwResource *item,void *args) {
    DtwResourceCHashrrayMapProps *formmate_args = (DtwResourceCHashrrayMapProps*)args;
    return (void*)formmate_args->callback(item,formmate_args->args);
}

bool private_dtw_CHashArray_filtrage(DtwResource *item,void *args) {
    DtwResourceCHashrrayMapProps *formmate_args = (DtwResourceCHashrrayMapProps*)args;
    return formmate_args->filtrage_callback(item,formmate_args->args);
}

int private_dtw_CHashArray_ordenation(DtwResource *item1,DtwResource *item2,void *args) {
    DtwResourceCHashrrayMapProps *formmate_args = (DtwResourceCHashrrayMapProps*)args;
    return formmate_args->ordenation_callback(item1,item2,formmate_args->args);
}

void privateDtwResource_add_to_item_to_CHashArray_array(void* array, void *item){
    CHashArray_append_any((CHashArray*)array, (CHash *)item);
}

CHashArray *DtwResource_map_CHashArray(DtwResource *self,DtwResourceCHashrrayMapProps props){

    CHashArray *itens = newCHashArrayEmpty();

    DtwResourceMapProps map_props = DtwResource_create_map_props(
        itens,
        privateDtwResource_add_to_item_to_CHashArray_array,
        private_dtw_CHashArray_callback
    );

    map_props.args = (void*)&props;
    if(props.filtrage_callback) {
        map_props.filtrage_callback = private_dtw_CHashArray_filtrage;
    }
    if(props.qtd){
        map_props.qtd = props.qtd;
    }
    if(props.start){
        map_props.start = props.start;
    }

    if(props.ordenation_callback) {
        map_props.ordenation_callback = private_dtw_CHashArray_ordenation;
    }

    DtwResource_map(self,map_props);

    return itens;
}
CHashArray *DtwResource_schema_map_CHashArray(DtwResource *self,DtwResourceCHashrrayMapProps props){
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                    "only root schema have schema values"
            );
            return NULL;
    }
    return DtwResource_map_CHashArray(self->values_resource,props);
}


#define DTW_ALLOW_CHASH



DtwResourceCHashObjectMapProps DtwResource_createCHashObjectMapProps(
    CHash *(*callback)(DtwResource *item, void *args),
    char* (*key_provider)(DtwResource *item, void *args_filter)
){
    DtwResourceCHashObjectMapProps props = {0};
    props.qtd = DTW_RESOURCE_ALL;
    props.callback = callback;
    props.key_provider_callback = key_provider;
    return props;
}


void  *private_dtw_CHashObject_callback(DtwResource *item,void *args) {
    DtwResourceCHashObjectMapProps *formmate_args = (DtwResourceCHashObjectMapProps*)args;
    privateDtw_CHash_element_and_key *created = (privateDtw_CHash_element_and_key*)malloc(sizeof(privateDtw_CHash_element_and_key));
    created->free_key = formmate_args->free_key;
    created->key = formmate_args->key_provider_callback(item,args);
    created->element =formmate_args->callback(item,formmate_args->args);
    return (void*)created;
}

bool private_dtw_CHashObject_filtrage(DtwResource *item,void *args) {
    DtwResourceCHashObjectMapProps *formmate_args = (DtwResourceCHashObjectMapProps*)args;
    return formmate_args->filtrage_callback(item,formmate_args->args);
}

int private_dtw_CHashObject_ordenation(DtwResource *item1,DtwResource *item2,void *args) {
    DtwResourceCHashObjectMapProps *formmate_args = (DtwResourceCHashObjectMapProps*)args;
    return formmate_args->ordenation_callback(item1,item2,formmate_args->args);
}

void privateDtwResource_add_to_item_to_CHashObject(void* object, void *item){
    privateDtw_CHash_element_and_key *casted = (privateDtw_CHash_element_and_key*)item;
    CHashObject_set_any((CHash*)object,casted->key,casted->element);
    if(casted->free_key){
        free(casted->key);
    }

    free(casted);
}


CHash *DtwResource_map_CHashObject(DtwResource *self,DtwResourceCHashObjectMapProps props){

    CHash *itens = newCHashObjectEmpty();

    DtwResourceMapProps map_props = DtwResource_create_map_props(
        itens,
        privateDtwResource_add_to_item_to_CHashObject,
        private_dtw_CHashObject_callback
    );
    map_props.args = (void*)&props;
    if(props.filtrage_callback) {
        map_props.filtrage_callback = private_dtw_CHashObject_filtrage;
    }

    if(props.qtd){
        map_props.qtd = props.qtd;
    }
    if(props.start){
        map_props.start = props.start;
    }

    if(props.ordenation_callback) {
        map_props.ordenation_callback = private_dtw_CHashObject_ordenation;
    }
    DtwResource_map(self,map_props);

    return itens;
}

CHash *DtwResource_schema_map_CHashObject(DtwResource *self,DtwResourceCHashObjectMapProps props){
    if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                    "only root schema have schema values"
            );
            return NULL;
    }

    return DtwResource_map_CHashObject(self->values_resource,props);

}




#endif






#include <time.h>


DtwResourceArray * DtwResource_get_schema_values(DtwResource *self){
    if(DtwResource_error(self)){
        return NULL;
    }
    privateDtwSchemaUnsafe({
        if(self->schema_type != PRIVATE_DTW_SCHEMA_ROOT){
            private_DtwResource_raise_error(
                    self,
                    DTW_RESOURCE_ONLY_ROOT_SCHEMA_HAVE_SCHEMA_VALUES,
                    "only root schema have schema values"
            );
            DtwSchemaRebase
            return NULL;
        }

        DtwResourceArray *elements =  DtwResource_sub_resources(self->values_resource);
        DtwSchemaRebase
        return elements;
    })


}


DtwResourceArray * DtwResource_sub_resources(DtwResource *self){


    DtwStringArray  *names  = DtwResource_list_names(self);
    DtwStringArray_sort(names);
    DtwResourceArray *target_array = (DtwResourceArray*)self->sub_resources;

    if(self->cache_sub_resources == false){
        target_array = newDtwResourceArray();
    }

    for(int i = 0; i < names->size; i++){

        char *current_name = names->strings[i];

        if(self->cache_sub_resources){
            DtwResource_sub_resource(self,"%s", current_name);
            if(DtwResource_error(self)){
                DtwStringArray_free(names);
                return NULL;
            }
        }

        else{
            DtwResource *current_resource = DtwResource_sub_resource(self,"%s",current_name);
            DtwResourceArray_append(target_array,current_resource);
            if(DtwResource_error(self)){
                DtwStringArray_free(names);
                return NULL;
;
            }
        }
    }

    DtwStringArray_free(names);
    return target_array;

}








DtwResourceArray * newDtwResourceArray(){
    DtwResourceArray *self = (DtwResourceArray*) malloc(sizeof (DtwResourceArray));
    self->resources = (DtwResource**) malloc(0);
    self->size = 0;
    return self;
}


void DtwResourceArray_append(DtwResourceArray *self, DtwResource *element){
    self->resources = (DtwResource**)realloc(self->resources,(self->size +1) * sizeof (DtwResource**));
    self->resources[self->size] = element;
    self->size+=1;
}


DtwResource* DtwResourceArray_get_by_name(DtwResourceArray *self, const char *name){
    for(int i = 0; i < self->size; i++){
        DtwResource *current = self->resources[i];
        if(strcmp(current->name,name) ==0){
            return current;
        }
    }
    return NULL;
}



void DtwResourceArray_represent(DtwResourceArray *self){
    for(int i = 0; i< self->size; i++){
        printf("----------------------------------------\n");
        DtwResource_represent(self->resources[i]);
    }
}

void DtwResourceArray_free(DtwResourceArray *self){
    for(int i = 0; i < self->size; i++){
        DtwResource_free(self->resources[i]);

    }
    free(self->resources);
    free(self);
}










DtwJsonTransactionError * private_new_DtwJsonTransactionError( int code,const char *mensage,const  char *path){
    DtwJsonTransactionError *self = (DtwJsonTransactionError*) malloc(sizeof(DtwJsonTransactionError));
    self->code  = code;
    self->mensage = strdup(mensage);
    self->path = NULL;
    if(path){
        self->path = strdup(path);
    }

    return self;
}

void DtwJsonTransactionError_represent(struct DtwJsonTransactionError *self){
    printf("code: %d\n",self->code);
    printf("mensage:%s\n",self->mensage);
    if(self->path){
        printf("path: %s",self->path);
    }
}

void DtwJsonTransactionError_prepend_path(struct DtwJsonTransactionError *self,char *path){
    if(self->path){

        char *new_path = (char*)calloc(sizeof (char), strlen(self->path) + strlen(path) + 2);

        sprintf(new_path,"%s%s",path,self->path);

        free(self->path);
        self->path = new_path;
        return;
    }
    self->path = strdup(path);
}


void DtwJsonTransactionError_free(struct DtwJsonTransactionError *self){
    free(self->mensage);
    if(self->path){
        free(self->path);
    }
    free(self);

}







DtwActionTransaction * newDtwActionTransaction(){
    DtwActionTransaction *self = (DtwActionTransaction*) malloc(sizeof (DtwActionTransaction));
    *self= (DtwActionTransaction){0};
    return self;
}


DtwActionTransaction * DtwActionTransaction_write_any(const char *source, unsigned  char *content,long size,bool is_binary){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_WRITE;
    self->content = (unsigned char*)malloc(size +2);
    memcpy(self->content,content,size);
    self->content[size] = '\0';
    self->size = size;
    self->source = strdup(source);
    self->is_binary = is_binary;
    return self;
}


DtwActionTransaction * DtwActionTransaction_move_any(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_MOVE;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;

}


DtwActionTransaction * DtwActionTransaction_copy_any(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_COPY;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;
}
DtwActionTransaction * DtwActionTransaction_move_any_merging(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_MOVE_MERGING;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;
}

DtwActionTransaction * DtwActionTransaction_copy_any_merging(const char *source, const char *dest){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_COPY_MERGING;
    self->source = strdup(source);
    self->dest = strdup(dest);
    return self;
}

DtwActionTransaction * DtwActionTransaction_delete_any(const char *source){
    DtwActionTransaction *self = newDtwActionTransaction();
    self->action_type = DTW_ACTION_DELETE;
    self->source = strdup(source);
    return self;
}



void DtwActionTransaction_commit(DtwActionTransaction* self,const char *path){

    char *formated_source = dtw_concat_path(path,self->source);


    if(self->action_type == DTW_ACTION_WRITE){
        dtw_write_any_content(formated_source,self->content,self->size);
        free(formated_source);
        return;
    }
    if(self->action_type == DTW_ACTION_DELETE){
        dtw_remove_any(formated_source);
        free(formated_source);
        return;
    }
    char *formated_dest = dtw_concat_path(path,self->dest);

    if(self->action_type == DTW_ACTION_MOVE){
        dtw_move_any(formated_source,formated_dest,DTW_NOT_MERGE);
    }

    if(self->action_type == DTW_ACTION_MOVE_MERGING){
        dtw_move_any(formated_source,formated_dest,DTW_MERGE);
    }

    if(self->action_type == DTW_ACTION_COPY){
        dtw_copy_any(formated_source,formated_dest,DTW_NOT_MERGE);
    }

    if(self->action_type == DTW_ACTION_COPY_MERGING){
        dtw_copy_any(formated_source,formated_dest,DTW_MERGE);
    }

    free(formated_dest);
    free(formated_source);

}


void DtwActionTransaction_free(DtwActionTransaction* self){

    if(self->content){
        free(self->content);
    }
    if(self->source){
        free(self->source);
    }
    if(self->dest){
        free(self->dest);
    }
    free(self);
}





short DtwActionTransaction_convert_action_to_integer(char *action){
    if(strcmp(action,"write") == 0){
        return DTW_ACTION_WRITE;
    }

    if(strcmp(action,"move") == 0){
        return DTW_ACTION_MOVE;
    }

    if(strcmp(action,"copy") == 0){
        return DTW_ACTION_COPY;
    }

    if(strcmp(action,"delete") == 0){
        return DTW_ACTION_DELETE;
    }
    return -1;

}

const char * DtwActionTransaction_convert_action_to_string(int action){
    if(action == DTW_ACTION_WRITE){
        return "write";
    }
    if(action == DTW_ACTION_MOVE){
        return "move";
    }

    if(action == DTW_ACTION_COPY){
        return "copy";
    }
    if(action == DTW_ACTION_DELETE){
        return "delete";
    }
    return NULL;
}

DtwJsonTransactionError * private_dtw_validate_json_action_transaction(cJSON *json_obj){

    if(json_obj->type != cJSON_Object ){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the action object its not an object",
                NULL
        );
    }

    cJSON *action = cJSON_GetObjectItem(json_obj,"action");

    if(!action){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_NOT_PRESENT_VALUE,
                "the action is not present",
                "[\"action\"]"
        );
    }

    if(action->type != cJSON_String){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the action is not an string",
                "[\"action\"]"
        );
    }


    int converted_action = DtwActionTransaction_convert_action_to_integer(action->valuestring);

    if(converted_action == -1){

        char *formated_mensage = (char*)calloc(sizeof (char),strlen(action->valuestring) + 30);
        sprintf(formated_mensage,"the action: %s its not valid",action->valuestring);
        DtwJsonTransactionError  *error = private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_INVALID_ACTION,
                formated_mensage,
                "[\"action\"]"
        );
        free(formated_mensage);
        return error;
    }

    if(converted_action == DTW_ACTION_WRITE){
        cJSON  *content = cJSON_GetObjectItem(json_obj,"content");
        if(!content){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_NOT_PRESENT_VALUE,
                    "the content is not present",
                    "[\"content\"]"
            );
        }
        if(content->type != cJSON_String){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_WRONG_TYPE,
                    "the content is not an string",
                    "[\"content\"]"
            );
        }
        cJSON *is_binary = cJSON_GetObjectItem(json_obj,"is binary");
        if(is_binary){
            if(!cJSON_IsBool(is_binary)){
                return private_new_DtwJsonTransactionError(
                        JSON_TRANSACTION_WRONG_TYPE,
                        "the is binary is not an bool",
                        "[\"is binary\"]"
                );
            }
        }

    }




    cJSON *source = cJSON_GetObjectItem(json_obj,"source");
    if(!source){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_NOT_PRESENT_VALUE,
                "the source is not present",
                "[\"source\"]"
        );
    }

    if(source->type != cJSON_String){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the source is not an string",
                "[\"source\"]"
        );
    }

    if(converted_action == DTW_ACTION_MOVE || converted_action == DTW_ACTION_COPY){
        cJSON *dest = cJSON_GetObjectItem(json_obj,"dest");

        if(!dest){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_NOT_PRESENT_VALUE,
                    "the dest is not present",
                    "[\"dest\"]"
            );
        }
        if(dest->type != cJSON_String){
            return private_new_DtwJsonTransactionError(
                    JSON_TRANSACTION_WRONG_TYPE,
                    "the dest is not an string",
                    "[\"dest\"]"
            );
        }
    }
    return NULL;

}


DtwActionTransaction * private_DtwActionTransaction_parse_json_object(cJSON *json_obj){
    DtwActionTransaction  *self = newDtwActionTransaction();

    char *action = cJSON_GetObjectItem(json_obj,"action")->valuestring;
    self->action_type  = DtwActionTransaction_convert_action_to_integer(action);

    char *source = cJSON_GetObjectItem(json_obj,"source")->valuestring;
    self->source = strdup(source);

    if(self->action_type == DTW_ACTION_DELETE){
        return self;
    }

    if(self->action_type == DTW_ACTION_WRITE){
        cJSON *is_binary = cJSON_GetObjectItem(json_obj,"is binary");

        if(is_binary){
            if(is_binary->valueint){
                self->is_binary= true;
            }
        }

        char *content = cJSON_GetObjectItem(json_obj,"content")->valuestring;
        if(self->is_binary){
            self->content = dtw_base64_decode(content,&self->size);
        }
        else{
            self->content =(unsigned char*)strdup(content);
            self->size =(long)strlen(content);
        }

        return self;
    }
    char *dest  = cJSON_GetObjectItem(json_obj,"dest")->valuestring;
    self->dest = strdup(dest);
    return self;
}

cJSON *  private_DtwActionTransaction_create_json_object(DtwActionTransaction* self){
    cJSON * json_object = cJSON_CreateObject();
    cJSON_AddStringToObject(json_object,"action",DtwActionTransaction_convert_action_to_string(self->action_type));

    cJSON_AddStringToObject(json_object,"source",self->source);
    if(self->action_type ==DTW_ACTION_WRITE){
        if(self->is_binary){
            char *converted = dtw_base64_encode(self->content,self->size);
            cJSON_AddStringToObject(json_object,"content",converted);
            free(converted);
            cJSON_AddBoolToObject(json_object,"is binary",true);
        }
        else{
            cJSON_AddStringToObject(json_object,"content",(char*)self->content);
        }
    }
    if(self->action_type != DTW_ACTION_DELETE){
        cJSON_AddStringToObject(json_object,"dest",self->dest);
    }

    return json_object;
}



void DtwActionTransaction_represent(DtwActionTransaction* self){

    printf("\taction: %s\n", DtwActionTransaction_convert_action_to_string(self->action_type));
    printf("\tsource:%s\n",self->source);
    if(self->action_type == DTW_ACTION_WRITE){

        if(!self->is_binary && self->size <  30){

            printf("\tcontent : %s\n",(char*)self->content);
        }
        else{
            printf("\tcontent: impossible to show\n");
        }

        printf("\tsize:%ld\n",self->size);
        printf("\tis binary: %s\n",self->is_binary? "true":"false");
        return;
    }

    if(self->action_type != DTW_ACTION_DELETE){
        printf("\tdest: %s\n",self->dest);
    }

}







DtwTransaction * newDtwTransaction(){
    DtwTransaction *self = (DtwTransaction*) malloc(sizeof(DtwTransaction));
    self->actions = (DtwActionTransaction **) malloc(sizeof (DtwActionTransaction**));
    self->size = 0;

    return self;
}

void DtwTransaction_append_action(struct DtwTransaction *self,struct DtwActionTransaction  *action){
    self->actions =  (DtwActionTransaction**)realloc(
            self->actions,
            (sizeof(DtwActionTransaction*) * (self->size+1))
    );
    self->actions[self->size] = action;
    self->size++;
}


void DtwTransaction_remove_from_index(DtwTransaction *self,long index){


    DtwActionTransaction_free(self->actions[index]);
    self->size -=1;
    if(self->size == 0){
        return;
    }
    for(long i = index; i < self->size; i++){
        self->actions[i] = self->actions[i+1];
    }

}
void DtwTransaction_filter(DtwTransaction *self,bool (*callback)(DtwActionTransaction *action)){
    for(long i = 0; i < self->size; i++){
        DtwActionTransaction *current = self->actions[i];
        if(!callback(current)){
            DtwTransaction_remove_from_index(self,i);
            i-=1;
        }
    }
}

void DtwTransaction_remove_from_source(DtwTransaction *self,const char *source){
    for(long i = 0; i < self->size; i++){
        DtwActionTransaction *current = self->actions[i];
        if(strcmp(current->source,source) ==0){
            DtwTransaction_remove_from_index(self,i);
            i-=1;
        }
    }
}


void DtwTransaction_write_any(struct DtwTransaction *self,const char *path,unsigned char *content, long size,bool is_binary){
    DtwActionTransaction * action = DtwActionTransaction_write_any(path,content,size,is_binary);
    DtwTransaction_append_action(self,action);
}

void DtwTransaction_write_string(struct DtwTransaction *self,const char *path,const char *content){
    DtwActionTransaction * action = DtwActionTransaction_write_any(path,(unsigned char*)content, strlen(content),false);
    DtwTransaction_append_action(self,action);
}


void DtwTransaction_write_long(struct DtwTransaction *self,const char *path,long value){
    char converted[20] ={0};
    sprintf(converted,"%ld",value);
    DtwTransaction_write_string(self,path,converted);
}

void DtwTransaction_write_bool(struct DtwTransaction *self,const char *path,bool value){
    if(value){
        DtwTransaction_write_string(self,path,"t");
    }
    else{
        DtwTransaction_write_string(self,path,"f");
    }
}

void DtwTransaction_write_double(struct DtwTransaction *self,const char *path,double value){
    char converted[20] ={0};
    sprintf(converted,"%lf",value);
    DtwTransaction_write_string(self,path,converted);
}


void DtwTransaction_move_any(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_move_any(source,dest);
    DtwTransaction_append_action(self,action);
}

void DtwTransaction_copy_any(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_copy_any(source,dest);
    DtwTransaction_append_action(self,action);
}

void DtwTransaction_move_any_merging(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_move_any_merging(source,dest);
    DtwTransaction_append_action(self,action);
}


void DtwTransaction_copy_any_merging(struct DtwTransaction *self,const char *source,const char *dest){
    DtwActionTransaction * action = DtwActionTransaction_copy_any_merging(source,dest);
    DtwTransaction_append_action(self,action);
}


void DtwTransaction_delete_any(struct DtwTransaction *self,const char *source){
     DtwActionTransaction  *action = DtwActionTransaction_delete_any(source);
     DtwTransaction_append_action(self,action);
}



void DtwTransaction_commit(struct DtwTransaction *self,const char *path){
    for(int i = 0; i < self->size; i++){
        DtwActionTransaction_commit(self->actions[i],path);
    }
}



void DtwTransaction_free(struct DtwTransaction *self){
    for(int i =0; i < self->size; i++){
        DtwActionTransaction_free(self->actions[i]);
    }
    free(self->actions);
    free(self);
}






DtwJsonTransactionError * dtw_validate_json_transaction(cJSON *json_entry){
    if(json_entry->type != cJSON_Array){
        return private_new_DtwJsonTransactionError(
                JSON_TRANSACTION_WRONG_TYPE,
                "the initial value its not an array",
                NULL
                );
    }
    long  element_size = cJSON_GetArraySize(json_entry);
    for(long  i = 0; i <element_size; i++){

        cJSON *current_obj = cJSON_GetArrayItem(json_entry,i);

        DtwJsonTransactionError  *current_error = private_dtw_validate_json_action_transaction(current_obj);
        if(current_error){
            char formated_path[20] = {0};
            sprintf(formated_path,"[%ld]",i);
            DtwJsonTransactionError_prepend_path(current_error,formated_path);

            return current_error;
        }

    }

    return NULL;
}

DtwJsonTransactionError * dtw_validate_json_transaction_file(const char *filename){
    char *content = dtw_load_string_file_content(filename);
    if(!content){
        char *formated_mensage = (char*)calloc(sizeof (char), strlen(filename) + 50);
        sprintf(formated_mensage, "file: %s not found",filename);
        DtwJsonTransactionError  *error = private_new_DtwJsonTransactionError(
                DTW_ACTION_FILE_NOT_FOUND,
                formated_mensage,
                NULL
                );
        free(formated_mensage);
        return error;
    }
    cJSON *parsed = cJSON_Parse(content);
    if(!parsed){
        char *formated_mensage = (char*)calloc(sizeof (char), strlen(filename) + 50);
        sprintf(formated_mensage, "file: %s its not an valid json",filename);
        DtwJsonTransactionError  *error = private_new_DtwJsonTransactionError(
                DTW_ACTION_ITS_NOT_JSON,
                formated_mensage,
                NULL
        );
        free(formated_mensage);
        free(content);
        return error;
    }
    DtwJsonTransactionError *generated_error = dtw_validate_json_transaction(parsed);

    free(content);
    cJSON_Delete(parsed);
    return generated_error;
}


DtwTransaction * newDtwTransaction_from_json(cJSON *json_entry){
    DtwJsonTransactionError *generated_error = dtw_validate_json_transaction(json_entry);
    if(generated_error) {
        DtwJsonTransactionError_free(generated_error);
        return NULL;
    }
    DtwTransaction *self = newDtwTransaction();
    long size = cJSON_GetArraySize(json_entry);
    for(int i  = 0; i < size; i ++){
        cJSON  *object_action = cJSON_GetArrayItem(json_entry,i);
        DtwActionTransaction  *current_action = private_DtwActionTransaction_parse_json_object(object_action);
        DtwTransaction_append_action(self,current_action);
    }
    return self;
}



DtwTransaction * newDtwTransaction_from_json_file(const char *filename){
    char *content = dtw_load_string_file_content(filename);
    if(!content){
        return NULL;
    }

    cJSON  *element = cJSON_Parse(content);
    free(content);
    if(!element){
        return NULL;
    }

    DtwJsonTransactionError *error = dtw_validate_json_transaction(element);
    if(error){
        DtwJsonTransactionError_free(error);
        cJSON_Delete(element);
        return NULL;
    }


    DtwTransaction  *self = newDtwTransaction_from_json(element);
    cJSON_Delete(element);

    return self;
}

cJSON * DtwTransaction_dumps_to_json(struct DtwTransaction *self){
    cJSON * json_array = cJSON_CreateArray();
    for(int i =0; i < self->size; i ++){

        cJSON_AddItemToArray(
                json_array,
                private_DtwActionTransaction_create_json_object(self->actions[i])
        );

    }
    return json_array;
}


void DtwTransaction_dumps_to_json_file(struct DtwTransaction *self,const char *filename){
    cJSON *json_array = DtwTransaction_dumps_to_json(self);
    char *result = cJSON_Print(json_array);
    dtw_write_string_file_content(filename,result);
    free(result);
    cJSON_Delete(json_array);
}

void DtwTransaction_represent(struct DtwTransaction *self){

    for(int i = 0; i < self->size; i++){

        DtwActionTransaction_represent(self->actions[i]);
        printf("------------------------------------\n");

    }

}











DtwHash * newDtwHash(){
    DtwHash *self = (DtwHash*) malloc(sizeof(DtwHash));
    self->hash = dtw_generate_sha_from_string("");

    return self;
}

bool  DtwHash_digest_any(DtwHash *self,unsigned char *content,long size){
    if(content == NULL){
        return false;
    }
    char *generated = dtw_generate_sha_from_any(content,size);
    char result[300] ={0};
    sprintf(result,"%s%s",self->hash,generated);
    free(generated);
    free(self->hash);
    self->hash = dtw_generate_sha_from_string(result);
    return true;
}

bool  DtwHash_digest_string(DtwHash * self, const char *content){
    return DtwHash_digest_any(self,(unsigned char *)content, (long)strlen(content));
}

void DtwHash_digest_long(DtwHash * self,long content){
    char formated[20] ={0};
    sprintf(formated,"%ld",content);
    DtwHash_digest_string(self,formated);
}

void DtwHash_digest_double(DtwHash * self,double content){
    char formated[20] ={0};
    sprintf(formated,"%lf",content);
    DtwHash_digest_string(self,formated);
}

void DtwHash_digest_bool(DtwHash * self,bool content){
    char formated[20] ={0};
    sprintf(formated,"%d",(bool)content);
    DtwHash_digest_string(self,formated);
}

bool  DtwHash_digest_file(DtwHash * self, const char *path){

    long size;
    unsigned  char *content = dtw_load_binary_content(path,&size);
    if(!content){
        return false;
    }
    DtwHash_digest_any(self,content,size);
    free(content);
    return true;
}

bool  DtwHash_digest_entity_last_modification(DtwHash * self, const char *path){
    long last_modification = dtw_get_entity_last_motification_in_unix(path);
    if(last_modification == -1){
        return false;
    }
    DtwHash_digest_long(self,last_modification);
    return true;
}


bool  DtwHash_digest_string_array(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);

    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_string(self,clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return  true;
}

bool  DtwHash_digest_string_array_last_modifications(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_entity_last_modification(self, clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}

bool DtwHash_digest_string_array_last_modifications_adding_name(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_string(self,clone->strings[i]);
        DtwHash_digest_entity_last_modification(self, clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}


bool DtwHash_digest_string_array_content(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0 ; i < clone->size; i++){
        DtwHash_digest_file(self,clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}

bool DtwHash_digest_string_array_content_adding_name(DtwHash *self,DtwStringArray *element){
    if(element->size == 0){
        return false;
    }
    DtwStringArray  *clone = DtwStringArray_clone(element);
    DtwStringArray_sort(clone);
    for(int i =0; i < clone->size; i++){
        DtwHash_digest_string(self,clone->strings[i]);
        DtwHash_digest_file(self,clone->strings[i]);
    }
    DtwStringArray_free(clone);
    return true;
}


bool DtwHash_digest_folder_by_last_modification(DtwHash *self,const char *path){
    DtwStringArray  *folder = dtw_list_all_recursively(path,DTW_NOT_CONCAT_PATH);
    if(folder->size == 0){
        DtwStringArray_free(folder);
        return false;
    }
    DtwStringArray_sort(folder);
    for(int i =0; i < folder->size; i++){
        DtwHash_digest_string(self,folder->strings[i]);
        char *formated_path = dtw_concat_path(path,folder->strings[i]);

        DtwHash_digest_entity_last_modification(self, formated_path);
        free(formated_path);
    }
    DtwStringArray_free(folder);
    return true;
}

bool DtwHash_digest_folder_by_content(DtwHash *self,const char *path){

    DtwStringArray  *folder = dtw_list_all_recursively(path,DTW_NOT_CONCAT_PATH);
    if(folder->size == 0){
        DtwStringArray_free(folder);
        return false;
    }
    DtwStringArray_sort(folder);
    for(int i =0; i < folder->size; i++){
        DtwHash_digest_string(self,folder->strings[i]);
        char *formated_path = dtw_concat_path(path,folder->strings[i]);
        DtwHash_digest_file(self,formated_path);
        free(formated_path);
    }
    DtwStringArray_free(folder);
    return true;
}

void  DtwHash_free(DtwHash *self){
    free(self->hash);
    free(self);
}






DtwRandonizerModule newDtwRandonizerModule(){
    DtwRandonizerModule self = {0};
    self.newRandonizer = newDtwRandonizer;
    self.generate_num = DtwRandonizer_generate_num;
    self.generate_token =DtwRandonizer_generate_token;
    self.free = DtwRandonizer_free;
    return self;
}





DtwPathModule newDtwPathModule(){
    DtwPathModule  self = {0};
    self.newPath = newDtwPath;
    self.changed =DtwPath_changed;
    self.get_full_name = DtwPath_get_full_name;
    self.get_name = DtwPath_get_name;
    self.get_extension = DtwPath_get_extension;
    self.get_path = DtwPath_get_path;
    self.get_dir = DtwPath_get_dir;
    self.get_total_dirs = DtwPath_get_total_dirs;
    self.get_sub_dirs_from_index = DtwPath_get_sub_dirs_from_index;
    self.insert_dir_at_index = DtwPath_insert_dir_at_index;
    self.remove_sub_dirs_at_index =  DtwPath_remove_sub_dirs_at_index;
    self.insert_dir_after= DtwPath_insert_dir_after;
    self.insert_dir_before = DtwPath_insert_dir_before;
    self.replace_dirs = DtwPath_replace_dirs;
    self.remove_sub_dirs_at = DtwPath_remove_sub_dirs_at;

    self.set_extension = DtwPath_set_extension;
    self.set_name = DtwPath_set_name;
    self.set_dir = DtwPath_set_dir;
    self.set_full_name =DtwPath_set_full_name;
    self.set_path = DtwPath_set_path;

    self.add_start_dir =DtwPath_add_start_dir;
    self.add_end_dir = DtwPath_add_end_dir;
    self.represent = DtwPath_represent;
    self.free = DtwPath_free;

    return self;
}





DtwStringArrayModule newDtwStringArrayModule(){
    DtwStringArrayModule self = {0};
    self.newStringArray = newDtwStringArray;
    self.set_value = DtwStringArray_set_value;
    self.append = DtwStringArray_append;
    self.pop = DtwStringArray_pop;
    self.merge = DtwStringArray_merge;
    self.represent = DtwStringArray_represent;
    self.find_position = DtwStringArray_find_position;
    self.sort = DtwStringArray_sort;
    self.free =DtwStringArray_free;
    return self;
}






DtwTreePartModule newDtwTreePartModule(){
    DtwTreePartModule self ={0};
    self.newPart = newDtwTreePart;
    self.newPartEmpty = newDtwTreePartEmpty;
    self.newPartLoading = newDtwTreePartLoading;
    self.get_content_string_by_reference = DtwTreePart_get_content_string_by_reference;
    self.get_content_binary_by_reference = DtwTreePart_get_content_binary_by_reference;
    self.get_content_sha = DtwTreePart_get_content_sha;
    self.set_any_content = DtwTreePart_set_any_content;
    self.set_string_content = DtwTreePart_set_string_content;
    self.set_binary_content = DtwTreePart_set_binary_content;
    self.load_content_from_hardware =DtwTreePart_load_content_from_hardware;
    self.free_content = DtwTreePart_free_content;
    self.represent =DtwTreePart_represent;
    self.hardware_remove = DtwTreePart_hardware_remove;
    self.hardware_write = DtwTreePart_hardware_write;
    self.hardware_modify = DtwTreePart_hardware_modify;
    self.hardware_commit =DtwTreePart_hardware_commit;

    self.free = DtwTreePart_free;
    self.self_copy = DtwTreePart_self_copy;


    return self;
}





DtwJsonTreeErrorModule newDtwJsonTreeErrorModule(){
    DtwJsonTreeErrorModule self = {0};
    self.validate_json_tree_by_cJSON= DtwJsonTreeError_validate_json_tree_by_cJSON;
    self.validate_json_tree_by_content = DtwJsonTreeError_validate_json_tree_by_content;
    self.represent =DtwJsonTreeError_represent;
    self.free = DtwJsonTreeError_free;
    return self;
}





DtwTreeTransactionReportModule newDtwTreeTransactionReportModule(){
    DtwTreeTransactionReportModule self = {0};
    self.represent = DtwTreeTransactionReport_represent;
    self.free = DtwTreeTransactionReport_free;
    return self;
}





DtwTreeModule newDtwTreeModule(){
    DtwTreeModule self = {0};
    self.newTree = newDtwTree;
    self.add_tree_part_by_copy = DtwTree_add_tree_part_copy;
    self.remove_tree_part  = DtwTree_remove_tree_part;
    self.add_tree_part_getting_owenership = DtwTree_add_tree_part_getting_onwership;
    self.add_tree_part_referencing = DtwTree_add_tree_part_referencing;
    self.add_tree_parts_from_string_array = DtwTree_add_tree_parts_from_string_array;
    self.get_sub_tree = DtwTree_get_sub_tree;
    self.add_tree_from_hardware = DtwTree_add_tree_from_hardware;
    self.find_tree_part_by_function = DtwTree_find_tree_part_by_function;
    self.filter = DtwTree_filter;
    self.map = DtwTree_map;

    self.list_files = DtwTree_list_files;
    self.list_dirs = DtwTree_list_dirs;
    self.list_all = DtwTree_list_all;

    self.list_files_recursively = DtwTree_list_files_recursively;
    self.list_dirs_recursively = DtwTree_list_dirs_recursively;
    self.list_all_recursively = DtwTree_list_all_recursively;

    self.find_tree_part_by_name = DtwTree_find_tree_part_by_name;
    self.find_tree_part_by_path = DtwTree_find_tree_part_by_path;

    self.create_report = DtwTree_create_report;
    self.loads_json_tree = DtwTree_loads_json_tree;
    self.loads_json_tree_from_file = DtwTree_loads_json_tree_from_file;
    self.dumps_json_tree = DtwTree_dumps_tree_json;
    self.dumps_json_tree_to_file = DtwTree_dumps_tree_json_to_file;

    self.represent = DtwTree_represent;
    self.insecure_hardware_remove_tree = DtwTree_insecure_hardware_remove_tree;
    self.insecure_hardware_write_tree = DtwTree_insecure_hardware_write_tree;
    self.hardware_commit_tree = DtwTree_hardware_commit_tree;
    self.free = DtwTree_free;
    self.transaction_report = newDtwTreeTransactionReportModule();
    self.part = newDtwTreePartModule();
    self.json_error = newDtwJsonTreeErrorModule();
    return self;
}







DtwLockerModule newDtwLockerModule(){
    DtwLockerModule  self = {0};
    self.newLocker = newDtwLocker;
    self.lock = DtwLocker_lock;
    self.unlock = DtwLocker_unlock;
    self.represemt = DtwLocker_represemt;
    self.free = DtwLocker_free;
    return self;
}





DtwActionTransactionModule newDtwActionTransactionModule(){
    DtwActionTransactionModule self = {0};
    self.newAction = newDtwActionTransaction;
    self.write_any = DtwActionTransaction_write_any;
    self.move_any = DtwActionTransaction_move_any;
    self.copy_any = DtwActionTransaction_copy_any;
    self.move_any_merging = DtwActionTransaction_move_any_merging;
    self.copy_any_merging = DtwActionTransaction_move_any_merging;
    self.delete_any = DtwActionTransaction_delete_any;
    self.convert_action_to_integer =DtwActionTransaction_convert_action_to_integer;
    self.convert_action_to_string = DtwActionTransaction_convert_action_to_string;
    self.commit = DtwActionTransaction_commit;
    self.represent = DtwActionTransaction_represent;
    self.free = DtwActionTransaction_free;
    return self;
}





DtwJsonTransactionErrorModule newDtwJsonTransactionErrorModule(){
    DtwJsonTransactionErrorModule self = {0};
    self.represent = DtwJsonTransactionError_represent;
    self.free = DtwJsonTransactionError_free;
    return self;
}






DtwTransactionModule newDtwTransactionModule(){
    DtwTransactionModule self = {0};
    self.newTransaction = newDtwTransaction;
    self.newTransaction_from_json = newDtwTransaction_from_json;
    self.newTransaction_from_json_file = newDtwTransaction_from_json_file;
    self.validate_json_transaction_file = dtw_validate_json_transaction_file;
    self.remove_from_index = DtwTransaction_remove_from_index;
    self.remove_from_source = DtwTransaction_remove_from_source;
    self.filter = DtwTransaction_filter;
    self.append_action = DtwTransaction_append_action;
    self.write_any = DtwTransaction_write_any;
    self.write_string = DtwTransaction_write_string;
    self.write_long = DtwTransaction_write_long;
    self.write_bool = DtwTransaction_write_bool;
    self.write_double = DtwTransaction_write_double;

    self.move_any_merging = DtwTransaction_move_any_merging;
    self.copy_any_merging = DtwTransaction_copy_any_merging;
    self.move_any = DtwTransaction_move_any;
    self.copy_any = DtwTransaction_copy_any;
    self.delete_any = DtwTransaction_delete_any;

    self.dumps_transaction_to_json = DtwTransaction_dumps_to_json;
    self.dumps_transaction_to_json_file = DtwTransaction_dumps_to_json_file;

    self.commit = DtwTransaction_commit;
    self.represent = DtwTransaction_represent;
    self.free =DtwTransaction_free;

    self.action = newDtwActionTransactionModule();
    self.json_error = newDtwJsonTransactionErrorModule();


    return self;
}






DtwResourceArrayModule newDtwResourceArrayModule(){
    DtwResourceArrayModule self = {0};
    self.append = DtwResourceArray_append;
    self.represent = DtwResourceArray_represent;
    self.get_by_name = DtwResourceArray_get_by_name;
    self.free = DtwResourceArray_free;
    return self;
}





DtwResourceModule newDtwResourceModule(){
    DtwResourceModule self = {0};
    self.newResource = new_DtwResource;
    self.get_error_code = DtwResource_get_error_code;
    self.get_error_message = DtwResource_get_error_message;
    self.error = DtwResource_error;
    self.load = DtwResource_load;
    self.clear_errors = DtwResource_clear_errors;
    self.unload = DtwResource_unload;
    self.sub_resource = DtwResource_sub_resource;

    self.create_foreach_props = DtwResource_create_foreach_props;
    self.each = DtwResource_foreach;
    self.schema_each  =DtwResource_schema_foreach;

    self.create_map_props = DtwResource_create_map_props;
    self.map = DtwResource_map;
    self.schema_map = DtwResource_schema_map;

    self.create_cJSONArrayMapProps = DtwResource_create_cJSONArrayMapProps;
    self.map_cJSONArray = DtwResource_map_cJSONArray;
    self.schema_map_cJSONArray = DtwResource_schema_map_cJSONArray;

    self.create_cJSONObjectProps = DtwResource_create_cJSONObjectProps;
    self.map_cJSONObject =DtwResource_map_cJSONObject;
    self.schema_map_cJSONObject = DtwResource_schema_map_cJSONObject;

    #ifdef DTW_ALLOW_CHASH
        self.create_CHashrrayMapProps = DtwResource_create_CHashrrayMapProps;
        self.map_CHashArray = DtwResource_map_CHashArray;
        self.schema_map_CHashArray  = DtwResource_schema_map_CHashArray;

        self.createCHashObjectMapProps = DtwResource_createCHashObjectMapProps;
        self.map_CHashObject = DtwResource_map_CHashObject;
        self.schema_map_CHashObject = DtwResource_schema_map_CHashObject;

    #endif
    self.get_any_from_sub_resource = DtwResource_get_any_from_sub_resource;
    self.get_binary_from_sub_resource = DtwResource_get_binary_from_sub_resource;
    self.get_string_from_sub_resource = DtwResource_get_string_from_sub_resource;
    self.get_long_from_sub_resource = DtwResource_get_long_from_sub_resource;
    self.get_double_from_sub_resource = DtwResource_get_double_from_sub_resource;
    self.get_bool_from_sub_resource = DtwResource_get_bool_from_sub_resource;
    self.get_error_path = DtwResource_get_error_path;
    self.get_schema_values = DtwResource_get_schema_values;
    self.set_binary_in_sub_resource = DtwResource_set_binary_in_sub_resource;
    self.set_string_in_sub_resource = DtwResource_set_string_in_sub_resource;
    self.set_long_in_sub_resource = DtwResource_set_long_in_sub_resource;
    self.set_double_in_sub_resource = DtwResource_set_double_in_sub_resource;
    self.set_bool_in_sub_resource = DtwResource_set_bool_in_sub_resource;
    self.is_file = DtwResource_is_file;
    self.sub_resource_ensuring_not_exist = DtwResource_sub_resource_ensuring_not_exist;
    self.sub_resource_next = DtwResource_sub_resource_next;
    self.destroy_sub_resource = DtwResource_destroy_sub_resource;
    self.rename_sub_resource = DtwResource_rename_sub_resource;
    self.sub_resource_now  = DtwResource_sub_resource_now;
    self.sub_resource_now_in_unix = DtwResource_sub_resource_now_in_unix;
    self.sub_resource_random = DtwResource_sub_resource_random;
    self.set_binary_sha =DtwResource_set_binary_sha;
    self.set_string_sha = DtwResource_set_string_sha;
    self.set_any_in_sub_resource = DtwResource_set_any_in_sub_resource;
    self.set_binary_sha_in_sub_resource = DtwResource_set_binary_sha_in_sub_resource;
    self.set_string_sha_in_sub_resource = DtwResource_set_string_sha_in_sub_resource;

    self.new_schema_insertion = DtwResource_new_schema_insertion;
    self.find_by_name_id = DtwResource_find_by_name_id;
    self.find_by_primary_key_with_string = DtwResource_find_by_primary_key_with_string;
    self.find_by_primary_key_with_binary = DtwResource_find_by_primary_key_with_binary;
    self.dangerous_remove_schema_prop = DtwResource_dangerous_remove_schema_prop;
    self.dangerous_rename_schema_prop = DtwResource_dangerous_rename_schema_prop;
    self.newDatabaseSchema = DtwResource_newDatabaseSchema;

    self.lock =DtwResource_lock;
    self.unlock = DtwResource_unlock;
    self.destroy = DtwResource_destroy;

    self.get_any = DtwResource_get_any;
    self.get_string = DtwResource_get_string;
    self.get_binary = DtwResource_get_binary;
    self.get_double = DtwResource_get_double;
    self.get_long = DtwResource_get_long;
    self.get_bool = DtwResource_get_bool;

    self.set_any = DtwResource_set_any;
    self.set_binary = DtwResource_set_binary;
    self.set_string = DtwResource_set_string;
    self.set_long = DtwResource_set_long;
    self.set_double = DtwResource_set_double;
    self.set_bool = DtwResource_set_bool;


    self.list_names = DtwResource_list_names;
    self.size = DtwResource_size;
    self.type = DtwResource_type;
    self.type_in_str = DtwResource_type_in_str;
    self.commit =DtwResource_commit;
    self.represent = DtwResource_represent;
    self.rename = DtwResource_rename;
    self.free  = DtwResource_free;
    self.sub_resources = DtwResource_sub_resources;
    self.array = newDtwResourceArrayModule();

    return self;
}







DtwHashModule newDtwHashModule(){
    DtwHashModule self = {0};
    self.newHash =newDtwHash;
    self.digest_any = DtwHash_digest_any;
    self.digest_string = DtwHash_digest_string;
    self.digest_long = DtwHash_digest_long;
    self.digest_double = DtwHash_digest_double;
    self.digest_bool = DtwHash_digest_bool;
    self.digest_file = DtwHash_digest_file;
    self.digest_entity_last_modification =DtwHash_digest_entity_last_modification;
    self.digest_string_array = DtwHash_digest_string_array;
    self.digest_string_array_last_modifications = DtwHash_digest_string_array_last_modifications;
    self.digest_string_array_last_modifications_adding_name = DtwHash_digest_string_array_last_modifications_adding_name;
    self.digest_string_array_content = DtwHash_digest_string_array_content;
    self.digest_string_array_content_adding_name = DtwHash_digest_string_array_content_adding_name;
    self.digest_folder_by_last_modification = DtwHash_digest_folder_by_last_modification;
    self.digest_folder_by_content = DtwHash_digest_folder_by_content;
    self.free = DtwHash_free;
    return self;
}






DtwSchemaModule newDtwSchemaModule(){
    DtwSchemaModule  self = {0};
    self.sub_schema = DtwSchema_new_subSchema;
    self.add_primary_key = DtwSchema_add_primary_key;

    return  self;
}






DtwDatabaseSchemaModule newDtwDatabaseSchemaModule(){
    DtwDatabaseSchemaModule  self = {0};
    self.sub_schema = DtwDtatabaseSchema_new_subSchema;
    return  self;
}





DtwNamespace newDtwNamespace(){
    DtwNamespace self = {0};
    //io
    self.create_dir_recursively = dtw_create_dir_recursively;
    self.remove_any = dtw_remove_any;
    self.get_absolute_path = dtw_get_absolute_path;
    self.get_current_dir = dtw_get_current_dir;
    self.load_any_content = dtw_load_any_content;
    self.load_string_file_content = dtw_load_string_file_content;
    self.load_binary_content = dtw_load_binary_content;
    self.write_any_content = dtw_write_any_content;
    self.write_string_file_content =dtw_write_string_file_content;
    self.entity_type = dtw_entity_type;
    self.complex_entity_type = dtw_complex_entity_type;
    self.convert_entity  = dtw_convert_entity;
    self.copy_any = dtw_copy_any;
    self.move_any = dtw_move_any;
    //numeral io
    self.load_long_file_content = dtw_load_long_file_content;
    self.load_double_file_content =  dtw_load_double_file_content;
    self.load_bool_file_content = dtw_load_bool_file_content;

    self.write_long_file_content = dtw_write_long_file_content;
    self.write_double_file_content = dtw_write_double_file_content;
    self.write_bool_file_content = dtw_write_bool_file_content;

    //listage
    self.list_files = dtw_list_files;
    self.list_dirs = dtw_list_dirs;
    self.list_all = dtw_list_all;

    self.list_files_recursively = dtw_list_files_recursively;
    self.list_dirs_recursively = dtw_list_dirs_recursively;
    self.list_all_recursively = dtw_list_all_recursively;

    //extras
    self.generate_sha_from_file = dtw_generate_sha_from_file;
    self.generate_sha_from_string = dtw_generate_sha_from_string;
    self.generate_sha_from_any = dtw_generate_sha_from_any;
    self.get_entity_last_motification_in_unix = dtw_get_entity_last_motification_in_unix;
    self.get_entity_last_motification_in_string = dtw_get_entity_last_motification_in_string;
    self.concat_path = dtw_concat_path;
    //bas64
    self.base64_encode = dtw_base64_encode;
    self.base64_decode  = dtw_base64_decode;
    self.convert_binary_file_to_base64 = dtw_convert_binary_file_to_base64;

    self.string_array = newDtwStringArrayModule();
    self.path = newDtwPathModule();
    self.locker = newDtwLockerModule();

    self.schema = newDtwSchemaModule();
    self.database_schema = newDtwDatabaseSchemaModule();
    self.tree = newDtwTreeModule();
    self.hash = newDtwHashModule();
    self.transaction = newDtwTransactionModule();
    self.resource = newDtwResourceModule();
    self.randonizer = newDtwRandonizerModule();

    return self;
}








#ifndef DTW_NOT_IMPLEMENT_CJSON
    #ifdef PRIVATE_DTW_CJSON_DEFINED_IN_DO_THE_WORLD
        /*
  Copyright (c) 2009-2017 Dave Gamble and cJSON contributors

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/

/* cJSON */
/* JSON parser in C. */

/* disable warnings about old C89 functions in MSVC */
#if !defined(_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER)
#define _CRT_SECURE_NO_DEPRECATE
#endif

#ifdef __GNUC__
#pragma GCC visibility push(default)
#endif
#if defined(_MSC_VER)
#pragma warning (push)
/* disable warning about single line comments in system headers */
#pragma warning (disable : 4001)
#endif

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>
#include <float.h>

#ifdef ENABLE_LOCALES
#include <locale.h>
#endif

#if defined(_MSC_VER)
#pragma warning (pop)
#endif
#ifdef __GNUC__
#pragma GCC visibility pop
#endif




/* define our own boolean type */
#ifdef true
#undef true
#endif
#define true ((cJSON_bool)1)

#ifdef false
#undef false
#endif
#define false ((cJSON_bool)0)

/* define isnan and isinf for ANSI C, if in C99 or above, isnan and isinf has been defined in math.h */
#ifndef isinf
#define isinf(d) (isnan((d - d)) && !isnan(d))
#endif
#ifndef isnan
#define isnan(d) (d != d)
#endif

#ifndef NAN
#ifdef _WIN32
#define NAN sqrt(-1.0)
#else
#define NAN 0.0/0.0
#endif
#endif

typedef struct {
    const unsigned char *json;
    size_t position;
} error;
static error global_error = { NULL, 0 };

CJSON_PUBLIC(const char *) cJSON_GetErrorPtr(void)
{
    return (const char*) (global_error.json + global_error.position);
}

CJSON_PUBLIC(char *) cJSON_GetStringValue(const cJSON * const item)
{
    if (!cJSON_IsString(item))
    {
        return NULL;
    }

    return item->valuestring;
}

CJSON_PUBLIC(double) cJSON_GetNumberValue(const cJSON * const item)
{
    if (!cJSON_IsNumber(item))
    {
        return (double) NAN;
    }

    return item->valuedouble;
}

/* This is a safeguard to prevent copy-pasters from using incompatible C and header files */
#if (CJSON_VERSION_MAJOR != 1) || (CJSON_VERSION_MINOR != 7) || (CJSON_VERSION_PATCH != 18)
    #error cJSON.h and cJSON.c have different versions. Make sure that both have the same.
#endif

CJSON_PUBLIC(const char*) cJSON_Version(void)
{
    static char version[15];
    sprintf(version, "%i.%i.%i", CJSON_VERSION_MAJOR, CJSON_VERSION_MINOR, CJSON_VERSION_PATCH);

    return version;
}

/* Case insensitive string comparison, doesn't consider two NULL pointers equal though */
static int case_insensitive_strcmp(const unsigned char *string1, const unsigned char *string2)
{
    if ((string1 == NULL) || (string2 == NULL))
    {
        return 1;
    }

    if (string1 == string2)
    {
        return 0;
    }

    for(; tolower(*string1) == tolower(*string2); (void)string1++, string2++)
    {
        if (*string1 == '\0')
        {
            return 0;
        }
    }

    return tolower(*string1) - tolower(*string2);
}

typedef struct internal_hooks
{
    void *(CJSON_CDECL *allocate)(size_t size);
    void (CJSON_CDECL *deallocate)(void *pointer);
    void *(CJSON_CDECL *reallocate)(void *pointer, size_t size);
} internal_hooks;

#if defined(_MSC_VER)
/* work around MSVC error C2322: '...' address of dllimport '...' is not static */
static void * CJSON_CDECL internal_malloc(size_t size)
{
    return malloc(size);
}
static void CJSON_CDECL internal_free(void *pointer)
{
    free(pointer);
}
static void * CJSON_CDECL internal_realloc(void *pointer, size_t size)
{
    return realloc(pointer, size);
}
#else
#define internal_malloc malloc
#define internal_free free
#define internal_realloc realloc
#endif

/* strlen of character literals resolved at compile time */
#define static_strlen(string_literal) (sizeof(string_literal) - sizeof(""))

static internal_hooks global_hooks = { internal_malloc, internal_free, internal_realloc };

static unsigned char* cJSON_strdup(const unsigned char* string, const internal_hooks * const hooks)
{
    size_t length = 0;
    unsigned char *copy = NULL;

    if (string == NULL)
    {
        return NULL;
    }

    length = strlen((const char*)string) + sizeof("");
    copy = (unsigned char*)hooks->allocate(length);
    if (copy == NULL)
    {
        return NULL;
    }
    memcpy(copy, string, length);

    return copy;
}

CJSON_PUBLIC(void) cJSON_InitHooks(cJSON_Hooks* hooks)
{
    if (hooks == NULL)
    {
        /* Reset hooks */
        global_hooks.allocate = malloc;
        global_hooks.deallocate = free;
        global_hooks.reallocate = realloc;
        return;
    }

    global_hooks.allocate = malloc;
    if (hooks->malloc_fn != NULL)
    {
        global_hooks.allocate = hooks->malloc_fn;
    }

    global_hooks.deallocate = free;
    if (hooks->free_fn != NULL)
    {
        global_hooks.deallocate = hooks->free_fn;
    }

    /* use realloc only if both free and malloc are used */
    global_hooks.reallocate = NULL;
    if ((global_hooks.allocate == malloc) && (global_hooks.deallocate == free))
    {
        global_hooks.reallocate = realloc;
    }
}

/* Internal constructor. */
static cJSON *cJSON_New_Item(const internal_hooks * const hooks)
{
    cJSON* node = (cJSON*)hooks->allocate(sizeof(cJSON));
    if (node)
    {
        memset(node, '\0', sizeof(cJSON));
    }

    return node;
}

/* Delete a cJSON structure. */
CJSON_PUBLIC(void) cJSON_Delete(cJSON *item)
{
    cJSON *next = NULL;
    while (item != NULL)
    {
        next = item->next;
        if (!(item->type & cJSON_IsReference) && (item->child != NULL))
        {
            cJSON_Delete(item->child);
        }
        if (!(item->type & cJSON_IsReference) && (item->valuestring != NULL))
        {
            global_hooks.deallocate(item->valuestring);
            item->valuestring = NULL;
        }
        if (!(item->type & cJSON_StringIsConst) && (item->string != NULL))
        {
            global_hooks.deallocate(item->string);
            item->string = NULL;
        }
        global_hooks.deallocate(item);
        item = next;
    }
}

/* get the decimal point character of the current locale */
static unsigned char get_decimal_point(void)
{
#ifdef ENABLE_LOCALES
    struct lconv *lconv = localeconv();
    return (unsigned char) lconv->decimal_point[0];
#else
    return '.';
#endif
}

typedef struct
{
    const unsigned char *content;
    size_t length;
    size_t offset;
    size_t depth; /* How deeply nested (in arrays/objects) is the input at the current offset. */
    internal_hooks hooks;
} parse_buffer;

/* check if the given size is left to read in a given parse buffer (starting with 1) */
#define can_read(buffer, size) ((buffer != NULL) && (((buffer)->offset + size) <= (buffer)->length))
/* check if the buffer can be accessed at the given index (starting with 0) */
#define can_access_at_index(buffer, index) ((buffer != NULL) && (((buffer)->offset + index) < (buffer)->length))
#define cannot_access_at_index(buffer, index) (!can_access_at_index(buffer, index))
/* get a pointer to the buffer at the position */
#define buffer_at_offset(buffer) ((buffer)->content + (buffer)->offset)

/* Parse the input text to generate a number, and populate the result into item. */
static cJSON_bool parse_number(cJSON * const item, parse_buffer * const input_buffer)
{
    double number = 0;
    unsigned char *after_end = NULL;
    unsigned char number_c_string[64];
    unsigned char decimal_point = get_decimal_point();
    size_t i = 0;

    if ((input_buffer == NULL) || (input_buffer->content == NULL))
    {
        return false;
    }

    /* copy the number into a temporary buffer and replace '.' with the decimal point
     * of the current locale (for strtod)
     * This also takes care of '\0' not necessarily being available for marking the end of the input */
    for (i = 0; (i < (sizeof(number_c_string) - 1)) && can_access_at_index(input_buffer, i); i++)
    {
        switch (buffer_at_offset(input_buffer)[i])
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            case '+':
            case '-':
            case 'e':
            case 'E':
                number_c_string[i] = buffer_at_offset(input_buffer)[i];
                break;

            case '.':
                number_c_string[i] = decimal_point;
                break;

            default:
                goto loop_end;
        }
    }
loop_end:
    number_c_string[i] = '\0';

    number = strtod((const char*)number_c_string, (char**)&after_end);
    if (number_c_string == after_end)
    {
        return false; /* parse_error */
    }

    item->valuedouble = number;

    /* use saturation in case of overflow */
    if (number >= INT_MAX)
    {
        item->valueint = INT_MAX;
    }
    else if (number <= (double)INT_MIN)
    {
        item->valueint = INT_MIN;
    }
    else
    {
        item->valueint = (int)number;
    }

    item->type = cJSON_Number;

    input_buffer->offset += (size_t)(after_end - number_c_string);
    return true;
}

/* don't ask me, but the original cJSON_SetNumberValue returns an integer or double */
CJSON_PUBLIC(double) cJSON_SetNumberHelper(cJSON *object, double number)
{
    if (number >= INT_MAX)
    {
        object->valueint = INT_MAX;
    }
    else if (number <= (double)INT_MIN)
    {
        object->valueint = INT_MIN;
    }
    else
    {
        object->valueint = (int)number;
    }

    return object->valuedouble = number;
}

/* Note: when passing a NULL valuestring, cJSON_SetValuestring treats this as an error and return NULL */
CJSON_PUBLIC(char*) cJSON_SetValuestring(cJSON *object, const char *valuestring)
{
    char *copy = NULL;
    /* if object's type is not cJSON_String or is cJSON_IsReference, it should not set valuestring */
    if ((object == NULL) || !(object->type & cJSON_String) || (object->type & cJSON_IsReference))
    {
        return NULL;
    }
    /* return NULL if the object is corrupted or valuestring is NULL */
    if (object->valuestring == NULL || valuestring == NULL)
    {
        return NULL;
    }
    if (strlen(valuestring) <= strlen(object->valuestring))
    {
        strcpy(object->valuestring, valuestring);
        return object->valuestring;
    }
    copy = (char*) cJSON_strdup((const unsigned char*)valuestring, &global_hooks);
    if (copy == NULL)
    {
        return NULL;
    }
    if (object->valuestring != NULL)
    {
        cJSON_free(object->valuestring);
    }
    object->valuestring = copy;

    return copy;
}

typedef struct
{
    unsigned char *buffer;
    size_t length;
    size_t offset;
    size_t depth; /* current nesting depth (for formatted printing) */
    cJSON_bool noalloc;
    cJSON_bool format; /* is this print a formatted print */
    internal_hooks hooks;
} printbuffer;

/* realloc printbuffer if necessary to have at least "needed" bytes more */
static unsigned char* ensure(printbuffer * const p, size_t needed)
{
    unsigned char *newbuffer = NULL;
    size_t newsize = 0;

    if ((p == NULL) || (p->buffer == NULL))
    {
        return NULL;
    }

    if ((p->length > 0) && (p->offset >= p->length))
    {
        /* make sure that offset is valid */
        return NULL;
    }

    if (needed > INT_MAX)
    {
        /* sizes bigger than INT_MAX are currently not supported */
        return NULL;
    }

    needed += p->offset + 1;
    if (needed <= p->length)
    {
        return p->buffer + p->offset;
    }

    if (p->noalloc) {
        return NULL;
    }

    /* calculate new buffer size */
    if (needed > (INT_MAX / 2))
    {
        /* overflow of int, use INT_MAX if possible */
        if (needed <= INT_MAX)
        {
            newsize = INT_MAX;
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        newsize = needed * 2;
    }

    if (p->hooks.reallocate != NULL)
    {
        /* reallocate with realloc if available */
        newbuffer = (unsigned char*)p->hooks.reallocate(p->buffer, newsize);
        if (newbuffer == NULL)
        {
            p->hooks.deallocate(p->buffer);
            p->length = 0;
            p->buffer = NULL;

            return NULL;
        }
    }
    else
    {
        /* otherwise reallocate manually */
        newbuffer = (unsigned char*)p->hooks.allocate(newsize);
        if (!newbuffer)
        {
            p->hooks.deallocate(p->buffer);
            p->length = 0;
            p->buffer = NULL;

            return NULL;
        }

        memcpy(newbuffer, p->buffer, p->offset + 1);
        p->hooks.deallocate(p->buffer);
    }
    p->length = newsize;
    p->buffer = newbuffer;

    return newbuffer + p->offset;
}

/* calculate the new length of the string in a printbuffer and update the offset */
static void update_offset(printbuffer * const buffer)
{
    const unsigned char *buffer_pointer = NULL;
    if ((buffer == NULL) || (buffer->buffer == NULL))
    {
        return;
    }
    buffer_pointer = buffer->buffer + buffer->offset;

    buffer->offset += strlen((const char*)buffer_pointer);
}

/* securely comparison of floating-point variables */
static cJSON_bool compare_double(double a, double b)
{
    double maxVal = fabs(a) > fabs(b) ? fabs(a) : fabs(b);
    return (fabs(a - b) <= maxVal * DBL_EPSILON);
}

/* Render the number nicely from the given item into a string. */
static cJSON_bool print_number(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output_pointer = NULL;
    double d = item->valuedouble;
    int length = 0;
    size_t i = 0;
    unsigned char number_buffer[26] = {0}; /* temporary buffer to print the number into */
    unsigned char decimal_point = get_decimal_point();
    double test = 0.0;

    if (output_buffer == NULL)
    {
        return false;
    }

    /* This checks for NaN and Infinity */
    if (isnan(d) || isinf(d))
    {
        length = sprintf((char*)number_buffer, "null");
    }
    else if(d == (double)item->valueint)
    {
        length = sprintf((char*)number_buffer, "%d", item->valueint);
    }
    else
    {
        /* Try 15 decimal places of precision to avoid nonsignificant nonzero digits */
        length = sprintf((char*)number_buffer, "%1.15g", d);

        /* Check whether the original double can be recovered */
        if ((sscanf((char*)number_buffer, "%lg", &test) != 1) || !compare_double((double)test, d))
        {
            /* If not, print with 17 decimal places of precision */
            length = sprintf((char*)number_buffer, "%1.17g", d);
        }
    }

    /* sprintf failed or buffer overrun occurred */
    if ((length < 0) || (length > (int)(sizeof(number_buffer) - 1)))
    {
        return false;
    }

    /* reserve appropriate space in the output */
    output_pointer = ensure(output_buffer, (size_t)length + sizeof(""));
    if (output_pointer == NULL)
    {
        return false;
    }

    /* copy the printed number to the output and replace locale
     * dependent decimal point with '.' */
    for (i = 0; i < ((size_t)length); i++)
    {
        if (number_buffer[i] == decimal_point)
        {
            output_pointer[i] = '.';
            continue;
        }

        output_pointer[i] = number_buffer[i];
    }
    output_pointer[i] = '\0';

    output_buffer->offset += (size_t)length;

    return true;
}

/* parse 4 digit hexadecimal number */
static unsigned parse_hex4(const unsigned char * const input)
{
    unsigned int h = 0;
    size_t i = 0;

    for (i = 0; i < 4; i++)
    {
        /* parse digit */
        if ((input[i] >= '0') && (input[i] <= '9'))
        {
            h += (unsigned int) input[i] - '0';
        }
        else if ((input[i] >= 'A') && (input[i] <= 'F'))
        {
            h += (unsigned int) 10 + input[i] - 'A';
        }
        else if ((input[i] >= 'a') && (input[i] <= 'f'))
        {
            h += (unsigned int) 10 + input[i] - 'a';
        }
        else /* invalid */
        {
            return 0;
        }

        if (i < 3)
        {
            /* shift left to make place for the next nibble */
            h = h << 4;
        }
    }

    return h;
}

/* converts a UTF-16 literal to UTF-8
 * A literal can be one or two sequences of the form \uXXXX */
static unsigned char utf16_literal_to_utf8(const unsigned char * const input_pointer, const unsigned char * const input_end, unsigned char **output_pointer)
{
    long unsigned int codepoint = 0;
    unsigned int first_code = 0;
    const unsigned char *first_sequence = input_pointer;
    unsigned char utf8_length = 0;
    unsigned char utf8_position = 0;
    unsigned char sequence_length = 0;
    unsigned char first_byte_mark = 0;

    if ((input_end - first_sequence) < 6)
    {
        /* input ends unexpectedly */
        goto fail;
    }

    /* get the first utf16 sequence */
    first_code = parse_hex4(first_sequence + 2);

    /* check that the code is valid */
    if (((first_code >= 0xDC00) && (first_code <= 0xDFFF)))
    {
        goto fail;
    }

    /* UTF16 surrogate pair */
    if ((first_code >= 0xD800) && (first_code <= 0xDBFF))
    {
        const unsigned char *second_sequence = first_sequence + 6;
        unsigned int second_code = 0;
        sequence_length = 12; /* \uXXXX\uXXXX */

        if ((input_end - second_sequence) < 6)
        {
            /* input ends unexpectedly */
            goto fail;
        }

        if ((second_sequence[0] != '\\') || (second_sequence[1] != 'u'))
        {
            /* missing second half of the surrogate pair */
            goto fail;
        }

        /* get the second utf16 sequence */
        second_code = parse_hex4(second_sequence + 2);
        /* check that the code is valid */
        if ((second_code < 0xDC00) || (second_code > 0xDFFF))
        {
            /* invalid second half of the surrogate pair */
            goto fail;
        }


        /* calculate the unicode codepoint from the surrogate pair */
        codepoint = 0x10000 + (((first_code & 0x3FF) << 10) | (second_code & 0x3FF));
    }
    else
    {
        sequence_length = 6; /* \uXXXX */
        codepoint = first_code;
    }

    /* encode as UTF-8
     * takes at maximum 4 bytes to encode:
     * 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx */
    if (codepoint < 0x80)
    {
        /* normal ascii, encoding 0xxxxxxx */
        utf8_length = 1;
    }
    else if (codepoint < 0x800)
    {
        /* two bytes, encoding 110xxxxx 10xxxxxx */
        utf8_length = 2;
        first_byte_mark = 0xC0; /* 11000000 */
    }
    else if (codepoint < 0x10000)
    {
        /* three bytes, encoding 1110xxxx 10xxxxxx 10xxxxxx */
        utf8_length = 3;
        first_byte_mark = 0xE0; /* 11100000 */
    }
    else if (codepoint <= 0x10FFFF)
    {
        /* four bytes, encoding 1110xxxx 10xxxxxx 10xxxxxx 10xxxxxx */
        utf8_length = 4;
        first_byte_mark = 0xF0; /* 11110000 */
    }
    else
    {
        /* invalid unicode codepoint */
        goto fail;
    }

    /* encode as utf8 */
    for (utf8_position = (unsigned char)(utf8_length - 1); utf8_position > 0; utf8_position--)
    {
        /* 10xxxxxx */
        (*output_pointer)[utf8_position] = (unsigned char)((codepoint | 0x80) & 0xBF);
        codepoint >>= 6;
    }
    /* encode first byte */
    if (utf8_length > 1)
    {
        (*output_pointer)[0] = (unsigned char)((codepoint | first_byte_mark) & 0xFF);
    }
    else
    {
        (*output_pointer)[0] = (unsigned char)(codepoint & 0x7F);
    }

    *output_pointer += utf8_length;

    return sequence_length;

fail:
    return 0;
}

/* Parse the input text into an unescaped cinput, and populate item. */
static cJSON_bool parse_string(cJSON * const item, parse_buffer * const input_buffer)
{
    const unsigned char *input_pointer = buffer_at_offset(input_buffer) + 1;
    const unsigned char *input_end = buffer_at_offset(input_buffer) + 1;
    unsigned char *output_pointer = NULL;
    unsigned char *output = NULL;

    /* not a string */
    if (buffer_at_offset(input_buffer)[0] != '\"')
    {
        goto fail;
    }

    {
        /* calculate approximate size of the output (overestimate) */
        size_t allocation_length = 0;
        size_t skipped_bytes = 0;
        while (((size_t)(input_end - input_buffer->content) < input_buffer->length) && (*input_end != '\"'))
        {
            /* is escape sequence */
            if (input_end[0] == '\\')
            {
                if ((size_t)(input_end + 1 - input_buffer->content) >= input_buffer->length)
                {
                    /* prevent buffer overflow when last input character is a backslash */
                    goto fail;
                }
                skipped_bytes++;
                input_end++;
            }
            input_end++;
        }
        if (((size_t)(input_end - input_buffer->content) >= input_buffer->length) || (*input_end != '\"'))
        {
            goto fail; /* string ended unexpectedly */
        }

        /* This is at most how much we need for the output */
        allocation_length = (size_t) (input_end - buffer_at_offset(input_buffer)) - skipped_bytes;
        output = (unsigned char*)input_buffer->hooks.allocate(allocation_length + sizeof(""));
        if (output == NULL)
        {
            goto fail; /* allocation failure */
        }
    }

    output_pointer = output;
    /* loop through the string literal */
    while (input_pointer < input_end)
    {
        if (*input_pointer != '\\')
        {
            *output_pointer++ = *input_pointer++;
        }
        /* escape sequence */
        else
        {
            unsigned char sequence_length = 2;
            if ((input_end - input_pointer) < 1)
            {
                goto fail;
            }

            switch (input_pointer[1])
            {
                case 'b':
                    *output_pointer++ = '\b';
                    break;
                case 'f':
                    *output_pointer++ = '\f';
                    break;
                case 'n':
                    *output_pointer++ = '\n';
                    break;
                case 'r':
                    *output_pointer++ = '\r';
                    break;
                case 't':
                    *output_pointer++ = '\t';
                    break;
                case '\"':
                case '\\':
                case '/':
                    *output_pointer++ = input_pointer[1];
                    break;

                /* UTF-16 literal */
                case 'u':
                    sequence_length = utf16_literal_to_utf8(input_pointer, input_end, &output_pointer);
                    if (sequence_length == 0)
                    {
                        /* failed to convert UTF16-literal to UTF-8 */
                        goto fail;
                    }
                    break;

                default:
                    goto fail;
            }
            input_pointer += sequence_length;
        }
    }

    /* zero terminate the output */
    *output_pointer = '\0';

    item->type = cJSON_String;
    item->valuestring = (char*)output;

    input_buffer->offset = (size_t) (input_end - input_buffer->content);
    input_buffer->offset++;

    return true;

fail:
    if (output != NULL)
    {
        input_buffer->hooks.deallocate(output);
        output = NULL;
    }

    if (input_pointer != NULL)
    {
        input_buffer->offset = (size_t)(input_pointer - input_buffer->content);
    }

    return false;
}

/* Render the cstring provided to an escaped version that can be printed. */
static cJSON_bool print_string_ptr(const unsigned char * const input, printbuffer * const output_buffer)
{
    const unsigned char *input_pointer = NULL;
    unsigned char *output = NULL;
    unsigned char *output_pointer = NULL;
    size_t output_length = 0;
    /* numbers of additional characters needed for escaping */
    size_t escape_characters = 0;

    if (output_buffer == NULL)
    {
        return false;
    }

    /* empty string */
    if (input == NULL)
    {
        output = ensure(output_buffer, sizeof("\"\""));
        if (output == NULL)
        {
            return false;
        }
        strcpy((char*)output, "\"\"");

        return true;
    }

    /* set "flag" to 1 if something needs to be escaped */
    for (input_pointer = input; *input_pointer; input_pointer++)
    {
        switch (*input_pointer)
        {
            case '\"':
            case '\\':
            case '\b':
            case '\f':
            case '\n':
            case '\r':
            case '\t':
                /* one character escape sequence */
                escape_characters++;
                break;
            default:
                if (*input_pointer < 32)
                {
                    /* UTF-16 escape sequence uXXXX */
                    escape_characters += 5;
                }
                break;
        }
    }
    output_length = (size_t)(input_pointer - input) + escape_characters;

    output = ensure(output_buffer, output_length + sizeof("\"\""));
    if (output == NULL)
    {
        return false;
    }

    /* no characters have to be escaped */
    if (escape_characters == 0)
    {
        output[0] = '\"';
        memcpy(output + 1, input, output_length);
        output[output_length + 1] = '\"';
        output[output_length + 2] = '\0';

        return true;
    }

    output[0] = '\"';
    output_pointer = output + 1;
    /* copy the string */
    for (input_pointer = input; *input_pointer != '\0'; (void)input_pointer++, output_pointer++)
    {
        if ((*input_pointer > 31) && (*input_pointer != '\"') && (*input_pointer != '\\'))
        {
            /* normal character, copy */
            *output_pointer = *input_pointer;
        }
        else
        {
            /* character needs to be escaped */
            *output_pointer++ = '\\';
            switch (*input_pointer)
            {
                case '\\':
                    *output_pointer = '\\';
                    break;
                case '\"':
                    *output_pointer = '\"';
                    break;
                case '\b':
                    *output_pointer = 'b';
                    break;
                case '\f':
                    *output_pointer = 'f';
                    break;
                case '\n':
                    *output_pointer = 'n';
                    break;
                case '\r':
                    *output_pointer = 'r';
                    break;
                case '\t':
                    *output_pointer = 't';
                    break;
                default:
                    /* escape and print as unicode codepoint */
                    sprintf((char*)output_pointer, "u%04x", *input_pointer);
                    output_pointer += 4;
                    break;
            }
        }
    }
    output[output_length + 1] = '\"';
    output[output_length + 2] = '\0';

    return true;
}

/* Invoke print_string_ptr (which is useful) on an item. */
static cJSON_bool print_string(const cJSON * const item, printbuffer * const p)
{
    return print_string_ptr((unsigned char*)item->valuestring, p);
}

/* Predeclare these prototypes. */
static cJSON_bool parse_value(cJSON * const item, parse_buffer * const input_buffer);
static cJSON_bool print_value(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool parse_array(cJSON * const item, parse_buffer * const input_buffer);
static cJSON_bool print_array(const cJSON * const item, printbuffer * const output_buffer);
static cJSON_bool parse_object(cJSON * const item, parse_buffer * const input_buffer);
static cJSON_bool print_object(const cJSON * const item, printbuffer * const output_buffer);

/* Utility to jump whitespace and cr/lf */
static parse_buffer *buffer_skip_whitespace(parse_buffer * const buffer)
{
    if ((buffer == NULL) || (buffer->content == NULL))
    {
        return NULL;
    }

    if (cannot_access_at_index(buffer, 0))
    {
        return buffer;
    }

    while (can_access_at_index(buffer, 0) && (buffer_at_offset(buffer)[0] <= 32))
    {
       buffer->offset++;
    }

    if (buffer->offset == buffer->length)
    {
        buffer->offset--;
    }

    return buffer;
}

/* skip the UTF-8 BOM (byte order mark) if it is at the beginning of a buffer */
static parse_buffer *skip_utf8_bom(parse_buffer * const buffer)
{
    if ((buffer == NULL) || (buffer->content == NULL) || (buffer->offset != 0))
    {
        return NULL;
    }

    if (can_access_at_index(buffer, 4) && (strncmp((const char*)buffer_at_offset(buffer), "\xEF\xBB\xBF", 3) == 0))
    {
        buffer->offset += 3;
    }

    return buffer;
}

CJSON_PUBLIC(cJSON *) cJSON_ParseWithOpts(const char *value, const char **return_parse_end, cJSON_bool require_null_terminated)
{
    size_t buffer_length;

    if (NULL == value)
    {
        return NULL;
    }

    /* Adding null character size due to require_null_terminated. */
    buffer_length = strlen(value) + sizeof("");

    return cJSON_ParseWithLengthOpts(value, buffer_length, return_parse_end, require_null_terminated);
}

/* Parse an object - create a new root, and populate. */
CJSON_PUBLIC(cJSON *) cJSON_ParseWithLengthOpts(const char *value, size_t buffer_length, const char **return_parse_end, cJSON_bool require_null_terminated)
{
    parse_buffer buffer = { 0, 0, 0, 0, { 0, 0, 0 } };
    cJSON *item = NULL;

    /* reset error position */
    global_error.json = NULL;
    global_error.position = 0;

    if (value == NULL || 0 == buffer_length)
    {
        goto fail;
    }

    buffer.content = (const unsigned char*)value;
    buffer.length = buffer_length;
    buffer.offset = 0;
    buffer.hooks = global_hooks;

    item = cJSON_New_Item(&global_hooks);
    if (item == NULL) /* memory fail */
    {
        goto fail;
    }

    if (!parse_value(item, buffer_skip_whitespace(skip_utf8_bom(&buffer))))
    {
        /* parse failure. ep is set. */
        goto fail;
    }

    /* if we require null-terminated JSON without appended garbage, skip and then check for a null terminator */
    if (require_null_terminated)
    {
        buffer_skip_whitespace(&buffer);
        if ((buffer.offset >= buffer.length) || buffer_at_offset(&buffer)[0] != '\0')
        {
            goto fail;
        }
    }
    if (return_parse_end)
    {
        *return_parse_end = (const char*)buffer_at_offset(&buffer);
    }

    return item;

fail:
    if (item != NULL)
    {
        cJSON_Delete(item);
    }

    if (value != NULL)
    {
        error local_error;
        local_error.json = (const unsigned char*)value;
        local_error.position = 0;

        if (buffer.offset < buffer.length)
        {
            local_error.position = buffer.offset;
        }
        else if (buffer.length > 0)
        {
            local_error.position = buffer.length - 1;
        }

        if (return_parse_end != NULL)
        {
            *return_parse_end = (const char*)local_error.json + local_error.position;
        }

        global_error = local_error;
    }

    return NULL;
}

/* Default options for cJSON_Parse */
CJSON_PUBLIC(cJSON *) cJSON_Parse(const char *value)
{
    return cJSON_ParseWithOpts(value, 0, 0);
}

CJSON_PUBLIC(cJSON *) cJSON_ParseWithLength(const char *value, size_t buffer_length)
{
    return cJSON_ParseWithLengthOpts(value, buffer_length, 0, 0);
}

#define cjson_min(a, b) (((a) < (b)) ? (a) : (b))

static unsigned char *print(const cJSON * const item, cJSON_bool format, const internal_hooks * const hooks)
{
    static const size_t default_buffer_size = 256;
    printbuffer buffer[1];
    unsigned char *printed = NULL;

    memset(buffer, 0, sizeof(buffer));

    /* create buffer */
    buffer->buffer = (unsigned char*) hooks->allocate(default_buffer_size);
    buffer->length = default_buffer_size;
    buffer->format = format;
    buffer->hooks = *hooks;
    if (buffer->buffer == NULL)
    {
        goto fail;
    }

    /* print the value */
    if (!print_value(item, buffer))
    {
        goto fail;
    }
    update_offset(buffer);

    /* check if reallocate is available */
    if (hooks->reallocate != NULL)
    {
        printed = (unsigned char*) hooks->reallocate(buffer->buffer, buffer->offset + 1);
        if (printed == NULL) {
            goto fail;
        }
        buffer->buffer = NULL;
    }
    else /* otherwise copy the JSON over to a new buffer */
    {
        printed = (unsigned char*) hooks->allocate(buffer->offset + 1);
        if (printed == NULL)
        {
            goto fail;
        }
        memcpy(printed, buffer->buffer, cjson_min(buffer->length, buffer->offset + 1));
        printed[buffer->offset] = '\0'; /* just to be sure */

        /* free the buffer */
        hooks->deallocate(buffer->buffer);
        buffer->buffer = NULL;
    }

    return printed;

fail:
    if (buffer->buffer != NULL)
    {
        hooks->deallocate(buffer->buffer);
        buffer->buffer = NULL;
    }

    if (printed != NULL)
    {
        hooks->deallocate(printed);
        printed = NULL;
    }

    return NULL;
}

/* Render a cJSON item/entity/structure to text. */
CJSON_PUBLIC(char *) cJSON_Print(const cJSON *item)
{
    return (char*)print(item, true, &global_hooks);
}

CJSON_PUBLIC(char *) cJSON_PrintUnformatted(const cJSON *item)
{
    return (char*)print(item, false, &global_hooks);
}

CJSON_PUBLIC(char *) cJSON_PrintBuffered(const cJSON *item, int prebuffer, cJSON_bool fmt)
{
    printbuffer p = { 0, 0, 0, 0, 0, 0, { 0, 0, 0 } };

    if (prebuffer < 0)
    {
        return NULL;
    }

    p.buffer = (unsigned char*)global_hooks.allocate((size_t)prebuffer);
    if (!p.buffer)
    {
        return NULL;
    }

    p.length = (size_t)prebuffer;
    p.offset = 0;
    p.noalloc = false;
    p.format = fmt;
    p.hooks = global_hooks;

    if (!print_value(item, &p))
    {
        global_hooks.deallocate(p.buffer);
        p.buffer = NULL;
        return NULL;
    }

    return (char*)p.buffer;
}

CJSON_PUBLIC(cJSON_bool) cJSON_PrintPreallocated(cJSON *item, char *buffer, const int length, const cJSON_bool format)
{
    printbuffer p = { 0, 0, 0, 0, 0, 0, { 0, 0, 0 } };

    if ((length < 0) || (buffer == NULL))
    {
        return false;
    }

    p.buffer = (unsigned char*)buffer;
    p.length = (size_t)length;
    p.offset = 0;
    p.noalloc = true;
    p.format = format;
    p.hooks = global_hooks;

    return print_value(item, &p);
}

/* Parser core - when encountering text, process appropriately. */
static cJSON_bool parse_value(cJSON * const item, parse_buffer * const input_buffer)
{
    if ((input_buffer == NULL) || (input_buffer->content == NULL))
    {
        return false; /* no input */
    }

    /* parse the different types of values */
    /* null */
    if (can_read(input_buffer, 4) && (strncmp((const char*)buffer_at_offset(input_buffer), "null", 4) == 0))
    {
        item->type = cJSON_NULL;
        input_buffer->offset += 4;
        return true;
    }
    /* false */
    if (can_read(input_buffer, 5) && (strncmp((const char*)buffer_at_offset(input_buffer), "false", 5) == 0))
    {
        item->type = cJSON_False;
        input_buffer->offset += 5;
        return true;
    }
    /* true */
    if (can_read(input_buffer, 4) && (strncmp((const char*)buffer_at_offset(input_buffer), "true", 4) == 0))
    {
        item->type = cJSON_True;
        item->valueint = 1;
        input_buffer->offset += 4;
        return true;
    }
    /* string */
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '\"'))
    {
        return parse_string(item, input_buffer);
    }
    /* number */
    if (can_access_at_index(input_buffer, 0) && ((buffer_at_offset(input_buffer)[0] == '-') || ((buffer_at_offset(input_buffer)[0] >= '0') && (buffer_at_offset(input_buffer)[0] <= '9'))))
    {
        return parse_number(item, input_buffer);
    }
    /* array */
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '['))
    {
        return parse_array(item, input_buffer);
    }
    /* object */
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '{'))
    {
        return parse_object(item, input_buffer);
    }

    return false;
}

/* Render a value to text. */
static cJSON_bool print_value(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output = NULL;

    if ((item == NULL) || (output_buffer == NULL))
    {
        return false;
    }

    switch ((item->type) & 0xFF)
    {
        case cJSON_NULL:
            output = ensure(output_buffer, 5);
            if (output == NULL)
            {
                return false;
            }
            strcpy((char*)output, "null");
            return true;

        case cJSON_False:
            output = ensure(output_buffer, 6);
            if (output == NULL)
            {
                return false;
            }
            strcpy((char*)output, "false");
            return true;

        case cJSON_True:
            output = ensure(output_buffer, 5);
            if (output == NULL)
            {
                return false;
            }
            strcpy((char*)output, "true");
            return true;

        case cJSON_Number:
            return print_number(item, output_buffer);

        case cJSON_Raw:
        {
            size_t raw_length = 0;
            if (item->valuestring == NULL)
            {
                return false;
            }

            raw_length = strlen(item->valuestring) + sizeof("");
            output = ensure(output_buffer, raw_length);
            if (output == NULL)
            {
                return false;
            }
            memcpy(output, item->valuestring, raw_length);
            return true;
        }

        case cJSON_String:
            return print_string(item, output_buffer);

        case cJSON_Array:
            return print_array(item, output_buffer);

        case cJSON_Object:
            return print_object(item, output_buffer);

        default:
            return false;
    }
}

/* Build an array from input text. */
static cJSON_bool parse_array(cJSON * const item, parse_buffer * const input_buffer)
{
    cJSON *head = NULL; /* head of the linked list */
    cJSON *current_item = NULL;

    if (input_buffer->depth >= CJSON_NESTING_LIMIT)
    {
        return false; /* to deeply nested */
    }
    input_buffer->depth++;

    if (buffer_at_offset(input_buffer)[0] != '[')
    {
        /* not an array */
        goto fail;
    }

    input_buffer->offset++;
    buffer_skip_whitespace(input_buffer);
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == ']'))
    {
        /* empty array */
        goto success;
    }

    /* check if we skipped to the end of the buffer */
    if (cannot_access_at_index(input_buffer, 0))
    {
        input_buffer->offset--;
        goto fail;
    }

    /* step back to character in front of the first element */
    input_buffer->offset--;
    /* loop through the comma separated array elements */
    do
    {
        /* allocate next item */
        cJSON *new_item = cJSON_New_Item(&(input_buffer->hooks));
        if (new_item == NULL)
        {
            goto fail; /* allocation failure */
        }

        /* attach next item to list */
        if (head == NULL)
        {
            /* start the linked list */
            current_item = head = new_item;
        }
        else
        {
            /* add to the end and advance */
            current_item->next = new_item;
            new_item->prev = current_item;
            current_item = new_item;
        }

        /* parse next value */
        input_buffer->offset++;
        buffer_skip_whitespace(input_buffer);
        if (!parse_value(current_item, input_buffer))
        {
            goto fail; /* failed to parse value */
        }
        buffer_skip_whitespace(input_buffer);
    }
    while (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == ','));

    if (cannot_access_at_index(input_buffer, 0) || buffer_at_offset(input_buffer)[0] != ']')
    {
        goto fail; /* expected end of array */
    }

success:
    input_buffer->depth--;

    if (head != NULL) {
        head->prev = current_item;
    }

    item->type = cJSON_Array;
    item->child = head;

    input_buffer->offset++;

    return true;

fail:
    if (head != NULL)
    {
        cJSON_Delete(head);
    }

    return false;
}

/* Render an array to text */
static cJSON_bool print_array(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output_pointer = NULL;
    size_t length = 0;
    cJSON *current_element = item->child;

    if (output_buffer == NULL)
    {
        return false;
    }

    /* Compose the output array. */
    /* opening square bracket */
    output_pointer = ensure(output_buffer, 1);
    if (output_pointer == NULL)
    {
        return false;
    }

    *output_pointer = '[';
    output_buffer->offset++;
    output_buffer->depth++;

    while (current_element != NULL)
    {
        if (!print_value(current_element, output_buffer))
        {
            return false;
        }
        update_offset(output_buffer);
        if (current_element->next)
        {
            length = (size_t) (output_buffer->format ? 2 : 1);
            output_pointer = ensure(output_buffer, length + 1);
            if (output_pointer == NULL)
            {
                return false;
            }
            *output_pointer++ = ',';
            if(output_buffer->format)
            {
                *output_pointer++ = ' ';
            }
            *output_pointer = '\0';
            output_buffer->offset += length;
        }
        current_element = current_element->next;
    }

    output_pointer = ensure(output_buffer, 2);
    if (output_pointer == NULL)
    {
        return false;
    }
    *output_pointer++ = ']';
    *output_pointer = '\0';
    output_buffer->depth--;

    return true;
}

/* Build an object from the text. */
static cJSON_bool parse_object(cJSON * const item, parse_buffer * const input_buffer)
{
    cJSON *head = NULL; /* linked list head */
    cJSON *current_item = NULL;

    if (input_buffer->depth >= CJSON_NESTING_LIMIT)
    {
        return false; /* to deeply nested */
    }
    input_buffer->depth++;

    if (cannot_access_at_index(input_buffer, 0) || (buffer_at_offset(input_buffer)[0] != '{'))
    {
        goto fail; /* not an object */
    }

    input_buffer->offset++;
    buffer_skip_whitespace(input_buffer);
    if (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == '}'))
    {
        goto success; /* empty object */
    }

    /* check if we skipped to the end of the buffer */
    if (cannot_access_at_index(input_buffer, 0))
    {
        input_buffer->offset--;
        goto fail;
    }

    /* step back to character in front of the first element */
    input_buffer->offset--;
    /* loop through the comma separated array elements */
    do
    {
        /* allocate next item */
        cJSON *new_item = cJSON_New_Item(&(input_buffer->hooks));
        if (new_item == NULL)
        {
            goto fail; /* allocation failure */
        }

        /* attach next item to list */
        if (head == NULL)
        {
            /* start the linked list */
            current_item = head = new_item;
        }
        else
        {
            /* add to the end and advance */
            current_item->next = new_item;
            new_item->prev = current_item;
            current_item = new_item;
        }

        if (cannot_access_at_index(input_buffer, 1))
        {
            goto fail; /* nothing comes after the comma */
        }

        /* parse the name of the child */
        input_buffer->offset++;
        buffer_skip_whitespace(input_buffer);
        if (!parse_string(current_item, input_buffer))
        {
            goto fail; /* failed to parse name */
        }
        buffer_skip_whitespace(input_buffer);

        /* swap valuestring and string, because we parsed the name */
        current_item->string = current_item->valuestring;
        current_item->valuestring = NULL;

        if (cannot_access_at_index(input_buffer, 0) || (buffer_at_offset(input_buffer)[0] != ':'))
        {
            goto fail; /* invalid object */
        }

        /* parse the value */
        input_buffer->offset++;
        buffer_skip_whitespace(input_buffer);
        if (!parse_value(current_item, input_buffer))
        {
            goto fail; /* failed to parse value */
        }
        buffer_skip_whitespace(input_buffer);
    }
    while (can_access_at_index(input_buffer, 0) && (buffer_at_offset(input_buffer)[0] == ','));

    if (cannot_access_at_index(input_buffer, 0) || (buffer_at_offset(input_buffer)[0] != '}'))
    {
        goto fail; /* expected end of object */
    }

success:
    input_buffer->depth--;

    if (head != NULL) {
        head->prev = current_item;
    }

    item->type = cJSON_Object;
    item->child = head;

    input_buffer->offset++;
    return true;

fail:
    if (head != NULL)
    {
        cJSON_Delete(head);
    }

    return false;
}

/* Render an object to text. */
static cJSON_bool print_object(const cJSON * const item, printbuffer * const output_buffer)
{
    unsigned char *output_pointer = NULL;
    size_t length = 0;
    cJSON *current_item = item->child;

    if (output_buffer == NULL)
    {
        return false;
    }

    /* Compose the output: */
    length = (size_t) (output_buffer->format ? 2 : 1); /* fmt: {\n */
    output_pointer = ensure(output_buffer, length + 1);
    if (output_pointer == NULL)
    {
        return false;
    }

    *output_pointer++ = '{';
    output_buffer->depth++;
    if (output_buffer->format)
    {
        *output_pointer++ = '\n';
    }
    output_buffer->offset += length;

    while (current_item)
    {
        if (output_buffer->format)
        {
            size_t i;
            output_pointer = ensure(output_buffer, output_buffer->depth);
            if (output_pointer == NULL)
            {
                return false;
            }
            for (i = 0; i < output_buffer->depth; i++)
            {
                *output_pointer++ = '\t';
            }
            output_buffer->offset += output_buffer->depth;
        }

        /* print key */
        if (!print_string_ptr((unsigned char*)current_item->string, output_buffer))
        {
            return false;
        }
        update_offset(output_buffer);

        length = (size_t) (output_buffer->format ? 2 : 1);
        output_pointer = ensure(output_buffer, length);
        if (output_pointer == NULL)
        {
            return false;
        }
        *output_pointer++ = ':';
        if (output_buffer->format)
        {
            *output_pointer++ = '\t';
        }
        output_buffer->offset += length;

        /* print value */
        if (!print_value(current_item, output_buffer))
        {
            return false;
        }
        update_offset(output_buffer);

        /* print comma if not last */
        length = ((size_t)(output_buffer->format ? 1 : 0) + (size_t)(current_item->next ? 1 : 0));
        output_pointer = ensure(output_buffer, length + 1);
        if (output_pointer == NULL)
        {
            return false;
        }
        if (current_item->next)
        {
            *output_pointer++ = ',';
        }

        if (output_buffer->format)
        {
            *output_pointer++ = '\n';
        }
        *output_pointer = '\0';
        output_buffer->offset += length;

        current_item = current_item->next;
    }

    output_pointer = ensure(output_buffer, output_buffer->format ? (output_buffer->depth + 1) : 2);
    if (output_pointer == NULL)
    {
        return false;
    }
    if (output_buffer->format)
    {
        size_t i;
        for (i = 0; i < (output_buffer->depth - 1); i++)
        {
            *output_pointer++ = '\t';
        }
    }
    *output_pointer++ = '}';
    *output_pointer = '\0';
    output_buffer->depth--;

    return true;
}

/* Get Array size/item / object item. */
CJSON_PUBLIC(int) cJSON_GetArraySize(const cJSON *array)
{
    cJSON *child = NULL;
    size_t size = 0;

    if (array == NULL)
    {
        return 0;
    }

    child = array->child;

    while(child != NULL)
    {
        size++;
        child = child->next;
    }

    /* FIXME: Can overflow here. Cannot be fixed without breaking the API */

    return (int)size;
}

static cJSON* get_array_item(const cJSON *array, size_t index)
{
    cJSON *current_child = NULL;

    if (array == NULL)
    {
        return NULL;
    }

    current_child = array->child;
    while ((current_child != NULL) && (index > 0))
    {
        index--;
        current_child = current_child->next;
    }

    return current_child;
}

CJSON_PUBLIC(cJSON *) cJSON_GetArrayItem(const cJSON *array, int index)
{
    if (index < 0)
    {
        return NULL;
    }

    return get_array_item(array, (size_t)index);
}

static cJSON *get_object_item(const cJSON * const object, const char * const name, const cJSON_bool case_sensitive)
{
    cJSON *current_element = NULL;

    if ((object == NULL) || (name == NULL))
    {
        return NULL;
    }

    current_element = object->child;
    if (case_sensitive)
    {
        while ((current_element != NULL) && (current_element->string != NULL) && (strcmp(name, current_element->string) != 0))
        {
            current_element = current_element->next;
        }
    }
    else
    {
        while ((current_element != NULL) && (case_insensitive_strcmp((const unsigned char*)name, (const unsigned char*)(current_element->string)) != 0))
        {
            current_element = current_element->next;
        }
    }

    if ((current_element == NULL) || (current_element->string == NULL)) {
        return NULL;
    }

    return current_element;
}

CJSON_PUBLIC(cJSON *) cJSON_GetObjectItem(const cJSON * const object, const char * const string)
{
    return get_object_item(object, string, false);
}

CJSON_PUBLIC(cJSON *) cJSON_GetObjectItemCaseSensitive(const cJSON * const object, const char * const string)
{
    return get_object_item(object, string, true);
}

CJSON_PUBLIC(cJSON_bool) cJSON_HasObjectItem(const cJSON *object, const char *string)
{
    return cJSON_GetObjectItem(object, string) ? 1 : 0;
}

/* Utility for array list handling. */
static void suffix_object(cJSON *prev, cJSON *item)
{
    prev->next = item;
    item->prev = prev;
}

/* Utility for handling references. */
static cJSON *create_reference(const cJSON *item, const internal_hooks * const hooks)
{
    cJSON *reference = NULL;
    if (item == NULL)
    {
        return NULL;
    }

    reference = cJSON_New_Item(hooks);
    if (reference == NULL)
    {
        return NULL;
    }

    memcpy(reference, item, sizeof(cJSON));
    reference->string = NULL;
    reference->type |= cJSON_IsReference;
    reference->next = reference->prev = NULL;
    return reference;
}

static cJSON_bool add_item_to_array(cJSON *array, cJSON *item)
{
    cJSON *child = NULL;

    if ((item == NULL) || (array == NULL) || (array == item))
    {
        return false;
    }

    child = array->child;
    /*
     * To find the last item in array quickly, we use prev in array
     */
    if (child == NULL)
    {
        /* list is empty, start new one */
        array->child = item;
        item->prev = item;
        item->next = NULL;
    }
    else
    {
        /* append to the end */
        if (child->prev)
        {
            suffix_object(child->prev, item);
            array->child->prev = item;
        }
    }

    return true;
}

/* Add item to array/object. */
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToArray(cJSON *array, cJSON *item)
{
    return add_item_to_array(array, item);
}

#if defined(__clang__) || (defined(__GNUC__)  && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5))))
    #pragma GCC diagnostic push
#endif
#ifdef __GNUC__
#pragma GCC diagnostic ignored "-Wcast-qual"
#endif
/* helper function to cast away const */
static void* cast_away_const(const void* string)
{
    return (void*)string;
}
#if defined(__clang__) || (defined(__GNUC__)  && ((__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ > 5))))
    #pragma GCC diagnostic pop
#endif


static cJSON_bool add_item_to_object(cJSON * const object, const char * const string, cJSON * const item, const internal_hooks * const hooks, const cJSON_bool constant_key)
{
    char *new_key = NULL;
    int new_type = cJSON_Invalid;

    if ((object == NULL) || (string == NULL) || (item == NULL) || (object == item))
    {
        return false;
    }

    if (constant_key)
    {
        new_key = (char*)cast_away_const(string);
        new_type = item->type | cJSON_StringIsConst;
    }
    else
    {
        new_key = (char*)cJSON_strdup((const unsigned char*)string, hooks);
        if (new_key == NULL)
        {
            return false;
        }

        new_type = item->type & ~cJSON_StringIsConst;
    }

    if (!(item->type & cJSON_StringIsConst) && (item->string != NULL))
    {
        hooks->deallocate(item->string);
    }

    item->string = new_key;
    item->type = new_type;

    return add_item_to_array(object, item);
}

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObject(cJSON *object, const char *string, cJSON *item)
{
    return add_item_to_object(object, string, item, &global_hooks, false);
}

/* Add an item to an object with constant string as key */
CJSON_PUBLIC(cJSON_bool) cJSON_AddItemToObjectCS(cJSON *object, const char *string, cJSON *item)
{
    return add_item_to_object(object, string, item, &global_hooks, true);
}

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToArray(cJSON *array, cJSON *item)
{
    if (array == NULL)
    {
        return false;
    }

    return add_item_to_array(array, create_reference(item, &global_hooks));
}

CJSON_PUBLIC(cJSON_bool) cJSON_AddItemReferenceToObject(cJSON *object, const char *string, cJSON *item)
{
    if ((object == NULL) || (string == NULL))
    {
        return false;
    }

    return add_item_to_object(object, string, create_reference(item, &global_hooks), &global_hooks, false);
}

CJSON_PUBLIC(cJSON*) cJSON_AddNullToObject(cJSON * const object, const char * const name)
{
    cJSON *null = cJSON_CreateNull();
    if (add_item_to_object(object, name, null, &global_hooks, false))
    {
        return null;
    }

    cJSON_Delete(null);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddTrueToObject(cJSON * const object, const char * const name)
{
    cJSON *true_item = cJSON_CreateTrue();
    if (add_item_to_object(object, name, true_item, &global_hooks, false))
    {
        return true_item;
    }

    cJSON_Delete(true_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddFalseToObject(cJSON * const object, const char * const name)
{
    cJSON *false_item = cJSON_CreateFalse();
    if (add_item_to_object(object, name, false_item, &global_hooks, false))
    {
        return false_item;
    }

    cJSON_Delete(false_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddBoolToObject(cJSON * const object, const char * const name, const cJSON_bool boolean)
{
    cJSON *bool_item = cJSON_CreateBool(boolean);
    if (add_item_to_object(object, name, bool_item, &global_hooks, false))
    {
        return bool_item;
    }

    cJSON_Delete(bool_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddNumberToObject(cJSON * const object, const char * const name, const double number)
{
    cJSON *number_item = cJSON_CreateNumber(number);
    if (add_item_to_object(object, name, number_item, &global_hooks, false))
    {
        return number_item;
    }

    cJSON_Delete(number_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddStringToObject(cJSON * const object, const char * const name, const char * const string)
{
    cJSON *string_item = cJSON_CreateString(string);
    if (add_item_to_object(object, name, string_item, &global_hooks, false))
    {
        return string_item;
    }

    cJSON_Delete(string_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddRawToObject(cJSON * const object, const char * const name, const char * const raw)
{
    cJSON *raw_item = cJSON_CreateRaw(raw);
    if (add_item_to_object(object, name, raw_item, &global_hooks, false))
    {
        return raw_item;
    }

    cJSON_Delete(raw_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddObjectToObject(cJSON * const object, const char * const name)
{
    cJSON *object_item = cJSON_CreateObject();
    if (add_item_to_object(object, name, object_item, &global_hooks, false))
    {
        return object_item;
    }

    cJSON_Delete(object_item);
    return NULL;
}

CJSON_PUBLIC(cJSON*) cJSON_AddArrayToObject(cJSON * const object, const char * const name)
{
    cJSON *array = cJSON_CreateArray();
    if (add_item_to_object(object, name, array, &global_hooks, false))
    {
        return array;
    }

    cJSON_Delete(array);
    return NULL;
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemViaPointer(cJSON *parent, cJSON * const item)
{
    if ((parent == NULL) || (item == NULL))
    {
        return NULL;
    }

    if (item != parent->child)
    {
        /* not the first element */
        item->prev->next = item->next;
    }
    if (item->next != NULL)
    {
        /* not the last element */
        item->next->prev = item->prev;
    }

    if (item == parent->child)
    {
        /* first element */
        parent->child = item->next;
    }
    else if (item->next == NULL)
    {
        /* last element */
        parent->child->prev = item->prev;
    }

    /* make sure the detached item doesn't point anywhere anymore */
    item->prev = NULL;
    item->next = NULL;

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromArray(cJSON *array, int which)
{
    if (which < 0)
    {
        return NULL;
    }

    return cJSON_DetachItemViaPointer(array, get_array_item(array, (size_t)which));
}

CJSON_PUBLIC(void) cJSON_DeleteItemFromArray(cJSON *array, int which)
{
    cJSON_Delete(cJSON_DetachItemFromArray(array, which));
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObject(cJSON *object, const char *string)
{
    cJSON *to_detach = cJSON_GetObjectItem(object, string);

    return cJSON_DetachItemViaPointer(object, to_detach);
}

CJSON_PUBLIC(cJSON *) cJSON_DetachItemFromObjectCaseSensitive(cJSON *object, const char *string)
{
    cJSON *to_detach = cJSON_GetObjectItemCaseSensitive(object, string);

    return cJSON_DetachItemViaPointer(object, to_detach);
}

CJSON_PUBLIC(void) cJSON_DeleteItemFromObject(cJSON *object, const char *string)
{
    cJSON_Delete(cJSON_DetachItemFromObject(object, string));
}

CJSON_PUBLIC(void) cJSON_DeleteItemFromObjectCaseSensitive(cJSON *object, const char *string)
{
    cJSON_Delete(cJSON_DetachItemFromObjectCaseSensitive(object, string));
}

/* Replace array/object items with new ones. */
CJSON_PUBLIC(cJSON_bool) cJSON_InsertItemInArray(cJSON *array, int which, cJSON *newitem)
{
    cJSON *after_inserted = NULL;

    if (which < 0 || newitem == NULL)
    {
        return false;
    }

    after_inserted = get_array_item(array, (size_t)which);
    if (after_inserted == NULL)
    {
        return add_item_to_array(array, newitem);
    }

    if (after_inserted != array->child && after_inserted->prev == NULL) {
        /* return false if after_inserted is a corrupted array item */
        return false;
    }

    newitem->next = after_inserted;
    newitem->prev = after_inserted->prev;
    after_inserted->prev = newitem;
    if (after_inserted == array->child)
    {
        array->child = newitem;
    }
    else
    {
        newitem->prev->next = newitem;
    }
    return true;
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemViaPointer(cJSON * const parent, cJSON * const item, cJSON * replacement)
{
    if ((parent == NULL) || (parent->child == NULL) || (replacement == NULL) || (item == NULL))
    {
        return false;
    }

    if (replacement == item)
    {
        return true;
    }

    replacement->next = item->next;
    replacement->prev = item->prev;

    if (replacement->next != NULL)
    {
        replacement->next->prev = replacement;
    }
    if (parent->child == item)
    {
        if (parent->child->prev == parent->child)
        {
            replacement->prev = replacement;
        }
        parent->child = replacement;
    }
    else
    {   /*
         * To find the last item in array quickly, we use prev in array.
         * We can't modify the last item's next pointer where this item was the parent's child
         */
        if (replacement->prev != NULL)
        {
            replacement->prev->next = replacement;
        }
        if (replacement->next == NULL)
        {
            parent->child->prev = replacement;
        }
    }

    item->next = NULL;
    item->prev = NULL;
    cJSON_Delete(item);

    return true;
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInArray(cJSON *array, int which, cJSON *newitem)
{
    if (which < 0)
    {
        return false;
    }

    return cJSON_ReplaceItemViaPointer(array, get_array_item(array, (size_t)which), newitem);
}

static cJSON_bool replace_item_in_object(cJSON *object, const char *string, cJSON *replacement, cJSON_bool case_sensitive)
{
    if ((replacement == NULL) || (string == NULL))
    {
        return false;
    }

    /* replace the name in the replacement */
    if (!(replacement->type & cJSON_StringIsConst) && (replacement->string != NULL))
    {
        cJSON_free(replacement->string);
    }
    replacement->string = (char*)cJSON_strdup((const unsigned char*)string, &global_hooks);
    if (replacement->string == NULL)
    {
        return false;
    }

    replacement->type &= ~cJSON_StringIsConst;

    return cJSON_ReplaceItemViaPointer(object, get_object_item(object, string, case_sensitive), replacement);
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObject(cJSON *object, const char *string, cJSON *newitem)
{
    return replace_item_in_object(object, string, newitem, false);
}

CJSON_PUBLIC(cJSON_bool) cJSON_ReplaceItemInObjectCaseSensitive(cJSON *object, const char *string, cJSON *newitem)
{
    return replace_item_in_object(object, string, newitem, true);
}

/* Create basic types: */
CJSON_PUBLIC(cJSON *) cJSON_CreateNull(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_NULL;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateTrue(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_True;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateFalse(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_False;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateBool(cJSON_bool boolean)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = boolean ? cJSON_True : cJSON_False;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateNumber(double num)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_Number;
        item->valuedouble = num;

        /* use saturation in case of overflow */
        if (num >= INT_MAX)
        {
            item->valueint = INT_MAX;
        }
        else if (num <= (double)INT_MIN)
        {
            item->valueint = INT_MIN;
        }
        else
        {
            item->valueint = (int)num;
        }
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateString(const char *string)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_String;
        item->valuestring = (char*)cJSON_strdup((const unsigned char*)string, &global_hooks);
        if(!item->valuestring)
        {
            cJSON_Delete(item);
            return NULL;
        }
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateStringReference(const char *string)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item != NULL)
    {
        item->type = cJSON_String | cJSON_IsReference;
        item->valuestring = (char*)cast_away_const(string);
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateObjectReference(const cJSON *child)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item != NULL) {
        item->type = cJSON_Object | cJSON_IsReference;
        item->child = (cJSON*)cast_away_const(child);
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateArrayReference(const cJSON *child) {
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item != NULL) {
        item->type = cJSON_Array | cJSON_IsReference;
        item->child = (cJSON*)cast_away_const(child);
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateRaw(const char *raw)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type = cJSON_Raw;
        item->valuestring = (char*)cJSON_strdup((const unsigned char*)raw, &global_hooks);
        if(!item->valuestring)
        {
            cJSON_Delete(item);
            return NULL;
        }
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateArray(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if(item)
    {
        item->type=cJSON_Array;
    }

    return item;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateObject(void)
{
    cJSON *item = cJSON_New_Item(&global_hooks);
    if (item)
    {
        item->type = cJSON_Object;
    }

    return item;
}

/* Create Arrays: */
CJSON_PUBLIC(cJSON *) cJSON_CreateIntArray(const int *numbers, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (numbers == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for(i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateNumber(numbers[i]);
        if (!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p, n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateFloatArray(const float *numbers, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (numbers == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for(i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateNumber((double)numbers[i]);
        if(!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p, n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateDoubleArray(const double *numbers, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (numbers == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for(i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateNumber(numbers[i]);
        if(!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p, n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

CJSON_PUBLIC(cJSON *) cJSON_CreateStringArray(const char *const *strings, int count)
{
    size_t i = 0;
    cJSON *n = NULL;
    cJSON *p = NULL;
    cJSON *a = NULL;

    if ((count < 0) || (strings == NULL))
    {
        return NULL;
    }

    a = cJSON_CreateArray();

    for (i = 0; a && (i < (size_t)count); i++)
    {
        n = cJSON_CreateString(strings[i]);
        if(!n)
        {
            cJSON_Delete(a);
            return NULL;
        }
        if(!i)
        {
            a->child = n;
        }
        else
        {
            suffix_object(p,n);
        }
        p = n;
    }

    if (a && a->child) {
        a->child->prev = n;
    }

    return a;
}

/* Duplication */
CJSON_PUBLIC(cJSON *) cJSON_Duplicate(const cJSON *item, cJSON_bool recurse)
{
    cJSON *newitem = NULL;
    cJSON *child = NULL;
    cJSON *next = NULL;
    cJSON *newchild = NULL;

    /* Bail on bad ptr */
    if (!item)
    {
        goto fail;
    }
    /* Create new item */
    newitem = cJSON_New_Item(&global_hooks);
    if (!newitem)
    {
        goto fail;
    }
    /* Copy over all vars */
    newitem->type = item->type & (~cJSON_IsReference);
    newitem->valueint = item->valueint;
    newitem->valuedouble = item->valuedouble;
    if (item->valuestring)
    {
        newitem->valuestring = (char*)cJSON_strdup((unsigned char*)item->valuestring, &global_hooks);
        if (!newitem->valuestring)
        {
            goto fail;
        }
    }
    if (item->string)
    {
        newitem->string = (item->type&cJSON_StringIsConst) ? item->string : (char*)cJSON_strdup((unsigned char*)item->string, &global_hooks);
        if (!newitem->string)
        {
            goto fail;
        }
    }
    /* If non-recursive, then we're done! */
    if (!recurse)
    {
        return newitem;
    }
    /* Walk the ->next chain for the child. */
    child = item->child;
    while (child != NULL)
    {
        newchild = cJSON_Duplicate(child, true); /* Duplicate (with recurse) each item in the ->next chain */
        if (!newchild)
        {
            goto fail;
        }
        if (next != NULL)
        {
            /* If newitem->child already set, then crosswire ->prev and ->next and move on */
            next->next = newchild;
            newchild->prev = next;
            next = newchild;
        }
        else
        {
            /* Set newitem->child and move to it */
            newitem->child = newchild;
            next = newchild;
        }
        child = child->next;
    }
    if (newitem && newitem->child)
    {
        newitem->child->prev = newchild;
    }

    return newitem;

fail:
    if (newitem != NULL)
    {
        cJSON_Delete(newitem);
    }

    return NULL;
}

static void skip_oneline_comment(char **input)
{
    *input += static_strlen("//");

    for (; (*input)[0] != '\0'; ++(*input))
    {
        if ((*input)[0] == '\n') {
            *input += static_strlen("\n");
            return;
        }
    }
}

static void skip_multiline_comment(char **input)
{
    *input += static_strlen("/*");

    for (; (*input)[0] != '\0'; ++(*input))
    {
        if (((*input)[0] == '*') && ((*input)[1] == '/'))
        {
            *input += static_strlen("*/");
            return;
        }
    }
}

static void minify_string(char **input, char **output) {
    (*output)[0] = (*input)[0];
    *input += static_strlen("\"");
    *output += static_strlen("\"");


    for (; (*input)[0] != '\0'; (void)++(*input), ++(*output)) {
        (*output)[0] = (*input)[0];

        if ((*input)[0] == '\"') {
            (*output)[0] = '\"';
            *input += static_strlen("\"");
            *output += static_strlen("\"");
            return;
        } else if (((*input)[0] == '\\') && ((*input)[1] == '\"')) {
            (*output)[1] = (*input)[1];
            *input += static_strlen("\"");
            *output += static_strlen("\"");
        }
    }
}

CJSON_PUBLIC(void) cJSON_Minify(char *json)
{
    char *into = json;

    if (json == NULL)
    {
        return;
    }

    while (json[0] != '\0')
    {
        switch (json[0])
        {
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                json++;
                break;

            case '/':
                if (json[1] == '/')
                {
                    skip_oneline_comment(&json);
                }
                else if (json[1] == '*')
                {
                    skip_multiline_comment(&json);
                } else {
                    json++;
                }
                break;

            case '\"':
                minify_string(&json, (char**)&into);
                break;

            default:
                into[0] = json[0];
                json++;
                into++;
        }
    }

    /* and null-terminate. */
    *into = '\0';
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsInvalid(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Invalid;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsFalse(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_False;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsTrue(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xff) == cJSON_True;
}


CJSON_PUBLIC(cJSON_bool) cJSON_IsBool(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & (cJSON_True | cJSON_False)) != 0;
}
CJSON_PUBLIC(cJSON_bool) cJSON_IsNull(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_NULL;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsNumber(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Number;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsString(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_String;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsArray(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Array;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsObject(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Object;
}

CJSON_PUBLIC(cJSON_bool) cJSON_IsRaw(const cJSON * const item)
{
    if (item == NULL)
    {
        return false;
    }

    return (item->type & 0xFF) == cJSON_Raw;
}

CJSON_PUBLIC(cJSON_bool) cJSON_Compare(const cJSON * const a, const cJSON * const b, const cJSON_bool case_sensitive)
{
    if ((a == NULL) || (b == NULL) || ((a->type & 0xFF) != (b->type & 0xFF)))
    {
        return false;
    }

    /* check if type is valid */
    switch (a->type & 0xFF)
    {
        case cJSON_False:
        case cJSON_True:
        case cJSON_NULL:
        case cJSON_Number:
        case cJSON_String:
        case cJSON_Raw:
        case cJSON_Array:
        case cJSON_Object:
            break;

        default:
            return false;
    }

    /* identical objects are equal */
    if (a == b)
    {
        return true;
    }

    switch (a->type & 0xFF)
    {
        /* in these cases and equal type is enough */
        case cJSON_False:
        case cJSON_True:
        case cJSON_NULL:
            return true;

        case cJSON_Number:
            if (compare_double(a->valuedouble, b->valuedouble))
            {
                return true;
            }
            return false;

        case cJSON_String:
        case cJSON_Raw:
            if ((a->valuestring == NULL) || (b->valuestring == NULL))
            {
                return false;
            }
            if (strcmp(a->valuestring, b->valuestring) == 0)
            {
                return true;
            }

            return false;

        case cJSON_Array:
        {
            cJSON *a_element = a->child;
            cJSON *b_element = b->child;

            for (; (a_element != NULL) && (b_element != NULL);)
            {
                if (!cJSON_Compare(a_element, b_element, case_sensitive))
                {
                    return false;
                }

                a_element = a_element->next;
                b_element = b_element->next;
            }

            /* one of the arrays is longer than the other */
            if (a_element != b_element) {
                return false;
            }

            return true;
        }

        case cJSON_Object:
        {
            cJSON *a_element = NULL;
            cJSON *b_element = NULL;
            cJSON_ArrayForEach(a_element, a)
            {
                /* TODO This has O(n^2) runtime, which is horrible! */
                b_element = get_object_item(b, a_element->string, case_sensitive);
                if (b_element == NULL)
                {
                    return false;
                }

                if (!cJSON_Compare(a_element, b_element, case_sensitive))
                {
                    return false;
                }
            }

            /* doing this twice, once on a and b to prevent true comparison if a subset of b
             * TODO: Do this the proper way, this is just a fix for now */
            cJSON_ArrayForEach(b_element, b)
            {
                a_element = get_object_item(a, b_element->string, case_sensitive);
                if (a_element == NULL)
                {
                    return false;
                }

                if (!cJSON_Compare(b_element, a_element, case_sensitive))
                {
                    return false;
                }
            }

            return true;
        }

        default:
            return false;
    }
}

CJSON_PUBLIC(void *) cJSON_malloc(size_t size)
{
    return global_hooks.allocate(size);
}

CJSON_PUBLIC(void) cJSON_free(void *object)
{
    global_hooks.deallocate(object);
    object = NULL;
}

        #undef true
        #define true 1
        #undef false
        #define false 0
    #endif
#endif

#ifndef DTW_NOT_IMPLEMENT_SHA256
    #ifdef PRIVATE_DTW_SHA_DEFINED_IN_DO_THE_WORLD
        


#define TOTAL_LEN_LEN 8

/*
 * Comments from pseudo-code at https://en.wikipedia.org/wiki/SHA-2 are reproduced here.
 * When useful for clarification, portions of the pseudo-code are reproduced here too.
 */

/*
 * @brief Rotate a 32-bit value by a number of bits to the right.
 * @param value The value to be rotated.
 * @param count The number of bits to rotate by.
 * @return The rotated value.
 */
static inline uint32_t right_rot(uint32_t value, unsigned int count)
{
	/*
	 * Defined behaviour in standard C for all count where 0 < count < 32, which is what we need here.
	 */
	return value >> count | value << (32 - count);
}

/*
 * @brief Update a hash value under calculation with a new chunk of data.
 * @param h Pointer to the first hash item, of a total of eight.
 * @param p Pointer to the chunk data, which has a standard length.
 *
 * @note This is the SHA-256 work horse.
 */
static inline void consume_chunk(uint32_t *h, const uint8_t *p)
{
	unsigned i, j;
	uint32_t ah[8];

	/* Initialize working variables to current hash value: */
	for (i = 0; i < 8; i++)
		ah[i] = h[i];

	/*
	 * The w-array is really w[64], but since we only need 16 of them at a time, we save stack by
	 * calculating 16 at a time.
	 *
	 * This optimization was not there initially and the rest of the comments about w[64] are kept in their
	 * initial state.
	 */

	/*
	 * create a 64-entry message schedule array w[0..63] of 32-bit words (The initial values in w[0..63]
	 * don't matter, so many implementations zero them here) copy chunk into first 16 words w[0..15] of the
	 * message schedule array
	 */
	uint32_t w[16];

	/* Compression function main loop: */
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 16; j++) {
			if (i == 0) {
				w[j] =
				    (uint32_t)p[0] << 24 | (uint32_t)p[1] << 16 | (uint32_t)p[2] << 8 | (uint32_t)p[3];
				p += 4;
			} else {
				/* Extend the first 16 words into the remaining 48 words w[16..63] of the
				 * message schedule array: */
				const uint32_t s0 = right_rot(w[(j + 1) & 0xf], 7) ^ right_rot(w[(j + 1) & 0xf], 18) ^
						    (w[(j + 1) & 0xf] >> 3);
				const uint32_t s1 = right_rot(w[(j + 14) & 0xf], 17) ^
						    right_rot(w[(j + 14) & 0xf], 19) ^ (w[(j + 14) & 0xf] >> 10);
				w[j] = w[j] + s0 + w[(j + 9) & 0xf] + s1;
			}
			const uint32_t s1 = right_rot(ah[4], 6) ^ right_rot(ah[4], 11) ^ right_rot(ah[4], 25);
			const uint32_t ch = (ah[4] & ah[5]) ^ (~ah[4] & ah[6]);

			/*
			 * Initialize array of round constants:
			 * (first 32 bits of the fractional parts of the cube roots of the first 64 primes 2..311):
			 */
			static const uint32_t k[] = {
			    0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4,
			    0xab1c5ed5, 0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe,
			    0x9bdc06a7, 0xc19bf174, 0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f,
			    0x4a7484aa, 0x5cb0a9dc, 0x76f988da, 0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7,
			    0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967, 0x27b70a85, 0x2e1b2138, 0x4d2c6dfc,
			    0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85, 0xa2bfe8a1, 0xa81a664b,
			    0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070, 0x19a4c116,
			    0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
			    0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7,
			    0xc67178f2};

			const uint32_t temp1 = ah[7] + s1 + ch + k[i << 4 | j] + w[j];
			const uint32_t s0 = right_rot(ah[0], 2) ^ right_rot(ah[0], 13) ^ right_rot(ah[0], 22);
			const uint32_t maj = (ah[0] & ah[1]) ^ (ah[0] & ah[2]) ^ (ah[1] & ah[2]);
			const uint32_t temp2 = s0 + maj;

			ah[7] = ah[6];
			ah[6] = ah[5];
			ah[5] = ah[4];
			ah[4] = ah[3] + temp1;
			ah[3] = ah[2];
			ah[2] = ah[1];
			ah[1] = ah[0];
			ah[0] = temp1 + temp2;
		}
	}

	/* Add the compressed chunk to the current hash value: */
	for (i = 0; i < 8; i++)
		h[i] += ah[i];
}

/*
 * Public functions. See header file for documentation.
 */

void sha_256_init(struct Sha_256 *sha_256, uint8_t hash[SIZE_OF_SHA_256_HASH])
{
	sha_256->hash = hash;
	sha_256->chunk_pos = sha_256->chunk;
	sha_256->space_left = SIZE_OF_SHA_256_CHUNK;
	sha_256->total_len = 0;
	/*
	 * Initialize hash values (first 32 bits of the fractional parts of the square roots of the first 8 primes
	 * 2..19):
	 */
	sha_256->h[0] = 0x6a09e667;
	sha_256->h[1] = 0xbb67ae85;
	sha_256->h[2] = 0x3c6ef372;
	sha_256->h[3] = 0xa54ff53a;
	sha_256->h[4] = 0x510e527f;
	sha_256->h[5] = 0x9b05688c;
	sha_256->h[6] = 0x1f83d9ab;
	sha_256->h[7] = 0x5be0cd19;
}

void sha_256_write(struct Sha_256 *sha_256, const void *data, size_t len)
{
	sha_256->total_len += len;

	/*
	 * The following cast is not necessary, and could even be considered as poor practice. However, it makes this
	 * file valid C++, which could be a good thing for some use cases.
	 */
	const uint8_t *p = (const uint8_t *)data;

	while (len > 0) {
		/*
		 * If the input chunks have sizes that are multiples of the calculation chunk size, no copies are
		 * necessary. We operate directly on the input data instead.
		 */
		if (sha_256->space_left == SIZE_OF_SHA_256_CHUNK && len >= SIZE_OF_SHA_256_CHUNK) {
			consume_chunk(sha_256->h, p);
			len -= SIZE_OF_SHA_256_CHUNK;
			p += SIZE_OF_SHA_256_CHUNK;
			continue;
		}
		/* General case, no particular optimization. */
		const size_t consumed_len = len < sha_256->space_left ? len : sha_256->space_left;
		memcpy(sha_256->chunk_pos, p, consumed_len);
		sha_256->space_left -= consumed_len;
		len -= consumed_len;
		p += consumed_len;
		if (sha_256->space_left == 0) {
			consume_chunk(sha_256->h, sha_256->chunk);
			sha_256->chunk_pos = sha_256->chunk;
			sha_256->space_left = SIZE_OF_SHA_256_CHUNK;
		} else {
			sha_256->chunk_pos += consumed_len;
		}
	}
}

uint8_t *sha_256_close(struct Sha_256 *sha_256)
{
	uint8_t *pos = sha_256->chunk_pos;
	size_t space_left = sha_256->space_left;
	uint32_t *const h = sha_256->h;

	/*
	 * The current chunk cannot be full. Otherwise, it would already have been consumed. I.e. there is space left
	 * for at least one byte. The next step in the calculation is to add a single one-bit to the data.
	 */
	*pos++ = 0x80;
	--space_left;

	/*
	 * Now, the last step is to add the total data length at the end of the last chunk, and zero padding before
	 * that. But we do not necessarily have enough space left. If not, we pad the current chunk with zeroes, and add
	 * an extra chunk at the end.
	 */
	if (space_left < TOTAL_LEN_LEN) {
		memset(pos, 0x00, space_left);
		consume_chunk(h, sha_256->chunk);
		pos = sha_256->chunk;
		space_left = SIZE_OF_SHA_256_CHUNK;
	}
	const size_t left = space_left - TOTAL_LEN_LEN;
	memset(pos, 0x00, left);
	pos += left;
	uint64_t len = sha_256->total_len;
	pos[7] = (uint8_t)(len << 3);
	len >>= 5;
	int i;
	for (i = 6; i >= 0; --i) {
		pos[i] = (uint8_t)len;
		len >>= 8;
	}
	consume_chunk(h, sha_256->chunk);
	/* Produce the final hash value (big-endian): */
	int j;
	uint8_t *const hash = sha_256->hash;
	for (i = 0, j = 0; i < 8; i++) {
		hash[j++] = (uint8_t)(h[i] >> 24);
		hash[j++] = (uint8_t)(h[i] >> 16);
		hash[j++] = (uint8_t)(h[i] >> 8);
		hash[j++] = (uint8_t)h[i];
	}
	return sha_256->hash;
}

void calc_sha_256(uint8_t hash[SIZE_OF_SHA_256_HASH], const void *input, size_t len)
{
	struct Sha_256 sha_256;
	sha_256_init(&sha_256, hash);
	sha_256_write(&sha_256, input, len);
	(void)sha_256_close(&sha_256);
}

    #endif
#endif



#endif //DO_THE_WORLD_H



#ifndef UNIVERSAL_GARBAGE_H
#ifndef UNIVERSAL_GARBAGE_H
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define UniversalGarbage_create_empty_struct(name,element_type) \
(element_type*)malloc(sizeof(element_type));    \
*name = (element_type){0};


#define UniversalGarbage_cast(value) ((void**)&value)


#define UniversalGarbage_add(garbage,deallocator_callback,value) \
    rawUniversalGarbage_add(garbage,(void(*)(void*))deallocator_callback,UniversalGarbage_cast(value))

#define UniversalGarbage_add_simple(garbage,value) \
     UniversalGarbage_add(garbage,free,value)


#define UniversalGarbage_add_return(garbage,deallocator_callback,value) \
        UniversalGarbage_add(garbage->return_values,deallocator_callback,value)


#define UniversalGarbage_add_simple_return(garbage,value) \
    UniversalGarbage_add_simple(garbage->return_values,value)



#define  UniversalGarbage_remove(garbage,value) \
    rawUniversalGarbage_remove(garbage,UniversalGarbage_cast(value));


#define  UniversalGarbage_disconnect(garbage,value) \
    rawUniversalGarbage_disconnect(garbage,UniversalGarbage_cast(value));




#define UniversalGarbage_reallocate(garbage,value) \
    rawUniversalGarbage_reallocate(garbage,UniversalGarbage_cast(value))


#define UniversalGarbage_resset(garbage,value) \
    rawUniversalGarbage_resset(garbage,UniversalGarbage_cast(value))



#ifndef PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
#define PRIVATE_UNIVERSGAL_GARBAGE_ELEMENT_TYPE
typedef struct privateUniversalGarbageElement{
    void **pointer;
    void (*deallocator_callback)(void *element);
    void *pointed_value;
}privateUniversalGarbageElement;
#endif



#ifndef  PRIVATE_UNIVERSAL_GARBAGE_TYPE
#define PRIVATE_UNIVERSAL_GARBAGE_TYPE


typedef  struct UniversalGarbage{

    struct UniversalGarbage *return_values;
    privateUniversalGarbageElement **elements;
    int  elements_size;
    bool is_the_root;

}UniversalGarbage;
#endif














void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self);


void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self);

privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer);







UniversalGarbage * newUniversalGarbage();

UniversalGarbage * private_new_MainUniversalGarbage();



bool  rawUniversalGarbage_resset(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_remove(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_disconnect(UniversalGarbage *self, void **pointer);

bool rawUniversalGarbage_reallocate(UniversalGarbage *self, void **pointer);

bool  rawUniversalGarbage_add(UniversalGarbage *self,  void (*dealocator_callback)(void *element), void **pointer);

void private_UniversalGarbage_free_all_sub_elements(UniversalGarbage *self);

void UniversalGarbage_free_including_return(UniversalGarbage *self);

void UniversalGarbage_free(UniversalGarbage *self);





#ifdef __cplusplus
}
#endif

#define UNIVERSAL_GARBAGE_H
#endif










privateUniversalGarbageElement * private_newUniversalGarbageSimpleElement(void (*dealocator_callback)(void *element), void **pointer){

    privateUniversalGarbageElement * self = UniversalGarbage_create_empty_struct(
        self,
        privateUniversalGarbageElement
    );
    self->pointer = pointer;
    self->deallocator_callback = dealocator_callback;
    self->pointed_value = *pointer;
    return  self;
}
void private_UniversalGarbageSimpleElement_free_pointed_value(privateUniversalGarbageElement *self){
    if(self->pointed_value){
        self->deallocator_callback(self->pointed_value);
        self->pointed_value = NULL;
    }
}

void private_UniversalGarbageSimpleElement_free(privateUniversalGarbageElement *self){
    private_UniversalGarbageSimpleElement_free_pointed_value(self);
    free(self);
}






UniversalGarbage * private_new_MainUniversalGarbage(){
    UniversalGarbage *self = UniversalGarbage_create_empty_struct(self,UniversalGarbage)
    self->elements = (privateUniversalGarbageElement**)malloc(0);
    self->is_the_root = false;
    return self;
}

UniversalGarbage * newUniversalGarbage(){
    UniversalGarbage *self = UniversalGarbage_create_empty_struct(self,UniversalGarbage)
    self->is_the_root = true;
    self->elements = (privateUniversalGarbageElement**)malloc(0);
    self->return_values =private_new_MainUniversalGarbage();

    return self;
}




bool  rawUniversalGarbage_reallocate(UniversalGarbage *self, void **pointer){

    if(self->is_the_root){

        if(rawUniversalGarbage_reallocate(self->return_values,pointer)){
            return true;
        }
    }


    for(int i = 0; i < self->elements_size; i++){

        privateUniversalGarbageElement *current = self->elements[i];
        bool reallocate = current->pointer == pointer;

        if(reallocate){
            current->pointed_value = *pointer;
            return true;
        }
    }
    return false;
}

bool rawUniversalGarbage_resset(UniversalGarbage *self, void **pointer){

    if(self->is_the_root){
        if(rawUniversalGarbage_resset(self->return_values,pointer)){
            return true;
        }
    }


    for(int i = 0; i < self->elements_size; i++){
        privateUniversalGarbageElement *current = self->elements[i];
        bool resset = current->pointer == pointer;
        if(resset){
            private_UniversalGarbageSimpleElement_free_pointed_value(current);
            current->pointed_value = *pointer;
            return true;
        }
    }
    return  false;

}
bool  rawUniversalGarbage_remove(UniversalGarbage *self, void **pointer){
    if(self->is_the_root){
        if(rawUniversalGarbage_remove(self->return_values,pointer)){
            *pointer = NULL;
            return true;
        }
    }

    for(int i = 0; i < self->elements_size; i++){
        privateUniversalGarbageElement *current = self->elements[i];
        if(current->pointer == pointer){
            private_UniversalGarbageSimpleElement_free(current);
            self->elements_size-=1;
            bool its_not_the_last = i < self->elements_size;
            if(its_not_the_last){
                self->elements[i] = self->elements[self->elements_size];

            }
            *pointer = NULL;
            return  true;
        }
    }
    return  false;
}
bool  rawUniversalGarbage_disconnect(UniversalGarbage *self, void **pointer){
    if(self->is_the_root){
        if(rawUniversalGarbage_disconnect(self->return_values,pointer)){
            return true;
        }
    }

    for(int i = 0; i < self->elements_size; i++){
        privateUniversalGarbageElement *current = self->elements[i];
        if(current->pointer == pointer){
            free(current);
            self->elements_size-=1;
            bool its_not_the_last = i < self->elements_size;
            if(its_not_the_last){
                privateUniversalGarbageElement *last_element =  self->elements[self->elements_size];
                self->elements[i] = last_element;
            }
            return true;
        }
    }
    return  false;



}
bool  rawUniversalGarbage_add(UniversalGarbage *self,  void (*dealocator_callback)(void *element), void **pointer){

    if(!pointer){
        return false;
    }

    if(*pointer){
        for(int i = 0; i < self->elements_size; i++){
            privateUniversalGarbageElement *current = self->elements[i];
            if(current->pointed_value == *pointer){
                return false;
            }
        }
    }


    self->elements = (privateUniversalGarbageElement**)realloc(
            self->elements,
            (self->elements_size + 1) * sizeof(privateUniversalGarbageElement*)
    );



    self->elements[self->elements_size] = private_newUniversalGarbageSimpleElement(dealocator_callback, pointer);
    self->elements_size+=1;
    return  true;
}



void  private_UniversalGarbage_free_all_sub_elements(UniversalGarbage *self){
    for(int i = 0; i < self->elements_size; i++){
        private_UniversalGarbageSimpleElement_free(self->elements[i]);
    }
    free(self->elements);
}

void UniversalGarbage_free_including_return(UniversalGarbage *self){
    private_UniversalGarbage_free_all_sub_elements(self);
    if(self->is_the_root){
        UniversalGarbage_free(self->return_values);
    }
    free(self);
}

void UniversalGarbage_free(UniversalGarbage *self){
    private_UniversalGarbage_free_all_sub_elements(self);

    if(self->is_the_root){

        UniversalGarbage *return_garbage = self->return_values;
        for(int i = 0; i < return_garbage->elements_size; i++){
            free(return_garbage->elements[i]);
        }

        free(return_garbage->elements);
        free(return_garbage);
    }


    free(self);
}






#define UNIVERSAL_GARBAGE_H
#endif


#endif

#ifndef camalgamator_api_const
#define camalgamator_api_const

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end
#define  PRIVATE_CAMALGAMATOR_NO_ERRORS 0
#define  CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED -1

#define  CAMALGAMATOR_UNEXPECTED_ERROR -2
#define CAMALGAMATOR_MAX_CONTENT_SIZE -3
#define CAMALGAMATOR_MAX_RECURSION_CALL -4


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#define CAMALGAMATOR_DONT_INCLUDE 1
#define CAMALGAMATOR_DONT_CHANGE 2
#define CAMALGAMATOR_INCLUDE_ONCE 3
#define CAMALGAMATOR_INCLUDE_PERPETUAL 4


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#define CAMALGAMATOR_ONE_KBYTE 1024
#define CAMALGAMATOR_ONE_MB CAMALGAMATOR_ONE_KBYTE * 1000


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


enum{
    PRIVATE_CAMALGAMATOR_NORMAL_STATE,
    PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START,
    PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME,
    PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT,
    PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT,
    PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING,
    PRIVATE_CAMALGAMATOR_INSIDE_CHAR
};

#endif

#ifndef camalgamator_api_type
#define camalgamator_api_type

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


struct CAmalgamatorErrorOrContent{
    char *content;
    int error;
    char *error_msg;
    char *include_name;
    char *filename;
};
typedef  struct CAmalgamatorErrorOrContent CAmalgamatorErrorOrContent;

#endif

#ifndef camalgamator_api_type1
#define camalgamator_api_type1

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

struct CAmalgamatorNamesapce{

    CAmalgamatorErrorOrContent * (*generate_amalgamation)(
        const char*filename,
        long max_content_size,
        int max_recursion,
        short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
        void *args
    );
    CAmalgamatorErrorOrContent * (*generate_amalgamation_simple)(const char*filename, long maxcontent_size, int max_recursion);

    short DONT_INCLUDE;
    short DONT_CHANGE;
    short INCLUDE_ONCE;
    short INCLUDE_PERPETUAL;
    short FILE_NOT_FOUND;
    short UNEXPECTED_ERROR;
    short NO_ERRORS;
    int ONE_KBYTE;
    int  ONE_MB;

    void (*free_error_or_string)(CAmalgamatorErrorOrContent *self);

};
typedef   struct  CAmalgamatorNamesapce CAmalgamatorNamesapce;

#endif

#ifndef camalgamator_api_declare
#define camalgamator_api_declare

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_error(int error_code,char *include_name,char *filename, const char *error_msg,...);


CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_ok(char *content);

void CAmalgamatorErrorOrString_free(CAmalgamatorErrorOrContent *self);


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end
CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation(
    const char*filename,
    long max_content_size,
    int max_recursion,
    short (*generator_handler)(const char *filename,const  char *path, void *extra_args),
    void *args
);

CAmalgamatorErrorOrContent * CAmalgamator_generate_amalgamation_simple(const char*filename,long max_content_size,    int max_recursion);


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

CAmalgamatorNamesapce newCAmalgamatorNamesapce();


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

bool private_CAmalgamator_is_include_at_point(char *content,int content_size,int point);

bool private_CAmalgamator_is_start_multiline_coment_at_point(char *content,int content_size,int point);

bool private_CAmalgamator_is_end_multiline_coment_at_point(char *content,int content_size,int point);

bool private_CAmalgamator_is_start_inline_coment_at_point(char *content,int content_size,int point);


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end


int  private_CAmalgamator_generate_amalgamation(
    const char *prev_file,
    const char *include_code,
    CTextStack * final,
    DtwStringArray *already_included,
    char **include_code_error,
    char **filename_errr,
    long max_content_size,
    int recursion_call,
    int max_recursion,
    short (*generator_handler)(const char *filename,const  char *import_name, void *extra_args),
    void *args
);

#endif

#ifndef camalgamator_api_define
#define camalgamator_api_define

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_error(int error_code,char *include_name,char *filename, const char *error_msg,...){
    CAmalgamatorErrorOrContent *self = (CAmalgamatorErrorOrContent*)malloc(sizeof(CAmalgamatorErrorOrContent));
    *self = (CAmalgamatorErrorOrContent){0};
    self->error = error_code;
    va_list args;
    va_start(args, error_msg);
    self->error_msg = private_dtw_format_vaarg(error_msg,args);
    va_end(args);
    self->include_name = include_name;
    self->filename = filename;
    return  self;
}

CAmalgamatorErrorOrContent * Private_new_CAmalgamatorErrorOrString_as_ok(char *content){
    CAmalgamatorErrorOrContent *self = (CAmalgamatorErrorOrContent*)malloc(sizeof(CAmalgamatorErrorOrContent));
    *self = (CAmalgamatorErrorOrContent){0};
    self->error = PRIVATE_CAMALGAMATOR_NO_ERRORS;
    self->content = content; //we take the ownership
    return  self;
}

void CAmalgamatorErrorOrString_free(CAmalgamatorErrorOrContent *self){
    if(self->include_name){
        free(self->include_name);
    }
    if(self->content){
        free(self->content);
    }
    if(self->error_msg){
        free(self->error_msg);
    }
    if(self->filename){
        free(self->filename);
    }

    free(self);
}


//silver_chain_scope_start
//mannaged by silver chain

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


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

CAmalgamatorNamesapce newCAmalgamatorNamesapce(){
    CAmalgamatorNamesapce self = {0};
    self.generate_amalgamation = CAmalgamator_generate_amalgamation;
    self.generate_amalgamation_simple = CAmalgamator_generate_amalgamation_simple;
    self.free_error_or_string = CAmalgamatorErrorOrString_free;
    self.DONT_CHANGE = CAMALGAMATOR_DONT_CHANGE;
    self.DONT_INCLUDE = CAMALGAMATOR_DONT_INCLUDE;
    self.INCLUDE_ONCE = CAMALGAMATOR_INCLUDE_ONCE;
    self.INCLUDE_PERPETUAL= CAMALGAMATOR_INCLUDE_PERPETUAL;
    self.FILE_NOT_FOUND = PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
    self.UNEXPECTED_ERROR = CAMALGAMATOR_UNEXPECTED_ERROR;
    self.NO_ERRORS = PRIVATE_CAMALGAMATOR_NO_ERRORS;
    self.ONE_KBYTE =CAMALGAMATOR_ONE_KBYTE;
    self.ONE_MB = CAMALGAMATOR_ONE_MB;

    return self;
}


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#define PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,char)\
    if(content[point] != char){\
    return false;\
}
#define PRIVATE_CAMALGAMATOR_STR_SIZE(str) (sizeof(str)-1)

bool private_CAmalgamator_is_include_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("#include") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'#')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'i')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+2,'n')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+3,'c')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+4,'l')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+5,'u')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+6,'d')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+7,'e')
    return true;
}

bool private_CAmalgamator_is_start_multiline_coment_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("/*") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'/')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'*')
    return true;
}

bool private_CAmalgamator_is_end_multiline_coment_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("*/") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'*')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'/')
    return true;
}


bool private_CAmalgamator_is_start_inline_coment_at_point(char *content,int content_size,int point){
    if(point + PRIVATE_CAMALGAMATOR_STR_SIZE("//") >= content_size){
        return false;
    }
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point,'/')
    PRIVATE_C_AMALGAMATOR_CHECK_CHAR(point+1,'/')
    return true;
}


//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

#define COLLECT_ERROR_ATTIBUTES \
if(include_code == NULL){\
    *filename_errr = strdup(prev_file);\
}\
if(include_code){\
    *include_code_error = strdup(include_code);\
    *filename_errr = dtw_get_absolute_path(prev_file);\
}


int  private_CAmalgamator_generate_amalgamation(
    const char *prev_file,
    const char *include_code,
    CTextStack * final,
    DtwStringArray *already_included,
    char **include_code_error,
    char **filename_errr,
    long max_content_size,
    int recursion_call,
    int max_recursion,
    short (*generator_handler)(const char *filename,const  char *import_name, void *extra_args),
    void *args
){
    if(recursion_call >= max_recursion){
      COLLECT_ERROR_ATTIBUTES
        return CAMALGAMATOR_MAX_RECURSION_CALL;
    }

    if(final->size >= max_content_size ){
        COLLECT_ERROR_ATTIBUTES
        return CAMALGAMATOR_MAX_CONTENT_SIZE;
    }

    short behavior = CAMALGAMATOR_INCLUDE_ONCE;
    char *filename = (char*)prev_file;
    UniversalGarbage *garbage = newUniversalGarbage();

    DtwPath *current_path = newDtwPath(prev_file);
    UniversalGarbage_add(garbage,DtwPath_free, current_path);
    char *dir = DtwPath_get_dir(current_path);

    if(include_code){
        filename = dtw_concat_path(dir,include_code);

        UniversalGarbage_add_simple(garbage,filename);
    }

    bool is_binary;
    long size;
    char *content = (char*)dtw_load_any_content(filename,&size,&is_binary);
    UniversalGarbage_add_simple(garbage, content);
    if(content == NULL || is_binary){


        COLLECT_ERROR_ATTIBUTES
        UniversalGarbage_free(garbage);
        return CAMALGAMATOR_FILE_NOT_FOUND_OR_ITS_NOT_CORRECTED_FORMATED;
    }

    if(generator_handler && include_code){
         behavior  = generator_handler(filename,include_code, args);
    }

    if(behavior < 0) {
        COLLECT_ERROR_ATTIBUTES
        UniversalGarbage_free(garbage);
        return behavior;
    }

    if(behavior == CAMALGAMATOR_DONT_INCLUDE){
        return PRIVATE_CAMALGAMATOR_NO_ERRORS;
    }
    if(behavior == CAMALGAMATOR_DONT_CHANGE){
        CTextStack_format(final,"$include \"%s\"\n", include_code);
        return PRIVATE_CAMALGAMATOR_NO_ERRORS;
    }


    if(behavior == CAMALGAMATOR_INCLUDE_ONCE){
        char *absolute = dtw_get_absolute_path(filename);
        UniversalGarbage_add_simple(garbage, absolute);
        bool is_already_included =DtwStringArray_find_position(already_included,absolute) != -1;
        if(is_already_included){
               UniversalGarbage_free(garbage);
                return PRIVATE_CAMALGAMATOR_NO_ERRORS;
        }
        DtwStringArray_append(already_included, absolute);
    }

    CTextStack *new_include_code = newCTextStack_string_empty();
    UniversalGarbage_add(garbage,CTextStack_free,new_include_code);

    int state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
    for(int i =0; i < size;i++){

        char current_char = content[i];

        if(state == PRIVATE_CAMALGAMATOR_NORMAL_STATE){
            bool is_multiline_coment_start = private_CAmalgamator_is_start_multiline_coment_at_point(content,size,i);
            if(is_multiline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                continue;
            }
            bool is_inline_coment_start =  private_CAmalgamator_is_start_inline_coment_at_point(content,size,i);
            if(is_inline_coment_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT;
                CTextStack_format(final,"%c",current_char);
                continue;
            }
            bool is_str_start = current_char == '"';
            if(is_str_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING;
                CTextStack_format(final,"%c",current_char);
                continue;
            }
            bool is_char_start = current_char == '\'';
            if(is_char_start){
                state = PRIVATE_CAMALGAMATOR_INSIDE_CHAR;
                CTextStack_format(final,"%c",current_char);
                continue;
            }
            bool is_include = private_CAmalgamator_is_include_at_point(content,size,i);
            if(is_include){
                state =PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START;
                continue; // we dont format include here
            }
            CTextStack_format(final,"%c",current_char);
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_MULTILINE_COMENT ){
            bool is_multiline_coment_end = private_CAmalgamator_is_end_multiline_coment_at_point(content,size,i);
            if(is_multiline_coment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }
            CTextStack_format(final,"%c",current_char);
            continue;

        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_INLINE_COMENT){
            bool is_inline_comment_end = current_char == '\n';
            if(is_inline_comment_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }

            CTextStack_format(final,"%c",current_char);
            continue;

        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_NORMAL_STRING){
            char last_char = content[i-1];
            bool is_str_end = current_char == '"' && last_char != '\\';
            if(is_str_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }

            CTextStack_format(final,"%c",current_char);
            continue;

        }

        if(state == PRIVATE_CAMALGAMATOR_INSIDE_CHAR){
            char last_char = content[i-1];
            bool is_char_end = current_char == '\''&& last_char != '\'';
            if(is_char_end){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;

            }
            CTextStack_format(final,"%c",current_char);
            continue;

        }

        if(state == PRIVATE_CAMALGAMATOR_WATING_FILENAME_STRING_START){
            if (current_char == '"'){
                state = PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME;
            }

            if(current_char == '<'){
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
                //aborts inclusion
                CTextStack_text(final,"#include <");
            }
            continue;
        }

        if(state == PRIVATE_CAMALGAMATOR_COLLECTING_FILENAME){

            // means its the end of the #include "filename"
            // so whe have the hle filename stored in
            // new_include_code->rendered_text
            if(current_char == '"'){
                int error = private_CAmalgamator_generate_amalgamation(
                    filename,
                    new_include_code->rendered_text,
                    final,
                    already_included,
                    include_code_error,
                    filename_errr,
                    max_content_size,
                    recursion_call+1,
                    max_recursion,
                    generator_handler,
                    args
                );
                if(error){
                        UniversalGarbage_free(garbage);
                        return error;
                }
                CTextStack_restart(new_include_code);
                state = PRIVATE_CAMALGAMATOR_NORMAL_STATE;
            }

            else{
                CTextStack_format(new_include_code,"%c", current_char);
            }
        }
    }
    UniversalGarbage_free(garbage);
    return PRIVATE_CAMALGAMATOR_NO_ERRORS;
}

#endif

#ifndef camalgamator_cli_dependencies
#define camalgamator_cli_dependencies

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end



/*
MIT License

Copyright (c) 2023 OUI

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/
#ifndef CTEXTENGINE_H
#define CTEXTENGINE_H


#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>




#define CTEXT_BY_OWNESHIP 1
#define CTEXT_BY_COPY 2
#define CTEXT_BY_REFERENCE 3

//
// Created by jurandi on 18-04-2023.
//
#define CTEXT_HTML "html"
#define CTEXT_BODY "body"
#define CTEXT_DIV "div"
#define CTEXT_H1 "h1"
#define CTEXT_H2 "h2"
#define CTEXT_H3 "h3"
#define CTEXT_H4 "h4"
#define CTEXT_H5 "h5"
#define CTEXT_H6 "h6"
#define CTEXT_P "p"
#define CTEXT_SPAN "span"
#define CTEXT_A "a"
#define CTEXT_IMG "img"
#define CTEXT_INPUT "input"
#define CTEXT_BUTTON "button"
#define CTEXT_TABLE "table"
#define CTEXT_TR "tr"
#define CTEXT_TD "td"
#define TH "th"
#define CTEXT_THEAD "thead"
#define CTEXT_TBODY "tbody"
#define CTEXT_TFOOT "tfoot"
#define CTEXT_UL "ul"
#define CTEXT_LI "li"
#define CTEXT_OL "ol"
#define CTEXT_FORM "form"
#define CTEXT_LABEL "label"
#define CTEXT_SELECT "select"
#define CTEXT_OPTION "option"
#define CTEXT_TEXTAREA "textarea"
#define CTEXT_SCRIPT "script"
#define CTEXT_STYLE "style"
#define CTEXT_META "meta"
#define CTEXT_LINK "link"
#define CTEXT_HEAD "head"
#define CTEXT_BASE "base"
#define CTEXT_BR "br"
#define CTEXT_HR "hr"
#define CTEXT_TITLE "title"
#define CTEXT_IFRAME "iframe"
#define CTEXT_NAV "nav"
#define CTEXT_HEADER "header"
#define CTEXT_FOOTER "footer"
#define CTEXT_SECTION "section"
#define CTEXT_ARTICLE "article"
#define CTEXT_ASIDE "aside"
#define CTEXT_DETAILS "details"
#define CTEXT_SUMMARY "summary"
#define CTEXT_DIALOG "dialog"
#define MENU "menu"
#define MENUITEM "menuitem"
#define CTEXT_MAIN "main"
#define CTEXT_CANVAS "canvas"
#define CTEXT_AUDIO "audio"
#define CTEXT_VIDEO "video"
#define CTEXT_SOURCE "source"
#define CTEXT_TRACK "track"
#define CTEXT_EMBED "embed"
#define CTEXT_PARAM "param"








#define CTEXT_LINE_BREAKER "\n"
#define CTEXT_SEPARATOR "   "

#define CTEXT_LONG 1
#define CTEXT_DOUBLE 2
#define CTEXT_BOOL 3
#define CTEXT_STRING 4

typedef struct CTextStack{

    char *rendered_text;
    size_t rendered_text_alocation_size;
    size_t size;

    char *line_breaker;
    char *separator;
    int ident_level;

}CTextStack;

struct CTextStack *newCTextStack(const char *line_breaker, const char *separator);


struct CTextStack *newCTextStack_string(const char *starter);

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter);

struct CTextStack *newCTextStack_string_empty();


void CTextStack_text(struct CTextStack *self, const char *text);


void private_ctext_text_double_size_if_reachs(struct CTextStack *self);


void CTextStack_segment_text(struct CTextStack *self, const char *text);


void CTextStack_segment(struct CTextStack *self);


void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...);


void CTextStack_format(struct CTextStack *self, const char *format, ...);


void CTextStack_segment_format(struct CTextStack *self, const char *format, ...);


void ctext_open(struct CTextStack *self, const char *tag);


void ctext_close(struct CTextStack *self, const char *tag);

void CTextStack_represent(struct CTextStack *self);
void CTextStack_free(struct CTextStack *self);


struct CTextStack * CTextStack_clone(struct CTextStack *self);


char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self);

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_string);


void CTextStack_restart(struct CTextStack *self);


//algorithm methods

struct CTextStack *CTextStack_substr(struct CTextStack *self, long starter, long end);
void CTextStack_self_substr(struct CTextStack *self, long starter, long end);


struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end);
void  CTextStack_self_pop(struct CTextStack *self, long starter, long end);


struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace);
void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace);


struct CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace);
void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace);

struct CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace);
void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace);


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element);
void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element);


long CTextStack_index_of_char(struct  CTextStack *self, char element);
long CTextStack_index_of(struct  CTextStack *self, const char *element);

bool CTextStack_starts_with(struct  CTextStack *self, const char *element);
bool CTextStack_ends_with(struct  CTextStack *self, const char *element);

bool CTextStack_equal(struct  CTextStack *self,const char *element);

struct CTextStack *CTextStack_trim(struct CTextStack *self);
void CTextStack_self_trim(struct CTextStack *self);

struct CTextStack *CTextStack_lower(struct CTextStack *self);
void CTextStack_self_lower(struct CTextStack *self);

struct CTextStack *CTextStack_upper(struct CTextStack *self);
void CTextStack_self_upper(struct CTextStack *self);

int CTextStack_typeof(struct CTextStack *self);

bool CTextStack_is_a_num(struct CTextStack *self);


const char * CTextStack_typeof_in_str(struct CTextStack *self);
bool  CTextStack_parse_to_bool(struct CTextStack *self);
long  CTextStack_parse_to_integer(struct CTextStack *self);
double  CTextStack_parse_to_double(struct CTextStack *self);


struct CTextStack *CTextStack_reverse(struct CTextStack *self);
void CTextStack_self_reverse(struct CTextStack *self);






long private_CText_transform_index(long size, long value);


void private_ctext_generate_formated_text(
    struct CTextStack *stack,
    const char *format,
    va_list argptr
    );



typedef struct CTextArray{

    CTextStack **stacks;
    long size;


}CTextArray;

CTextArray * newCTextArray();


void CTextArray_append(CTextArray *self,CTextStack *element);


void CTextArray_append_string(CTextArray *self,const char *element);

CTextStack * CTextArray_join(CTextArray *self,const char *separator);

CTextArray * CTextArray_split(const char *element,const char *target);

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element));

CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element));

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element));

bool CTextArray_includes(CTextArray *self,const char *element);

void  CTextArray_free(CTextArray *self);

void CTextArray_represent(CTextArray *self);





typedef struct CTextStackModule{

    //admnistrative methods
    CTextStack  *(*newStack)(const char *line_breaker, const char *separator);
    CTextStack *(*newStack_string)(const char *starter);
    CTextStack *(*newStack_string_getting_ownership)(const char *starter);
    CTextStack *(*newStack_string_empty)();

    void (*free)(struct CTextStack *self);
    struct CTextStack *(*clone)(struct CTextStack *self);
    void (*represent)(struct CTextStack *self);
    char *(*self_transform_in_string_and_self_clear)(struct CTextStack *self);
    void (*restart)(struct CTextStack *self);

    //render methods
    void (*text)(struct CTextStack *self, const char *element);

    void (*segment_text)(struct CTextStack *self, const char *element);

    void (*format)(struct CTextStack *self, const char *format, ...);

    void (*segment)(struct CTextStack *self);

    void (*segment_format)(struct CTextStack *self, const char *format, ...);

    void (*$open)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*only$open)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*auto$close)(struct CTextStack *self, const char *tag, const char *format,...);

    void (*open)(struct CTextStack *self, const char *tag);

    void (*close)(struct CTextStack *self, const char *tag);


    //algorithm methods
    struct CTextStack * (*substr)(struct CTextStack *self, long starter, long end);
    void  (*self_substr)(struct CTextStack *self, long starter, long end);


    struct CTextStack *(*pop)(struct CTextStack *self, long starter, long end);
    void(*self_pop)(struct CTextStack *self, long starter, long end);



    struct CTextStack *(*insert_at)(struct CTextStack *self,long point, const char *element);
    void (*self_insert_at)(struct CTextStack *self,long point, const char *element);

    struct CTextStack *(*replace)(struct CTextStack *self,const char *element, const char *element_to_replace);
    void (*self_replace)(struct CTextStack *self,const char *element, const char *element_to_replace);


    struct CTextStack *(*replace_long)(struct CTextStack *self,const char *element, long element_to_replace);
    void(*self_replace_long)(struct CTextStack *self,const char *element, long element_to_replace);


    struct CTextStack *(*replace_double)(struct CTextStack *self,const char *element, double element_to_replace);
    void (*self_replace_double)(struct CTextStack *self,const char *element, double element_to_replace);


    struct CTextStack * (*lower)(struct CTextStack *self);
    void(*self_lower)(struct CTextStack *self);

    struct CTextStack * (*upper)(struct CTextStack *self);
    void(*self_upper)(struct CTextStack *self);


    struct CTextStack * (*reverse)(struct CTextStack *self);
    void(*self_reverse)(struct CTextStack *self);

    struct CTextStack * (*trim)(struct CTextStack *self);
    void(*self_trim)(struct CTextStack *self);

    bool (*starts_with)(struct CTextStack *self, const char *element);
    bool (*ends_with)(struct CTextStack *self, const char *element);

    bool (*equal)(struct  CTextStack *self,const char *element);
    int (*typeof_element)(struct CTextStack *self);
    bool (*is_a_num)(struct CTextStack *self);

    const char * (*typeof_in_str)(struct CTextStack *self);
    bool  (*parse_to_bool)(struct CTextStack *self);
    long  (*parse_to_integer)(struct CTextStack *self);
    double  (*parse_to_double)(struct CTextStack *self);

    long (*index_of)(struct CTextStack *self, const char *element);
    long (*index_of_char)(struct CTextStack *self, char element);
}CTextStackModule;

CTextStackModule newCTextStackModule();


typedef struct CTextArrayModule{
    CTextArray *(*newArray)();
    void (*append)(CTextArray *self,CTextStack *element);
    void (*append_string)(CTextArray *self,const char *element);
    CTextStack * (*join)(CTextArray *self,const char *separator);

    CTextArray * (*map)(CTextArray *self, CTextStack *(caller)(CTextStack* element));
    CTextArray * (*filter)(CTextArray *self, bool (caller)(CTextStack* element));
    void  (*foreach)(CTextArray *self, void (*caller)(CTextStack* element));
    bool (*includes)(CTextArray *self,const char *element);
    void (*represent)(CTextArray *self);
    void (*free)(CTextArray *self);

}CTextArrayModule;

CTextArrayModule newCTextArrayModule();



typedef struct CTextNamespace{

    CTextArrayModule array;
    CTextStackModule stack;

}CTextNamespace;

CTextNamespace newCTextNamespace();









char * CTextStack_self_transform_in_string_and_self_clear(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    char *result = self->rendered_text;
    free(self);
    return result;
}

void private_CTextStack_parse_ownership(struct CTextStack *self, struct CTextStack *new_stack){

    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);

    self->rendered_text_alocation_size = new_stack->rendered_text_alocation_size;
    self->size = new_stack->size;
    self->ident_level = new_stack->ident_level;


    self->line_breaker = new_stack->line_breaker;
    self->separator = new_stack->separator;
    self->rendered_text = new_stack->rendered_text;
    free(new_stack);

}
void CTextStack_restart(struct CTextStack *self){
    free(self->rendered_text);
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
}

void CTextStack_represent(struct CTextStack *self){
    printf("%s\n",self->rendered_text);
}


void CTextStack_free(struct CTextStack *self){
    free(self->line_breaker);
    free(self->separator);
    free(self->rendered_text);
    free(self);
}

struct CTextStack * CTextStack_clone(struct CTextStack *self){
    CTextStack *new_stack = newCTextStack(self->line_breaker,self->separator);
    new_stack->ident_level = self->ident_level;
    CTextStack_text(new_stack,self->rendered_text);
    return new_stack;
}




struct CTextStack * CTextStack_substr(struct CTextStack *self, long starter, long end){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CText_transform_index(self->size, starter);
    long formated_end = private_CText_transform_index(self->size, end);

    if(formated_starter == formated_end){
        CTextStack_format(new_element,"%c",self->rendered_text[formated_starter]);
        return new_element;
    }

    for(long i =formated_starter; i < formated_end; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }

    return new_element;

}

void CTextStack_self_substr(struct CTextStack *self, long starter, long end){
    CTextStack *new_stack = CTextStack_substr(self,starter,end);
    private_CTextStack_parse_ownership(self,new_stack);

}


struct CTextStack *CTextStack_replace(struct CTextStack *self,const char *element, const char *element_to_replace){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long element_size = (long)strlen(element);
    for(long i = 0; i < self->size;i++){
        CTextStack  *possible_ocurrence  = CTextStack_substr(self,i,i+element_size);

        if(strcmp(possible_ocurrence->rendered_text,element)== 0){
            CTextStack_text(new_element,element_to_replace);
            i+=element_size -1;
        }

        else{
            CTextStack_format(new_element,"%c",self->rendered_text[i]);
        }

        CTextStack_free(possible_ocurrence);

    }
    return new_element;
}

void CTextStack_self_replace(struct CTextStack *self,const char *element, const char *element_to_replace){
    CTextStack  *new_stack = CTextStack_replace(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    char num_conversion[20] = {0};
    sprintf(num_conversion,"%ld",element_to_replace);
    return CTextStack_replace(self,element,num_conversion);
}


void CTextStack_self_replace_long(struct CTextStack *self,const char *element, long element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_long(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
    CTextStack  *num_formated = newCTextStack_string_empty();
    CTextStack_format(num_formated,"%f",element_to_replace);
    CTextStack  *result = CTextStack_replace(self,element,num_formated->rendered_text);
    CTextStack_free(num_formated);
    return result;
}


void CTextStack_self_replace_double(struct CTextStack *self,const char *element, double element_to_replace){
    CTextStack  *new_stack = CTextStack_replace_double(self,element,element_to_replace);
    private_CTextStack_parse_ownership(self,new_stack);
}



long CTextStack_index_of(struct  CTextStack *self, const char *element){
    long element_size = (long)strlen(element);
    for(int i = 0; i < self->size; i++){
        CTextStack  *possible_element = CTextStack_substr(self,i,i+element_size);
        if(strcmp(possible_element->rendered_text,element) == 0){
            CTextStack_free(possible_element);
            return i;
        }
        CTextStack_free(possible_element);

    }
    return -1;
}


long CTextStack_index_of_char(struct  CTextStack *self, char element){
    for(int i = 0; i < self->size; i++) {
        if(self->rendered_text[i] == element){
            return i;
        }
    }
    return -1;
}
bool CTextStack_starts_with(struct  CTextStack *self, const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,0,element_size);
    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}

bool CTextStack_ends_with(struct  CTextStack *self, const char *element){
    long element_size = strlen(element);
    CTextStack  *separated = CTextStack_substr(self,self->size -element_size,-1);

    if(strcmp(separated->rendered_text,element) == 0){
        CTextStack_free(separated);
        return true;
    }
    CTextStack_free(separated);
    return false;
}



struct CTextStack *CTextStack_lower(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i =0; i < self->size; i++){
        char current = self->rendered_text[i];
        CTextStack_format(new_element,"%c",tolower(current));
    }
    return new_element;
}

void CTextStack_self_lower(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_lower(self);
    private_CTextStack_parse_ownership(self,new_stack);
}

struct CTextStack *CTextStack_upper(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i =0; i < self->size; i++){
        char current = self->rendered_text[i];
        CTextStack_format(new_element,"%c",toupper(current));
    }
    return new_element;
}


void CTextStack_self_upper(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_upper(self);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_reverse(struct CTextStack *self){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    for(long i = (long)self->size; i >= 0 ; i--){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;

}

void CTextStack_self_reverse(struct CTextStack *self){
    CTextStack *new_stack = CTextStack_reverse(self);
    private_CTextStack_parse_ownership(self,new_stack);
}



struct CTextStack *CTextStack_pop(struct CTextStack *self, long starter, long end){
    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;
    long formated_starter = private_CText_transform_index(self->size, starter);
    long formated_end = private_CText_transform_index(self->size, end);

    for(int i =0; i < self->size; i ++){
        if(i >= formated_starter && i <= formated_end){
            continue;
        }
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}


void  CTextStack_self_pop(struct CTextStack *self, long starter, long end){
    CTextStack  *new_stack = CTextStack_pop(self, starter, end);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_insert_at(struct CTextStack *self,long point, const char *element){

    CTextStack *new_element = newCTextStack(self->line_breaker,self->separator);
    new_element->ident_level = self->ident_level;

    long converted_point = private_CText_transform_index(self->size, point);
    for(long i = 0; i < converted_point; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    CTextStack_text(new_element,element);
    for(long i = converted_point; i < self->size; i++){
        CTextStack_format(new_element,"%c",self->rendered_text[i]);
    }
    return new_element;
}

void CTextStack_self_insert_at(struct CTextStack *self,long point, const char *element){
    CTextStack  *new_stack = CTextStack_insert_at(self, point,element);
    private_CTextStack_parse_ownership(self,new_stack);
}


struct CTextStack *CTextStack_trim(struct CTextStack *self){

    CTextStack  *invalid_elements = newCTextStack_string("\t\r\n ");
    long start_point = 0;
    for(int i = 0; i < self->size; i ++){
        char current_char =self->rendered_text[i];
        long invalid_point = CTextStack_index_of_char(invalid_elements, current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            start_point = i;
            break;
        }
    }
    long end_point = -1;
    for(long i = (long)self->size -1; i >= 0; i--){

        char current_char =self->rendered_text[i];
        long invalid_point = CTextStack_index_of_char(invalid_elements, current_char);
        bool is_invalid = invalid_point != -1;
        if(!is_invalid){
            end_point = i+1;
            break;
        }
    }
    CTextStack_free(invalid_elements);
    return CTextStack_substr(self,start_point,end_point);

}


void CTextStack_self_trim(struct CTextStack *self){
    CTextStack  *new_stack = CTextStack_trim(self);
    private_CTextStack_parse_ownership(self,new_stack);
}

//
// Created by jurandi on 14-06-2023.
//
struct CTextStack * newCTextStack(const char *line_breaker, const char *separator){
    struct CTextStack *self = (struct CTextStack*)malloc(sizeof(struct CTextStack));
    self->rendered_text = (char*)malloc(2);
    strcpy(self->rendered_text,"\0");
    self->rendered_text_alocation_size = 2;
    self->size = 0;
    self->ident_level = 0;
    self->line_breaker = strdup(line_breaker);
    self->separator = strdup(separator);


    return self;
}

struct CTextStack *newCTextStack_string(const char *starter){
    CTextStack *self = newCTextStack("","");
    if(starter){
        CTextStack_format(self,"%s", starter);
    }
    return self;
}

struct CTextStack *newCTextStack_string_getting_ownership(const char *starter){
    CTextStack *self = newCTextStack("","");
    free(self->rendered_text);
    self->rendered_text = (char*)starter;
    self->size = strlen(starter);
    self->rendered_text_alocation_size = self->size;
    return self;
}
struct CTextStack *newCTextStack_string_empty(){
    return  newCTextStack("","");
}


int CTextStack_typeof(struct CTextStack *self){
    if(self->size == 0){
        return CTEXT_STRING;
    }

    if(CTextStack_equal(self,"true") ||CTextStack_equal(self,"false") ){
        return CTEXT_BOOL;
    }

    double data;
    int result = sscanf(self->rendered_text,"%lf",&data);
    if(!result){
        return CTEXT_STRING;
    }
    if(CTextStack_index_of(self,".") == -1){
        return CTEXT_LONG;
    }
    return CTEXT_DOUBLE;


}
bool CTextStack_is_a_num(struct CTextStack *self){
    int type = CTextStack_typeof(self);
    if(type == CTEXT_DOUBLE || type == CTEXT_LONG){
        return true;
    }
    return false;
}


const char * CTextStack_typeof_in_str(struct CTextStack *self){
    int current_type = CTextStack_typeof(self);

    if(current_type == CTEXT_BOOL){
        return "bool";
    }

    else if(current_type == CTEXT_STRING){
        return "string";
    }

    else if(current_type == CTEXT_LONG){
        return "long";
    }

    else if(current_type == CTEXT_DOUBLE){
        return "double";
    }

    else{
        return "invalid";
    }
}

bool  CTextStack_parse_to_bool(struct CTextStack *self){
    if(CTextStack_equal(self,"true")){
        return true;
    }
    return false;
}

long  CTextStack_parse_to_integer(struct CTextStack *self){
    long value;
    int result = sscanf(self->rendered_text,"%ld",&value);
    if(!result){
        return -1;
    }
    return value;
}

double  CTextStack_parse_to_double(struct CTextStack *self){
    double value;
    int result = sscanf(self->rendered_text,"%lf",&value);
    if(!result){
        return -1;
    }
    return value;
}



void private_ctext_text_double_size_if_reachs(struct CTextStack *self){

    while(self->size >= (self->rendered_text_alocation_size - 2)){
        self->rendered_text_alocation_size  =  (self->rendered_text_alocation_size  * 2)+2;
        self->rendered_text = (char*)(realloc(
            self->rendered_text,self->rendered_text_alocation_size
        ));
    }
}

void CTextStack_text(struct CTextStack *self, const char *text){

    if (!text || !text[0]) {
        // Tratar caso de ponteiro nulo ou string vazia
        return;
    }

    size_t text_size = strlen(text);

    self->size += text_size;
    private_ctext_text_double_size_if_reachs(self);

    memcpy(
            self->rendered_text + self->size - text_size,
        text,
        text_size
    );
    self->rendered_text[self->size] = '\0';
}



void CTextStack_segment_text(struct CTextStack *self, const char *text){
    CTextStack_segment(self);
    CTextStack_text(self,text);
}


void CTextStack_format(struct CTextStack *self, const char *format, ...){
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}

void CTextStack_segment_format(struct CTextStack *self, const char *format, ...){
    CTextStack_segment(self);
    va_list  argptr;
    va_start(argptr, format);
    private_ctext_generate_formated_text(self,format,argptr);
}


void CTextStack_segment(struct CTextStack *self){

    CTextStack_text(self,self->line_breaker);

    for(int i=0;i<self->ident_level;i++){
        CTextStack_text(self,self->separator);

    }


}

void CTextStack_$open(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');
    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    CTextStack_format(self, "%c",'>');


    self->ident_level += 1;
}

void CTextStack_only$open(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');
        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    CTextStack_format(self, "%c",'>');


}

void CTextStack_auto$close(struct CTextStack *self, const char *tag, const char *format, ...){
    CTextStack_segment(self);
    CTextStack_format(self, "%c",'<');

    CTextStack_text(self,tag);


    if(format!=NULL){
        CTextStack_format(self, "%c",' ');

        va_list  argptr;
        va_start(argptr, format);
        private_ctext_generate_formated_text(self,format,argptr);
    }
    CTextStack_text(self,"/>");

}

void ctext_open(struct CTextStack *self, const char *tag){
    if(tag ==  NULL){

        self->ident_level += 1;
        return;
    }
    CTextStack_$open(self, tag, NULL);
}




void ctext_close(struct CTextStack *self, const char *tag){

    if(tag==NULL){
        self->ident_level -= 1;

        return;
    }
    self->ident_level -= 1;
    CTextStack_segment(self);


    CTextStack_text(self,"</");
    CTextStack_text(self,tag);
    CTextStack_format(self, "%c",'>');

}







void private_ctext_generate_formated_text(
        struct CTextStack *stack,const char *format,va_list argptr){
    long  text_size = strlen(format);

    int i;
    for(i =0;i < text_size -1 ;i++){

        char single_test[3] = {format[i],format[i+1],'\0'};
        char double_test[4] = {0};


        if(i < text_size -2){
            strcpy(double_test,single_test);
            double_test[2] = format[i+2];
            double_test[3] = '\0';

        }

        if(strcmp(single_test,"%d") == 0) {
            char result[20] ={0};
            sprintf(result,"%ld", va_arg(argptr,long));
            CTextStack_text(stack,result);
            i+=1;
            continue;
        }

        if(strcmp(single_test,"%f") == 0) {
            char result_text[20]= {0};

            sprintf(result_text,"%lf", va_arg(argptr,double ));

            for(int t = 18; t > 0; t--){
                char current_char = result_text[t];
                if(current_char != '0' && current_char != '\0'){

                    if(current_char == '.'){
                        result_text[t+2]  = '\0';
                    }
                    else{
                        result_text[t+1]  = '\0';
                    }

                    break;
                }
            }
            CTextStack_text(stack,result_text);
            i+=1;
            continue;
        }

        else if(strcmp(single_test,"%c") == 0){
            char result = va_arg(argptr,int);
            char element[2] = {result,'\0'};
            CTextStack_text(stack,element);
            i+=1;
            continue;
        }


        else if(strcmp(single_test,"%b") == 0){
            bool value = va_arg(argptr,int);
            if(value){
                CTextStack_text(stack,"true");
            }else{
                CTextStack_text(stack,"false");
            }
            i+=1;
            continue;
        }

        else if(strcmp(double_test,"%sc") == 0){
            char *value = va_arg(argptr,char*);
            CTextStack_text(stack,value);
            free(value);
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%s") == 0){
            const char *value = va_arg(argptr,const char*);
            CTextStack_text(stack,value);
            i+=1;
            continue;
        }
        else if(strcmp(double_test,"%tc") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            char *result = CTextStack_self_transform_in_string_and_self_clear(new_stack);
            CTextStack_text(stack,result);
            free(result);
            i+=2;
            continue;
        }

        else if(strcmp(single_test,"%t") == 0){
            struct CTextStack *new_stack = (struct  CTextStack*)va_arg(argptr,void *);
            CTextStack_text(stack,new_stack->rendered_text);
            i+=1;
            continue;
        }

        char element[2] = {format[i],'\0'};
        CTextStack_text(stack,element);

        }



    if(text_size > 0 && text_size> i){
        char element[2] = {format[text_size-1],'\0'};
        CTextStack_text(stack,element);
    }

    va_end(argptr);
}


long private_CText_transform_index(long size , long value){
    long formated_value = value;

    if(formated_value >= size){
        formated_value = size;
    }

    if(formated_value  < 0){
        formated_value = size + (formated_value +1);
    }
    if(formated_value <0){
        formated_value = 0;
    }
    return formated_value;
}


CTextArray * newCTextArray(){
    CTextArray  *self = (CTextArray*) malloc(sizeof (CTextArray));
    self->size = 0;
    self->stacks = (CTextStack**) malloc(0);
    return self;
}

void CTextArray_append(CTextArray *self,CTextStack *element){
    self->stacks =  (CTextStack**) realloc(
            self->stacks,
            (self->size+1)* sizeof (CTextStack*)
            );

    self->stacks[self->size] = element;
    self->size+=1;
}



void CTextArray_append_string(CTextArray *self,const char *element){
    CTextStack *new_element = newCTextStack_string(element);
    CTextArray_append(self,new_element);
}

CTextStack * CTextArray_join(CTextArray *self,const char *separator){
    CTextStack  *result  = newCTextStack_string_empty();
    for(int i = 0; i < self->size; i++){
        if(i < self->size -1){
            CTextStack_format(result,"%t%s",self->stacks[i],separator);
        }
        else{
            CTextStack_format(result,"%t",self->stacks[i]);

        }

    }
    return result;
}

CTextArray *CTextArray_split(const char *element,const char *target){
    CTextArray *self = newCTextArray();
    CTextStack *text = newCTextStack_string(element);
    long target_size = (long)strlen(target);
    CTextStack  *acumulated = newCTextStack_string_empty();

    for(int i = 0; i <text->size; i++){
        CTextStack  *possible_division = CTextStack_substr(text,i,target_size + i);
        if(CTextStack_equal(possible_division,target)){
            CTextArray_append(self,acumulated);
            acumulated = newCTextStack_string_empty();
            CTextStack_free(possible_division);
            continue;
        }
        CTextStack_free(possible_division);

        CTextStack_format(acumulated,"%c",text->rendered_text[i]);
    }

    CTextArray_append(self,acumulated);
    CTextStack_free(text);
    return self;
}

bool CTextStack_equal(struct  CTextStack *self,const char *element){
    return strcmp(self->rendered_text,element) == 0;
}


void  CTextArray_free(CTextArray *self){
    for(int i = 0; i < self->size; i++){
            CTextStack_free(self->stacks[i]);
    }
    free(self->stacks);
    free(self);
}

CTextArray * CTextArray_map(CTextArray *self, CTextStack *(caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();
    for(int i = 0; i < self->size; i++){
        CTextStack *result = caller(self->stacks[i]);
        CTextArray_append(new_array,result);
    }
    return new_array;
}


CTextArray * CTextArray_filter(CTextArray *self, bool (caller)(CTextStack* element)){
    CTextArray *new_array  = newCTextArray();

    for(int i = 0; i < self->size; i++){
        if(caller(self->stacks[i])){

            CTextArray_append(new_array, CTextStack_clone(self->stacks[i]));
        }
    }

    return new_array;
}

void  CTextArray_foreach(CTextArray *self, void (*caller)(CTextStack* element)){
    for(int i = 0; i < self->size; i++){
        caller(self->stacks[i]);
    }
}

bool CTextArray_includes(CTextArray *self,const char *element){
    for(int i = 0 ; i < self->size;i++){
        if(CTextStack_equal(self->stacks[i],element)){
            return true;
        }
    }
    return false;
}


void CTextArray_represent(CTextArray *self){
    for(int i =0; i < self->size; i++){
        CTextStack_represent(self->stacks[i]);
    }
}



CTextStackModule newCTextStackModule(){
    struct CTextStackModule self = {0};
    self.newStack = newCTextStack;
    self.newStack_string = newCTextStack_string;
    self.newStack_string_empty = newCTextStack_string_empty;
    self.newStack_string_getting_ownership = newCTextStack_string_getting_ownership;
    self.text = CTextStack_text;
    self.segment_text = CTextStack_segment_text;
    self.format = CTextStack_format;
    self.segment = CTextStack_segment;
    self.segment_format = CTextStack_segment_format;
    self.$open = CTextStack_$open;
    self.only$open =CTextStack_only$open;
    self.auto$close = CTextStack_auto$close;
    self.open = ctext_open;
    self.close = ctext_close;
    self.free =  CTextStack_free;
    self.clone = CTextStack_clone;
    self.represent = CTextStack_represent;
    self.self_transform_in_string_and_self_clear = CTextStack_self_transform_in_string_and_self_clear;
    self.restart = CTextStack_restart;
    self.substr = CTextStack_substr;
    self.self_substr =CTextStack_self_substr;

    self.pop = CTextStack_pop;
    self.self_pop =CTextStack_self_pop;

    self.replace = CTextStack_replace;
    self.self_replace = CTextStack_self_replace;

    self.replace_long = CTextStack_replace_long;
    self.self_replace_long =CTextStack_self_replace_long;


    self.replace_double = CTextStack_replace_double;
    self.self_replace_double =CTextStack_self_replace_double;

    self.insert_at = CTextStack_insert_at;
    self.self_insert_at  = CTextStack_self_insert_at;


    self.index_of = CTextStack_index_of;
    self.index_of_char = CTextStack_index_of_char;

    self.lower = CTextStack_lower;
    self.self_lower = CTextStack_self_lower;

    self.upper = CTextStack_upper;
    self.self_upper = CTextStack_self_upper;

    self.starts_with = CTextStack_starts_with;
    self.ends_with = CTextStack_ends_with;

    self.equal = CTextStack_equal;
    self.reverse = CTextStack_reverse;
    self.self_reverse = CTextStack_self_reverse;


    self.typeof_element = CTextStack_typeof;
    self.is_a_num = CTextStack_is_a_num;
    self.typeof_in_str = CTextStack_typeof_in_str;
    self.parse_to_bool = CTextStack_parse_to_bool;
    self.parse_to_integer = CTextStack_parse_to_integer;
    self.parse_to_double = CTextStack_parse_to_double;

    self.trim = CTextStack_trim;
    self.self_trim = CTextStack_self_trim;


    return self;
}



CTextArrayModule newCTextArrayModule(){
    CTextArrayModule module = {0};
    module.newArray = newCTextArray;
    module.append = CTextArray_append;
    module.append_string = CTextArray_append_string;
    module.join = CTextArray_join;
    module.map  = CTextArray_map;
    module.filter = CTextArray_filter;
    module.foreach = CTextArray_foreach;
    module.represent = CTextArray_represent;
    module.includes = CTextArray_includes;
    module.free = CTextArray_free;
    return module;
}




CTextNamespace newCTextNamespace(){
    CTextNamespace self  = {0};
    self.stack = newCTextStackModule();
    self.array = newCTextArrayModule();
    return self;
}


#endif // CTEXTENGINE_H

#define CLI_NOT_EXIST -1
#define CLI_BOOL CTEXT_BOOL
#define CLI_DOUBLE CTEXT_DOUBLE
#define CLI_LONG CTEXT_LONG
#define CLI_STRING CTEXT_STRING




#define PRIVATE_CLI_CHAR_TRASH 1
#define PRIVATE_CLI_FLAG_TRASH 2

typedef struct privateCliGarbageElement{
    int type;
    void *value;
}privateCliGarbageElement;


typedef struct privateCliGarbage{
    int size;
    privateCliGarbageElement **values;

}privateCliGarbage;


privateCliGarbage *private_cli_newGarbageArray();
void private_CliGarbage_append(privateCliGarbage*self, int type, void *value);
void private_cli_free_garbage(privateCliGarbage*self);





int private_cli_compare_elements_size(const void *element1,const  void *element2);

void private_cli_sort_text_arrays_by_size(CTextArray *element);

CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive);

CTextStack *private_cli_get_flag_if_its_an_flag(CTextArray *identifiers,CTextStack *possible_flag,bool case_sensitve);

//getterso of arrays
int private_cli_get_type_from_array(CTextArray *elements,int position);

bool private_cli_verifiy_if_element_is_numeric(CTextArray *elements,int position);

const char * private_cli_get_type_in_str_from_array(CTextArray *elements,int position);

char * private_cli_get_str_from_array(privateCliGarbage *garbage, CTextArray *elements, int position,bool case_sensitive);

long private_cli_get_long_from_array(CTextArray *elements,int position);

double private_cli_get_double_from_array(CTextArray *elements,int position);

bool private_cli_get_bool_from_array(CTextArray *elements,int position);


typedef struct CliFlag{

    CTextArray  *elements;
    bool exist;
    privateCliGarbage *private_garbage;
    int size;



}CliFlag;

CliFlag *private_cli_newCliFlag();
void private_cli_CliFlag_free(CliFlag *self);

int CliFlag_typeof_arg(CliFlag *self, int position);
bool CliFlag_is_numeric(CliFlag *self, int position);
const char *CliFlag_typeof_arg_in_str(CliFlag *self, int position);
char* CliFlag_get_str(CliFlag *self, int position, bool case_sensitive);
long  CliFlag_get_long(CliFlag *self, int position);
double CliFlag_get_double(CliFlag *self, int position);
bool CliFlag_get_bool(CliFlag *self, int position);

void CliFlag_represent(CliFlag *self);





#define CLI_CASE_SENSITIVE true
#define CLI_NOT_CASE_SENSITIVE false


typedef struct CliEntry{

    CTextArray * elements;
    int size;
    privateCliGarbage  * private_garbage;

    const char *flag_identifiers;



}CliEntry;

CliEntry * newCliEntry(int argc, char **argv);
int CliEntry_typeof_arg(CliEntry *self,int position);

bool CliEntry_is_numeric(CliEntry *self,int position);

const char *CliEntry_typeof_arg_in_str(CliEntry *self,int position);

CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive);
char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive);

long    CliEntry_get_long(CliEntry *self, int position);

double  CliEntry_get_double(CliEntry *self, int position);

bool  CliEntry_get_bool(CliEntry *self, int position);
void CliEntry_free(struct CliEntry *self);

void  CliEntry_represent(CliEntry *self);





typedef struct CliEntryModule{

    CliEntry *(*newEntry)(int argc, char **argv);
    int (*typeof_arg)(CliEntry *self, int position);
    bool (*is_numeric)(CliEntry *self,int position);
    const char *(*typeof_arg_in_str)(CliEntry *self, int position);
    CliFlag *(*get_flag)(CliEntry *self,const char *flags,bool case_sensitive);
    char*   (*get_str)(CliEntry *self, int position, bool case_sensitive);

    long    (*get_long)(CliEntry *self, int position);
    double  (*get_double)(CliEntry *self, int position);
    bool  (*get_bool)(CliEntry *self, int position);

    void (*represent)(CliEntry *self);
    void (*free)(CliEntry *self);

}CliEntryModule;

CliEntryModule newCliEntryModule();




typedef struct CliFlagModule{

    int      (*typeof_arg)(CliFlag *self, int position);
    bool (*is_numeric)(CliFlag *self,int position);

    const char *(*type_of_arg_in_str)(CliFlag *self, int position);
    char*   (*get_str)(CliFlag *self, int position, bool case_sensitive);
    long    (*get_long)(CliFlag *self, int position);
    double  (*get_double)(CliFlag *self, int position);
    bool  (*get_bool)(CliFlag *self, int position);
    void  (*represent)(CliFlag *self);


}CliFlagModule;

CliFlagModule newCliFlagModule();


typedef struct CliNamespace{
    CliEntryModule entry;
    CliFlagModule  flag;
}CliNamespace;

CliNamespace newCliNamespace();







privateCliGarbage *private_cli_newGarbageArray(){
    privateCliGarbage *self = (privateCliGarbage*) malloc(sizeof (privateCliGarbage));
    self->values = (privateCliGarbageElement**)(0);
    self->size = 0;
    return self;
}

void private_CliGarbage_append(privateCliGarbage*self, int type, void *value){
    self->values = (privateCliGarbageElement**) realloc(self->values, (self->size + 1) * sizeof (privateCliGarbageElement**));
    privateCliGarbageElement *new_garbage = (privateCliGarbageElement*) malloc(sizeof (privateCliGarbageElement));
    new_garbage->type = type;
    new_garbage->value = value;
    self->values[self->size] = new_garbage;
    self->size+=1;;

}

void private_cli_free_garbage(privateCliGarbage*self){
    for(int i = 0 ; i < self->size; i++){
        privateCliGarbageElement *current = self->values[i];
        if(current->type == PRIVATE_CLI_CHAR_TRASH){
            free(current->value);
        }
        if(current->type == PRIVATE_CLI_FLAG_TRASH){
            CliFlag *current_flag = (CliFlag*)current->value;
            private_cli_CliFlag_free(current_flag);
        }
        free(current);
    }
    free(self->values);
    free(self);
}







int private_cli_compare_elements_size(const void *element1,const  void *element2){
    CTextStack  *s1 = *(CTextStack**)element1;
    CTextStack  *s2 = *(CTextStack**)element2;

    return (int)(s2->size - s1->size);


}


void private_cli_sort_text_arrays_by_size(CTextArray *elements){
    qsort(elements->stacks, (size_t)elements->size,sizeof(CTextStack **),private_cli_compare_elements_size);
}


CTextArray * private_cli_parse_flags(const char *flags,bool case_sensitive){
    CTextArray *elements = CTextArray_split(flags,"|");
    private_cli_sort_text_arrays_by_size(elements);

    CTextArray_foreach(elements,CTextStack_self_trim);

    if(!case_sensitive){
        CTextArray_foreach(elements,CTextStack_self_lower);
    }
    return elements;
}

CTextStack *private_cli_get_flag_if_its_an_flag(CTextArray *identifiers,CTextStack *possible_flag,bool case_sensitve){

    CTextStack *formated_possible_flag = CTextStack_clone(possible_flag);
    if(!case_sensitve){
        CTextStack_self_lower(formated_possible_flag);
    }


    for(int i =0; i < identifiers->size; i++){

        CTextStack  *current_identifier = identifiers->stacks[i];

        if(CTextStack_starts_with(formated_possible_flag,current_identifier->rendered_text)){
            CTextStack_self_substr(formated_possible_flag, (long)current_identifier->size,-1);

            return formated_possible_flag;
        }

    }
    CTextStack_free(formated_possible_flag);

    return NULL;
}
int private_cli_get_type_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return CLI_NOT_EXIST;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_typeof(current);
}
bool private_cli_verifiy_if_element_is_numeric(CTextArray *elements,int position){
    int type = private_cli_get_type_from_array(elements,position);
    if(type ==CLI_LONG || type == CLI_DOUBLE){
        return true;
    }
    return false;
}


const char * private_cli_get_type_in_str_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return  "not exist";
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_typeof_in_str(current);
}

char * private_cli_get_str_from_array(privateCliGarbage *garbage, CTextArray *elements, int position,bool case_sensitive){
    if(position >=elements->size){
        return NULL;
    }
    CTextStack *current = elements->stacks[position];
    char *result;
    if(case_sensitive){
        CTextStack *formated = CTextStack_lower(current);
        result = CTextStack_self_transform_in_string_and_self_clear(formated);
    } else{
        result =strdup(current->rendered_text);
    }

    private_CliGarbage_append(garbage, PRIVATE_CLI_CHAR_TRASH, result);
    return result;
}

long private_cli_get_long_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return -1;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_parse_to_integer(current);
}

double private_cli_get_double_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return -1;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_parse_to_double(current);
}

bool private_cli_get_bool_from_array(CTextArray *elements,int position){
    if(position >=elements->size){
        return false;
    }
    CTextStack *current = elements->stacks[position];
    return CTextStack_parse_to_bool(current);
}


CliFlag *private_cli_newCliFlag(){
    CliFlag *self = (CliFlag*) malloc(sizeof(CliFlag));
    *self = (CliFlag){0};
    self->elements = newCTextArray();
    self->private_garbage = private_cli_newGarbageArray();
    return self;
}

void private_cli_CliFlag_free(CliFlag *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->private_garbage);
    free(self);
}


int CliFlag_typeof_arg(CliFlag *self, int position){
    return private_cli_get_type_from_array(self->elements,position);
}

bool CliFlag_is_numeric(CliFlag *self, int position){
    return private_cli_verifiy_if_element_is_numeric(self->elements,position);
}

const char *CliFlag_typeof_arg_in_str(CliFlag *self, int position){
    return private_cli_get_type_in_str_from_array(self->elements,position);
}

char* CliFlag_get_str(CliFlag *self, int position, bool case_sensitive){
    return private_cli_get_str_from_array(self->private_garbage,self->elements, position,case_sensitive);
}

long  CliFlag_get_long(CliFlag *self, int position){
    return private_cli_get_long_from_array(self->elements,position);
}

double CliFlag_get_double(CliFlag *self, int position){
    return private_cli_get_double_from_array(self->elements,position);
}

bool CliFlag_get_bool(CliFlag *self, int position){
    return private_cli_get_bool_from_array(self->elements,position);
}

void CliFlag_represent(CliFlag *self){
    printf("exist: %s\n",self->exist ?"true":"false");
    printf("size :%d\n",self->size);
    printf("flags: \n");
    CTextArray_represent(self->elements);
}




CliEntry * newCliEntry(int argc, char **argv){
    CliEntry *self = (CliEntry*) malloc(sizeof (CliEntry));
    self->size = argc;
    self->elements = newCTextArray();
    self->private_garbage = private_cli_newGarbageArray();

    self->flag_identifiers = " - | -- | --- ";

    for(int i = 0; i < argc; i++){
        CTextArray_append_string(self->elements,argv[i]);
    }
    return self;

}



CliFlag *CliEntry_get_flag(CliEntry *self,const char *flags,bool case_sensitive){
    CTextArray *identifiers = private_cli_parse_flags(self->flag_identifiers,case_sensitive);
    CTextArray *formated_flags = private_cli_parse_flags(flags,case_sensitive);

    CliFlag *flag = private_cli_newCliFlag();
    private_CliGarbage_append(self->private_garbage, PRIVATE_CLI_FLAG_TRASH, flag);
    for(int i = 0; i < self->size;i++){


        CTextStack *possible_flag = private_cli_get_flag_if_its_an_flag(identifiers,self->elements->stacks[i],case_sensitive);
        //means its an flag
        if(possible_flag){
            //means its the  end of current flag and start of other
            if(flag->exist){
                CTextStack_free(possible_flag);
                break;
            }
            else{
                if(CTextArray_includes(formated_flags,possible_flag->rendered_text)){
                    flag->exist = true;
                }
            }
            CTextStack_free(possible_flag);
        }

        else{
            //means its an normal atribute
            if(flag->exist){
                CTextArray_append_string(flag->elements,self->elements->stacks[i]->rendered_text);
            }
        }
    }
    flag->size = (int)flag->elements->size;

    CTextArray_free(identifiers);
    CTextArray_free(formated_flags);

    return flag;

}

int CliEntry_typeof_arg(CliEntry *self,int position){
    return private_cli_get_type_from_array(self->elements,position);
}

bool CliEntry_is_numeric(CliEntry *self,int position){
    return private_cli_verifiy_if_element_is_numeric(self->elements,position);
}

const char *CliEntry_typeof_arg_in_str(CliEntry *self,int position){
    return private_cli_get_type_in_str_from_array(self->elements,position);
}

char*   CliEntry_get_str(CliEntry *self, int position, bool case_sensitive){
    return private_cli_get_str_from_array(self->private_garbage, self->elements, position, case_sensitive);
}

long CliEntry_get_long(CliEntry *self, int position){
    return private_cli_get_long_from_array(self->elements,position);
}

double CliEntry_get_double(CliEntry *self, int position){
    return private_cli_get_double_from_array(self->elements,position);
}

bool CliEntry_get_bool(CliEntry *self, int position){
    return private_cli_get_bool_from_array(self->elements,position);
}

void  CliEntry_represent(CliEntry *self){
    printf("size :%d\n",self->size);
    printf("args:\n");
    CTextArray_represent(self->elements);
}

void CliEntry_free(struct CliEntry *self){
    CTextArray_free(self->elements);
    private_cli_free_garbage(self->private_garbage);
    free(self);
}





CliEntryModule newCliEntryModule(){
    CliEntryModule self = {0};
    self.newEntry = newCliEntry;
    self.is_numeric = CliEntry_is_numeric;
    self.typeof_arg = CliEntry_typeof_arg;
    self.typeof_arg_in_str = CliEntry_typeof_arg_in_str;
    self.get_flag =CliEntry_get_flag;
    self.get_long = CliEntry_get_long;
    self.get_str = CliEntry_get_str;
    self.get_double = CliEntry_get_double;
    self.get_bool = CliEntry_get_bool;
    self.represent = CliEntry_represent;
    self.free = CliEntry_free;
    return self;
}


CliFlagModule newCliFlagModule(){
    CliFlagModule self = {0};
    self.typeof_arg = CliFlag_typeof_arg;
    self.is_numeric =CliFlag_is_numeric;
    self.type_of_arg_in_str = CliFlag_typeof_arg_in_str;
    self.get_str = CliFlag_get_str;
    self.get_long = CliFlag_get_long;
    self.get_double = CliFlag_get_double;
    self.get_bool = CliFlag_get_bool;
    self.represent =CliFlag_represent;
    return self;
}


CliNamespace newCliNamespace(){
    CliNamespace self = {0};
    self.flag = newCliFlagModule();
    self.entry = newCliEntryModule();
    return self;
}


#endif

#ifndef camalgamator_cli_type
#define camalgamator_cli_type

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

struct Behaviors{
    DtwStringArray *dont_change;
    DtwStringArray *include_perpetual;
    DtwStringArray *dont_include;
};
typedef  struct Behaviors Behaviors ;

#endif

#ifndef camalgamator_cli_globals
#define camalgamator_cli_globals

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

CAmalgamatorNamesapce amalgamator;
CliNamespace cli;
DtwNamespace dtw;

#endif

#ifndef camalgamator_cli_declare
#define camalgamator_cli_declare

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

bool is_inside(const char *file,DtwStringArray *source);

short generator_handler(const char *filename,const  char *import_name, void *extra_args);

int collect_flag(CliFlag *flag,DtwStringArray *source);

#endif

#ifndef camalgamator_cli_define
#define camalgamator_cli_define

//silver_chain_scope_start
//mannaged by silver chain

//silver_chain_scope_end

bool is_inside(const char *file,DtwStringArray *source){
    for(int i = 0; i < source->size; i++){
        char *current = source->strings[i];

        if(dtw_starts_with(file,current)){
            return  true;
        }
    }
    return  false;
}
short generator_handler(const char *filename,const  char *import_name, void *extra_args){
    Behaviors * behavior = (Behaviors*)extra_args;
    char *absolute_file  = dtw.get_absolute_path(filename);
    if(absolute_file == NULL){
        return amalgamator.UNEXPECTED_ERROR;
    }

    if(is_inside(absolute_file,behavior->dont_change)){
        free(absolute_file);
        return  amalgamator.DONT_CHANGE;
    }
    if(is_inside(absolute_file, behavior->dont_include)){
        free(absolute_file);
        return  amalgamator.DONT_INCLUDE;
    }
    if(is_inside(absolute_file, behavior->include_perpetual)){
        free(absolute_file);
        return amalgamator.INCLUDE_PERPETUAL;
    }
    free(absolute_file);
    return  amalgamator.INCLUDE_ONCE;
}

int  collect_flag(CliFlag *flag,DtwStringArray *source){
    if(flag->exist == false){
        return amalgamator.NO_ERRORS;
    }
    for(int i = 0; i < flag->size;i++){
        char *current = cli.flag.get_str(flag,i,false);
        char *current_absolute = dtw.get_absolute_path(current);
        if(current_absolute == NULL){
            return amalgamator.UNEXPECTED_ERROR;
        }
        dtw.string_array.append(source,current_absolute);
        free(current_absolute);
    }
    return  amalgamator.NO_ERRORS;
}

#endif

//silver_chain_scope_end



int main(int argc, char *argv[]){
    cli = newCliNamespace();
    amalgamator = newCAmalgamatorNamesapce();
    dtw = newDtwNamespace();
    UniversalGarbage *garbage = newUniversalGarbage();
    CliEntry* entry = newCliEntry(argc,argv);
    UniversalGarbage_add(garbage, cli.entry.free, entry);

    CliFlag *file = cli.entry.get_flag(entry,"f | file",CLI_NOT_CASE_SENSITIVE);

    if(!file->exist){
          printf(" entrie  file not provided \n");
          UniversalGarbage_free(garbage);
          return 1;
    }
    if(file->size == 0){
        printf("file flag its empty\n");
        UniversalGarbage_free(garbage);
        return 1;
    }
    char *filename =  cli.flag.get_str(file,0,CLI_NOT_CASE_SENSITIVE);
    CliFlag *output_flag = cli.entry.get_flag(entry,"o | out | output",CLI_NOT_CASE_SENSITIVE);
    if(!output_flag->exist){
        printf("you didint passed the output file\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    if(output_flag->size == 0){
        printf("output flag its empty\n");
        UniversalGarbage_free(garbage);
        return 1;
    }
    long max_size  = amalgamator.ONE_MB * 100;
    CliFlag *max_bytes = cli.entry.get_flag(entry,"maxbyte",CLI_NOT_CASE_SENSITIVE);
    if(max_bytes->size > 0){
        max_size = cli.flag.get_long(max_bytes,0);
    }
    if(max_size == -1){
        printf("max bytes its not a number\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    CliFlag *max_mega = cli.entry.get_flag(entry,"maxmega",CLI_NOT_CASE_SENSITIVE);
    if(max_mega->size > 0){
        max_size = cli.flag.get_long(max_mega,0);
    }
    if(max_size == -1){
        printf("max mega its not a number\n");
        UniversalGarbage_free(garbage);
        return 1;
    }

    int max_recursion = 1000;
    CliFlag * max_recursion_flag = cli.entry.get_flag(entry,"maxreq",CLI_NOT_CASE_SENSITIVE);
    if(max_recursion_flag->size > 0){
        max_recursion = cli.flag.get_long(max_recursion_flag,0);
    }

    if(max_recursion == -1){
        printf("max recursin its not a number\n");
        UniversalGarbage_free(garbage);
        return 1;
    }


    char *output_file = cli.flag.get_str(output_flag,0,CLI_NOT_CASE_SENSITIVE);

    Behaviors  behaviors = {0};

    behaviors.dont_change = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,  behaviors.dont_change );
    if(collect_flag(cli.entry.get_flag(entry,"nochange | nc",CLI_NOT_CASE_SENSITIVE), behaviors.dont_change)){
            UniversalGarbage_free(garbage);
            return 1;
    }

    behaviors.dont_include = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,   behaviors.dont_include);
    if(collect_flag(cli.entry.get_flag(entry,"noinclude | ni",CLI_NOT_CASE_SENSITIVE), behaviors.dont_include)){
        UniversalGarbage_free(garbage);
        return 1;
    }

    behaviors.include_perpetual = newDtwStringArray();
    UniversalGarbage_add(garbage, dtw.string_array.free,   behaviors.include_perpetual);
    if(collect_flag(cli.entry.get_flag(entry,"perpetual | p",false), behaviors.include_perpetual)){
        UniversalGarbage_free(garbage);
        return 1;
    }

    CAmalgamatorErrorOrContent *error_or_content = amalgamator.generate_amalgamation(
          filename,
          max_size,
          max_recursion,
          generator_handler,
          (void*)&behaviors
      );

    UniversalGarbage_add(garbage,amalgamator.free_error_or_string,error_or_content);
    if(error_or_content->error){
        printf("%s\n",error_or_content->error_msg);
        UniversalGarbage_free(garbage);
        return 1;
    }
    dtw.write_string_file_content(output_file,error_or_content->content);
    UniversalGarbage_free(garbage);
    return 0;
}
