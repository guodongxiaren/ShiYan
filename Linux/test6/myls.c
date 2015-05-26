#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <memory.h>
#include <malloc.h>
#include <getopt.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <error.h>
#include <sys/types.h>
#include <linux/kdev_t.h> 

#define  OPT_v        0x0001   /* -v 选项:查看本软件版本 */
#define  OPT_h        0x0002   /* -h 选项:查看本软件帮助 */
#define  OPT_l        0x0004   /* -l 选项:长型(long)显示 */
#define  OPT_a        0x0008   /* -a 选项:显示所有文件(all)*/
#define  OPT_R        0x0010   /* -R 选项:显示子目录内容 */
#define  OPT_f        0x0020   /* -f 选项:不排序 */

#define DONE_SUCCESS  0

typedef struct _Node 
{ 
     char path[1024];
     char name[256];
     int length;
     struct stat st;
     struct _Node *pnext;
} nNode;

    
int createlslink(char *path,int flag,nNode **head)
{
    DIR * dp;
    struct dirent *entry;
    struct stat statbuf;    
    nNode *p;
    char  abspath[1024];
    if((dp=opendir(path))==NULL)
    {
         fprintf(stderr,"cannot open directory:%s\n",path);
         return -1;
    }
    if(chdir(path) == -1)
    {
         fprintf(stderr,"cannot cd directory:%s\n",path);
         return -2;
    }
   
    if(NULL==getcwd(abspath,1024))
    {   
         fprintf(stderr,"getcwd error!\n");
	 return -3;
    } 
    while((entry=readdir(dp)) != NULL) 
    {
        lstat(entry->d_name,&statbuf);
        if((!(flag & OPT_a)) && (entry->d_name[0]=='.'))   /*没有选项 -a 则不显示.开头的文件(或目录)名*/
           continue;
        else
        {
           p = (nNode *)malloc(sizeof(nNode));
           p->pnext = *head;
           *head = p;
           (*head)->length = strlen(entry->d_name);
           strcpy((*head)->path,abspath);
           strcpy((*head)->name,entry->d_name);
           memcpy(&((*head)->st),&statbuf,sizeof(struct stat));
        }
    }
    
    if(-1==chdir(".."))
    {
         fprintf(stderr,"cannot cd directory:..\n");
         return -3;
    }
    
   if((closedir(dp)) ==-1)
    {
         fprintf(stderr,"cannot close dp\n");
         return -4;
    }
      
    return DONE_SUCCESS;
}


void sortlslink(nNode *head,int flag)
{
    nNode *p,*q,r;
    int  msuccess;
    if(!head)
       return;
       
    if(flag & OPT_f)
    {
        ;
    }
    else
    { 
        p = head;
        while(p->pnext) p = p->pnext;
       
        while(p!=head)
        { 
            q=head;
            msuccess = 1;
            while(q->pnext)
            {
                if(strcmp(q->name,q->pnext->name)>0)
                {
                    memcpy(&r,q,sizeof(nNode));
                    strcpy(q->name,q->pnext->name);
                    strcpy(q->path,q->pnext->path);
                    q->length = q->pnext->length;
                    memcpy(&q->st,&(q->pnext->st),sizeof(q->st));
                    
                    strcpy(q->pnext->name,r.name);
                    strcpy(q->pnext->path,r.path);
                    q->pnext->length = r.length;                    
                    memcpy(&(q->pnext->st),&(r.st),sizeof(r.st));
                    msuccess = 0;
                }

                if(q->pnext==p)
                    break;
                q = q->pnext;
            }
            
            if(msuccess)
               break;
            p = q;
        }  
    }
}

void format_long_print(nNode *head,int flag)
{
    nNode * p = head;
    char buf[12];
    struct passwd *password;
    struct group  *grp;
    struct tm * tm_ptr;

    char  linkfilebuf[1024];
    char pathfilename[1024];
    char filename[256];
    if(!p)
        return;
   
    while(p)
    {
        if( !strcmp(p->name,".") || !strcmp(p->name,"..")) 
        {
            printf("%s\n",p->name);
        }
        else
        {
           /*permission*/   
            strcpy(pathfilename,p->path);
            strcpy(filename,p->name);

	    memset(buf,'-',11);
	    buf[11]=0;
 
	    if(S_ISDIR(p->st.st_mode))       buf[0] = 'd';
	    else if(S_ISCHR(p->st.st_mode))  buf[0] = 'c';
	    else if(S_ISBLK(p->st.st_mode))  buf[0] = 'b'; 
	    else if(S_ISFIFO(p->st.st_mode)) buf[0] = 'p';
	    else if(S_ISLNK(p->st.st_mode))  buf[0] = 'l';
	    else if(S_ISSOCK(p->st.st_mode)) buf[0] = 's';
	     
            if(S_IRUSR&p->st.st_mode) buf[1] = 'r';
            if(S_IWUSR&p->st.st_mode) buf[2] = 'w';
            if(S_IXUSR&p->st.st_mode) buf[3] = 'x';

            if(S_IRGRP&p->st.st_mode) buf[4] = 'r';
            if(S_IWGRP&p->st.st_mode) buf[5] = 'w';
            if(S_IXGRP&p->st.st_mode) buf[6] = 'x';

            if(S_IROTH&p->st.st_mode) buf[7] = 'r';
            if(S_IWOTH&p->st.st_mode) buf[8] = 'w';
	    if(S_IXOTH&p->st.st_mode) buf[9] = 'x';
	
	    printf("%s ",buf);

            /*link number*/
            printf("%4d ",p->st.st_nlink);

            /*owner*/
 	    password = getpwuid(p->st.st_uid);
	    if(password)
   	    {
                printf("%s ",password->pw_name);
	    }
            else
	    {
	        printf("%d ",p->st.st_uid);
	    }    

            /* group */
	    grp= getgrgid(p->st.st_gid);
	    if(grp)
	    {
	        printf("%s ",grp->gr_name);
	    }
            else
	    {
	        printf("%d ",p->st.st_gid);
	    }

            /*file bytes or dev number*/
            if(S_ISBLK(p->st.st_mode) || S_ISCHR(p->st.st_mode))
            {
                printf("%3u,",MAJOR(p->st.st_rdev));  
                printf("%3u ",MINOR(p->st.st_rdev));
            }
            else
            {
                printf("%7u ",p->st.st_size);
            }       

            /*time*/
      	    tm_ptr = localtime(&(p->st.st_mtime));
            printf("%02d-%02d ",tm_ptr->tm_mon+1,tm_ptr->tm_mday);
            printf("%02d:%02d ",tm_ptr->tm_hour,tm_ptr->tm_min);
       
            /*filename */
            if(S_ISDIR(p->st.st_mode))
                printf("\033[;34m%s\033[0m\n",filename);
            else 
                printf("%s ",filename);   
       
            if(S_ISLNK(p->st.st_mode))
            {
               strcat(pathfilename,"/");
               strcat(pathfilename,p->name);
               int rslt=readlink(pathfilename,linkfilebuf,1024);
               if (rslt<0)
               { 
                   printf("readlink error!\n");
                   exit(-1);
               }

               linkfilebuf[rslt]='\0';
               printf("-> \033[;32m%s\033[0m",linkfilebuf);
            }  
            printf("\n");
        }

        p = p->pnext;
    }

    return;
} 

void format_normal_print(nNode *head,int flag)
{
    nNode * p = head;
 
    while(p)
    {
        if(  ( (strcmp(p->name,".")==0) || (strcmp(p->name,"..")==0) ) && (flag & OPT_a))
        {
            printf("%s\n",p->name);
        }
        else
        {
            if(S_ISDIR(p->st.st_mode))
                printf("\033[;32m%s\033[0m\n",p->name);
            else 
                printf("%s\n",p->name); 
        }  
        p = p->pnext;
    }

    return;
}

void showlslink(nNode *head,int flag)
{
    if(flag & OPT_l)
       format_long_print(head,flag);
    else
       format_normal_print(head,flag);
    return;
}


void lspath(char *path,int flag)
{
    char pathname[1024];
    char filename[256];
  
    nNode *p = NULL;
    nNode *head = NULL;
     
    /*创建列文件链表 head*/
    if ((createlslink(path,flag,&head)) != DONE_SUCCESS)
    { 
       printf("createlslink error!\n");
       return;
    }
     /* 对链表排序 */
    sortlslink(head,flag);
     /* 按选项显示链表内容  */
    showlslink(head,flag); 
   
    /*如果节点不是子目录，则删除节点，否则当有-R选项时,列子目录内容后删除节点  */ 
    while(head)
    {  
        p = head;
        head = head->pnext;
        
        if(S_ISDIR(p->st.st_mode) && (flag & OPT_R))  
        {    
             if( strcmp(p->name,".") && strcmp(p->name,"..") ) 
             {
                 strcpy(pathname,p->path);
                 strcat(pathname,"/");
                 strcat(pathname,p->name);      
                 printf("\033[;32m%s:\033[0m\n",pathname);
                 lspath(pathname,flag);
             }
        }
        
        free(p);
    }
 
     return;
}


int main(int argc,char *argv[])
{
    int opt;
    char path[1024];
    int listflag = 0;
    struct stat statbuf;

    struct option longopts[] = { {"help",0,NULL,'h'},{"version",0,NULL,'v'},{0,0,0,0}};
       
    while((opt=getopt_long(argc,argv,"afhlvR",longopts,NULL)) != -1)
    {
        switch(opt)
        {
           case 'a': listflag |= OPT_a;
                     break;
           case 'f': listflag |= OPT_f;
                     break;
           case 'h': listflag |= OPT_h;
                     break;
           case 'l': listflag |= OPT_l;
                     break;
           case 'v': listflag |= OPT_v;
                     break;
           case 'R': listflag |= OPT_R;
                     break;
           case '?': printf("Usage:\n %s -h \n or \n  %s --help \nfor help\n",argv[0],argv[0]);
                     exit(-1);
        }
    }    


    if(listflag & OPT_h )
    {
         printf("Usage:  %s -afhlvR [directory1 [directory2],...]\n",argv[0]);
         return 0;
    }
    else if(listflag & OPT_v)
    {
         printf("myls version 0.1\nCopyright by YCG 2015\n");
         return 0;
    }
     
    
    if(optind==argc)
    {
        /* 列当前目录文件 */
 	if(NULL==getcwd(path,1024))
	    return -1;       		
 	
        lspath(path,listflag);
	
    }
    else
    { 
         for(;optind<argc;optind++)
         {
            if(lstat(argv[optind],&statbuf)<0)
            {
               fprintf(stderr,"stat error\n");
               return -1;
            }
            if(S_ISDIR(statbuf.st_mode))
               lspath(argv[optind],listflag);
            else 
            {
               ;
            }
         }
    }
 
    return 0;
}

