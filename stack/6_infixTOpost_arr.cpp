#include <iostream>



#include <string.h>



using namespace std;



class Stack {



public:



int size;



char *S;



int top;



Stack (){



top =-1;



}



int Full (Stack *obj){



if (obj->top==obj->size-1)



return 1;



return 0;



}



void Push (Stack *obj,char x){



if (obj->Full(obj)==1)



cout<<"Stack Overflow";



else{



obj->top++;



obj->S[obj->top]=x;



}



}



int Empty (Stack *obj){



if(obj->top==-1)



return 1;



return 0;



}



char pop (Stack *obj){



char x=0;



if (obj->Empty(obj)==1)



cout<<"Stack is Empty";



else{



x=obj->S[obj->top];



obj->top--;



}



return x;



}



};



int Pre (char x){



if (x=='+'||x=='-')



return 1;



else if (x=='*'||x=='/')



return 2;

return 0;

}



int operand(char x){



if (x=='+'||x=='-'||x=='*'||x=='/')



return 0;



else



return 1;



}



char *Convert (char *infix) {



Stack obj;



obj.size=12;



obj.S = new char[12];



char *Postfix = new char [12];



int i=0,j=0;



while (infix[i]!='\0'){



if (operand(infix[i])){



Postfix[j]=infix[i];



i++;



j++;



}else{



if (obj.top==-1 || Pre(infix[i]) > Pre(obj.S[obj.top]) ){



obj.Push(&obj,infix[i++]);



}



else {



Postfix[j++]=obj.pop(&obj);



}



}





}



while(obj.top!=-1){



Postfix[j++]=obj.pop(&obj);



}

Postfix[j]='\0';

return Postfix;

}



int main (){







char infix[12]="a+b*c+d";



cout<<"Infix ";

for(int i=0;i<=11;i++){



cout<<infix[i];



}

cout<<endl;



char *Post;

cout<<"PostFix : ";

Post=Convert(infix);





cout<<Post;

cout<<endl;



}



    