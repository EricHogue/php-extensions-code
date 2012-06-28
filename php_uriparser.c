/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Elizabeth Smith <auroraeosrose@php.net>                      |
  +----------------------------------------------------------------------+
*/

#include "php_uriparser.h"
#include "ext/standard/info.h"

ZEND_BEGIN_ARG_INFO(uriparser_version_args, ZEND_SEND_BY_VAL)
ZEND_END_ARG_INFO()

/* {{{ proto int uriparser_version(void)
 Returns a string version number of the uriparser library being used */
PHP_FUNCTION(uriparser_version)
{
	if (zend_parse_parameters_none() == FAILURE) {
		return;
	}
    
	RETURN_STRING(URI_VER_ANSI, 1);
}
/* }}} */

/* {{{ PHP_MINIT_FUNCTION */
PHP_MINIT_FUNCTION(uriparser)
{
	PHP_MINIT(uriparser_uri)(INIT_FUNC_ARGS_PASSTHRU);
	PHP_MINIT(uriparser_normalize)(INIT_FUNC_ARGS_PASSTHRU);
	
	return SUCCESS;
}
/* }}} */

/* {{{ PHP_MINFO_FUNCTION */
PHP_MINFO_FUNCTION(uriparser)
{
	php_info_print_table_start();
	php_info_print_table_header(2, "Uriparser Library Bindings", "enabled");
	php_info_print_table_row(2, "Uriparser Library Version", URI_VER_ANSI);
	php_info_print_table_row(2, "Extension Version", PHP_URIPARSER_VERSION);
	php_info_print_table_end();
}
/* }}} */

/* {{{ uriparser_functions[] */
static const zend_function_entry uriparser_functions[] = {
	PHP_FE(uriparser_version, uriparser_version_args)
	ZEND_FE_END
};
/* }}} */

/* {{{ uriparser_module_entry */
zend_module_entry uriparser_module_entry = {
	STANDARD_MODULE_HEADER,
	"uriparser",
	uriparser_functions,
	PHP_MINIT(uriparser),
	NULL, /* MSHUTDOWN */
	NULL, /* RINIT */
	NULL, /* RSHUTDOWN */
	PHP_MINFO(uriparser), /* MINFO */
	PHP_URIPARSER_VERSION, /* USE NO_VERSION_YET at the very least */
	STANDARD_MODULE_PROPERTIES
};
/* }}} */

/* Required for dynamic linking */
#ifdef COMPILE_DL_URIPARSER
ZEND_GET_MODULE(uriparser)
#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
