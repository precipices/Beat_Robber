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
	cout<<"1.本作不支持鼠标，采用数字及字母键输入菜单编号控制游戏"<<endl;
	cout<<"2.人物对话时键入任意键继续"<<endl;
	cout<<"3.使用物品数字录入时按[Enter]键结束录入"<<endl;
	cout<<"4.键入字母时记得切换成英文输入法哦！"<<endl;
	cout<<"作弊码：\n addmoney:加钱\n addATK:加武力值\n addweapon\n addarmor\n addmedicine\n addhoe"<<endl;
	_getch();
}
void makeinfo(){
	system("cls");
	cout<<"制作者：客七（待命名）\n联系方式：1042110134@qq.com"<<endl;
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
	{0,0,0,0,0,WE,"无"},
	{1,10,50,30,5,WE,"杀猪大砍刀"},
	{2,50,250,150,5,WE,"千牙狼牙棒"},
	{3,10,100,60,100,AR,"破铜烂铁衣"},
	{4,50,500,300,100,AR,"赤铁虎皮裳"}
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
	{0,20,10,6,MED,"狗皮膏药"},
	{1,50,20,12,MED,"跌打药"},
	{2,999,50,30,SPM,"金创药"},
	{101,5,50,30,HOM,"鹤嘴锄"},
	{102,10,100,60,HOM,"灿烂银光铲"},
	{201,20,0,0,ORE,"石头"},
	{202,20,10,10,ORE,"铁矿块"},
	{203,30,40,20,ORE,"银矿块"},
	{204,150,20,10,ORE,"深埋的地雷"},
	{205,20,300,200,ORE,"古老的宝藏"},
	{206,100,60,30,ORE,"屠龙锈铁剑"},
	{301,20,40,10,DIE,"未处理猪尸"},
	{302,30,30,25,DIE,"未处理狼尸"},
	{303,40,60,30,DIE,"未处理虎尸"},
	{304,20,60,30,DIE,"未处理蟒尸"},
	{305,10,100,30,DIE,"鲤鱼"},
	{306,10,400,200,DIE,"白龙鲤"},
	{307,1000,10000,10000,DIE,"龙珠"}
};
int pr_arrID(int I)//将物品ID转换成道具列表下标
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
	int drop[3];//掉落物品ID
	string name;
};
monster mon[]=
{//ID,HP,ATK,esc,name//掉落物品第一件100%，第二件40%，第三件20%(*装备)，为零则不掉落
	{0,50,10,100,{301,0,1},"小山猪"},
	{1,100,50,50,{301,0,2},"山猪王"},
	{2,50,20,100,{302,0,2},"白眼狼"}, 
	{3,150,80,30,{302,0,2},"狼王"},
	{4,100,60,80,{303,0,4},"黑纹虎"},
	{5,150,90,80,{303,0,4},"啸山虎"},
	{6,50,30,50,{302,0,2},"青光狼"},
	{7,50,60,50,{302,0,2},"烽狼"},
	{8,50,30,80,{302,0,2},"水狼"},
	{9,50,90,80,{302,0,2},"血狼"},
	{10,100,60,0,{304,0,0},"盘丝蛇"},
	{11,1000,99,100,{307,0,0},"白龙"},
	{12,100,80,80,{303,0,4},"白纹虎"},
	{13,200,90,50,{205,2,4},"强盗"},
	//ID,HP,ATK,esc,name
	{14,60,30,100,{305,0,0},"金龙鲤"},
	{15,60,20,100,{305,0,0},"银龙鲤"},
	{16,100,10,100,{306,307,0},"白龙鲤"},
	{17,1000,5,30,{0,0,0},"女鬼"}
};

class Role
{
private:
	string name;
	int HP;//生命值
	int HP_max;
	int ATK;//武力值
	int phy;//体力
	int phy_max;
	int money;//银两

	equipment wea;//武器
	equipment arm;//防具
	equipment *eq_bag;//装备背包
	int eq_bagsize;//装备背包内存分配
	int eq_num;//装备背包占用

	int pr_bag[pr_num];//道具背包（只记录道具数量）
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
		cout<<"确认存档？\n[1]是\n[0]否"<<endl;
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
		system("cls");cout<<"数据保存成功！该存档保存在save.d文件中！"<<endl;_getch();
	}
	bool readgame()
	{
		char sel;
		system("cls");
		cout<<"确认读取？\n[1]是\n[0]否"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='1'));
		if(sel=='0')return false;
		fstream save;
		save.open("save.d",ios_base::in);
		if(!save)
		{
			system("cls");
			cout<<"存档不存在！"<<endl;_getch();
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
		system("cls");cout<<"数据读取成功！"<<endl;_getch();
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
		cout<<"你的HP回复了"<<k<<"点"<<endl;
		HP+=k;
	}
	bool sub_money(int n)
	{
		if(money<n)
		{cout<<"银两不足！！"<<endl;return false;}
		money-=n;
		cout<<"你使用了"<<n<<"两银子"<<endl;
		return true;
	}
	void add_money(int n)
	{
		money+=n;
		cout<<"你得到了"<<n<<"两银子"<<endl;
	}
	void add_atk(int n)
	{
		ATK+=n;
		cout<<"你的武力值增加了"<<n<<"点！"<<endl;
	}
	bool sub_phy(int n)
	{
		if(phy<n)
		{cout<<"体力不足！！"<<endl;return false;}
		phy-=n;
		cout<<"你消耗了"<<n<<"点体力！"<<endl;
		return true;
	}
	void add_phy(int n)
	{
		int k=n;
		if(k>phy_max-phy)
			k=phy_max-phy;
		if(n!=1000)
		cout<<"你的体力回复了"<<k<<"点"<<endl;
		phy+=k;
	}
	//道具类函数
	int n_prID(int n)//道具背包第n个数量>0转换成道具列表下标（不能为零或超过背包数量）
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
	void add_pr(int prID)//参数为道具ID
	{
		int n=pr_arrID(prID);
		pr_bag[n]++;
		cout<<"你获得了["<<pro[n].name<<"]"<<endl;
	}
	void sub_pr(int prID)//参数为道具ID
	{
		int n=pr_arrID(prID);
		if(pr_bag[n]<=0)
		{cout<<"没有该物品！"<<endl;return;}
		pr_bag[n]--;
		cout<<"你失去了["<<pro[n].name<<"]"<<endl;
	}

	//显示类函数
	void showRole()
	{
		int harm;
		if(wea.lasting<=0)
			harm=ATK+arm.ATK;
		else
			harm=ATK+wea.ATK+arm.ATK;
		cout<<"========================================"<<endl;
		cout<<"名称：  "<<name<<endl;
		cout<<"武力值："<<ATK<<endl;
		cout<<"综合武力值："<<harm<<endl;
		cout<<"体力值："<<phy<<"/"<<phy_max<<endl;
		cout<<"生命值："<<HP<<"/"<<HP_max<<endl;
		cout<<"银两：  "<<money<<endl;
		cout<<"武器：  ";
		if(wea.ID==0)
			cout<<"无"<<endl;
		else
		{
			cout<<wea.name;
			if(wea.lasting<=0)
				cout<<"(损坏请维修)";
			else
				cout<<"\t武力+"<<wea.ATK;
			cout<<"\t耐久："<<wea.lasting<<endl;
		}
		cout<<"防具：  ";
		if(arm.ID==0)
			cout<<"无"<<endl;
		else
			cout<<arm.name<<"(武力+"<<arm.ATK<<")"<<endl;
		cout<<"========================================"<<endl;
		cout<<"【说明】：黄寡妇说如果能打败强盗就嫁给他，被这样的话激励着，"<<ro->getname()<<"踏上了修行之路。"<<endl;
		cout<<"========================================"<<endl;
	}

	//装备类函数
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
	void equip(int bagID)//参数为装备背包下标
	{
		switch(eq_bag[bagID].kin)
		{
		case WE:
			if(!(wea.ID==0)) {cout<<wea.name<<"已解除！"<<endl;add_eq(wea);}
			wea=eq_bag[bagID];
			sub_eq(bagID);
			cout<<wea.name<<"装备成功！"<<endl;
			break;
		case AR:
			if(!(arm.ID==0)) {cout<<arm.name<<"已解除！"<<endl;add_eq(arm);}
			arm=eq_bag[bagID];
			sub_eq(bagID);
			cout<<arm.name<<"装备成功！"<<endl;
			break;
		}
	}
	void un_equip(eq_kind k)
	{
		switch(k)
		{
		case WE:
			if(wea.ID==0)
			{cout<<"尚未装备武器！！"<<endl;return;}
			cout<<wea.name<<"已解除！"<<endl;
			add_eq(wea);
			wea=equ[0];
			break;
		case AR:
			if(arm.ID==0)
			{cout<<"尚未装备防具！！"<<endl;return;}
			cout<<arm.name<<"已解除！"<<endl;
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
			cout<<"["<<setw(2)<<++k<<"]装备中："<<setw(10)<<wea.name;
			if(wea.lasting<=0)
				cout<<"(损坏请维修)";
			else
				cout<<"\t武力+"<<wea.ATK;
			cout<<"\t耐久："<<wea.lasting<<endl;
		}
		if(arm.ID!=0)
		{
			cout<<"["<<setw(2)<<++k<<"]装备中："<<setw(10)<<arm.name<<"\t武力+"<<arm.ATK<<endl;
		}
		for(int i=0;i<eq_num;i++)
		{
			cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<eq_bag[i].name<<"\t典当价："<<eq_bag[i].sell_money<<"\t武力+"<<eq_bag[i].ATK;
			if(eq_bag[i].kin==WE)
				cout<<"\t耐久："<<eq_bag[i].lasting;
			cout<<endl;
		}
	}
	void use_eq(int n)//参数为装备中及装备背包第n个，n>0
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
	bool fix(int n)//参数为装备中及装备背包第n个
	{
		int t=n_eqbagID(n);
		switch(t)
		{
		case -2:
			wea.lasting++;
			cout<<wea.name<<"的耐久度提升了一点！"<<endl;
			return true;
		case -1:
			cout<<"防具无法维修！！"<<endl;
			return false;
		default:
			if(eq_bag[t].kin==AR)
			{cout<<"防具无法维修！！"<<endl;return false;}
			eq_bag[t].lasting++;
			cout<<eq_bag[t].name<<"的耐久度提升了一点！"<<endl;
			return true;
		}
	}
	int n_eqbagID(int n)//装备中及装备背包第n个，转换成装备背包列表下标（n不能为零或超过背包数量,装备中武器返回-2，防具返回1）
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
	int geteq_n()//包括装备中在内的装备数量
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

	//背包处理函数
	void showme()
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//药品
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i];
				if(pro[i].kin==MED)
					cout<<"\tHP+"<<pro[i].pow;
				else if(pro[i].kin==SPM)
					cout<<"\tHP全满";
				cout<<endl;
			}
		}
	}
	void use_me(int n)//参数为背包中的第n个药品，n不能为0
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
	int me_prID(int n)//药品背包第n个数量>0转换成道具列表下标（不能为零或超过背包数量）
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



	void showho()//矿铲
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//矿铲
		{
			if(pro[i].kin==HOM&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i]<<"\t效果值："<<pro[i].pow<<endl;
			}
		}
	}
	int ho_prID(int n)
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//矿铲
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

	void showor()//矿石
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//矿石
		{
			if(pro[i].kin==ORE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i]<<"\t掷出伤害："<<pro[i].pow<<endl;
			}
		}
	}
	int or_prID(int n)//矿石背包第n个数量>0转换成道具列表下标（不能为零或超过背包数量）
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
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t数量："<<pr_bag[i]<<"\t掷出伤害："<<pro[i].pow<<endl;
			}
		}
	}
	int or_di_prID(int n)//矿石及尸体背包第n个数量>0转换成道具列表下标（不能为零或超过背包数量）
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
	
	void showdi()//猎物
	{
		int k=0;
		for(int i=0;i<pr_num;i++)//猎物
		{
			if(pro[i].kin==DIE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i]<<"\t掷出伤害："<<pro[i].pow<<endl;
			}
		}
	}


	void showall()
	{
		int k=0;
		for(int i=0;i<eq_num;i++)//装备
		{
			cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<eq_bag[i].name<<"\t典当价："<<eq_bag[i].sell_money<<"\t武力+"<<eq_bag[i].ATK;
			if(eq_bag[i].kin==WE)
				cout<<"\t耐久："<<eq_bag[i].lasting;
			cout<<endl;
		}
		for(int i=0;i<pr_num;i++)//药品
		{
			if((pro[i].kin==MED||pro[i].kin==SPM)&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i];
				if(pro[i].kin==MED)
					cout<<"\tHP+"<<pro[i].pow;
				else if(pro[i].kin==SPM)
					cout<<"\tHP全满";
				cout<<endl;
			}
		}
		for(int i=0;i<pr_num;i++)//矿铲
		{
			if(pro[i].kin==HOM&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i]<<"\t效果值："<<pro[i].pow<<endl;
			}
		}
		for(int i=0;i<pr_num;i++)//矿石
		{
			if(pro[i].kin==ORE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i]<<"\t掷出伤害："<<pro[i].pow<<endl;
			}
		}
		for(int i=0;i<pr_num;i++)//猎物
		{
			if(pro[i].kin==DIE&&pr_bag[i]!=0)
			{
				cout<<"["<<setw(2)<<++k<<"]"<<setw(10)<<pro[i].name<<"\t典当价："<<pro[i].sell_money<<"\t数量："<<pr_bag[i]<<"\t掷出伤害："<<pro[i].pow<<endl;
			}
		}
	}
	bool use_all(int n)//全部物品中的第n个
	{
		int k=0;
		for(int i=0;i<eq_num;i++)//装备
		{
			if(++k==n)
			{equip(i);return true;}
		}
		for(int i=0;i<pr_num;i++)//药品
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
		for(int i=0;i<eq_num;i++)//装备
		{
			if(++k==n)
			{cout<<"你失去了"<<eq_bag[i].name<<endl;add_money(eq_bag[i].sell_money);sub_eq(i);}
		}
		for(int i=0;i<pr_num;i++)//道具
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
		for(int i=0;i<pr_num;i++)//药品
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
		char sel;//字符型选择
		int se;//数字型选择
		int n;//数目记录
		while(1)
		{
			system("cls");
			cout<<"【1】武具\n【2】药品\n【3】工具\n【4】矿石\n【5】猎物\n【6】全部\n【0】返回"<<endl;
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
					cout<<"【武具】"<<endl;
					showeq();
					if(n==0)
						cout<<"什么都没有！！！"<<endl;
					cout<<"[ 0]返回"<<endl;
					cout<<"选择你要使用物品的编号，按Enter键确认使用：";
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
					cout<<"【药品】"<<endl;
					showme();
					if(n==0)
						cout<<"什么都没有！！！"<<endl;
					cout<<"[ 0]返回"<<endl;
					cout<<"选择你要使用物品的编号，按Enter键确认使用：";
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
				cout<<"【工具】"<<endl;
				showho();
				cout<<"(此处无法使用工具)"<<endl;_getch();
				break;
			case '4':
				system("cls");
				cout<<"【矿石】"<<endl;
				showor();
				cout<<"(此处无法使用矿石)"<<endl;_getch();
				break;
			case '5':
				system("cls");
				cout<<"【猎物】"<<endl;
				showdi();
				cout<<"(此处无法使用猎物)"<<endl;_getch();
				break;
			case '6':
				while(1)
				{
					system("cls");
					n=getall_num();
					cout<<"【全部】"<<endl;
					showall();
					if(n==0)
						cout<<"什么都没有！！！"<<endl;
					cout<<"[ 0]返回"<<endl;
					cout<<"选择你要使用物品的编号，按Enter键确认使用：";
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
					{system("cls");cout<<"此处无法使用！"<<endl;}
					_getch();
				}
				break;
			}
			
		}
	}


	//战斗函数,胜利返回true，死亡或逃跑返回false
	bool combat(monster m)
	{
		char sel;
		int harm;//角色总攻
		int beharm;//怪物总攻
		int se;
		int num;
		bool turn=false;//判断是谁的回合
		srand(unsigned(time(NULL)));
		int prob;//用概率判断强盗使用的技能
		
		system("cls");
		cout<<"你遇到了【"<<m.name<<"】"<<endl;
		cout<<m.name<<"冲了过来！！"<<endl;
		_getch();
		while(1)
		{
			if(wea.lasting<=0)
				harm=ATK+arm.ATK;
			else
				harm=ATK+wea.ATK+arm.ATK;
			beharm=m.ATK;
			if(turn==false)//怪物的回合
			{
				system("cls");
				system("color 0e");
				cout<<"======================================="<<endl;
				cout<<m.name<<"\t攻击："<<beharm<<"\tHP："<<m.HP<<endl;
				cout<<name<<"\t攻击："<<harm<<"\tHP："<<HP<<endl;
				cout<<"======================================="<<endl;
				prob=rand()%100;
				//普通攻击
				if(m.ID==13&&m.HP<100)
				{
					cout<<m.name<<"使出了[仙术]！"<<endl;
					cout<<m.name<<"生命增加了200点"<<endl;
					m.HP+=200;
				}
				else if(m.ID!=13||prob<40)
				{
					cout<<m.name<<"攻击了你"<<endl;
					if(rand()%100<20)
					{beharm*=2;cout<<"击中要害！伤害翻倍！ "<<endl;}
					HP-=beharm;
					cout<<m.name<<"对你造成了"<<beharm<<"点伤害"<<endl;
				}
				else if(prob<65)
				{
					cout<<m.name<<"使出了[闷棍]！"<<endl;
					cout<<name<<"无法行动……"<<endl;
					cout<<m.name<<"使出了[强夺]！"<<endl;
					num=getpr_num();
					if(num==0)
					{
						cout<<m.name<<"强夺失败，你没有可以抢夺的道具！"<<endl;
					}
					else
					{
						cout<<m.name<<"强夺成功！"<<endl;
						sub_pr(n_prID(rand()%num+1));
					}
				}
				else if(prob<70)
				{
					cout<<m.name<<"使出了[闷棍]！"<<endl;
					cout<<name<<"无法行动……"<<endl;
					cout<<m.name<<"使出了[打落]！"<<endl;
					if(wea.ID!=0)
					{
						cout<<"你失去了"<<wea.name<<endl;
						wea=equ[0];
					}
					else if(arm.ID!=0)
					{
						cout<<"你失去了"<<arm.name<<endl;
						arm=equ[0];
					}
					else
					{
						cout<<m.name<<"打落失败，你身上没有装备武具"<<endl;
					}
				}
				else
				{
					cout<<m.name<<"使出了[仙术]！"<<endl;
					cout<<m.name<<"生命增加了100点"<<endl;
					m.HP+=100;
				}
				_getch();
				//死亡判定
				if(HP<=0)
				{
					system("cls");
					system("color 0c");
					cout<<"你被["<<m.name<<"]杀死了！！"<<endl;_getch();
					system("cls");
					for(int i=0;i<8;i++)
					cout<<"GAMEOVER GAMEOVER GAMEOVER GAMEOVER GAMEOVER"<<endl;
					cout<<"胜败乃兵家常事，大侠重新来过吧……"<<endl;
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
				cout<<m.name<<"\t攻击："<<beharm<<"\tHP："<<m.HP<<endl;
				cout<<name<<"\t攻击："<<harm<<"\tHP："<<HP<<endl;
				cout<<"======================================="<<endl;
				cout<<"[1]攻击[2]扔物品[3]用药品[0]逃跑"<<endl;
				cout<<"======================================="<<endl;
				do
				sel=_getch();
				while(!(sel>='0'&&sel<='3'));
				switch(sel)
				{
				case '0':
					if(rand()%100<m.esc)
					{
						cout<<"成功逃掉了！"<<endl;_getch();
						system("color 07");
						return false;
					}
					cout<<"糟糕！没逃掉，被逮住了！"<<endl;
					_getch();
					turn=false;
					break;
				case '1':
					cout<<"你向"<<m.name<<"发动了攻击"<<endl;
					if(rand()%100<10)
					{harm*=2;cout<<"击中要害！伤害翻倍！ "<<endl;}
					m.HP-=harm;
					cout<<"你对"<<m.name<<"造成了"<<harm<<"点伤害"<<endl;
					_getch();
					turn=false;
					break;
				case '2':
					num=getor_di_num();
					if(num==0)
					{system("cls");cout<<"糟糕！没有物品！！"<<endl;_getch();break;}
					system("cls");
					cout<<"请选择："<<endl;
					showor_di();
					cout<<"[0]返回"<<endl;
					cout<<"选择你要使用物品的编号，按Enter键确认使用："<<endl;
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
					cout<<"你向"<<m.name<<"扔出了"<<pro[se].name<<endl;
					m.HP-=pro[se].pow;
					cout<<m.name<<"受到了"<<pro[se].pow<<"点伤害"<<endl;
					_getch();
					turn=false;
					break;
				case '3':
					num=getme_num();
					if(num==0)
					{system("cls");cout<<"糟糕！没有药品！！"<<endl;_getch();break;}
					system("cls");
					cout<<"请选择："<<endl;
					showme();
					cout<<"[0]返回"<<endl;
					cout<<"选择你要使用物品的编号，按Enter键确认使用："<<endl;
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
					cout<<"你使用了"<<pro[se].name<<endl;
					add_HP(pro[se].pow);
					_getch();
					turn=false;
					break;
				}
				if(m.HP<=0)
				{
					system("cls");
					system("color 0f");
					cout<<m.name<<"被"<<name<<"杀死了！！"<<endl;
					sub_phy(7);
					if(wea.lasting>0)
					{
						wea.lasting--;
						cout<<wea.name<<"的耐久减少一点"<<endl;
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
						cout<<"你获得了"<<equ[m.drop[2]].name<<endl;
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