#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#define MAX(a,b)	(a>b ? a:b )
#define MIN(a,b)	(a<b ? a:b )

#define CONNECT(a,b)	a##b //��ʾ����a b �� n=connect(123,456) n=123456 cha* str=connect("abcd","efg") str="abcdefg"
//#define	TOCHAR(a)		#@a //�����Ű�������a������һ���ַ� char* ch1 =TOCHAR(1) ch1 = '1' ֻ�е��ַ�����
#define	TOSTRING(a)		#a //˫���Ű�������a������һ���ַ��� char* str =TOSTRING(123) str1="123"

#define	MEM_B(x)		( *( (byte *) (x) ) ) //�õ�ָ����ַ�ϵ�һ���ֽ�ֵ  typedef unsigned char byte;
#define	MEM_W(x)		( *( (word *) (x) ) ) //�õ�ָ����ַ�ϵ�һ����ֵ wordһ��������֡���ϵͳӲ���йأ���������Ϊ16λ����1wordΪ2byte��32λʱ��1wordΪ4byte��

#define OFFSETOF(type ,field) ((size_t) & ((type *) 0) ->field ) //�õ�һ��field�ڽṹ���е�ƫ����
#define	FSIZ(type , field )	sizeof( ( (type *) 0) ->field ) //�õ�һ���ṹ����field��ռ�õ��ֽ���
#define B_PTR(var)	( (byte *) (void *) &(var)) //�õ�һ�������ĵ�ַ
#define W_PTR(var)	( (word *) (void *) &(var)) //�õ�һ�������Ŀ��

#define	UPCASE(c)	( ( (c) >= 'a' && (c) <= 'z') ? ((c) - 0x20) : (c) ) //��һ����ĸת��Ϊ��д  ˼�� ��ν���дת��ΪСд

#define INC_SAT(val)	(val = ((val) + 1 > (val)) ? (val) +1 : (val)) //��ֹ�����һ���취

#define	ARR_SIZE(a)		(sizeof((a)) / sizeof((a[0]))) //��������Ԫ�صĸ���

#define DECCHK( c ) ((c) >= ''0'' && (c) <= ''9'')	//�ж��ַ��ǲ���10��ֵ������
#define HEXCHK( c ) ( ((c) >= ''0'' && (c) <= ''9'') ||((c) >= ''A'' && (c) <= ''F'') ||((c) >= ''a'' && (c) <= ''f'') )  //8 �ж��ַ��ǲ���16��ֵ������




int GetRandChar_test();
void GetRandChar(char * buff, int n);
int GetCurTime(void);
char* del_Enter( char* qrcode );
int del_useless(char *src);

int del_str(char* qrcode ,char* need_del_char);




#endif










