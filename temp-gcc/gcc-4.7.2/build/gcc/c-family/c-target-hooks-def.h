#ifndef TARGET_HANDLE_C_OPTION
#define TARGET_HANDLE_C_OPTION default_handle_c_option
#endif
#ifndef TARGET_OBJC_CONSTRUCT_STRING_OBJECT
#define TARGET_OBJC_CONSTRUCT_STRING_OBJECT NULL
#endif
#ifndef TARGET_STRING_OBJECT_REF_TYPE_P
#define TARGET_STRING_OBJECT_REF_TYPE_P hook_bool_const_tree_false
#endif
#ifndef TARGET_CHECK_STRING_OBJECT_FORMAT_ARG
#define TARGET_CHECK_STRING_OBJECT_FORMAT_ARG NULL
#endif

#define TARGETCM_INITIALIZER \
  { \
    TARGET_HANDLE_C_OPTION, \
    TARGET_OBJC_CONSTRUCT_STRING_OBJECT, \
    TARGET_STRING_OBJECT_REF_TYPE_P, \
    TARGET_CHECK_STRING_OBJECT_FORMAT_ARG, \
  }
