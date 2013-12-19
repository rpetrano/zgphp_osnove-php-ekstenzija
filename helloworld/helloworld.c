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
	php_printf("Hello World!\n");
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
