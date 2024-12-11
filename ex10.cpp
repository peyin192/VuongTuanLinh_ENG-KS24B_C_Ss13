#include<stdio.h>
void addAllItem(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("phan tu thu arr[%d] co gia tri: ",i);
        scanf("%d", &arr[i]);
    }
}


void showItem(int arr[], int size){
    for(int i=0; i<size; i++){
        printf("phan tu arr[%d] co gia tri: %d \n", i, arr[i]);
    }
}


void addIem(int arr[], int *size, int index, int item){
    if(index>=0 && index< *size){
        for(int i= *size -1; i>= index; i--){
            arr[i+1] = arr[i];
            printf(" %d\n", i);
        }
        arr[index]= item;
        *size= *size+1;
    }else if(index == *size){
        arr[index]= item;
        *size=*size+1;
    }else if(index> *size){
        for(int i=*size; i<index; i++){
            arr[i]=0;
        }
        arr[index-1]= item;
        *size= index;
    }else{
        printf("vi tri khong hop le \n");
    }
}



void fixItem(int index, int item, int size, int arr[]){
    if(index >= 0 && index < size){
        arr[index]= item;
    }
}


void deleteItem(int index, int *size, int arr[]){
    if(index<0){
        printf("vi tri ban nhap khong hop le \n");
    }else{
        for(int i= index; i< *size; i++){
            arr[i]= arr[i+1];
        }
    }
    *size= *size-1;
}


void increase(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j = 0; j< size -1-i; j++){
            if(arr[j]> arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}


void reduce(int arr[], int size){
    for(int i=0; i<size-1; i++){
        for(int j = 0; j< size -1-i; j++){
            if(arr[j]< arr[j+1]){
                int temp= arr[j];
                arr[j]= arr[j+1];
                arr[j+1]= temp;
            }
        }
    }
}


void linearSearch(int arr[], int size, int item){
    int count=0;
    for(int i=0; i<size; i++){
        if(item == arr[i]){
            printf("Phan tu %d o vi tri arr[%d] \n", item, i);
            count++;
            break;
        }
    }
    if(count==0){
        printf("Phan tu %d khong co trong mang \n", item);
    }
}



void binarySearch(int arr[], int size, int item){
    increase(arr, size);
    int count=0;
    int start=0, end= size-1;
    while(start<=end){
        int mid= (start +end)/2;
        if(arr[mid]== item){
            printf("Phan tu %d o vi tri arr[%d] \n", item, mid);
            count=1;
            break;
        }else if(arr[mid]> item){
            end= mid-1;
        }else{
            start= mid+1;
        }
    }
    if(count==0){
        printf("Phan tu %d khong co trong mang \n", item);
    }
}


int main(){
    int flag=0;
    int arr[100]={0};
    int choose=0;
    int size=0,item=0,index =0;
    int letter=0;
    do{

        printf("1. them so luong phan tu va nhap gia tri \n");
        printf("2. In ra cac phan tu dang quan ly \n");
        printf("3. Them 1 phan tu vao vi tri chi dinh \n");
        printf("4. Sua 1 phan tu o vi tri chi dinh \n");
        printf("5. Xoa 1 phan tu tai vi tri chi dinh \n");
        printf("6. Sap xep phan tu \n");
        printf("7. Tim kiem phan tu nhap vao \n");
        printf("moi ban chon case: ");
        scanf("%d", &choose);
        switch(choose){
            case 1:
                flag =1;
                printf("Nhap so luong phan tu: ");
                scanf("%d", &size);
                addAllItem(arr, size);
                break;
            case 2:
                if(flag!=1){
                    printf("Chua khoi tao mang \n");
                }else{
                    showItem(arr, size);
                }
                break;
            case 3:
                if(flag!=1){
                    printf("Chua khoi tao mang \n");
                }else{
                    printf("Nhap gia tri muon them: ");
                    scanf("%d", &item);
                    printf("Nhap vi tri muon them: ");
                    scanf("%d", &index);
                    addIem(arr,&size,index, item);
                    showItem(arr, size);
                }
                break;
            case 4:
                if(flag!=1){
                    printf("Chua khoi tao mang \n");
                }else{
                    printf("Nhap vi tri muon sua: ");
                    scanf("%d", &index);
                    printf("Nhap gia tri phan tu moi: ");
                    scanf("%d", &item);
                    fixItem(index, item, size, arr);
                }
                break;
            case 5:
                if(flag!=1){
                    printf("Chua khoi tao mang\n");
                }else{
                    printf("Nhap vi tri muon xoa ");
                    scanf("%d", &index);
                    deleteItem(index, &size, arr);
                }
                break;
            case 6:
                if(flag!=1){
                    printf("Chua khoi tao mang \n");
                }else{
                    printf(" 1. Giam dan \n");
                    printf(" 2. Giam dan \n");
                    scanf("\t %d", &letter);
                    if(letter == 1 ){
                        increase(arr, size);
                    }
                    if(letter ==2){
                        reduce(arr, size);
                    }
                }
                break;
            case 7:
                if(flag!=1){
                    printf("Chua khoi tao mang \n");
                }else{
                    printf("Nhap phan tu muon tim: ");
                    scanf("%d", &item);
                    printf(" 1. Tim kiem tuyen tinh \n ");
                    printf(" 2. Tim kiem nhi phan \n ");
                    scanf("\t %d", &letter);
                    if(letter ==1 ){
                        linearSearch(arr, size, item);
                    }
                    if(letter==2){
                        
                    }
                }
                break;
            case 8:
                break;
            default:
                printf("Lua chon khong co trong MENU \n");
        }
    }while(choose!=8);
    return 0;
}
