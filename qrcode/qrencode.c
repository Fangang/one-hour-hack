#include <stdio.h>
#include <qrencode.h>
#include <SDL/SDL.h>

int margin = 4;
int size = 4;
SDL_Surface *screen = NULL;

void draw_QRcode(QRcode *qrcode,int ox, int oy)
{
	int x;
	int y;
	int width;
	unsigned char *p;
	SDL_Rect rect;
	
	ox += margin * size;
	oy += margin * size;
	width = qrcode->width;
	p = qrcode->data;

	for(y=0;y<width;++y)
	{
    for(x=0;x<width;++x)
		{
			rect.x = ox + x * size;
			rect.y = oy + y * size;
			rect.w = size;
			rect.h = size;
			//SDL_FillRect(screen,&rect,(*p&1)?0:0xffffff);
			p++;
		}
	}

}
int main(int argc, char *argv[])
{
	int width;

	QRcode *qrcode;
	qrcode = QRcode_encodeString("hanwenfang",0,QR_ECLEVEL_H,QR_MODE_8,0);
	width = (qrcode->width + margin *2) * size;
	screen = SDL_SetVideoMode(width,width,32,0);
	//SDL_FillRect(screen,NULL,0xffffff);

	draw_QRcode(qrcode,0,0);

	SDL_Flip(screen);
	QRcode_free(qrcode);

	SDL_Quit();
	exit(0);
}
