/** @file sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com 
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include <MCP48FV_DAC_SPI.h>
#include "sys_common.h"

/* USER CODE BEGIN (1) */
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */

uint16_t lookUpSine[]={
                       0x800,0x880,0x900,0x97f,0x9fd,0xa78,0xaf1,0xb67,
                       0xbda,0xc49,0xcb3,0xd19,0xd79,0xdd4,0xe29,0xe78,
                       0xec0,0xf02,0xf3c,0xf6f,0xf9b,0xfbf,0xfdb,0xfef,
                       0xffb,0xfff,0xffb,0xfef,0xfdb,0xfbf,0xf9b,0xf6f,
                       0xf3c,0xf02,0xec0,0xe78,0xe29,0xdd4,0xd79,0xd19,
                       0xcb3,0xc49,0xbda,0xb67,0xaf1,0xa78,0x9fd,0x97f,
                       0x900,0x880,0x800,0x77f,0x6ff,0x680,0x602,0x587,
                       0x50e,0x498,0x425,0x3b6,0x34c,0x2e6,0x286,0x22b,
                       0x1d6,0x187,0x13f,0xfd,0xc3,0x90,0x64,0x40,
                       0x24,0x10,0x4,0x0,0x4,0x10,0x24,0x40,
                       0x64,0x90,0xc3,0xfd,0x13f,0x187,0x1d6,0x22b,
                       0x286,0x2e6,0x34c,0x3b6,0x425,0x498,0x50e,0x587,
                       0x602,0x680,0x6ff,0x77f,0x800};




/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */

    // set value, 333= 3.33V, 0< input <500
    //    MSP48FV_Set_Value(333);


    //kinda of step function, needs debugging
    uint16_t i=0;
    uint32_t j=0;
    mibspiInit();
    for(i=0; i<sizeof(lookUpSine)-1; i++){
       for (  j=0;j<0xFffF; j++){
           asm("NOP");
       }


       uint8_t try1= lookUpSine[i]/0x100;
       uint8_t try2= lookUpSine[i]%0x100;

       uint16_t txbuffer[]={0x00,try1, try2}; //debug
       mibspiSetData(mibspiREG1,0,txbuffer);
        mibspiTransfer(mibspiREG1,0);
       while(!(mibspiIsTransferComplete(mibspiREG1,0)));
    }


//

/* USER CODE END */

    return 0;
}


/* USER CODE BEGIN (4) */
/* USER CODE END */
