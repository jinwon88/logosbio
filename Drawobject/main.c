
#include "adstar.h"
void boardinit();
void lcdon();

int main()
{
	boardinit();
	init_interrupt();
	uart_config(0,115200,DATABITS_8,STOPBITS_1,UART_PARNONE);
	debugstring("================================================\r\n");
	debugprintf("ADSTAR Drawing View.System Clock(%dMhz)\r\n",get_ahb_clock()/1000000);
	debugstring("================================================\r\n");
	
	//jijojoasjflkasjdlasdfsdfsf
	crtc_clock_init();

	SURFACE *frame = createframe(800,480,16);
	setscreen(SCREEN_800x480,SCREENMODE_RGB565);
	setframebuffer(frame);
	lcdon();

	set_draw_target(frame);	
	
	draw_rectfill(0,0,800,480,MAKE_COLORREF(255,255,255));
	
	int i;
	for(i=0;i<240;i+=10)
	{
		draw_rect(0+i,0+i,800-(i*2),480-(i*2),MAKE_COLORREF(0,255,0));
	}
	draw_rectfill(500,200,100,100,MAKE_COLORREF(100,100,100));
	
	draw_circle(400,240,50,MAKE_COLORREF(0,0,255));
	
	draw_circlefill(100,100,30,MAKE_COLORREF(0,255,255));
	
	draw_ellipsefill(500,100,100,20,MAKE_COLORREF(255,0,255));
	draw_ellipse(300,100,100,20,MAKE_COLORREF(255,0,255));
	
	draw_roundrect(100,200,50,50,10,MAKE_COLORREF(255,0,255));
	draw_roundrectfill(200,200,50,50,10,MAKE_COLORREF(255,0,255));
	while(1);
}
