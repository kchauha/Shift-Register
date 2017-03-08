#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include<vector>
#include<utility>
#include<algorithm>
#include "iostream"
using namespace std;
class operate
{
     public:
        int vec, size, right, left, var, print,i;
        char ch[10];  
        vector<int> v,p;      
        void set_val(vector<int>, int, int, int, int, int, char [], int);
        void print_val();
        void calculate();
        

};
    void operate:: calculate()
{
   
      if(ch[0]=='i')
     {
        
        int long n= v.size();

        if(size>n) 
    {         
     v.resize(size);
     rotate(v.begin(), v.begin()+(n), v.end());
    }
     if(size<n)
     v.resize(size);

     
         for(int j=2; j<i; j++)
        {
	
	
           if(ch[j]=='r')
         {
            rotate(v.rbegin(),v.rbegin()+ right, v.rend());
            for(int x=0;x<right; x++)
              v[x]=var;            
         }
       
	
    
	if( ch[j]=='l')
        {
          rotate(v.begin(), v.begin()+left, v.end());
        int pos=size-left;
        
	
        for(int i=size-1; i>=size-left;i--)   v[i]=var;
     
        }
	
  
}  
    
}

if( print==1)
{
cout<<"\nThe result is ";
for (int i=0;i<size;i++) cout<<v[i];
cout<<endl;
}
        

}

    void operate:: set_val(vector<int> vec, int size, int right, int left, int var, int print, char ch[], int i)  
   {
          v=vec;
          this->size= size;
          this->right=right;
          this->left=left;
          this->var=var; 
          this->print=print;
          strcpy(this->ch,ch);
          this->i=i; 
         
   }  

   

 
void print_usage() {
    printf("Usage: -[option] \n");
}

int main(int argc, char *argv[]) {
    int opt= 0;    
    int vec=-1, size=-1, right=-1, left=-1, var=-1;
    vector<int> v,p;
    operate obj; 
      
//Specifying the expected options
    //The two options l and b expect numbers as argument
    static struct option long_options[] = {
        {"vector",    required_argument, NULL,  'i' },
        {"size", required_argument,      NULL,  's' },
        {"right",    required_argument,  NULL,  'r' },
        {"left",   required_argument,    NULL,  'l' },
        {"var",   required_argument,     NULL,  'v' },
        {"print",   no_argument,         0,  'p' },
        {0,           0,                 0,   0  }
    };

    int long_index =0;
   
       
        char a[6];
     int i=0;
    int print =0;
    while ((opt = getopt_long(argc, argv,"i:s:r:l:v:p",long_options, &long_index)) != -1) {
        switch (opt) {
             case 'i' : vec=atoi(optarg);                   
                       a[i]='i';
                       i++;                 
                 break;
             case 's' : size=atoi(optarg);
                     a[i]='s';
                       i++;      
                 break;
             case 'r' : right=atoi(optarg); 
                     a[i]='r';
                       i++;      
                 break;
             case 'l' : left=atoi(optarg);
                        a[i]='l';
                       i++;      
                 break;
             case 'v' : var=atoi(optarg);
                    a[i]='v';
                       i++;      
                 break;
             case 'p' : print= 1;
                  a[i]='p';
                       i++;      
                 break;
             default: print_usage(); 
                 exit(EXIT_FAILURE);
  
        }
    }
       if( (size<=0)||(left<0)||(right<0)||(var<0))
{
     cerr<<"Invalid Syntax1"<< endl;
       return -1;
 }     
       if((vec>=0) && (size>=0))
     {
          for(int j=0;j<size;j++)
     {
          int n= vec% 10;
          if((n!=0) && (n!=1)) 
          {
     cerr<<"Invalid Syntax"<< endl;
       return -1;
 }             
          v.push_back(n);
          vec=vec/10;
     }
       
       reverse(v.begin(), v.end()); 
     }
    else
{
      cerr<<"Invalid Syntax"<< endl;
       return -1;
     }
             
        obj.set_val( v,  size,  right,  left,  var,  print, a , i);
        obj.calculate();
        
        
       return 0;
}

 
   



     
    
      









