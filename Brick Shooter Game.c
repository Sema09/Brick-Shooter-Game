#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int z,t,es,ma,ze,te,zet,tet,row,column,ne,wa,condition,create,funcnumber;
int xcord,ycord,loop =1,lo=0,a=1,u,shooterx,shootery,integer;
float xcor,ycor;
char string2[100],col;
void func(char list[ze][te],char array[zet][tet],int borxx,int boryy,float shootx,float shooty,float newhox,float newhoy,int poin);
void function(char arr[z][t],int borx, int bory);
int check(char arrayy[row][column],int borxxx,int boryyy,char col,int shy,int shx);
int main(void){
    scanf("%[^\n]%*c",string2);
    xcord= atoi(string2);
    ycord = atoi(string2+2);
    z=ycord;
    t=xcord;
    char ar[ycord][xcord];
    for(int j=0;j<ycord;j++){
        if(j==0){
            for(int a=0;a<xcord;a++){
                if(a==(xcord-1)){
                    ar[j][a]='|';
                    break;    
                }
                if(a==0){
                    ar[j][a]='|';
                    continue;
                }
                else{
                    ar[j][a]='~';
                    continue;
                }
            }
        }
        else{
            for(int m=0;m<xcord;m++){
                if (m==0){
                    ar[j][m]='|';
                    continue;
                }
                if(m==(xcord-2)){
                    ar[j][m]=' ';
                    ar[j][m+1]='|';
                    break;
                }
                else{
                    ar[j][m]=' ';
                    continue;
                }
            }
        }
    }
    function(ar,xcord,ycord);
    return 0;
}

void function(char arr[z][t],int borx, int bory){
    int lop=1,length,w=1,coun=1,shotx,shoty;
    char string[100];
    ze=bory;
    zet=bory;
    te=borx;
    tet=borx;
    while(lop==1){
        scanf("%[^\n]%*c",string);
        length=strlen(string);
        if(string[0]=='e' && string[1]=='n' && string[2]=='d' && string[3]=='\0'){
            scanf("%d %d", &shotx, &shoty);
            arr[shoty][shotx]='_';
            for(int r=0;r<bory;r++) {
                for(int t=0;t<borx;t++){
                    if(t==(borx-1)){
                        printf("%c\n",arr[r][t]);
                    }
                    else{
                        printf("%c",arr[r][t]);
                    }
                }
            }
            printf("\n");
            func(arr,arr,borx,bory,(float)shotx,(float)shoty,(float)shotx,(float)shoty,0);
            lop+=1;
            break;
        }
        else{
            for(int p=0;p<length;p++){
                if(string[p]=='R'){
                    arr[coun][p+1]='R';
                }
                else if(string[p]=='G'){
                    arr[coun][p+1]='G';
                }
                else if(string[p]=='B'){
                    arr[coun][p+1]='B';
                }
                else if(string[p]=='Y'){
                    arr[coun][p+1]='Y';
                }
                else if(string[p]==' '){
                    arr[coun][p+1]=' ';
                }
            }
            coun++;
        } 
    }
}
void func(char list[ze][te],char array[zet][tet],int borxx,int boryy,float shootx,float shooty,float newhox,float newhoy,int poin){
    float movx,movy,movxx,movyy,lop=1.0,lop2=1.0;
    char color,string[100];
    int count=0,sum =0,points,defin=0,checking,chec=0;
    row=boryy;
    column=borxx;
    movxx=newhox;
    movyy = newhoy;
    points=poin;
    while(1){
        for(int r=1;r<boryy;r++) {
            for(int t=1;t<borxx;t++){
                if(list[r][t]==' '){
                    defin+=1;
                }
                else if(list[r][t]=='_');
            }
        }
        if(defin==((borxx*boryy)-(2*boryy)-(borxx-2)-1)){
            printf("Game is over. Your score is %d!",points);
	    defin=1;
            exit(0);
        }
        else break;
    }
    while(1){
	if(defin==1){
	    scanf("%s",string);
	    break;
	} 
        scanf(" %c*",&color);
        if(color=='q'){
            printf("Game is over. Your score is %d!",points);
            exit(0);
        }
        else{
            scanf("%f %f",&movx,&movy);
            if(movx<0.0 && movy<0.0){
                movx=movx*-1.0;
                movy=movy*-1.0;
                movx=movx/movy;
                movy=movy/movy;
                if(movx>(shootx-1.0) || movx>(float)borxx-shootx-1.0){
                    movy=movy/movx;
                    movx=movx/movx;
                }
	        else if(movx<(shootx-1.0) || movx<(float)borxx-shootx-1.0){
		    if(movx>movy){
			movy=movy/movx;
			movx=movx/movx;
		    }
		}
                movx=movx*-1.0;
                movy=movy*-1.0;
            }
            else if(movx>0.0 && movy<0.0){
                movy=movy*-1.0;
                movx=movx/movy;
                movy=movy/movy;
                if(movx>(shootx-1.0) || movx>(float)borxx-shootx-1.0){
                    movy=movy/movx;
                    movx=movx/movx;
                }
		else if(movx<(shootx-1.0) || movx<(float)borxx-shootx-1.0){
		    if(movx>movy){
			movy=movy/movx;
			movx=movx/movx;
		    }
		}
                movy=movy*-1.0;
            }
            else if(movx==0.0 && movy<0.0){
                movy=movy*-1.0;
                movx=movx/movy;
                movy=movy/movy;
                movy=movy*-1.0;
            }
            while(1){
                shootx+=movx;
                shooty+=movy;
                for(float lop=1.0;lop<(float)boryy ;lop=lop+1.0){
                    for(float lop2=1.0;lop2<(float)borxx;lop2=lop2+1.0){
                        if(shooty==lop && shootx==lop2){
                            if(list[(int)shooty-1][(int)shootx]=='~' || list[(int)shooty-1][(int)shootx]=='Y' || list[(int)shooty-1][(int)shootx]=='B' || list[(int)shooty-1][(int)shootx]=='R' || list[(int)shooty-1][(int)shootx]=='G'){
                                list[(int)shooty][(int)shootx]=color;
                                checking = check(list,borxx,boryy,color,(int)shooty,(int)shootx);
                                if(checking>4){
                                    for(int r=(int)shooty-1;r<(int)shooty+2;r++) {
                                        for(int t=(int)shootx-1;t<(int)shootx+2;t++){
                                            if(list[r][t]==color){
                                                list[r][t]=' ';
                                            }
                                        }
                                    }
                                    points+=100;
                                    printf("You got %d points. Score: %d\n",100,points);
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                    
                                }
                                else if(checking>2 && checking<5){
                                    for(int r=(int)shooty-1;r<(int)shooty+2;r++) {
                                        for(int t=(int)shootx-1;t<(int)shootx+2;t++){
                                            if(list[r][t]==color){
                                                list[r][t]=' ';
                                            }
                                        }
                                    }
                                    points+=(checking*10);
                                    printf("You got %d points. Score: %d\n",checking*10,points);
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                    

                                }
                                else if(checking<3){
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                }
                            }
                            else if(list[(int)shooty][(int)shootx-1]=='|' || list[(int)shooty][(int)shootx]=='|'){
                                if(movx>0.0 && (int)shootx==borxx-1){
                                    chec=10;
                                    break;
                                }
                                else if(movx<0.0 && (int)shootx==1){
                                    chec=10;
                                    break;
                                }
                            }
                        }
                        else if(shooty==lop && shootx!=lop2){
                            if(list[(int)shooty-1][(int)shootx]=='~' || list[(int)shooty-1][(int)shootx]=='Y' || list[(int)shooty-1][(int)shootx]=='B' || list[(int)shooty-1][(int)shootx]=='R' || list[(int)shooty-1][(int)shootx]=='G'){
                                list[(int)shooty][(int)shootx]=color;
                                checking=check(list,column,row,color,(int)shooty,(int)shootx);
                                if(checking>4){
                                    for(int r=(int)shooty-1;r<(int)shooty+2;r++) {
                                        for(int t=(int)shootx-1;t<(int)shootx+2;t++){
                                            if(list[r][t]==color){
                                                list[r][t]=' ';
                                            }
                                        }
                                    }
                                    points+=100;
                                    printf("You got %d points. Score: %d\n",100,points);
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                    
                                }
                                else if(checking>2 && checking<5){
                                    for(int r=(int)shooty-1;r<(int)shooty+2;r++) {
                                        for(int t=(int)shootx-1;t<(int)shootx+2;t++){
                                            if(list[r][t]==color){
                                                list[r][t]=' ';
                                            }
                                        }
                                    }
                                    points+=(checking*10);
                                    printf("You got %d points. Score: %d\n",checking*10,points);
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                    

                                }
                                else if(checking<3){
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                }
                                
                            }
                            else if(list[(int)shooty][(int)shootx-1]=='|' || list[(int)shooty][(int)shootx]=='|'){
                                if(movx>0.0 && (int)shootx==borxx-1){
                                    chec=10;
                                    break;
                                }
                                else if(movx<0.0 && (int)shootx==1){
                                    chec=10;
                                    break;
                                }
                            }
                        }
                        else if(shooty!=lop && shootx==lop2){
                            if(list[(int)shooty][(int)shootx]=='~' || list[(int)shooty][(int)shootx]=='Y' || list[(int)shooty][(int)shootx]=='B' || list[(int)shooty][(int)shootx]=='R' || list[(int)shooty][(int)shootx]=='G'){
                                if(movx<0.0){
                                    list[(int)shooty+1][(int)shootx]=color;
                                    checking=check(list,column,row,color,(int)shooty+1,((int)shootx));
                                }
                                else{
                                    list[(int)shooty][(int)shootx-1]=color;
                                    checking=check(list,column,row,color,(int)shooty,((int)shootx-1));
                                }
                                if(checking>4){
                                    for(int r=(int)shooty-1;r<(int)shooty+2;r++) {
                                        for(int t=(int)shootx-1;t<(int)shootx+2;t++){
                                            if(list[r][t]==color){
                                                list[r][t]=' ';
                                            }
                                        }
                                    }
                                    points+=100;
                                    printf("You got %d points. Score: %d\n",100,points);
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                    
                                }
                                else if(checking>2 && checking<5){
                                    for(int r=(int)shooty-1;r<(int)shooty+2;r++) {
                                        for(int t=(int)shootx-1;t<(int)shootx+2;t++){
                                            if(list[r][t]==color){
                                                list[r][t]=' ';
                                            }
                                        }
                                    }
                                    points+=(checking*10);
                                    printf("You got %d points. Score: %d\n",checking*10,points);
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                    

                                }
                                else if(checking<3){
                                    for(int r=0;r<boryy;r++) {
                                        for(int t=0;t<borxx;t++){
                                            if(t==(borxx-1)){
                                                printf("%c\n",list[r][t]);
                                            }
                                            else{
                                                printf("%c",list[r][t]);
                                            }
                                        }
                                    }
                                    printf("\n");
                                    func(list,list,column,row,movxx,movyy,movxx,movyy,points);
                                }
                                
                            }
                            else if(list[(int)shooty][(int)shootx-1]=='|' || list[(int)shooty][(int)shootx]=='|'){
                                if(movx>0.0 && (int)shootx==borxx-1){
                                    chec=10;
                                    break;
                                }
                                else if(movx<0.0 && (int)shootx==1){
                                    chec=10;
                                    break;
                                }
                            }
                        }
                    }
                }
                if(chec==10){
                    movx=movx*-1.0;
                    chec=0;
                    continue;
                }
                
            } 
        }
    }
    exit(0);
}

int check(char arrayy[row][column],int borxxx,int boryyy,char col,int shy,int shx){
    int es,ti;
    es=boryyy;
    ti=borxxx;
    int count = 0,points;
    int sum =0;
    char neww[es][ti];
    for(int r=0;r<boryyy;r++) {
        for(int t=0;t<borxxx;t++){
           neww[r][t]=arrayy[r][t];
        }
    }
    for(int se =0;se<8;se++){
        if(neww[shy][shx-1]==col){
            neww[shy][shx-1]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy-1][shx-1]==col){
            neww[shy-1][shx-1]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy-1][shx]==col){
            neww[shy-1][shx]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy-1][shx+1]==col){
            neww[shy-1][shx+1]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy][shx+1]==col){
            neww[shy][shx+1]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy+1][shx]==col){
            neww[shy+1][shx]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy+1][shx-1]==col){
            neww[shy+1][shx-1]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
        else if(neww[shy+1][shx+1]==col){
            neww[shy+1][shx+1]=' ';
            neww[shy][shx]=' ';
            count+=1;
        }
    }
    count+=1;
    if(count==3){
        points=30;
        sum+=30;
        return 3;
    }
    else if(count==4){
        points=40;
        sum+=40;
        return 4;
    }
    else if(count>4){
        points=100;
        sum+=100;
        return count;
    }
    else{
        return count;
    } 
}
