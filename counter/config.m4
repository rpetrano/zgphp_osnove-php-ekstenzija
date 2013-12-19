PHP_ARG_WITH(counter, Enabled the Counter extension,
	[  --with-counter          Enable the Counter extension])

if test "$PHP_COUNTER" != "no"; then
	PHP_NEW_EXTENSION(counter, counter.c, $ext_shared)
	PHP_SUBST(COUNTER_SHARED_LIBADD)
fi
