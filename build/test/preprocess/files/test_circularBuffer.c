#include "build/temp/_test_circularBuffer.c"
#include "src/circularBuffer.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.29.1/vendor/unity/src/unity.h"








static int buf[5];

void setUp(void)

{

 buf_Create(buf);

}



void tearDown(void)

{

}



void test_bufCreate(void)

{

 int buf[5] = {1, 1, 1, 1, 1};

 buf_Create(buf);

 for(int i = 0; i < 5; i++)

 {

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buf[i])), (

 ((void *)0)

 ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_INT);

 }

}



void test_bufInsertOne(void)

{

 buf_Insert(1);

 for (int i = 0; i < 5 -1; i++)

 {

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buf[i])), (

 ((void *)0)

 ), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);

 }

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buf[4])), (

((void *)0)

), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_INT);

}



void test_bufInsertTwo(void)

{

 buf_Insert(1);

 buf_Insert(2);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((buf[3])), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((buf[4])), (

((void *)0)

), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_INT);

 for (int i = 0; i < 5 -2; i++)

 {

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buf[i])), (

 ((void *)0)

 ), (UNITY_UINT)(45), UNITY_DISPLAY_STYLE_INT);

 }

}



void test_bufRemove(void)

{

 buf_Insert(1);

 buf_Insert(2);

 buf_Remove();

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buf[3])), (

((void *)0)

), (UNITY_UINT)(54), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((buf[4])), (

((void *)0)

), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

 for(int i = 0; i < 5 -2; i++)

 {

  UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((buf[i])), (

 ((void *)0)

 ), (UNITY_UINT)(58), UNITY_DISPLAY_STYLE_INT);

 }

}



void test_bufRead(void)

{

 buf_Insert(1);

 buf_Insert(2);

 int fifo = buf_Read();

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((fifo)), (

((void *)0)

), (UNITY_UINT)(67), UNITY_DISPLAY_STYLE_INT);

 buf_Remove();

 fifo = buf_Read();

 UnityAssertEqualNumber((UNITY_INT)((2)), (UNITY_INT)((fifo)), (

((void *)0)

), (UNITY_UINT)(70), UNITY_DISPLAY_STYLE_INT);

}



void test_bufFull(void)

{

 for (int i = 0; i < 5; i++)

 {

  buf_Insert(10);

 }

 buf_Insert(9);

 for (int i = 0; i < 5; i++)

 {

  UnityAssertEqualNumber((UNITY_INT)((10)), (UNITY_INT)((buf[i])), (

 ((void *)0)

 ), (UNITY_UINT)(82), UNITY_DISPLAY_STYLE_INT);

 }



}
