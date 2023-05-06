#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class emp{
	public:
	string name;
	int employ_id;
    string email;
    string position;
    string employ_salary;
    string employ_contact;
    emp *left;
    emp *right;
    emp(){
    	this->left = NULL;
    	this->right = NULL;
	}
	friend class emp_mangmet;
};
class emp_mangment{
	public:
		emp *root;
	emp_mangment(){
		root = new emp();
		root == NULL;
	}
	emp* getInfo(emp *temp);
	void insert();
	void display(emp *temp);
	void inor(emp *temp);
	int total_emp(emp *temp);
	void search(emp *temp,int key);
	void display_file();
	void store();
};
emp* emp_mangment::getInfo(emp *temp){

        cout<<"Enter Employee's name --------: ";
        cin>>temp->name;
        cout<<"Enter Employee's ID ----------: ";
        cin>>temp->employ_id;
        cout<<"Enter Employee's Email ID ----: ";
        cin>>temp->email;
        cout<<"Enter Employee's Position ----: ";
        cin>>temp->position;
        cout<<"Enter Employee contact Info --: ";
        cin>>temp->employ_contact;
        cout<<"Enter Employee's Salary ------: ";
        cin>>temp->employ_salary;
        temp->left=NULL;
        temp->right=NULL;
        this->store();
        return temp;
}

void emp_mangment :: display(emp *temp){
	
		cout<<"\n Employee's name --------: ";
        cout<<temp->name;
        cout<<"\n Employee's ID ----------: ";
        cout<<temp->employ_id;
        cout<<"\n Employee's Email ID ----: ";
        cout<<temp->email;
        cout<<"\n Employee's Position ----: ";
        cout<<temp->position;
        cout<<"\n Employee contact Info --: ";
        cout<<temp->employ_contact;
        cout<<"\n Employee's Salary ------: ";
        cout<<temp->employ_salary;
        cout<<endl;
}

void emp_mangment :: insert(){
		
		emp *p,*q,*temp;
		temp = new emp;
		if(root == NULL){
			root = getInfo(temp);
			delete temp;
			cout<<"ROOT EMPLOYEE CREATED.\n";
		}		
		p=new emp;
		p = getInfo(p);
		p->left = NULL;
		p->right = NULL;
		q=root;
		
		while(q != NULL){
			if(q->employ_id > p->employ_id){
				if ( q->left == NULL){
					q->left = p ;
					cout<<"EMPLOYEE INSERTED \n";
					return;
				}else{
					q = q-> left;
				}

			}
			else if(p->employ_id > q->employ_id){
				if( q ->right == NULL){
					q ->right = p ;
					cout<<"EMPLOYEE INSERTED \n";
					return ;
				}else{
					q = q->right;
				}
			}
		}
}
void emp_mangment :: inor(emp *temp){
		if(temp == NULL){
			return ;
		}
		if(temp != NULL){
			inor(temp->left);
			display(temp);
			inor(temp->right);
		}
}

int emp_mangment :: total_emp(emp *temp){
		if(temp == NULL){
			return 0;
		}
		
		return (total_emp(temp->left)+total_emp(temp->right)+1);	

	}

void emp_mangment :: search(emp *root,int employ_id){
		emp *q;
		q = new emp;
		q=root;
		int searchkey,qkey;
		searchkey = employ_id;
		if(q == NULL){
			cout<<"Record list is EMPTY\n";
		}
		while(q != NULL){
			qkey = q->employ_id;
			if(qkey > searchkey){
				if ( qkey == searchkey){
					
					cout<<"RECORD found !\n ";
					display(q);
					return;
				}else{
					q = q-> left;
				}

			}
			else if(qkey < searchkey){
				if( qkey == searchkey){
					cout<<"RECORD found !\n";
					display(q);
					return ;
				}else{
					q = q->right;
				}
			}
		}
		cout<<"NO RECORD FOUND \n";
}
	
void emp_mangment :: store(){
	ofstream fout;
	fout.open("EMP.txt",ios :: app | ios :: binary);
	fout.write((char*)this,sizeof(*this));
	fout.close();
	this->display_file();
}
void emp_mangment :: display_file(){
	ifstream fin;
	fin.open("EMP.txt",ios::in | ios :: binary);
	while(!fin.eof()){
		fin.read((char*)this,sizeof(*this));
		//cout<<this->name;	
	}
	fin.close();
}


int main(){
	int key,ch = 0;
	emp_mangment obj;
	do{
	
		cout<<"\t\t*******************************************\n";
	    cout<<"\t\t\t  EMPLOYEE MANAGEMENT SYSTEM\n";
	    cout<<"\t\t*******************************************\n";
	    cout<<"\n\nPress 1 : To Add an Employee Details";
	    cout<<"\nPress 2 : To See an Employee Details ";
	    cout<<"\nPress 3 : To Remove an Employee";
	    cout<<"\nPress 4 : total ..To Update Employee Details";
	    cout<<"\nPress 5 : To Exit the EMS Portal";
	    cout<<"\nEnter choice : ";
	    cin>>ch;
	    
	    switch(ch){
	    	case 1:
				obj.insert();
				break;
			case 2:
				obj.inor(obj.root);
				//obj.display_file();
				break;
			case 3:
				cout<<"ENTER EMPLOYEE ID : ";cin>>key;
				obj.search(obj.root , key);
				break;
			case 4:
				cout<<obj.total_emp(obj.root);
				break;
			case 5:
				exit(0);
				break;
			default :
				cout<<"Enter correct choice .";		
		}

	}while(true);
	return 0;
}
