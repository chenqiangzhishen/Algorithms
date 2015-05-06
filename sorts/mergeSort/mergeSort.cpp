
#include<iostream>
using namespace std;

//sd - source data
//td - temp data, used to store the sorting data
void merge(int sd[], int td[], int beg, int mid, int end)
{
    if(beg<0 || end <0 || beg>=end)
        return;
    int i=beg, j=mid+1, k=beg;
    while(i!=mid+1 && j!=end+1)//note the last index
    {
        if(sd[i]<sd[j])
        {
            td[k++] = sd[i++];
        } else
        {
            td[k++] = sd[j++];
        }
    }
    while(i != mid+1)//note the last index
    {
        td[k++] = sd[i++];
    }
    while(j != end+1)//note the last index
    {
        td[k++] = sd[j++];
    }
    for(i=0; i<=end; ++i)//note the last index
    {
        sd[i] = td[i];
    }
}

void mergeSort(int sd[], int td[], int beg, int end)
{
    if(beg<0 || end <0 || beg>=end)
        return;
    int mid = beg + ((end-beg)>>1);
    mergeSort(sd, td,  beg, mid);
    mergeSort(sd, td, mid+1, end);
    merge(sd, td, beg, mid, end);
}



int main(void)
{
    int data[10] = {4, 1, 3, 6, 8, 9, 0, 2, 5, 7};
    int tempdata[10];
    mergeSort(data, tempdata, 0 ,9);
    for(int i=0; i<10; ++i)
    {
        cout<<data[i]<<(i != 9? "," : "\n");
    }
    return 0;
}





