#ifndef DATA_H
#define DATA_H
#include<iostream>
using namespace std;
#include<string>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<ctime>
#include<fstream>

static int week=1;
static bool map_open[10]={false};
static int count[10]={0};
static bool if_win=false;

class Role;
Role *ro;


void help(){
	system("cls");
	cout<<"1.������֧����꣬�������ּ���ĸ������˵���ſ�����Ϸ"<<endl;
	cout<<"2.����Ի�ʱ�������������"<<endl;
	cout<<"3.ʹ����Ʒ����¼��ʱ��[Enter]������¼��"<<endl;
	cout<<"4.������ĸʱ�ǵ��л���Ӣ�����뷨Ŷ��"<<endl;
	cout<<"�����룺\n addmoney:��Ǯ\n addATK:������ֵ\n addweapon\n addarmor\n addmedicine\n addhoe"<<endl;
	_getch();
}
void makeinfo(){
	system("cls");
	cout<<"�����ߣ����ߣ���������\n��ϵ��ʽ��1042110134@qq.com"<<endl;
	_getch();
}

#define eq_n 5
enum eq_kind{WE,AR};
struct equipment
{
	int ID;
	int ATK;
	int money;
	int sell_money;
	int lasting;
	eq_kind kin;
	string name;
};
equipment equ[]=
{
	{0,0,0,0,0,WE,"��"},
	{1,10,50,30,5,WE,"ɱ��󿳵�"},
	{2,50,250,150,5,WE,"ǧ��������"},
	{3,10,100,60,100,AR,"��ͭ������"},
	{4,50,500,300,100,AR,"������Ƥ��"}
};


enum pr_kind{MED,SPM,HOM,ORE,DIE};
struct prop
{
	int ID;
	int pow;
	int money;
	int sell_money;
	pr_kind kin;
	string name;
};
#define pr_num 18
prop pro[pr_num]=
{//ID,pow,money,sell_money,kin,name
	{0,20,10,6,MED,"��Ƥ��ҩ"},
	{1,50,20,12,MED,"����ҩ"},
	{2,999,50,30,SPM,"��ҩ"},
	{101,5,50,30,HOM,"�����"},
	{102,10,100,60,HOM,"���������"},
	{201,20,0,0,ORE,"ʯͷ"},
	{202,20,10,10,ORE,"�����"},
	{203,30,40,20,ORE,"�����"},
	{204,150,20,10,ORE,"����ĵ���"},
	{205,20,300,200,ORE,"���ϵı���"},
	{206,100,60,30,ORE,"����������"},
	{301,20,40,10,DIE,"δ������ʬ"},
	{302,30,30,25,DIE,"δ������ʬ"},
	{303,40,60,30,DIE,"δ����ʬ"},
	{304,20,60,30,DIE,"δ������ʬ"},
	{305,10,100,30,DIE,"����"},
	{306,10,400,200,DIE,"������"},
	{307,1000,10000,10000,DIE,"����"}
};
int pr_arrID(int I)//����ƷIDת���ɵ����б��±�
{
	if(I<=100)
		return I;
	else if(I<=200)
		return I-101+3;
	else if(I<=300)
		return I-201+5;
	else if(I<=400)
		return I-301+11;
	else
		return -1;
}

struct monster
{
	int ID;
	int HP;
	int ATK;
	int esc;
	int drop[3];//������ƷID
	string name;
};
monster mon[]=
{//ID,HP,ATK,esc,name//������Ʒ��һ��100%���ڶ���40%��������20%(*װ��)��Ϊ���򲻵���
	{0,50,10,100,{301,0,1},"Сɽ��"},
	{1,100,50,50,{301,0,2},"ɽ����"},
	{2,50,20,100,{302,0,2},"������"}, 
	{3,150,80,30,{302,0,2},"����"},
	{4,100,60,80,{303,0,4},"���ƻ�"},
	{5,150,90,80,{303,0,4},"Хɽ��"},
	{6,50,30,50,{302,0,2},"�����"},
	{7,50,60,50,{302,0,2},"����"},
	{8,50,30,80,{302,0,2},"ˮ��"},
	{9,50,90,80,{302,0,2},"Ѫ��"},
	{10,100,60,0,{304,0,0},"��˿��"},
	{11,1000,99,100,{307,0,0},"����"},
	{12,100,80,80,{303,0,4},"���ƻ�"},
	{13,200,90,50,{205,2,4},"ǿ��"},
	//ID,HP,ATK,esc,name
	{14,60,30,100,{305,0,0},"������"},
	{15,60,20,100,{305,0,0},"������"},
	{16,100,10,100,{306,307,0},"������"},
	{17,1000,5,30,{0,0,0},"Ů��"}
};

class Role
{
private:
	string name;
	int HP;//����ֵ
	int HP_max;
	int ATK;//����ֵ
	int phy;//����
	int phy_max;
	int money;//����

	equipment wea;//����
	equipment arm;//����
	equipment *eq_bag;//װ������
	int eq_bagsize;//װ�������ڴ����
	int eq_num;//װ������ռ��

	int pr_bag[pr_num];//���߱�����ֻ��¼����������
public:
	Role(){}
	Role(string name):name(name)
	{
		HP_max=HP=200;
		ATK=10;
		phy_max=phy=30;
		money=100;
		eq_bag=new equipment[10];
		eq_bagsize=10;
		eq_num=0;
		wea=arm=equ[0];
		for(int i=0;i<pr_num;i++)  pr_bag[i]=0;
	}
	~Role()
	{
		delete[] eq_bag;
	}
	void savegame()
	{
		char sel;
		system("cls");
		cout<<"ȷ�ϴ浵��\n[1]��\n[0]��"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='1'));
		if(sel=='0')return;
		fstream save;
		save.open("save.d",ios_base::out);
		save<<eq_num<<" "<<eq_bagsize<<endl;
		for(int i=0;i<eq_num;i++)
		{
			save.write(reinterpret_cast<char*>(&eq_bag[i]),sizeof(eq_bag[i]));save<<endl;
		}
		save.write(reinterpret_cast<char*>(&wea),sizeof(wea));save<<endl;
		save.write(reinterpret_cast<char*>(&arm),sizeof(arm));save<<endl;



		save<<week<<" "<<if_win<<endl;
		for(int i=0;i<10;i++)
		{
			save<<map_open[i]<<" "<<count[i]<<endl;
		}
		save<<name<<" "<<HP<<" "<<HP_max<<" "<<ATK<<" "<<phy<<" "<<phy_max<<" "<<money<<endl;
		for(int i=0;i<pr_num;i++)
		{
			save<<pr_bag[i]<<" ";
		}
		save.close();
		system("cls");cout<<"���ݱ���ɹ����ô浵������save.d�ļ��У�"<<endl;_getch();
	}
	bool readgame()
	{
		char sel;
		system("cls");
		cout<<"ȷ�϶�ȡ��\n[1]��\n[0]��"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='1'));
		if(sel=='0')return false;
		fstream save;
		save.open("save.d",ios_base::in);
		if(!save)
		{
			system("cls");
			cout<<"�浵�����ڣ�"<<endl;_getch();
			return false;
		}
		save>>eq_num>>eq_bagsize;
		save.seekg(2*sizeof(int));
		//delete [] eq_bag;
		eq_bag=new equipment[eq_bagsize];
		for(int i=0;i<eq_num;i++)
		{
			save.read(reinterpret_cast<char*>(&eq_bag[i]),sizeof(eq_bag[i]));
		}
		save.read(reinterpret_cast<char*>(&wea),sizeof(wea));
		save.read(reinterpret_cast<char*>(&arm),sizeof(arm));
		save.seekg(2*sizeof(int)+(2+eq_num)*sizeof(equipment));



		save>>week>>if_win;
		for(int i=0;i<10;i++)
		{
			save>>map_open[i]>>count[i];
		}
		save>>name>>HP>>HP_max>>ATK>>phy>>phy_max>>money;
		for(int i=0;i<pr_num;i++)
		{
			save>>pr_bag[i];
		}
		save.close();
		system("cls");cout<<"���ݶ�ȡ�ɹ���"<<endl;_getch();
		return true;
	}

	string getname(){return name;}
	int getmoney(){return money;}
	int getATK(){return ATK;}
	int getHP(){return HP;}
	int getphy(){return phy;}
	void sub_HP(int n)
	{
		HP-=n;
	}

	void add_HP(int n)
	{
		int k=n;
		if(k>HP_max-HP)
			k=HP_max-HP;
		if(n!=1000)
		cout<<"���HP�ظ���"<<k<<"��"<<endl;
		HP+=k;
	}
	bool sub_money(int n)
	{
		if(money<n)
		{cout<<"�������㣡��"<<endl;return false;}
		money-=n;
		cout<<"��ʹ����"<<n<<"������"<<endl;
		return true;
	}
	void add_money(int n)
	{
		money+=n;
		cout<<"��õ���"<<n<<"������"<<endl;
	}
	void add_atk(int n)
	{
		ATK+=n;
		cout<<"�������ֵ������"<<n<<"�㣡"<<endl;
	}
	bool sub_phy(int n)
	{
		if(phy<n)
		{cout<<"�������㣡��"<<endl;return false;}
		phy-=n;
		cout<<"��������"<<n<<"��������"<<endl;
		return true;
	}
	void add_phy(int n)
	{
		int k=n;
		if(k>phy_max-phy)
			k=phy_max-phy;
		if(n!=1000)
		cout<<"��������ظ���"<<k<<"��"<<endl;
		phy+=k;
	}
	//�����ຯ��
	int n_prID(int n)//���߱�����n������>0ת���ɵ����б��±꣨����Ϊ��򳬹�����������
	{
		int k=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pr_bag[i]<=0)
				continue;
			k++;
			if(k==n)
				return i;
		}
		return -1;
	}
	int getpr_num()
	{
		int n=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pr_bag[i]<=0)
				continue;
			n++;
		}
		return n;
	}
	void add_pr(int prID)//����Ϊ����ID
	{
		int n=pr_arrID(prID);
		pr_bag[n]++;
		cout<<"������["<<pro[n].name<<"]"<<endl;
	}
	void sub_pr(int prID)//����Ϊ����ID
	{
		int n=pr_arrID(prID);
		if(pr_bag[n]<=0)
		{cout<<"û�и���Ʒ��"<<endl;return;}
		pr_bag[n]--;
		cout<<"��ʧȥ��["<<pro[n].name<<"]"<<endl;
	}

	//��ʾ�ຯ��
	void showRole()
	{
		int harm;
		if(wea.lasting<=0)
			harm=ATK+arm.ATK;
		else
			harm=ATK+wea.ATK+arm.ATK;
		cout<<"========================================"<<endl;
		cout<<"���ƣ�  "<<name<<endl;
		cout<<"����ֵ��"<<ATK<<endl;
		cout<<"�ۺ�����ֵ��"<<harm<<endl;
		cout<<"����ֵ��"<<phy<<"/"<<phy_max<<endl;
		cout<<"����ֵ��"<<HP<<"/"<<HP_max<<endl;
		cout<<"������  "<<money<<endl;
		cout<<"������  ";
		if(wea.ID==0)
			cout<<"��"<<endl;
		else
		{
			cout<<wea.name;
			if(wea.lasting<=0)
				cout<<"(����ά��)";
			else
				cout<<"\t����+"<<wea.ATK;
			cout<<"\t�;ã�"<<wea.lasting<<endl;
		}
		cout<<"���ߣ�  ";
		if(arm.ID==0)
			cout<<"��"<<endl;
		else
			cout<<arm.name<<"(����+"<<arm.ATK<<")"<<endl;
		cout<<"========================================"<<endl;
		cout<<"��˵�������ƹѸ�˵����ܴ��ǿ���ͼ޸������������Ļ������ţ�"<<ro->getname()<<"̤��������֮·��"<<endl;
		cout<<"========================================"<<endl;
	}

	//װ���ຯ��
	equipment geteq(int n)
	{
		return eq_bag[n];
	}
	void add_eq(equipment e)
	{
		eq_bag[eq_num]=e;
		eq_num++;
		if(eq_num==eq_bagsize)
		{
			equipment *temp=new equipment[eq_bagsize+=10];
			for(int i=0;i<eq_num;i++)
				temp[i]=eq_bag[i];
			delete [] eq_bag;
			eq_bag=temp;
		}
	}
	void sub_eq(int bagID)
	{
		for(int i=bagID;i<eq_num;i++)
		{
			eq_bag[i]=eq_bag[i+1];
		}
		eq_num--;
		eq_bag[eq_num]=equ[0];
	}
	void equip(int bagID)//����Ϊװ�������±�
	{
		switch(eq_bag[bagID].kin)
		{
		case WE:
			if(!(wea.ID==0)) {cout<<wea.name<<"�ѽ����"<<endl;add_eq(wea);}
			wea=eq_bag[bagID];
			sub_eq(bagID);
			cout<<wea.name<<"װ���ɹ���"<<endl;
			break;
		case AR:
			if(!(arm.ID==0)) {cout<<arm.name<<"�ѽ����"<<endl;add_eq(arm);}
			arm=eq_bag[bagID];
			sub_eq(bagID);
			cout<<arm.name<<"װ���ɹ���"<<endl;
			break;
		}
	}
	void un_equip(eq_kind k)
	{
		switch(k)
		{
		case WE:
			if(wea.ID==0)
			{cout<<"��δװ����������"<<endl;return;}
			cout<<wea.name<<"�ѽ����"<<endl;
			add_eq(wea);
			wea=equ[0];
			break;
		case AR:
			if(arm.ID==0)
			{cout<<"��δװ�����ߣ���"<<endl;return;}
			cout<<arm.name<<"�ѽ����"<<endl;
			add_eq(arm);
			arm=equ[0];
			break;
		}
	}


	void showeq()
	{
		int k=0;
		if(wea.ID!=0)
		{
			cout<<"["<<setw(2)<<++k<<"]װ���У�"<<setw(10)<<wea.name;
			if(wea.lasting<=0)
				cout<<"(����ά��)";
			else
				cout<<"\t����+"<<wea.ATK;
			cout<<"\t�;ã�"<<wea.lasting<<endl;
		}
		if(arm.ID!=0)
		{
			cout<<"["<<setw(2)<<++k<<"]װ���У�"<<setw(10)<<arm.name<<"\t����+"<<arm.ATK<<endl;
		}
		for(int i=0;i<eq_num;i++)
		{
			cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<eq_bag[i].name<<"\t�䵱�ۣ�"<<eq_bag[i].sell_money<<"\t����+"<<eq_bag[i].ATK;
			if(eq_bag[i].kin==WE)
				cout<<"\t�;ã�"<<eq_bag[i].lasting;
			cout<<endl;
		}
	}
	void use_eq(int n)//����Ϊװ���м�װ��������n����n>0
	{
		int t=0;
		if(wea.ID!=0)
		{
			++t;
			if(n==t)
			{un_equip(WE);return;}
		}
		if(arm.ID!=0)
		{
			++t;
			if(n==t)
			{un_equip(AR);return;}
		}
		for(int i=0;i<eq_num;i++)
		{
			++t;
			if(n==t)
			{equip(i);return;}
		}
	}
	bool fix(int n)//����Ϊװ���м�װ��������n��
	{
		int t=n_eqbagID(n);
		switch(t)
		{
		case -2:
			wea.lasting++;
			cout<<wea.name<<"���;ö�������һ�㣡"<<endl;
			return true;
		case -1:
			cout<<"�����޷�ά�ޣ���"<<endl;
			return false;
		default:
			if(eq_bag[t].kin==AR)
			{cout<<"�����޷�ά�ޣ���"<<endl;return false;}
			eq_bag[t].lasting++;
			cout<<eq_bag[t].name<<"���;ö�������һ�㣡"<<endl;
			return true;
		}
	}
	int n_eqbagID(int n)//װ���м�װ��������n����ת����װ�������б��±꣨n����Ϊ��򳬹���������,װ������������-2�����߷���1��
	{
		int t=0;
		if(wea.ID!=0)
		{
			++t;
			if(n==t)
				return -2;
		}
		if(arm.ID!=0)
		{
			++t;
			if(n==t)
				return -1;
		}
		for(int i=0;i<eq_num;i++)
		{
			++t;
			if(n==t)
				return i;
		}
		return-10;
	}
	int geteq_num(){return eq_num;}
	int geteq_n()//����װ�������ڵ�װ������
	{
		int t=0;
		if(wea.ID!=0)
		{
			++t;
		}
		if(arm.ID!=0)
		{
			++t;
		}
		return eq_num+t;
	}

	//����������
	void showme()
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//ҩƷ
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i];
				if(pro[i].kin==MED)
					cout<<"\tHP+"<<pro[i].pow;
				else if(pro[i].kin==SPM)
					cout<<"\tHPȫ��";
				cout<<endl;
			}
		}
	}
	void use_me(int n)//����Ϊ�����еĵ�n��ҩƷ��n����Ϊ0
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				if(++t==n)
				{
					sub_pr(pro[i].ID);
					add_HP(pro[i].pow);
					return;
				}
			}
		}
	}
	int me_prID(int n)//ҩƷ������n������>0ת���ɵ����б��±꣨����Ϊ��򳬹�����������
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				++t;
				if(n==t)
					return i;
			}
		}
		return-1;
	}
	int getme_num()
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				++t;
			}
		}
		return t;
	}



	void showho()//���
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//���
		{
			if(pro[i].kin==HOM&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i]<<"\tЧ��ֵ��"<<pro[i].pow<<endl;
			}
		}
	}
	int ho_prID(int n)
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//���
		{
			if(pro[i].kin==HOM&&pr_bag[i]!=0)
			{
				if(++k==n)
					return i;
			}
		}
		return -1;
	}
	int getho_num()
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pro[i].kin==HOM&&pr_bag[i]!=0)
			{
				t++;
			}
		}
		return t;
	}

	void showor()//��ʯ
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//��ʯ
		{
			if(pro[i].kin==ORE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i]<<"\t�����˺���"<<pro[i].pow<<endl;
			}
		}
	}
	int or_prID(int n)//��ʯ������n������>0ת���ɵ����б��±꣨����Ϊ��򳬹�����������
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pro[i].kin==ORE&&pr_bag[i]!=0)
			{
				t++;
				if(n==t)
					return i;
			}
		}
	}
	int getor_num()
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pro[i].kin==ORE&&pr_bag[i]!=0)
			{
				t++;
			}
		}
		return t;
	}

	void showor_di()
	{
		int k=0;
		for(int i=0;i<pr_num;i++)
		{
			if((pro[i].kin==ORE||pro[i].kin==DIE)&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t������"<<pr_bag[i]<<"\t�����˺���"<<pro[i].pow<<endl;
			}
		}
	}
	int or_di_prID(int n)//��ʯ��ʬ�屳����n������>0ת���ɵ����б��±꣨����Ϊ��򳬹�����������
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if((pro[i].kin==ORE||pro[i].kin==DIE)&&pr_bag[i]!=0)
			{
				t++;
				if(t==n)
					return i;
			}
		}
		return -1;
	}
	int getor_di_num()
	{
		int t=0;
		for(int i=0;i<pr_num;i++)
		{
			if((pro[i].kin==ORE||pro[i].kin==DIE)&&pr_bag[i]!=0)
			{
				t++;
			}
		}
		return t;
	}
	
	void showdi()//����
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//����
		{
			if(pro[i].kin==DIE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i]<<"\t�����˺���"<<pro[i].pow<<endl;
			}
		}
	}


	void showall()
	{
		int k=0;
		for(int i=0;i<eq_num;i++)//װ��
		{
			cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<eq_bag[i].name<<"\t�䵱�ۣ�"<<eq_bag[i].sell_money<<"\t����+"<<eq_bag[i].ATK;
			if(eq_bag[i].kin==WE)
				cout<<"\t�;ã�"<<eq_bag[i].lasting;
			cout<<endl;
		}
		for(int i=0;i<pr_num;i++)//ҩƷ
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i];
				if(pro[i].kin==MED)
					cout<<"\tHP+"<<pro[i].pow;
				else if(pro[i].kin==SPM)
					cout<<"\tHPȫ��";
				cout<<endl;
			}
		}
		for(int i=0;i<pr_num;i++)//���
		{
			if(pro[i].kin==HOM&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i]<<"\tЧ��ֵ��"<<pro[i].pow<<endl;
			}
		}
		for(int i=0;i<pr_num;i++)//��ʯ
		{
			if(pro[i].kin==ORE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i]<<"\t�����˺���"<<pro[i].pow<<endl;
			}
		}
		for(int i=0;i<pr_num;i++)//����
		{
			if(pro[i].kin==DIE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t�䵱�ۣ�"<<pro[i].sell_money<<"\t������"<<pr_bag[i]<<"\t�����˺���"<<pro[i].pow<<endl;
			}
		}
	}
	bool use_all(int n)//ȫ����Ʒ�еĵ�n��
	{
		int k=0;
		for(int i=0;i<eq_num;i++)//װ��
		{
			if(++k==n)
			{equip(i);return true;}
		}
		for(int i=0;i<pr_num;i++)//ҩƷ
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				if(++k==n)
				{
					sub_pr(pro[i].ID);
					add_HP(pro[i].pow);
					return true;
				}
			}
		}
		return false;
	}
	void sell(int n)
	{
		int k=0;
		for(int i=0;i<eq_num;i++)//װ��
		{
			if(++k==n)
			{cout<<"��ʧȥ��"<<eq_bag[i].name<<endl;add_money(eq_bag[i].sell_money);sub_eq(i);}
		}
		for(int i=0;i<pr_num;i++)//����
		{
			if(pr_bag[i]!=0)
			{
				if(++k==n)
				{sub_pr(pro[i].ID);add_money(pro[i].sell_money);}
			}
		}
	}
	int getall_num()
	{
		int k=eq_num;
		for(int i=0;i<pr_num;i++)//ҩƷ
		{
			if(pr_bag[i]!=0)
			{
				++k;
			}
		}
		return k;
	}

	void showbag()
	{
		char sel;//�ַ���ѡ��
		int se;//������ѡ��
		int n;//��Ŀ��¼
		while(1)
		{
			system("cls");
			cout<<"��1�����\n��2��ҩƷ\n��3������\n��4����ʯ\n��5������\n��6��ȫ��\n��0������"<<endl;
			do
			sel=_getch();
			while(!(sel>='0'&&sel<='6'));
			switch(sel)
			{
			case '0':return;
			case '1':
				while(1)
				{
					system("cls");
					n=geteq_n();
					cout<<"����ߡ�"<<endl;
					showeq();
					if(n==0)
						cout<<"ʲô��û�У�����"<<endl;
					cout<<"[ 0]����"<<endl;
					cout<<"ѡ����Ҫʹ����Ʒ�ı�ţ���Enter��ȷ��ʹ�ã�";
					do
					{
						cin>>se;
						if(cin.fail())
						{
							cin.clear();
							cin.sync();
							se=-1;
						}
					}while(!(se>=0&&se<=n));
					if(se==0)
						break;
					system("cls");use_eq(se);_getch();
				}
				break;
			case '2':
				while(1)
				{
					system("cls");
					n=getme_num();
					cout<<"��ҩƷ��"<<endl;
					showme();
					if(n==0)
						cout<<"ʲô��û�У�����"<<endl;
					cout<<"[ 0]����"<<endl;
					cout<<"ѡ����Ҫʹ����Ʒ�ı�ţ���Enter��ȷ��ʹ�ã�";
					do
					{
						cin>>se;
						if(cin.fail())
						{
							cin.clear();
							cin.sync();
							se=-1;
						}
					}while(!(se>=0&&se<=n));
					if(se==0)
						break;
					system("cls");use_me(se);_getch();
				}
				break;
			case '3':
				system("cls");
				cout<<"�����ߡ�"<<endl;
				showho();
				cout<<"(�˴��޷�ʹ�ù���)"<<endl;_getch();
				break;
			case '4':
				system("cls");
				cout<<"����ʯ��"<<endl;
				showor();
				cout<<"(�˴��޷�ʹ�ÿ�ʯ)"<<endl;_getch();
				break;
			case '5':
				system("cls");
				cout<<"�����"<<endl;
				showdi();
				cout<<"(�˴��޷�ʹ������)"<<endl;_getch();
				break;
			case '6':
				while(1)
				{
					system("cls");
					n=getall_num();
					cout<<"��ȫ����"<<endl;
					showall();
					if(n==0)
						cout<<"ʲô��û�У�����"<<endl;
					cout<<"[ 0]����"<<endl;
					cout<<"ѡ����Ҫʹ����Ʒ�ı�ţ���Enter��ȷ��ʹ�ã�";
					do
					{
						cin>>se;
						if(cin.fail())
						{
							cin.clear();
							cin.sync();
							se=-1;
						}
					}while(!(se>=0&&se<=n));
					if(se==0)
						break;
					system("cls");
					if(!use_all(se))
					{system("cls");cout<<"�˴��޷�ʹ�ã�"<<endl;}
					_getch();
				}
				break;
			}
			
		}
	}


	//ս������,ʤ������true�����������ܷ���false
	bool combat(monster m)
	{
		char sel;
		int harm;//��ɫ�ܹ�
		int beharm;//�����ܹ�
		int se;
		int num;
		bool turn=false;//�ж���˭�Ļغ�
		srand(unsigned(time(NULL)));
		int prob;//�ø����ж�ǿ��ʹ�õļ���
		
		system("cls");
		cout<<"�������ˡ�"<<m.name<<"��"<<endl;
		cout<<m.name<<"���˹�������"<<endl;
		_getch();
		while(1)
		{
			if(wea.lasting<=0)
				harm=ATK+arm.ATK;
			else
				harm=ATK+wea.ATK+arm.ATK;
			beharm=m.ATK;
			if(turn==false)//����Ļغ�
			{
				system("cls");
				system("color 0e");
				cout<<"======================================="<<endl;
				cout<<m.name<<"\t������"<<beharm<<"\tHP��"<<m.HP<<endl;
				cout<<name<<"\t������"<<harm<<"\tHP��"<<HP<<endl;
				cout<<"======================================="<<endl;
				prob=rand()%100;
				//��ͨ����
				if(m.ID==13&&m.HP<100)
				{
					cout<<m.name<<"ʹ����[����]��"<<endl;
					cout<<m.name<<"����������200��"<<endl;
					m.HP+=200;
				}
				else if(m.ID!=13||prob<40)
				{
					cout<<m.name<<"��������"<<endl;
					if(rand()%100<20)
					{beharm*=2;cout<<"����Ҫ�����˺������� "<<endl;}
					HP-=beharm;
					cout<<m.name<<"���������"<<beharm<<"���˺�"<<endl;
				}
				else if(prob<65)
				{
					cout<<m.name<<"ʹ����[�ƹ�]��"<<endl;
					cout<<name<<"�޷��ж�����"<<endl;
					cout<<m.name<<"ʹ����[ǿ��]��"<<endl;
					num=getpr_num();
					if(num==0)
					{
						cout<<m.name<<"ǿ��ʧ�ܣ���û�п�������ĵ��ߣ�"<<endl;
					}
					else
					{
						cout<<m.name<<"ǿ��ɹ���"<<endl;
						sub_pr(n_prID(rand()%num+1));
					}
				}
				else if(prob<70)
				{
					cout<<m.name<<"ʹ����[�ƹ�]��"<<endl;
					cout<<name<<"�޷��ж�����"<<endl;
					cout<<m.name<<"ʹ����[����]��"<<endl;
					if(wea.ID!=0)
					{
						cout<<"��ʧȥ��"<<wea.name<<endl;
						wea=equ[0];
					}
					else if(arm.ID!=0)
					{
						cout<<"��ʧȥ��"<<arm.name<<endl;
						arm=equ[0];
					}
					else
					{
						cout<<m.name<<"����ʧ�ܣ�������û��װ�����"<<endl;
					}
				}
				else
				{
					cout<<m.name<<"ʹ����[����]��"<<endl;
					cout<<m.name<<"����������100��"<<endl;
					m.HP+=100;
				}
				_getch();
				//�����ж�
				if(HP<=0)
				{
					system("cls");
					system("color 0c");
					cout<<"�㱻["<<m.name<<"]ɱ���ˣ���"<<endl;_getch();
					system("cls");
					for(int i=0;i<8;i++)
					cout<<"GAMEOVER GAMEOVER GAMEOVER GAMEOVER GAMEOVER"<<endl;
					cout<<"ʤ���˱��ҳ��£��������������ɡ���"<<endl;
					for(int i=0;i<8;i++)
					cout<<"GAMEOVER GAMEOVER GAMEOVER GAMEOVER GAMEOVER"<<endl;
					_getch();
					system("color 07");
					return false;
				}
				system("color 07");
				turn=true;
			
			}

			if(turn==true)
			{
				system("cls");
				system("color 0a");
				cout<<"======================================="<<endl;
				cout<<m.name<<"\t������"<<beharm<<"\tHP��"<<m.HP<<endl;
				cout<<name<<"\t������"<<harm<<"\tHP��"<<HP<<endl;
				cout<<"======================================="<<endl;
				cout<<"[1]����[2]����Ʒ[3]��ҩƷ[0]����"<<endl;
				cout<<"======================================="<<endl;
				do
				sel=_getch();
				while(!(sel>='0'&&sel<='3'));
				switch(sel)
				{
				case '0':
					if(rand()%100<m.esc)
					{
						cout<<"�ɹ��ӵ��ˣ�"<<endl;_getch();
						system("color 07");
						return false;
					}
					cout<<"��⣡û�ӵ�������ס�ˣ�"<<endl;
					_getch();
					turn=false;
					break;
				case '1':
					cout<<"����"<<m.name<<"�����˹���"<<endl;
					if(rand()%100<10)
					{harm*=2;cout<<"����Ҫ�����˺������� "<<endl;}
					m.HP-=harm;
					cout<<"���"<<m.name<<"�����"<<harm<<"���˺�"<<endl;
					_getch();
					turn=false;
					break;
				case '2':
					num=getor_di_num();
					if(num==0)
					{system("cls");cout<<"��⣡û����Ʒ����"<<endl;_getch();break;}
					system("cls");
					cout<<"��ѡ��"<<endl;
					showor_di();
					cout<<"[0]����"<<endl;
					cout<<"ѡ����Ҫʹ����Ʒ�ı�ţ���Enter��ȷ��ʹ�ã�"<<endl;
					do
					{
						cin>>se;
						if(cin.fail())
						{
							cin.clear();
							cin.sync();
							se=-1;
						}
					}while(!(se>=0&&se<=num));
					if(se==0) break;
					se=or_di_prID(se);
					pr_bag[se]--;
					cout<<"����"<<m.name<<"�ӳ���"<<pro[se].name<<endl;
					m.HP-=pro[se].pow;
					cout<<m.name<<"�ܵ���"<<pro[se].pow<<"���˺�"<<endl;
					_getch();
					turn=false;
					break;
				case '3':
					num=getme_num();
					if(num==0)
					{system("cls");cout<<"��⣡û��ҩƷ����"<<endl;_getch();break;}
					system("cls");
					cout<<"��ѡ��"<<endl;
					showme();
					cout<<"[0]����"<<endl;
					cout<<"ѡ����Ҫʹ����Ʒ�ı�ţ���Enter��ȷ��ʹ�ã�"<<endl;
					do
					{
						cin>>se;
						if(cin.fail())
						{
							cin.clear();
							cin.sync();
							se=-1;
						}
					}while(!(se>=0&&se<=num));
					if(se==0) break;
					se=me_prID(se);
					pr_bag[se]--;
					cout<<"��ʹ����"<<pro[se].name<<endl;
					add_HP(pro[se].pow);
					_getch();
					turn=false;
					break;
				}
				if(m.HP<=0)
				{
					system("cls");
					system("color 0f");
					cout<<m.name<<"��"<<name<<"ɱ���ˣ���"<<endl;
					sub_phy(7);
					if(wea.lasting>0)
					{
						wea.lasting--;
						cout<<wea.name<<"���;ü���һ��"<<endl;
					}
					if(m.drop[0]!=0)
					{
						add_pr(m.drop[0]);
					}
					if(m.drop[1]!=0&&rand()%100<40)
					{
						add_pr(m.drop[1]);
					}
					if(m.drop[2]!=0&&rand()%100<20)
					{
						add_eq(equ[m.drop[2]]);
						cout<<"������"<<equ[m.drop[2]].name<<endl;
					}
					add_atk(5);
					if(m.ID==13)
						add_atk(100);
					_getch();
					system("color 07");
					return true;
				}


			}
		}
	}
};




#endif//DATA_H