#include <iostream>
using namespace std;

// jean-yves Youssef      Matricule:182422

class Acollection{
    public:
    Acollection(int capacite):capacite(capacite),size(0)
    {
        tableau=new float[capacite];
    }
    
	Acollection(Acollection const& A1):
    capacite(A1.capacite),size(A1.size)
    {
        tableau=new float[capacite];
        for(int i=0;i<capacite;++i){
            tableau[i]=A1.tableau[i];
        }
    }
    
	Acollection& operator=(const Acollection& A){
        capacite=A.capacite;
        size=A.size;
        tableau=A.tableau;
    }


    void add(float x){
       check_capacity();
        tableau[size]=x;
        ++size;
    }
    
    virtual void insert(float x, int pos){
        check_capacity();
        float temp=tableau[pos];
        tableau[pos]=x;
        ++size;
        for(int i=pos+1;i<=size;++i){
            float old=tableau[i];
            tableau[i]=temp;
            temp=old;
        }
    }

    virtual  void remove(int pos){
        if(pos>=0 && pos<size ){
            for(int i=pos;i<size-1;++i){
                    tableau[i]=tableau[i+1];
            }
        --size;
        }
    }

    void affiche(){
        for(int i=0;i<size;++i){
            cout<<tableau[i]<<",";
        }
        cout<<endl;
    }

    int indexOf(float x){
        for (int i =0;i<size;++i){
            if(tableau[i]==x){
                return i;
            }
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
	int Size(){
		return size;
	}
	int capacity(){
		return capacite;
	}
	
    ~Acollection(){
        delete[] tableau;
    }
    
    private:
    
	int capacite,size;
    float* tableau;
    
	void check_capacity(){
         if(size==capacite){
            capacite*=2;
            float* temp= new float[capacite];
            for(int i=0;i<capacite/2;++i){
                temp[i]=tableau[i];
            }
            tableau=temp;
            delete[] temp;
        }
    }  
};
 
class Astack : public Acollection{
    public:
        Astack(int n): Acollection(n){}

		void push(int x){
			 Acollection::insert(x,0);
		}

        void remove(){
            Acollection::remove(Acollection::Size()-1);        
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


class Aqueu : public Acollection{
    public:
        Aqueu(int n):Acollection(n){}
        
        void push(int x){
			 Acollection::insert(x,0);
		}
        
        void remove(){
            Acollection::remove(0);
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
	
	Astack a(3);
	a.push(4);
	a.push(3);
	a.affiche();
	a.removeFirst(3);
	a.affiche();
	
/*
	Acollection A(3);
	A.add(2);
	A.add(3);
	A.add(4);
	A.insert(5,1);
	A.add(2);
	A.affiche();
	A.removeFirst(2);
	A.affiche();
	cout<< A.find(6)<<endl;

	Acollection a(10);
	a.add(1);
	a.add(2);
	a.add(4);
	a.add(5);
	a.add(3);
	a.add(5);
	a.add(6);
	a.add(7);
	a.add(8);
	a.add(9);
	a.add(100);
	a.add(204);
	a.affiche();
*/



	
	return 0;
}
