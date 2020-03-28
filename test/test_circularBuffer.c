#include "unity.h"

#include "circularBuffer.h"

#define SIZE 5

static int buf[SIZE];
void setUp(void)
{
	buf_Create(buf);
}

void tearDown(void)
{
}

void test_bufCreate(void)
{
	int buf[SIZE] = {1, 1, 1, 1, 1};
	buf_Create(buf);
	for(int i = 0; i < SIZE; i++)
	{
		TEST_ASSERT_EQUAL(0, buf[i]);
	}
}

void test_bufInsertOne(void)
{
	buf_Insert(1);
	for (int i = 0; i < SIZE-1; i++)
	{
		TEST_ASSERT_EQUAL(0, buf[i]);
	}
	TEST_ASSERT_EQUAL(1, buf[4]);
}

void test_bufInsertTwo(void)
{
	buf_Insert(1);
	buf_Insert(2);
	TEST_ASSERT_EQUAL(1, buf[3]);
	TEST_ASSERT_EQUAL(2, buf[4]);
	for (int i = 0; i < SIZE-2; i++)
	{
		TEST_ASSERT_EQUAL(0, buf[i]);
	}
}

void test_bufRemove(void)
{
	buf_Insert(1);
	buf_Insert(2);
	buf_Remove();
	TEST_ASSERT_EQUAL(0, buf[3]);
	TEST_ASSERT_EQUAL(2, buf[4]);
	for(int i = 0; i < SIZE-2; i++)
	{
		TEST_ASSERT_EQUAL(0, buf[i]);
	}
}

void test_bufRead(void)
{
	buf_Insert(1);
	buf_Insert(2);
	int fifo = buf_Read();
	TEST_ASSERT_EQUAL(1, fifo);
	buf_Remove();
	fifo = buf_Read();
	TEST_ASSERT_EQUAL(2, fifo);
}

void test_bufFull(void)
{
	for (int i = 0; i < SIZE; i++)
	{
		buf_Insert(10);
	}
	buf_Insert(9);
	for (int i = 0; i < SIZE; i++)
	{
		TEST_ASSERT_EQUAL(10, buf[i]);
	}

}











