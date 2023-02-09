#include "排序.h"
void print(elementType *data,int count){
    for(int i = 0;i<count;i++){
        cout<<data[i]<<"  --->  ";
        
    }
    cout<<endl;
}
void SortUtils::chaRuSort(elementType *data,int count){
    cout<<"插入排序"<<endl;
    int temp;
    int i,j;
    for(i=1;i<count;i++){
        if(data[i]<data[i-1]){
            temp=data[i];
            for(j=i-1;temp<data[j]&&j>=0;j--){
                data[j+1]=data[j];
            }
            data[j+1]=temp;
        }
    }
    print(data, count);
}

void SortUtils::xiErSort(elementType *data, int count){
    cout<<"希尔排序"<<endl;
    int increment = count;
    int temp;
    int i,j;
    do{
        increment=increment/2;
        for(i = increment;i<count;i++){
            if(data[i]<data[i-increment]){
                temp=data[i];
                for(j=i-increment;temp<data[j]&&j>=0;j=j-increment){
                    data[j+increment]=data[j];
                }
                data[j+increment]=temp;
            }
            
        }
        
    }while(increment>1);//当increment到达1的时候，其实说明已经拍完了
    print(data, count);
}

void SortUtils::xuanZeSort(elementType *data, int count){
    cout<<"选择排序"<<endl;
    int i,j;
    int min;
    for(i = 0;i<count;i++){
        min=i;
        for(j=i+1;j<count;j++){
            if(data[j]<data[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp = data[min];
            data[min] = data[i];
            data[i] = temp;
        }
        
    }
    print(data,count);
}

void adjustHeap(elementType *data, int count,int i ){
    //i为当前节点的下标
    int large = i;
    int lson = i*2+1;
    int rson = i*2+2;
    if(lson<count&&data[lson]>data[large]){
        large = lson;
        
    }
    if(rson<count&&data[rson]>data[large]){
        large =  rson;
    }
    
    if(large!=i){
        int temp = data[large];
        data[large] = data[i];
        data[i]= temp;
        adjustHeap(data, count, large);
    }
    
    
}
void SortUtils::duiSort(elementType *data, int count){
    cout<<"堆排序"<<endl;
    //将数组建立为大顶堆
    for(int i = (count-1)/2;i>=0;i--){
        adjustHeap(data, count, i);
    }
    //排序
    for(int i = count-1;i>0;i--){
        int temp = data[i];
        data[i]=data[0];
        data[0]=temp;
        
        adjustHeap(data, i, 0);
    }
    print(data, count);
}


void SortUtils::maoPaoSort(elementType *data, int count){
    bool flag = true;
    
    for(int i = 0;i<count&&flag;i++){
        flag = false;
        for(int j=1;j<count-i;j++){
            if(data[j]<data[j-1]){
                int temp = data[j];
                data[j] = data[j-1];
                data[j-1]=temp;
                flag = true;
            }
        }
    }
    print(data, count);
}

int partition(elementType *list,int low,int high){
    int pivotKey;
    pivotKey = list[low];
    while(low<high)
    {
        while(low<high&&list[high]>=pivotKey)
        {
            high--;
        }
        swap(list[low],list[high]);
        while(low<high&&list[low]<=pivotKey)
        {
            low++;
        }
        swap(list[low],list[high]);
    }
    return low;

}
    
    
void diGui(elementType *data,int low,int high){
    if(low<high){
        int mid = partition(data, low, high);
        diGui(data, low, mid-1);
        diGui(data, mid+1, high);
    }
}

void SortUtils::kuaiSuSort(elementType *data, int count){
    cout<<"快速排序"<<endl;
    diGui(data, 0, count-1);
    print(data, count);
}


void merge(elementType *data,int start,int mid,int end){
    const int len1 = mid - start+1;
    const int len2 = end - mid;
    const int len =end - start +1;
    int i,j,k;
    int* front = new int[len1];
    int* back  = new int[len2];
    for(i=0;i<len1;i++){
        front[i] = data[start+i];
    }
    for(i = 0;i<len2;i++){
        back[i]=data[mid+i+1];
    }
    
    for(i=0,j=0,k=start;i<len1&&j<len2&&k<end;k++){
        if(front[i]<back[j]){
            data[k]=front[i];
            i++;
        }else{
            data[k]=back[j];
            j++;
        }
    }
    while (i<len1) {
        data[k++]=front[i++];
    }
    while(j<len2){
        data[k++]=back[j++];
    }
}
void diGui2(elementType *data,int start,int end){
    if(start<end){
        int mid = (start + end)/2;
        diGui2(data, 0, mid);
        diGui2(data,mid+1,end);
        merge(data, start, mid, end);
    }
}
void SortUtils::guiBingSort(elementType *data, int count){
    cout<<"归并排序"<<endl;
    diGui2(data,0,count-1);
    print(data,count);
}

int main(){
    int data[]={2,3,51,1,5,67,845,7,5,8,12};
    SortUtils sort;
    sort.guiBingSort(data,11);
}
