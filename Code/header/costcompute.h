using namespace std;

int cost_compute(int [10][10],int,int [][2]);
void copy(int, int [10][10], int [][10][10],int);

void copy(int i, int temp[10][10],int time_table[][10][10],int total_subjects){
    int j,k;
    for(j=0;j<total_subjects;j++){
        for(k=0;k<6;k++){
            time_table[i][j][k]=temp[j][k];
        }
    }

}

int cost_compute(int temp[10][10],int total_subjects,int data[][2]){
    int cost=0,i,j,k;
    int rows =  class_per_day(data,total_subjects);
    for(i=0;i<6;i++){
        for(j=0;j<rows;j++){
            for(k=j+1;k<rows;k++){
                if(temp[j][i]==temp[k][i]){
                    cost+=2;
                }
            }
        }
    }
    for(i=0;i<rows;i++){
        for(j=0;j<6;j++){
            for(k=j+1;k<6;k++){
                if(temp[i][j]==temp[i][k]){
                    if(temp[i][j]!=0){
                       cost+=1;
                    }
                }
            }
        }
    }
    return cost;
}