/*
 * 25-calculator.c
 *
 * Created: 8/14/2022 3:52:35 AM
 * Author : Islam Ashraf Mustafa
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "keypad_driver.h"

char arr[6]={NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED,NOTPRESSED};
char count=0;
short result;
int main(void)
{
	lable :
   LCD_vInit();
   keypad_vInit();
	while(1)
	{
		LCD_clearscreen();
		do{
			arr[count]=keypad_u8check_press();
		}while(arr[count]==NOTPRESSED);
		_delay_ms(300);
		if (arr[count]=='A'||arr[count]=='+'||arr[count]=='-'||arr[count]=='*'||arr[count]=='/'||arr[count]=='=')
		{
			LCD_clearscreen();
			LCD_vSend_string("error");
			_delay_ms(2000);
			goto lable;
		}
		else 
		{
		LCD_vSend_char(arr[count]);
		count++;
		}
		do{
			arr[count]=keypad_u8check_press();
		}while(arr[count]==NOTPRESSED);
		_delay_ms(300);
		if (arr[count]=='A'||arr[count]=='+'||arr[count]=='-'||arr[count]=='*'||arr[count]=='/'||arr[count]=='=')
		{
			LCD_clearscreen();
			LCD_vSend_string("error");
			_delay_ms(2000);
			goto lable;
		}
		else
		{
			LCD_vSend_char(arr[count]);
			count++;
		}
		do{
			arr[count]=keypad_u8check_press();
		}while(arr[count]==NOTPRESSED);
		_delay_ms(300);
		if (arr[count]=='+'||arr[count]=='-'||arr[count]=='*'||arr[count]=='/')
		{
			LCD_vSend_char(arr[count]);
			count++;
		}
		else
		{
			LCD_clearscreen();
			LCD_vSend_string("error");
			_delay_ms(2000);
			goto lable;
		}
		do{
			arr[count]=keypad_u8check_press();
		}while(arr[count]==NOTPRESSED);
		_delay_ms(300);
		if (arr[count]=='A'||arr[count]=='+'||arr[count]=='-'||arr[count]=='*'||arr[count]=='/'||arr[count]=='=')
		{
			LCD_clearscreen();
			LCD_vSend_string("error");
			_delay_ms(2000);
			goto lable;
		}
		else
		{
			LCD_vSend_char(arr[count]);
			count++;
		}
		do{
			arr[count]=keypad_u8check_press();
		}while(arr[count]==NOTPRESSED);
		_delay_ms(300);
		if (arr[count]=='A'||arr[count]=='+'||arr[count]=='-'||arr[count]=='*'||arr[count]=='/'||arr[count]=='=')
		{
			LCD_clearscreen();
			LCD_vSend_string("error");
			_delay_ms(2000);
			goto lable;
		}
		else
		{
			LCD_vSend_char(arr[count]);
			count++;
		}
		do{
			arr[count]=keypad_u8check_press();
		}while(arr[count]==NOTPRESSED);
		_delay_ms(300);
		if (arr[count]=='=')
		{
			LCD_vSend_char(arr[count]);
		}
		else
		{
			LCD_clearscreen();
			LCD_vSend_string("error");
			_delay_ms(2000);
			goto lable;
		}
		switch (arr[count-3])
		{
			case '+' :
			result=((arr[count-5]-48)*10)+(arr[count-4]-48)+((arr[count-2]-48)*10)+(arr[count-1]-48);
			if (result<10)
			{
				LCD_vSend_char(result+48);
				_delay_ms(2000);
			}
			else if ((result>10)&&(result<100))
			{
				LCD_vSend_char((result/10)+48);
				LCD_vSend_char((result%10)+48);
				_delay_ms(2000);
			}
			break;
			case '-' :
			result=((arr[count-5]-48)*10)+(arr[count-4]-48)-((arr[count-2]-48)*10)-(arr[count-1]-48);
			if (result<10)
			{
				LCD_vSend_char(result+48);
				_delay_ms(2000);
			}
			else if ((result>10)&&(result<100))
			{
				LCD_vSend_char((result/10)+48);
				LCD_vSend_char((result%10)+48);
				_delay_ms(2000);
			}
			break;
			case '*' :
			result=(((arr[count-5]-48)*10)+(arr[count-4]-48))*(((arr[count-2]-48)*10)+(arr[count-1]-48));
			if (result<10)
			{
				LCD_vSend_char(result+48);
				_delay_ms(2000);
			}
			else if ((result>10)&&(result<100))
			{
				LCD_vSend_char((result/10)+48);
				LCD_vSend_char((result%10)+48);
				_delay_ms(2000);
			}
			break;
			case '/' :
			result=(((arr[count-5]-48)*10)+(arr[count-4]-48))/(((arr[count-2]-48)*10)+(arr[count-1]-48));
			if (result<10)
			{
				LCD_vSend_char(result+48);
				_delay_ms(2000);
			}
			else if ((result>10)&&(result<100))
			{
				LCD_vSend_char((result/10)+48);
				LCD_vSend_char((result%10)+48);
				_delay_ms(2000);
			}
			break;
		}
	
		}
}

