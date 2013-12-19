#ifndef PHP_COUNTER_H
#define PHP_COUNTER_H

extern zend_module_entry counter_module_entry;
#define counter_module_ptr &counter_module_entry

PHP_MINFO_FUNCTION(counter);
PHP_MINIT_FUNCTION(counter);

PHP_RINIT_FUNCTION(counter);

PHP_FUNCTION(get_request_count);

// {{{ Globals declarations
ZEND_BEGIN_MODULE_GLOBALS(counter);
long counter;
ZEND_END_MODULE_GLOBALS(counter);
// }}}

// {{{ If Thread Safe Zend is enabled, use Thread Safe Resource Manager to access globals
#ifdef ZTS
	#include "TSRM.h"
	#define COUNTER TSRMG(counter_globals_id, zend_counter_globals *, counter)
#else
	#define COUNTER (counter_globals.counter)
#endif
// }}}

#endif
//vim: fdm=marker
