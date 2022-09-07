#include "shell.h"
/**
 * sign_handle - ^C to end shell.
 * @sign_handle: signal handler.
 * Return: void.
 */
void sign_handle(int sign_handle)
{
	(void) sign_handle;
	_puts("\n$ ");
}
