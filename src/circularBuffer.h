#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H
void buf_Create(int *bufAddress);
void buf_Insert(int PID);
void buf_Remove();
int buf_Read();
#endif // CIRCULARBUFFER_H
