#include <xc.h>
#include <pic16f1829.h>
#include <stdint.h>
#include "spi.h"



/*Slave*/

//Slaveピン設定関数

//SDO1  RC7                 出力
//SDI1  RB4                 入力
//SCK1  RB6                 入力
//SS1   RC6                 入力
void slave_reg()
{
    
    //ピン設定
    TRISB   = TRISB | 0x50;
    TRISC   = TRISC | 0x40;
    PORTB   = 0x00;
    PORTC   = 0x00;

    //SPI設定
    SSP1CON1    = 0b00100100;
    SSP1STAT    = 0b00000000;
    
    //割り込みの許可
    SSP1IF  = 0;
    SSP1IE  = 1;
    
}


//SPIで受け取ったデータを返す関数
//割り込み内で実行してください
//返り値 char型 
uint8_t slave_read()
{
    
	//SPIのデータが受信しているかのチェック
    if((SSP1IF == 1) && (SSP1STATbits.BF != 0)){
        SSP1IF  = 0;
        return (SSP1BUF);
    }

    return 0;

}



/*Master*/

//Masterピン設定

//SDO1  RC7                 出力
//SDI1  RB4                 入力
//SCK1  RB6                 出力
void master_reg()
{
    
    //ピン設定
    TRISB   = TRISB | 0x10;
    TRISC   = TRISC | 0x00;
    PORTB   = 0x00;
    PORTC   = 0x00;

    //SPI設定
    SSP1CON1    = 0b00100000;//分周比4
    SSP1STAT    = 0b00000000;

    //割り込みの許可
    SSP1IF  = 0;
    SSP1IE  = 1;

}

//SPIでデータを送る関数
//obj   :SSピンの名前(SS_XX)
//s_data:送るデータ(8bit)

void master_send(int obj,uint8_t s_data)
{
    
    if(obj == SS_RA0){
        RA0 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RA0 = 1;
        return;
    }

    if(obj == SS_RA1){
        RA1 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RA1 = 1;
        return;
    }

    if(obj == SS_RA2){
        RA2 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RA2 = 1;
        return;
    }

    if(obj == SS_RA3){
        RA3 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RA3 = 1;
        return;
    }

    if(obj == SS_RA4){
        RA4 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RA4 = 1;
        return;
    }

    if(obj == SS_RA5){
        RA5 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RA5 = 1;
        return;
    }

    if(obj == SS_RB5){
        RB5 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RB5 = 1;
        return;
    }

    if(obj == SS_RB7){
        RB7 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RB7 = 1;
        return;
    }

    if(obj == SS_RC0){
        RC0 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RC0 = 1;
        return;
    }

    if(obj == SS_RC1){
        RC1 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RC1 = 1;
        return;
    }
    
    if(obj == SS_RC2){
        RC2 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RC2 = 1;
        return;
    }
    
    if(obj == SS_RC3){
        RC3 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RC3 = 1;
        return;
    }
    
    if(obj == SS_RC4){
        RC4 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RC4 = 1;
        return;
    }
    
    if(obj == SS_RC5){
        RC5 = 0;
        SSP1BUF = s_data;
        while(SSP1STATbits.BF == 0);
        RC5 = 1;
        return;
    }
    
}

