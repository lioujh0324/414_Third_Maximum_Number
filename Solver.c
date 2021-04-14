

int thirdMax(int* nums, int numsSize)
{
    short int collect=1;
    int ThirdMax[3];
    ThirdMax[0]=*nums;
    nums++;
    numsSize--;
    while(collect!=3)
    {
        if(!numsSize)
            return ThirdMax[0];
        if(collect==1)
        {
            if(ThirdMax[0]>*nums)
            {
                ThirdMax[1]=*nums;
                collect++;
            }
            else if(ThirdMax[0]<*nums)
            {
                ThirdMax[1]=ThirdMax[0];
                ThirdMax[0]=*nums;
                collect++;
            }
        }
        if(collect==2)
        {
            if(ThirdMax[0]<*nums)
            {
                ThirdMax[2]=ThirdMax[1];
                ThirdMax[1]=ThirdMax[0];
                ThirdMax[0]=*nums;
                collect++;
            }
            else if(ThirdMax[1]<*nums && ThirdMax[0]>*nums)
            {
                ThirdMax[2]=ThirdMax[1];
                ThirdMax[1]=*nums;
                collect++;
            }
            else if(ThirdMax[1]>*nums)
            {
                ThirdMax[2]=*nums;
                collect++;
            }
        }
        nums++;
        numsSize--;   
    }
    while(numsSize)
    {
        if(*nums<ThirdMax[1] && *nums>ThirdMax[2])
        {
            ThirdMax[2]=*nums;
        }
        else if(*nums>ThirdMax[1] && *nums<ThirdMax[0])
        {
            ThirdMax[2]=ThirdMax[1];
            ThirdMax[1]=*nums;
        }
        else if(*nums>ThirdMax[0])
        {
            ThirdMax[2]=ThirdMax[1];
            ThirdMax[1]=ThirdMax[0];
            ThirdMax[0]=*nums;
        }
        nums++;
        numsSize--;
    }
    return ThirdMax[2];
}
