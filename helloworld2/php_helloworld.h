#ifndef PHP_HELLOWORLD_H
#define PHP_HELLLOWORD_H

extern zend_module_entry helloworld_module_entry;
#define helloworld_module_ptr &helloworld_module_entry
#define phpext_helloworld_ptr php_module_ptr

PHP_MINFO_FUNCTION(helloworld);

PHP_FUNCTION(helloworld);
PHP_FUNCTION(helloworld2);

PHP_FUNCTION(helloworld_double);
PHP_FUNCTION(helloworld_long);
PHP_FUNCTION(helloworld_bool);
PHP_FUNCTION(helloworld_null);

PHP_FUNCTION(helloworld_me);

#endif
