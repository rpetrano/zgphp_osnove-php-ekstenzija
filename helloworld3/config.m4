PHP_ARG_WITH(helloworld, Enabled the HelloWorld extension,
	[  --with-helloworld       Enable the HelloWorld extension])

if test "$PHP_HELLO" != "no"; then
	PHP_NEW_EXTENSION(helloworld, helloworld.c, $ext_shared)
	PHP_SUBST(HELLOWORLD_SHARED_LIBADD)
fi
