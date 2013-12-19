// {{{ includes
#ifdef HAVE_CONFIG_H
	#include "config.h"
#endif

#include "php.h"
#include "php_helloworld.h"
// }}}

// {{{ helloworld module info function
PHP_MINFO_FUNCTION(helloworld) {
	php_info_print_table_start();
	php_info_print_table_row(2, "HelloWorld support", "enabled! ;)");
	php_info_print_table_end();
}
// }}}

// {{{ Function with parameter of any type
PHP_FUNCTION(helloworld) {
	zval *param;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &param) != SUCCESS)
		RETURN_NULL();

	const char *type_str;

	switch (Z_TYPE_P(param)) {
		case IS_NULL:
			type_str = "NULL fuj";
			break;

		case IS_BOOL:
			type_str = "Boolean";
			break;

		case IS_LONG:
			type_str = "Long";
			break;

		case IS_DOUBLE:
			type_str = "Double";
			break;

		case IS_STRING:
			type_str = "String";
			break;

		case IS_ARRAY:
			type_str = "Array";
			break;

		case IS_OBJECT:
			type_str = "Object";
			break;
			
		case IS_RESOURCE:
			type_str = "Resurs!";
			break;

		default:
			RETURN_NULL();
	}

	convert_to_string(param);

	long str_len = Z_STRLEN_P(param) + 50;
	char *param_str = ecalloc(str_len, sizeof(char));

	snprintf(param_str, str_len, "Hello %s %s!\n", type_str, Z_STRVAL_P(param));

	zval_ptr_dtor(&param);
	RETURN_STRING(param_str, 0);
}
// }}}

// {{{ Check if extension is built as shared module
#ifdef COMPILE_DL_HELLOWORLD
	ZEND_GET_MODULE(helloworld)
#endif
// }}}

// {{{ Structure telling ZE address of our function(s)
static const zend_function_entry helloworld_functions[] = {
	PHP_FE(helloworld, NULL)
	PHP_FE_END
};
// }}}

// {{{ Setup module
zend_module_entry helloworld_module_entry = {
	STANDARD_MODULE_HEADER,
	"helloworld",            // Name
	helloworld_functions,    // Functions
	NULL,                    // MINIT
	NULL,                    // MSHUTDOWN
	NULL,                    // RINIT
	NULL,                    // RSHUTDOWN
	PHP_MINFO(helloworld),   // MINFO
	NO_VERSION_YET,          // Version
	STANDARD_MODULE_PROPERTIES
};
// }}}
// vim: fdm=marker
