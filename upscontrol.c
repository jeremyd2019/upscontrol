#include "osapi.h"
#include "user_interface.h"
#include "cpp_routines.h"
#include "driver/uart.h"

void ICACHE_FLASH_ATTR init_done()
{
	os_printf("Init done!\n");
}

// they seem to have neglected to define U0CTS function...
#define FUNC_U0CTS FUNC_U0RTS
void ICACHE_FLASH_ATTR user_init()
{
	uart_init(2400, 74880);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTDO_U, FUNC_U0RTS);
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_MTCK_U, FUNC_U0CTS);
	system_uart_swap();
  system_set_os_print(1);
  do_global_ctors();
  os_printf("Hello world!\n");
  system_init_done_cb(&init_done);
}
