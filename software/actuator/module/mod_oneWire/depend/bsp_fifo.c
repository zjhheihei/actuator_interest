
#include ".\SnailDataTypedef.h"
#include ".\SnailMacro.h"
#include "intrinsics.h"


typedef struct
{
    volatile INT16U    in;         //输入索引
    volatile INT16U    out;        //输出索引
    volatile INT16U    count;      //字节数
    INT16U             size;       //FIFO大小
    INT8U              *ptBuf;
}fifo_t;

static fifo_t fifo;

void bsp_fifo_init(INT8U *bufAddr,INT16U maxSize)
{
    fifo.in    = 0;
    fifo.out   = 0;
    fifo.count = 0;
    fifo.ptBuf = bufAddr;
    fifo.size  = maxSize;
    
}

BOOLEAN bsp_fifo_wirte(INT8U *ptDat,INT16U wirteLength)
{
    INT8U i = 0;
    for(;i < wirteLength; i++)
    {
        if(fifo.count < fifo.size)
        {
            fifo.ptBuf[fifo.in] = ptDat[i];
            fifo.in++;
            fifo.count++;
            if(fifo.in >= fifo.size)
            {
                fifo.in = 0;
            }
        }
        else
        {
            return BN_FALSE;
        }
    } 
    return BN_TRUE;
}

BOOLEAN bsp_fifo_read(INT8U *_out_ptDat,INT16U readLenth)
{  
    INT8U i = 0;
    for(;i < readLenth; i++)
    {
        if(fifo.count)
        {
            _out_ptDat[i] = fifo.ptBuf[fifo.out];
            fifo.count--;
            fifo.out++;
            if(fifo.out >= fifo.size)
            {
                fifo.out = 0;
            }
        }
        else
        {
            return BN_FALSE;
        }       
    }  
    return BN_TRUE;
}

INT16U bsp_fifo_get_count(void)
{
    return fifo.count;
}

void bsp_fifo_reset(void)
{
    fifo.count = 0;
    fifo.in    = 0;
    fifo.out   = 0;
}

