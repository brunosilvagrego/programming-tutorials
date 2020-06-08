/**** Modules includes ****/
#include "CircularBuffer.h"

/**** Public functions code ****/

/** \fn void CircularBuffer_InitBuffer (CircularBuffer_buff_t* cbuff)
 *  \brief Initializes the circular buffer pointed by cbuff
 *  \param[in] cbuff Pointer to the circular buffer structure
 */
void CircularBuffer_InitBuffer (CircularBuffer_buff_t* cbuff)
{
    uint16_t i;

    cbuff->firstWrite = 1;
    cbuff->head = 0;
    cbuff->tail = 0;

    for (i = 0; i < CIRCULAR_BUFFER_SIZE; i++)
    {
        cbuff->buffer[i] = 0;
    }
}

/** \fn BYTE CircularBuffer_WriteBuffer (BYTE val, CircularBuffer_buff_t* cbuff)
 *  \brief Writes the value passed as argument to the circular buffer pointed by cbuff, if the buffer is not full
 *  \param[in] val Value to write
 *  \param[in] cbuff Pointer to the circular buffer structure
 * 	\return 1 if sucessfull, 0 if the buffer is full
 */
uint8_t CircularBuffer_WriteBuffer (uint8_t val, CircularBuffer_buff_t* cbuff)
{
    if (cbuff->firstWrite)
    {
        cbuff->buffer[cbuff->tail] = val;
        cbuff->tail++;
        cbuff->firstWrite = 0;
    }
    else
    {
        if (((cbuff->tail + 1) % CIRCULAR_BUFFER_SIZE) != cbuff->head)
        {
            cbuff->buffer[cbuff->tail] = val;
            cbuff->tail = (cbuff->tail + 1) % CIRCULAR_BUFFER_SIZE;
        }
        else
        {
            return 0;    // ERROR (BUFFER OVERRIDE)
        }
    }

    return 1;
}

/** \fn BYTE CircularBuffer_ReadBuffer (BYTE* retval, CircularBuffer_buff_t* cbuff)
 *  \brief This function reads a byte from the circular buffer pointed by cbuff to the char variable pointed by retval, if the buffer is not empty
 *  \param[out] retval Pointer to the variable where will be written the value read from the buffer
 *  \param[in] cbuff Pointer to the circular buffer structure
 * 	\return 1 if sucessfull, 0 if the buffer is empty
 */
uint8_t CircularBuffer_ReadBuffer (uint8_t* retval, CircularBuffer_buff_t* cbuff)
{
    if (cbuff->head == cbuff->tail)
    {
        return 0;    // ERROR (EMPTY BUFFER)
    }
    else
    {
        *retval = cbuff->buffer[cbuff->head];
        cbuff->head = (cbuff->head + 1) % CIRCULAR_BUFFER_SIZE;
        return 1;
    }
}

/** \fn WORD CircularBuffer_StoredBytes (CircularBuffer_buff_t* cbuff)
 *  \brief This function returns the number of elements stored in the circular buffer pointed by cbuff
 *  \param[in] cbuff Pointer to the circular buffer structure
 * 	\return Number of stored bytes
 */
uint16_t CircularBuffer_StoredBytes (CircularBuffer_buff_t* cbuff)
{
    if (cbuff->tail >= cbuff->head)
    {
        return (cbuff->tail - cbuff->head);
    }
    else
    {
        return (CIRCULAR_BUFFER_SIZE - cbuff->head + cbuff->tail);
    }
}
