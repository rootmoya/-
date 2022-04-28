#include<iostream>
#include<string>
#include<vector>
#include<iomanip>  //格式化输出输入
#include<fstream>   //文件的输入，输出流
using namespace std;

//图书类 
class Book
{
	public:
		int flag;//借出为0
		int Kind;//图书的类型 0-纸质图书  1-电子图书  2-光碟
		Book()
        {
            flag=1;
			Kind=0;
        }
		virtual void Revise(string,string,long,float,int);         //修改 
		virtual void Revise(string,string,float,int);
		virtual void Display();//显示信息 
		virtual string GetName();
		string GetPublisher();
		long GetIsbn();
		virtual float GetPrice();
		int GetPage();
		//修改时使用
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
//学生类 
class Student
{
	public:
		Student(string name,long id,string sex)
		{
			this->name=name;
			this->id=id;
			this->sex=sex;
		}
		void Borrow(Book bo[]);//借书 
		void Displ();
		long GetId()
		{
			return id;
		}
		void Revise(string,string,long);
	private:
		string name;
		long id;
		string sex;	
	//	Book bo[100];	
};
//图书资源管理类
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
		void addBook();   //添加
		void delBook();   //删除
		void findBook();  //查看
		void reBook();     //修改
		void showBook();   //显示
	private:
		Book *bo[100];
		int Number;         //记录图书的本书
	//图书的增,删,改,查等方法
	//需要对Book类对象持续化处理
};
vector<Student>stus;
vector<Student>::iterator it;
//学生管理类
class StudentManger
{
	public:
		 ~StudentManger()
		 {
			stus.clear();
		 }
		void addStudent(); //添加学生
		void delStudent(); //删除学生
		void findStudent(); //查看学生
		void reStudent();  //修改学生
		void showStuent(); //显示所有学生
	private:
		int n;
	//	Student stu[100];
	//学生的增,删,改,查等方法
	//需要对Student类对象持续化处理
};
// vector<Student>stus;
// vector<Student>::iterator it;
// void Add() 
// {
// 	char name,sex;
// 	char h;
// 	int id;
// 	int s=0,i=1;
// 	char t;
// 	ifstream in("student.txt",ios::in);
// 	if(!in){
// 		cout <<"不能打开输入文件:\n";
// 	}
// 	while(in>>t)
// 	{	
// 		//for(int i=1;i<=3;i++)
// 		//{
// 			if(t==':' && i==1)
// 			{
// 				in>>t;
// 				name=t;
// 				i=2;
// 		//		cout<<name<<endl;
// 				s=1;
// 			//	cout<<"    "<<t<<endl;
// 			}
// 			if(t==':' && i==2)
// 			{
// 				in>>t;
// 				id=t-48;
// 				i=3;
// 			//	cout<<id<<endl;
// 			//	cout<<t<<endl;
// 			}
// 			if(t==':' && i==3)
// 			{
// 				in>>t;
// 				sex=t;
// 				i=1;
// 			//	cout<<sex<<endl;
// 			//	cout<<t<<endl;
// 			}
// 			if(s==1)
// 			{
// 			Student stu(name,id,sex);
// 			stus.push_back(stu);
// 		//	}	
// 		}
	

		
// 	}
// 	cout<<"\n";
// 	in.close();

// }

void StudentManger::addStudent()
{
	string name,sex;
	long id;
	int num;
	ofstream ofile("student.txt",ios::app);
	cout<<setw(10)<<cout.fill('-')<<"添加学生信息系统"<<setw(10)<<cout.fill('-')<<endl;
	cout<<"请输入添加人数:"<<endl;
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cout<<"请输入第"<<i<<"名学生名字,学号,性别:"<<endl;
		cin>>name>>id>>sex;
		Student stu(name,id,sex);
		stus.push_back(stu);
		
		if(!ofile.fail())
		{
			ofile<<"姓名:"<<name<<"    "<<"id:"<<id<<"    "<<"性别:"<<sex<<"\r\n";
		}
		else
		cout<<"open fail" <<endl;
	}
	ofile.close();
	cout<<"添加成功!"<<endl;
	system("pause");
    system("cls");
}
void StudentManger::delStudent()
{
	long id;string ans;
	cout<<setw(10)<<cout.fill('-')<<"删除学生信息系统"<<setw(10)<<cout.fill('-')<<endl;
	cout<<"请输入预删除学生的学号:"<<endl;
	cin>>id;
	for(it=stus.begin();it!=stus.end();it++)
	{
		if((*it).GetId()==id)
		{
			cout<<"是否继续删除(y/n)"<<endl;
			cin>>ans;
			if(ans=="y")
			stus.erase(it);
			cout<<"删除成功!"<<endl;
			break;
		}
	}
	system("pause");
    system("cls");
}
void StudentManger::findStudent()
{
	long id;
	cout<<setw(10)<<cout.fill('-')<<"查找学生信息系统"<<setw(10)<<cout.fill('-')<<endl;
	cout<<"请输入预查找学生的学号:"<<endl;
	cin>>id;
	for(it=stus.begin();it!=stus.end();it++)
	{
		if((*it).GetId()==id)
		{
			cout<<"查找成功"<<endl;
			(*it).Displ();
			break;
		}
	}
	system("pause");
    system("cls");
}
void StudentManger::reStudent()	
{
	long id;string name,sex;
	cout<<setw(10)<<cout.fill('-')<<"修改学生信息系统"<<setw(10)<<cout.fill('-')<<endl;
	cout<<"请输入预查找学生的学号:"<<endl;
	cin>>id;
	ofstream ofile("student.txt",ios::app);
	for(it=stus.begin();it!=stus.end();it++)
	{
		if((*it).GetId()==id)
		{
			cout<<"请输入修改信息:"<<endl;
			cin>>name>>sex>>id;
			(*it).Revise(name,sex,id);
			cout<<"修改成功!"<<endl;
			break;
		}
	}
	system("pause");
    system("cls");
}
void StudentManger::showStuent()
{
	string t;
	int a=1,k;
	cout<<setw(10)<<cout.fill('-')<<"学生信息系统"<<setw(10)<<cout.fill('-')<<endl;
	cout<<"选择功能:"<<endl;
	cout<<"【0】查看已有的学生信息"<<endl;
	cout<<"【1】查看新增学生信息"<<endl;
	cin>>k;
	if(k==0)
	{
		ifstream in("student.txt",ios::in);
		if(!in)
		{
			cout <<"不能打开输入文件:\n";
		}
		while(in>>t)
		{
			cout<<"  "<<t;
			if(a%3==0)
			cout<<"\n";
			a++;
		}
		in.close();
	}
	if(k==1)
	{
		for(it=stus.begin();it!=stus.end();it++)
		{
		(*it).Displ();
		}
	cout<<"\n";
	}

	system("pause");
    system("cls");
		
}
//class Ebook
//由图书基类派生的电子类图书
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
	cout<<"电子类"<<endl;
    cout<<"书名:"<<name<<'\n'<<"作者:"<<writer<<"\n"<<"价格:"<<price<<"\n"<<"页数"<<page<<endl;
}
string EBook::GetName()
{
    return name;
}


//由图书基类派生的碟片
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
	cout<<"碟片类"<<endl;
	cout<<"碟片名字:"<<name<<endl;
}



//基本图书类的声明
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
	cout<<"基本图书类"<<endl;
	cout<<"图书的名称是:"<<name<<"\n"<<"图书的出版社:"<<publisher<<"\n"<<"图书isbn号为:"<<isbn<<"\n"<<"图书价格:"<<price<<"\n"<<"图书的页数:"<<page<<endl;
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


//学生类的声明
void Student::Displ()
{
	cout<<"学生姓名:"<<name<<"\n"<<"学生学号:"<<id<<"\n"<<"学生性别:"<<sex<<endl; 
}
void Student::Borrow(Book bo[])
{
	string bona;//输入的图书名 
	int x=0;//判断是否找到图书 
	char answer;//是否继续借书 
	for(int k=0;;k++)
	{
		x=0; 
		cout<<"请输入想要借书的书名:"<<endl;
		cin>>bona;
		for(int i=0;i<=3;i++)
		{
			x++;
			if(bona==bo[i].GetName())
			{
				if(bo[i].flag==1)
				{
				   cout<<"你以借到图书信息为:"<<endl;
		     	   bo[i].Display();
		     	   bo[i].flag=0;
		     	   break;
				}
				else
					cout<<"此图书已经被借出"<<endl;
				
			} 
		}
		if(x==3)
		{
			cout<<"没有找到此本书"<<endl;
		}
		cout<<"是否继续借书(y/n)"<<endl;
		cin>>answer;
		if(answer=='n')
		break;
	}
}
void Student::Revise(string name,string sex,long id)
{
	this->name=name;
	this->sex=sex;
	this->id=id;
}






//图书管理类的声明
BookManger::BookManger()
{
	Number=0;
}
//添加图书
void BookManger::addBook()
{
	int choose;
	int a;
    string na;
    string pul;
    long is;
	float pr;
	int pa;
    cout<<"-------------------------添加图书系统--------------------------"<<endl;
	cout<<"请输入添加图书的本数:";
	cin>>a;
	for(int i=Number;i<a+Number;i++)
	{
        cout<<"请选择输入图书的类型:"<<"\n"<<"0-纸质图书  1-电子图书  2-光碟"<<endl; 
		cin>>choose;
		switch(choose)
		{
			case 0:
				bo[i]=new Book();
				cout<<"请输入图书的名字,出版社,isbn,价格,页数:";
                cin>>na>>pul>>is>>pr>>pa;
				bo[i]->Revise(na,pul,is,pr,pa);
				break;
			case 1:
                bo[i]=new EBook();
                cout<<"请输入图书的名字,作者,价格,页数:"<<endl;
                cin>>na>>pul>>pr>>pa;
                bo[i]->Revise(na,pul,pr,pa);
				break;
			case 2:
                bo[i]=new Disc();
				cout<<"请输入碟片名:"<<endl;
				cin>>na;
				bo[i]->setName(na);
				break;
			default:
				cout<<"输入错误!"<<endl;
				break;
			
		}
	}
    Number=Number+a;
    system("pause");
    system("cls");
}
//显示图书
void BookManger::showBook()
{
	for(int i=0;i<Number;i++)
	{
		cout<<"-----------------第"<<i<<"本的图书------------------"<<endl;
		if(bo[i]->flag==1)
		{
			bo[i]->Display();
		}
		
	}
    system("pause");
    system("cls");
 }
//删除图书
void BookManger::delBook()
{
	string name;
	int x=0;
    cout<<"-------------------------删除图书系统--------------------------"<<endl;
	cout<<"请输入要删除图书的书名:";
	cin>>name;
	for(int i=0;i<Number;i++)
	{
		if(name==bo[i]->GetName())
		{
			char answer;
			cout<<"确认是否继续删除(y/n):";
			cin>>answer;
			if(answer=='y')
			{
				if(i!=Number)
				{
					for(int j=i;j<=Number-1;j++)
						bo[j]=bo[j+1];			
				}
				Number--;
				cout<<"------------删除成功-------------"<<endl;
				break;
			}
			else
			{
				cout<<"退出"<<endl; 
				break;
			}
		}
		x++;
	}
	if(x==Number)
	{
		cout<<"--------------删除失败-------------"<<endl;
	}
    system("pause");
    system("cls");
}
//修改图书
void BookManger::reBook()
{
	string na,pu;
	float pr;
	int pa,k;
	long is;
	char ans;
	cout<<"-------------------------修改图书系统--------------------------"<<endl;
	cout<<"请输入想要修改图书的名字:"<<endl;
	cin>>na;
	for(int i=0;i<Number;i++)
	{
		if(na==bo[i]->GetName())
		{
			cout<<"找到图书,确认是否继续修改(y/n)"<<endl;
			cin>>ans;
			if(ans=='y')
			{
				cout<<"图书的信息:"<<endl;
				bo[i]->Display();
				cout<<"请选择想要修改图书的信息:"<<endl;
				if(bo[i]->Kind==0)
				{
					cout<<"请选择操作:"<<endl;
					cout<<"0-修改书名  1-修改出版社  2-修改价格  3-修改页数  4-修改isbn"<<endl;
					cin>>k;
					switch(k)
					{
						case 0:
							cout<<"请输入新书名:"<<endl;
							cin>>na;
							bo[i]->setName(na);
							break;
						case 1:
							cout<<"请输入新出版社:"<<endl;
							cin>>pu;
							bo[i]->setPu(pu);
							break;
						case 2:
							cout<<"请输入新价格:"<<endl;
							cin>>pr;
							bo[i]->setPrice(pr);
							break;
						case 3:
							cout<<"请输入新页数:"<<endl;
							cin>>pa;
							bo[i]->setPage(pa);
							break;
						case 4:
							cout<<"请输入新isbn:"<<endl;
							cin>>is;
							bo[i]->setIsbn(is);
							break;
						default:
							cout<<"输入错误!"<<endl;
							break;
					}
				}
				else if(bo[i]->Kind==1)
				{
					cout<<"请选择操作:"<<endl;
					cout<<"0-修改书名  1-修改作者  2-修改价格  3-修改页数  "<<endl;
					cin>>k;
					switch(k)
					{
						case 0:
							cout<<"请输入新书名:"<<endl;
							cin>>na;
							bo[i]->setName(na);
							break;
						case 1:
							cout<<"请输入新作者:"<<endl;
							cin>>pu;
							bo[i]->setPu(pu);
							break;
						case 2:
							cout<<"请输入新价格:"<<endl;
							cin>>pr;
							bo[i]->setPrice(pr);
							break;
						case 3:
							cout<<"请输入新页数:"<<endl;
							cin>>pa;
							bo[i]->setPage(pa);
							break;
						default:
							cout<<"输入错误!"<<endl;
							break;
					}	
				}
				else
				{
					cout<<"请选择操作:"<<endl;
					cout<<"0-修改碟片名字"<<endl;
					cin>>k;
					switch(k)
					{
						case 0:
							cout<<"请输入新片名:"<<endl;
							cin>>na;
							bo[i]->setName(na);
							break;
						default:
							cout<<"输入错误,其他功能待开发!"<<endl;
							break;
					}
				}
			}	
		}
		
	}
	system("pause");
	system("cls");
}
//寻找图书
void BookManger::findBook()
{
	string name;
	int x=0;
    cout<<"-------------------------寻找图书系统--------------------------"<<endl;
	cout<<"请输入想要查找的图书的书名:"<<endl;
	cin>>name;
	for(int i=0;i<Number;i++)
	{
		if(name==bo[i]->GetName())
		{
			cout<<"---------查找成功---------"<<endl;
			bo[i]->Display();	
			break;
		}
		x++;
	}
	if(x==Number)
		cout<<"------------查找失败---------"<<endl; 
    system("pause");
    system("cls");
}
//管理图书类的界面
void menu1(StudentManger stu1,BookManger bo1);
void menu2(BookManger bo1,StudentManger stu1)
{
    int k;
    while(1)
    {
        cout<<"_______________________________图书管理系统_________________________________"<<endl;
        cout<<"                           ————————————————————                            "<<endl;
        cout<<"                           -【0】退出系统      -                            "<<endl;
        cout<<"                           -【1】删除图书      -                            "<<endl;
        cout<<"                           -【2】寻找图书      -                            "<<endl;
        cout<<"                           -【3】添加图书      -                            "<<endl;
        cout<<"                           -【4】显示图书      -                            "<<endl;
        cout<<"                           -【5】修改图书      -                            "<<endl;
		cout<<"                           -【6】切换系统      -                            "<<endl;
        cout<<"                           ————————————————————                            "<<endl;
        cout<<"请选择操作:"<<endl;
        cin>>k;
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                system("cls");
                bo1.delBook();
                break;
            case 2:
                system("cls");
                bo1.findBook();
                break;
            case 3:
                system("cls");
                bo1.addBook();
                break;
            case 4:
                system("cls");
                bo1.showBook();
                break;
            case 5:
                 system("cls");
                 bo1.reBook();
                 break;
			case 6:
				 system("cls");
				 menu1(stu1,bo1);
            default:
                cout<<"输入错误"<<endl;
                system("pause");
                system("cls");
        }
    }
}
void menu1(StudentManger stu1,BookManger bo1)
{
	int k;
    while(1)
    {
        cout<<"_______________________________学生管理系统_________________________________"<<endl;
        cout<<"                           ————————————————————                            "<<endl;
        cout<<"                           -【0】退出系统      -                            "<<endl;
        cout<<"                           -【1】删除学生      -                            "<<endl;
        cout<<"                           -【2】寻找学生      -                            "<<endl;
        cout<<"                           -【3】添加学生      -                            "<<endl;
        cout<<"                           -【4】显示学生      -                            "<<endl;
        cout<<"                           -【5】修改学生      -                            "<<endl;
		cout<<"                           -【6】切换系统      -                            "<<endl;
        cout<<"                           ————————————————————                            "<<endl;
        cout<<"请选择操作:"<<endl;
        cin>>k;
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                system("cls");
                stu1.delStudent();
                break;
            case 2:
                system("cls");
                stu1.findStudent();
                break;
            case 3:
                system("cls");
                stu1.addStudent();
                break;
            case 4:
                system("cls");
                stu1.showStuent();
                break;
            case 5:
                 system("cls");
                 stu1.reStudent();
                 break;
			case 6:
				system("cls");
				menu2(bo1,stu1);
            default:
                cout<<"输入错误"<<endl;
                system("pause");
                system("cls");
        }
    }
}
void menu(BookManger bo1,StudentManger stu1)
{
	
	int k;
	while(1)
	{
		cout<<setw(25)<<cout.fill('-')<<"图书系统"<<setw(25)<<cout.fill('-')<<endl;
		cout<<setw(20)<<cout.fill(' ')<<"【0】退出"<<setw(20)<<cout.fill(' ')<<endl;
		cout<<setw(20)<<cout.fill(' ')<<"【1】学生管理系统"<<setw(20)<<cout.fill(' ')<<endl;
		cout<<setw(20)<<cout.fill(' ')<<"【2】图书管理系统"<<setw(20)<<cout.fill(' ')<<endl;
		cout<<"请选择操作:"<<endl;
        cin>>k;
        switch(k)
        {
            case 0:
                exit(0);
                break;
            case 1:
                system("cls");
                menu1(stu1,bo1);
                break;
			case 2:
                system("cls");
                menu2(bo1,stu1);
                break;
			default:
                cout<<"输入错误"<<endl;
                system("pause");
                system("cls");
		}
	}

}

int main(int argc, char** argv)
{
	Book *bo[100];
	BookManger bo1;
    StudentManger stu1;
	menu(bo1,stu1);
	return 0;
}
