#ifndef SECOND
#define SECOND
#include"data.h"


void showtitle(string name){
	system("cls");
	cout<<"\n\n\n\n\n\n";
	cout<<"һ�죬��ƽ������[��ƽ��]ӭ����һ��[ǿ��]��"<<endl;_getch();
	cout<<"[ǿ��]ʱ��ʱ��[��ƽ��]���Ҽ����˼ҵķ��ӣ������ϸ�ü�Ȯ����,"<<endl;_getch();
	cout<<"���죬[ǿ��]�ո�����"<<name<<"һֱ�����ŵ�[�ƹѸ�]�ļң�[�ƹѸ�]�Ŀ����̼���"<<name<<"��"<<endl;_getch();
	cout<<"��ʱ�˿̣�"<<name<<"ͻȻ������һ��Ҫ����С���ǿ����ͷ��"<<endl;_getch();
	cout<<"����"<<name<<"���ĺú�ϰ�䣬ϣ���г�һ���ܰ�ǿ���ϳ�С��"<<endl;_getch();
}
void showtime(){
	cout<<"========================================"<<endl;
	cout<<"��"<<week<<"��"<<endl;
	cout<<"========================================"<<endl;
}




void martialschool()	//[1]��ʦ�������
{
	char sel;
	while(1)
	{
		system("cls");
		if(map_open[0]==false)
		{
		cout<<"����ʦ������ʲô?��Ҫ����ѧ��������ѽѽ���ǲ�����Ҫ���ƹѸ���ǰ�԰ڰ���"<<endl;_getch();
		cout<<"����ʦ��������ѽѽ�����¸��Ǿ��棬ʵ���ǰ����ѵ�һ���ķϲİ���������һ�߶���ȥ�ɣ�"<<endl;_getch();
		}
		cout<<"����ʦ��������ѽѽ������ѧ�����ϣ�һ�ÿ�һ�������ң�������������"<<endl;
		cout<<"���Ƿ���Ƥ������ѧϰ��\n[1]�ǣ����������ظ���һ��������\n[2]������һ�ŸϽ���\n[0]�����뿪��������һƬ�Ʋ�"<<endl;
		
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='2'));
		if(sel=='1')
		{
			system("cls");
			if(ro->getphy()<10)
			{cout<<"��������10�㣡��"<<endl;_getch();return;}
			if(ro->getmoney()<100)
			{cout<<"�������㣡��"<<endl;_getch();return;}
			ro->sub_money(100);
			map_open[0]=true;
			cout<<"��ѧϰ����ʦ������ѧ֮�Ρ���"<<endl;
			ro->sub_phy(10);
			ro->add_atk(10);
			_getch();
		}
		else
			return;
	}
}
void weaponshop()		//[2]��ʦ������߹�
{
	char sel;
	int se;
	int n;
	system("cls");
	cout<<"����ʦ��������ѽ��������ͷ��ϰ���̫���ˣ�������������ȥ������"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"����ʦ��������ѽѽ��ϡ��ϡ�ͣ�������������ү��Ҫ���ʲô��"<<endl;
		for(int i=1;i<=4;i++)
		{
			cout<<"["<<equ[i].ID<<"]"<<equ[i].name<<"\t���ۣ�"<<equ[i].money<<"\t����+"<<equ[i].ATK;
			if(equ[i].kin==WE)
				cout<<"\t�;ã�"<<equ[i].lasting;
			cout<<endl;
		}
		cout<<"[0]����"<<endl;
		cout<<"[F/f]��������"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='4'||sel=='F'||sel=='f'));
		switch(sel)
		{
		case '0':
			system("cls");
			cout<<"����ʦ������������ѽ����������������ɶ������������ԶЩ���ߣ��������"<<endl;
			_getch();
			return;
		case 'F':
		case 'f':break;
		default:
			system("cls");
			if(!(ro->sub_money(equ[sel-48].money))) {_getch();return; }
			ro->add_eq(equ[sel-48]);
			cout<<"������["<<equ[sel-48].name<<"],����������˱�����"<<endl;
			_getch();
			continue;
		}
		system("cls");
		cout<<"����ʦ��������ѽѽ����ү�����ţ����������վ��������϶�һ�ݣ���������������׼û���⣡"<<endl;_getch();
		cout<<"����ʦ������ɶ����û����û��Ҳû��ϵ�����Ҹ������ĵ��ģ���֤��ʤ��������"<<endl;_getch();
		while(1)
		{
			system("cls");
			cout<<"����ʦ��������ô��Ҫ���ļ������أ�һ���;��������ӣ�ͯ�����ۣ�\n(�;�û�����ޣ����Գ�������)"<<endl;
			ro->showeq();
			cout<<"[0]�᲻��Ǯ��������"<<endl;
			n=ro->geteq_n();//���װ������������װ����
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
				cout<<"����ʦ������������ѽ����ûǮ��������ɶ������������ԶЩ���ߣ��������"<<endl;_getch();
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
void pharmacy()			//[3]�Ŵ����ҩ��
{
	char sel;
	while(1)
	{
		system("cls");
		cout<<"���Ŵ������ӭ��ӭ���汧Ǹ���������������æ�������ˣ�ҩ��Ҳ��ȱ�ˡ�"<<endl;
		int k=0;
		for(int i=0;i<pr_num;i++)
		{
			if(pro[i].kin==MED)
				cout<<"["<<++k<<"]"<<pro[i].name<<"\t���ۣ�"<<pro[i].money<<"\tHP+"<<pro[i].pow<<endl;
			else if(pro[i].kin==SPM)
				cout<<"["<<++k<<"]"<<pro[i].name<<"\t���ۣ�"<<pro[i].money<<"\tHPȫ��"<<endl;
		}
		cout<<"[0]������"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<=k+48));
		switch(sel)
		{
		case '0':
			system("cls");
			cout<<"���Ŵ�������߰����´α��������ˣ�������"<<endl;
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
void grocery()			//[4]��������ӻ���
{
	char sel;
	int n=0;
	while(1)
	{
		system("cls");
		cout<<"�������塿��ŶŶ����С�Ⱑ��������ǿ�������󣬵���Ķ����Ѿ������ˡ�"<<endl;
			for(int i=0;i<pr_num;i++)
			{
				if(pro[i].kin==HOM)
				{
					cout<<"["<<pro[i].ID-100<<"]"<<pro[i].name<<"\t���ۣ�"<<pro[i].money<<endl;
					n++;
				}
			}
			cout<<"[0]����"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<=n+48));
		switch(sel)
		{
		case '0':return;
		default:
			system("cls");
			if(ro->sub_money(pro[pr_arrID(sel-48+100)].money)==false) {system("cls");cout<<"�������㣡��"<<endl;_getch();break;}
			ro->add_pr(sel-48+100);
			_getch();
			break;
		}
	}
}
void restaurant()		//[5]���Ĳ͹�
{
	char sel;
	system("cls");
	if(if_win)
	{
		cout<<"�������߰��߰ɣ����ʲô��û�У�������ë��˦��˦��"<<endl;_getch();
		cout<<"��СŮ�������������������˸�������"<<endl;_getch();
		cout<<ro->getname()<<"������"<<endl;_getch();
		return;
	}
	cout<<"��СŮ���������ء�����ﱻǿ��ץ���ˣ�˵��Ҫ��ѹկ����"<<endl;_getch();
	cout<<"��"<<ro->getname()<<"���Թԣ��ⶼ�ܿ����ϣ���ǿ��Ʒζ����أ�"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"��СŮ�������Ҿͻ���ô�����ˣ���Ҫ��ô��"<<endl;
		cout<<"[1]������        ����+10     ���ۣ�30"<<endl;
		cout<<"[2]С����Ģ��    ����ȫ��    ���ۣ�60"<<endl;
		cout<<"[0]������"<<endl;
			do
			sel=_getch();
			while(!(sel>='0'&&sel<='2'));
			system("cls");
			switch(sel)
			{
			case '0':return;
			case '1':
				if(ro->getmoney()<30)
				{cout<<"�������㣡"<<endl;_getch();return;}
				ro->sub_money(30);
				ro->add_phy(10);
				_getch();
				break;
			case '2':
				if(ro->getmoney()<60)
				{cout<<"�������㣡"<<endl;_getch();return;}
				ro->sub_money(60);
				ro->add_phy(999);
				_getch();
				break;
			}
	}
}
void pawnshop()			//[6]��ǵ���
{
	int se;
	int n;
	system("cls");
	cout<<"�����ϰ塿�������̵ģ���������ͷ��ʲô�����������ģ����ÿ�ʯͷ����������Ҳ�Ͱ��ˣ���ֻɽ���������̫��������˰ɣ����������ģ����᳡��"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"�����ϰ塿��ʲô����Ҳ�ǹ�������Щ�ģ�����������������ӹ�������"<<endl;
		ro->showall();
		n=ro->getall_num();
		cout<<"[ 0]�Ͻ�����"<<endl;
		cout<<"(�������֣���Enter����������)"<<endl;
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
	cout<<"�����ϰ塿����~���ڵ�[������]��[ǿ��]���ܺ���������Ҳ���ù���"<<endl;_getch();
}
void hunterhome()		//[7]���Ի��ļ�
{
	int sel;
	system("cls");
	cout<<"�����Ի�������ȥ���ɽʱ���������������������ʱ�����ˣ���Ȼ������ǿ����ķݣ�"<<endl;_getch();
	cout<<"��"<<ro->getname()<<"���ǰ��������������˵Ĳ��ᰡ����"<<endl;_getch();
	while(1)
	{
		system("cls");
		cout<<"�����Ի�������ƽɽ���������Ҫ�Ҹ��㽲����"<<endl;
		cout<<"[1]ɽ��"<<endl;
		cout<<"[2]��ľ������"<<endl;
		cout<<"[3]�ض�"<<endl;
		cout<<"[4]ˮ̶"<<endl;
		cout<<"[5]�ݴ�"<<endl;
		cout<<"[6]С��"<<endl;
		cout<<"[7]ɽ��"<<endl;
		cout<<"[0]���˰ɣ���û��Ȥ"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='7'));
		system("cls");
		switch(sel)
		{
		case '0':return;
		case '1':
			cout<<"ɽ����ס��һֻɽ��������ֻСɽ��Сɽ����ɽ�������������ɽ����ƽʱ������������������С�������ˣ���Ҳ��������"<<endl;_getch();break;
		case '2':
			cout<<"�������������ǣ�˭Ҳ��֪�������ж����ǣ�����֪���ľ��а����ǣ�����ǣ����ǣ�ˮ�ǣ�Ѫ�ǣ�ʵ���β�룬��������[������]˵���������ƺ�����һֻ����������֮����û����������"<<endl;_getch();break;
		case '3':
			cout<<"�ض�����˿�ߵľ�ס�أ������ض��ܴ󣬴�˵����ɽ�ﶼ�ǿն�������������˿��Ҳ�ֻܶ࣬�ǲ������������ˣ�������˿�ߺܲ��ˣ������������ܲ�����û���յĻ���Ҫ���׳���"<<endl;_getch();break;
		case '4':
			cout<<"ˮ̶��ס�Ž������������ż��Ҳ�����������ˮ�ǻ��ȥ͵�ԣ���˵ˮ̶�ﻹ�а�������������ı��֣����㶼��������ȴ�Ǽ�Ϊ����ʳ��Ŷ�����Ҿ�˵������һ��С���������ź�ͻ�����ɰ���Ŷ������ɽ���ϵ����ְ�������������û˵�ѣ�ɽ�����������"<<endl;_getch();break;
		case '5':
			cout<<"�ݴ���ס��һ�Է��ޣ����ƻ��Ͱ��ƻ���������ӱ��ɽͷ����ֻХɽ������������������أ����ʱ�������ȥ�϶�������һ��ֻ�ϻ������ϻ����ر������������������ֵû��أ��ӵ��ĸ����а˳�"<<endl;_getch();break;
		case '6':
			cout<<"��˵�и���Ů������С���ϱ��ϻ�ҧ���ˣ������������Ů���������ǻ���������������������Ů����˵��ǿ�����ط��ˣ��ӵ��ĸ���ֻ�����ɣ�����������Ҫ�Ҵ��ϻ�����ȥ����ģ�����Ҫ�Ǵ�ù��ϻ����紳������ȥ�ˣ�����ô�������죿"<<endl;_getch();break;
		case '7':
			cout<<"ɽ������һ���޴�ķ�ӡ����ӡʱ��ʱ�֣�����������������������ӡʱ��ϸ���ҵĻ�˵�������ҵ��ѷ죬�����Ϳ��Խ�ȥ�ˣ���ӡ����һֻ�޴�İ�������˵��ƽɽ����Ϊ�˷�ӡ���������ڵģ������Ҿ������������ʱ�յ��ˡ�����˵����û˵���ˣ�"<<endl;_getch();break;
		}
	}
}
void hunt()				//[8]��ƽɽ����
{
	char sel;
	if(ro->getphy()<7)
	{system("cls");cout<<"���������Խ���ս������"<<endl;_getch();return;}
	srand(unsigned(time(NULL)));
	int prob;
	while(1)
	{
	if(ro->getHP()<=0)return;
	if(ro->getphy()<7)
	{system("cls");cout<<"���������Խ���ս������"<<endl;_getch();return;}
	system("cls");
	cout<<ro->getname()<<"��ɽ�ϵ�Ұ��̫���ˣ���Щ��������Щǿ�����ף�����ǿ�����������ˣ���������Ի�Ҳ��֪��Щ�鱨����"<<endl;
	cout<<"[1]ɽ��"<<endl;
	cout<<"[2]��ľ������"<<endl;
	cout<<"[3]�ض�"<<endl;
	cout<<"[4]ˮ̶"<<endl;
	cout<<"[5]�ݴ�"<<endl;
	cout<<"[6]С��"<<endl;
	cout<<"[7]ɽ��"<<endl;
	cout<<"��B/b��������Z/z��״̬��0������"<<endl;
	cout<<"��Ҫȥ�Ķ���"<<endl;
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
	case '1'://ɽ����ס��һֻɽ��������ֻСɽ��Сɽ����ɽ�������������ɽ����ƽʱ������������������С�������ˣ���Ҳ��������
		if(count[0]<5)
		{if(ro->combat(mon[0]))count[0]++;}
		else if(count[0]<6)
		{ro->combat(mon[1]);count[0]++;}
		else
		{system("cls");cout<<"ɽ�����Ѿ�ʲô��û���ˣ���"<<endl;_getch();}
		break;
	case '2'://�������������ǣ�˭Ҳ��֪�������ж����ǣ�����֪���ľ��а����ǣ�����ǣ����ǣ�ˮ�ǣ�Ѫ�ǣ���������[������]˵���������ƺ�����һֻ����������֮����û����������
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
	case '3'://�ض�����˿�ߵľ�ס�أ������ض��ܴ󣬴�˵����ɽ�ﶼ�ǿն�������������˿��Ҳ�ֻܶ࣬�ǲ������������ˣ�������˿�ߺܲ��ˣ������������ܲ�����û���յĻ���Ҫ���׳���
		if(prob<=20)
			ro->combat(mon[10]);
		else
		{system("cls");cout<<"ʲô��û��������"<<endl;_getch();}
		break;
	case '4'://ˮ̶��ס�Ž������������ż��Ҳ�����������ˮ�ǻ��ȥ͵�ԣ���˵ˮ̶�ﻹ�а�������������ı��֣����㶼��������ȴ�Ǽ�Ϊ����ʳ��Ŷ�����Ҿ�˵������һ��С���������ź�ͻ�����ɰ���Ŷ������ɽ���ϵ����ְ�������������û˵��
		if(prob<=40)
			ro->combat(mon[14]);
		else if(prob<=80)
			ro->combat(mon[15]);
		else if(prob<=95)
			ro->combat(mon[8]);
		else if(prob<100)
			ro->combat(mon[16]);
		break;
	case '5'://�ݴ���ס��һ�Է��ޣ����ƻ��Ͱ��ƻ���������ӱ��ɽͷ����ֻХɽ������������������أ����ʱ�������ȥ�϶�������һ��ֻ�ϻ������ϻ���ͦ������
		if(count[1]==0)
		{if(ro->combat(mon[4]))count[1]++;}
		else if(count[1]==1)
		{if(ro->combat(mon[12]))count[1]++;}
		else if(count[1]==2)
		{if(ro->combat(mon[5]))count[1]++;}
		else
		{system("cls");cout<<"ɽ���Ѿ�û���ϻ���"<<endl;_getch();}
		break;
	case '6'://��˵�и���Ů������С���ϱ��ϻ�ҧ���ˣ������������Ů���������ǻ���������������������Ů����˵��ǿ�����ط��ˣ��ӵ��ĸ���ֻ�����ɣ�����������Ҫ�Ҵ��ϻ�����ȥ����ģ�����Ҫ�Ǵ�ù��ϻ����紳������ȥ�ˣ�����ô�������죿
		if(count[2]==0)
		{
			if(count[1]==3)
			{
				system("cls");
				cout<<"��Ů����ʲô������İ������ϻ����ɵ������ء������ء���"<<endl;_getch();
				system("cls");
				system("color f7");Sleep(1000);system("color 07");
				cout<<"һ��׹�������ǰ������һ��������Ů"<<endl;_getch();
				cout<<"����Ů����лл�㣬�����Ҹо��롪�������ᡪ���죡������Ů���ĵ�ת�˸�Ȧ��"<<endl;_getch();
				cout<<"����Ů���������Ǹ����ˣ�������������ҿ϶���޸���ģ�������Ů���ĵĳ�������Ц��"<<endl;_getch();
				system("color f7");Sleep(1000);system("color 07");
				system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
				cout<<"��Ů����һ��������ɢ�ˡ���"<<endl;_getch();
				cout<<"��õ��ˡ���Ů��ף����"<<endl;_getch();
				ro->add_atk(30);_getch();
				count[2]++;
			}
			else if(prob<20)
			{
				system("cls");
				for(int i=0;i<5;i++)
				{cout<<"��Ů�����ء������ء���ɱ�����ϻ�����"<<endl;_getch();}
				if(ro->combat(mon[17]))count[2]++;
			}
			else
			{system("cls");cout<<"ʲô��û������"<<endl;_getch();}
		}
		else
		{system("cls");cout<<"�Ѿ�û��Ů���ˣ�"<<endl;_getch();}
		break;
	case '7'://ɽ������һ���޴�ķ�ӡ����ӡʱ��ʱ�֣�����������������������ӡʱ��ϸ���ҵĻ�˵�������ҵ��ѷ죬�����Ϳ��Խ�ȥ�ˣ���ӡ����һֻ�޴�İ�������˵��ƽɽ����Ϊ�˷�ӡ���������ڵģ������Ҿ������������ʱ�յ��ˡ�����˵����û˵���ˣ�
		if(count[3]==0)
		{
			if(prob<=20)
			{
				system("cls");
				cout<<"�����˾޴�ķ�ӡ��\n��ӡ����⸲�ǣ����������������"<<endl;_getch();
				if(rand()%100<50)
				{
					cout<<ro->getname()<<"�ҵ���һ��СС���ѷ�"<<endl;_getch();
					cout<<ro->getname()<<"����Ȼ����У��ѵ����Ի�˵�Ķ�����ģ�"<<endl;_getch();
					cout<<"�Ƿ��ȥ��\n[1]��\n[0]��"<<endl;
					do
					sel=_getch();
					while(!(sel>='0'&&sel<='1'));
					if(sel=='0')
						break;
					system("cls");
					system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
					cout<<"��¡¡����"<<endl;_getch();
					cout<<"��ӡ�ܵ��˾޴��ײ��"<<endl;_getch();
					cout<<"�����������������Ǹ��������ˣ���Ȼ���ҹ���������ô�ã�����"<<endl;_getch();
					cout<<"����������ʲô�������˴������ˣ�������Ľ������΢С������"<<endl;_getch();
					cout<<"��������ע�⵽����"<<endl;_getch();
					system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
					ro->combat(mon[11]);
					count[3]++;
					break;
				}
				else
				{cout<<"�������ã�û�ҵ��ѷ졭��"<<endl;_getch();break;}
			}
			else
			{system("cls");cout<<"ʲô��û������"<<endl;_getch();break;}
		}
		else
		{system("cls");cout<<"�Ѿ�û�а����ˣ�"<<endl;_getch();break;}

	}
	}
}
void mine()				//[9]��ƽ��ĵ��¿�
{
	char sel;
	int n;
	system("cls");
	n=ro->getho_num();
	if(n==0)
	{cout<<"��⣡��������ˣ���"<<endl;_getch();return;}
	if(ro->getphy()<10)
	{cout<<"�������㣬�޷��ڿ󣡣�"<<endl;_getch();return;}
	cout<<ro->getname()<<"�������һƬ�Ŀ��С���"<<endl;
	cout<<"���Ƿ�Ҫ�ڿ�\n[1]��\n[0]��"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<='1'));
	if(sel=='0')return;
	system("cls");
	cout<<"��ѡ��ʹ���İѳ�ͷ��"<<endl;
	ro->showho();
	cout<<"[0]����"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<=n+48));
	int num=pro[ro->ho_prID(sel-48)].pow;
	srand(unsigned(time(NULL)));
	int t;

	do
	{
	system("cls");
	cout<<ro->getname()<<"�����ػ����ſ������"<<endl;
	cout<<ro->getname()<<"�ڿ��С���"<<endl;
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
	cout<<"�Ƿ�����ڿ�\n[1]��\n[0]��"<<endl;
	do
	sel=_getch();
	while(!(sel>='0'&&sel<='1'));
	if(sel=='0')return;
	if(ro->getphy()<10)
	{system("cls");cout<<"�������㣬�޷��ڿ󣡣�"<<endl;_getch();return;}

	}while(1);

}

void robber()//[Q]ǿ��������
{
	system("cls");
	if(if_win)
	{
		cout<<"�տյ�������\n�����������������Ǹ�߳����Ƶ�ǿ�����ѵ㡭��"<<endl;_getch();return;
	}
	if(ro->getphy()<7)
	{
		cout<<"�������㣬�޷���սǿ������"<<endl;_getch();return;
	}
	system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
	cout<<"��ǿ������С�ӣ�����ս�ң�����е����"<<endl;_getch();
	cout<<ro->getname()<<"���ϻ���˵������ү����Ҫ�����е���"<<endl;_getch();
	cout<<"��ǿ������С�ӣ����������㣬��ү���������������׹��пܣ�";_getch();
	cout<<"�������ɣ��չ����ӣ�";_getch();
	cout<<"�������˿��У�ץ�������ϣ������˽��µ����";_getch();
	cout<<"�����Ҳ���ѧ�˼��������������˳�����";_getch();
	cout<<"�۽���ˣ�������Ǿ��񿴽��µ����ϣ��ȶ���м��"<<endl;_getch();
	cout<<ro->getname()<<"���������´�ţ�Ĺ������������������"<<endl;_getch();
	if(ro->combat(mon[13]))
	{
		system("cls");
		system("color cf");
		if_win=true;
		cout<<"�����ߡ���С�ӣ���ϲͨ�أ�"<<endl;_getch();
		cout<<"�����ߡ�������ү�Ͳ�����ϳ���Ϸ����"<<endl;_getch();
		cout<<"�����ߡ�������ͼ�����ɣ�"<<endl;_getch();
		cout<<"�����ߡ�����л�Ұɣ�С���ϵ��˱���ү������С��������ˣ�"<<endl;_getch();
		cout<<"�����ߡ���������Щ���������С�����Ǿͻز����ˣ����ء���"<<endl;_getch();
		system("cls");
		cout<<"ǿ������ܺ����ϵ��˽����ػ����ˡ���"<<endl;_getch();
		cout<<"��Ҷ��ܿ��ģ�ֻ����ﲻ֪��Ϊʲô���Ʋ��֡���"<<endl;_getch();
		cout<<"���ã���ʿ"<<ro->getname()<<"�����ϵĻƹѸ�Ҳ����ˡ���"<<endl;_getch();
		cout<<"��ƽ��ص������պ�ƽ����������"<<endl;_getch();
		system("color 07");
	}
}
void home()//[H]�Ϲ���ļ�
{
	char sel;
	system("cls");
	cout<<"Ҫ��Ϣ��(������HP�����ָ���ʱ���ȥһ��)"<<endl;
	cout<<"[1]��"<<endl;
	cout<<"[0]��"<<endl;
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
	cout<<"��������һ�ܹ�ȥ�ˡ���"<<endl;
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
		cout<<"�������ܣ�����ʦ������ݡ���[ǿ��]����"<<endl;_getch();
		cout<<"����ʦ��������ѽѽ����ǿ���������ҽ���ѧ�䰡����ѧ֮���Ѿ���ôû���ˣ�����������һ����ҲҪ��ôʧ���ˣ�"<<endl;Sleep(2000);_getch();
		break;
	case 3:
		map_open[2]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������ܣ�����ʦ������ߵ꡿Ҳ��[ǿ��]����"<<endl;_getch();
		cout<<"����ʦ��������ѽѽ�������Ѿ����ܴ��ˣ���Ҫ�ᵽ��һ��С��ȥ�����ҵ���ѧ����"<<endl;_getch();
		cout<<"����ʦ��������ѽѽ��"<<ro->getname()<<"��,ʵ�������Ǻ���ϰ���츳�ģ�����֮ǰ�����㽫�ҵ�ϰ��֮�����ڸ���"<<endl;_getch();
		cout<<"��ʦ�����㴫����ϰ��֮�������Ƿ���ܣ�\n[1]��\n[0]��"<<endl;
		do
		sel=_getch();
		while(!(sel>='0'&&sel<='1'));
		if(sel=='0'){cout<<"��ܾ�����ʦ��"<<endl;_getch();break;}
		cout<<"��õ��ˡ���ʦ�����书�ؼ���"<<endl;_getch();
		map_open[9]=true;
		cout<<ro->getname()<<"����ô��£����������û��ü��ܲ���Ū����"<<endl;_getch();
		break;
	case 4:
		map_open[3]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������ܣ����Ŵ����ҩ�̡�Ҳ��[ǿ��]����"<<endl;_getch();
		cout<<"���Ŵ�����������ϴ���ǿ����ȡҩ��û�����Ҿ�֪��������Ź��ҵģ�������������������ҩ��"<<endl;_getch();
		cout<<"���Ŵ����������������Ӵ�����ȥ�ˣ���Ҳ�ߺ���"<<endl;_getch();
		break;
	case 5:
		map_open[4]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������ܣ�����������ӻ��꡿Ҳ��[ǿ��]����"<<endl;_getch();
		cout<<"�������塿�������ѳ�ͷ���ѣ�ǿ����Ҳ����˼��������"<<endl;_getch();
		system("cls");
		system("color f7");Sleep(1000);system("color 07");
		cout<<"\n\n\n\n\n\n"<<endl;
		cout<<"��һҹ�������ǹ���ã��������ǻ�����գ�����һ��Ī������ζ"<<endl;_getch();
		if(map_open[9]==true)
		{
			cout<<ro->getname()<<"��Ȼ�������У��ó�����ʦ������ǰ�������ġ���ʦ�����书�ؼ���"<<endl;_getch();
			cout<<ro->getname()<<"��Ŷ����ԭ������ô���°�����������������"<<endl;_getch();
			ro->add_atk(20);_getch();
		}
		break;
	case 6:
		map_open[5]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������ܣ������Ĳ͹ݡ��ġ�С�����[ǿ��]������"<<endl;_getch();
		cout<<"��С��������˵�����Ƕ����úܺã�Ҫ����Ҳ�ӹ�ȥ�ˣ�Ү������Ҳ���ø�[�Ϲ��]�ղ��ˣ���"<<endl;_getch();
		cout<<ro->getname()<<"������"<<endl;_getch();
		break;
	case 7:
		map_open[6]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������ܣ�����ǵ��̡�Ҳ��[ǿ��]����"<<endl;_getch();
		cout<<ro->getname()<<"���ϰ塭�������ġ����ҡ���"<<endl;_getch();
		cout<<"�����ϰ塿�������̵ģ���ʲô�������ӿ�һ�㶼û���ģ��������Ǿ�Ӫ�˼�ʮ��ĵ����𡭡�"<<endl;_getch();
		cout<<"�����ϰ塿�������̵ģ��Ҿ����˰ɣ�����������Ҳ���ò�����ˡ���"<<endl;_getch();
		cout<<"�����ϰ塿������ģ����ӡ����ء������ء���"<<endl;_getch();
		break;
	case 8:
		map_open[7]=true;
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������ܣ������Ի��ļҡ�Ҳ��[ǿ��]����"<<endl;_getch();
		cout<<"�����Ի������ߣ��������������[��]����ʱ�����ˣ��������СС��[ǿ��]����"<<endl;_getch();
		cout<<ro->getname()<<"���������ˣ�������˾����˰ɣ�����ο��"<<endl;_getch();
		cout<<"�����Ի�������ŭ����С�ӣ���������"<<endl;_getch();
		break;
	case 9:
		system("color f7");Sleep(100);system("color 08");Sleep(50);system("color f7");Sleep(100);system("color 07");
		cout<<"�������죬���Ϲ���ļҡ�Ҳӭ����[ǿ��]"<<endl;_getch();
		cout<<"��ǿ��������˵��С���ܾ��������ĻƹѸ��������㣬��椶�����ү�����ˣ���Ͻ����̸����˰ɣ�"<<endl;_getch();
		cout<<ro->getname()<<"���Ҵ�"<<endl;_getch();
		cout<<"��"<<ro->getname()<<"����˵���Ʒζ��Ӧ������Ｖ���𣿣�"<<endl;_getch();
		robber();
		break;
	default:
		break;
	}
}
void widow()//[G]�ƹѸ�
{
	system("cls");
	if(if_win==false)
	{
		cout<<"���ƹѸ����������ء����ǿɶ��ǿ�������ҵķ��ӣ��������޼ҿɹ��ˣ����ء���"<<endl;_getch();
		cout<<"���ƹѸ��������ܰ��Ұ��ǻ���������"<<endl;
		cout<<"[1]��������Ȼ���ԣ�"<<endl;
		while(_getch()!='1');
		cout<<"���ƹѸ��������ء�������磬�������ã����������ǿ�����ҿ��Լ޸����𣿣����죩"<<endl;_getch();
	}
	else
	{
		cout<<"���ƹѸ����������๫���������죩"<<endl;_getch();
	}
}

void cheat()
{
	string command;
	while(1)
	{
		system("cls");
		cout<<"�����ߡ���С�ӣ����׿ɲ���ʲô����Ϊ�������Ҫ���ף�"<<endl;
		cout<<"[0]���ˣ���������"<<endl;
		cout<<"����������ָ�";
		cin>>command;
		if(command=="0")
			return;
		else if(command=="addmoney")
		{system("cls");ro->add_money(1000);_getch();}
		else if(command=="addATK")
		{system("cls");ro->add_atk(20);_getch();}
		else if(command=="addweapon")
		{system("cls");ro->add_eq(equ[2]);cout<<"������"<<equ[2].name<<endl;_getch();}
		else if(command=="addarmor")
		{system("cls");ro->add_eq(equ[4]);cout<<"������"<<equ[4].name<<endl;_getch();}
		else if(command=="addmedicine")
		{system("cls");ro->add_pr(2);_getch();}
		else if(command=="addhoe")
		{system("cls");ro->add_pr(102);_getch();}
		else if(command=="super")
		{
			system("cls");
			ro->add_money(10000);
			ro->add_atk(500);
			ro->add_eq(equ[2]);cout<<"������"<<equ[2].name<<endl;
			ro->add_eq(equ[4]);cout<<"������"<<equ[4].name<<endl;
			ro->add_pr(2);ro->add_pr(2);ro->add_pr(2);ro->add_pr(2);
			ro->add_pr(102);
			_getch();
		}
		else
		{system("cls");cout<<"ָ����󣡣�"<<endl;_getch();}
	}
}
#endif//SECOND