
void test(char * buf, char *result,int n){
   char s[10]={0}; //stack
   char s1[20]={0};
   int *buf2=(int*)malloc(10*sizeof(int));//heap
   char * s2=(char*)malloc(20*sizeof(char));

    char * pbuf=buf;
    char *end;
     char c;
if(s[0]=='0'){
   if(strlen(result)+1>n)
  return;
  strcat(result,";"); //6
  }
   else if (s[0]=='1'){
     if(strlen(result)+strlen(buf)>n)
  return;
   strcat(result,buf); //7
   }
    


  
   free(buf2);
   free(s2);
  return 0;
}

int main(){
return 0;
}
