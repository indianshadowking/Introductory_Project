#include<iostream>
#include<iomanip>
using namespace std;

void getdata(int [][2],int);
void printdata(int [][2],int);
void filldata(int [][2],int [][7], int,int);
void print_table(int [][7],int);

int main(){
    int H=-1,M=0,i;
    while (!(H>0 && H<=25))
    {
    cout<<"Enter the number of Subjects(between 0 to 25): ";
    cin>>H;
    }
    int I[H][2];
    getdata(I,H);
    printdata(I,H);
    for(i=0;i<H;i++)
    M+=I[i][1];
    M=M/6+1;
    int T[6][7];
    filldata(I,T,M,H);
    print_table(T,M);
    return 0;
}

void getdata(int I[][2],int a){
    for(int i=0;i<a;i++){
        cout<<"Enter Subject Code: ";
        cin>>I[i][0];
        cout<<"Enter the number of credits: ";
        cin>>I[i][1];
    }
}

void printdata(int I[][2],int a){
    cout<<"SUBJECT_CODE \t CREDITS\n";
    for(int i=0;i<a;i++){
        cout<<setw(8)<<I[i][0]<<setw(13)<<I[i][1]<<endl;
    }
}

void filldata(int I[][2],int T[][7],int a,int h){
    int i,j,l=0,m=0;
    for(i=0;i<h;i++){
        for(j=0;j<I[i][1];j++){
            T[l][m]=I[i][0];
            m++;
            if(m>a){
                m=0;
                l++;
            }
        }
    }
}

void print_table(int T[][7],int a){
    int i,j;
    cout<<"Per1 Per2 Per3 Per4 Per5 Per6 Per7"<<endl;
    for(i=0;i<6;i++){
        for(j=0;j<a;j++){
            cout<<T[i][j]<<setw(5);
        }
        cout<<endl;
    }  
}