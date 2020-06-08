/** \file CircularBuffer.h */

/*
 * File:   CircularBuffer.h
 * Author: Bruno Grego
 * Date:   2016/08/04
 */

#ifndef _CIRCULARBUFFER_H
#define _CIRCULARBUFFER_H

/**** System includes ****/
#include <stdint.h>

/**** Defines ****/
#define CIRCULAR_BUFFER_SIZE 5000

/** \brief Structure of the circular buffer */
typedef struct{
    /** \brief First write flag */
    uint8_t firstWrite;
    /** \brief Circular buffer head */
    uint16_t head;
    /** \brief Circular buffer tail */
    uint16_t tail;
    /** \brief Circular buffer */
    uint8_t buffer[CIRCULAR_BUFFER_SIZE];
} CircularBuffer_buff_t;

/**** Public functions prototypes ****/

/** \fn void CircularBuffer_InitBuffer (CircularBuffer_buff_t* cbuff)
 *  \brief Initializes the circular buffer pointed by cbuff
 *  \param[in] cbuff Pointer to the circular buffer structure
 */
void CircularBuffer_InitBuffer (CircularBuffer_buff_t* cbuff);

/** \fn BYTE CircularBuffer_WriteBuffer (BYTE val, CircularBuffer_buff_t* cbuff)
 *  \brief Writes the value passed as argument to the circular buffer pointed by cbuff, if the buffer is not full
 *  \param[in] val Value to write
 *  \param[in] cbuff Pointer to the circular buffer structure
 * 	\return 1 if sucessfull, 0 if the buffer is full
 */
uint8_t CircularBuffer_WriteBuffer (uint8_t val, CircularBuffer_buff_t* cbuff);

/** \fn BYTE CircularBuffer_ReadBuffer (BYTE* retval, CircularBuffer_buff_t* cbuff)
 *  \brief This function reads a byte from the circular buffer pointed by cbuff to the char variable pointed by retval, if the buffer is not empty
 *  \param[out] retval Pointer to the variable where will be written the value read from the buffer
 *  \param[in] cbuff Pointer to the circular buffer structure
 * 	\return 1 if sucessfull, 0 if the buffer is empty
 */
uint8_t CircularBuffer_ReadBuffer (uint8_t* retval, CircularBuffer_buff_t* cbuff);

/** \fn WORD CircularBuffer_StoredBytes (CircularBuffer_buff_t* cbuff)
 *  \brief This function returns the number of elements stored in the circular buffer pointed by cbuff
 *  \param[in] cbuff Pointer to the circular buffer structure
 * 	\return Number of stored bytes
 */
uint16_t CircularBuffer_StoredBytes (CircularBuffer_buff_t* cbuff);

#endif /* _CIRCULARBUFFER_H */
