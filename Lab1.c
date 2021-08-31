#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <stdlib.h>

static int k = 0;
//1.
int FunCallBack(libusb_context *ctx, libusb_device *device, libusb_hotplug_event event, void *user_data){
    //действия, выполняемые по событию на шине USB
	//дескриптор устройства
	struct libusb_device_descriptor deviceDesk;

		if(libusb_get_device_descriptor(device, &deviceDesk)!=0)
		{
		printf("Неудалось получить дескриптор устройства:\n");
		exit(1);
		}
		printf("Подключеное устройство, параметры: %x, %x, %x\n", deviceDesk.bDeviceClass, deviceDesk.bDeviceSubClass, deviceDesk.bDeviceProtocol);	
		/*if (LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED == event) 
		{		
		}
		else if (LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT == event)
		{			
		}*/
		k++;
		return 0;
	}
    
int main()
{
	//2.Выполнить инициализацию библиотеки libusb
	if(libusb_init(NULL)!=0)
	{
		printf("Инициализация не прошла:\n");
		exit(1);
	}	
	//3.
	libusb_hotplug_callback_handle callback_handle;
	int rc = libusb_hotplug_register_callback(NULL, LIBUSB_HOTPLUG_EVENT_DEVICE_ARRIVED |
                                        LIBUSB_HOTPLUG_EVENT_DEVICE_LEFT, LIBUSB_HOTPLUG_ENUMERATE, 0x058f, 0x6387,
                                        LIBUSB_HOTPLUG_MATCH_ANY, FunCallBack, NULL,
                                        &callback_handle);//0x058f:0x6387
	if(rc!=LIBUSB_SUCCESS)
	{
		printf("Неудалось зарегистрировать функцию обратного вызова:\n");
		exit(1);
	}
	//4.
	while(k<1)
	{
		int rc1 = libusb_handle_events(NULL);
		if(rc!=LIBUSB_SUCCESS)
	{
		printf("Неудалось детектировать событие:\n");
		exit(1);
	}
	}
	//5.
	libusb_hotplug_deregister_callback(NULL,callback_handle); 
	libusb_exit(NULL);
	
	return 0;	
	}
