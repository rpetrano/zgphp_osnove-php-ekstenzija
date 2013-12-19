// {{{ includes
#ifdef HAVE_CONFIG_H
	#include "config.h"
#endif

#include "php.h"
#include "php_counter.h"
// }}}

// {{{ Globals initialization
ZEND_DECLARE_MODULE_GLOBALS(counter)

static void php_counter_init_globals(zend_counter_globals *globals) {
	globals->counter = 0;
}
// }}}

// {{{ Module info function
PHP_MINFO_FUNCTION(counter) {
	php_info_print_table_start();
	php_info_print_table_row(2, "Counter support", "enabled! ;)");
	php_info_print_table_end();
}
// }}}

// {{{ Module init function
PHP_MINIT_FUNCTION(counter) {
	ZEND_INIT_MODULE_GLOBALS(counter, php_counter_init_globals, NULL);

	COUNTER = 0;
	return SUCCESS;
}
// }}}

// {{{ Request init function
PHP_RINIT_FUNCTION(counter)
{
	COUNTER++;
	return SUCCESS;
}
// }}}

// {{{ Userspace function
PHP_FUNCTION(get_request_count) {
	RETURN_LONG(COUNTER);
}
// }}}

// {{{ Check if extension is built as shared module
#ifdef COMPILE_DL_COUNTER
	ZEND_GET_MODULE(counter)
#endif
// }}}

// {{{ Structure telling ZE address of our function(s)
static const zend_function_entry counter_functions[] = {
	PHP_FE(get_request_count, NULL)
	PHP_FE_END
};
// }}}

// {{{ Setup module
zend_module_entry counter_module_entry = {
	STANDARD_MODULE_HEADER,
	"counter",               // Name
	counter_functions,       // Functions
	PHP_MINIT(counter),      // MINIT
	NULL,                    // MSHUTDOWN
	PHP_RINIT(counter),      // RINIT
	NULL,                    // RSHUTDOWN
	PHP_MINFO(counter),   // MINFO
	NO_VERSION_YET,          // Version
	STANDARD_MODULE_PROPERTIES
};
// }}}
// vim: fdm=marker
