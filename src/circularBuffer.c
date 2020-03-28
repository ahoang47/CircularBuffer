#include "circularBuffer.h"
#define SIZE 5
static int *internalBuf;

void buf_Create(int *bufAddress)
{
	internalBuf = bufAddress;
	for(int i = 0; i < SIZE; i++)
	{
		internalBuf[i] = 0;
	}
}

void buf_Insert(int PID)
{
	if(internalBuf[0] == 0)
	{
		for(int i = 0; i < SIZE-1; i++)
		{
			internalBuf[i] = internalBuf[i+1];
		}
		internalBuf[SIZE-1] = PID;
	}
}

void buf_Remove()
{
	for(int i = 0; i < SIZE; i++)
	{
		if(internalBuf[i] != 0)
		{
			internalBuf[i] = 0;
			i = SIZE;
		}
	}
}

int buf_Read()
{
	int rValue;
	for(int i = 0; i < SIZE; i++)
	{
		if(internalBuf[i] != 0)
		{
			rValue = internalBuf[i];
			i = SIZE;	
		}
	}
	return rValue;
}
