#include <iostream>
using namespace std;

// jean-yves Youssef      Matricule:182422

struct Node{
    float value;
    Node* nxt;
};

class Lcollection {
    public:
    Lcollection(int capacite): capacite(capacite),first(nullptr),size(0){}
    
virtual   void insert(float x,int pos){
    	check();
        if(pos>size || pos<0){
            cout<<"cannot add this element"<<endl;
        }else{
            Node* tmp=new Node;
            tmp->nxt=nullptr;
            tmp->value=x;
            if(this->first==nullptr){
                this->first=tmp;
            }else{
                if(pos==0){
            		tmp->nxt=first;
            		first=tmp;
				}
				else{	
				Node* current=first;
                Node* previous=new Node;
                for(int i=0;i<pos;++i){
                	previous=current;
                    current=current->nxt;
            }
            tmp->nxt=current;
            previous->nxt=tmp;
    		}
        }
            ++size;
        }   
    }

	int Size(){
		return size;
	}

virtual void remove(int pos){
        if(pos==0){
            Node* tmp=first;
            first=first->nxt;
            delete tmp;
        }else{
        Node* current=first;
        Node* previous=nullptr;
        for(int i=0;i<pos;++i){
            previous=current;
            current=current->nxt;
        }
        previous->nxt=current->nxt;
        delete current;
        }
        --size;
    }

    int indexOf(float x){
        Node* current=first;
        for(int i=0;i<size;++i){
            if(current->value==x){
                return i;
            }
            current=current->nxt;
        }
        return -1;
    }

    bool find(float x){
        return indexOf(x)!=-1;
    }

    void removeFirst(float x){
        this->remove(indexOf(x));
    }

    void removeAll(float x){
        while(find(x)){
            this->removeFirst(x);
        }
    }

    void affiche(){
        Node* current=first;
        int i=0;
        while(i<size){
            cout<<current->value<<",";
            current=current->nxt;
            ++i;
        }
        cout<<endl;
        
    }

    private:
    int capacite,size;
    Node* first;
    void check(){
    	if(size==capacite){
    		capacite*=2;
		}
	}

    
};


class Lstack : public Lcollection{
    public:
        Lstack(int n): Lcollection(n){}
		
		void push(int x){
			Lcollection::insert(x,Lcollection::Size()-1);
		}
		
        void pop(){
            Lcollection::remove(Lcollection::Size()-1);        
        }

        void insert(float x,int pos) override{
            error();
        }

        void remove(int pos) override{
            error();
        }

    private:
        void error(){
            cerr<<"cannot remove or insert a random element"<<endl;
        }
};


class Lqueu : public Lcollection{
    public:
        Lqueu(int n):Lcollection(n){}
        
        void push(int x){
			Lcollection::insert(x,Lcollection::Size()-1);
		}
        
        void remove(){
            Lcollection::remove(0);
        }
        void insert(float x,int pos) override{
            error();
        }

        void remove(int pos) override{
            error();
        }

    private:
        void error(){
            cerr<<"cannot remove or insert a random element"<<endl;
        }
};



int main(){
	Lcollection L(3);
	L.insert(4,0);
	L.insert(10,1);
	L.insert(16,1);
	L.insert(5,0);
	L.insert(5,3);
	L.insert(12,2);
	L.insert(8,5);

	
	L.affiche();
	L.remove(2);
	L.affiche();
	
	L.removeAll(5);
	L.affiche();
	return 0;
	
	
		
	
}



