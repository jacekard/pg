#define F_CPU 16000000UL 

#include <util/delay.h>
#include <lcd.h>
#include <avr/io.h>


void lcd_init(void) {
	MCUCR = _BV(SRE) | _BV(SRW10);
	XMCRA = _BV(SRW01) | _BV(SRW00) | _BV(SRW11);
	MMnet104_CONF = 0x13;
	
	_delay_ms(30);
	COMM_LCD = 0x30;
	_delay_ms(30);
	COMM_LCD = 0x30;
	_delay_ms(30);
	COMM_LCD = 0x30;
	_delay_ms(30);
	pisz_com(0x38);
	pisz_com(0x0C);
    pisz_com(0x01);
	pisz_com(0x06);
	//_delay_ms(30);
}

void disp_txt_d(char* adres){
	volatile uint8_t al;
	for(int i=0; i<16; i++){
		al = adres[i];
		if(al == 0x00){
			break;
		}
		
		pisz_ws(al);
	}
}

void disp_txt_p(char* adres){
		volatile uint8_t al;
	for(int i=0; i<16; i++){
		al = adres[i];
		if(al == 0x00){
			break;
		}
		
		pisz_ws(al);
	}
}

int main(void)
{
	lcd_init();
	disp_txt_d("ADC=");
	char buff[5];
	buff[4] = 0;
    while(1)
    {
		ADMUX = 0b11000001;
		ADCSRA = 0b11100111;
		while(ADIF == 1);
		uint16_t wynik;
		wynik = ADCL;
		wynik += (ADCH & 0b00000011) << 8;
		pisz_com(0b10000000);
		disp_txt_p("ADC=");
		buff[0] = (wynik >> 8) + '0';
		buff[1] = (wynik & 0b11110000) >> 4;
		if(buff[1] < 10) buff[1] += '0';
		else buff[1] += 'A'-10;
		buff[2] = (wynik & 0b1111);
		if(buff[2] < 10) buff[2] += '0';
		else buff[2] += 'A'-10;
		buff[3] = 'H';
		disp_txt_p(buff);
		pisz_com(0b11000000);
		disp_txt_d("Vin=");
		float vin = (float)(wynik)/1024 * 5;
		buff[0] = (int)(vin) + '0';
		buff[1] = '.';
		buff[2] = (vin - (int)(vin)) * 10 + '0';
		buff[3] = 'V';
		disp_txt_d(buff);
		
		_delay_ms(100);
        //TODO:: Please write your application code 
    }
}
