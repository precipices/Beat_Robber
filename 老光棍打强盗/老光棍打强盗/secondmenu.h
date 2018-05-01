#ifndef SECOND
#define SECOND
#include"data.h"


void showtitle(string name){
	system("cls");
	cout<<"\n\n\n\n\n\n";
	cout<<"一天，和平安宁的[清平镇]迎来了一个[强盗]，"<<endl;_getch();
	cout<<"[强盗]时不时到[清平镇]打砸几户人家的房子，把镇上搞得鸡犬不宁,"<<endl;_getch();
	cout<<"这天，[强盗]刚刚砸了"<<name<<"一直暗恋着的[黄寡妇]的家，[黄寡妇]的哭声刺激着"<<name<<"，"<<endl;_getch();
	cout<<"此时此刻，"<<name<<"突然升起了一种要保护小镇的强烈念头，"<<endl;_getch();
	cout<<"于是"<<name<<"决心好好习武，希望有朝一日能把强盗赶出小镇！"<<endl;_getch();
}
void showtime(){
	cout<<"========================================"<<endl;
	cout<<"第"<<week<<"周"<<endl;
	cout<<"========================================"<<endl;
}




void martialschool()	//[1]刘师傅的武馆
{
	char sel;
	while(1)
	{
		system("cls");
		if(map_open[0]==false)
		{
		cout<<"【刘师傅】：什么?你要跟我学武术，哎呀呀，是不是又要到黄寡妇面前显摆啊？"<<endl;_getch();
		cout<<"【刘师傅】：哎呀呀，阁下根骨惊奇，实在是百年难得一遇的废材啊！还是请一边儿玩去吧！"<<endl;_getch();
		}
		cout<<"【刘师傅】：哎呀呀，真想学？得嘞，一堂课一百两银砸，不给滚蛋……"<<endl;
		cout<<"您是否死皮赖脸地学习？\n[1]是，恭恭敬敬地给他一百两银砸\n[2]否，踹他一脚赶紧跑\n[0]悄悄离开，不带走一片云彩"<<endl;
		
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='2'));
		if(sel=='1')
		{
			system("cls");
			if(ro->getphy()<10)
			{cout<<"体力不足10点！！"<<endl;_getch();return;}
			if(ro->getmoney()<100)
			{cout<<"银两不足！！"<<endl;_getch();return;}
			ro->sub_money(100);
			map_open[0]=true;
			cout<<"你学习了刘师傅的武学之课……"<<endl;
			ro->sub_phy(10);
			ro->add_atk(10);
			_getch();
		}
		else
			return;
	}
}
void weaponshop()		//[2]刘师傅的武具馆
{
	char sel;
	int se;
	int n;
	system("cls");
	cout<<"【刘师傅】：哎呀……这年头，习武的太少了，东西都销不出去啊！！"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"【刘师傅】：哎呀呀！稀客稀客，请坐请坐！大爷您要买点什么？"<<endl;
		for(int i=1;i<=4;i++)
		{
			cout<<"["<<equ[i].ID<<"]"<<equ[i].name<<"\t单价："<<equ[i].money<<"\t武力+"<<equ[i].ATK;
			if(equ[i].kin==WE)
				cout<<"\t耐久："<<equ[i].lasting;
			cout<<endl;
		}
		cout<<"[0]不买"<<endl;
		cout<<"[F/f]精修武器"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='4'||sel=='F'||sel=='f'));
		switch(sel)
		{
		case '0':
			system("cls");
			cout<<"【刘师傅】：哎——呀——不买你搁这儿瞅啥，滚滚滚，滚远些！哼，死穷鬼！！"<<endl;
			_getch();
			return;
		case 'F':
		case 'f':break;
		default:
			system("cls");
			if(!(ro->sub_money(equ[sel-48].money))) {_getch();return; }
			ro->add_eq(equ[sel-48]);
			cout<<"你获得了["<<equ[sel-48].name<<"],并将其放入了背包。"<<endl;
			_getch();
			continue;
		}
		system("cls");
		cout<<"【刘师傅】：哎呀呀，大爷您别不信，洒家这手艺绝对是镇上独一份，武器坏了找我修准没问题！"<<endl;_getch();
		cout<<"【刘师傅】：啥？还没坏？没坏也没关系，洒家给您捣鼓捣鼓，保证更胜往昔啊！"<<endl;_getch();
		while(1)
		{
			system("cls");
			cout<<"【刘师傅】：那么您要修哪件武器呢？一点耐久五两银子，童叟无欺！\n(耐久没有上限，可以持续增加)"<<endl;
			ro->showeq();
			cout<<"[0]舍不得钱，不修了"<<endl;
			n=ro->geteq_n();//获得装备数量，包括装备中
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
			switch(se)
			{
			case 0:
				system("cls");
				cout<<"【刘师傅】：哎——呀——没钱你搁这儿瞅啥，滚滚滚，滚远些！哼，死穷鬼！！"<<endl;_getch();
				return;
			default:
				system("cls");
				if(ro->fix(se))
					ro->sub_money(5);
				_getch();
				break;
			}
		}
	}
}
void pharmacy()			//[3]张大娘的药铺
{
	char sel;
	while(1)
	{
		system("cls");
		cout<<"【张大娘】：欢迎欢迎，真抱歉啊！唉……最近都忙不过来了，药材也紧缺了。"<<endl;
		int k=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pro[i].kin==MED)
				cout<<"["<<++k<<"]"<<pro[i].name<<"\t单价："<<pro[i].money<<"\tHP+"<<pro[i].pow<<endl;
			else if(pro[i].kin==SPM)
				cout<<"["<<++k<<"]"<<pro[i].name<<"\t单价："<<pro[i].money<<"\tHP全满"<<endl;
		}
		cout<<"[0]不买了"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<=k+48));
		switch(sel)
		{
		case '0':
			system("cls");
			cout<<"【张大娘】：慢走啊，下次别再受伤了！唉……"<<endl;
			_getch();
			return;
		default:
			system("cls");
			if(!ro->sub_money(pro[sel-48-1].money)) {_getch();break;}
			ro->add_pr(pro[sel-48-1].ID);
			_getch();
			break;
		}
	}
}
void grocery()			//[4]铁大叔的杂货店
{
	char sel;
	int n=0;
	while(1)
	{
		system("cls");
		cout<<"【铁大叔】：哦哦，是小光啊，唉……强盗来过后，店里的东西已经不多了。"<<endl;
			for(int i=0;i<pr_num;i++)
			{
				if(pro[i].kin==HOM)
				{
					cout<<"["<<pro[i].ID-100<<"]"<<pro[i].name<<"\t单价："<<pro[i].money<<endl;
					n++;
				}
			}
			cout<<"[0]不买"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<=n+48));
		switch(sel)
		{
		case '0':return;
		default:
			system("cls");
			if(ro->sub_money(pro[pr_arrID(sel-48+100)].money)==false) {system("cls");cout<<"银两不足！！"<<endl;_getch();break;}
			ro->add_pr(sel-48+100);
			_getch();
			break;
		}
	}
}
void restaurant()		//[5]李阿娘的餐馆
{
	char sel;
	system("cls");
	if(if_win)
	{
		cout<<"【李阿娘】：走吧走吧，这儿什么都没有！！（拿毛巾甩了甩）"<<endl;_getch();
		cout<<"【小女孩】：嘻嘻……（做了个鬼脸）"<<endl;_getch();
		cout<<ro->getname()<<"：……"<<endl;_getch();
		return;
	}
	cout<<"【小女孩】：呜呜……李阿娘被强盗抓走了，说是要当压寨夫人"<<endl;_getch();
	cout<<"（"<<ro->getname()<<"：乖乖，这都能看得上，这强盗品味真独特）"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"【小女孩】：我就会这么几个菜，你要吃么？"<<endl;
		cout<<"[1]蛋炒饭        体力+10     单价：30"<<endl;
		cout<<"[2]小鸡炖蘑菇    体力全满    单价：60"<<endl;
		cout<<"[0]不吃了"<<endl;
			do
			sel=_getch();
			while(!(sel>='0'&&sel<='2'));
			system("cls");
			switch(sel)
			{
			case '0':return;
			case '1':
				if(ro->getmoney()<30)
				{cout<<"银两不足！"<<endl;_getch();return;}
				ro->sub_money(30);
				ro->add_phy(10);
				_getch();
				break;
			case '2':
				if(ro->getmoney()<60)
				{cout<<"银两不足！"<<endl;_getch();return;}
				ro->sub_money(60);
				ro->add_phy(999);
				_getch();
				break;
			}
	}
}
void pawnshop()			//[6]吴记当铺
{
	int se;
	int n;
	system("cls");
	cout<<"【吴老板】：他奶奶的，现在这年头，什么都有拿来当的，你拿块石头过来我忍忍也就罢了，提只山猪过来当就太他妈过分了吧！当我这是哪？火葬场吗！"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"【吴老板】：什么？你也是过来当这些的？滚！！你他妈给老子滚！！！"<<endl;
		ro->showall();
		n=ro->getall_num();
		cout<<"[ 0]赶紧走人"<<endl;
		cout<<"(输入数字，按Enter键结束输入)"<<endl;
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
		else 
		{system("cls");ro->sell(se);_getch();}
	}
	system("cls");
	cout<<"【吴老板】：唉~隔壁的[王屠户]被[强盗]吓跑后，我这日子也不好过了"<<endl;_getch();
}
void hunterhome()		//[7]孙猎户的家
{
	int sel;
	system("cls");
	cout<<"【孙猎户】：我去年进山时遇见了龙，在与恶龙搏斗时受了伤，不然哪有那强盗混的份！"<<endl;_getch();
	cout<<"（"<<ro->getname()<<"：是啊，您的脑子真伤的不轻啊！）"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"【孙猎户】：清平山真是奇妙啊，要我给你讲讲吗？"<<endl;
		cout<<"[1]山洞"<<endl;
		cout<<"[2]灌木和树丛"<<endl;
		cout<<"[3]地洞"<<endl;
		cout<<"[4]水潭"<<endl;
		cout<<"[5]草丛"<<endl;
		cout<<"[6]小径"<<endl;
		cout<<"[7]山顶"<<endl;
		cout<<"[0]算了吧，我没兴趣"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='7'));
		system("cls");
		switch(sel)
		{
		case '0':return;
		case '1':
			cout<<"山洞里住着一只山猪王和五只小山猪，小山猪是山上最弱的生物，而山猪王平时不会出来，但如果发现小猪都不见了，它也会生气的"<<endl;_getch();break;
		case '2':
			cout<<"树丛里藏着许多狼，谁也不知道里面有多少狼，据我知道的就有白眼狼，青光狼，烽狼，水狼，血狼，实力参差不齐，不过我听[王屠户]说过，那里似乎还有一只狼王，但总之我是没见过就是了"<<endl;_getch();break;
		case '3':
			cout<<"地洞是盘丝蛇的居住地，不过地洞很大，传说整座山里都是空洞，所以里面盘丝蛇也很多，只是不容易遇见罢了，而且盘丝蛇很缠人，遇上了铁定跑不掉，没把握的话不要轻易尝试"<<endl;_getch();break;
		case '4':
			cout<<"水潭里住着金龙鲤和银龙鲤，偶尔也会有树丛里的水狼混过去偷吃，据说水潭里还有白龙鲤，是银龙鲤的变种，鲤鱼都很弱，但却是极为珍贵的食材哦，而且据说白龙鲤一不小心跳过龙门后就会进化成白龙哦！就是山顶上的那种白龙！不——我没说谎，山上真的有龙！"<<endl;_getch();break;
		case '5':
			cout<<"草丛里住着一对夫妻，黑纹虎和白纹虎，但最近从别的山头来了只啸山虎，现在在争夺领地呢，这个时候如果过去肯定能碰上一两只老虎，但老虎都特别厉害，不过他们正闹得欢呢，逃掉的概率有八成"<<endl;_getch();break;
		case '6':
			cout<<"传说有个美女在这条小径上被老虎咬死了，现在她变成了女鬼在这里徘徊，但不容易遇到，而且女鬼虽说不强，但特烦人，逃掉的概率只有三成，老是嚷嚷着要我打老虎，我去他妈的，老子要是打得过老虎，早闯荡江湖去了，还他么在这儿鬼混？"<<endl;_getch();break;
		case '7':
			cout<<"山顶上有一个巨大的封印，封印时隐时现，并不经常能碰到，碰到封印时仔细找找的话说不定能找到裂缝，那样就可以进去了，封印里有一只巨大的白龙，传说清平山就是为了封印白龙而存在的，唉，我就是与白龙搏斗时收的伤……都说了我没说谎了！"<<endl;_getch();break;
		}
	}
}
void hunt()				//[8]清平山修行
{
	char sel;
	if(ro->getphy()<7)
	{system("cls");cout<<"体力不足以进行战斗！！"<<endl;_getch();return;}
	srand(unsigned(time(NULL)));
	int prob;
	while(1)
	{
	if(ro->getHP()<=0)return;
	if(ro->getphy()<7)
	{system("cls");cout<<"体力不足以进行战斗！！"<<endl;_getch();return;}
	system("cls");
	cout<<ro->getname()<<"：山上的野兽太多了，有些很弱，有些强的离谱，比起强盗来都不差了，村里的孙猎户也许知道些情报……"<<endl;
	cout<<"[1]山洞"<<endl;
	cout<<"[2]灌木和树丛"<<endl;
	cout<<"[3]地洞"<<endl;
	cout<<"[4]水潭"<<endl;
	cout<<"[5]草丛"<<endl;
	cout<<"[6]小径"<<endl;
	cout<<"[7]山顶"<<endl;
	cout<<"【B/b】背包【Z/z】状态【0】返回"<<endl;
	cout<<"你要去哪儿？"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<='7'||sel=='B'||sel=='b'||sel=='Z'||sel=='z'));
	prob=rand()%100+1;
	switch(sel)
	{
	case '0':
		return;
	case 'B':
	case 'b':
		ro->showbag();
		break;
	case 'Z':
	case 'z':
		system("cls");
		ro->showRole();
		_getch();
		break;
	case '1'://山洞里住着一只山猪王和五只小山猪，小山猪是山上最弱的生物，而山猪王平时不会出来，但如果发现小猪都不见了，它也会生气的
		if(count[0]<5)
		{if(ro->combat(mon[0]))count[0]++;}
		else if(count[0]<6)
		{ro->combat(mon[1]);count[0]++;}
		else
		{system("cls");cout<<"山洞里已经什么都没有了！！"<<endl;_getch();}
		break;
	case '2'://树丛里藏着许多狼，谁也不知道里面有多少狼，据我知道的就有白眼狼，青光狼，烽狼，水狼，血狼，不过我听[王屠户]说过，那里似乎还有一只狼王，但总之我是没见过就是了
		if(prob<=5)
			ro->combat(mon[3]);
		else if(prob<=40)
			ro->combat(mon[2]);
		else if(prob<=65)
			ro->combat(mon[6]);
		else if(prob<=80)
			ro->combat(mon[7]);
		else if(prob<=90)
			ro->combat(mon[8]);
		else if(prob<=100)
			ro->combat(mon[9]);
		break;
	case '3'://地洞是盘丝蛇的居住地，不过地洞很大，传说整座山里都是空洞，所以里面盘丝蛇也很多，只是不容易遇见罢了，而且盘丝蛇很缠人，遇上了铁定跑不掉，没把握的话不要轻易尝试
		if(prob<=20)
			ro->combat(mon[10]);
		else
		{system("cls");cout<<"什么都没遇到！！"<<endl;_getch();}
		break;
	case '4'://水潭里住着金龙鲤和银龙鲤，偶尔也会有树丛里的水狼混过去偷吃，据说水潭里还有白龙鲤，是银龙鲤的变种，鲤鱼都很弱，但却是极为珍贵的食材哦，而且据说白龙鲤一不小心跳过龙门后就会进化成白龙哦！就是山顶上的那种白龙！不——我没说谎
		if(prob<=40)
			ro->combat(mon[14]);
		else if(prob<=80)
			ro->combat(mon[15]);
		else if(prob<=95)
			ro->combat(mon[8]);
		else if(prob<100)
			ro->combat(mon[16]);
		break;
	case '5'://草丛里住着一对夫妻，黑纹虎和白纹虎，但最近从别的山头来了只啸山虎，现在在争夺领地呢，这个时候如果过去肯定能碰上一两只老虎，但老虎都挺厉害的
		if(count[1]==0)
		{if(ro->combat(mon[4]))count[1]++;}
		else if(count[1]==1)
		{if(ro->combat(mon[12]))count[1]++;}
		else if(count[1]==2)
		{if(ro->combat(mon[5]))count[1]++;}
		else
		{system("cls");cout<<"山上已经没有老虎了"<<endl;_getch();}
		break;
	case '6'://传说有个美女在这条小径上被老虎咬死了，现在她变成了女鬼在这里徘徊，但不容易遇到，而且女鬼虽说不强，但特烦人，逃掉的概率只有三成，老是嚷嚷着要我打老虎，我去他妈的，老子要是打得过老虎，早闯荡江湖去了，还他么在这儿鬼混？
		if(count[2]==0)
		{
			if(count[1]==3)
			{
				system("cls");
				cout<<"【女鬼】：什么？你真的把所有老虎都干掉啦！呜……呜呜……"<<endl;_getch();
				system("cls");
				system("color f7");Sleep(1000);system("color 07");
				cout<<"一阵白光亮起，眼前出现了一名白衣少女"<<endl;_getch();
				cout<<"【少女】：谢谢你，现在我感觉浑——身——轻——快！！（少女开心的转了个圈）"<<endl;_getch();
				cout<<"【少女】：你真是个好人，如果有来生，我肯定会嫁给你的！！（少女开心的冲你嘻嘻笑）"<<endl;_getch();
				system("color f7");Sleep(1000);system("color 07");
				system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
				cout<<"少女化作一阵清烟消散了……"<<endl;_getch();
				cout<<"你得到了【少女的祝福】"<<endl;_getch();
				ro->add_atk(30);_getch();
				count[2]++;
			}
			else if(prob<20)
			{
				system("cls");
				for(int i=0;i<5;i++)
				{cout<<"【女鬼】：呜……呜呜……杀了那老虎……"<<endl;_getch();}
				if(ro->combat(mon[17]))count[2]++;
			}
			else
			{system("cls");cout<<"什么都没碰到！"<<endl;_getch();}
		}
		else
		{system("cls");cout<<"已经没有女鬼了！"<<endl;_getch();}
		break;
	case '7'://山顶上有一个巨大的封印，封印时隐时现，并不经常能碰到，碰到封印时仔细找找的话说不定能找到裂缝，那样就可以进去了，封印里有一只巨大的白龙，传说清平山就是为了封印白龙而存在的，唉，我就是与白龙搏斗时收的伤……都说了我没说谎了！
		if(count[3]==0)
		{
			if(prob<=20)
			{
				system("cls");
				cout<<"遇到了巨大的封印！\n封印被青光覆盖，看不清里面的情形"<<endl;_getch();
				if(rand()%100<50)
				{
					cout<<ro->getname()<<"找到了一个小小的裂缝"<<endl;_getch();
					cout<<ro->getname()<<"：居然真的有！难道孙猎户说的都是真的？"<<endl;_getch();
					cout<<"是否进去？\n[1]是\n[0]否"<<endl;
					do
					sel=_getch();
					while(!(sel>='0'&&sel<='1'));
					if(sel=='0')
						break;
					system("cls");
					system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
					cout<<"轰隆隆……"<<endl;_getch();
					cout<<"封印受到了巨大的撞击"<<endl;_getch();
					cout<<"【白龙】：啊！！那该死的仙人，居然把我关在这里这么久！！！"<<endl;_getch();
					cout<<"【白龙】：什么？又有人闯进来了？真是羡慕你们那微小的身体"<<endl;_getch();
					cout<<"【白龙】注意到了你"<<endl;_getch();
					system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
					ro->combat(mon[11]);
					count[3]++;
					break;
				}
				else
				{cout<<"运气不好，没找到裂缝……"<<endl;_getch();break;}
			}
			else
			{system("cls");cout<<"什么都没碰到！"<<endl;_getch();break;}
		}
		else
		{system("cls");cout<<"已经没有白龙了！"<<endl;_getch();break;}

	}
	}
}
void mine()				//[9]清平镇的地下矿洞
{
	char sel;
	int n;
	system("cls");
	n=ro->getho_num();
	if(n==0)
	{cout<<"糟糕！忘带矿铲了！！"<<endl;_getch();return;}
	if(ro->getphy()<10)
	{cout<<"体力不足，无法挖矿！！"<<endl;_getch();return;}
	cout<<ro->getname()<<"走在漆黑一片的矿洞中……"<<endl;
	cout<<"你是否要挖矿？\n[1]是\n[0]否"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<='1'));
	if(sel=='0')return;
	system("cls");
	cout<<"你选择使用哪把锄头？"<<endl;
	ro->showho();
	cout<<"[0]不挖"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<=n+48));
	int num=pro[ro->ho_prID(sel-48)].pow;
	srand(unsigned(time(NULL)));
	int t;

	do
	{
	system("cls");
	cout<<ro->getname()<<"卖力地挥舞着矿铲……"<<endl;
	cout<<ro->getname()<<"挖矿中……"<<endl;
	Sleep(3000);
	for(int i=0;i<num;i++)
	{
		t=rand()%100;
		if(t<50)
			ro->add_pr(201);
		else if(t<70)
			ro->add_pr(202);
		else if(t<80)
			ro->add_pr(203);
		else if(t<90)
			ro->add_pr(204);
		else if(t<95)
			ro->add_pr(205);
		else if(t<100)
			ro->add_pr(206);
	}
	ro->sub_phy(10);
	_getch();
	system("cls");
	cout<<"是否继续挖矿？\n[1]是\n[0]否"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<='1'));
	if(sel=='0')return;
	if(ro->getphy()<10)
	{system("cls");cout<<"体力不足，无法挖矿！！"<<endl;_getch();return;}

	}while(1);

}

void robber()//[Q]强盗的老窝
{
	system("cls");
	if(if_win)
	{
		cout<<"空空荡荡……\n难以想象这里曾是那个叱咤风云的强盗的窝点……"<<endl;_getch();return;
	}
	if(ro->getphy()<7)
	{
		cout<<"体力不足，无法挑战强盗！！"<<endl;_getch();return;
	}
	system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
	cout<<"【强盗】：小子，敢挑战我，你很有胆气嘛！"<<endl;_getch();
	cout<<ro->getname()<<"：废话少说，本大爷今天要替天行道！"<<endl;_getch();
	cout<<"【强盗】：小子，不怕吓着你，老爷我曾当过将军，宰过敌寇；";_getch();
	cout<<"创过门派，收过弟子；";_getch();
	cout<<"还被仙人看中，抓到了天上，在仙人脚下当过差，";_getch();
	cout<<"不过我不仅学了几手仙术，还逃了出来；";_getch();
	cout<<"眼界高了，如今看你们就像看脚下的蚂蚁，踩都不屑踩"<<endl;_getch();
	cout<<ro->getname()<<"：……阁下吹牛的功夫还真厉害，在下佩服"<<endl;_getch();
	if(ro->combat(mon[13]))
	{
		system("cls");
		system("color cf");
		if_win=true;
		cout<<"【作者】：小子，恭喜通关！"<<endl;_getch();
		cout<<"【作者】：本大爷就不把你赶出游戏啦！"<<endl;_getch();
		cout<<"【作者】：想玩就继续玩吧！"<<endl;_getch();
		cout<<"【作者】：感谢我吧，小镇上的人本大爷都帮你小子请回来了！"<<endl;_getch();
		cout<<"【作者】：不过那些被你打死的小动物们就回不来了，呜呜……"<<endl;_getch();
		system("cls");
		cout<<"强盗被打败后，镇上的人渐渐地回来了……"<<endl;_getch();
		cout<<"大家都很开心，只有李阿娘不知道为什么闷闷不乐……"<<endl;_getch();
		cout<<"不久，勇士"<<ro->getname()<<"与镇上的黄寡妇也结婚了……"<<endl;_getch();
		cout<<"清平镇回到了往日和平安宁的生活"<<endl;_getch();
		system("color 07");
	}
}
void home()//[H]老光棍的家
{
	char sel;
	system("cls");
	cout<<"要休息吗？(体力和HP都将恢复，时间过去一周)"<<endl;
	cout<<"[1]是"<<endl;
	cout<<"[0]否"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<='1'));
	switch(sel)
	{
	case '0':return;
	case '1':break;
	}
	system("cls");
	cout<<"\n\n\n\n\n\n"<<endl;
	cout<<"就这样，一周过去了……"<<endl;
	week++;
	ro->add_phy(1000);
	ro->add_HP(1000);
	_getch();
	if(if_win)
		return;
	system("cls");
	switch(week)
	{
	case 2:
		map_open[1]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【刘师傅的武馆】被[强盗]砸了"<<endl;_getch();
		cout<<"【刘师傅】：哎呀呀，那强盗看不得我教人学武啊！武学之道已经这么没落了，现在连我这一身技艺也要这么失传了！"<<endl;Sleep(2000);_getch();
		break;
	case 3:
		map_open[2]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【刘师傅的武具店】也被[强盗]砸了"<<endl;_getch();
		cout<<"【刘师傅】：哎呀呀，这里已经不能呆了，我要搬到另一个小镇去传播我的武学！！"<<endl;_getch();
		cout<<"【刘师傅】：哎呀呀，"<<ro->getname()<<"！,实际上你是很有习武天赋的，我走之前，打算将我的习武之道传授给你"<<endl;_getch();
		cout<<"刘师傅打算传授你习武之道，你是否接受？\n[1]是\n[0]否"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='1'));
		if(sel=='0'){cout<<"你拒绝了刘师傅"<<endl;_getch();break;}
		cout<<"你得到了【刘师傅的武功秘籍】"<<endl;_getch();
		map_open[9]=true;
		cout<<ro->getname()<<"：这么深奥！！！看来得花好几周才能弄懂了"<<endl;_getch();
		break;
	case 4:
		map_open[3]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【张大娘的药铺】也被[强盗]砸了"<<endl;_getch();
		cout<<"【张大娘】：唉……上次那强盗来取药我没给，我就知道他不会放过我的，唉……可是我哪来的药啊"<<endl;_getch();
		cout<<"【张大娘】：唉……这个镇子待不下去了，我也走好了"<<endl;_getch();
		break;
	case 5:
		map_open[4]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【铁大叔的杂货店】也被[强盗]砸了"<<endl;_getch();
		cout<<"【铁大叔】：就两把锄头而已，强盗你也好意思抢！！！"<<endl;_getch();
		system("cls");
		system("color f7");Sleep(1000);system("color 07");
		cout<<"\n\n\n\n\n\n"<<endl;
		cout<<"这一夜，窗外星光灿烂，几颗流星划过天空，带着一股莫名的韵味"<<endl;_getch();
		if(map_open[9]==true)
		{
			cout<<ro->getname()<<"忽然心有所感，拿出了刘师傅临行前交给他的【刘师傅的武功秘籍】"<<endl;_getch();
			cout<<ro->getname()<<"：哦……原来是这么回事啊！！！！！！！！"<<endl;_getch();
			ro->add_atk(20);_getch();
		}
		break;
	case 6:
		map_open[5]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【李阿娘的餐馆】的【小姑娘】被[强盗]带走了"<<endl;_getch();
		cout<<"【小姑娘】：李阿娘说她在那儿过得很好，要把我也接过去了，耶！！再也不用给[老光棍]烧菜了！！"<<endl;_getch();
		cout<<ro->getname()<<"：……"<<endl;_getch();
		break;
	case 7:
		map_open[6]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【吴记当铺】也被[强盗]砸了"<<endl;_getch();
		cout<<ro->getname()<<"：老板……别伤心……我……"<<endl;_getch();
		cout<<"【吴老板】：他奶奶的，看什么看，老子可一点都没伤心！！不就是经营了几十年的店铺吗……"<<endl;_getch();
		cout<<"【吴老板】：他奶奶的，砸就砸了吧！！反正老子也正好不想干了……"<<endl;_getch();
		cout<<"【吴老板】：他妈的，老子……呜……呜呜……"<<endl;_getch();
		break;
	case 8:
		map_open[7]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这周，【孙猎户的家】也被[强盗]砸了"<<endl;_getch();
		cout<<"【孙猎户】：哼！如果不是老子与[龙]搏斗时受了伤，还怕你个小小的[强盗]！！"<<endl;_getch();
		cout<<ro->getname()<<"：……算了，这个砸了就砸了吧，不安慰了"<<endl;_getch();
		cout<<"【孙猎户】：（怒）你小子！！！！！"<<endl;_getch();
		break;
	case 9:
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"就在这天，【老光棍的家】也迎来了[强盗]"<<endl;_getch();
		cout<<"【强盗】：听说你小子总纠缠附近的黄寡妇，告诉你，那妞儿本大爷看上了，你赶紧卷铺盖走人吧！"<<endl;_getch();
		cout<<ro->getname()<<"：找打！"<<endl;_getch();
		cout<<"（"<<ro->getname()<<"：话说你的品味不应该是李阿娘级的吗？）"<<endl;_getch();
		robber();
		break;
	default:
		break;
	}
}
void widow()//[G]黄寡妇
{
	system("cls");
	if(if_win==false)
	{
		cout<<"【黄寡妇】：呜呜呜……那可恶的强盗砸了我的房子，我现在无家可归了，呜呜……"<<endl;_getch();
		cout<<"【黄寡妇】：你能帮我把那坏蛋赶走吗？"<<endl;
		cout<<"[1]当……当然可以！"<<endl;
		while(_getch()!='1');
		cout<<"【黄寡妇】：呜呜……光棍哥，你对我真好，等你赶走了强盗，我可以嫁给你吗？（脸红）"<<endl;_getch();
	}
	else
	{
		cout<<"【黄寡妇】：……相公……（脸红）"<<endl;_getch();
	}
}

void cheat()
{
	string command;
	while(1)
	{
		system("cls");
		cout<<"【作者】：小子！作弊可不是什么好行为，你真的要作弊？"<<endl;
		cout<<"[0]算了，不作弊了"<<endl;
		cout<<"请输入作弊指令：";
		cin>>command;
		if(command=="0")
			return;
		else if(command=="addmoney")
		{system("cls");ro->add_money(1000);_getch();}
		else if(command=="addATK")
		{system("cls");ro->add_atk(20);_getch();}
		else if(command=="addweapon")
		{system("cls");ro->add_eq(equ[2]);cout<<"你获得了"<<equ[2].name<<endl;_getch();}
		else if(command=="addarmor")
		{system("cls");ro->add_eq(equ[4]);cout<<"你获得了"<<equ[4].name<<endl;_getch();}
		else if(command=="addmedicine")
		{system("cls");ro->add_pr(2);_getch();}
		else if(command=="addhoe")
		{system("cls");ro->add_pr(102);_getch();}
		else if(command=="super")
		{
			system("cls");
			ro->add_money(10000);
			ro->add_atk(500);
			ro->add_eq(equ[2]);cout<<"你获得了"<<equ[2].name<<endl;
			ro->add_eq(equ[4]);cout<<"你获得了"<<equ[4].name<<endl;
			ro->add_pr(2);ro->add_pr(2);ro->add_pr(2);ro->add_pr(2);
			ro->add_pr(102);
			_getch();
		}
		else
		{system("cls");cout<<"指令错误！！"<<endl;_getch();}
	}
}
#endif//SECOND