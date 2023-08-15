#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint32;
typedef signed int sint32;

sint32 Arr[10] = {1, 11, 22, 33, 44, 55, 66, 77, 88, 99};

sint32 BinarySearchAlgorithm_1(sint32 ArrData[], uint32 S_Index, uint32 E_Index, uint32 Req_Val);
sint32 BinarySearchAlgorithm_2(sint32 ArrData[], uint32 S_Index, uint32 E_Index, uint32 Req_Val);

int main()
{
    sint32 Ret = 0;
    Ret = BinarySearchAlgorithm_1(Arr, 0, 9, 3); printf("%i\n", Ret);
    Ret = BinarySearchAlgorithm_1(Arr, 0, 9, 33); printf("%i\n", Ret);
    Ret = BinarySearchAlgorithm_1(Arr, 0, 9, 22); printf("%i\n", Ret);
    Ret = BinarySearchAlgorithm_1(Arr, 0, 9, 77); printf("%i\n", Ret);
    printf("=======================\n");
    Ret = BinarySearchAlgorithm_2(Arr, 0, 9, 3); printf("%i\n", Ret);
    Ret = BinarySearchAlgorithm_2(Arr, 0, 9, 33); printf("%i\n", Ret);
    Ret = BinarySearchAlgorithm_2(Arr, 0, 9, 22); printf("%i\n", Ret);
    Ret = BinarySearchAlgorithm_2(Arr, 0, 9, 77); printf("%i\n", Ret);
    
    return 0;
}
sint32 BinarySearchAlgorithm_1(sint32 ArrData[], uint32 S_Index, uint32 E_Index, uint32 Req_Val)
{
    uint32 M_Index = 0;
    while (S_Index <= E_Index)
    {
        M_Index = S_Index + ((E_Index - S_Index) / 2);

        if (Req_Val == ArrData[M_Index])
        {
            return M_Index;
        }
        else if(Req_Val > ArrData[M_Index])
        {
            S_Index = M_Index + 1;
        }
        else
        {
            E_Index = M_Index - 1;
        }
    }
    return -1;
}
sint32 BinarySearchAlgorithm_2(sint32 ArrData[], uint32 S_Index, uint32 E_Index, uint32 Req_Val)
{
    uint32 M_Index = 0;
    while (S_Index <= E_Index)
    {
        M_Index = S_Index + ((E_Index - S_Index) / 2);

        if (Req_Val == ArrData[M_Index])
        {
            return M_Index;
        }
        else if(Req_Val > ArrData[M_Index])
        {
           return BinarySearchAlgorithm_2(ArrData, M_Index + 1, E_Index, Req_Val);
        }
        else
        {
            return  BinarySearchAlgorithm_2(ArrData, S_Index, M_Index - 1, Req_Val);
            
        }
    }
    return -1;
}