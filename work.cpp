#include<iostream>
#include<string>
using namespace std;

//ͼ���� 
class Book
{
	public:
		int flag;//���Ϊ0
		int Kind;//ͼ������� 0-ֽ��ͼ��  1-����ͼ��  2-���
		Book()
        {
            flag=1;
			Kind=0;
        }
		virtual void Revise(string,string,long,float,int);         //�޸� 
		virtual void Revise(string,string,float,int);
		virtual void Display();//��ʾ��Ϣ 
		virtual string GetName();
		string GetPublisher();
		long GetIsbn();
		virtual float GetPrice();
		int GetPage();
		//�޸�ʱʹ��
		void setIsbn(long is);
		virtual void setPage(int pa);
		virtual void setPrice(float pr);
        virtual void setName(string na);
		virtual void setPu(string pu);	
	protected:
		string name,publisher;
		long isbn;
		float price;
		int page;
};

//ѧ���� 
class Student
{
	public:
		Student();
		void Borrow(Book bo[]);//���� 
		void Displ();
	private:
		string name;
		long id;	
	//	Book bo[100];	
};

//ͼ����Դ������
class BookManger
{
	public:
		BookManger();
		~BookManger()
		{
			for(int i=0;i<Number;i++)
			{
				delete bo[i];
			}
		}
		void addBook();   //���
		void delBook();   //ɾ��
		void findBook();  //�鿴
		void reBook();     //�޸�
		void showBook();   //��ʾ
	private:
		Book *bo[100];
		int Number;         //��¼ͼ��ı���
	//ͼ�����,ɾ,��,��ȷ���
	//��Ҫ��Book��������������
};

//ѧ��������
class StudentManger
{
	public:
		StudentManger();
		void addStudent(); //���ѧ��
		void delStudent(); //ɾ��ѧ��
		void findStudent(); //�鿴ѧ��
		void reStudent();  //�޸�ѧ��
		void showStuent(); //��ʾ����ѧ��
	private:
		Student stu[100];
	//ѧ������,ɾ,��,��ȷ���
	//��Ҫ��Student��������������
};

//��ͼ����������ĵ�����ͼ��
class EBook:public Book
{
	private:
		int num;
        string writer;
	public:
        EBook()
        {
            num=1;
			Kind=1;
        }
		void Revise(string,string,float,int);
		void setWriter(string wr);
        void Display();
        string GetName();
};

void EBook::setWriter(string wr)
{
	writer=wr;
}
void EBook::Revise(string na,string pul,float pr,int pa)
{
	name=na;
	writer=pul;
	price=pr;
	page=pa;
}
// float EBook::GetPrice()
void EBook::Display()
{
	cout<<"������"<<endl;
    cout<<"����:"<<name<<'\n'<<"����:"<<writer<<"\n"<<"�۸�:"<<price<<"\n"<<"ҳ��"<<page<<endl;
}
string EBook::GetName()
{
    return name;
}


//��ͼ����������ĵ�Ƭ
class Disc:public Book
{	
    public:
		void Display();
        Disc()
        {
			Kind=2;
        }
};
void Disc::Display()
{
	cout<<"��Ƭ��"<<endl;
	cout<<"��Ƭ����:"<<name<<endl;
}



//����ͼ���������
void Book::setIsbn(long is)
{
	isbn=is;
}
void Book::setPage(int pa)
{
	page=pa;
}
void Book::setPrice(float pr)
{
	price=pr;
}
void Book::setPu(string pu)
{
	publisher=pu;
}
void Book::Revise(string na,string pu,long is,float pr,int pa)
{
	name=na;
	publisher=pu;
	isbn=is;
	price=pr;
	page=pa;
}
void Book::Display()
{
	cout<<"����ͼ����"<<endl;
	cout<<"ͼ���������:"<<name<<"\n"<<"ͼ��ĳ�����:"<<publisher<<"\n"<<"ͼ��isbn��Ϊ:"<<isbn<<"\n"<<"ͼ��۸�:"<<price<<"\n"<<"ͼ���ҳ��:"<<page<<endl;
}
string Book::GetName()
{
	return name;
}
string Book::GetPublisher()
{
	return publisher;
}
long Book::GetIsbn()
{
	return isbn;
}
float Book::GetPrice()
{
	return price;
}
int Book::GetPage()
{
	return page;
}
void Book::setName(string na)
{
    name=na;
}
void Book::Revise(string na,string pu,float pr,int pa)
{
	name=na;
	publisher=pu;
	price=pr;
	page=pa;
}



//ѧ���������
void Student::Displ()
{
	cout<<"ѧ������:"<<name<<"\n"<<"ѧ��ѧ��:"<<id<<endl; 
}
Student::Student()
{
	name="С��";
	id=0001;
}
void Student::Borrow(Book bo[])
{
	string bona;//�����ͼ���� 
	int x=0;//�ж��Ƿ��ҵ�ͼ�� 
	char answer;//�Ƿ�������� 
	for(int k=0;;k++)
	{
		x=0; 
		cout<<"��������Ҫ���������:"<<endl;
		cin>>bona;
		for(int i=0;i<=3;i++)
		{
			x++;
			if(bona==bo[i].GetName())
			{
				if(bo[i].flag==1)
				{
				   cout<<"���Խ赽ͼ����ϢΪ:"<<endl;
		     	   bo[i].Display();
		     	   bo[i].flag=0;
		     	   break;
				}
				else
					cout<<"��ͼ���Ѿ������"<<endl;
				
			} 
		}
		if(x==3)
		{
			cout<<"û���ҵ��˱���"<<endl;
		}
		cout<<"�Ƿ��������(y/n)"<<endl;
		cin>>answer;
		if(answer=='n')
		break;
	}
}




//ͼ������������
BookManger::BookManger()
{
	Number=0;
}
//���ͼ��
void BookManger::addBook()
{
	int choose;
	int a;
    string na;
    string pul;
    long is;
	float pr;
	int pa;
    cout<<"-------------------------���ͼ��ϵͳ--------------------------"<<endl;
	cout<<"���������ͼ��ı���:";
	cin>>a;
	for(int i=Number;i<a+Number;i++)
	{
        cout<<"��ѡ������ͼ�������:"<<"\n"<<"0-ֽ��ͼ��  1-����ͼ��  2-���"<<endl; 
		cin>>choose;
		switch(choose)
		{
			case 0:
				bo[i]=new Book();
				cout<<"������ͼ�������,������,isbn,�۸�,ҳ��:";
                cin>>na>>pul>>is>>pr>>pa;
				bo[i]->Revise(na,pul,is,pr,pa);
				break;
			case 1:
                bo[i]=new EBook();
                cout<<"������ͼ�������,����,�۸�,ҳ��:"<<endl;
                cin>>na>>pul>>pr>>pa;
                bo[i]->Revise(na,pul,pr,pa);
				break;
			case 2:
                bo[i]=new Disc();
				cout<<"�������Ƭ��:"<<endl;
				cin>>na;
				bo[i]->setName(na);
				break;
			default:
				cout<<"�������!"<<endl;
				break;
			
		}
	}
    Number=Number+a;
    system("pause");
    system("cls");
}
//��ʾͼ��
void BookManger::showBook()
{
	for(int i=0;i<Number;i++)
	{
		cout<<"-----------------��"<<i<<"����ͼ��------------------"<<endl;
		if(bo[i]->flag==1)
		{
			bo[i]->Display();
		}
		
	}
    system("pause");
    system("cls");
 }
//ɾ��ͼ��
void BookManger::delBook()
{
	string name;
	int x=0;
    cout<<"-------------------------ɾ��ͼ��ϵͳ--------------------------"<<endl;
	cout<<"������Ҫɾ��ͼ�������:";
	cin>>name;
	for(int i=0;i<Number;i++)
	{
		if(name==bo[i]->GetName())
		{
			char answer;
			cout<<"ȷ���Ƿ����ɾ��(y/n):";
			cin>>answer;
			if(answer=='y')
			{
				if(i!=Number)
				{
					for(int j=i;j<=Number-1;j++)
						bo[j]=bo[j+1];			
				}
				Number--;
				cout<<"------------ɾ���ɹ�-------------"<<endl;
				break;
			}
			else
			{
				cout<<"�˳�"<<endl; 
				break;
			}
		}
		x++;
	}
	if(x==Number)
	{
		cout<<"--------------ɾ��ʧ��-------------"<<endl;
	}
    system("pause");
    system("cls");
}
//�޸�ͼ��
void BookManger::reBook()
{
	string na,pu;
	float pr;
	int pa,k;
	long is;
	char ans;
	cout<<"-------------------------�޸�ͼ��ϵͳ--------------------------"<<endl;
	cout<<"��������Ҫ�޸�ͼ�������:"<<endl;
	cin>>na;
	for(int i=0;i<Number;i++)
	{
		if(na==bo[i]->GetName())
		{
			cout<<"�ҵ�ͼ��,ȷ���Ƿ�����޸�(y/n)"<<endl;
			cin>>ans;
			if(ans=='y')
			{
				cout<<"ͼ�����Ϣ:"<<endl;
				bo[i]->Display();
				cout<<"��ѡ����Ҫ�޸�ͼ�����Ϣ:"<<endl;
				if(bo[i]->Kind==0)
				{
					cout<<"��ѡ�����:"<<endl;
					cout<<"0-�޸�����  1-�޸ĳ�����  2-�޸ļ۸�  3-�޸�ҳ��  4-�޸�isbn"<<endl;
					cin>>k;
					switch(k)
					{
						case 0:
							cout<<"������������:"<<endl;
							cin>>na;
							bo[i]->setName(na);
							break;
						case 1:
							cout<<"�������³�����:"<<endl;
							cin>>pu;
							bo[i]->setPu(pu);
							break;
						case 2:
							cout<<"�������¼۸�:"<<endl;
							cin>>pr;
							bo[i]->setPrice(pr);
							break;
						case 3:
							cout<<"��������ҳ��:"<<endl;
							cin>>pa;
							bo[i]->setPage(pa);
							break;
						case 4:
							cout<<"��������isbn:"<<endl;
							cin>>is;
							bo[i]->setIsbn(is);
							break;
						default:
							cout<<"�������!"<<endl;
							break;
					}
				}
				else if(bo[i]->Kind==1)
				{
					cout<<"��ѡ�����:"<<endl;
					cout<<"0-�޸�����  1-�޸�����  2-�޸ļ۸�  3-�޸�ҳ��  "<<endl;
					cin>>k;
					switch(k)
					{
						case 0:
							cout<<"������������:"<<endl;
							cin>>na;
							bo[i]->setName(na);
							break;
						case 1:
							cout<<"������������:"<<endl;
							cin>>pu;
							bo[i]->setPu(pu);
							break;
						case 2:
							cout<<"�������¼۸�:"<<endl;
							cin>>pr;
							bo[i]->setPrice(pr);
							break;
						case 3:
							cout<<"��������ҳ��:"<<endl;
							cin>>pa;
							bo[i]->setPage(pa);
							break;
						default:
							cout<<"�������!"<<endl;
							break;
					}	
				}
				else
				{
					cout<<"��ѡ�����:"<<endl;
					cout<<"0-�޸ĵ�Ƭ����"<<endl;
					cin>>k;
					switch(k)
					{
						case 0:
							cout<<"��������Ƭ��:"<<endl;
							cin>>na;
							bo[i]->setName(na);
							break;
						default:
							cout<<"�������,�������ܴ�����!"<<endl;
							break;
					}
				}
			}	
		}
		
	}
	system("pause");
	system("cls");
}
//Ѱ��ͼ��
void BookManger::findBook()
{
	string name;
	int x=0;
    cout<<"-------------------------Ѱ��ͼ��ϵͳ--------------------------"<<endl;
	cout<<"��������Ҫ���ҵ�ͼ�������:"<<endl;
	cin>>name;
	for(int i=0;i<Number;i++)
	{
		if(name==bo[i]->GetName())
		{
			cout<<"---------���ҳɹ�---------"<<endl;
			bo[i]->Display();	
			break;
		}
		x++;
	}
	if(x==Number)
		cout<<"------------����ʧ��---------"<<endl; 
    system("pause");
    system("cls");
}
//����ͼ����Ľ���
void menu(BookManger one)
{
    int k;
    while(1)
    {
        cout<<"_______________________________ͼ�����ϵͳ_________________________________"<<endl;
        cout<<"                           ����������������������������������������                            "<<endl;
        cout<<"                           -��0���˳�ϵͳ      -                            "<<endl;
        cout<<"                           -��1��ɾ��ͼ��      -                            "<<endl;
        cout<<"                           -��2��Ѱ��ͼ��      -                            "<<endl;
        cout<<"                           -��3�����ͼ��      -                            "<<endl;
        cout<<"                           -��4����ʾͼ��      -                            "<<endl;
        cout<<"                           -��5���޸�ͼ��      -                            "<<endl;
        cout<<"                           ����������������������������������������                            "<<endl;
        cout<<"��ѡ�����:"<<endl;
        cin>>k;
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                system("cls");
                one.delBook();
                break;
            case 2:
                system("cls");
                one.findBook();
                break;
            case 3:
                system("cls");
                one.addBook();
                break;
            case 4:
                system("cls");
                one.showBook();
                break;
            case 5:
                 system("cls");
                 one.reBook();
                 break;
            default:
                cout<<"�������"<<endl;
                system("pause");
                system("cls");
        }
    }
}
int main(int argc, char** argv)
{
	Book *bo[100];
	BookManger one;
    menu(one);
	return 0;
}