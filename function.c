#include 	"function.h"
#include	"stdlib.h"
#include	"stdio.h"




 /**
��δʹ�ù��ú��� �ú�������Ӧ������һ��whileѭ�������������ͬ���ַ���
  * @brief   	ɾ��ɾ���ַ����е�ĳ���ַ��������ַ��� �ú���ֻ��ɾ��һ���ַ��� һ�㲻ʹ�á� 
  * @Name	 	 int del_substr(char *str,char const *substr)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/02/22 Create
  * @Version 	1.0 2020/04/27  
  *		     	1.1 2020/04/27 change sth
  * @Note   qrcode:#04HDownANGDownONGDownDDDownADDFAS#
  
  **/
 int del_substr(char *str,char const *substr)
 {
	 int len = strlen(str);
	 int sublen = strlen(substr);
	 char *string = str;
	 int i;
	 int j;
	 int tmp=0;
	 int flag = 0;
	 for(i = 0;i<len;i++)
	 {
		 tmp = 0;
		 if(*str == *substr)			//����з�����ͬ���ַ�������ַ����ȶ�
		 {//�ô��ȶ�ֻ��Ե����ַ�
			  for(j = 0;j<sublen;j++)
			  {
					if(*str == *substr)
				  {
					  str++;
					  substr++;
					  tmp++;
				  }
				  else
				  {
					  substr-=tmp;
					  str -=tmp;
					  break;
				  }
			  }
		 }
		  if(tmp == sublen)
		  {  
			 str -= tmp; 
			 char *p = str;
			 p += tmp;
					 while(*str != NULL)  
			 {
				 *str++ = *p++;
				 flag++;
			 }
			 break;
		  }
		 else
		 {
			 str++;
		 }
	 }	 
	 if(i==len)
	 {
		 return 0;
	 }
	 if(j==sublen)
	 {
		 str = string;	
		 return 1;
	 }
 
 
 }

 /**

  * @brief   	ɾ���ַ����е�ĳ���ַ��������ַ��������ظ�ָ�롣
  * @Name	 	  int del_str(char* qrcode ,char* need_del_char)
  * @param   	qrcode ����     need_del_char׼��ɾ�����ַ���
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/02/22 Create
  * @Version 	1.0 2020/04/27  
  *		     	1.1 2020/04/27 change sth
  * @Note   ���Զ��������Ŀǰ��δ���ָú�����bug
  
  **/
 int del_str(char* qrcode ,char* need_del_char)
 {
	char *p;	
	char temp[1024];
	PX("the input qrcode=%s\n" , qrcode);
	while((p=strstr(qrcode,need_del_char)) != NULL) 
	{ //��s1��s2�ַ����Ҳ�����ͬԪ��ʱֹͣ��strstr�ַ��������ַ��� 
		*p = '\0';//��s1����s2��ȵ�ͷ����Ϊ\0,�ض� 
		strcpy(temp , p+strlen(need_del_char));//��p����ӵ�s1��s2��ȵ��Ƕ�ĩβ��������	strcpy�����ַ��� 
		strcat(qrcode, temp );//��temp ����s1����	  
	} 
	//PX("the final qrcode=%s\n" , qrcode);
	return 0; 
 }


 
 /***********************************************************************
  *��������:del_useless()
  *�������:						 
  *���ز���:
  *�������ܣ�ɾ�������ַ�
  *����˵����
  *��	  ע:20191127 ZCJ
  ************************************************************************/
 int del_useless(char *src)
 {	  
	 char *pTmp = src;	  
	 unsigned int iSpace = 0;	  
	 while(*src != '\0') 
	 {		  
		 if(*src != 0x20 && *src != 0x0D && *src != 0x0A ) //0x20�ո� 0x0D�س�	0X0A����
		 {			 
			 *pTmp++ = *src; //  *pTmp = src��*pTmp++��
		 } 
		 else
		 {			 
			 iSpace++;		  
		 }		   
		 src++;    
	 }	   
	 *pTmp = '\0';	   
	 return iSpace;
 }


 /**

  * @brief   	ɾ���س���Down ɾ���ַ����е�ĳ���ַ��������ַ���������ɾ������ȷ���ַ�����
  * @Name	 	 int del_Enter( char* qrcode	)
  * @param   	None
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/02/22 Create
  * @Version 	1.0 2020/02/22  
  *		     	1.1 2020/02/22 change sth
  * @Note   qrcode:#04HDownANGDownONGDownDDDownADDFAS#
  
  **/
  
 char* del_Enter( char* qrcode )
 {		 
	char *subString;	
	char *subStringNext; 
	char *subStringNext1;
	char newcode[1024] = { 0} ;
	char *finalcode;
	char i = 0; 
	char SUBSTRING[20];
	subString = qrcode;	
//	newcode = malloc(sizeof(char)*1024);
	finalcode = malloc(sizeof(char)*1024);
	subStringNext =  strstr(subString, "Down");
	 while( subStringNext != NULL)
	{
		
		subStringNext = strstr(subString, "Down");
		if( subStringNext  != NULL )
		{
		//	printx("subStringNext :%s\n" , subStringNext);	
			subStringNext = subStringNext +  4 ;	
		}
		else
		{
			qrcode = finalcode ;
			PX("qrcode=%s\n" , qrcode);	
			free(finalcode);
			return qrcode;		
		}
		memset(newcode , 0 , sizeof(newcode));
	//	memset(finalcode , 0 , sizeof(finalcode));
		printx("subString :%s\n" , subString);
		printx("subStringNext :%s\n" , subStringNext);			
		PX("PsubString=%p PsubStringNext=%p\n" , subString ,subStringNext);
		memcpy(newcode , subString ,  abs((subStringNext)  - (subString))  -4);
		sprintf(finalcode , "%s%s" , newcode ,subStringNext );
		PX("newcode=%s\n" , newcode );
		PX("finalcode=%s\n\n" , finalcode );	
		subString =  finalcode ;
	}
	 PX("NO ENTER,ALL IS WELL!\n");
	 return qrcode ;
//	return 0;  
 }

/**

  * @brief   	��ȡ����ַ��� ������Сд��ĸ������
  * @Name	 	void GetRandChar(char * buff, int n)
  * @param   	char * buff �洢�����������ָ����    				int n �ַ�����Ϊn-1
  * @retval  	None
  * @Author  	ZCJ
  * @Date 	 	2020/04/23 Create
  * @Version 	1.0 2020/04/23  
  * @Note  
  

  **/

void GetRandChar(char * buff, int n)
{
	int i = 0 ;
    char metachar[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
//    srand(time(NULL));
/*/c���������srand( (time(NULL) ) ;
��ʾ����һ��������ӣ�ÿ�����ж��ܱ�֤������Ӳ�ͬ��
���������֧�֣�֧�ֵĿ��Լ��ϣ�ȷ�����õ������
*/
    for( i = 0; i < n - 1; i++)
    {
        buff[i] = metachar[rand() % 62]; 
    }
    buff[n - 1] = '\0';
}
 int GetRandChar_test()
{
    char r[10];
    GetRandChar(r, 10);
    printf("GetRandChar=%s\n", r);
}

 /**
 
   * @brief 	 ��ȡ��ǰʱ�� 
   * @Name		 int GetCurTime(void)
   * @param 	 
   * @retval	 None
   * @Author	 ZCJ
   * @Date		 2020/04/24 Create
   * @Version	 1.0 2020/04/24  
   * @Note	
 /*  
 #ifndef _TM_DEFINED
struct tm {
int tm_sec; //* �� �C ȡֵ����Ϊ[0,59] 
int tm_min; //* �� - ȡֵ����Ϊ[0,59] 
int tm_hour; //* ʱ - ȡֵ����Ϊ[0,23] *
int tm_mday; //* һ�����е����� - ȡֵ����Ϊ[1,31] *
int tm_mon; //* �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11] *
int tm_year; //* ��ݣ���ֵ����ʵ����ݼ�ȥ1900 *
int tm_wday; //* ���� �C ȡֵ����Ϊ[0,6]������0���������죬1��������һ���Դ����� *
int tm_yday; //* ��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ����� *
int tm_isdst; //* ����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ������ʵ������ʱ��ʱ��tm_isdstΪ0�����˽����ʱ��tm_isdst()Ϊ����*
long int tm_gmtoff; //*ָ�������ڱ���߶���ʱ����UTC����ʱ����������UTC����ʱ���ĸ�����*
const char *tm_zone; //*��ǰʱ��������(�뻷������TZ�й�)*
};

#define _TM_DEFINED
#endif
   */
 int GetCurTime(void)
 
 {
	 struct tm *ptr;
	 time_t lt;
	 lt =time(NULL);
	 ptr=localtime(&lt);
	 /*
	 printf("second:%d\n",ptr->tm_sec);
	 printf("minute:%d\n",ptr->tm_min);
	 printf("hour:%d\n",ptr->tm_hour);
	 printf("mday:%d\n",ptr->tm_mday);
	 printf("month:%d\n",ptr->tm_mon+1);
	 */
	 printf("TIME IS:%d-%d-%d-%d-%d-%d\n", ptr->tm_year+1900 ,ptr->tm_mon+1 , ptr->tm_mday, ptr->tm_hour, ptr->tm_min , ptr->tm_sec);
	 return 0;
 }


