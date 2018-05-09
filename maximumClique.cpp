#include <stdlib.h> 
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <GL/glu.h> // Thu vien cua OpenGL.

typedef unsigned char byte;
typedef unsigned long long ull;

using namespace std;
int Nmax = 10;
int ent_counter=0;

#define Nmax 64 // Set the grid size limit
byte N, count;
ull pik[Nmax],clique[Nmax],mask;

//Ve do thi.
#define scale 1.6f
#define num_scale 1.1f
#define PI2 6.2831853071
#define dp -5.0f

double dots[65][2];
// + Khoi tao doi tuong ve do thi.
void init_dots(){
    float dang=PI2/Nmax;
    float ang=PI2/4;
    for (int i=0; i<Nmax; i++){
        dots[i][0]=scale*cos(ang);
        dots[i][1]=scale*sin(ang);
        ang+=dang;
    }
    dots[Nmax][0]=dots[0][0];
    dots[Nmax][1]=dots[0][1];
}

// + Xu ly su kien ban phim.
void GLFWCALL handleKeypress(int key,int press) 
{
    switch (key) {
        case GLFW_KEY_ESC: 
            exit(0); // Thoat chuong trinh
        case GLFW_KEY_ENTER:
            ent_counter++;
    }
}

// + Xu ly man hinh window su dung OpenGL.
void GLFWCALL handleResize(int width,int height)
{
    //OpenGL thiet ke vi tri toa do tung diem cua do thi.
    glViewport( 0, 0, width, height );

    glMatrixMode( GL_PROJECTION ); 
    
    glLoadIdentity(); 
    gluPerspective( 45.0f,                      
                (GLfloat)width/(GLfloat)height, 
                 1.0f,                          
                100.0f );                       //
}

// + Khoi tao kich thuoc dung hinh cua so consolute cua windown.
void initializeRendering()
{
    glfwInit();
    init_dots();
     if( !glfwOpenWindow( 768, // Chieu rong window
                          768, // Chieu cao window
                          1,  
                          0,  
                          0,  
                          0,  
                          0,  
                          0, 
                          GLFW_WINDOW ) 
        ) 
    {
        glfwTerminate(); /

    }

    glfwSetWindowTitle("Clique finder");
    glfwSetWindowSizeCallback(handleResize); 
    glfwSetKeyCallback(handleKeypress); 
    glPointSize(7.0f);
}
// +Xu ly connext doi tuong diem cua do thi truy van OpenGL.
void connect_dots(int i, int j, bool color){
    if (color){
        glColor3f(0.0f, 0.0f, 0.0f);
    }
    else{
        glColor3f(1.0f, 0.0f, 0.0f);
    }
    glBegin(GL_LINES);
    glVertex3f( dots[i][0], dots[i][1], dp );
    glVertex3f( dots[j][0], dots[j][1], dp );
    glEnd();
}
//+ Xu ly ve vi tri cac diem cua do thi.
void draw_graph(){
    glLineWidth(0.5f);
    glColor3f(0.0f, 0.0f, 0.0f);
   
    for (int i=0; i<Nmax;i++){
        for (int j=0; j<Nmax; j++){
            connect_dots(i, j, true);
        }
        glBegin(GL_POINTS);
        if (i==0){
            glColor3f(0.0f, 1.0f, 0.7f);
        }
        else{
            glColor3f(0.0f, 0.0f, 0.0f);
        }
        glVertex3f(dots[i][0], dots[i][1], dp);
        glEnd();

    }
}

// +Ham quan trong trong OpenGL chay xu ly truy van cac ham ve va tinh toans maximum sclique.
void display()
{
    glClearColor( 1.0f, 1.0f, 1.0f, 0.0f ); 
    glClear( GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
    draw_graph();
    glfwSwapBuffers();

}
// +D Dem so luong bieu dien nhi phan cua mot so
byte number( ull x)
{
	byte i;
	ull single, ret;
	single=1;
	ret=0;
	for (i=0;i<Nmax;i++)
	{
		ret=ret+((x&single)>>i);
		single=single<<1;
	}
	return ret;
}
// + Dau ra N bit dau tien cua mot so nhi phan.
void long_print(ull x, byte N, byte eol)
{
	byte i;
	ull single;
	single=1;
	printf(" ");
	for (i=0;i<N;i++)
	{
		printf("%llu",(x&(single<<(N-1-i)))>>(N-1-i));
	}
	if (eol)
	{
		printf("\n");
	}
}


// Ham giai thuat tinh toan cac Maximum clique.
void maximumClique(ull R, ull P, ull X)
{
byte i;
ull v,single;
if ((P==0)&&(X==0))
{
	printf("Clique\n");
	long_print(R,N,1);
	clique[count]=R;
	count++;
}
else
{
	single=1;
	for (i=0;i<N;i++)
	{
		v=single<<(N-1-i);
		if(P&v)
		{
			printf("Vertex Cond0 Cond1 Pik\n");
			long_print(v,N,0);
			long_print(P,N,0);
			P=P^v;
			long_print(P,N,0);
			long_print(pik[i],N,1);
			maximumClique(R|v,P&pik[i],X&pik[i]);
			X=X|v;
		}
	}
}
return;
}


int main(int argc, char *argv){
FILE *iFile, *oFile;
byte  i, j, bit, max_count;
ull sum,lbit,R,P,X,max;

// + Kiem  du lieu dau vao va dau ra khi goi toi file cac gia tri diem cua do thi.
if ( argc != 3 )
{
	printf( "Usage: %s Inputfile Outputfile.\n", argv[0] );
	return 1;
}
else
{
// 	We assume argv[1] is a filename to open
	iFile = fopen( argv[1], "r" );
	if ( iFile == 0 )
	{
		printf( "Could not open input file\n" );
		return 2;
	}
	oFile = fopen( argv[2], "w" );
	if ( oFile == 0 )
	{
		printf( "Could not open output file\n" );
		return 3;
	}
}

// + Doc file dau vao
fscanf (iFile,"%hhu",&N);
if (N>Nmax)
{
	printf("N is larger the 64");
	exit (1);
}

lbit=1;
mask=0;
for (i=0;i<N;i++)
{
	mask=mask|(lbit<<i);
}

// + Truy van matrix
for (i=0;i<N;i++)
{
	sum=0;
	for (j=0;j<N;j++)
	{
		if (j<i)
		{
			lbit=1;
			bit=0;
			if ((pik[j]&(lbit<<(N-i-1)))>0)
			{
				bit=1;
			}
		}
		if (j==i)
		{
			bit=0;
		}
		if (j>i)
		{
			fscanf (iFile,"%hhu",&bit);
			if(bit>1 || bit <0)
			{
				printf("Bad data.");
				exit (2);
			}
		}
		sum=(sum<<1)|bit;
	}
	pik[i]=sum;
}

R=0;
P=mask;
X=0;
count=0;

maximumClique(R,P,X);

fprintf (oFile,"Full connected group:\n");

// TIM KIEM CAC MAXIMAL CLIQUE
max=0;
for (i=0;i<count;i++)
{
	if(number(clique[i])>max)
	{
		max=number(clique[i]);
	}
}

// + Dau ra MAXIMAL CLIQUE.
max_count=0;
for (i=0;i<count;i++)
{
	if(number(clique[i])==max)
	{
		max_count++;
		lbit=1;
		for (j=0;j<N;j++)
		{
			if ((clique[i]&(lbit<<(N-(j+1))))>0)
			{
				fprintf(oFile,"%d ",j+1);
			}
		}
		fprintf(oFile,"\n");
	}
}
fprintf (oFile,"Total %d groups.\n",max_count);
fclose(iFile);
fclose(oFile);
return 0;
}

int main()
{
    bool    running = true;
    initializeRendering();

    while(running) 
    {              
        display();
        running = glfwGetWindowParam( GLFW_OPENED ); 
                                                     
    }
    return 0;
}





