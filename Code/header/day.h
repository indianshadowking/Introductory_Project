using namespace std;

int repeat_same_day_check(int [][10],int [][2], int );
void repeat_same_day(int [][10],int [][2],int,string [][10],string [][10]);

int repeat_same_day_check(int temp[][10],int data[][2], int total_subjects){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	for(i=0;i<6;i++){
		for(j=0;j<rows;j++){
			for(k=j+1;k<rows;k++){
				if(temp[j][i]==temp[k][i]){
					return 1;
				}
			}
		}
	}
	return 0;
}

void repeat_same_day(int temp[][10],int data[][2], int total_subjects,string temp_name[][10],string teacher_name[][10]){
	int rows =  class_per_day(data,total_subjects);  
	int i,j,k,l,tempo;
	string stempo,ttempo;				//stempo----> subject temporary   and  ttempo----> teacher temporary
	for(i=0;i<6;i++){
		for(j=0;j<rows;j++){
			for(k=j+1;k<rows;k++){
				if(temp[j][i]==temp[k][i]){
					for(l=0;l<6;l++){
						if(i!=l){
							if(temp[k][i]!=temp[k][l]){
								tempo=temp[k][i];
								stempo=temp_name[k][i];
								ttempo=teacher_name[k][i];

								temp[k][i]=temp[k][l];
								temp_name[k][i]=temp_name[k][l];
								teacher_name[k][i]=teacher_name[k][l];

				
								temp[k][l]=tempo;
								temp_name[k][l]=stempo;
								teacher_name[k][l]=ttempo;
							}
						}
					}
				}
			}
		}
	}
}