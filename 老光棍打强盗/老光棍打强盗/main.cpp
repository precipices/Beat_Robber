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
		cout<<"���Ϲ����ǿ����"<<endl;
		cout<<"[1]�µ��ó�"<<endl;
		cout<<"[2]����ǰԵ"<<endl;
		cout<<"[3]��Ϸ����"<<endl;
		cout<<"[4]������Ϣ"<<endl;
		cout<<"[0]�˳���Ϸ"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='4'));
		switch(sel)
		{
		case '1':
			system("cls");
			cout<<"�������ɫ������"<<endl;
			cin>>name;
			ro=new Role("[�Ϲ����"+name+"]");
			break;
		case '2':
			ro=new Role;
			if(ro->readgame())break;else continue;
		case '3':help();continue;
		case '4':makeinfo();continue;
		case '0':
			system("cls");
			cout<<"ȷ���˳���\n[1]ȷ��\n[0]����һ���"<<endl;
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
			cout<<"[1]��ʦ�������";if(map_open[1]==true&&if_win==false)cout<<"(����)";cout<<"         [H]�Ϲ���ļң���Ϣ�㣩"<<endl;
			cout<<"[2]��ʦ������߹�";if(map_open[2]==true&&if_win==false)cout<<"(����)";cout<<"       [G]�ƹѸ�"<<endl;
			cout<<"[3]�Ŵ����ҩ��";if(map_open[3]==true&&if_win==false)cout<<"(����)";cout<<"         [Q]ǿ��������"<<endl;
			cout<<"[4]��������ӻ���";if(map_open[4]==true&&if_win==false)cout<<"(����)";cout<<endl;
			cout<<"[5]���Ĳ͹�";if(map_open[5]==true&&if_win==false)cout<<"(����)";cout<<endl;
			cout<<"[6]��ǵ���";if(map_open[6]==true&&if_win==false)cout<<"(����)";cout<<endl;
			cout<<"[7]���Ի��ļ�";if(map_open[7]==true&&if_win==false)cout<<"(����)";cout<<endl;
			cout<<"[8]��ƽ��ĵ��¿�"<<endl;
			cout<<"[9]��ƽɽ���У���ֵ㣩"<<endl;
			cout<<"��B/b��������Z/z��״̬��X/x������浵��V/v����ȡ�浵��C/c�����ס�0���˳�"<<endl;
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
				cout<<"�˻���ѡ����\n[1]ȷ��\n[2]���浵ֱ���˳���Ϸ\n[0]����һ���"<<endl;
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
			if(ro->getHP()<=0||se=='1')//���س�ʼ�˵�
			{delete ro;break;}
		}

	}
}
	//Sleep(2000);cout<<"�����С���"<<endl;Sleep(2000);