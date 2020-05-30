using namespace std;

void repeat_same_hour(int [][10],int [][2],int,string [][10],string [][10]);
int repeat_same_hour_check(int [][10],int [][2], int );

int repeat_same_hour_check(int temp[][10],int data[][2], int total_subjects){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	for(i=0;i<rows-1;i++){
		for(j=0;j<6;j++){
			for(k=j+1;k<6;k++){
				if(temp[i][j]==temp[i][k]){
					return 1;
				}
			}
		}
	}
	return 0;
}

void repeat_same_hour(int temp[][10],int data[][2], int total_subjects,string temp_name[][10],string teacher_name[][10]){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	string stempo,ttempo;			//stempo----> subject temporary   and  ttempo----> teacher temporary
	for(i=0;i<rows-1;i++){
		for(j=0;j<6;j++){
			for(k=j+1;k<6;k++){
				if(temp[i][j]==temp[i][k]){
					for(l=0;l<rows;l++){
						if(l!=k){
							if(temp[i][j]!=temp[l][k]){
								tempo=temp[i][j];
								stempo=temp_name[i][j];
								ttempo=teacher_name[i][j];
								
								temp[i][j]=temp[l][k];
								temp_name[i][j]=temp_name[l][k];
								teacher_name[i][j]=teacher_name[l][k];

								temp[l][k]=tempo;
								temp_name[l][k]=stempo;
								teacher_name[l][k]=ttempo;
							}
						}
					}
				}
			}
		}
	}
}
