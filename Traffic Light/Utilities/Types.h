/*
 * Types.h
 *
 * Created: 10/6/2022 8:41:47 PM
 *  Author: Peter
 */ 


#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char uint8_t;

typedef enum EN_DIO_error_t
{
	DIO_OK,
	DIO_WRONG_PIN_NUMBER,
	DIO_WRONG_PORT_NUMBER,
	DIO_WRONG_DIRECTION,
	DIO_WRONG_VALUE
}EN_DIO_error_t ;



#endif /* TYPES_H_ */