/**************************************************************/
/***********     Author    :  Mokhtar                **********/
/***********     Version   :  V0.1                   **********/
/***********     Date      :  26-11-2022             **********/
/**************************************************************/

#ifndef OTA_CONFIG_H
#define OTA_CONFIG_H

#define OTA_RECIEVE_TIMEOUT_S   15

/* To change these values you muct change it too in NodeMCU code*/
#define OTA_DATA_START_CHAR     'X'
#define OTA_LINE_BREAK_CHAR     'Y'
#define OTA_DATA_END_CHAR       'Z'
#define OTA_READ_CONFIRM_CHAR   'R'
#endif
