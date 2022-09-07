#include "shell.h"
/**
 * sign_handle - handles control C interruption of a process
 * @sig_handler: variable for handler
 * Return: nothing
*/
void sign_handle(int sign_handle)
{
	(void) sign_handle;
	_puts("\n$ ");
}
