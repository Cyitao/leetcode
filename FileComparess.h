#pragma once
#include "base.h"
#include "HaffmanTree.h"
using namespace std;
class FileComparess
{
public:
	void compress(const char* filename)
	{
		FILE *fread=fopen(filename,"rb");
		if(fread==NULL)
		{
			cout<<"打开待压缩文件失败" << endl;
			return;
		}
		CharInfo HNarry[256];
		for(int i=0;i<256;i++)
			HNarry[i]._ch=i;
		unsigned char ch=fgetc(fread);
		while(!feof(fread))
		{
			HNarry[ch]._count++;
			ch=fgetc(fread);
		}
		HaffmanTree h(HNarry,256,CharInfo());
		Node *root=h.GetRoot();
		string str;
		GenerateHaffmanCode(HNarry, root, str);
		fseek(fread,0,SEEK_SET);
		ch=fgetc(fread);
		unsigned char data=0;
		int bitcount=7;
		string write(filename);
		write=write+".compress";
		FILE *fwrite=fopen(write.c_str(),"wb");
		while(!feof(fread))
		{
			const char *cur=HNarry[ch]._code.c_str();
			while(*cur)
			{
				if(bitcount>=0)
				{
					data=data|((*cur-'0')<<bitcount);
					bitcount--;
				}
				if(bitcount<0)
				{
					fputc(data,fwrite);
					bitcount=7;
					data=0;
				}
				cur++;
			}
			ch=fgetc(fread);
		}
		fputc(data,fwrite);
		WriteConfig(HNarry,filename);
		fclose(fread);
		fclose(fwrite);
	}
	void uncompress(const char* filename)
	{
		CharInfo HNarry[256];
		ReadConfig(HNarry,filename);
		HaffmanTree h(HNarry,256,CharInfo());
		Node *root=h.GetRoot();
		Node *cur=root;
		string comf(filename);
		comf=comf+".compress";
		FILE *fread=fopen(comf.c_str(),"rb");
		if(fread==NULL)
		{
			cout<<"打开待压缩文件失败" << endl;
			return;
		}
		string out(filename);
		out=out+".output";
		FILE *fwrite=fopen(out.c_str(),"wb");
		int sumcount=(*root)._wight._count;
		unsigned char ch=fgetc(fread);
		while(sumcount)
		{
			int tmp=1;
			int bitcount=7;
			while(bitcount>=0)
			{
				if(ch&(tmp<<bitcount))
					cur=(*cur)._right;
			    else
				    cur=(*cur)._left;
			    bitcount--;
			    if((*cur)._left==NULL&&(*cur)._right==NULL)
				{
					fputc((*cur)._wight._ch,fwrite);
				    cur=root;
					sumcount--;
					if(sumcount==0)
						break;
				}
			}
			ch=fgetc(fread);
		}
		fclose(fread);
		fclose(fwrite);

	}
protected:
	//得到Haffman编码（后序遍历HaffmanTree）
	void GenerateHaffmanCode(CharInfo *HNarry,Node *root,string &code)
	{
		if(root==NULL)
			return;
		GenerateHaffmanCode(HNarry,(*root)._left,code+'0');
		GenerateHaffmanCode(HNarry,(*root)._right,code+'1');
		(*root)._wight._code=code;
		if((*root)._left==NULL&&(*root)._right==NULL)
			HNarry[(*root)._wight._ch]._code=code;
	}
	void WriteConfig(CharInfo* HNarry,const char* filename)
	{
		string conf(filename);
		conf=conf+".configure";
		FILE *fcon=fopen(conf.c_str(),"wb");
		for(int i=0;i<256;i++)
		{
			if(HNarry[i]._count!=0)
			{
				fputc(HNarry[i]._ch,fcon);
				fputc(',',fcon);
				stringstream ss;
				ss<<HNarry[i]._count;
				string s(ss.str());
				fputs(s.c_str(),fcon);
				fputc(',',fcon);
				fputs(HNarry[i]._code.c_str(),fcon);
				fputc('\n',fcon);
			}
		}
		fclose(fcon);
	}
	void ReadConfig(CharInfo* HNarry,const char* filename)
	{
		string conf(filename);
		conf=conf+".configure";
		FILE *fread=fopen(conf.c_str(),"rb");
		if(fread==NULL)
		{
			cout<<"打开压缩文件失败"<<endl;
			return;
		}
		char str[100];
		while(fgets(str,100,fread))
		{
			char *ptr=str;
			unsigned char index=(unsigned char) *ptr;
			if(index=='\n')
			{
				HNarry[index]._ch=index;
				fgets(str,100,fread);
				ptr=str;
				ptr++;
				LongType count=0;
				while(*ptr!=','&&*ptr)
				{
					count=count*10+(*ptr)-'0';
					ptr++;
				}
				HNarry[index]._count=count;
				ptr++;
				string code(ptr);
				HNarry[index]._code=code;
			}
			else
			{
				HNarry[index]._ch=index;
				ptr+=2;
				LongType count=0;
				while(*ptr!=','&&*ptr)
				{
					count=count*10+(*ptr)-'0';
					ptr++;
				}
				HNarry[index]._count=count;
				ptr++;
				string code(ptr);
				code.pop_back();
				HNarry[index]._code=code;
			}
		}
	}
};