#include"secondmenu.h"
int main()
{
	string name;
	char sel;
	char se='3';
	bool book=false;
	while(1)
	{
		system("cls");
		cout<<"【老光棍打强盗】"<<endl;
		cout<<"[1]新的旅程"<<endl;
		cout<<"[2]再续前缘"<<endl;
		cout<<"[3]游戏帮助"<<endl;
		cout<<"[4]制作信息"<<endl;
		cout<<"[0]退出游戏"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='4'));
		switch(sel)
		{
		case '1':
			system("cls");
			cout<<"请输入角色姓名："<<endl;
			cin>>name;
			ro=new Role("[老光棍·"+name+"]");
			break;
		case '2':
			ro=new Role;
			if(ro->readgame())break;else continue;
		case '3':help();continue;
		case '4':makeinfo();continue;
		case '0':
			system("cls");
			cout<<"确认退出吗？\n[1]确定\n[0]再玩一会儿"<<endl;
			do
			sel=_getch();
			while(!(sel>='0'&&sel<='1'));
			if(sel=='1')
				return 0;
			continue;
		}

		showtitle(ro->getname());
		while(1)
		{
			system("cls");
			showtime();
			cout<<"[1]刘师傅的武馆";if(map_open[1]==true&&if_win==false)cout<<"(废墟)";cout<<"         [H]老光棍的家（休息点）"<<endl;
			cout<<"[2]刘师傅的武具馆";if(map_open[2]==true&&if_win==false)cout<<"(废墟)";cout<<"       [G]黄寡妇"<<endl;
			cout<<"[3]张大娘的药铺";if(map_open[3]==true&&if_win==false)cout<<"(废墟)";cout<<"         [Q]强盗的老窝"<<endl;
			cout<<"[4]铁大叔的杂货店";if(map_open[4]==true&&if_win==false)cout<<"(废墟)";cout<<endl;
			cout<<"[5]李阿娘的餐馆";if(map_open[5]==true&&if_win==false)cout<<"(废墟)";cout<<endl;
			cout<<"[6]吴记当铺";if(map_open[6]==true&&if_win==false)cout<<"(废墟)";cout<<endl;
			cout<<"[7]孙猎户的家";if(map_open[7]==true&&if_win==false)cout<<"(废墟)";cout<<endl;
			cout<<"[8]清平镇的地下矿洞"<<endl;
			cout<<"[9]清平山修行（打怪点）"<<endl;
			cout<<"【B/b】背包【Z/z】状态【X/x】保存存档【V/v】读取存档【C/c】作弊【0】退出"<<endl;
			do
			sel=_getch();
			while(!(sel>='0'&&sel<='9'||sel=='H'||sel=='h'||sel=='G'||sel=='g'||sel=='Q'||sel=='q'||sel=='B'||sel=='b'||sel=='Z'||sel=='z'||sel=='X'||sel=='x'||sel=='V'||sel=='v'||sel=='C'||sel=='c'));
			switch(sel)
			{
			case '1':if(map_open[1]==false||if_win)martialschool();break;
			case '2':if(map_open[2]==false||if_win)weaponshop();break;
			case '3':if(map_open[3]==false||if_win)pharmacy();break;
			case '4':if(map_open[4]==false||if_win)grocery();break;
			case '5':if(map_open[5]==false||if_win)restaurant();break;
			case '6':if(map_open[6]==false||if_win)pawnshop();break;
			case '7':if(map_open[7]==false||if_win)hunterhome();break;
			case '8':mine();break;
			case '9':hunt();break;
			case 'H':
			case 'h':home();break;
			case 'G':
			case 'g':widow();break;
			case 'Q':
			case 'q':robber();break;
			case '0':
				system("cls");
				cout<<"退回主选单？\n[1]确定\n[2]不存档直接退出游戏\n[0]再玩一会儿"<<endl;
				do
				se=_getch();
				while(!(se>='0'&&se<='2'));
				if(se=='1')
				{break;}
				else if(se=='2')
				{delete ro;return 0;}
				else if(se=='0')
					continue;
			case 'Z':
			case 'z':
				system("cls");
				ro->showRole();
				_getch();
				break;
			case 'B':
			case 'b':
				ro->showbag();
				break;
			case 'X':
			case 'x':ro->savegame();break;
			case 'V':
			case 'v':ro->readgame();break;
			case 'C':
			case 'c':
				cheat();
				break;
			}
			if(ro->getHP()<=0||se=='1')//返回初始菜单
			{delete ro;break;}
		}

	}
}
	//Sleep(2000);cout<<"测试中……"<<endl;Sleep(2000);