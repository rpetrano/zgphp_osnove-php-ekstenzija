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

// {{{ helloworld userspace function
PHP_FUNCTION(helloworld) {
	RETURN_STRING("Hello World!", 1);
}
// }}}

// {{{ Identical copy
PHP_FUNCTION(helloworld2) {
	char *greeting = estrdup("Hello World!");
	RETURN_STRING(greeting, 0);
}
// }}}

// {{{ Functions for other types
PHP_FUNCTION(helloworld_double) { RETURN_DOUBLE(3.14); }

PHP_FUNCTION(helloworld_long)   { RETURN_LONG  (1337); }

PHP_FUNCTION(helloworld_bool)   { RETURN_BOOL  (1); }

PHP_FUNCTION(helloworld_null)   { RETURN_NULL  (); }
// }}}

// {{{ Function with string parameter
PHP_FUNCTION(helloworld_me) {
	char *name = NULL;
	int name_len = 0;

	zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|s", &name, &name_len);

	if (name == NULL) {
		name = estrdup("World");
		name_len = 5;
	}

	int size = name_len + 9;
	char *greeting = ecalloc(size, sizeof(char));

	snprintf(greeting, size, "Hello %s!", name);

	efree(name);
	RETURN_STRING(greeting, 0);
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
	PHP_FE(helloworld2, NULL)
	PHP_FE(helloworld_double, NULL)
	PHP_FE(helloworld_long, NULL)
	PHP_FE(helloworld_bool, NULL)
	PHP_FE(helloworld_null, NULL)
	PHP_FE(helloworld_me, NULL)
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
